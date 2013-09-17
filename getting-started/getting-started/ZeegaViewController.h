//
//  ZeegaViewController.h
//  Getting-started
//
//  Created by Luís Brandão on 9/16/13.
//  Copyright (c) 2013 Luís Brandão. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ZeegaViewController : UIViewController
- (IBAction)configureMessage:(id)sender;
@property (weak, nonatomic) IBOutlet UITextField *textField;
@property (weak, nonatomic) IBOutlet UILabel *textLabel;

@end
