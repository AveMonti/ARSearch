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
#import <TomTomOnlineUtils/TomTomOnlineUtils.h>

@class TTAlongRouteSearchQuery;


@interface TTAlongRouteSearchQueryBuilder : NSObject

/**
 Init of TTAlongRouteSearchQueryBuilder object
 
 @param term Object containing the data needed to perform a search.
 @param route Route object with list of coordination.
 @param maxDetourTime Maximum detour time. Max value is 3600.
 @return TTAlongRouteSearchQuery object.
 */
-(id)initWithTerm:(NSString*)term withRoute:(id<TTRouteData>)route withMaxDetourTime:(int) maxDetourTime;

/**
 Builder of TTAlongRouteSearchQueryBuilder object
 
 @param term Object containing the data needed to perform a search.
 @param route Route object with list of coordination.
 @param maxDetourTime Maximum detour time. Max value is 3600.
 @return TTAlongRouteSearchQuery object.
 */
+(TTAlongRouteSearchQueryBuilder*)withTerm:(NSString*)term withRoute:(id<TTRouteData>)route withMaxDetourTime:(int) maxDetourTime;

/**
 Part of builder TTAlongRouteSearchQueryBuilder obejct.
 
 @param limit Maximum number of responses that will be returned. Default value 10.
 @return TTAlongRouteSearchQuery object.
 */
-(TTAlongRouteSearchQueryBuilder*)withLimit:(int)limit;

/**
 Build method.
 
 @return TTAlongRouteSearchQuery object.
 */
-(TTAlongRouteSearchQuery*)build;
@end

@interface TTAlongRouteSearchQuery : NSObject

@end
