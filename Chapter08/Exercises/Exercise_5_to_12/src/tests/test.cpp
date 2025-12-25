#include "../../includes/tests/test.h"
#include <iostream>
#include <iomanip>

void print_table_row(const std::vector<std::string>& columns, const std::vector<int>& widths, bool left_align = true)
{
    for (size_t i = 0; i < columns.size(); ++i) {
        if (left_align)
            std::cout << std::left;
        else
            std::cout << std::right;

        std::cout << std::setw(widths[i]) << columns[i];
    }
    std::cout << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::vector<int> widths = {20, 10, 15};
    print_table_row({"Models", "Size", "Alignment"}, widths);
    print_table_row({"application", std::to_string(sizeof(console::application)), std::to_string(alignof(console::application))}, widths);
    print_table_row({"books", std::to_string(sizeof(models::books)), std::to_string(alignof(models::books))}, widths);
    print_table_row({"token", std::to_string(sizeof(models::token)), std::to_string(alignof(models::token))}, widths);
    print_table_row({"unordered_map", std::to_string(sizeof(std::unordered_map<std::string, utilities::command>)), std::to_string(alignof(std::unordered_map<std::string, utilities::command>))}, widths);
    print_table_row({"patron_manager", std::to_string(sizeof(core::patron_manager)), std::to_string(alignof(core::patron_manager))}, widths);
    print_table_row({"book_manager", std::to_string(sizeof(core::book_manager)), std::to_string(alignof(core::book_manager))}, widths);
    print_table_row({"patrons", std::to_string(sizeof(models::patron)), std::to_string(alignof(models::patron))}, widths);
    print_table_row({"transaction", std::to_string(sizeof(models::transaction)), std::to_string(alignof(models::transaction))}, widths);
    print_table_row({"copyright_date", std::to_string(sizeof(models::copyright_date)), std::to_string(alignof(models::copyright_date))}, widths);
    print_table_row({"input_stream", std::to_string(sizeof(input_stream)), std::to_string(alignof(input_stream))}, widths);
    print_table_row({"transaction_manager", std::to_string(sizeof(core::transaction_manager)), std::to_string(alignof(core::transaction_manager))}, widths);
}