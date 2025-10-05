# Programming: Principles and Practice Using C++

**_Programming: Principles and Practice Using C++_**  
by the writer **Bjarne Stroustrup**.

---

**Solutions I came up with for solving the exercises and the drills**

In **_Chapter 7 and later_** there is a function named `termination_prompt()` 
and class named `TerminationException`.  
They are part of a **custom header file** I created called `termination`  
to skip some repetitive typing during exercises.

```cpp
    #ifndef TERMINATION_PROMT
    #define TERMINATION_PROMT

    #include <iostream>
    #include <limits>

    class TerminationException: std::exception
    {
        std::string message;

        public:
            explicit TerminationException(const std::string& msg): message(msg) {}

            const char* what()
            {
                return message.c_str();
            }
    };

    inline void termination_prompt()
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Press any key to exit...";
        std::cin.get();
    }

    #endif
```


**P.S: Run the .exe files for testing**