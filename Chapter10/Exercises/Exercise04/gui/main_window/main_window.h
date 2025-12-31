#include "pch.h"

constexpr int min_width = 600 * 0.2;
constexpr int max_width = 600 * 0.8;
constexpr int min_height = 400 * 0.2;
constexpr int max_height = 400 * 0.8;

class main_window: public QWidget
{
    protected:
        void paintEvent(QPaintEvent*) override;
    
    public:
        main_window(QWidget* parent = nullptr) noexcept;
        ~main_window() = default;
};