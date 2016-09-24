//
//  Lexer.cpp
//
//  Created by Nhat Nguyen on 9/15/16.
//  Copyright © 2016 Nhat Nguyen. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Lexer.h"

using namespace std;

Lexer::Lexer() {
    // code input using stdin getline
    
    while (getline(cin, line)) {
        cout << endl;
        cout << line << endl;
        
        // cout formatting
        string tok = "tok";
        int integerVal = 111;
        float floatVal = 3.14;
        cout << "(Tok: id= "
        << idNumber
        << " line= "
        << lineCount
        << " str= "
        << token
        << " int= " << integerVal << " float= " << floatVal
        << ")";
        
        lineCount += 1;
        
        if (cin.bad()) {
            // IO error
            break;
        }
        else if (cin.eof()) {
            break;
        }
    }
}

Lexer::Lexer(string file_name) {
    inFile.open(file_name);
    
    if (inFile.is_open()) {
        cout << "Success: File is opened." << endl;
    }
    if (!inFile.is_open()) {
        cout << "Error: File won't open." << endl;
    }
    
    while(!atEndOfFile()) {
        getline(inFile, line);
        cout << line << endl;
    }
}

bool Lexer::isInvalid(char some_char) {
    return (!
            (isSeparator(some_char)
             || isOperator(some_char)
             || isalnum(some_char)
             || (some_char == '.')
             ));
}

bool Lexer::isSeparator(char c) {
    return (
            c == '('
            || c == ')'
            || c == ';'
            || c == ','
            || c == '{'
            || c == '}'
            );
}

bool Lexer::isOperator(char c) {
    return (
            c == '='
            || c == '!'
            || c == '<'
            || c == '>'
            || c == '+'
            || c == '-'
            || c == '*'
            || c == '/'
            );
}

bool Lexer::isKeyword(string input) {
    return (
            input == "function"
            || input == "return"
            || input == "integer"
            || input == "int"
            || input == "real"
            || input == "boolean"
            || input == "if"
            || input == "else"
            || input == "read"
            || input == "write"
            || input == "while"
            || input == "for"
            );
}

bool Lexer::atEndOfFile() {
    if (!inFile) {
        return true;
    } else {
        return false;
    }
}

void Lexer::closeFile() {
    inFile.close();
}