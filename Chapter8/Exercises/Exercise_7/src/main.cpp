#include "application.h"
#include <iostream>

int main()
{
    console::application app;
    app.io_synchronization(false);
    app.run();
}