#include  "headers.h"

void fill_prime_vector(std::vector<int>& vector) // unrolling the loop to reduce from 98 loops to 49
{

    for(int i = 2; i <= 100; i++)
    {
        int counter = 0;
        
        for(int j = i - 1; j > 0; j--)
        {
            if(i % j == 0)
            {
                counter++;
            }
        }

        if(counter == 1)
        {
            vector.push_back(i);
        }
    }
}

int main()
{
    std::cout << "Exercise 12" << std::endl; 
    {   
        std::vector<int> primes;
        
        fill_prime_vector(primes);

        int index = 1;
        for(int i = 2; i <= 100; i++)
        {   
            bool is_prime = true;

            for(int prime: primes)
            {
                if(prime * prime > i)
                {
                    break;
                }

                if(i % prime == 0 && i != prime)
                {
                    is_prime = false;
                    break;
                }
            }

            if(is_prime)
            {
                std::cout << index << ". " << i << " is a prime number" << std::endl;
                index++;
            }
        }
    }

    std::cout << "\nExercise 13: Sieve of Eratosthenes" << std::endl;

    {   
        std::vector<int> sieve;

        for(int i = 2; i <= 96; i += 4)
        {
            sieve.push_back(i);
            sieve.push_back(i + 1);
            sieve.push_back(i + 2);
            sieve.push_back(i + 3);
        }

        sieve.push_back(98);
        sieve.push_back(99);
        sieve.push_back(100);

        for(int i = 0; i < sieve.size(); i++)
        {
            if(sieve[i] != 0)
            {
                for(int j = sieve[i] + i; j < sieve.size(); j += sieve[i])
                {
                    sieve[j] = 0;
                }
            }
        }

        int index_s = 1;

        for(int num: sieve)
        {
            if(num != 0)
            {
                std::cout << index_s << ". " << num << std::endl;
                index_s++;
            }
        }
    }

    std::cout << "\nExcercise 14" << std::endl;
    {
        std::cout << "Enter a number and find all the prime numbers until your inpuy:" << std::endl;
        int n;
        std::cin >> n;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::vector<bool> vec(n + 1, true);
        vec[0] = vec[1] = false;

        for(int i = 2; i * i <= n; i++)
        {
            if(vec[i])
            {
                for(int j = i * i; j <= n; j += i)
                {
                    vec[j] = false;
                }
            }
        }

        for(int i = 2;  i <= n; i++)
        {
            if(vec[i])
            {
                std::cout << i << std::endl;
            }
        }
    }

    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}