struct Node{
    int data;
    Node* next;
    int min;
};
class MinStack {
public:
    /** initialize your data structure here. */
    Node* head; 

    MinStack() {
        head = NULL;
    }
    
    void push(int x) {
        Node* temp = new Node();
        temp->next = NULL;
        temp->data = x;
        temp->min = 0;
        if(head==NULL)
        {
            head = temp;
            head->min = x;
        }
        else
        {
            //head->min will always point to lowest element found so far
            temp->min = std::min(head->min,x);
            // cout<<head->min;
            temp->next = head;
            head = temp;
            
        }
    }
    
    void pop() {
        
        if(head==NULL)
            return;
        else
        {
            Node* temp=head;
            head = temp->next;
            delete(temp);
        }
    }
    
    int top() {
        if(head==NULL)
            return -1;
        else
        {
            return head->data;
        }
    }
    
    int getMin() {
        if(head==NULL)
            return -1;
        return head->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */