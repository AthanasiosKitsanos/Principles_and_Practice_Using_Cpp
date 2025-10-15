#pragma once
#include "month.h"
#include <vector>

class date;
struct year;
struct day;

std::vector<date*> ptr_table;

void run();
date* allocate_date();
date* allocate_date(const date& d);
void deallocate_date(date*& ptr);
void deallocate_date_all();