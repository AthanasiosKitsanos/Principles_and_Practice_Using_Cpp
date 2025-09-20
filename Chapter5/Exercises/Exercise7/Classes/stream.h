#pragma once

class Stream
{
    private:
        int number;
        int count;
        char c_number;

    public:
        Stream();
        ~Stream();

        void get();
        int digits();

        void print();
        void reset_stream();
};