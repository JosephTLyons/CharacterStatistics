//
//  CharacterStatistics.cpp
//  Char Statistics
//
//  Created by Joseph Lyons on 10/11/17.
//  Copyright © 2017 Joseph Lyons. All rights reserved.
//

#include <iostream>
#include "CharacterStatistics.hpp"

CharacterStatistics::CharacterStatistics()
{
    // Zero out array
    for (int i = 0; i < 256; i++)
    {
        characterLog[i] = 0;
    }
    
    totalCharacters = 0;
}

void CharacterStatistics::logCharacter(const char &letter)
{
    characterLog[(int) letter] += 1;
    totalCharacters++;
}

void CharacterStatistics::printLog() const
{
    // Print printable characters (skip non-printables)
    for (int i = 0; i < 256; i++)
    {
        // Only print characters that have been logged
        if (characterLog[i] > 0)
        {
            std::cout << (char) i << ": ";
            std::cout << characterLog[i] << std::endl;
        }
    }
}

float CharacterStatistics::vowelStatistics(const bool &includeY) const
{
    int vowelCount = 0;
    
    vowelCount += characterLog[(int) 'a'];
    vowelCount += characterLog[(int) 'A'];
    vowelCount += characterLog[(int) 'e'];
    vowelCount += characterLog[(int) 'E'];
    vowelCount += characterLog[(int) 'i'];
    vowelCount += characterLog[(int) 'I'];
    vowelCount += characterLog[(int) 'o'];
    vowelCount += characterLog[(int) 'O'];
    vowelCount += characterLog[(int) 'u'];
    vowelCount += characterLog[(int) 'U'];
    
    if (includeY)
    {
        vowelCount += characterLog[(int) 'y'];
        vowelCount += characterLog[(int) 'Y'];
    }
    
    return vowelCount / (float) getTotalCharacters();
}

int CharacterStatistics::getTotalCharacters() const
{
    return totalCharacters;
}
