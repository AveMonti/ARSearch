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
#import "TTAlongRouteSearchResponse.h"
#import <TomTomOnlineUtils/TomTomOnlineUtils.h>

@class TTAlongRouteSearchQuery;
@class TTAlongRouteSearch;
@class TTAlongRouteSearchResult;
@class TTResponseError;

@protocol TTAlongRouteSearchDelegate
/**
 Method responsible to handle along route search response when search returns results. Within this callback user will obtain Response populated with Results.
 
 @param search Object type TTAlongRouteSearch.
 @param response Object type TTAlongRouteSearchResponse.
 */
-(void)search:(TTAlongRouteSearch*)search completedWithResult:(TTAlongRouteSearchResponse*)response;

/**
 Method responsible to handle along route search response when search returns error. Within this callback user will obtain SearchError containing a Throwable fail reason
 
 @param search object type TTAlongRouteSearch.
 @param error object type TTResponseError.
 */
-(void)search:(TTAlongRouteSearch*)search failedWithError:(TTResponseError*)error;
@end

/**
 Performs along route search action based on provided query object and returns the result with usage of callback implementation.
 */
@interface TTAlongRouteSearch : NSObject

/**
 Performs along route search action based on provided query object and returns the result with usage of dlegate callback implementation.
 
 @param query The object which contains data necessary to execute search action
 @param delegate Delegate that informs the subscriber when a search result is available. It contains a TTAlongRouteSearch object.
 */
- (void)searchWithQuery:(TTAlongRouteSearchQuery*)query
      withAsyncDelegate:(id<TTAlongRouteSearchDelegate>)delegate;

/**
 Performs along route search action based on provided query object and returns the result with usage of completion handler callback implementation.
 
 @param query The object which contains data necessary to execute search action
 @param completionHandler completionHandler CompletionHandler that informs the subscriber when a search result is available. It contains a TTAlongRouteSearchResponse object.
 */
- (void)searchWithQuery:(TTAlongRouteSearchQuery *)query
      completionHandler:(void (^)(TTAlongRouteSearchResponse *response, TTResponseError *error))completionHandler;

/**
 *Search with sync result
 *
 *@param query Object containing the data needed to perform a search.
 *@param error Error
 *@return return TTAlongRouteSearchResponse object.
 */
- (TTAlongRouteSearchResponse *)searchWithQuery:(TTAlongRouteSearchQuery *)query
                                                error:( TTResponseError *)error;


/**
Cancels the current along route search request.
 */
- (void)cancel;



@end
