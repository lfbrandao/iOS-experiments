//
//  ListViewController.m
//  NerdFeed
//
//  Created by Luís Brandão on 9/26/13.
//  Copyright (c) 2013 Zeega. All rights reserved.
//

#import "ListViewController.h"
#import "RSSChannel.h"
#import "RSSItem.h"

@implementation ListViewController

-(id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    
    if(self) {
        [self fetchEntries];
    }
    
    return self;
}

-(NSInteger)tableView:(UITableView *)tableView
    numberOfRowsInSection:(NSInteger)section
{
    return [[channel items] count];
}

-(UITableViewCell *)tableView:(UITableView *)tableView
    cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView
                             dequeueReusableCellWithIdentifier:@"UITableViewCell"];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault
                                      reuseIdentifier:@"UITableViewCell"];
    }
    RSSItem *item = [[channel items] objectAtIndex:[indexPath row]];
    [[cell textLabel] setText:[item title]];
    
    return cell;
}

-(void)fetchEntries
{
    [[BNRFeedStore sharedStore] fetchRSSFeedWithCompletion:^(RSSChannel *obj, NSError *err) {
         // When the request completes, this block will be called.
         if (!err) {
             // If everything went ok, grab the channel object, and
             // reload the table.
             channel = obj;
             
             [[self tableView] reloadData];
         } else {
             // If things went bad, show an alert view
             UIAlertView *av = [[UIAlertView alloc]
                                initWithTitle:@"Error"
                                message:[err localizedDescription]
                                delegate:nil
                                cancelButtonTitle:@"OK"
                                otherButtonTitles:nil];
             [av show];
         }
     }];
}

@end
