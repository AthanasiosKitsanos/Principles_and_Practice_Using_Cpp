#include "main_window.h"

/*
When the shape is bigger that the window, then it is drawn only the parts it allows it,
as for making the window bigger than the screen, the OS tries to resize it to the maximum screen resolution of the screen
In this exercise I created a button that changes what appears on the window.
When the program runs, the rectangle is not visible until you make the window's size bigger.
When you press the button, it resizes the window to be bigger than the my screens width and height.
2 programs in 1
*/


int main(int argc, char* argv[])
{
    QApplication app{argc, argv};
    main_window window{};
    window.show();
    return app.exec();
}