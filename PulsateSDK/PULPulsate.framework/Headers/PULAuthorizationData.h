//
//  PULAuthorizationKeys.h
//  PULPulsate
//
//  Created by Michal on 04/12/2014.
//  Copyright (c) 2014 Pulsatehq. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PULAuthorizationData : NSObject

@property (nonatomic, readonly) NSString* appId;
@property (nonatomic, readonly) NSString* appKey;

/**
 *  Creates and validates the authorization data.
 *
 *  @param pAppId
 *  @param pAppKey
 *  @param Validation error. Nil if no error ocurred.
 *
 *  @return instancetype
 */
-(instancetype)initWithAppId:(NSString*)pAppId andAppKey:(NSString*)pAppKey validationError:(NSError**)error;

@end
