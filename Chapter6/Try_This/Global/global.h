#pragma once
#include "headers.h"

class Token_Stream;
class Variable;

extern Token_Stream* ts_global;

extern std::vector<Variable> var_table;

void initialize_stream_pointer();

void delete_stream_pointer();

void show_variables();

void show_functions();

void calculate();

void clean_up_mess();

double get_value(std::string s);

void set_value(std::string s, double d);