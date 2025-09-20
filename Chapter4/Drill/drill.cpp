#include "headers.h"

//This test was written with bugs. The purpose of this drill was to find every bug and fix it.
//The purpose it to print success
int main()
{
    try
    {
        std::cout << "Success!" << std::endl;   // It was Cout, not cout
        std::cout << "Success!" << '\n';        // Had no closing " and not a semi-column
        std::cout << "Success" << '\n';           // No "" at success and \n was in between ’ ’

        int res = 7; // Wrong type, changed from string to int 
        std::vector<int> v(10); 
        v[5] = res; 
        std::cout << "Success!\n";

        std::vector<int> b(10);
        b[5] = 7; // was v(5)
        if(b[5] == 7) // was v(5)
        {
            //We need to execute the code so changed the codnitionfrom != to ==
            std::cout << "Success!\n";
        }

        bool cond = true; // cond was not declared and initialized
        if(cond)
        {
            std::cout << "Success!\n";
        }
        else // else was inside the if(cond) statement
        {
            std::cout << "Fail!\n";
        }

        bool c = false;
        if(!c) // it was if(c)
        {
            std::cout << "Success!\n";
        }
        else // else was inside the if(c) statemant
        {
            std::cout << "Fail\n";
        }

        std::string s = "ape";
        std::string t = "fool"; //Wrong type changed it from boo to std::string and shared the same name with bool c
        if(s < t) // < t, ( < c before the cprrection was used after the declaration of boo c = "fool" < s)
        {
            std::cout << "Success!\n";
        }
        
        std::string d = "ape";
        if(s != "fool") // It was ==
        {
            std::cout << "Success!" << std::endl;
        }

        std::string f = "ape"; 
        if(s != "fool") // It was ==
        {
            std::cout << "Success!" << std::endl; // One operator < was missing
        }

        std::string g = "fool"; // The original implementation was s = "ape"
        if(s == "fool") // The condition was wrong '+'
        {
            std::cout << "Success!" << std::endl;
        }

        std::vector<char> q(5);
        for(int i = 0; i < q.size(); i++) // The condition was 0 < v.size()
        {
            std::cout << "Success!" << std::endl;
        }

        std::vector<char> n(5);
        for(int i = 0; i < n.size(); i++) // The condition was i <= v.size() out of range exception
        {
            std::cout << "Success!" << std::endl;
        }

        std::string h = "Success!\n";
        for(int i = 0; i < 9; i++) // It was i < 6
        {
            std::cout << h[i];
        }

        if(true) // It was if -> then instead of {}
        {
            std::cout << "Success!" << std::endl;
        }
        else
        {
            std::cout << "Fail!" << std::endl;
        }

        int x = 2000;
        char p = x;
        if(p == 2000)
        {
            std::cout << "Success!" << std::endl;
        }

        std::string a = "Success!\n";
        for(int i = 0; i < 9; i++) // It was i < 10, out of range exception
        {
            std::cout << a[i];
        }

        std::vector<char> m(5); // Missing the type
        for(int i = 0; i < m.size(); i++)
        {
            std::cout << "Success!" << std::endl;
        }

        int i = 0;
        int j = 9;
        while(i <= 10) // It was i < 10
        {
            i++; // It was j++
        }

        if(i > j)
        {
            std::cout << "Success!" << std::endl;
        }

        int o = 2;
        double e = 5 / o; // it was 5 / (o - 2), division by zero
        if(e == 2 * o + 0.5)
        {
            std::cout << "Success!" << std::endl;
        }

        std::string l = "Success!\n"; // It was string<char>
        for(int i = 0; i < 9; i++) // it was i <= 10 out of range exception
        {
            std::cout << l[i];
        }

        int y = 0;
        while(i < 10)
        {
            j++;
        }
        if(j < i)
        {
            std::cout << "Success!" << std::endl;
        }

        int z = 4;
        double r = 5 / (z - 2); 
        if (r == 2 / z + 0.5) // missing the comparison and it should be 2 * z + 0.5 equals to 8.5
        {
            std::cout << "Success!" << std::endl;
        }

        std::cout << "Succces!" << std::endl; // it was cin << "Success"

        std::cout << "Press any key to exit...";
        std::cin.get();

        return 0;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch(...)
    {
        std::cerr << "Oop: Unkown exception" << std::endl;

        return 2;
    }
}