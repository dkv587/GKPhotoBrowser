//
//  GKWebImageProtocol.h
//  GKPhotoBrowser
//
//  Created by QuintGao on 2017/11/14.
//  Copyright © 2017年 QuintGao. All rights reserved.
//

#import "GKPhotoBrowserConfigure.h"

typedef void (^GKWebImageProgressBlock)(NSInteger receivedSize, NSInteger expectedSize);

typedef void (^GKWebImageCompletionBlock)(UIImage * _Nullable image, NSURL * _Nullable url, BOOL finished, NSError * _Nullable error);

@protocol GKWebImageProtocol<NSObject>

/// 设置imageView类
- (Class _Nonnull)imageViewClass;

/// 为imageView设置图片
/// @param imageView imageView
/// @param url 图片url
/// @param placeholderImage 缺省图片
/// @param progressBlock 加载进度
/// @param completionBlock 完成进度
- (void)setImageForImageView:(nullable UIImageView *)imageView
                         url:(nullable NSURL *)url
            placeholderImage:(nullable UIImage *)placeholderImage
                    progress:(nullable GKWebImageProgressBlock)progressBlock
                  completion:(nullable GKWebImageCompletionBlock)completionBlock;

/// 根据data加载图片（主要用于显示GIF图片）
/// @param data 图片数据
- (UIImage *_Nullable)imageWithData:(nullable NSData *)data;

/// 取消imageView的图片请求
/// @param imageView imageView
- (void)cancelImageRequestWithImageView:(nullable UIImageView *)imageView;

/// 根据url从内存中获取图片
/// @param url url
- (UIImage *_Nullable)imageFromCacheForURL:(nullable NSURL *)url;

@end
