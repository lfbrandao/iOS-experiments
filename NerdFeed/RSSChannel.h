//
//  RSSChannel.h
//  NerdFeed
//
//  Created by Luís Brandão on 9/27/13.
//  Copyright (c) 2013 Zeega. All rights reserved.
//

#import <Foundation/Foundation.h>
@class RSSItem;

@interface RSSChannel : NSObject <NSXMLParserDelegate>
{
    NSMutableString *currentString;
}

@property (nonatomic, weak) id parentParserDelegate;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *infoString;
@property (nonatomic, readonly, strong) NSMutableArray *items;
@end
