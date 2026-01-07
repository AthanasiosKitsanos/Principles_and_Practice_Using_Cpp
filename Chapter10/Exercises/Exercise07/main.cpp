#include "main_window.h"

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    QApplication app{argc, argv};
    main_window win{};
    return app.exec();
}