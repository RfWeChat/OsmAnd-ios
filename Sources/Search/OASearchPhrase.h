//
//  OASearchPhrase.h
//  OsmAnd
//
//  Created by Alexey Kulish on 11/01/2017.
//  Copyright © 2017 OsmAnd. All rights reserved.
//
//  revision 878491110c391829cc1f42eace8dc582cb35e08e

#import <Foundation/Foundation.h>
#import "OANameStringMatcher.h"
#import "OAObjectType.h"
#import <CoreLocation/CoreLocation.h>
#import "OASearchResult.h"

#include <OsmAndCore/Data/DataCommonTypes.h>

typedef NS_ENUM(NSInteger, EOASearchPhraseDataType)
{
    P_DATA_TYPE_MAP = 0,
    P_DATA_TYPE_ADDRESS,
    P_DATA_TYPE_ROUTING,
    P_DATA_TYPE_POI
};

@class OASearchSettings, OASearchPhrase, QuadRect, OASearchWord;

@interface OASearchPhrase : NSObject

- (instancetype)initWithSettings:(OASearchSettings *)settings;

- (OASearchPhrase *) generateNewPhrase:(NSString *)text settings:(OASearchSettings *)settings;
- (NSMutableArray<OASearchWord *> *) getWords;
- (BOOL) isUnknownSearchWordComplete;
+ (BOOL) isSearchWordComplete:(NSString *)text;
- (BOOL) isLastUnknownSearchWordComplete;
- (NSMutableArray<NSString *> *) getUnknownSearchWords;
- (NSMutableArray<NSString *> *) getUnknownSearchWords:(NSSet<NSString *> *)exclude;
- (NSString *) getUnknownSearchWord;
- (NSString *) getUnknownSearchPhrase;
- (BOOL) isUnknownSearchWordPresent;
- (int) getUnknownSearchWordLength;
- (QuadRect *) getRadiusBBoxToSearch:(int)radius;
- (QuadRect *) get1km31Rect;
- (OASearchSettings *) getSettings;
- (int) getRadiusLevel;
- (OASearchPhrase *) selectWord:(OASearchResult *)res;
- (OASearchPhrase *) selectWord:(OASearchResult *)res unknownWords:(NSArray<NSString *> *)unknownWords lastComplete:(BOOL)lastComplete;
- (BOOL) isLastWord:(EOAObjectType)p;
- (OANameStringMatcher *) getNameStringMatcher;
- (BOOL) hasObjectType:(EOAObjectType)p;
- (void) syncWordsWithResults;
- (NSString *) getText:(BOOL)includeLastWord;
- (NSString *) getTextWithoutLastWord;
- (NSString *) getStringRerpresentation;
- (NSString *) toString;
- (BOOL) isNoSelectedType;
- (BOOL) isEmpty;
- (OASearchWord *) getLastSelectedWord;
- (CLLocation *) getWordLocation;
- (CLLocation *) getLastTokenLocation;
- (void) countUnknownWordsMatch:(OASearchResult *)sr;
- (void) countUnknownWordsMatch:(OASearchResult *)sr localeName:(NSString *)localeName otherNames:(NSMutableArray<NSString *> *)otherNames;
- (int) getRadiusSearch:(int)meters;

- (NSArray<NSString *> *) getRadiusOfflineIndexes:(int)meters dt:(EOASearchPhraseDataType)dt;
- (NSArray<NSString *> *) getOfflineIndexes:(QuadRect *)rect dt:(EOASearchPhraseDataType)dt;
- (NSArray<NSString *> *) getOfflineIndexes;

- (void) selectFile:(NSString *)resourceId;
- (void) sortFiles;


@end
