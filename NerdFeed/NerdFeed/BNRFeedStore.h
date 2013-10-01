//
//  BNRFeedStore.h
//  NerdFeed
//
//  Created by Luís Brandão on 9/30/13.
//  Copyright (c) 2013 Zeega. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RSSChannel.h"
#import "BNRConnection.h"

@interface BNRFeedStore : NSObject

+ (BNRFeedStore *)sharedStore;

- (void)fetchRSSFeedWithCompletion:(void (^)(RSSChannel *obj, NSError *err))block;

@end
