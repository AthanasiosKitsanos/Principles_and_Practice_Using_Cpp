#include "../includes/console/smart_ptr.h"
#include "../application/application.h"

int main()
{
    console::smart_ptr app{};

    app.initialize();
    app->io_synchronization(false);
    app->use_library();
    app->use_patron();
    
    app->run();
}