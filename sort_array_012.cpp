#include<bits/stdc++.h>
using namespace std;
void swap(int &x, int&y)
{
    int temp = x;
    x = y;
    y = temp;
}
void sort_vec(vector <int> &A)
{
    //take 3 variables count 0, count 1 and count 2. then insert elements in array

    int low= 0;
    int mid = 0;
    int high = A.size()-1;
    while(mid<=high)
    {
        if(A[mid]==0)
        {
            swap(A[low],A[mid]);
            low++;
        }
        if(A[mid]==1)
        {
            mid++;
        }
        if(A[mid]==2)
        {
            swap(A[high],A[mid]);
            high--;
        }
    } 
}
int main()
{
    vector <int> a{1,2,0,0,2,1,2};
    sort_vec(a);
    for(int i=0; i<a.size(); i++)
        cout<<a[i]<<" ";
    return 0;
}