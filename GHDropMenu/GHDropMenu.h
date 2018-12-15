//
//  GHDropMenu.h
//  GHDropMenuDemo
//
//  Created by zhaozhiwei on 2018/12/14.
//  Copyright © 2018年 GHome. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GHDropMenuHeader.h"

NS_ASSUME_NONNULL_BEGIN

/** 菜单类型 */
typedef NS_ENUM (NSUInteger,GHDropMenuType ) {
    /** 标题 */
    GHDropMenuTypeTitle = 1,
    /** 筛选菜单 */
    GHDropMenuTypeFilter,
};
@interface GHDropMenuModel :NSObject
@property (nonatomic , strong) NSArray *sections;
@property (nonatomic , assign) NSInteger tagIdentifier;

@property (nonatomic , strong) GHDropMenuModel *dropMenuTagModel;
/** sectionHeaderTitle */
@property (nonatomic , copy) NSString *sectionHeaderTitle;
@property (nonatomic , copy) NSString *sectionHeaderDetails;

/** 标签名称 */
@property (nonatomic , copy) NSString *tagName;
/** 标签选中状态 */
@property (nonatomic , assign) BOOL tagSeleted;

@property (nonatomic , assign) GHDropMenuType dropMenuType;
/** 标题 */
@property (nonatomic , copy) NSString *title;
@property (nonatomic , assign) NSInteger identifier;

@property (nonatomic , strong) UIFont *titleFont;
@property (nonatomic , assign) CGFloat menuHeight;
/** 标题被选中 */
@property (nonatomic , assign) BOOL titleSeleted;
/** 标题数组 */
@property (nonatomic , strong) NSArray *titles;
/** 数据源数组 */
@property (nonatomic , strong) NSArray *dataArray;

@property (nonatomic , assign) CGRect frame;

/** 顶部颜色 */
@property (nonatomic , strong) UIColor *titleViewBackGroundColor;
@property (nonatomic , strong) NSIndexPath *indexPath;

@end

@class GHDropMenu,GHDropMenuModel;
@protocol GHDropMenuDelegate <NSObject>
- (void)dropMenu: (GHDropMenu *)dropMenu dropMenuModel: (nullable GHDropMenuModel *)dropMenuModel tagArray: (NSArray *)tagArray;
@end
@interface GHDropMenu : UIView


/**
 初始化方法
 
 @param configuration GHDropMenuModel模型

 @return GHDropMenu
 */
- (instancetype)creatDropMenuWithConfiguration: (GHDropMenuModel *)configuration;
/** set方法 */
@property (nonatomic , strong) GHDropMenuModel *configuration;

@property (nonatomic , strong) UIColor *titleViewBackGroundColor;

@property (nonatomic , strong) UIFont *titleFont;

@property (nonatomic , weak) id <GHDropMenuDelegate>delegate;

- (void)resetMenuStatus;
@end

NS_ASSUME_NONNULL_END
