//
//  ZGADetailViewController.h
//  RKgist
//
//  Created by Luis Brandao on 9/17/13.
//  Copyright (c) 2013 Zeega. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ZGADetailViewController : UIViewController

@property (strong, nonatomic) id detailItem;

@property (weak, nonatomic) IBOutlet UILabel *detailDescriptionLabel;
@end
