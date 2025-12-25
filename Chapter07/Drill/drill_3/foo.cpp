module foo;
import <iostream>;

int foo = 0;

void print_foo()
{
    std::cout << "foo = " << foo << std::endl;
    std::cout << "Press any key to exit...";
    std::cin.get();
}

void set_foo(int x) { foo = x; }

int get_foo() { return foo; }