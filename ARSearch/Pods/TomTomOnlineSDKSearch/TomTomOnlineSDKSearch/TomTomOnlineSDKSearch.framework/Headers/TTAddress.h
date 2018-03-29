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

/**
 A representation of address returned in the result.
 */
@interface TTAddress : NSObject

/**
 Contry code like 'US'
 */
@property (nonatomic, strong, readonly) NSString* _Nonnull countryCode;

/**
 Full name of a country like 'United States Of America'
 */
@property (nonatomic, strong, readonly) NSString* _Nonnull country;

/**
 Country code like 'USA'
 */
@property (nonatomic, strong, readonly) NSString* _Nonnull countryCodeISO3;

/**
 Freeformed Address like "33 S lst St, San Jose, CA 95113"
 */
@property (nonatomic, strong, readonly) NSString* _Nonnull freeformAddress;

/**
The building number on the street like "33"
 */
@property (nonatomic, strong, readonly) NSString* _Nullable streetNumber;

/**
 The street.
 */
@property (nonatomic, strong, readonly) NSString* _Nullable street;

/**
 The name of the street.
 */
@property (nonatomic, strong, readonly) NSString* _Nullable streetName;

/**
  The street name like "S lst St"
 */
@property (nonatomic, strong, readonly) NSString* _Nullable streetNameAndNumber;

/**
 The building number on the street like "33"
 */
@property (nonatomic, strong, readonly) NSString* _Nullable buildingNumber;

/**
 Route numbers.
 */
@property (nonatomic, strong, readonly) NSArray<NSString*>* _Nullable routeNumbers;

/**
 Subdivision level of locality. For example: neighbourhood, suburb, city district, village.
 */
@property (nonatomic, strong, readonly) NSString* _Nullable municipalitySubdivision;

/**
  Locality. For example: city, town, community, borough like "San Jose"
 */
@property (nonatomic, strong, readonly) NSString* _Nullable municipality;

/**
 Second level of country administrative hierarchy. For example: county, borough, parish, municipality like "Santa Clara"
 */
@property (nonatomic, strong, readonly) NSString* _Nullable countrySecondarySubdivision;

/**
 Third level of country administrative hierarchy. For example: town, townships, borough, named area like "San Jose"
 */
@property (nonatomic, strong, readonly) NSString* _Nullable countryTertiarySubdivision;

/**
 First level of country administrative hierarchy. For example: state, province, region, dependent country like "CA"
 */
@property (nonatomic, strong, readonly) NSString* _Nullable countrySubdivision;

/**
  Postal(Zip) Code like "95113"
 */
@property (nonatomic, strong, readonly) NSString* _Nullable postalCode;

/**
 Speed limit
 */
@property (nonatomic, strong, readonly) NSString* _Nullable speedLimit;


/**
 A full name of a first level of country administrative hierarchy.
 This field appears only in case countrySubdivision is presented in an abbreviated form.
 Supported only for USA, Canada and Great Britain.
 */
@property (nonatomic, strong, readonly) NSString* _Nullable countrySubdivisionName;

- (id)initWithCountry:(NSString* _Nonnull)country
          countryCode:(NSString* _Nonnull)countryCode
      countryCodeISO3:(NSString* _Nonnull)countryCodeISO3
      freeformAddress:(NSString* _Nonnull)freeformAddress
         streetNumber:(NSString* )streetNumber
       buildingNumber:(NSString *)buildingNumber
         routeNumbers:(NSArray<NSString*>*)routeNumbers
               street:(NSString *)street
           streetName:(NSString *)streetName
  streetNameAndNumber:(NSString *)streetNameAndNumber
           speedLimit:(NSString *)speedLimit
   countrySubdivision:(NSString *)countrySubdivision
countrySubdivisionName:(NSString *)countrySubdivisionName
countrySecondarySubdivision:(NSString *)countrySecondarySubdivision
         municipality:(NSString *)municipality
municipalitySubdivision:(NSString *)municipalitySubdivision
           postalCode:(NSString *)postalCode;


@end
