#include "Info.hpp"
Info::Info(){simferopol=NULL;} // Конструктор без параметоров
Info::Info(char* temp) // Конструктор с параметром
{
    simferopol=new char [strlen(temp)+1];
    strcpy(simferopol, temp);
    cout<<"Создаю объекты"<<this<<endl;
}
Info::Info (const Info& obj) // Конструктор копирования
{
    this->simferopol=obj.simferopol;
    this->simferopol=new char[strlen(obj.simferopol)+1];
    strcpy(this->simferopol,obj.simferopol);
    cout<<"Вызывается конструктор копирования"<<this<<endl;
}
Info::~Info() // Диструктор
{
    cout<<"Вызвался диструктор"<<this<<endl;
    delete [] simferopol;
}
char * Info::Get() // Геттер
{
    return simferopol;
}
void Info::Set(char* temp)// Сеттер
{
    simferopol=new char [strlen(temp)+1];
    strcpy(simferopol, temp);
}
void Info::Show()
{
    return ;
}
int Info::Strlen() // Число строк
{
    int i=strlen(simferopol);
    return i;
}
void Info::ClearString() // Очистка строк
{
    for (int i=0;i<strlen(simferopol);++i)
    {
        if (simferopol[i]!='0')
        {
            simferopol[i]=' ';
        }
    }
}
Info& Info::operator=(const Info& obj)
{
    if(this->simferopol!=nullptr)
        delete [] this->simferopol;
    this->simferopol=new char[strlen(obj.simferopol)+1];
    strcpy(this->simferopol,obj.simferopol);
    cout<<"Оператор присваивания\n";
    return *this;
}
Info& Info:: operator+(const Info&obj)
{
    Info temp;
    temp.simferopol=new char [strlen(strcat(this->simferopol,obj.simferopol))];
    strcpy(temp.simferopol,this->simferopol);
    cout<<"Оператор +"<<endl;
    return *this;
}
Info& Info::operator+=(const Info&obj)
{
    if (this->simferopol==NULL)
    {
        this->simferopol=new char [strlen(obj.simferopol)];
        strcpy(this->simferopol,obj.simferopol);
        cout<<"Оператор +="<<endl;
        return *this;
    }
    else
    {
        Info temp;
        temp.simferopol=new char [strlen(strcat(this->simferopol,obj.simferopol))];
        strcat(this->simferopol,temp.simferopol);
        cout<<"Оператор +="<<endl;
        return *this;
    }
}
bool Info::operator==(const Info&obj)
{
    if (this->simferopol==obj.simferopol)
    {
        return true;
    }
    else
    {
        
        return false;
    }
}
bool Info::operator!=(const Info&obj)
{
    return !(this->simferopol==obj.simferopol);
}

