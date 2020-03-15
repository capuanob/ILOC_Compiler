//
// Created by bailey on 3/14/20.
//

#ifndef ILOC_LEXER_H
#define ILOC_LEXER_H

#include <string>
#include <iostream>
#include <stack>

#include "dfa.h"

using namespace std;

#define BUFFER_SIZE 4096
#define DOUBLE_BUFFER_SIZE BUFFER_SIZE * 2

enum TokenType {
    MEMOP, LOADI, ARITHOP, OUTPUT, NOP, CONSTANT, REGISTER, COMMA, INTO, OTHER
}; // Enumerates types of tokens supported by language

const string literalTokenTypes[] = { "MEMOP", "LOADI", "ARITHOP", "OUTPUT", "NOP",
                                       "CONSTANT", "REGISTER", "COMMA", "INTO", "OTHER"};

struct Token; // Fundamental processing unit of a parser, produced by the scanner

class Lexer {
public:
    Lexer();
    ~Lexer();

    /**
     * @return next token from input
     */
    Token getToken();

    /**
     * Returns the provided token to the buffer
     * @param token Token to be returned to token stack
     */
    void returnToken(Token);

private:
    char* buffer; // Pointer to array of characters to be processed in the heap
    int input; // Index of character acquisition
    int fence; // Index of start of valid context
    std::string lexeme; // Word currently being processed
    stack<state> s;
    /**
     * @brief Returns next character from buffer and decides if buffer must be filled
     * @return next character from buffer
     */
    char getChar();

    /**
     * @brief Returns buffer state to previous character
     */
    void rollback();

    /**
     * @brief Fills the buffer from stdin in a specified range
     * @param start Beginning index in buffer to fill from
     * @param end Ending index in buffer to fill through
     */
    void fillBuffer(int start, int end);

    /**
     * Determines and sets a token lexeme's type
     * @param tok: Token to be modified
     */
    void setTokenType(Token& tok);

    // Functions representing states
    void scanInit();
    void scan();

};


#endif //ILOC_LEXER_H
