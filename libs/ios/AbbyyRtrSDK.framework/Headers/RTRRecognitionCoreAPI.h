/// ABBYY® Real-Time Recognition SDK 1 © 2016 ABBYY Production LLC.
/// ABBYY is either a registered trademark or a trademark of ABBYY Software Ltd.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "RTRConstants.h"

#pragma mark - Definitions

@class RTRTextBlock;
@class RTRDataField;
@class RTRDataScheme;
@class RTRExtendedSettings;

@protocol RTRDataCaptureProfileBuilder;

@protocol RTRCoreAPIProcessingSettings;
@protocol RTRCoreAPIDataCaptureSettings;
@protocol RTRCoreAPITextRecognitionSettings;

/**
 * Approximate progress of the operation.
 *
 * @param percentage The percentage of the current work that has already been done. It is in the range from 0 to 100.
 * @param warningCode A warning reported. Some corrections may be required.
 *
 * @return NO if the recognition process should be terminated.
 */
typedef BOOL (^RTRProgressCallbackBlock)(NSInteger percentage, RTRCallbackWarningCode warningCode);

/**
 * Text orientation is detected.
 *
 * The result is always returned in normalized coordinates (rotated to normal text orientation).
 *
 * @param angle The angle in degrees (0, 90, 180, 270) for the detected text orientation.
 */
typedef void (^RTRTextOrientationDetectedBlock)(NSInteger angle);

#pragma mark - RTRCoreAPISingleImageRecognizer

/**
 * Provides access to low-level single image core API functions for current thread. Should be used in the same thread in
 * which it was created. Multiple objects can be created in different threads and used concurrently.
 * All methods are synchronous (blocking) and should not be used in UI thread. For advanced users.
 */
@protocol RTRRecognitionCoreAPI
@required

/**
 * Basic settings applicable to most methods.
 */
@property (nonatomic, readonly) id<RTRCoreAPIProcessingSettings> processingSettings;
/**
 * Settings for text recognition.
 */
@property (nonatomic, readonly) id<RTRCoreAPITextRecognitionSettings> textRecognitionSettings;
/**
 * Extended CoreAPI configuration settings.
 * Settings intended for advanced users. Not used in common scenarios.
 */
@property (nonatomic, readonly) RTRExtendedSettings* extendedSettings;

/**
 * Recognize text on a still image.
 *
 * @param image Image to recognize.
 * @param progressCallback Approximate progress of the operation callback.
 * @param textOrientationDetectedCallback The block that is called when a text orientation is detected.
 * @param error The description of the error that has occurred.
 * @return An array of RTRTextBlock objects.
 */
- (NSArray<RTRTextBlock*>*)recognizeTextOnImage:(UIImage*)image onProgress:(RTRProgressCallbackBlock)progressCallback onTextOrientationDetected:(RTRTextOrientationDetectedBlock)textOrientationDetectedCallback error:(__autoreleasing NSError**)error;

@end

#pragma mark - RTRDataCaptureCoreAPI

/**
 * Provides access to low-level single image core API functions for current thread. Should be used in the same thread in
 * which it was created. Multiple objects can be created in different threads and used concurrently.
 * All methods are synchronous (blocking) and should not be used in UI thread. For advanced users.
 */
@protocol RTRDataCaptureCoreAPI
@required

/**
 * Basic settings applicable to most methods.
 */
@property (nonatomic, readonly) id<RTRCoreAPIProcessingSettings> processingSettings;
/**
 * Settings for data capture.
 */
@property (nonatomic, readonly) id<RTRCoreAPIDataCaptureSettings> dataCaptureSettings;

/**
 * Extended CoreAPI configuration settings.
 * Settings intended for advanced users. Not used in common scenarios.
 */
@property (nonatomic, readonly) RTRExtendedSettings* extendedSettings;

/**
 * Extract data from a still image.
 *
 * @param image Image to recognize.
 * @param progressCallback Approximate progress of the operation callback.
 * @param textOrientationDetectedCallback The block that is called when a text orientation is detected.
 * @param error The description of the error that has occurred.
 * @return An array of RTRDataField objects.
 */
- (NSArray<RTRDataField*>*)extractDataFromImage:(UIImage*)image onProgress:(RTRProgressCallbackBlock)progressCallback onTextOrientationDetected:(RTRTextOrientationDetectedBlock)textOrientationDetectedCallback error:(__autoreleasing NSError**)error;

@end

#pragma mark - RTRCoreAPIProcessingSettings

/**
 * Basic settings applicable to most methods.
 */
@protocol RTRCoreAPIProcessingSettings
@required

/**
 * The number of threads, zero if the number should be determined automatically (by default is set to zero).
 */
@property (nonatomic, assign) NSInteger processingThreadsCount;

@end

#pragma mark - RTRCoreAPITextRecognitionSettings

/**
 * Settings for text recognition.
 */
@protocol RTRCoreAPITextRecognitionSettings
@required

/**
 * Sets the area on the image where the text is to be found.
 *
 * By default, no area of interest is selected.
 *
 * @param areaOfInterest The rectangle specifying the area of interest in image coordinates. Pass CGRectZero for default value.
 */
- (void)setAreaOfInterest:(CGRect)areaOfInterest;

/**
 * Sets the languages to be used for recognition.
 *
 * Setting the correct languages for your text will improve
 * recognition accuracy. However, setting too many languages may slow down performance.
 *
 * @param recognitionLanguages The set of languages to be used for recognition.
 */
- (void)setRecognitionLanguages:(NSSet<NSString*>*)recognitionLanguages;

@end

#pragma mark - RTRCoreAPIDataCaptureSettings

/**
 * Settings for data capture.
 */
@protocol RTRCoreAPIDataCaptureSettings
@required

/**
 * Sets the area on the image where the text is to be found.
 *
 * By default, no area of interest is selected.
 *
 * @param areaOfInterest The rectangle specifying the area of interest in image coordinates. Pass CGRectZero for default value.
 */
- (void)setAreaOfInterest:(CGRect)areaOfInterest;

/** The predefined profile. */
@property (nonatomic, copy) NSString* profile;

/**
 * Creates a profile builder object with which you will be able to configure the Data Capture Core API
 * to recognize a custom field.
 *
 * @return Profile builder object or nil in unsupported scenarios.
 */
- (id<RTRDataCaptureProfileBuilder>)configureDataCaptureProfile;

@end
