#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.resize(400, 300);
    window.setWindowTitle("Chapter 10 Window");
    window.show();

    return app.exec();
}