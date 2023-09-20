#include "mystring2.h"
#include <iostream>
#include <cassert> // 使用正确的头文件名称

mystring::mystring()
{
    buflen = 0;
    buffer = new char[1]; // 为了表示空字符串，分配一个字节的空间并设置为'\0'
    buffer[0] = '\0';
}

mystring::mystring(unsigned size)
{
    buflen = size;
    buffer = new char[size + 1]; // 加1以包含结尾的'\0'
    for (unsigned i = 0; i < buflen; i++)
        buffer[i] = '\0';
}

mystring::mystring(char c)
{
    buflen = 1;
    buffer = new char[2]; // 一个字符+结尾的'\0'
    buffer[0] = c;
    buffer[1] = '\0';
}

mystring::mystring(const char *initstr)
{
    buflen = cstrLen(initstr);
    buffer = new char[buflen + 1]; // 加1以包含结尾的'\0'
    for (unsigned i = 0; i < buflen; i++)
        buffer[i] = initstr[i];
    buffer[buflen] = '\0'; // 添加结尾的'\0'
}

mystring::mystring(const mystring &initstr)
{
    buflen = initstr.buflen;
    buffer = new char[buflen + 1]; // 加1以包含结尾的'\0'
    for (unsigned i = 0; i < buflen; i++)
        buffer[i] = initstr.buffer[i];
    buffer[buflen] = '\0'; // 添加结尾的'\0'
}

mystring::~mystring()
{
    delete[] buffer; // 释放内存
}

void mystring::operator=(const mystring &right)
{
    if (this != &right)
    {
        delete[] buffer; // 释放原有内存
        buflen = right.buflen;
        buffer = new char[buflen + 1]; // 加1以包含结尾的'\0'
        for (unsigned i = 0; i < buflen; i++)
            buffer[i] = right.buffer[i];
        buffer[buflen] = '\0'; // 添加结尾的'\0'
    }
}

int mystring::compare(const mystring &right) const
{
    char *p = buffer;
    char *q = right.buffer;

    for (; (*p != '\0') && (*p == *q); p++, q++)
        ;

    return *p - *q;
}

char nothing;
char &mystring::operator[](unsigned index) const
{
    if (index >= buflen)
    {
        nothing = '\0';
        return nothing;
    }
    return buffer[index];
}

unsigned mystring::length() const
{
    return buflen;
}

istream &mystring::Getline(istream &in)
{
    in.getline(buffer, buflen, '\n');
    return in;
}

mystring::operator const char *() const
{
    return buffer;
}

unsigned cstrLen(const char *s)
{
    unsigned len = 0;
    for (; s[len] != '\0'; len++)
        ;
    return len;
}

istream &operator>>(istream &in, mystring &str)
{
    char inbuffer[1000];
    if (in >> inbuffer)
        str = inbuffer;
    else
        str = " ";
    return in;
}

ostream &operator<<(ostream &out, const mystring &str)
{
    out << str.buffer << endl;
    return out;
}

int operator<=(const mystring &left, const mystring &right)
{
    return left.compare(right) <= 0;
}

int operator<(const mystring &left, const mystring &right)
{
    return left.compare(right) < 0;
}

int operator>(const mystring &left, const mystring &right)
{
    return left.compare(right) > 0;
}

int operator>=(const mystring &left, const mystring &right)
{
    return left.compare(right) >= 0;
}

int operator==(const mystring &left, const mystring &right)
{
    return left.compare(right) == 0;
}

int operator!=(const mystring &left, const mystring &right)
{
    return left.compare(right) != 0;
}
