#import <Foundation/Foundation.h>

// Define PlayerType as an NS_ENUM
typedef NS_ENUM(NSInteger, PlayerType) {
    PlayerTypeUnknown,
    PlayerTypeLive,
    PlayerTypeVOD,
    // Add more types as needed
};

@interface TWAnalyticsController : NSObject
+ (instancetype)analyticsController;
@end

@interface HTTPManager : NSObject
+ (instancetype)defaultManager;
@end

@interface TWHLSProvider : NSObject

/**
 * Initialize a TWHLSProvider instance.
 *
 * @param analyticsController The analytics controller.
 * @param httpManager The HTTP manager.
 * @param playerType The player type.
 *
 * @return An initialized TWHLSProvider instance.
 */
- (instancetype)initWithAnalyticsController:(TWAnalyticsController *)analyticsController
                               httpManager:(HTTPManager *)httpManager
                                playerType:(PlayerType)playerType;

- (NSString *)playerTypeStringForRequestType:(NSInteger)requestType;
- (void)requestManifest;
@end

@interface LiveHLSURLProvider : TWHLSProvider
@end

@interface IVSPlayer : NSObject
@property(nonatomic, copy) NSURL *path;
@end

@implementation TWHLSProvider

// Implementation of TWHLSProvider
// ...

@end

static PlayerType playerType = PlayerTypeUnknown;
static NSMutableDictionary<NSString *, TWHLSProvider *> *providers;
