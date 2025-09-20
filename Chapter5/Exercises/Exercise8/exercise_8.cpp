#include "headers.h"
#include "flow_handler.h"

int main()
{
    flow_handler* app = flow_handler::initialize_handler();

    app->run();

    flow_handler::free_flow_handler(app);

    return 0;
}