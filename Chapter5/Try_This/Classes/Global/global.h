#pragma once

class Token_Stream;

extern Token_Stream* ts_global;

void initialize_stream_pointer();

void delete_stream_pointer();