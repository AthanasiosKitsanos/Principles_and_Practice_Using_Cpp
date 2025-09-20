#pragma once

class Name_Value
{
    public:
        std::string name = "";
        int score = 0;

        Name_Value(std::string& n, int& s);
        ~Name_Value();
};