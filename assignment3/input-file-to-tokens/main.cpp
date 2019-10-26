/*
      Name:               David Guido
      Course:             CPSC 323, Compilers and Languages
      Meeting Times:      T/TH 4:00pm - 5:15pm
      Date:               October 25, 2019
      Semester:           Fall 19'
   
      Assignment:         Assignment 3a (Programming)
   
      Files Included:     1.) main.cpp
                          2.) TokenHandler.cpp
                          3.) TokenHandler.hpp
****************************************************************
 
 Token  Handler (C++)
    Tokenize the file and display specified results:
*/

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <iomanip>      // std::setw
#include <fstream>
#include "TokenHandler.hpp"

using namespace std;
    
//Main Function
int main(int argc, const char * argv[])
{
    string delimeters = ", ;=";
    vector<string> splitTokens;
    
    string inFileName = "data.txt";
    
    TokenHandler tokenHandler;  // Single-instance token handler.
    
    if (tokenHandler.openFileIn(inFileName))
        tokenHandler.readFile(inFileName);

    tokenHandler.split (tokenHandler.fileContents, delimeters, splitTokens);
    tokenHandler.print (splitTokens);
    
    return 0;
}
