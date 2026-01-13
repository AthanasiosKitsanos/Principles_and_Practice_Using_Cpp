#pragma once

#include "widget_pch.h"
#include "show_data.h"

constexpr int data_count{13};

enum class data_index: short {point_1, graph_1, window_1, gui_1, simple_window_1, ch10_1, graph_2, window_2, gui_2, gui_private_2, window_cpp_2, image_2};

class main_widget: public QWidget
{
    show_data data_list[data_count] = 
    {
        ///show_data("Title", "Context", point_x, point_y, width, height, number_of_lines)
        show_data{"Point.h:", "struct Point{...};", 0.2f, 0.1f, 1.0f, 0.2f, 0},
        show_data{"Graph.h:", "// Graphing interface\nstruct Shape{...};\n...", 0.2f, 0.3f, 1.0f, 0.7f, 1},
        show_data{"Window.h:", "// Window interface\nstruct Window{...};\n...", 0.425f, 0.2f, 1.0f, 0.7f, 1},
        show_data{"GUI.h:", "// GIU interface\nstruct Button{...};\n...", 0.75f, 0.25f, 1.0f, 0.7f, 1},
        show_data{"Simple Window.h:", "// Simple window interface\nstruct Simple_window{...};\n...", 0.415f, 0.5f, 1.2f, 0.75f, 1},
        show_data{"Ch10.cpp:", "int main() {...}", 0.3f, 0.8f, 1.0f, 0.2f, 2},
        show_data{"Graph.h:", "...", 0.2f, 0.1f, 0.5f, 0.2f, 0},
        show_data{"Window.h:", "...", 0.2f, 0.4f, 0.5f, 0.2f, 0},
        show_data{"GUI.h:", "...", 0.2f, 0.7f, 0.5f, 0.2f, 0},
        show_data{"GUI_private.h:", "...", 0.35f, 0.2f, 0.5f, 0.2f, 2},
        show_data{"Window.cpp:", "Window code", 0.45f, 0.7f, 0.7f, 0.2f, 6},
        show_data{"Image_private.h:", "...", 0.6f, 0.1f, 0.5f, 0.2f, 1},
        show_data{"", "Qt headers", 0.45f, 0.01f, 0.5f, 0.2f, 0}
    };
    data_index index;
    QPixmap p1_buffer;
    QPixmap p2_buffer;
    QPixmap pixmap;
    QPixmap* current_pixmap;
    QPushButton* button;

    void paint_pixmaps(const int width, const int height) noexcept;
    void paint_pixmap_1(const int width, const int height, QRect& frame, QFont& font) noexcept;
    void paint_pixmap_2(const int width, const int height, QRect& frame, QFont& font) noexcept;
    void draw_arrows(const data_index& index, const show_data& data, QPainter& painter);

    private slots:
        void on_press();

    protected:
        void resizeEvent(QResizeEvent* event) override;
        void paintEvent(QPaintEvent*) override;

    public:
        explicit main_widget(QWidget* parent = nullptr) noexcept;
        ~main_widget() = default;
};