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

#include <iostream>
#include "LogLibrary.hpp"

using namespace std;

    // Log Library Test Function Declaration.
void TestLogLibrary();

    // Main function.
int main()
{
    TestLogLibrary();   // Log Library Test Function Call.
    
    return 0;
}

    /*
         Log Library Test Function Definition.
         - Function to Test Log Library.

         1.) Asks user for a log file name to read from.
            --> 1.a) If it exists, the files contents are displayed.
         2.) The user is then asked for a file name to write to.
            ** Step 1, 2 loop, causing them to execute two additional times.
         3.) The user is then asked for a final file name to read from.
    */

void TestLogLibrary()
{
    Logger::LogLibrary logLibraryInstance;  // Single Log Library Instance. (Logger Namespace)
    
    string logInFileName;       // File name to read-in.
    string logOutFileName;      // File name to read-out.
    string logFileContents;     // User-defined message regaurding logging event.
    
    
    for (int i = 0; i < 3; i++)
    {
            // User-Input (Input File Name).
        cout << "Enter Input (.log) File Name: ";
        cin >> logInFileName;
        
            // Check if the user-defined file name exists.
        if (logLibraryInstance.OpenLogIn(logInFileName))          // Open log file for input.
        {
            cout << "Reading Input Log File.." << endl << endl;
            logLibraryInstance.ReadLog(logInFileName);            // Read-in & display file contents.
            cout << "Closing Input Log File." << endl;
            logLibraryInstance.CloseLog();                        // Close log file input.
        }
        else
            cout << "The File Name Doesn't Exist, Consider Creating It." << endl;
        
        logLibraryInstance.CloseLog();                            // Close log file input.
        cout << endl;
        
        
            // User-Input (Output File Name).
        cout << "Enter Output (.log) File Name: ";
        cin >> logOutFileName;
        logLibraryInstance.OpenLogOut(logOutFileName);           // Open log file for output.
        
        cout << "Enter Log Message: ";
        cin >> logFileContents;                                  // Read-in user-defined LOG message.
        
        cout << "Writing File Contents." << endl;
        logLibraryInstance.WriteLog(__LINE__, __func__,                             // Append current program
                                    Logger::LogLibrary::INFO, logFileContents);     // state to log file.
        
        cout << "Closing Output Log File." << endl << endl;
        logLibraryInstance.CloseLog();                             // Close log file output.
    }
    
        // User-Input (Input File Name).
    cout << "Enter Input (.log) File Name: ";
    cin >> logInFileName;
    
    if (logLibraryInstance.OpenLogIn(logInFileName))
    {
        cout << "Reading Input Log File.." << endl << endl;
        logLibraryInstance.ReadLog(logInFileName);            // Read-in & display file contents.
        cout << "Closing Input Log File." << endl;
    }
    else
        cout << "The File Name Doesn't Exist, Consider Creating It." << endl;
    
    logLibraryInstance.CloseLog();                            // Close log file input.

}
