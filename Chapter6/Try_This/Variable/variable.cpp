#include "variable.h"
#include "global.h"
#include "token.h"
#include "token_stream.h"

Variable::Variable(std::string s, double d):name(s), value(d) {}
Variable::~Variable() {}