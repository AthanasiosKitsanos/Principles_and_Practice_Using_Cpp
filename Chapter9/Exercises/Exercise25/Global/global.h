#pragma once

#include "headers.h"
#include "symbol_table.h"

class Token_Stream;
class Variable;
class Token;

extern Token_Stream* ts_global;

extern Symbol_Table sym_table;

void initialize_stream_pointer();

void delete_stream_pointer();

void show_variables();

void show_functions();

void calculate();

void clean_up_mess();

double get_value(std::string s);

void set_value(std::string s, double d);