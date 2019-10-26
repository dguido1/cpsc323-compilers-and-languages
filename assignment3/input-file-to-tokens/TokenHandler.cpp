//
//  TokenHandler.cpp
//  InputFileToTokens
//
//  Created by David Guido on 10/25/19.
//  Copyright © 2019 csuf. All rights reserved.
//

#include "TokenHandler.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <iomanip>      // std::setw
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

    // Default Constructor.
TokenHandler::TokenHandler(){}

bool TokenHandler::openFileIn(string fileName)
{
    dataFile.open(fileName, ios::in);              // Open fstream obj for input.

    if (dataFile.fail())    // Check if log file is ready for input.
        return false;
    else
        return true;
}

void TokenHandler::readFile(string fileName)
{
    string readData;

    if (dataFile)           // Check if data file is open.
    {
        while (!dataFile.eof())
        {
            getline (dataFile, readData);
            fileContents = fileContents + "" + readData;
        }
    }
}

//Print function
//Prints all the values of the given vector.
//Uses call to parseToken.
void TokenHandler::print(vector<string>  &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        cout << std::left << std::setw(15) << input.at(i)
        << std::right << std::setw(3) << parseToken(input.at(i))
        << '\n';
    }
}

//Parse Token Function
//Returns the given string, followed by a tab and the input category result of thi.
string TokenHandler::parseToken(string& token)
{
    string reservedWords[] = {"int", "float"};
    int periodCount = 0;

    token = token.substr(0, token.find(' '));
            
    //Reserved word
    if (reservedWords[0].compare(token) == 0 || reservedWords[1].compare(token) == 0)
        return "RESERVED WORD";
    else if (isalpha(token[0]) != 0)  //Case (*Starts with a letter)
    {
        for (int j = 1; j < token.length(); j++)    //Loop through rest of token and check for ONLY alphabetic & numeric symbols
            if ((isalnum(token[j]) == 0))             //If somthing else is found, print INVALID (isalnum = is Alpha || Numeric)
                return "INVALID TOKEN";  //Case: INVALID
    
        return "IDENTIFIER";             //Case: IDENTIFIER
    }
    else if (isdigit(token[0]) != 0)   //Case (*Starts with a number)
    {
        for (int k = 1; k < token.length(); k++) //Loop through rest of token and check for ONLY numeric symbols
        {
            if (token[k] == '.')
                ++periodCount;
            else if (isdigit(token[k]) == 0)
                return "INVALID TOKEN";
        }
    }

    if (periodCount == 1)
        return "REAL NUMBER";           //Case: REAL NUMBER
    else if (periodCount > 1)
        return "NOT REAL NUMBER";           //Case: REAL NUMBER
    else
        return "INTEGER NUMBER";        //Case: INTEGER, only numeric values
}

void TokenHandler::split (const string& str, const string& delim, vector<string>& parts)
{
  size_t start, end = 0;
  while (end < str.size())
  {
    start = end;
    while (start < str.size() && (delim.find(str[start]) != string::npos))
      start++;  // skip initial whitespace
    
    end = start;
    while (end < str.size() && (delim.find(str[end]) == string::npos))
      end++; // skip to end of word
    
    if (end-start != 0) {  // just ignore zero-length strings.
      parts.push_back(string(str, start, end-start));
    }
  }
}

    // Destructor.
TokenHandler::~TokenHandler(){}
