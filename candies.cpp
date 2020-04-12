//https://www.hackerrank.com/challenges/candies/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
    long candies = 0;
    vector <int> c;
    c.push_back(1);
    for(int i=1; i<arr.size(); i++)
    {
        if(arr[i]>arr[i-1])
        {
            c.push_back(c[i-1]+1);
        }
        else
            c.push_back(1);
    }
    for(int i=arr.size()-1; i>=0; i--)
    {
        if(arr[i-1]>arr[i] && c[i-1] <= c[i])
        {
            c[i-1] = c[i]+1;
        }
    }
    for(int i=0;i<c.size(); i++)
        candies += c[i];
    return candies;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
