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
#import "TTClassificationName.h"

/**
 Representation of the classifications field of a json response.
 https://developer.tomtom.com/online-search/online-search-documentation/supported-category-codes
 */
@interface TTClassification : NSObject

/**
 Classification code
 */
@property (nonatomic, strong, readonly) NSString* code;

/**
 A vector of classification names
 */
@property (nonatomic, strong, readonly) NSArray<TTClassificationName*>* classificationNames;

@end
