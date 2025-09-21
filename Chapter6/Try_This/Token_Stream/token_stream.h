#pragma once

class Token;

class Token_Stream
{
    private:
        static bool is_full;
        static Token buffer;

    public:
        Token_Stream();
        ~Token_Stream();

        Token get();
        void putback(Token& token);
        void ignore(char c);
        bool is_alpha(char c);
        bool is_digit(char c);
};