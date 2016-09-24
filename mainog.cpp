//
//  main.cpp
//  Lexer
//
//  Created by Nhat Nguyen on 9/15/16.
//  Copyright © 2016 Nhat Nguyen. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isOperator(char c);
bool isSeparator(char c);
bool isKeyword(string input);

int main(int argc, const char * argv[]) {
    string filename = "input.txt";
    ifstream newFile;
    
    newFile.open(filename);
    
    if (newFile.is_open()) {
        cout << "Success: File is opened." << endl;
    }
    if (!newFile.is_open()) {
        cout << "Error: File won't open." << endl;
    }
    
    cout << "Token" << " " << "Lexeme" << endl;
    
    char c = ' ';
    string buffer;
    string type;
    
    int count = 1;
    
    while (true) {
        char line[256];
        
        newFile.getline(line, 256);
        cout << count << endl;
        
        count += 1;
        if (newFile.eof()) {
            newFile.close();
            break;
        }
    }
    
    // Original Code
    ifstream inFile;
    inFile.open(filename);
    
    while ( inFile.get(c) ) {
        
        if (isspace(c)) {
            continue;
        }
        // c is now the first char after whitespace
        
        // check if a comment is in the line
        char c2 = 'p';
        if (c == '/' && c2 == '/'){
            // skip entire line
        }
        
        if (isSeparator(c)) { // token is a separator, check for 2-char
            cout << "Sepr: ";
            if (c == '$' && inFile.peek() == '$') {
                inFile.get(c); // skip second $
                cout << "$$" << endl;
            }
            else {
                cout << c << endl;
            }
        }
        else if (isOperator(c)) { // current token is an operator, check for 2-char
            cout << "Oper: ";
            if ( (c=='=' || c=='!' || c=='<' || c=='>') && inFile.peek() == '=') { // 2 char operator
                cout << c;
                inFile.get(c);
                cout << c << endl;
            }
            else {
                cout << c << endl;
            }
        }
        else if (isdigit(c)) { // current token is int or real
            buffer += c;
            while (isdigit(inFile.peek())) {
                inFile.get(c);
                buffer += c;
            }
            if (inFile.peek() == '.') { // token is a real
                inFile.get(c);
                buffer += c;
                while (isdigit(inFile.peek())) {
                    inFile.get(c);
                    buffer += c;
                }
                cout << "Real: " << buffer << endl;
            }
            else { // token is an int
                cout << "Int:  " << buffer << endl;
            }
        }
        else if (isalpha(c)) { // current token is keyword or identifier
            buffer += c;
            while ( isalpha(inFile.peek()) || isdigit(inFile.peek()) ) {
                inFile.get(c);
                buffer += c;
            }
            if (isKeyword(buffer)) {
                cout << "Keyw: " << buffer << endl;
            }
            else {
                cout << "Iden: " << buffer << endl;
            }
        }
        else {
            cout << "Invalid character: " << c << endl;
            return 1;
        }
        
        buffer = "";
    }
    
    inFile.close();
    cout << endl;
    
    return 0;
}

bool isOperator(char c) {
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

bool isSeparator(char c) {
    return (
            c == '('
            || c == ')'
            || c == ';'
            || c == ','
            || c == '{'
            || c == '}'
            || c == '$'
            );
}

bool isKeyword(string input) {
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