/// ABBYY® Real-Time Recognition SDK 1 © 2016 ABBYY Production LLC.
/// ABBYY is either a registered trademark or a trademark of ABBYY Software Ltd.

#import <AVFoundation/AVFoundation.h>

#import "RTRRecognitionService.h"

#pragma mark - RTRTextCaptureService

/**
 * A background text recognition service.
 */
@protocol RTRTextCaptureService <RTRRecognitionService>

/**
 * Sets the languages to be used for recognition.
 *
 * Setting the correct languages for your text will improve
 * recognition accuracy. However, setting too many languages may slow down performance.
 *
 * @param recognitionLanguages The set of languages to be used for recognition.
 */
- (void)setRecognitionLanguages:(NSSet*)recognitionLanguages;

/**
 * Sets the name of the translation dictionary.
 *
 * By default, no translation dictionary is used. Translation dictionaries should be
 * put in the 'Translation' subfolder of the app bundle.
 *
 * @param dictionaryName The name of the translation dictionary. Set nil for default value.
 */
- (void)setTranslationDictionary:(NSString*)dictionaryName;

@end
