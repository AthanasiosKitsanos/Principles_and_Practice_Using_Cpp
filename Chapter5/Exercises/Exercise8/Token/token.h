#pragma once

class token
{
    public:
        int value;
        char kind;

        token();
        token(char c);
        token(char c, int val);
        ~token();
};