#pragma once

class Token_Stream;

extern Token_Stream* global_ts;

void init_global_pointer();
void delete_global_pointer();