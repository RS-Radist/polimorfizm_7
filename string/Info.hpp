#ifndef Info_hpp
#define Info_hpp
#include <iostream>
#include <stdio.h>
#include "String1.hpp"

using namespace std;
class Info:public String1
{
private:
    char* simferopol;
public:
    Info(); // Конструктор без параметоров
    Info(char* temp); // Конструктор с параметром
    Info (const Info& obj); // Конструктор копирования
    ~Info(); // Диструктор
    char * Get(); // Геттер
    void Set(char* temp);// Сеттер
    void Show();
    int Strlen(); // Число строк
    void ClearString(); // Очистка строк
    Info& operator=(const Info& obj);
    Info& operator+(const Info&obj);
    Info& operator+=(const Info&obj);
    bool operator==(const Info&obj);
    bool operator!=(const Info&obj);
};
#endif /* Info_hpp */
