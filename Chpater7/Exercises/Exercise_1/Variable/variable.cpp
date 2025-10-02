#include "variable.h"

Variable::Variable(std::string var, double val, bool is_c):name(var), value(val), is_const(is_c) {}
Variable::~Variable() {}