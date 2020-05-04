class Solution {
public:
    int findBinary(int num)
    {
        // 6 -> 110 ->
        // 0 -> 1 -> 1
        int x = 0, k=0;
        while(num != 0)
        {
            int rem = num % 2;
            rem = rem == 1 ? 0 : 1;
            x += (rem * pow(2, k)); //
            k++;
            num /= 2;
        }
        return x;
    }
    int findComplement(int num) {
        if(num == 0)
            return 1;
        return findBinary(num);
    }
};