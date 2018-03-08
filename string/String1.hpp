
#ifndef String1_hpp
#define String1_hpp
#include <iostream>
#include <stdio.h>
using namespace std;
class String1
{
private:
    char* simf;
public:
    String1();
    String1 (char* temp);
    String1 (const String1& obj); // Конструктор копирования
    virtual~String1();
    String1& operator=(const String1& obj);
    String1& operator+(const String1&obj);
    String1& operator+=(const String1&obj);
    bool operator==(const String1&obj);
    bool operator!=(const String1&obj);
    virtual void ClearString()=0;
    virtual void Show()=0;
    virtual void Set(char * temp)=0;
    virtual char* Get()=0;
    virtual int Strlen()=0;
};


#endif /* String1_hpp */
