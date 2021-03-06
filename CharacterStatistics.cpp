//
//  CharacterStatistics.cpp
//  Char Statistics
//
//  Created by Joseph Lyons on 10/11/17.
//  Copyright © 2017 Joseph Lyons. All rights reserved.
//

#include <iostream>
#include <fstream>
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

long unsigned  CharacterStatistics::countVowels (const bool &includeY) const
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
    
    return vowelCount;
}

void CharacterStatistics::logCharacter (const char &letter)
{
    characterLog[(int) letter]++;
    totalCharacters++;
}

void CharacterStatistics::logStringOfCharacters (const std::string &string)
{
    for (int i = 0; i < string.size(); i++)
    {
        logCharacter (string[i]);
    }
}

void CharacterStatistics::logFileOfCharacters (const char *filePath)
{
    std::ifstream fileIn;
    
    fileIn.open (filePath);
    
    if (fileIn.fail())
    {
        return;
    }
    
    char letter = fileIn.get();
    
    while(!fileIn.eof())
    {
        logCharacter (letter);
        letter = fileIn.get();
    }
    
    fileIn.close();
}

void CharacterStatistics::printLog() const
{
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

float CharacterStatistics::vowelStatistics (const bool &includeY) const
{
    return countVowels (includeY) / (float) getTotalCharacters();
}

long unsigned int CharacterStatistics::getTotalCharacters() const
{
    return totalCharacters;
}
