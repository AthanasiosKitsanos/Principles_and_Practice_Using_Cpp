#include "main_window.h"

int main(int argc, char* argv[])
{
    QApplication app{argc, argv};
    main_window m_window{};
    return app.exec();
}