#pragma once

class Token_Stream;

class Variable;

extern Token_Stream* ts_global;

extern std::vector<Variable> var_table;

void initialize_stream_pointer();

void initialize_vector();

void delete_stream_pointer();

void calculate();

void clean_up_mess();

void set_value(std::string s, double d);

double get_value(std::string s);

bool is_declared(std::string s);

double define_name(std::string var, double val);