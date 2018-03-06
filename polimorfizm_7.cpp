/*Срок сдачи: 1 мар.
Полиморфизм 7
В заданиии требуется создать базовый класс (как вариант, абстрактный базовый класс) и определить общие методы show ( ), get ( ), set ( ) и другие, специфические для данного класса. Создать производные классы, в которых добавить специфические свойства и методы.

Часть методов переопределить. Создать массив объектов (указателей на объекты) базового класса и заполнить объектами (указателями на объекты) производных классов. Объекты производных классов идентифицировать конструктором по имени или идентификационному номеру.

Вызвать метод show ( ) базового класса и просмотреть массив объектов.

Использовать объекты производных классов для моделирования реальных ситуаций и объектов.

Задание.
Описать базовый класс «Строка».
Методы:
1) конструктор без параметров;+
2) конструктор, принимающий в качестве параметра C-строку (заканчивается нулевым байтом);+
3) конструктор копирования;+
4) оператор присваивания;+
5) получение длины строки;+
6) очистка строки (сделать строку пустой);+
7) деструктор;+
8) конкатенация строк (перегрузить операторы + и +=);+
9) проверка на равенство (= =) и на неравенство (!=).+
*/


#include <iostream>
using namespace std;
class String1
{
protected:
    char* simferopol;
public:
    virtual void Show()=0;
    virtual void Set(char * temp)=0;
    virtual char* Get()=0;
    virtual int Strlen()=0;
    virtual void ClearString()=0;
};

class Info:public String1
{
private:
    char* simf;
public:
    Info()
    {
        simf=NULL;
    }
    Info (char* temp)
    {
        simf=new char [strlen(temp)+1];
        strcpy(simf, temp);
        cout<<"Создаю объекты"<<this<<endl;
    }
    Info (const Info& obj) // Конструктор копирования
    {
        this->simf=obj.simf;
        this->simf=new char[strlen(obj.simf)+1];
        strcpy(this->simf,obj.simf);
        cout<<"Вызывается конструктор копирования"<<this<<endl;
    }
    ~Info()
    {
        cout<<"Вызвался диструктор"<<this<<endl;
        delete [] simf;
    }
    Info& operator=(const Info& obj)
    {
        if(this->simf!=nullptr)
        delete [] this->simf;
        this->simf=new char[strlen(obj.simf)+1];
        strcpy(this->simf,obj.simf);
        cout<<"Оператор присваивания\n";
        return *this;
    }
    int Strlen()
    {
        int i=strlen(simf);
        return i;
    }
    void ClearString()
    {
        for (int i=0;i<strlen(simf);++i)
        {
            if (simf[i]!='0')
            {
            simf[i]=' ';
            }
        }
    }
    char * Get()
    {
        return simf;
    }
    void Set(char* temp)
    {
        simf=new char [strlen(temp)+1];
        strcpy(simf, temp);
    }
    void Show()
    {
        
    }
    
    Info& operator +(const Info&obj)
    {
        Info temp;
        temp.simf=new char [strlen(strcat(this->simf,obj.simf))];
        strcpy(temp.simf,this->simf);
        cout<<"Оператор +"<<endl;
        return *this;
    }
    Info& operator+=(const Info&obj)
    {
        if (this->simf==NULL)
        {
            this->simf=new char [strlen(obj.simf)];
            strcpy(this->simf,obj.simf);
            cout<<"Оператор +="<<endl;
            return *this;
        }
        else
        {
            Info temp;
            temp.simf=new char [strlen(strcat(this->simf,obj.simf))];
            strcat(this->simf,temp.simf);
            cout<<"Оператор +="<<endl;
            return *this;
        }
    }
    bool operator==(const Info&obj)
    {
        if (this->simf==obj.simf)
        {
            return true;
        }
        else
        {
        
            return false;
        }
    }
    bool operator!=(const Info&obj)
    {
        return !(this->simf==obj.simf);
    }
};
int main()
{
    
    String1* str;
    Info info;
    
    str=&info;
    str->Set("hello");
    cout<<str->Get();
    cout<<endl;
    cout<<str->Strlen()<<endl;
    str->ClearString();
    cout<<str->Get();
    

    /*
    Info info("ttt");
    Info info1("aaa");
    Info yah(info1);
    cout<<yah.Get()<<endl;
    cout<<info.Get()<<endl;
    yah=info;
    cout<<yah.Get()<<endl;
    cout<<info.Strlen()<<endl;
    info.ClearString();
    cout<<info.Get()<<endl;
    Info test=info+info1;
    cout<<test.Get()<<endl;
    Info test;
    test+=info1;
    test+=yah;
    test+=yah;
    cout<<test.Get()<<endl;
     */// TEST

    
    

    
}
