//
//  RSSItem.h
//  NerdFeed
//
//  Created by Luís Brandão on 9/30/13.
//  Copyright (c) 2013 Zeega. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RSSItem : NSObject <NSXMLParserDelegate>
{
    NSMutableString *currentString;
}

@property (nonatomic, weak) id parentParserDelegate;

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *link;

@end
