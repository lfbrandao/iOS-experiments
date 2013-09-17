//
//  ZGAAppDelegate.h
//  RKgist
//
//  Created by Luis Brandao on 9/17/13.
//  Copyright (c) 2013 Zeega. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ZGAAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;

- (void)saveContext;
- (NSURL *)applicationDocumentsDirectory;

@end
