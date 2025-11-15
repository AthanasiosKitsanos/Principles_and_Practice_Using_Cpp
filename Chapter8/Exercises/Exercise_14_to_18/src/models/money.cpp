#include "models/money.h"

money::money(): currency(""), total_amount(0) {}
money::money(const std::string& cur, const int& amount): currency(cur), total_amount(amount) {}
money::money(const money& other): currency(other.currency), total_amount(other.total_amount) {}
money::money(money&& other) noexcept: currency(std::move(other.currency)), total_amount(other.total_amount)
{
    other.total_amount = 0;
}
money::~money() {}

const std::string& money::get_currency_type() const { return currency; }
const long int& money::get_amount() const { return total_amount; }
void money::convert_to(const std::string& type)
{
    if(currency == type)
    {
        std::cout << "Currency and type given are equal\n" << std::flush;
        return;
    }
    currency = type;
    if(type == "DKK")
    {
        total_amount *= 643;
    }
    else if(type == "USD")
    {
        total_amount /= 643;
    }
}

money& money::operator=(const money& other)
{
    if(this != &other)
    {
        currency = other.currency;
        total_amount = other.total_amount;
    }
    return *this;
}

money& money::operator=(money&& other) noexcept
{
    if(this != &other)
    {
        currency = std::move(other.currency);
        total_amount = other.total_amount;
        other.total_amount = 0;
    }
    return *this;
}

bool money::operator==(const money& other) const { return currency == other.currency && total_amount == other.total_amount; }
bool money::operator!=(const money& other) const { return currency != other.currency || total_amount != other.total_amount; }

money money::operator+(const money& other) const
{
    if(currency != other.currency) return money{"", -1};
    return money{currency, total_amount + other.total_amount};
}

money& money::operator+=(const money& other)
{
    if(this != &other)
    {
        if(currency == other.currency) total_amount += other.total_amount;
        else
        {
            currency = "";
            total_amount = -1;
        }
    }
    return *this;
}

money money::operator-(const money& other) const
{
    if(currency != other.currency) return money{"", -1};
    return money{currency, total_amount - other.total_amount};
}

money& money::operator-=(const money& other)
{
    if(this != &other)
    {
        if(currency == other.currency) total_amount -= other.total_amount;
        else
        {
            currency = "";
            total_amount = -1;
        }
    }
    return *this;
}

money money::operator*(const int& times) const
{
    return money{currency, total_amount * times};
}

money& money::operator*=(const int& times)
{
    total_amount *= times;
    return *this;
}

money money::operator/(const int& times) const
{
    return money{currency, total_amount / times};
}

money& money::operator/=(const int& times)
{
    total_amount /= times;
    return *this;
}

// the >> operates at maximum of 3 digits after the '.', but it will always display the first 2 digits
// e.g usd 12.456, will be displayed 12.46(roundup)
// if we do again usd 12.45678, the output will still be 12.46
// and the rest of the input will be consumed
std::istream& operator>>(std::istream& is, money& obj)
{
    char c{'\0'};
    obj.currency = "";
    obj.total_amount = 0;
    while(is.get(c) && isalpha(c))
    {
        c = std::toupper(c);
        obj.currency += c;
    }
    if(obj.currency != "USD" && obj.currency != "DKK")
    {
        is.setstate(std::ios::failbit);
        return is;
    }
    while(c == ' ') is.get(c);
    if(isdigit(c))
    {
        obj.total_amount += c - '0';
        while(is.get(c) && isdigit(c))
        {
            obj.total_amount = obj.total_amount*10 + (c -'0');
        }
        if(c == '.')
        {
            int counter{0};
            while(is.get(c) && isdigit(c))
            {
                ++counter;
                if(counter == 1) obj.total_amount = obj.total_amount*100 +((c - '0')*10);
                else if(counter == 2) obj.total_amount += (c - '0');
                else
                {
                    if(c > '4') obj.total_amount++;
                    while(c != '\n') is.get(c);
                    return is;
                }
            }
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const money& obj)
{
    return os << obj.get_currency_type() << ' '
    << obj.get_amount() / 100 << '.'
    << obj.get_amount() % 100; 
}