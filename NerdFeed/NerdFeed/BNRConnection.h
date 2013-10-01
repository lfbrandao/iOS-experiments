//
//  BNRConnection.h
//  NerdFeed
//
//  Created by Luís Brandão on 9/30/13.
//  Copyright (c) 2013 Zeega. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BNRConnection : NSObject <NSURLConnectionDelegate, NSURLConnectionDataDelegate>
{
    NSURLConnection *internalConnection;
    NSMutableData *container;
}

- (id)initWithRequest:(NSURLRequest *)req;

@property (nonatomic, copy) NSURLRequest *request;
@property (nonatomic, copy) void (^completionBlock)(id obj, NSError *err);
@property (nonatomic, strong) id <NSXMLParserDelegate> xmlRootObject;

- (void)start;

@end
