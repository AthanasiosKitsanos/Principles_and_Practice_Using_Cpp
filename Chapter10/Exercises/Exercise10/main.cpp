#include "pch.h"
#include "main_widget.h"

int main(int argc, char* argv[])
{
    QApplication app{argc, argv};
    main_widget wid{};
    return app.exec();
}