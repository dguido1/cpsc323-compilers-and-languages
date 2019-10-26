/*
Name:               David Guido
Course:             CPSC 323, Compilers and Languages
Meeting Times:      T/TH 4:00pm - 5:15pm
Date:               September 13, 2019
Semester:           Fall 19'

Assignment:         Programming Assignment 2 (Identifier Check)

Files Included:     main.cpp
****************************************************************
*/

#include <iostream>
#include "IdentifierCheck.hpp"
#include <fstream>
#include <locale>         // std::locale, std::isalnum
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

using namespace std;

// Function Declarations.
void TestInputForIdentifier();
bool CheckCharAlphaNumberic (char charToCheck);
bool CheckCharAlphabetic (char charToCheck);
bool CheckCharUnderscore (char charToCheck);
bool CheckCharWhitespace (char charToCheck);
bool CheckCharArrayKeyword (char* str);
bool CheckIdentifierValidity (string stringToCheck);

int main()
{
TestInputForIdentifier();

return 0;
}

/*
     Identifier (Test Function Definition.
     - Function to chack if user input corresponds to a c++ identifier.
    
     C++ Identifier Rules
        1. C++ is case-sensitive so that Uppercase Letters and Lower Case letters are different
        2. The name of identifier cannot begin with a digit. However, Underscore can be used as first
            character while declaring the identifier.
        3. Only alphabetic characters, digits and underscore (_) are permitted in C++ language for
            declaring identifier. Other special characters are not allowed for naming a variable /
            identifier
         4. Keywords cannot be used as Identifier.
 
    Source: http://www.c4learn.com/cplusplus/cpp-identifiers-tokens/
*/
void TestInputForIdentifier()
{
string identifier;
string executionStatus = "y";
bool identifierValid = false;

while (executionStatus == "y")
{
    cout << "Enter a string: ";                                  // Ask for a user-defined identifier string.
    getline(cin, identifier);                                    // Recieve user-defined identifier string.
    
    identifierValid = CheckIdentifierValidity(identifier);       // Call CheckIdentifierValidity, store result in local var.
        
    if (identifierValid)                                         // If the user input strng is a valid identifier, print it.
        cout << identifier << " is an identifier.";
    else                                                         // If not, print an error message as well.
        cout << identifier << " is not an identifier.";
    
    cout << endl << "CONTINUE(y/n)?";                             // Print continue message.
    getline(cin, executionStatus);                                // Update execution status with user input.
}

cout << "Closing program..";
}

bool CheckIdentifierValidity (string stringToCheck)
{
char identifierCharStr[stringToCheck.length()];
    
    // Create a char array matching the user-defined identifier string.
identifierCharStr[stringToCheck.length() + 1];
stringToCheck.copy(identifierCharStr, stringToCheck.length() + 1);
identifierCharStr[stringToCheck.length()] = '\0';

    // Check if first element (char) is alphabetic or underscore.
if (CheckCharAlphabetic(identifierCharStr[0]) || CheckCharUnderscore(identifierCharStr[0]))
{
        // Check that that user-defined identifier string is not a keyword.
    if (!CheckCharArrayKeyword(identifierCharStr))
    {
            // Check if the remaining elements (chars) are NOT spaces & ARE alphanumeric or underscores.
        for (int i = 1; i < stringToCheck.length(); i++)
            if (CheckCharWhitespace(identifierCharStr[i])
            || (!CheckCharAlphaNumberic(identifierCharStr[i]) && !CheckCharUnderscore(identifierCharStr[i])) )
                return false;
    }
    else
        return false;
}
else
    return false;

return true;
}

bool CheckCharAlphaNumberic (char charToCheck)
{
return isalnum(charToCheck);
}

bool CheckCharAlphabetic (char charToCheck)
{
return isalpha(charToCheck);
}

bool CheckCharUnderscore (char charToCheck)
{
return (charToCheck == '_');
}

bool CheckCharWhitespace (char charToCheck)
{
return (charToCheck == ' ');
}

bool CheckCharArrayKeyword (char* str)
{
if (!strcmp(str, "auto") || !strcmp(str, "default")
    || !strcmp(str, "signed") || !strcmp(str, "enum")
    ||!strcmp(str, "extern") || !strcmp(str, "for")
    || !strcmp(str, "register") || !strcmp(str, "if")
    || !strcmp(str, "else")  || !strcmp(str, "int")
    || !strcmp(str, "while") || !strcmp(str, "do")
    || !strcmp(str, "break") || !strcmp(str, "continue")
    || !strcmp(str, "double") || !strcmp(str, "float")
    || !strcmp(str, "return") || !strcmp(str, "char")
    || !strcmp(str, "case") || !strcmp(str, "const")
    || !strcmp(str, "sizeof") || !strcmp(str, "long")
    || !strcmp(str, "short") || !strcmp(str, "typedef")
    || !strcmp(str, "switch") || !strcmp(str, "unsigned")
    || !strcmp(str, "void") || !strcmp(str, "static")
    || !strcmp(str, "struct") || !strcmp(str, "goto")
    || !strcmp(str, "union") || !strcmp(str, "volatile"))
    return (true);

return (false);
}
