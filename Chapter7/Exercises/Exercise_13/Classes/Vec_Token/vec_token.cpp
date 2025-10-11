#include "vec_token.h"

vec_token::vec_token(const std::string& w, const int& l):word(w), length(l) {}
vec_token::~vec_token() {}

std::string vec_token::get_word()
{
    return word;
}

int vec_token::get_length()
{
    return length;
}

void vec_token::set_word(const std::string& w)
{
    word = w;
}

void vec_token::set_length(const int& l)
{
    length = l;
}