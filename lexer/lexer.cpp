//
// Created by bailey on 3/14/20.
//

#include "lexer.h"

struct Token {
    unsigned int lineNo;
    TokenType type;
    std::string lexeme;
};

Lexer::Lexer() {
    buffer = new char[DOUBLE_BUFFER_SIZE];
    input = 0;
    fence = 0;
    fillBuffer(0, BUFFER_SIZE);
}

Token Lexer::getToken() {

}

void Lexer::setTokenType(Token &tok) {

}

Lexer::~Lexer() {
    delete[] buffer;
}

char Lexer::getChar() {
    char c = buffer[input];
    input = (input + 1) % DOUBLE_BUFFER_SIZE;

    if (input % BUFFER_SIZE == 0) { // Buffer has been exhausted, must fill buffer.
        fillBuffer(input, input + BUFFER_SIZE - 1);
        fence = (input + BUFFER_SIZE) % DOUBLE_BUFFER_SIZE;
    }

    return c;
}

void Lexer::rollback() {
    if (input == fence) {
        cerr << "Unable to rollback input buffer. Terminating execution." << endl;
        exit(1);
    }

    input = (input - 1) % DOUBLE_BUFFER_SIZE;
}

void Lexer::fillBuffer(int start, int end) {
    int i = start;
    for (char c; cin >> c && i <= end;)
        buffer[i] = c;
}

void Lexer::scanInit() {
    lexeme = "";

}
