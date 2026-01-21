#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Symbol {
    string lexeme;
    string tokenType;
    int lineNumber;
};

string keywords[] = {
    "auto","break","case","char","const","continue","default","do","double",
    "else","enum","extern","float","for","goto","if","inline","int","long",
    "namespace","new","operator","private","protected","public","register",
    "return","short","signed","sizeof","static","struct","switch","template",
    "this","throw","try","typedef","union","unsigned","virtual","void",
    "volatile","while","class","bool","catch","using","true","false","cout","main"
};
string parenthesis[] = { "(", ")", "{", "}", "[", "]" };
string operators[] = { "+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">=", "<<" };
string separators[] = { ";", ",", ":" };

int keywordCount = sizeof(keywords) / sizeof(keywords[0]);
int parenthesisCount = sizeof(parenthesis) / sizeof(parenthesis[0]);
int operatorCount = sizeof(operators) / sizeof(operators[0]);
int separatorCount = sizeof(separators) / sizeof(separators[0]);

bool isStringLiteral(string s) {
    return s.length() >= 2 && s.front() == '"' && s.back() == '"';
}

bool isKeyword(string s) {
    for (int i = 0; i < keywordCount; i++) {
        if (s == keywords[i]) return true;
    }
    return false;
}

bool isParenthesis(string s) {
    for (int i = 0; i < parenthesisCount; i++) {
        if (s == parenthesis[i]) return true;
    }
    return false;
}

bool isOperator(string s) {
    for (int i = 0; i < operatorCount; i++) {
        if (s == operators[i]) return true;
    }
    return false;
}

bool isSeparator(string s) {
    for (int i = 0; i < separatorCount; i++) {
        if (s == separators[i]) return true;
    }
    return false;
}

bool isIdentifier(string s) {
    if (isKeyword(s)) return false;
    if (!((s[0] >= 'A' && s[0] <= 'Z') || (s[0] >= 'a' && s[0] <= 'z') || s[0] == '_'))
        return false;
    for (int i = 1; i < s.length(); i++) {
        if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9') || s[i] == '_'))
            return false;
    }
    return true;
}

bool isConstant(string s) {
    if (s.empty()) return false;
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) return false;
    }
    return true;
}

string getTokenType(string token) {
    if (isKeyword(token)) return "Keyword";
    if (isIdentifier(token)) return "Identifier";
    if (isConstant(token)) return "Constant";
    return "Unknown";
}

void addToken(Symbol symbolTable[], int &count, string lexeme, string tokenType, int lineNumber) {
    symbolTable[count].lexeme = lexeme;
    symbolTable[count].tokenType = tokenType;
    symbolTable[count].lineNumber = lineNumber;
    count++;
}

int main() {
    cout << "SYMBOL TABLE" << endl;

    ifstream inputFile("sample.txt");
    if (!inputFile.is_open()) {
        cout << "Unable to open file" << endl;
        return 0;
    }

    Symbol symbolTable[1000];
    int symbolCount = 0;
    string currentToken = "";
    bool inString = false;
    int lineNumber = 1;
    char ch;

    while (inputFile.get(ch)) {
        if (ch == '\n') {
            if (!currentToken.empty() && !inString) {
                addToken(symbolTable, symbolCount, currentToken, getTokenType(currentToken), lineNumber);
                currentToken = "";
            }
            lineNumber++;
        }
        else if (inString) {
            currentToken += ch;
            if (ch == '"') {
                inString = false;
                addToken(symbolTable, symbolCount, currentToken, "String Literal", lineNumber);
                currentToken = "";
            }
        }
        else if (ch == '"') {
            if (!currentToken.empty()) {
                addToken(symbolTable, symbolCount, currentToken, getTokenType(currentToken), lineNumber);
                currentToken = "";
            }
            inString = true;
            currentToken = "\"";
        }
        else if (ch == ' ' || ch == '\t' || ch == '\r') {
            if (!currentToken.empty()) {
                addToken(symbolTable, symbolCount, currentToken, getTokenType(currentToken), lineNumber);
                currentToken = "";
            }
        }
        else if (isParenthesis(string(1, ch)) || isOperator(string(1, ch)) || isSeparator(string(1, ch))) {
            if (!currentToken.empty()) {
                addToken(symbolTable, symbolCount, currentToken, getTokenType(currentToken), lineNumber);
                currentToken = "";
            }

            string currentOp(1, ch);
            char nextCh;
            if (inputFile.get(nextCh)) {
                string twoCharOp = currentOp + nextCh;
                if (isOperator(twoCharOp)) {
                    addToken(symbolTable, symbolCount, twoCharOp, "Operator", lineNumber);
                }
                else {
                    inputFile.unget();
                    if (isParenthesis(currentOp)) {
                        addToken(symbolTable, symbolCount, currentOp, "Parenthesis", lineNumber);
                    }
                    else if (isOperator(currentOp)) {
                        addToken(symbolTable, symbolCount, currentOp, "Operator", lineNumber);
                    }
                    else if (isSeparator(currentOp)) {
                        addToken(symbolTable, symbolCount, currentOp, "Separator", lineNumber);
                    }
                }
            }
            else {
                if (isParenthesis(currentOp)) {
                    addToken(symbolTable, symbolCount, currentOp, "Parenthesis", lineNumber);
                }
                else if (isOperator(currentOp)) {
                    addToken(symbolTable, symbolCount, currentOp, "Operator", lineNumber);
                }
                else if (isSeparator(currentOp)) {
                    addToken(symbolTable, symbolCount, currentOp, "Separator", lineNumber);
                }
            }
        }
        else {
            currentToken += ch;
        }
    }

    if (!currentToken.empty() && !inString) {
        addToken(symbolTable, symbolCount, currentToken, getTokenType(currentToken), lineNumber);
    }

    inputFile.close();


 

    int currentLine = 1;
    bool firstTokenInLine = true;
    
    for (int i = 0; i < symbolCount; i++) {
        if (symbolTable[i].lineNumber != currentLine) {
            if (!firstTokenInLine) {
                cout << endl;
            }
            currentLine = symbolTable[i].lineNumber;
            firstTokenInLine = true;
        }
        
        if (firstTokenInLine) {
            cout << "Line " << currentLine << ": ";
            firstTokenInLine = false;
        } else {
            cout << " || ";
        }
        
        cout << symbolTable[i].lexeme << " - " << symbolTable[i].tokenType;
    }
    cout << endl;

    return 0;
}
