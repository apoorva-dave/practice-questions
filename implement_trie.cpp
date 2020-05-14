struct Node
{
  char data;
  unordered_map <char, Node*> mp;
  bool ends_here;
  Node() : data('$') {}
  Node(char x) : data(x),ends_here(false) {}
};
class Trie {
public:
    /** Initialize your data structure here. */
    Node* head;
    Trie() {  
        head = NULL;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* n;
        if(head == NULL)
        {
            n = new Node();
            head = n;
            head->mp[word[0]] = new Node(word[0]);
        }
        else
        {
            n = new Node(word[0]);
            if(head->mp[word[0]] == nullptr)
            {
                 head->mp[word[0]] = new Node(word[0]);   
            }
        }
         n = head->mp[word[0]];
        //connect next nodes to n
        for(int i=1; i<word.length(); i++)
        {
            if(n->mp[word[i]] == nullptr)
            {
                Node* temp = new Node(word[i]);
                n->mp[word[i]] = temp;
                n = temp;
            }
            else
                n = n->mp[word[i]];
        }
        n->ends_here = true;
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* temp = head;
        int i;
        if(temp==nullptr)
            return false;
        for(i=0; i<word.length(); i++)
        {
            cout<<temp->data<<endl; //a p p l e
            if(temp->mp[word[i]] == nullptr)
                return false;
            // cout<<word[i]<<endl;
            temp = temp->mp[word[i]]; //temp = e
        }
        cout<<temp->data<<endl;
        
        return temp->ends_here;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* temp = head;
        int i;
        if(temp==nullptr)
            return false;
        for(i=0; i<prefix.length(); i++)
        {
            cout<<temp->data<<endl; //a p p l e
            if(temp->mp[prefix[i]] == nullptr)
                return false;
            // cout<<word[i]<<endl;
            temp = temp->mp[prefix[i]]; //temp = e
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */