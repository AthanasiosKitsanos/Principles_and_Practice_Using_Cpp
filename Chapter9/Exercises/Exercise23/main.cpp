#include <fstream>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const char* file_name = "input1.txt";

    //Create an file_name file stream instance
    std::ifstream ifs{file_name};
    if(!ifs)
    {
        std::cout << "Failed to open " << file_name << '\n';
        return 1;
    }
    // Get the size of the file
    ifs.seekg(0, std::ios::end);
    std::streamsize length = ifs.tellg();
    ifs.seekg(0, std::ios::beg);

    // allocate memory in the heap, to reuse the pointer for the second input
    char* buffer = static_cast<char*>(::operator new(length + 1));
    std::streambuf* sb = ifs.rdbuf();
    sb->sgetn(buffer, length); // Copy the bytes from the stream buffer to our buffer
    buffer[length] = '\0'; // set a termination character
    ifs.close(); // sb is deallocated on close

    //Create an output file stream instance
    std::ofstream ofs{"output.txt"};
    ofs << buffer << "\n\n"; //output the bytes to the new file
    ofs.close();

    //release buffer memory
    ::operator delete(buffer);
    buffer = nullptr;
    
    file_name = "input2.txt";

    //open the file input2.txt
    ifs.open(file_name);
    if(!ifs)
    {
        std::cout << "Failed to open " << file_name << '\n';
        return 1;
    }
    //get the lenght of input2.txt
    ifs.seekg(0, std::ios::end);
    length = ifs.tellg();
    ifs.seekg(0, std::ios::beg);

    //allocate memory of length size
    buffer = static_cast<char*>(::operator new(length + 1));
    sb = ifs.rdbuf(); // point to the new stream buffer
    sb->sgetn(buffer, length); // copy the bytes directly for the stream buffer
    buffer[length] = '\0'; // set a termination character
    ifs.close(); // sb is deallocated on close

    //open the output file again with the flag that we want to add new text
    ofs.open("output.txt", std::ios::app);
    ofs << buffer;
    ofs.close();
}