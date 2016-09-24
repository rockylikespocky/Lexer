//
//  Lexer.h
//
//  Created by Nhat Nguyen on 9/23/16.
//  Copyright © 2016 Nhat Nguyen. All rights reserved.
//

#ifndef Lexer_h
#define Lexer_h

#include <string>
#include <fstream>

using namespace std;

class Lexer {
public:
    Lexer();
    // empty constructor for standard input
    
    Lexer(string);
    // constructor opens file taking string of file name
    
    bool isInvalid(char);
    // if character is not in the language, returns true
    
    bool isSeparator(char);
    // if character is a separator, returns true
    
    bool isOperator(char);
    // if character is an operator, returns true
    
    bool isKeyword(string);
    // if string is a keyword, returns true
    
    bool atEndOfFile();
    // if at end of file, returns true
    
    void closeFile();
    // close file
    
private:
    ifstream inFile; // input stream
    
    int idNumber; // token ID number
    
    char current_char = ' '; // current character in line
    char next_char = ' '; // sneek peek at next character in line
    
    int lineCount = 1; // current line count in file
    string line; // string line read from input
    string token; // current string token
};

#endif /* Lexer_h */
