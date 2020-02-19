int Solution::solve(string A, string B, vector<string> &C) {

    queue <string> q;
    q.push(A);
    unordered_set <string> words(C.begin(),C.end());
    unordered_map <string, int> distance; //store the distancetance from start to the current word
    distance[A] = 1;
    while(!q.empty())
    {
        string x = q.front();
        q.pop();
        if(x==B)
            break;
        for(int i=0;i<x.length();i++)
        {
            for(char c='a';c<='z';c++)
            {
                string newWord = x;
                newWord[i] = c;
                if(words.find(newWord) != words.end() && distance.find(newWord)==distance.end())
                {
                    distance[newWord] = distance[x] + 1;
                    q.push(newWord);
                }
            }
        }
    }
    if(distance.find(B)==distance.end())
        return 0;
    else
        return distance[B];
    
    // //string A -> string B st each intermediate string is in C
    // queue <string> q;
    // q.push(A);
    // int len = A.length();
    // int count=0; // number of transformations
    // while(!q.empty())
    // {
    //     count++; 
    //     int Qsize = q.size();
    //     for(int j=0;j<Qsize;j++)
    //     {
    //         string x = q.front();
            
    //         q.pop();

            
    //         //loop through each character of string A
    //         for(int i=0;i<len;i++)
    //         {
    //             char origChar = x[i];
    //             // change each character of string A from a to z and check if it is in C
    //             for(char c = 'a'; c<='z';c++)
    //             {
    //                 x[i] = c;
    //                 if(x == B)
    //                     return count+1;
    //                 auto it = find(C.begin(),C.end(),x);
    //                 if(it == C.end())
    //                     continue;
                    
    //                 q.push(x);
    //                 C.erase(it);
    //             }
    //             x[i] = origChar;
    //         }
    //     }
    // }
    // return 0;
}
