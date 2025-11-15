#pragma once

#include "pch/pch.h"

class money
{
    std::string currency;
    long int total_amount;

    public:
        money();
        money(const std::string& cur, const int& amount);
        money(const money& other);
        money(money&& other) noexcept;
        ~money();

        const std::string& get_currency_type() const;
        const long int& get_amount() const;
        void convert_to(const std::string& type);

        money& operator=(const money& other);
        money& operator=(money&& other) noexcept;
        
        bool operator==(const money& other) const;
        bool operator!=(const money& other) const;

        money operator+(const money& other) const;
        money& operator+=(const money& other);
        money operator-(const money& other) const;
        money& operator-=(const money& other);
        money operator*(const int& times) const;
        money& operator*=(const int& times);
        money operator/(const int& times) const;
        money& operator/=(const int& times);

        friend std::istream& operator>>(std::istream& is, money& obj);
};

std::ostream& operator<<(std::ostream& os, const money& obj);