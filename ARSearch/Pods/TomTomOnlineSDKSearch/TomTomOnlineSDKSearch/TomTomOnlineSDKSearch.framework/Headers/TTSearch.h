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

@class TTSearchQuery;
@class TTSearch;
@class TTSearchResult;
@class TTResponseError;

@protocol TTSearchDelegate
/**
 Method responsible to handle search response when search returns results. Within this callback user will obtain Response populated with Results.
 
 @param search Object type TTSearch.
 @param result Object type NSArray<TTSearchResult>.
 */
-(void)search:(TTSearch*)search completedWithResult:(NSArray<TTSearchResult*>*)result;
/**
 Method responsible to geometry route search response when search returns error. Within this callback user will obtain SearchError containing a Throwable fail reason
 
 @param search Object type TTSearch.
 @param error Object type TTResponseError.
 */
-(void)search:(TTSearch*)search failedWithError:(TTResponseError*)error;
@end

/**
 *TomTom Search API main object. Contains methods to use Tomtom’s online search engine and provides support for both async and sync calls.
 */
@interface TTSearch : NSObject

/**
 *Search with async callback
 *
 *@param query Object containing the data needed to perform a search.
 *@param delegate Delegate that informs the subscriber when a search result is available. It contains a TTSearchResult object.
 */
- (void)searchWithQuery:(TTSearchQuery*)query
      withAsyncDelegate:(id<TTSearchDelegate>)delegate;

/**
 *Search with async block
 *
 *@param query Object containing the data needed to perform a search.
 *@param completionHandler CompletionHandler that informs the subscriber when a search result is available. It contains a TTSearchResult object.
 */
- (void)searchWithQuery:(TTSearchQuery *)query
      completionHandler:(void (^)(NSArray<TTSearchResult *> *result, TTResponseError *error))completionHandler;

/**
 *Cancels the current search request
 */
- (void)cancel;

@end
