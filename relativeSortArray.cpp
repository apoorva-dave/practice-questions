class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map <int, int> arr1map;
        unordered_map <int, int> arr2map;
        vector <int> result;
        vector <int> nonrepeating;
        for(int i=0; i<arr1.size(); i++) {
            arr1map[arr1[i]]++;
        }
        for(int i=0; i<arr2.size(); i++) {
             arr2map[arr2[i]]++;
        }

        
        for(int i=0; i<arr2.size(); i++) {
            int num = arr2[i]; //3
            int count1 = arr1map[num]; //2
            for (int j=0; j<count1; j++)
                result.push_back(num); // 2,2,2, 1, 4,3,3,9,6
        }

        for(int i=0; i<arr1.size(); i++) {
            int num = arr1[i]; //3
            int count1 = arr1map[num]; //2
            int count2 = arr2map[num]; //2
            if(count2 == 0) {
                nonrepeating.push_back(num);
            }
            // if(find(result.begin(), result.end(), arr1[i]) == result.end())
            //     result.push_back(arr1[i]);
        }
        sort(nonrepeating.begin(), nonrepeating.end());
        result.insert( result.end(), nonrepeating.begin(), nonrepeating.end() );

        return result;
    }
};
