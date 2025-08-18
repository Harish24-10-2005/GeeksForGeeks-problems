/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void ins(stack<int>&s,int ele)
{
    if(s.empty() || ele > s.top())
    {
        s.push(ele);
        return;
    }
    int temp = s.top();
    s.pop();
    ins(s,ele);
    s.push(temp);
    
}
void rec(stack<int>&s)
{
    if(s.empty()) return;
    
    int temp = s.top();
    s.pop();
    rec(s);
    ins(s,temp);
}
void SortedStack ::sort() {
    // Your code here
    rec(s);
}