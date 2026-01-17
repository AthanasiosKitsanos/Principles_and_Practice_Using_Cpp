#pragma once

#include "widget_pch.h"
#include "data_block.h"

constexpr int data_count{13};

class main_widget: public QWidget
{
    data_block data_list[data_count]
    {
        //data_block("Title", "Context", point_x, point_y, width, height, number_of_lines, data_index)
        data_block{frames_content{"Point.h:", "struct Point{...};"}, 0.2f, 0.1f, 1.0f, 0.2f, 0, data_index::point_1},
        data_block{frames_content{"Graph.h:", "// Graphing interface\nstruct Shape{...};\n..."}, 0.2f, 0.3f, 1.0f, 0.7f, 1, data_index::graph_1},
        data_block{frames_content{"Window.h:", "// Window interface\nstruct Window{...};\n..."}, 0.425f, 0.2f, 1.0f, 0.7f, 1, data_index::window_1},
        data_block{frames_content{"GUI.h:", "// GIU interface\nstruct Button{...};\n..."}, 0.75f, 0.25f, 1.0f, 0.7f, 1, data_index::gui_1},
        data_block{frames_content{"Simple Window.h:", "// Simple window interface\nstruct Simple_window{...};\n..."}, 0.415f, 0.5f, 1.2f, 0.75f, 1, data_index::simple_window_1},
        data_block{frames_content{"Ch10.cpp:", "int main() {...}"}, 0.3f, 0.8f, 1.0f, 0.2f, 2, data_index::ch10_1},
        data_block{frames_content{"", "Qt headers"}, 0.45f, 0.01f, 0.5f, 0.2f, 0, data_index::qtheaders},
        data_block{frames_content{"Graph.h:", "..."}, 0.2f, 0.1f, 0.5f, 0.2f, 0, data_index::graph_2},
        data_block{frames_content{"Window.h:", "..."}, 0.2f, 0.4f, 0.5f, 0.2f, 0, data_index::window_2},
        data_block{frames_content{"GUI.h:", "..."}, 0.2f, 0.7f, 0.5f, 0.2f, 0, data_index::gui_2},
        data_block{frames_content{"GUI_private.h:", "..."}, 0.35f, 0.2f, 0.5f, 0.2f, 2, data_index::gui_private_2},
        data_block{frames_content{"Window.cpp:", "Window code"}, 0.45f, 0.7f, 0.7f, 0.2f, 6, data_index::window_cpp_2},
        data_block{frames_content{"Image_private.h:", "..."}, 0.6f, 0.1f, 0.5f, 0.2f, 1, data_index::image_2}
    };
    QPixmap p1_buffer;
    QPixmap p2_buffer;
    QPixmap pixmap;
    QPixmap* current_pixmap;
    QPushButton* button;

    void paint_pixmaps(const int width, const int height) noexcept;
    void paint_pixmap_1(const int width, const int height, QRect& frame, QFont& font) noexcept;
    void paint_pixmap_2(const int width, const int height, QRect& frame, QFont& font) noexcept;

    private slots:
        void on_press();

    protected:
        void resizeEvent(QResizeEvent* event) override;
        void paintEvent(QPaintEvent*) override;

    public:
        explicit main_widget(QWidget* parent = nullptr) noexcept;
        ~main_widget() = default;
};