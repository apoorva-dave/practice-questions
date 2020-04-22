/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
        int rows = binaryMatrix.dimensions()[0];
        int col = binaryMatrix.dimensions()[1];
        int x = 0;
        int y = col-1;
        int ans = -1;
        while(x < rows && y>=0)
        {
            if(binaryMatrix.get(x,y)==1)
            {
                ans = y;
                y--;
            }
            else
            {
                x++;
            }    
        }
        return ans;
    }
};