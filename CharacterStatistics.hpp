//
//  CharacterStatistics.hpp
//  Char Statistics
//
//  Created by Joseph Lyons on 10/11/17.
//  Copyright © 2017 Joseph Lyons. All rights reserved.
//

#ifndef CharacterStatistics_hpp
#define CharacterStatistics_hpp

class CharacterStatistics
{
private:
    long unsigned int characterLog[256] = {};
    long unsigned int sortedCharacterLog[256] = {};
    long unsigned int totalCharacters;
    
    long unsigned int countVowels (const bool &includeY) const;
    
public:
    CharacterStatistics();
    
    void logCharacter (const char &letter);
    void logStringOfCharacters (const std::string &string);
    void logFileOfCharacters (const char *filePath);
    void printLog() const;
    float vowelStatistics (const bool &includeY) const;
    
    long unsigned int getTotalCharacters() const;
};

#endif /* CharacterStatistics_hpp */
