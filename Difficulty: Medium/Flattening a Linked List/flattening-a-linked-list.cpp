/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        
        Node* temp = root;
        while(temp!= NULL && temp->next!=NULL)
        {
            Node* l1 = temp;
            Node* l2 = temp->next;
            Node* n = temp->next->next;
            
            Node* head = new Node(-1);
            Node* main = head;
            while(l1 || l2)
            {
                if(l1 && l2 && l1->data < l2->data)
                {
                    main->bottom = l1;
                    l1 = l1->bottom;
                    main = main->bottom;
                }
                else if(l1 && l2 && l1->data >= l2->data)
                {
                    main->bottom = l2;
                    l2 = l2->bottom;
                    main = main->bottom;
                }
                else if(l1 && !l2)
                {
                    main->bottom = l1;
                    l1 = l1->bottom;
                    main = main->bottom;
                }
                else if(!l1 && l2)
                {
                    main->bottom = l2;
                    l2 = l2->bottom;
                    main = main->bottom;
                }
                main->next = nullptr;
            }
            temp = head->bottom;
            temp->next = n;
        }
        return temp;
    }
};