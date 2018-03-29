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

/**
 A representation of address ranges on a street segment. Available only for results where result type is equal to "Address Range".
 */
@interface TTAddressRanges : NSObject

/**
 An address range on the left side of a street segment
 */
@property (nonatomic, strong, readonly) NSString * _Nonnull rangeLeft;

/**
 An address range on the right side of a street segment
 */
@property (nonatomic, strong, readonly) NSString * _Nonnull rangeRight;

/**
 A beginning point of a street segment.
 */
@property (nonatomic, assign, readonly) CLLocationCoordinate2D from;

/**
 An end point of a street segment.
 */
@property (nonatomic, assign, readonly) CLLocationCoordinate2D to;

@end
