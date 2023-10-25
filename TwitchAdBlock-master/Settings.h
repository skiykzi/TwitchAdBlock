#import <UIKit/UIKit.h>
#import <substrate.h>

// Define constants using static or const
static NSString *const PROXY_URL = @"https://proxy.level3tjg.me/:path";

// Use meaningful names and proper comments
@interface UIFont (TwitchCoreUI)
@property(class) UIFont *twitchBodyFont;
@end

@interface TWDefaultThemeManager : NSObject
+ (instancetype)defaultManager;
@end

@protocol TWCoreUITheme <NSObject>
@required
@property(nonatomic, strong, readonly) UIColor *backgroundAccentColor;
@property(nonatomic, strong, readonly) UIColor *backgroundBodyColor;
@property(nonatomic, strong, readonly) UIColor *backgroundInputColor;
@end

@interface TWThemeableView : UIView

@property BOOL applyShadowPathForElevation;
@property id<TWCoreUITheme> lastConfiguredTheme;
@property TWDefaultThemeManager *themeManager;

- (instancetype)initWithFrame:(CGRect)frame themeManager:(TWDefaultThemeManager *)themeManager;

@end

@interface StandardTextField : TWThemeableView <UITextFieldDelegate>
@end

@interface TWAdBlockProxyTextField : StandardTextField
@end

@interface TWThemeableTableViewCell : UITableViewCell
@end

@interface TWBaseTableViewCell : TWThemeableTableViewCell
@end

@interface TWAdBlockProxyTextFieldTableViewCell : TWBaseTableViewCell

@property(nonatomic, strong) TWAdBlockProxyTextField *proxyTextField;

@end

@interface TwitchSwitchTableViewCell : UITableViewCell

@property BOOL isOn;
@property id delegate;

- (void)configureWithTitle:(NSString *)title
                 subtitle:(NSString *)subtitle
                isEnabled:(BOOL)isEnabled
                     isOn:(BOOL)isOn
  accessibilityIdentifier:(NSString *)accessibilityIdentifier;

@end

@interface TWBaseTableViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>

@property UITableView *tableView;

- (instancetype)initWithTableViewStyle:(NSInteger)style themeManager:(id)themeManager;

@end

@interface PreferenceSettingsViewController : TWBaseTableViewController
@end

@interface SettingsDisclosureCell : TWBaseTableViewCell
@end

@interface AppSettingsViewController : TWBaseTableViewController
@end

@interface AdBlockSettingsViewController : TWBaseTableViewController

@property(nonatomic, assign) BOOL adblock;
@property(nonatomic, assign) BOOL notify;
@property(nonatomic, assign) BOOL proxy;
@property(nonatomic, assign) BOOL customProxy;

@end
