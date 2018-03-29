//
//  ViewController.swift
//  ARSearch
//
//  Created by Mateusz Chojnacki on 3/29/18.
//  Copyright © 2018 MattChojnacki. All rights reserved.
//

import UIKit
import TomTomOnlineSDKSearch
import CoreLocation
import ARKit
import SceneKit

class ViewController: UIViewController,ARSCNViewDelegate, CLLocationManagerDelegate,UITextFieldDelegate, TTSearchDelegate,ARLocationDelegae  {
    func addChildNode(modelNode: SCNNode!) {
        self.arView.scene.rootNode.addChildNode(modelNode)
    }
    
    
    
    var search:TTSearch?
    
    //AR + Location
    var userLocation = CLLocation()
    var arLocationManager = ARLocation()
    let locationManager = CLLocationManager()
    @IBOutlet weak var arView: ARSCNView!
    
    @IBOutlet weak var addBTN: UIButton!
    @IBOutlet weak var input: UITextField!
    
    
    func search(_ search: TTSearch!, completedWithResult result: [TTSearchResult]!) {
        if(result.count > 0){
            for r in result{
                print(r)
                print("User Location:  \(userLocation)  \n")
                print("Pin Location:  \(r.position)  \n")
                self.arLocationManager.updatePin(userLocation: userLocation, pinLocaton: CLLocationCoordinate2DMake(r.position.longitude, r.position.latitude))
            }
        }
    }
    
    func search(_ search: TTSearch!, failedWithError error: TTResponseError!) {
        print(error)
    }
    

    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.input.delegate = self;
        //AR
        self.arLocationManager.delegate = self
        self.arView.delegate = self
        let scene = SCNScene()
        
        // Set the scene to the view
        self.arView.scene = scene
        
        self.search = TTSearch()
        self.addBTN.tintColor = UIColor.gray
        // Start location services
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
        locationManager.requestWhenInUseAuthorization()
        self.addBTN.backgroundColor = UIColor.gray
        
    }
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        // Create a session configuration
        let configuration = ARWorldTrackingConfiguration()
        configuration.worldAlignment = .gravityAndHeading
        
        // Run the view's session
        self.arView.session.run(configuration)
    }

    
    // Location
    func locationManager(_ manager: CLLocationManager, didFailWithError error: Error) {
        print(error.localizedDescription)
    }
    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        if status == .authorizedWhenInUse {
            self.locationManager.requestLocation()
        }
    }
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        if let location = locations.last {
            userLocation = location
            self.addBTN.backgroundColor = UIColor.green
            
        }
    }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        self.arView.endEditing(true)
    }
    
    @IBAction func searchBTN(_ sender: Any) {
        self.input.resignFirstResponder()
        
        let query = TTSearchQueryBuilder.create(withTerm: self.input.text).withPosition(CLLocationCoordinate2DMake(userLocation.coordinate.latitude, userLocation.coordinate.longitude)).build()
//        let query = TTSearchQueryBuilder.create(withTerm: self.input.text).build()
        self.search?.search(with: query, withAsyncDelegate: self)
        
    }
}

