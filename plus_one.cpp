class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        for(int i = digits.size()-1; i>=0; i--)
        {
            if(digits[i] >=0 && digits[i] <=8 && !carry)
            {
                digits[i] += 1;
                break;
            }
            else if(digits[i] >=0 && digits[i] <=8 && carry)
            {
                digits[i] += carry;
                carry = 0;
                break;
            }
            else
            {
                digits[i] = 0;
                carry = 1;
            }
        }
        if(carry == 1)
            digits.insert(digits.begin(),1);
        return digits;
    }
};