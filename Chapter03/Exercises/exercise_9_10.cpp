#include "headers.h"

//No need to do this exercise that way, I was just curious how to add more performance and keep some readability. using urolled loops and AVX
// void addThread(int* total_grains, int* previous_grains, int* current_square, int start, int end)
// {
//     for(int i = start; i < end; i += 16)
//     {
//         __m256i generate_previous = _mm256_set_epi32(1 << (i + 7), 1 << (i + 6), 1 << (i + 5), 1 << (i + 4), 1 << (i + 3), 1 << (i + 2), 1 << (i + 1), 1 << i);
//         __m256i generate_total = _mm256_set_epi32(1 << (i + 8), 1 << (i + 7), 1 << (i + 6), 1 << (i + 5), 1 << (i + 4), 1 << (i + 3), 1 << (i + 2), 1 << (i + 1));
//         __m256i generate_current_square = _mm256_set_epi32(i + 8, i + 7, i + 6, i + 5, i + 4, i + 3, i + 2, i + 1);

//         _mm256_storeu_si256((__m256i*)(previous_grains + i), generate_previous);
//         _mm256_storeu_si256((__m256i*)(total_grains + i), generate_total);        
//         _mm256_storeu_si256((__m256i*)(current_square + i), generate_current_square );
        
//         generate_previous = _mm256_set_epi32(1 << (i + 7 + 8), 1 << (i + 6 + 8), 1 << (i + 5 + 8), 1 << (i + 4 + 8), 1 << (i + 3 + 8), 1 << (i + 2 + 8), 1 << (i + 1 + 8), 1 << (i + 8));
//         generate_total = _mm256_set_epi32(1 << (i + 8 + 8), 1 << (i + 7 + 8), 1 << (i + 6 + 8), 1 << (i + 5 + 8), 1 << (i + 4 + 8), 1 << (i + 3 + 8), 1 << (i + 2 + 8), 1 << (i + 1 + 8));
//         generate_current_square = _mm256_set_epi32(i + 8 + 8, i + 7 + 8, i + 6 + 8, i + 5 + 8, i + 4 + 8, i + 3 + 8, i + 2 + 8, i + 1 + 8);

//         _mm256_storeu_si256((__m256i*)(previous_grains + i + 8), generate_previous);
//         _mm256_storeu_si256((__m256i*)(total_grains + i + 8), generate_total);
//         _mm256_storeu_si256((__m256i*)(current_square + i + 8), generate_current_square);
//     }
// }

// int main()
// {
//     const int total_squares = 64;
//     const int total_threads = 4;

//     int* current_square = static_cast<int*>(_aligned_malloc(sizeof(int) * total_squares, alignof(int)));;
//     int* total_grains = static_cast<int*>(_aligned_malloc(sizeof(int) * total_squares, alignof(int)));
//     int* previous_grains = static_cast<int*>(_aligned_malloc(sizeof(int) * total_squares, alignof(int)));
    
//     std::vector<std::thread> threads;
//     int chunck = total_squares / total_threads;

//     std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

//     for(int t = 0; t < 4; t++)
//     {  
//         int start_index = t * chunck;
//         int end_index = t == total_threads - 1 ? total_squares : start_index + chunck;
//         threads.emplace_back(addThread, total_grains, previous_grains, current_square, start_index, end_index);
//     }

//     for(std::thread& t: threads)
//     {  
//         t.join();
//     }

//     for(int i = 0; i < 64; i += 8)
//     {
//         std::cout << "Current Square: " << *(current_square + i) << " Previous Grains: " << *(previous_grains + i) << " Total Grains: " << *(total_grains + i) << std::endl;
//         std::cout << "Current Square: " << *(current_square + i + 1) << " Previous Grains: " << *(previous_grains + i + 1) << " Total Grains: " << *(total_grains + i + 1) << std::endl;
//         std::cout << "Current Square: " << *(current_square + i + 2) << " Previous Grains: " << *(previous_grains + i + 2) << " Total Grains: " << *(total_grains + i + 2) << std::endl;
//         std::cout << "Current Square: " << *(current_square + i + 3) << " Previous Grains: " << *(previous_grains + i + 3) << " Total Grains: " << *(total_grains + i + 3) << std::endl;
//         std::cout << "Current Square: " << *(current_square + i + 4) << " Previous Grains: " << *(previous_grains + i + 4) << " Total Grains: " << *(total_grains + i + 4) << std::endl;
//         std::cout << "Current Square: " << *(current_square + i + 5) << " Previous Grains: " << *(previous_grains + i + 5) << " Total Grains: " << *(total_grains + i + 5) << std::endl;
//         std::cout << "Current Square: " << *(current_square + i + 6) << " Previous Grains: " << *(previous_grains + i + 6) << " Total Grains: " << *(total_grains + i + 6) << std::endl;
//         std::cout << "Current Square: " << *(current_square + i + 7) << " Previous Grains: " << *(previous_grains + i + 7) << " Total Grains: " << *(total_grains + i + 7) << std::endl;
//     }

//     std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

//     long int duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

//     std::cout << "Duration: " << std::endl;
//     std::cout << "Minutes: " << duration / 60000 << " Seconds: " << (duration % 60) / 1000 << " Milliseconds: " << duration % 1000 << std::endl;

//     _aligned_free(total_grains);
//     _aligned_free(previous_grains);
//     _aligned_free(current_square);

//     total_grains = nullptr;
//     previous_grains = nullptr;
//     current_square = nullptr;

//     std::cin.clear();
//     std::cout << "Press any key to exit...";
//     std::cin.get();

//     return 0;
// }

int main()
{
    int total_grains = 0;
    int previous_grains = 0;
    int current_square = 0;

    for(int i = 0; i < 64; i++)
    {
        total_grains = i == 0 ? 1 : total_grains * 2;
        previous_grains = i == 0 ? 0 : total_grains / 2;
        current_square = i + 1;

        std::cout << "Current Square: " << current_square << std::endl;
        std::cout << "Previues Grains: " << previous_grains << std::endl;
        std::cout << "Total Grains: " << total_grains << std::endl;
    }

    std::cout << "Press any key to exit...";
    std::cin.get();

    return 0;
}


//The result is that after the 31st square, the values are going back to zero