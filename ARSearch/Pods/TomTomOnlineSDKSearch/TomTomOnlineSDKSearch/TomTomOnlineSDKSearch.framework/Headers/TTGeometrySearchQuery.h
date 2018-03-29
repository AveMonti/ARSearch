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

#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>
#import <TomTomOnlineUtils/TomTomOnlineUtils.h>
#import "TTSearchShape.h"

typedef NS_ENUM(NSUInteger, TTSearchIndex) {
    TTSearchIndexAddres,
    TTSearchIndexGeographies,
    TTSearchIndexPointAddress,
    TTSearchIndexPointOfInterest,
    TTSearchIndexStreets,
    TTSearchIndexCrossStreets
};

@class TTGeometrySearchQuery;

@interface TTGeometrySearchQueryBuilder : NSObject

+ (TTGeometrySearchQueryBuilder *)createWithTerm:(NSString *)term searchShapes:(NSArray<TTSearchShape *> *)shapes;
- (TTGeometrySearchQueryBuilder *)withLimit:(NSUInteger)limit;
- (TTGeometrySearchQueryBuilder *)withLanguage:(TTLanguage)language;
- (TTGeometrySearchQueryBuilder *)withExtendedPostalCodeFor:(TTSearchIndex)index;
- (TTGeometrySearchQueryBuilder *)withIdxSet:(TTSearchIndex)index;
- (TTGeometrySearchQuery *)build;

@end

@interface TTGeometrySearchQuery : NSObject

@end
