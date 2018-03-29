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
#import "TTSearchPolygon.h"
#import "TTSearchShape.h"

/**
 A polygon shape to be used for search query
 */
@interface TTSearchPolygon : TTSearchShape

/**
 Creates and returns a TTSearchPolygon object using coordinates array

 @param coordinates pointer to array of coordinates, array has to have at least 3 elements
 @param count number of coordiantes in array
 @return TTSearchPolygon
 */
+ (TTSearchPolygon *)polygonWithCoordinates:(CLLocationCoordinate2D *)coordinates count:(NSUInteger)count;

/**
 The array of coordinates defining the polygon.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D *coordinates;

/**
 The number of items in the coordinates array.
 */
@property (nonatomic, assign, readonly) NSUInteger count;

@end
