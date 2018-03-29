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
#import "TTClassification.h"

/**
 Represents a "poi" field in a json response.
 */
@interface TTPoi : NSObject

/**
 The name of the POI.
 */
@property (nonatomic, strong) NSString* _Nonnull name;

/**
 The phone number of the POI.
 */
@property (nonatomic, strong) NSString* _Nullable phone;

/**
 The url of the POI.
 */
@property (nonatomic, strong) NSString* _Nullable url;

/**
 A list of categories the POI belongs to.
 */
@property (nonatomic, strong) NSArray<NSString*>* _Nonnull categories;

/**
 A list of classifications the POI belongs to.
 */
@property (nonatomic, strong) NSArray<TTClassification*>* _Nonnull classifications;

@end
