#include "arrow_pointer.h"
#include <cmath>

constexpr double offset{std::numbers::pi / 8.0};

arrow_pointer::arrow_pointer() noexcept {}

void arrow_pointer::create_arrow(const QLine& line, double arrow_size)
{
    arrow_body = line;
    set_arrow_head(arrow_size);
}

void arrow_pointer::set_arrow_head(double arrow_size)
{
    double angle = std::atan2(-arrow_body.dy(), arrow_body.dx());
    QPoint temp_arrow_body(arrow_body.p2());
    arrow_head_1 = temp_arrow_body + QPoint(std::sin(angle + offset) * arrow_size, std::cos(angle + offset) * arrow_size);
    arrow_head_2 = temp_arrow_body + QPoint(std::sin(angle - offset) * arrow_size, std::cos(angle - offset) * arrow_size);
}