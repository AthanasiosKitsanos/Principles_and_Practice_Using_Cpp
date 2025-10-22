#pragma once

class main_controller;

class application
{
    main_controller* mc_ptr;
    void initialize_main_controller();

    public:
        application();
        application(const application& other) = delete;
        application(application&& other) noexcept;
        ~application();

        main_controller* operator->();
        main_controller& operator*();
        application& operator=(application&& other) noexcept;
        application& operator=(const application& other) = delete;

        void initialize();
};