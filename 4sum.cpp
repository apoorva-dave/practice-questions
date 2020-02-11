class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        map <int, vector <pair<int,int>>> mp;
        vector<vector<int>> result;
        if(nums.size()<1)
            return result;
        for(int i=0; i<nums.size()-1;i++)
        {
            for(int j=i+1; j<nums.size();j++)
            {
                pair <int,int> p = make_pair(i,j);
                mp[nums[i] + nums[j]].push_back(p);
            }
        }

        
        for(int i=0; i<nums.size()-1;i++)
        {
            for(int j=i+1; j<nums.size();j++)
            {
                
                int sum = nums[i] + nums[j]; 
                if (mp.find(target - sum) != mp.end()) 
                { 
                    auto num = mp.find(target - sum); 
                    vector<pair<int, int> > v = num->second; 
                    for (int k = 0; k < num->second.size(); k++) 
                    { 
                        vector <int> curr;
                        pair<int, int> it = v[k];
                        if (it.first != i && it.first != j &&  
                            it.second != i && it.second != j) 
                        {
                            curr.push_back(nums[i]);
                            curr.push_back(nums[j]);
                            curr.push_back(nums[it.first]);
                            curr.push_back(nums[it.second]);
                            sort(curr.begin(),curr.end());
                        }
                        if(curr.size()>0)
                            result.push_back(curr);
                    } 
                    
                }
                
            }
        }
        sort( result.begin(), result.end() );
        result.erase( unique( result.begin(), result.end() ), result.end() );
        return result;
    }
};