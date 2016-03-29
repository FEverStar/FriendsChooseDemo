//
//  UITextField+YX.m
//  SearchDemo
//
//  Created by ljjun on 15/9/22.
//  Copyright © 2015年 ljjun. All rights reserved.
//

#import "UITextField+YX.h"
#import <objc/runtime.h>
NSString * const YXTextFieldDidDeleteBackwardNotification = @"com.whojun.textfield.did.notification";
@implementation UITextField (YX)
+ (void)load {
    //交换2个方法中的IMP
    Method method1 = class_getInstanceMethod([self class], NSSelectorFromString(@"deleteBackward"));
    Method method2 = class_getInstanceMethod([self class], @selector(YX_deleteBackward));
    method_exchangeImplementations(method1, method2);
}

- (void)YX_deleteBackward {
    [self YX_deleteBackward];
    
    if ([self.delegate respondsToSelector:@selector(textFieldDidDeleteBackward:)])
    {
        id <YXTextFieldDelegate> delegate  = (id<YXTextFieldDelegate>)self.delegate;
        [delegate textFieldDidDeleteBackward:self];
    }
    
    [[NSNotificationCenter defaultCenter] postNotificationName:YXTextFieldDidDeleteBackwardNotification object:self];
}
@end
