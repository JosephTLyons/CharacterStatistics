//
//  CharacterLog.hpp
//  Char Statistics
//
//  Created by Joseph Lyons on 10/11/17.
//  Copyright © 2017 Joseph Lyons. All rights reserved.
//

#ifndef CharacterLog_hpp
#define CharacterLog_hpp

class CharacterLog
{
private:
    int characterLog[256] = {};
    int totalCharacters;
    
public:
    CharacterLog();
    void logCharacter(const char &letter);
    void printLog() const;
    float vowelStatistics(const bool &includeY);
    
    int getTotalCharacters() const;
};

#endif /* CharacterLog_hpp */
