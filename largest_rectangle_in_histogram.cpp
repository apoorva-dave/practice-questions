int Solution::largestRectangleArea(vector<int> &A) {
    int H, L, R, max_rect = 0,i;
    //largest rectangle's height will be equal to heights of one of the histogram = H
    //move left and right to H and find first value less than H
    //max rect = (R-L-1)*H
    if(A.size()<1)
        return -1;
    if(A.size()==1)
        return A[0];
    
    stack <int> st; //stack store indices of histograms
    // st.push(0);
    for(i=0;i<A.size();i++)
    {
        if(st.empty() || A[i] >= A[st.top()])
            st.push(i);
        if(A[i]<A[st.top()])
        {
            while(!st.empty() && A[i]<A[st.top()])
            {
                R = i;
                L = st.top();
                st.pop();
                if(!st.empty())
                {
                    max_rect = std::max(max_rect, (R-st.top()-1)*A[L]);
                }
                else
                {
                    max_rect = std::max(max_rect, R*A[L]);
                }
                // st.pop();
            }
            st.push(i);
        }
        

        // H = A[i];
        // L = i, R = i;
        // while(L >=0 && A[L] >= H)
        //     L = L-1;
        // while(R < A.size() && A[R] >= H)
        //     R = R+1;
        // max_rect = std::max(max_rect, (R-L-1)*H);
        // cout<<max_rect<<endl;
    }
    while(!st.empty())
    {
        R = i;
        L = st.top();
        st.pop();
        if(!st.empty())
        {
            max_rect = std::max(max_rect, (R-st.top()-1)*A[L]);
        }
        else
        {
            max_rect = std::max(max_rect, R*A[L]);
        }   
    }
    return max_rect;
}
