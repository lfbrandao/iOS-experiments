//
//  ZGAMasterViewController.h
//  RKgist
//
//  Created by Luis Brandao on 9/17/13.
//  Copyright (c) 2013 Zeega. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <CoreData/CoreData.h>

@interface ZGAMasterViewController : UITableViewController <NSFetchedResultsControllerDelegate>

@property (strong, nonatomic) NSFetchedResultsController *fetchedResultsController;
@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;

@end
