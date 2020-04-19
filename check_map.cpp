#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> v{2,3,4,2,5,3,6};
    map <int, vector <int>> mp;
    for(int i=0; i<v.size(); i++)
    {
            mp[v[i]].push_back(i); 
    }
    for(auto it=mp.begin(); it!= mp.end(); it++)
    {
        int y = it->first;
        cout<<y<<"\t";
        for(auto x: mp[y])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}