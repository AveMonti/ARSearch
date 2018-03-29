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
#import "TTGeometrySearchResult.h"
#import "TTPoi.h"
#import "TTAddress.h"
#import "TTBoundingBox.h"
#import "TTAddressRanges.h"
#import "TTEntryPoint.h"

@interface TTGeometrySearchResult : NSObject
/**
 Type of result. May be: POI, Street, Geography, Point Address, Address Range, Cross Street
 */
@property (nonatomic, strong, readonly) NSString * _Nonnull type;
/**
 The Id of the result like "CA/POI/p0/107249".
 */
@property (nonatomic, strong, readonly) NSString * _Nonnull ID;
/**
 The Score of the result like "11.3,".
 */
@property (nonatomic, assign, readonly) double score;
/**
 The Address of the result type TTAddresss.
 */
@property (nonatomic, strong, readonly) TTAddress * _Nonnull address;
/**
 The Position of the result type CLLocationCoordinate2D.
 */
@property (nonatomic, assign, readonly) CLLocationCoordinate2D position;
/**
 The Viewport of the result type TTBoundingBox.
 */
@property (nonatomic, strong, readonly) TTBoundingBox * _Nonnull viewport;
/**
 Optional value Distance of the result.
 */
@property (nonatomic, assign, readonly) double distance;
/**
 Optional value Info of the result.
 */
@property (nonatomic, strong, readonly) NSString * _Nullable info;
/**
 Optional value EntityType of the result.
 */
@property (nonatomic, strong, readonly) NSString * _Nullable entityType;
/**
 Optional value Poi of the result type TTPoi.
 */
@property (nonatomic, strong, readonly) TTPoi * _Nullable poi;
/**
 Optional value BoundingBox of the result type TTBoundingBox.
 */
@property (nonatomic, strong, readonly) TTBoundingBox * _Nullable boundingBox;
/**
 Optional value EntryPoints of the result type NSArray<TTEntryPoint>.
 */
@property (nonatomic, strong, readonly) NSArray<TTEntryPoint *>* _Nullable entryPoints;
/**
 Optional value AddressRanges of the result type TTAddressRanges.
 */
@property (nonatomic, strong, readonly) TTAddressRanges * _Nullable addressRanges;

@end
