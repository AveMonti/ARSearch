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
#import "TomTomOnlineSDKSearch.h"

typedef NS_OPTIONS(NSUInteger, TTExtendedPostalCodesIndexes) {
    TTExtendedPostalCodesIndexNone = 0,
    TTExtendedPostalCodesIndexAddr = 1 << 0,
    TTExtendedPostalCodesIndexGeo = 1 << 1,
    TTExtendedPostalCodesIndexPAD = 1 << 2,
    TTExtendedPostalCodesIndexPOI = 1 << 3,
    TTExtendedPostalCodesIndexStr = 1 << 4,
    TTExtendedPostalCodesIndexXStr = 1 << 5,
};

@class TTSearchQuery;

/**
 *TTSearchQueryBuilder Search query
 */
@interface TTSearchQueryBuilder : NSObject

/**
 *Create query builder with term
 *
 *@param term Query to be searched.
 *@return TTSearchQueryBuilder
 */
+(TTSearchQueryBuilder*)createWithTerm:(NSString*)term;


/**
 *@param limit Maximum number of search results that will be returned by the search service.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder*)withLimit:(NSNumber *)limit;


/**
 *@param offset Starting offset of the returned results within the full result set.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder*)withOffset:(NSNumber *)offset;


/**
 *@param position Position where results should be biased.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder*)withPosition:(CLLocationCoordinate2D)position;


/**
 *@param position Position for which the results should be biased.
 *@param radius If radius and location are set, the results will be constrained to the defined area.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder*)withPosition:(CLLocationCoordinate2D)position withRadius:(int)radius;


/**
 *@param countrySet This will limit the search to the specified countries.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder*)withCountrySet:(NSArray<NSString*>*)countrySet;


/**
 *@param idxSet Specifies which indexes to use for the search. The predefined indexes are: Addr (address range interpolation), Geo (Geographies), Str (streets).
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder*)withIdxSet:(NSArray<NSNumber*> *)idxSet;


/**
 *@param languageType Language
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder*)withLanguage:(TTLanguage)languageType;


/**
 @param extendedPostalCodesIndexes extendedPostalCodesIndexes Indexes for which extended postal codes should be included in the results.
 @return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder*)withExtendedPostalCodesFor:(TTExtendedPostalCodesIndexes)extendedPostalCodesIndexes;


/**
 *@param topLeft Top left corner of the bounding box.
 *@param bottomRight Bottom right corner of the bounding box.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder*)withBoundingBoxTopLeft:(CLLocationCoordinate2D)topLeft
                    withBoundingBoxBottomRight:(CLLocationCoordinate2D)bottomRight;


/**
 *@param isTypeAhead If the "typeahead" flag is set, the query will be interpreted as a partial input and the search will enter predictive mode.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder*)withTypeAhead:(BOOL)isTypeAhead;


/**
 *@param isCategory Indicates whether the query a category query.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder*)withCategory:(BOOL)isCategory;


/**
 *@param minFuzzyLevel Minimum fuzziness level to be used.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder*)withMinFuzzyLevel:(NSNumber *)minFuzzyLevel;


/**
 *@param maxFuzzyLevel Maximum fuzziness level to be used.
 *@return TTSearchQueryBuilder
 */
-(TTSearchQueryBuilder*)withMaxFuzzyLevel:(NSNumber *)maxFuzzyLevel;
-(TTSearchQuery*)build;
@end

typedef NS_ENUM(NSUInteger, CoordinateValue) {
    CoordinateValuePosition,
    CoordinateValueBoundingBoxTopLeft,
    CoordinateValueBoundingBoxBottomRight
};

typedef NS_ENUM(NSUInteger, IdxSet) {
    IdxSetAddressRangeInterpolation,
    IdxSetGeographies,
    IdxSetPointAddresses,
    IdxSetPointsOfInterest,
    IdxSetStreets,
    IdxSetCrossStreets,
};

@interface TTSearchQuery : NSObject
@property (nonatomic, readonly, copy) NSString *term;
@property (nonatomic, readonly, copy) NSValue *position;
@property (nonatomic, readonly, copy) NSNumber *radius;
@property (nonatomic, readonly, copy) NSNumber *limit;
@property (nonatomic, readonly, copy) NSNumber *offset;
@property (nonatomic, readonly, copy) NSArray<NSString*> *countrySet;
@property (nonatomic, readonly, copy) NSArray<NSNumber*> *idxSet;
@property (nonatomic, readonly, copy) NSValue *boundingBoxTopLeft;
@property (nonatomic, readonly, copy) NSValue *boundingBoxBottomRight;
@property (nonatomic, readonly, assign) BOOL isTypeAhead;
@property (nonatomic, readonly, assign) BOOL isCategory;
@property (nonatomic, readonly, assign) TTLanguage language;
@property (nonatomic, readonly, assign) TTExtendedPostalCodesIndexes extendedPostalCodesIndexes;
@property (nonatomic, readonly, copy) NSNumber *minFuzzyLevel;
@property (nonatomic, readonly, copy) NSNumber *maxFuzzyLevel;

+ (NSDictionary *)idxSetDict;

- (CLLocationCoordinate2D)coordinateForNSValue:(CoordinateValue)coordinateValue;

@end
