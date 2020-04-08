class Solution {
public:
    int countElements(vector<int>& arr) {
        // 1 1 2 2
        int count = 0;
        map <int, int> mp; // 1 2
        for(int i=0; i<arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        for(int i=0; i<arr.size(); i++)
        {
            int x = arr[i];
            if(mp.find(x+1)!=mp.end())
            {
                // cout<<"hello";
                count++;
                // cout<<mp[x]<<" "<<mp[x+1]<<endl;
                mp[x]--;
                mp[x+1]--;
                // cout<<mp[x]<<" "<<mp[x+1]<<endl; // 1-> 2 , 2-> 2
            }
        }
        return count;
    }
};