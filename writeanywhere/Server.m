#import <MRYIPCCenter.h>

@interface MCWriteAnywhere : NSObject
- (void)writeFile:(NSDictionary*)args;
@end

@implementation MCWriteAnywhere {
    MRYIPCCenter* _center;
}

+ (void)load
{
    [self sharedInstance];
}

+ (instancetype)sharedInstance
{
    static dispatch_once_t onceToken = 0;
    __strong static MCWriteAnywhere* sharedInstance = nil;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init];
    });
    return sharedInstance;
}

- (instancetype)init
{
    if ((self = [super init])) {
        _center = [MRYIPCCenter centerNamed:@"com.midnightchips.writeanywhere"];
        [_center addTarget:self action:@selector(writeFile:)];

        NSLog(@"[MCWriteAnywhere] running server in %@", [NSProcessInfo processInfo].processName);
    }
    return self;
}

- (void)writeFile:(NSDictionary*)args
{
    NSLog(@"[MCWriteAnywhere] running write file %@", [NSProcessInfo processInfo].processName);
    @try {
        NSString* filePath = args[@"filePath"];
        NSData* fileData = args[@"fileData"];
        NSFileManager* fm = [NSFileManager defaultManager];
        if (![fm fileExistsAtPath:filePath]) {
			NSString *parentPath = [filePath stringByDeletingLastPathComponent];
			[fm createDirectoryAtPath:parentPath withIntermediateDirectories:YES attributes:nil error:nil];
		}
        [fileData writeToFile:filePath atomically:YES];
    }
    @catch (NSException* exception) {
        NSLog(@"[MCWriteAnywhere] exception: %@", exception);
    }
}
@end