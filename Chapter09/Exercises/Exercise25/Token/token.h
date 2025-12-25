#pragma once

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

        double statement();
        double declaration();
        double expression();
        double term();
        double primary();
        double implement(Token t);
};