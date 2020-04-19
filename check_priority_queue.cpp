#include<bits/stdc++.h>
using namespace std;
struct st
{
    string name;
    int roll;
    st(string &name, int roll) : name(name), roll(roll) {}
    bool operator<(const st &s) const
    {
        return roll > s.roll;
    }
};
int main()
{
    priority_queue <struct st> pq;
    string x = "ABC";
    int y = 123;
    st s(x,y);
    pq.push(s);

    string a = "BC";
    int b = 3;
    st q(a,b);
    pq.push(q);
    
    while(!pq.empty())
    {
        cout<<pq.top().name<<" "<<pq.top().roll<<endl;
        pq.pop();
    }
    return 0;
}