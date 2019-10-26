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

#include "LogLibrary.hpp"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace Logger
{
        // Default Constructor.
    LogLibrary::LogLibrary(){}

        // Open Log File for input.
    bool LogLibrary::OpenLogIn(string fileName)
    {
        dataFile.open(fileName, ios::in);              // Open fstream obj for input.

        if (dataFile.fail())    // Check if log file is ready for input.
            return false;
        else
            return true;
    }
    
        // Open Log File for output.
    bool LogLibrary::OpenLogOut(string fileName)
    {
        dataFile.open(fileName, std::ios_base::app);   // Open fstream obj for output (append mode).
        
        if (dataFile.fail())    // Check if log file is ready for output.
            return false;
        else
            return true;
    }

        // Close Log File.
    void LogLibrary::CloseLog()
    {
        dataFile.close();       // Close current fstream obj for input/output.
    }

        // Read-in and Display Contents of Log File.
    void LogLibrary::ReadLog(string fileName)
    {
        string readData;

        if (dataFile)           // Check if data file is open.
        {
            while (!dataFile.eof())
            {
                getline (dataFile, readData);
                cout << readData << endl;
            }
            
            FlushLog();     // Call FlushLog(), causing the stream buffer to flush its output buffer.
        }
    }

        // Write to Log File. If file isn't found, create it.
    void LogLibrary::WriteLog(unsigned int lineNumber, string functionName, Level logLevel, string logLineOutput)
    {
        if (dataFile)                       // Check if data file is open.
        {
            time_t now = time(0);           // Current date/time based on current system.
            tm *ltm = localtime(&now);      // Convert to string form.
            
            dataFile <<
            "Time/Date: " << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec <<   // Date/Time.
            ", Line Number: " << lineNumber <<           // Line Number.
            ", Calling Function: " << functionName <<    // Calling Function.
            ", Type: ";                                  // Log Type. (INFO, WARNING, ERROR)
            
            switch (logLevel)
            {
                case INFO:                             // Log Level 00:
                        dataFile << "INFO";            // Append Log Type INFO to current log output buffer.
                    break;
                    
                case WARNING:                          // Log Level 01:
                        dataFile << "WARNING";         // Append Log Type WARNING to current log output buffer.
                    break;
                    
                case ERROR:                             // Log Level 02:
                        dataFile << "ERROR";            // Append Log Type ERROR to current log output buffer.
                    break;
            }
            
            dataFile << ", Message: " + logLineOutput << endl;
        }
    }

        // Flush Log File, causing stream buffer to flush its output buffer.
    void LogLibrary::FlushLog()
    {
        dataFile.flush();
    }

        // Destructor. (Already closed file in CloseLog() function.)
    LogLibrary::~LogLibrary(){}
}
