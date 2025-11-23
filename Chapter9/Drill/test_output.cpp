#include "models/pch.h"
#include "models/entity.h"
#include "models/point.h"

#define Debug

constexpr double example = 1234567.89;

struct enity
{
    std::string last_name;
    std::string name;
    std::string phone_number;
    std::string email;
};

void print_number(const char* input)
{
    if(strcmp(input, "defaultfloat") == 0) std::cout << "Default Float:\t" << std::defaultfloat << example << '\n';
    else if(strcmp(input, "fixed") == 0) std::cout << "Fixed:\t\t" << std::fixed << example << '\n' << std::defaultfloat;
    else if(strcmp(input, "scientific") == 0) std::cout << "Scientific:\t" << std::scientific << example << '\n' << std::defaultfloat << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    #ifndef Debug
        int birth_year{1993};
        
        std::cout << "Decimal:\t" << std::dec << birth_year << '\n'
        << "Hexadecimal:\t" << std::hex << birth_year << '\n'
        << "Octal:\t\t" << std::oct << birth_year << "\n\n";

        std::cout << "Age (decimal): " << std::dec <<birth_year << "\n\n";

        std::cout << "Show Base\n" <<  std::showbase
        << "Decimal:\t" << std::dec << birth_year << '\n'
        << "Hexadecimal:\t" << std::hex << birth_year << '\n'
        << "Octal:\t\t" << std::oct << birth_year << '\n' << std::endl;
    
        int a, b, c, d;
        std::cin >> a >> std::oct >> b >> std::hex >> c >> d;
        std::cout << a << '\t' << b << '\t' << c << '\t' << d << "\n\n";
        // output: 02322 01234 011064 011064 -> This happens because the last format is std::oct from the last output
        //before we use the the std::cout we should use std::cout << std::dec

        print_number("defaultfloat");
        print_number("fixed");
        print_number("scientific");
        //The most presice is the scientific

        enity e1{"Wick", "John",  "123456789", "johnwick@email.com"};
        enity e2{"Redigton", "Raymond", "6980488875", "raymondredigton@email.com"};
        enity e3{"Couper", "Harold", "456789123", "haroldcouper@email.com"};
        enity e4{"Kin", "Agnes", "123789456", "agneskin@email.com"};
        enity e5{"Ressler", "Donald", "987654321", "donaldressler@email.com"};

        std::cout << std::format("{:10} {:10} {:10} {:10}\n", e1.name, e1.last_name, e1.phone_number, e1.email)
        << std::format("{:10} {:10} {:10} {:10}\n", e2.name, e2.last_name, e2.phone_number, e2.email)
        << std::format("{:10} {:10} {:10} {:10}\n", e3.name, e3.last_name, e3.phone_number, e3.email)
        << std::format("{:10} {:10} {:10} {:10}\n", e4.name, e4.last_name, e4.phone_number, e4.email)
        << std::format("{:10} {:10} {:10} {:10}\n", e5.name, e5.last_name, e5.phone_number, e5.email) << std::endl;
    #endif

    std::vector<point> original_points;
    original_points.reserve(7);
    {
        point p;
        for(size_t index{0}; index < 7; ++index)
        {
            std::cin >> p;
            original_points.emplace_back(p);
        }
        std::cout << "Values accepter\n" << std::flush;
    }

    std::cout << "Passing the data to mydata.txt\n" << std::flush;
    {
        std::ofstream of{"mydata.txt"};
        of << original_points;
    }
    std::cout << "Output comleted\n" << std::flush;
    std::cin.get();
    
    std::vector<point> processed_data;
    processed_data.reserve(7);
    {
        std::ifstream ifs{"mydata.txt"};
        if(!ifs)
        {
            std::cout <<"File not found\n";
            return 1;
        }
        int count{0};
        for(point p; ifs >> p;)
        {
            processed_data.emplace_back(p);
            std::cout << ++count << ". Data passed succesfully\n" << std::flush;
        }
    }
    std::cout << "Original Data\n";
    std::cout << original_points << "\n\n";
    std::cout << "Processed Data\n";
    std::cout << processed_data << "\n\n";

    std::cout << "Comparison Original and Processed Data\n";
    if(original_points.size() == processed_data.size())
    {
        for(int i = 0; i < original_points.size(); ++i)
        {
            if(original_points[i] != processed_data[i])
            {
                std::cout << "Something's wrong\n";
                continue;
            }
        }
        return 1;
    }
    std::cout << "Something's wrong\n";
}