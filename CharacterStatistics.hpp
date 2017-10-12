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
    int characterLog[256] = {};
    int totalCharacters;
    
    int countVowels(const bool &includeY) const;
    
public:
    CharacterStatistics();
    void logCharacter(const char &letter);
    void printLog() const;
    float vowelStatistics(const bool &includeY) const;
    
    int getTotalCharacters() const;
};

#endif /* CharacterStatistics_hpp */
