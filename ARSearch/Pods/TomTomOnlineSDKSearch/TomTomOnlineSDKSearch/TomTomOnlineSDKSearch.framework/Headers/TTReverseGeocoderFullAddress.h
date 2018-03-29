/**
 * Copyright (c) 2017 TomTom N.V. All rights reserved.
 *
 * This software is the proprietary copyright of TomTom N.V. and its subsidiaries and may be used
 * for internal evaluation purposes or commercial use strictly subject to separate licensee
 * agreement between you and TomTom. If you are the licensee, you are only permitted to use
 * this Software in accordance with the terms of your license agreement. If you are not the
 * licensee then you are not authorised to use this software in any manner and should
 * immediately return it to TomTom N.V.
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class TTAddress;
@interface TTReverseGeocoderFullAddress : NSObject

- (id)initWithAddress:(TTAddress *)address
        withMatchType:(NSString *)matchType
         withPosition:(CLLocationCoordinate2D)position
          withRoadUse:(NSArray<NSString *>*)roadUse;


/**
 */
@property (nonatomic, readonly, copy) TTAddress *address;

/**
 */
@property (nonatomic, readonly, copy) NSString *matchType;

/**
 */
@property (nonatomic, readonly, assign) CLLocationCoordinate2D position;

/**
 */
@property (nonatomic, readonly, copy) NSArray<NSString*> *roadUse;

@end
