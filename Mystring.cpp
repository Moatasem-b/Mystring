#include "Mystring.h"
#include <iostream>
#include <cstring>
#include <cctype>

Mystring::Mystring()
:str(new char[1]) {
    *str = '\0';
}

Mystring::Mystring(const char *s)
:str(new char[std::strlen(s) + 1]) {
    std::strcpy(str, s);
}

Mystring::Mystring(const Mystring &source)
:str(new char[std::strlen(source.str) + 1]) {
    std::strcpy(str, source.str);
}

Mystring::Mystring(Mystring &&source)
:str(source.str) {
    source.str = nullptr;
}

Mystring::~Mystring() {
    delete[] str;
}

Mystring &Mystring::operator=(const Mystring &rhs) {
    if (this == &rhs) {
        return *this;
    }
    delete[] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

Mystring &Mystring::operator=(Mystring &&rhs) {
    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

bool Mystring::operator!=(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) != 0);
}

bool Mystring::operator>(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) > 0);
}

bool Mystring::operator<(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) < 0);
}

Mystring Mystring::operator-() const {
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (int i = 0; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp(buff);
    delete[] buff;
    return temp;
}

Mystring Mystring::operator+(const Mystring &rhs) const {
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp(buff);
    delete[] buff;
    return temp;
}

Mystring &Mystring::operator+=(const Mystring &rhs) {
    *this = (*this + rhs);
    return *this;
}

Mystring Mystring::operator*(int n) const {
    char *buff = new char[(std::strlen(str) * n) + 1];
    std::strcpy(buff, str);
    for (int i = 0; i < (n-1); i++) {
        std::strcat(buff, str);
    }
    Mystring temp(buff);
    delete[] buff;
    return temp;
}

Mystring &Mystring::operator*=(int n) {
    *this = (*this * n);
    return *this;
}

Mystring &Mystring::operator++() {
    for (int i = 0; i < std::strlen(str); i++) {
        str[i] = std::toupper(str[i]);
    }
    return *this;
}

Mystring Mystring::operator++(int) {
    Mystring temp(*this);
    operator++();
    return temp;
}

std::ostream &operator<<(std::ostream &output, const Mystring &rhs) {
    output << rhs.str;
    return output;
}

std::istream &operator>>(std::istream &input, Mystring &rhs) {
    char *buff = new char[500];
    input >> buff;
    rhs = buff;
    delete[] buff;
    return input;
}