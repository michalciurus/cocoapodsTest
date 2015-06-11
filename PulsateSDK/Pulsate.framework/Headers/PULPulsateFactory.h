//
//  PULPulsateFactory.h
//  PULPulsate
//
//  Created by Michal on 04/12/2014.
//  Copyright (c) 2014 Pulsatehq. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PULPulsateManager.h"

@class PULAuthorizationData;

@interface PULPulsateFactory : NSObject

/**
*  Creates a PulsateManager instance with API Keys fetched from the config. If an instanced
*  already exists it returns it instead.
*
*  @param error can't be nil
*
 *  @return if keys weren't found, it returns null.

*/
+(PULPulsateManager*)getInstanceWithLocationEnabled:(BOOL)locationEnabled andPushEnabled:(BOOL)pushEnabled andLaunchOptions:(NSDictionary*)launchOptions error:(NSError**)error;
/**
 *  Creates pulsate manager instance with given API keys. If an instance already exists
 *  it returns it instead.
 *
 *  @param authorizationData authorization data
 *  @param locationEnabled   should location be enabled
 *  @param pushEnabled       should push be enabled
 *  @param error             error
 *
 *  @return returns Pulsate Manager instance
 */

+(PULPulsateManager*)getInstanceWithAuthorizationData:(PULAuthorizationData*)authorizationData andLocationEnabled:(BOOL)locationEnabled andPushEnabled:(BOOL)pushEnabled andLaunchOptions:(NSDictionary*)launchOptions error:(NSError**)error;

/**
 *  Creates a PulsateManager instance with API Keys fetched from the config, location enabled and push enabled. If an instance already exists it returns it instead.
 *
 *
 *  @return
 */
+(PULPulsateManager*)getInstanceWithLaunchOptions:(NSDictionary*)launchOptions error:(NSError**)error;

+(void)addLoggerToView:(id)view;

@end
