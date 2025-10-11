#include "global.h"
#include <termination>

void app_run()
{
    std::cout.sync_with_stdio(false);
    vector_conversion vec;
    vec.run_loop_for<void>(&vector_conversion::get_string_length);
    vec.run_loop_for<void>(&vector_conversion::print_min_and_max_length);
    vec.run_loop_for<void>(&vector_conversion::print_smallest_and_biggest_word);
    termination_prompt();
}