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

@interface TTSearchSummary : NSObject

/**
 The query this is a response to.
 */
@property(nonatomic, strong, readonly) NSString* query;

/**
 The type of the query.
 */
@property(nonatomic, strong, readonly) NSString* queryType;

/**
 The time the query took to execute.
 */
@property(nonatomic, assign, readonly) int queryTime;

/**
 The number of results
 */
@property(nonatomic, assign, readonly) int numResults;

/**
 Start index of returned results for query
 */
@property(nonatomic, assign, readonly) int offset;

/**
 Number of total results available for given query
 */
@property(nonatomic, assign, readonly) int totalResults;

/**
 The fuzzy search level
 */
@property(nonatomic, assign, readonly) int fuzzyLevel;

@end
