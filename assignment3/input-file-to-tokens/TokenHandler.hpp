//
//  TokenHandler.hpp
//  InputFileToTokens
//
//  Created by David Guido on 10/25/19.
//  Copyright © 2019 csuf. All rights reserved.
//

#ifndef TokenHandler_hpp
#define TokenHandler_hpp

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class TokenHandler
{
    public:
        fstream dataFile;                       // FStream Obj using for input/output of log file.
        string fileContents;
    
        TokenHandler();                           // Default Constructor.
        bool openFileIn(string fileName);        // Open fstream obj for input.
        void readFile(string fileName);        // Open fstream obj for input.
        void print(vector<string>  &input);
        string parseToken(string& token);
        void split (const string& str, const string& delim, vector<string>& parts);
        void CloseLog();                        // Close current fstream obj for input/output.

                                                // to flush its output buffer.
        ~TokenHandler();                          // Destructor.
};

#endif /* TokenHandler_hpp */
