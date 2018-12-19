/// ABBYY® Real-Time Recognition SDK 1 © 2016 ABBYY Production LLC.
/// ABBYY is either a registered trademark or a trademark of ABBYY Software Ltd.

#import "RTREngine.h"

@protocol RTREngineSettings;
@protocol RTRDataCaptureService;
@protocol RTRDataCaptureServiceDelegate;

@class RTRExtendedSettings;

#pragma mark - RTREngine

@interface RTREngine (DataCapture)

/**
 * Additional engine settings.
 */
@property (nonatomic, readonly) id<RTREngineSettings> extendedSettings;

/**
 * Creates a background recognition DataCapture service.
 *
 * @param delegate The delegate object used to interact with the service.
 * @param profile The selected profile for DataCapture service.
 *
 * @return Data capture service that conforms to RTRDataCaptureService protocol.
 */
- (id<RTRDataCaptureService>)createDataCaptureServiceWithDelegate:(id<RTRDataCaptureServiceDelegate>)delegate profile:(NSString*)profile;

/**
 * Creates a background recognition DataCapture service.
 *
 * @param delegate The delegate object used to interact with the service.
 * @param profile The selected profile for DataCapture service.
 * @param settings The settings used to configure background recognition service.
 *
 * @return Data capture service that conforms to RTRDataCaptureService protocol.
 */
- (id<RTRDataCaptureService>)createDataCaptureServiceWithDelegate:(id<RTRDataCaptureServiceDelegate>)delegate profile:(NSString*)profile settings:(RTRExtendedSettings*)settings;

@end

#pragma mark - RTREngineSettings

@protocol RTREngineSettings
@required

/**
 * The additional path to search framework data.
 */
@property (nonatomic, copy) NSString* externalAssetsPath;

@end
