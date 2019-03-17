#include <bits/stdc++.h>

using namespace std;

enum words {one, two, more};

struct sentences
{
    string predl;
    words type;
}; vector <sentences> vec;

void check (string &word)
{
    int space=0;
    for(auto n : word)
        if(n == ' ')space++;

    if(space > 1)space=2;

    sentences buf; buf.predl = word;
    switch(space)
    {
        case 0: buf.type = one; break;
        case 1: buf.type = two; break;
        case 2: buf.type = more; break;
    }
    word = "";
    vec.push_back(buf);
}

int main()
{
    cout<<"1) Полный путь до файла\n"
        <<"2) Название файла\n"
        <<"Выберите вариант: "; int x; cin>>x;

    while(x != 1 && x != 2)
    {
        cout<<"Неправильный вариант. Введите заного: "; cin>>x;
    }

    string path;

    switch (x)
    {
        case 1: cout<<"Введите полный путь: "; getline(cin>>ws, path); break;
        case 2: cout<<"Введите название файла: "; string buf; getline(cin>>ws, buf); path = "/home/w3/Рабочий стол/OOP/lab3.2/"+buf; break;
    }

    ifstream in(path); ofstream out("/home/w3/Рабочий стол/OOP/lab3.2/out.txt", ios_base::ate);

    if(!in)cout<<"ERROR";

    string word;
    char c;
    while((c=in.get()) != EOF)
    {
        switch (c)
        {
            case 'A'...'Z': case 'a'...'z': case '0'...'9': case '_': case '-': case ' ': word += c; break;
            case '.': case '!': case '?':
                word += c; check(word); c=in.get();
                if((c!=' ') && (c!='\n'))word += c; break;
        }
    }

    for(auto n : vec)
        if(n.type == one)
            out<<n.predl<<endl;

    for(auto n : vec)
        if(n.type == two)
            out<<n.predl<<endl;

    for(auto n : vec)
        if(n.type == more)
            out<<n.predl<<endl;

    cout<<"Работяга выполнил задачу!";


}