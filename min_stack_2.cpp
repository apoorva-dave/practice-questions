// struct Node{
//     int val;
//     struct Node* next;
//     int min;
// };
// Node *head;
// MinStack::MinStack() {
//     head = NULL;
// }

// void MinStack::push(int x) {
//     Node *temp = new Node();
//     temp->val = x;
//     temp->next = NULL;
//     if(head==NULL)
//     {
//         head=temp;
//         head->min = x;
//     }
//     else
//     {
//         temp->min = std::min(head->min,x);
//         temp->next = head;
//         head = temp;
//     }
    
// }

// void MinStack::pop() {
//     if(head!=NULL)
//     {
//         Node *temp = head;
//         head = temp->next;  
//         delete(temp);   
//     }
// }

// int MinStack::top() {
//     if(head!=NULL)
//         return head->val;
//     else
//         return -1;
// }

// int MinStack::getMin() {
//     if(head!=NULL)
//         return head->min;
//     else
//         return -1;
// }

vector<int> st;
vector<int> mins;

MinStack::MinStack() {
    st.clear();
    mins.clear();
}

void MinStack::push(int x) {
    int sm = mins.size();
    if(!sm || mins[sm-1] > x)
        mins.push_back(x);
    
    st.push_back(x);
}

void MinStack::pop() {
    if(!st.size()) return;
    int x = MinStack::top();
    st.pop_back();
    if(x == mins[mins.size()-1]) mins.pop_back();
}

int MinStack::top() {
    int sz = st.size();
    if(!sz) return -1;
    return st[sz-1];
}

int MinStack::getMin() {
    if(!mins.size()) return -1;
    return mins[mins.size()-1];
}
