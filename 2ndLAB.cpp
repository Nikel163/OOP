#include <bits/stdc++.h>

using namespace std;

class Money
{
public:
    int val;
    string lav;
    Money(int x = 0, string a = "DA"): val(x), lav(a){}

    friend std::ostream& operator<<(std::ostream& out, Money& temp)
    {
        out<<"El="<<temp.val<<temp.lav;
        return out;
    }
    bool operator< (const Money& first)const
    {
        return val<first.val;
    }
    bool operator== (const Money& first)const
    {
        return  val==first.val;
    }
};

struct Hash
{
    size_t operator()(const Money& m)const { return hash<int>()(m.val); }
};

void task1()
{
    cout<<"First task....\n";
    int sizeList = 10, x;
    list<Money> spisok;

    for(int i = 0; i < sizeList; i++)
    {
        x = rand()%100;
        Money buf(x," a");
        spisok.push_back(buf);
    }

    cout<<"List: ";
    for(auto x : spisok)
        cout<<x<<" ";

    cout<<"\nEnter key: "; int key; cin>>key;

    auto result = find(spisok.begin(), spisok.end(), key);
    Money current = *result;

    if(current.val == key)
    {
        cout<<"Key is found! Enter new position: "; int x; cin>>x;
        if(x <= spisok.size())
        {
            auto it = spisok.begin();
            for(int i = 0; i < x; i++)it++;
                spisok.insert(it,key);

                cout<<"New list: ";
            for (auto x : spisok)
                cout<<x<<" ";

        } else cout<<"Incorrect position!\n";

    } else cout<<"Key not found!";
}

void task2()
{
    cout<<"\n\nSecond task....";
    unordered_set<Money, Hash> plural;

    for(int i = 0; i < 10; i++)
    {
        int x = rand()%100;
        Money buf(x);
        plural.insert(buf);
    }

    cout<<"\nUnsort set: ";
    for(auto x : plural)
        cout<<x<<" ";

    cout<<"\nEnter key: "; int key; cin>>key;
    auto result = eq(plural.begin(), plural.end(), key);
    if( *result == key )plural.erase(result);
    else cout<<"Key not found!";

    cout<<"Unsort set: ";
    for(auto x : plural)
        cout<<x<<" ";
}

void task3()
{
    cout<<"\n\nThird task....\n";
    multimap<char, Money> many;

    for(char c = 'a'; c <= 'j'; c++)
    {
        int x = rand()%100;
        Money buf(x);
        many.emplace(c, buf);
    }

    cout<<"Multimap: ";
    for(auto &n : many)
        cout<<n.first<<"("<<n.second.val<<") ";

    int max = many.begin()->second.val;
    int min = many.begin()->second.val;
    for(auto &n : many)
       n.second.val > max ? max = n.second.val : min = n.second.val;

    int dif = max - min;
    for(auto &n : many)
        n.second.val -= dif;

    cout<<"\nmax = "<<max<<" min = "<<min<<" dif = "<<dif<<endl;
    cout<<"Multimap: ";
    for(auto &n : many)
        cout<<n.first<<"("<<n.second.val<<") ";

}

int main()
{
    srand(time(0));
    task1();
    task2();
    task3();
}