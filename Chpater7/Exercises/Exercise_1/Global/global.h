#pragma once

#include "headers.h"
#include "symbol_table.h"
#include "token_stream.h"

extern Token_Stream ts_global;
extern Symbol_Table sym_table;

void show_variables();

void calculate(Token_Stream& t);

void clean_up_mess(Token_Stream t);

double get_value(std::string s);

void set_value(std::string s, double d);