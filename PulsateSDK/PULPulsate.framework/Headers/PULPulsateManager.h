//
//  PULPulsateManager.h
//  PULPulsate
//
//  Created by Michal on 04/12/2014.
//  Copyright (c) 2014 Pulsatehq. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PULPulsateManagerDelegate.h"
#import <UIKit/UIKit.h>

@class UINavigationController;

@interface PULPulsateManager : NSObject

@property (nonatomic,weak) id<PULPulsateManagerDelegate> delegate;

-(void)startPulsate;

-(void)updateFirstName:(NSString*)firstName;

-(void)updateLastName:(NSString*)lastName;

-(void)updateEmail:(NSString*)email;

-(void)createAttribute:(NSString *)propertyName withString:(NSString *)value;

-(void)createAttribute:(NSString *)propertyName withFloat:(CGFloat)number;

-(void)createAttribute:(NSString *)propertyName withInteger:(NSInteger)number;

-(void)createAttribute:(NSString *)propertyName withBoolean:(BOOL)boolean;

-(void)createAttribute:(NSString *)propertyName withDate:(NSDate*)date;

-(void)incrementIntegerAttribute:(NSString*)attributeName withInteger:(NSInteger)value;

-(void)decrementIntegerAttribute:(NSString*)attributeName withInteger:(NSInteger)value;

-(void)incrementFloatAttribute:(NSString*)attributeName withFloat:(CGFloat)value;

-(void)decrementFloatAttribute:(NSString*)attributeName withFloat:(CGFloat)value;

-(void)startLocation;

-(void)startRemoteNotifications;

-(UINavigationController*)getInboxNavigationController;

@end
