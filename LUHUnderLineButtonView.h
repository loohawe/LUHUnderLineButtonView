//
//  LUHUnderLineButtonView.h
//  pageView
//
//  Created by luhao on 15/10/27.
//  Copyright © 2015年 Hawe. All rights reserved.
//

#define kLUHUnderLineButtonUnderLineTag 2000
#define kLUHUnderLineButtonUnderLinePadding 10
#define kLUHUnderLineButtonUnderLineHeight 2

#import <UIKit/UIKit.h>

@interface LUHUnderLineButtonView : UIView
- (nullable instancetype)initWithItems:(nullable NSArray *)items;
- (void)addTarget:(nullable id)target action:(nonnull SEL)action;
@property (nonatomic) NSInteger selectedIndex;
@end
