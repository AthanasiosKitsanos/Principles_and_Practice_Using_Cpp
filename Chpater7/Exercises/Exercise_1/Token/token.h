#pragma once

class Token_Stream;

class Token
{
    public:
        double value;
        std::string name;
        char kind;       

        Token();
        Token(char k);
        Token(char k, double v);
        Token(char k, std::string n);
        Token(char k, std::string n, double v);
        
        ~Token();

        double statement(Token_Stream& t);
        double declaration(Token_Stream& t);
        double expression(Token_Stream& t);
        double term(Token_Stream& t);
        double primary(Token_Stream& t);
        double implement(Token_Stream& t);
};