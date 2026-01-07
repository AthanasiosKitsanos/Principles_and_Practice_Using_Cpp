#include "house_pch.h"

class chimney
{
    QLine l_part;
    QLine t_part;
    QLine r_part;

    public:
        explicit chimney() noexcept;
        ~chimney() = default;

        void set_chimney(int x, int y) noexcept;
        void draw_chimney(QPainter& painter) noexcept;
};