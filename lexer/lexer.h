//
// Created by bailey on 3/14/20.
//

#ifndef ILOC_LEXER_H
#define ILOC_LEXER_H

#define BUFFER_SIZE 4096

struct Token; // Fundamental processing unit of a parser, produced by the scanner

class Lexer {
public:
    Lexer();

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
    char buffer[2 * BUFFER_SIZE]{};
    char* input, *fence; // Pointer to points of character insertion

    char getChar();

    void rollback();
};


#endif //ILOC_LEXER_H
