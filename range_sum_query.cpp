class NumArray {
private:
    vector <int> data;
public:
    NumArray(vector<int>& nums) {
        data = nums;
        
        for(int i=1;i<data.size();i++)
        {
            data[i] = data[i-1] + data[i];
        }
        
    }
    
    int sumRange(int i, int j) {
      
        if(i>0)
            return (data[j]-data[i-1]);
        else
            return (data[j]);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */