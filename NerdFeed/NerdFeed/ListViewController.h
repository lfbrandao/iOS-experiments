//
//  ListViewController.h
//  NerdFeed
//
//  Created by Luís Brandão on 9/26/13.
//  Copyright (c) 2013 Zeega. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BNRFeedStore.h"

@class RSSChannel;

@interface ListViewController : UITableViewController
{
    RSSChannel *channel;
}
@end
