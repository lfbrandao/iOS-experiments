//
//  BNRConnection.m
//  NerdFeed
//
//  Created by Luís Brandão on 9/30/13.
//  Copyright (c) 2013 Zeega. All rights reserved.
//

#import "BNRConnection.h"

static NSMutableArray *sharedConnectionList = nil;

@implementation BNRConnection

@synthesize request, completionBlock, xmlRootObject;

- (id)initWithRequest:(NSURLRequest *)req
{
    self = [super init];
    if (self) {
        [self setRequest:req];
    }
    return self;
}

- (void)start
{
    // Initialize container for data collected from NSURLConnection
    container = [[NSMutableData alloc] init];
    
    // Spawn connection
    internalConnection = [[NSURLConnection alloc] initWithRequest:[self request]
                                                         delegate:self
                                                 startImmediately:YES];
    
    if(!sharedConnectionList) {
        sharedConnectionList = [[NSMutableArray alloc] init];
    }
    
    [sharedConnectionList addObject:self];
}

- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data
{
    [container appendData:data];
}

- (void)connectionDidFinishLoading:(NSURLConnection *)connection
{
    // If there is a "root object"
    if ([self xmlRootObject]) {
        
        // Create a parser with the incoming data and let the root object parse
        // its contents
        NSXMLParser *parser = [[NSXMLParser alloc] initWithData:container];
        [parser setDelegate:[self xmlRootObject]];
        [parser parse];
    }
    
    // Then, pass the root object to the completion block - remember,
    // this is the block that the controller supplied.
    if ([self completionBlock])
        [self completionBlock]([self xmlRootObject], nil);
    
    // Now, destroy this connection
    [sharedConnectionList removeObject:self];
}

- (void)connection:(NSURLConnection *)connection
  didFailWithError:(NSError *)error
{
    // Pass the error from the connection to the completionBlock
    if ([self completionBlock])
        [self completionBlock](nil, error);
    
    // Destroy this connection
    [sharedConnectionList removeObject:self];
}

@end
