//
//  YXUserSearchBar.h
//  SearchDemo
//
//  Created by ljjun on 15/9/22.
//  Copyright © 2015年 ljjun. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol YXUser;
@class YXUserSearchBar;

@protocol YXUserSearchBarDelegate <NSObject>
@optional

- (BOOL)searchBarShouldBeginEditing:(YXUserSearchBar *)searchBar;

- (BOOL)searchBarShouldEndEditing:(YXUserSearchBar *)searchBar;

- (void)searchBar:(YXUserSearchBar *)searchBar textDidChange:(NSString *)searchText;

- (void)searchBar:(YXUserSearchBar *)searchBar removeUser:(id <YXUser>)user;
@end


@interface YXUserSearchBar : UIView<UIScrollViewDelegate,UITextFieldDelegate>

@property (weak, nonatomic) id <YXUserSearchBarDelegate> delegate;
@property (weak, nonatomic) UIScrollView *userScrollView;
@property (weak, nonatomic) UITextField *searchTextView;

- (void)setText:(NSString *)text;

- (void)addUser:(id <YXUser>)user;
- (void)removeUser:(id <YXUser>)user;
@end

