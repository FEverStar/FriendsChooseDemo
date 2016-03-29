//
//  UITextField+YX.h
//  SearchDemo
//
//  Created by ljjun on 15/9/22.
//  Copyright © 2015年 ljjun. All rights reserved.
//

#import <UIKit/UIKit.h>
@protocol YXTextFieldDelegate <UITextFieldDelegate>
@optional
- (void)textFieldDidDeleteBackward:(UITextField *)textField;
@end
@interface UITextField (YX)
@property (weak, nonatomic) id<YXTextFieldDelegate> delegate;
@end
/**
 *  监听删除按钮
 *  object:UITextField
 */
extern NSString * const YXTextFieldDidDeleteBackwardNotification;
