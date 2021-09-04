// https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string S) {
         int arr[256];
        for(int i = 0; i<256; i++)
            arr[i] = -1;
        int firstNonRep;
        for(int i=0; i<S.length(); i++) {
            if(arr[S[i]-'0'] == -1) {
                arr[S[i]-'0'] = i;
            } else {
                arr[S[i]-'0'] = -2;
            }
        }
        int min_index = INT_MAX;
        bool found = false;
        for(int i=0; i<256; i++) {
            if(arr[i] >= 0) {
                min_index = min(min_index, arr[i]);
                found = true;
            }
        }
        if(found)
            return min_index;
        else 
            return -1;
    }
};