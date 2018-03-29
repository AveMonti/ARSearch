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
#import "TTSearchShape.h"

/**
 A circle shape to be used for search query
 */
@interface TTSearchCircle : TTSearchShape

/**
 Creates and returns a TTSearchCircle object using specified coordinate and radius.

 @param coordinate The center point of the circle, specified as a latitude and longitude value.
 @param radius The radius of the circle in meters.
 @return TTSearchCircle
 */
+ (TTSearchCircle *)circleWithCenter:(CLLocationCoordinate2D)coordinate radius:(NSUInteger)radius;

/**
 The center point of the circle, specified as a latitude and longitude value.
 */
@property (nonatomic, assign, readonly) CLLocationCoordinate2D coordinate;

/**
 The radius of the circle in meters.
 */
@property (nonatomic, assign, readonly) CLLocationDistance radius;

@end
