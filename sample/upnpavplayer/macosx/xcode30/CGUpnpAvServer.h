//
//  CGUpnpAvServer.h
//  CyberLink for C
//
//  Created by Satoshi Konno on 08/07/02.
//  Copyright 2008 Satoshi Konno. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import <CyberLink/UPnP.h>

#import <CGUpnpAvContentDirectory.h>

@class CGUpnpDevice;
@class CGUpnpAvObject;

/**
 * The CGUpnpAvServer class is a UPnP/AV media server class.
 */
@interface CGUpnpAvServer : CGUpnpDevice
{
	CGUpnpAvContentDirectory *contentDirectory;
}
@property(readonly) CGUpnpAvContentDirectory *contentDirectory;
/**
 * Create a new UPnP/AV server.
 * 
 * @return New instance if successfull; otherwise nil.
 */
- (id) init;
/**
 * Create a new UPnP/AV server with the C instance.
 * 
 * @return New instance if successfull; otherwise nil.
 */
- (id) initWithCObject:(CgUpnpDevice *)cobj;
- (NSArray *)browse:(NSString *)objectId;
- (CGUpnpAvObject *)objectForTitlePath:(NSString *)titlePath;
@end
