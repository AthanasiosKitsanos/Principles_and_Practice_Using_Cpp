#include "headers.h"
#include "token.h"

token::token() {}
token::token(char c):kind(c) {}
token::token(char c, int val): kind(c), value(val) {}
token::~token() {}