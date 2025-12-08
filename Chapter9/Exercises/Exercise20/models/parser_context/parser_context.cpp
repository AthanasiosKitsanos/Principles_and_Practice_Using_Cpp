#include "parser_context.h"

parser_context::parser_context() {}
parser_context::parser_context(const char* front, const char* back): current(front), end(back) {}
parser_context::~parser_context() {}