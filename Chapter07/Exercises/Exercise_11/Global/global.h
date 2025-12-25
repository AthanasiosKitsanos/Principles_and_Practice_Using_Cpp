#pragma once
#include "v_handler.h"
#include <iostream>
#include <vector>
#include <termination>

void start();
int get_size();
bool is_valid(const int& size);
vector_handler* initialize_vector_handler(const int& size);
void free_memory(vector_handler*& ptr);