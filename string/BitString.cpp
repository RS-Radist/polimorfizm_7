#include <iostream>
#include "BitString.hpp"
using namespace std;
BitString::BitString()
{
    str=NULL;
}
BitString::BitString(char* temp,char _znak)
{
    str=new char [strlen(temp)+1];
    strcpy(str, temp);
    for (int i=0;i<strlen(str);++i)
    {
        if ((str[i]!='1')&&(str[i]!='0'))
        {
            str[i]=' ';
        }
    }
    cout<<"Создаю объекты"<<this<<endl;
}
BitString::BitString(const BitString& obj) // Конструктор копирования
{
    this->str=obj.str;
    this->str=new char[strlen(obj.str)+1];
    strcpy(this->str,obj.str);
    cout<<"Вызывается конструктор копирования"<<this<<endl;
}
BitString::~BitString()
{
    cout<<"Вызвался диструктор"<<this<<endl;
    delete [] str;
}
BitString& BitString::operator=(const BitString& obj)
{
    if(this->str!=nullptr)
        delete [] this->str;
    this->str=new char[strlen(obj.str)+1];
    strcpy(this->str,obj.str);
    cout<<"Оператор присваивания\n";
    return *this;
}
char *BitString:: Get()
{
    return str;
}

void BitString::Set(char* temp)
{
    str=new char [strlen(temp)+1];
    strcpy(str, temp);
    for (int i=0;i<strlen(str);++i)
    {
        if ((str[i]!='1')&&(str[i]!='0'))
        {
            str[i]=' ';
        }
    }
}
void BitString::Show()
{
    
}

//    char *  MagicSting (BitString& obj)
//    {
//
//        for (int i=0;strlen(obj.str);++i)
//        {
//
//        }
//    }
BitString& BitString::operator +(const BitString&obj)
{
    BitString temp;
    temp.str=new char [strlen(strcat(this->str,obj.str))];
    strcpy(temp.str,this->str);
    cout<<"Оператор +"<<endl;
    return *this;
}
BitString& BitString::operator+=(const BitString&obj)
{
    if (this->str==NULL)
    {
        this->str=new char [strlen(obj.str)];
        strcpy(this->str,obj.str);
        cout<<"Оператор +="<<endl;
        return *this;
    }
    else
    {
        BitString temp;
        temp.str=new char [strlen(strcat(this->str,obj.str))];
        strcat(this->str,temp.str);
        cout<<"Оператор +="<<endl;
        return *this;
    }
}
bool BitString::operator==(const BitString&obj)
{
    if (this->str==obj.str)
    {
        return true;
    }
    else
    {
        
        return false;
    }
}
bool BitString::operator!=(const BitString&obj)
{
    return !(this->str==obj.str);
}
