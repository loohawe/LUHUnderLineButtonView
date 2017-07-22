# LUHUnderLineButtonView
 
#前言
在开发项目当中, 我需要用到一组特殊按钮, 效果如下:
![效果](https://github.com/Koneey/LUHUnderLineButtonView/blob/master/gif/LUHUnderLineButton.gif)
虽然现在 git 上现成的代码一抓一箩筐, 但是想来貌似我时间也不怎么值钱, 就加一会班写写看. 编码思路如下:

#分析
立马能想到的就是自己新建一个 View, 把按钮一个一个放上去, 点击按钮触发是事件, 移动按钮下的小白线(underLine).
新建的 View 需要暴露的接口有:
- 初始化方法, 需要传入按钮标题 **数组**
(nullable instancetype)initWithItems:(nullable NSArray *)items;
- 点击不同按钮时, 执行 action
(void)addTarget:(nullable id)target action:(nonnull SEL)action;

#实现
主要代码如下
添加按钮
```C
- (void)setButtons
{
    int i = 0;
    for (NSString *titleStr in _items) {
        UIButton *button = [[UIButton alloc] init];
        button.tag = 1000+i;
        [button setTitle:titleStr forState:UIControlStateNormal];
        [button setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
        [button addTarget:self action:@selector(buttonAction:) forControlEvents:UIControlEventTouchUpInside];
        [self addSubview:button];
        i++;
    }
    
    UIView *underLine = [[UIView alloc] init];
    underLine.backgroundColor = [UIColor whiteColor];
    underLine.tag = kLUHUnderLineButtonUnderLineTag;
    underLine.layer.cornerRadius = kLUHUnderLineButtonUnderLineHeight/2;
    [self addSubview:underLine];
}
```
计算位置
```
    CGFloat width = CGRectGetWidth(self.frame)/_items.count;
    CGFloat height = CGRectGetHeight(self.frame);
    for (int i = 0; i < _items.count; i++) {
        UIButton *button = (UIButton *)[self viewWithTag:1000+i];
        if (button != nil) button.frame = CGRectMake(i*width, 0, width, height);
    }
    
    UIView *underLine = [self viewWithTag:kLUHUnderLineButtonUnderLineTag];
    CGFloat underLineW = width - 2*kLUHUnderLineButtonUnderLinePadding;
    if (underLine != nil) {
        underLine.frame = CGRectMake(self.selectedIndex*underLineW + kLUHUnderLineButtonUnderLinePadding, height-kLUHUnderLineButtonUnderLineHeight,
                                     underLineW, kLUHUnderLineButtonUnderLineHeight);
    }
```

按钮点击之后
```
- (void)buttonAction:(UIButton *)button
{
    NSInteger index = button.tag-1000;
    if (index == self.selectedIndex) return;
    self.selectedIndex = index;
    if (self.action != nil) {
        [self.target performSelectorOnMainThread:self.action withObject:button waitUntilDone:NO];
    }
}
```

附 [源码](https://github.com/Koneey/LUHUnderLineButtonView)
