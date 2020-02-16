#include<bits/stdc++.h>
using namespace std;
// creating a trie to store words
// each node will have 2 properties - 1. char array of TreeNode* (i.e there can be 256 children for each node)
// 2. freq which is the number of times each letter appears 
// shortest unique prefix for a string will be the first letter whose freq =1 when traversing from root
struct TrieNode
{
  TrieNode* child[256];
  int freq;  
};
TrieNode* getNode()
{
    TrieNode* root = new TrieNode();
    root->freq = 1;
    for(int i=0;i<256;i++)
    {
        root->child[i]=NULL;
    }
    return root;
}
void insert(TrieNode *root, string s)
{
    //if character already exists then, move to next
    // else create a new node with that character value and insert it
    TrieNode *crawl = root;
    int len = s.length();
    for(int i=0;i<len;i++)
    {
        int index = s[i]; //eg dog is string then index = s[0] -> index = 100 (ascii of d)
        if(crawl->child[index]==NULL)
        {
            crawl->child[index] = getNode();
        }
        else
        {
            (crawl->child[index]->freq)++;
        }
        crawl = crawl->child[index];
    }
}
void prefixUtil(TrieNode *root, char prefix[], vector <string> &res, int ind, vector <string> A)
{
    if(root==NULL)
    {
        return;
    }
    if(root->freq == 1)
    {
        prefix[ind] = '\0';
        // cout<<prefix<<endl;
        res.push_back(prefix);
        return;
    }
    for(int i=0;i<256;i++)
    {
        if(root->child[i] != NULL)
        {
            prefix[ind] = i;
            prefixUtil(root->child[i],prefix,res,ind+1,A);
        }
    }
  
}
bool startswith(string x, string y)
{
    //x startswith y
    int i=0;
    while(x[i]==y[i] && i<y.length())
    {
        i++;
    }
    return (i==(y.length()));
}
vector<string> prefix(vector<string> &A) {
    vector <string> res;
    TrieNode* root = getNode();
    root->freq=0;
    for(int i=0;i<A.size();i++)
    {
        insert(root,A[i]); //insert A[i] in trie
    }
    //trie is created with freq of each node
    // traverse from root to node to find 1st node with freq 1
    char prefix[256];
    prefixUtil(root,prefix,res,0,A);
    vector <string> result;
    for(int j=0;j<A.size();j++)
    {
        for(int i=0;i<res.size();i++)
        {
            if(startswith(A[j],res[i]))
           {
               result.push_back(res[i]);
               break;
           }
        }   
    }
    return result;
}

int main()
{
    vector <string> A{"zebra", "dog", "dot", "duck" };
    vector <string> res= prefix(A);
    cout<<res[0];
    return 0;
}