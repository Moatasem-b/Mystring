#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <iostream>

class Mystring
{
private:
    char *str;
public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    ~Mystring();

    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);

    bool operator==(const Mystring &rhs) const;
    bool operator!=(const Mystring &rhs) const;
    bool operator>(const Mystring &rhs) const;
    bool operator<(const Mystring &rhs) const;

    Mystring operator-() const;

    Mystring operator+(const Mystring &rhs) const;
    Mystring &operator+=(const Mystring &rhs);

    Mystring operator*(int n) const;
    Mystring &operator*=(int n);

    Mystring &operator++();
    Mystring operator++(int);

    friend std::ostream &operator<<(std::ostream &output, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &input, Mystring &rhs);
};

#endif