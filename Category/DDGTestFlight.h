//
//  DDGTestFlight.h
//  DDGActivity
//
//  Created by Andrew Donoho on 2011/10/08.
//  Copyright 2011 Donoho Design Group, L.L.C. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const kLastCheckpointKey;

@protocol DDGTestFlight <NSObject>

@optional
//@required

@property (nonatomic, retain) NSString *lastCheckpoint;

/**
 Add custom environment information
 If you want to track a user name from your application you can add it here
 */
- (void) addCustomEnvironmentInformation: (NSString *) information forKey: (NSString*) key;

/**
 Starts a TestFlight session
 */
- (void) takeOff: (NSString *) teamToken;

/**
 Sets custom options
 Option                      Accepted Values                 Description
 reinstallCrashHandlers      [NSNumber numberWithBool:YES]   Reinstalls crash handlers, to be used if a third party 
 library installs crash handlers overtop of the TestFlight Crash Handlers
 */
- (void) setOptions: (NSDictionary *) options;

/**
 Track when a user has passed a checkpoint after the flight has taken off. Eg. passed level 1, posted high score
 */
- (void) passCheckpoint: (NSString *) checkpointName;

/**
 Opens a feeback window that is not attached to a checkpoint
 */
- (void) openFeedbackView;

@end