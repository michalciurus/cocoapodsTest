//
//  PULPulsateManagerDelegate.h
//  PULPulsate
//
//  Created by Michal on 02/01/2015.
//  Copyright (c) 2015 Pulsatehq. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol PULPulsateManagerDelegate <NSObject>

-(void)onPulsateEerror:(NSError*)error;

@end
