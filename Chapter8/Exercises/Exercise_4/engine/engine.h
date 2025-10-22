#pragma once
#include "application.h"
#include "input_controller.h"

struct engine
{
    application app;
    bool running;
    engine();
    ~engine();

    void start();
};