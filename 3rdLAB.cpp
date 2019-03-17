#include <bits/stdc++.h>

using namespace std;

void degreeC()
{
    cout<<"\nВыбран перевод в градусы Фаренгейта.\n"
        <<"Введите температуру в градусах Цельсия: "; double t; cin>>t;

    cout.width(13);
    cout.fill('/');
    cout.precision(4);
    cout<<fixed<<t<<"°C = ";

    cout.width(13);
    cout.fill('/');
    cout.precision(4);
    cout<<fixed<<32+1.8*t<<"°F\n";

}

void degreeF()
{
    cout<<"\nВыбран перевод в градусы Цельсия.\n"
        <<"Введите температуру в градусах Фаренгейта: "; double f; cin>>f;

    cout.width(13);
    cout.fill('/');
    cout.precision(4);
    cout<<fixed<<f<<"°F = ";

    cout.width(13);
    cout.fill('/');
    cout.precision(4);
    cout<<fixed<<(f-32)/1.8<<"°C\n";
}

void menu()
{
    cout<<"Перевод градусов:\n"
        <<"1) градусы Цельсия -> градусы Фаренгейта\n"
        <<"2) градусы Фаренгейта -> градусы Цельсия\n"
        <<"Выберите свой вариант: "; int x; cin>>x;

    while(x != 1 && x != 2)
    {
        cout<<"Недопустимое значение. Введите заного: "; cin>>x;
    }

    switch (x)
    {
        case 1: degreeC(); break;
        case 2: degreeF(); break;
    }

}

int main()
{
    menu();
}