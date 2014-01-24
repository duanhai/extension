//
//  NSObject+CC.h
//  
//
//  Created by Michael Du on 13-5-23.
//  Copyright (c) 2013年 MichaelDu. All rights reserved.
//

#import <Foundation/Foundation.h>

#undef	SAFE_RELEASE
#define SAFE_RELEASE(object)            [object release];object=nil


@protocol KeyboardNotificationProtocol <NSObject>
@optional
- (void)keyboardWillShow:(CGRect)frame duration:(NSTimeInterval)duration;
- (void)keyboardDidShow:(CGRect)frame duration:(NSTimeInterval)duration;
- (void)keyboardWillHide:(CGRect)frame duration:(NSTimeInterval)duration;
- (void)keyboardDidHide:(CGRect)frame duration:(NSTimeInterval)duration;
- (void)keyboardWillChangeFrame:(CGRect)frame duration:(NSTimeInterval)duration;
- (void)keyboardDidChangeFrame:(CGRect)frame duration:(NSTimeInterval)duration;
@end


@interface NSObject (CC)

- (NSData *)toData;
- (NSDate *)toDate;
- (NSNumber *)toNumber;
- (NSString *)toString;

@end


@interface NSObject (Notification)<KeyboardNotificationProtocol>

- (void)registerKeyboardNotification;
- (void)removeKeyboardNotification;

- (void)registerNotification:(NSString *)name object:(id)object selector:(SEL)selector;
- (void)removeNotification:(NSString *)name;
- (void)removeAllNotifications;

- (void)postNotification:(NSString *)name;
- (void)postNotification:(NSString *)name object:(NSObject *)object;

@end
