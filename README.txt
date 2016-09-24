PROJECT GROUP MEMBERS:
1. Nhat "Rocky" Nguyen			CWID: 894875020
2. Jake Cliff				CWID: 893637256

GROUP IDENTIFIER: NNJ

BUGS:
- Does not have the 99 ID for error detection. Only takes proper input.

FEATURES:
- Has 4 options at start of application: Test sample file 1, 2, or 3 and also Stdin.


COMPLETED:
- Sample output is identical.
- Displays output with proper formatting.
- Detects tokens.
- Detects token categories/types.
- Organized code and documentation.

NOT COMPLETED:
- Does not properly display IDnumber 99 for errors.
- Does not use function name next_token.

USE OF THE PROGRAM:
- Compile & execute command line application.
- Input files should be in the same directory as main.cpp
- Enter: 1 for a2-sample-1.
- Enter: 2 for a2-sample-2.
- Enter: 3 for a2-sample-3.
- Enter: 4 to submit input via Stdin.
- An output file is created called "output.txt".

FUNCTION AUTHORS:
Function Name			|			Author
main							Nhat Nguyen
Lexer()							Nhat Nguyen
Lexer(string)						Nhat Nguyen
void printOutput					Jake Cliff
void setTokenID()					Jake Cliff
void resetFIelds()					Jake Cliff
isComment(char, char)					Jack Cliff
isSpace()						Jake Cliff
isUnpariedDelimiters()					Nhat Nguyen
isPunctuation()						Jake Cliff
isDelimiter()						Nhat Nguyen
isMultiOperator()					Jake Cliff
isKeyword()						Nhat Nguyen
atEndOfFile()						Nhat Nguyen
closeFile()						Jake Cliff
endingProcess()						Nhat Nguyen