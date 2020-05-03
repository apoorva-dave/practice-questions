class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length() == 0)
            return true;
        int k = 0;
        // use hashmap for each char to sort string in O(n)
        sort(magazine.begin(), magazine.end());
        sort(ransomNote.begin(), ransomNote.end());
        for(int i=0; i<magazine.length(); i++)
        {
            if(ransomNote[k] == magazine[i])
            {
                k++;
                if(k == ransomNote.length())
                    return true;
            }
        }
        return false;
    }
};