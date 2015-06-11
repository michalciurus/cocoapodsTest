/*
 * Copyright (c) 2013 Pulsate. All rights reserved.
 */
#import <Foundation/Foundation.h>

/**
  Main Pulsate 1.4.2 framework class. Contains all public methods needed for
  interaction with Pulsate platform.

  Use it for framework initialization, session ending, message box showing/hiding
  and setting user's custom parameters.
 */
@interface Pulsate : NSObject {

}

/**---------------------------------------------------------------------------------------
 * @name Initialization and session management
 *  ---------------------------------------------------------------------------------------
 */

/**
  This method initializes Pulsate framework and also invalidates framework configuration.
  It should be invoked in the application: didFinishLaunchingWithOptions: method of application
  delegate.

  Start session events are stored locally in both offline and online mode and will be synchronized
  when synchronization will occur.

  Method will raise an exception in case:
  - framework configuration is wrong

  To initialize Pulsate simply put [Pulsate startSession:launchOptions] in didFinishLaunchingWithOptions: method of
  your application's app delegate:

	- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

		[Pulsate startSession:launchOptions];

		self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
		self.window.rootViewController = ...;
		[self.window makeKeyAndVisible];

		return YES;
	}

  When session is initialized a session event is stored. In case phone is in an online mode Pulsate will synchronize events,
  for offline mode, only a session event will be stored, it will be synchronized latter.

  Pulsate tries to synchronize sessions and location change events when app goes to foreground and also on location change
  (for both standard location change and region change).

  @param launchOptions - application launch options, always provide it for proper processing of push notifications
 */
+ (void)startSession:(NSDictionary *)launchOptions;

/**
  Ends user session. Invoked will store user's session end event.
  When invoked two times one after another the second invocation will not take any effect.

  End session events are stored locally in both offline and online mode and will be synchronized
  when synchronization will occur.
 */
+ (void)endSession;

/**---------------------------------------------------------------------------------------
 * @name Configuration
 *  ---------------------------------------------------------------------------------------
 */

/**
  Forces reload of remote framework configuration. Use it to refresh remote configuration.
  New fetched configuration will be used on the next application launch.
 */
+ (void)reloadRemoteConfiguration;

/**---------------------------------------------------------------------------------------
 * @name Message inbox
 *  ---------------------------------------------------------------------------------------
 */
/**
  Shows message inbox. Use to open Pulsate message inbox.
  Message inbox will be opened as present modal view controller on top of application.
  Invocation when message inbox is displayed will not take any effect.

  To show a message inbox simply invoke the method:

	[Pulsate showMessageInbox]

  It will pop-up message inbox window on top of your application.
 */
+ (void)showMessageInbox;
  
/**
  Invoke it to hide displayed message inbox.
  Invocation when no message inbox is displayed will not take any effect.

  To hide a message inbox simply invoke the method:

	[Pulsate hideMessageInbox]

  Message inbox can be also closed by tapping on the message window "Close" button.
 */
+ (void)hideMessageInbox;

/**---------------------------------------------------------------------------------------
 * @name Updating properties
 *  ---------------------------------------------------------------------------------------
 */
  
/**
  Updates users email address. If set, email address will be stored for both online and offline use of application
  and synchronized when the next app synchronization will occur.

  If email is nil, empty string or incorrect email address, method invocation will raise an exception.

  For example:

	[Pulsate updateEmail:@"david@pulsatehq.com"]

  Will update user's email to david@pulsatehq.com.

  Email is stored locally and will be synchronized with server when next synchronization will occur.

  @param email - email address, it should be a valid email address,
 */
+ (void)updateEmail:(NSString *)email;

/**
  Updates users name. If set, username will be stored for both online and offline use of application
  and synchronized when the next app synchronization will occur.

  If username is nil or empty string, method invocation will raise an exception.

  For example:

	[Pulsate updateFullName:@"David Beckham"]

  Will update users name to David Beckham.

  Name is stored locally and will be synchronized with server when next synchronization will occur.

  @param fullName - full name, a non-empty string
 */
+ (void)updateFullName:(NSString *)fullName;

/**
  Updates user's custom property. If updated, custom property will be stored for both online and offline use of application
  and synchronized when the next app synchronization will occur.

  Will raise an exception if value or key will be empty or nil.

  To update a custom property, for example a brand of user's car you simply invoke the method providing property name
  and its value:

	[Pulsate updateProperty:@"car" withValue:@"Audi"]

  The execution of above line of code will update a "car" property with "Audi" value.

  All properties are stored locally and will be synchronized with server when next synchronization will occur.

  @param propertyName - property name, a not empty string
  @param value - value of property, must be a not empty string
 */
+ (void)updateProperty:(NSString *)propertyName withValue:(NSString *)value;

/**---------------------------------------------------------------------------------------
 * @name Managing counters
 *  ---------------------------------------------------------------------------------------
 */

/**
  Increments counter with given name by provided value.

  If provided value is equal 0 method invocation takes no effect,
  if value is lower than 0 or counter name is not a non-empty string
  method will rise an exception.

  In order to increment a counter, invoke the method by providing counter name and the value by which it should be incremented.

  For example:


	[Pulsate incrementCounter:@"number_of_transactions" by:1]

  Will increment counter named number_of_transaction by 1, if counter will be incremented for the first time,
  it will be created and initialized with 0 value, then incremented by 1.

  All counter operations are stored locally and synchronized with Pulsate server when synchronization occurs.

  @param counterName - name of counter which should be incremented, a not empty string
  @param by - value, should be a positive integer
 */
+ (void)incrementCounter:(NSString *)counterName by:(int)by;

/**Decrements a counter with provided name by a provided value.


  If provided value is equal 0 method invocation takes no effect,
  if value is higher than 0 or counter name is not a non-empty string
  method will rise an exception.

  In order to decrement a counter, invoke the method by providing counter name and the value by which it should be incremented.

  For example:

	[Pulsate decrementCounter:@"number_of_transactions" by:1]

  Will decrement counter named number_of_transaction by 1, if counter will be decremented for the first time,
  it will be created and initialized with 0 value, then decremented by 1.

  All counter operations are stored locally and synchronized with Pulsate server when synchronization occurs.

  @param counterName - name of counter which should be decremented, a not empty string
  @param by - value, should be a negative integer
 */
+ (void)decrementCounter:(NSString *)counterName by:(int)by;

@end
