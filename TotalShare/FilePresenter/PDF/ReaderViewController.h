//
//	ReaderViewController.h
//	Reader v2.0.0
//
//	Created by Julius Oklamcak on 2011-07-01.
//	Copyright © 2011 Julius Oklamcak. All rights reserved.
//
//	This work is being made available under a Creative Commons Attribution license:
//		«http://creativecommons.org/licenses/by/3.0/»
//	You are free to use this work and any derivatives of this work in personal and/or
//	commercial products and projects as long as the above copyright is maintained and
//	the original author is attributed.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>

#import "ReaderDocument.h"
#import "ReaderContentView.h"
#import "ReaderMainToolbar.h"
#import "ReaderMainPagebar.h"

#import "SGManager.h"

@class ReaderViewController;
@class ReaderMainToolbar;
@class ReaderScrollView;

@protocol ReaderViewControllerDelegate <NSObject>

@required // Delegate protocols

- (void)dismissReaderViewController:(ReaderViewController *)viewController;

@end

@interface ReaderViewController : UIViewController <UIScrollViewDelegate, UIGestureRecognizerDelegate, MFMailComposeViewControllerDelegate,
													ReaderMainToolbarDelegate, ReaderMainPagebarDelegate, ReaderContentViewDelegate, SGPresentationHandler>
{
@private // Instance variables

	ReaderDocument *document;

	ReaderMainToolbar *mainToolbar;

	ReaderMainPagebar *mainPagebar;

	ReaderScrollView *theScrollView;

	NSMutableDictionary *contentViews;

	UIPrintInteractionController *printInteraction;

	NSInteger currentPage;

	NSDate *lastHideTime;

	BOOL isVisible;
}

@property (strong, nonatomic) UIDocument *document;

@property (nonatomic, assign, readwrite) id <ReaderViewControllerDelegate> delegate;

- (id)initWithReaderDocument:(ReaderDocument *)object;

@end
