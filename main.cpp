//
//  main.cpp
//  Main file that runs and tests and Lexer Class.
//
//  Created by Nhat Nguyen on 9/15/16.
//  Created by Jake Cliff on 9/15/16.
//  Copyright © 2016 Nhat Nguyen & Jake Cliff. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Lexer.h"

using namespace std;

void useFile1(string fileName) {
	Lexer l(fileName);
}

void useFile2(string fileName) {
	Lexer l(fileName);
}

void useFile3(string fileName) {
	Lexer l(fileName);
}

void Stdin() {
	Lexer l;
}

int main() {
	string inFileName1 = "a2-sample-1.txt";
	string inFileName2 = "a2-sample-2.txt";
	string inFileName3 = "a2-sample-3.txt";
    
	cout << "What do you want to test? 1. Sample-1  2. Sample-2  3. Sample-3 4. Stdin: ";
	int choice;
	string blank;
	cin >> choice;
	getline(cin, blank);
	
	switch (choice) {
	case 1: useFile1(inFileName1); break;
	case 2: useFile2(inFileName2); break;
	case 3: useFile3(inFileName3); break;
	case 4: Stdin(); break;
	}
    
	string line;
	cout << "Press ENTER to exit program..." << endl;
	getline(cin, line);

    return 0;
}