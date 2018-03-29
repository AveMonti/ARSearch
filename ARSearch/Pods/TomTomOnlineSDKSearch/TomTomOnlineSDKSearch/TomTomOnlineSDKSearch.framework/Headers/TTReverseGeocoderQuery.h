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

extern NSString *const TTReverseGeocoderAttributeCountry;
extern NSString *const TTReverseGeocoderAttributeCountryCode;
extern NSString *const TTReverseGeocoderAttributeCountryCodeISO3;
extern NSString *const TTReverseGeocoderAttributeCountrySubdivision;
extern NSString *const TTReverseGeocoderAttributeCountrySubdivisionName;
extern NSString *const TTReverseGeocoderAttributeCountrySecondarySubdivision;
extern NSString *const TTReverseGeocoderAttributeMunicipality;
extern NSString *const TTReverseGeocoderAttributeMunicipalitySubdivision;
extern NSString *const TTReverseGeocoderAttributeStreet;
extern NSString *const TTReverseGeocoderAttributeStreetName;
extern NSString *const TTReverseGeocoderAttributeStreetNameAndNumber;
extern NSString *const TTReverseGeocoderAttributePostalCode;
extern NSString *const TTReverseGeocoderAttributeBuildingNumber;
extern NSString *const TTReverseGeocoderAttributeStreetNumber;
extern NSString *const TTReverseGeocoderAttributeFreeformAddress;


@class TTReverseGeocoderQuery;

@interface TTReverseGeocoderQueryBuilder : NSObject

/**
 @param coordinate The map coordinate whose geographical information you want to retrieve.
 @return TTReverseGeocoderQueryBuilder
 */
+(TTReverseGeocoderQueryBuilder*)createWithCLLocationCoordinate2D:(CLLocationCoordinate2D)coordinate;


/**
 @param radius The maximum distance in meters from the specified position for the reverse geocoder to consider.
 @return TTReverseGeocoderQueryBuilder
 */
-(TTReverseGeocoderQueryBuilder*)withRadius:(NSNumber *)radius;


/**
 @param languageType languageType
 @return TTReverseGeocoderQueryBuilder
 */
-(TTReverseGeocoderQueryBuilder*)withLanguage:(TTLanguage)languageType;


/**
 @param heading The directional heading of travel along a segment of roadway. 0 is North, 90 is East and so on. Values range from -360 to 360. can have up to one decimal place of precision.
 @return TTReverseGeocoderQueryBuilder
 */
-(TTReverseGeocoderQueryBuilder*)withHeading:(NSNumber *)heading;


/**
 @param number Optional house number for the request. If this is used, the response may include the side of the street (Left/Right) and the offset position for that number.
 @return TTReverseGeocoderQueryBuilder
 */
-(TTReverseGeocoderQueryBuilder*)withNumber:(NSString *)number;


/**
 @param returnSpeedLimit Return the posted speed limit (where available).
 @return TTReverseGeocoderQueryBuilder
 */
-(TTReverseGeocoderQueryBuilder*)withReturnSpeedLimit:(BOOL)returnSpeedLimit;


/**
 @param returnRoadUse Return the road use array. Only available for street-level reverse geocodes.
 @return TTReverseGeocoderQueryBuilder
 */
-(TTReverseGeocoderQueryBuilder*)withReturnRoadUse:(BOOL)returnRoadUse;


/**
 @param tolerance
 @return TTReverseGeocoderQueryBuilder
 */
-(TTReverseGeocoderQueryBuilder*)withTolerance:(NSNumber *)tolerance;


/**
 @param returnMatchType returnMatchType
 @return TTReverseGeocoderQueryBuilder
 */
-(TTReverseGeocoderQueryBuilder*)withReturnMatchType:(BOOL)returnMatchType;


/**
 @param addressAttributes addressAttributes
 @return TTReverseGeocoderQueryBuilder
 */
-(TTReverseGeocoderQueryBuilder*)withAddressAttributes:(NSArray<NSString *> *)addressAttributes;


/**
 @return TTReverseGeocoderQuery
 */
-(TTReverseGeocoderQuery*)build;

@end

@interface TTReverseGeocoderQuery : NSObject

@property (nonatomic, readonly, copy) NSValue *coordinate;
@property (nonatomic, readonly, assign) CLLocationCoordinate2D locationCoordinate;
@property (nonatomic, readonly, copy) NSNumber *radius;
@property (nonatomic, readonly, assign) TTLanguage language;
@property (nonatomic, readonly, copy) NSString *languagePrefix;
@property (nonatomic, readonly, copy) NSNumber *heading;
@property (nonatomic, readonly, copy) NSString *number;
@property (nonatomic, readonly, assign) BOOL returnSpeedLimit;
@property (nonatomic, readonly, assign) BOOL returnRoadUse;
@property (nonatomic, readonly, copy) NSNumber *tolerance;
@property (nonatomic, readonly, assign) BOOL returnMatchType;
@property (nonatomic, readonly, copy) NSArray<NSString *> *addressAttributes;

@end

