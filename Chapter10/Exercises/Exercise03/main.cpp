#include "main_window.h"

int main(int argc, char* argv[])
{
    QApplication app{argc, argv};
    main_window win{};
    win.show();
    return app.exec();
}