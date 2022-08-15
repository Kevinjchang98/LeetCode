class MinStack {
public:
    struct Node {
        int val;
        Node* next;
    };
    
    Node* head;
    Node* min;
    
    MinStack() {
        head = nullptr;
        min = nullptr;
    }
    
    void push(int val) {
        if (!head) {
            head = new Node();
            head->val = val;
            head->next = nullptr;
            
            min = new Node();
            min->val = val;
            min->next = nullptr;
        } else {
            Node* temp = new Node();
            temp->val = val;
            temp->next = head;
            head = temp;
            
            if (val <= min->val) {
                Node* tempMin = new Node();
                tempMin->val = val;
                tempMin->next = min;
                min = tempMin;
            }
        }
    }
    
    void pop() {
        if (head) {
            Node* temp;
            if (head->val == min->val) {
                temp = min;
                min = min->next;
                delete temp;
            }
                
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return min->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */