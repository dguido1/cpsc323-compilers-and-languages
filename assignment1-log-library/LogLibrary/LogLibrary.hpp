/*
    Name:               David Guido
    Course:             CPSC 323, Compilers and Languages
    Meeting Times:      T/TH 4:00pm - 5:15pm
    Date:               September 13, 2019
    Semester:           Fall 19'
 
    Assignment:         Programming Assignment 1 (Log Library)
 
    Files Included:     1.) LogLibrary.cpp
                        2.) LogLibrary.hpp
                        3.) main.cpp
                        4.) LogTest.log
****************************************************************
*/

#ifndef LogLibrary_hpp
#define LogLibrary_hpp

#include <stdio.h>

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
using namespace std;

namespace Logger
{
    class LogLibrary
    {
        public:
            enum Level      // LOG enum Level. (3 Levels)
            {
                INFO = 0,   // INFO:    Used for outputting info that is useful to management of program.
                WARNING,    // WARNING: Used for handled 'exceptions' or other important log events
                ERROR       // ERROR:   Used to log all unhandled exceptions.
            };
        
            fstream dataFile;                       // FStream Obj using for input/output of log file.
        
            LogLibrary();                           // Default Constructor.
            bool OpenLogIn(string fileName);        // Open fstream obj for input.
            bool OpenLogOut(string fileName);       // Open fstream obj for output (append mode).
        
            void CloseLog();                        // Close current fstream obj for input/output.
            void ReadLog(string inFileName);        // Read-in and Display Contents of Log File
            void WriteLog(unsigned int lineNumber, string functionName,    // Write to Log File.
                          Level logLevel, string logLineOutput);           // If file isn't found, create it.
            void FlushLog();                        // Flush Log File, causing stream buffer
                                                    // to flush its output buffer.
            ~LogLibrary();                          // Destructor.
    };
}
#endif /* LogLibrary_hpp */
