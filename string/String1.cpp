//
//  String1.cpp
//  Polemorfizm_zadanie_7
//
//  Created by iMac on 08.03.18.
//  Copyright © 2018 Polemorfizm_zadanie_7. All rights reserved.
//

#include "String1.hpp"
String1::String1(){simf=NULL;};

String1::String1 (char* temp)
{
    simf=new char [strlen(temp)+1];
    strcpy(simf, temp);
    cout<<"Создаю объекты"<<this<<endl;
}
String1::~String1()
{
    cout<<"Вызвался диструктор"<<this<<endl;
    delete [] simf;};