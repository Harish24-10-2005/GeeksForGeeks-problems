class Node{
public:
  Node* links[26];
  bool f = false;
  bool iscontain(char a)
  {
      return links[a-'a'] != NULL;
  }
  void put(char a, Node* node)
  {
      links[a-'a'] = node;
  }
  Node* get(char a)
  {
      return links[a - 'a'];
  }
  void end()
  {
      f = true;
  }
};

class Trie{
private: Node* root;
public:
    Trie()
    {
        root = new Node();
    }
    void insert(string s)
    {
        Node* node = root;
        for(auto a:s)
        {
            if(!node->iscontain(a))
            {
                node->put(a,new Node());
            }
            node = node->get(a);
        }
        node->end();
    }
    bool search(string s)
    {
        Node* node = root;
        for(auto a:s)
        {
            if(node->iscontain(a))
            {
                node = node->get(a);
            }
            else
            {
                return false;
            }
        }
        return node->f;
    }
    
};


class Solution {
public:
    string longestValidWord(vector<string>& words) {
        // code here
        Trie trie;
        string s = "";
        int len = 0;
        for(auto a:words)
        {
            trie.insert(a);
        }
        for(auto a:words)
        {
            string temp ="";
            bool f = true;
            for(auto i:a)
            {
                temp+=i;
                if(!trie.search(temp))
                {
                    f = false;   
                    break;
                }
            }
            if(f)
            {
                if(a.size() > s.size())
                {
                    s = a;
                    len = a.size();
                }
                else if(a.size() == s.size())
                {
                    if(a < s)
                    {
                        s = a;
                    }
                }
            }
        }
        return s;
    }
};
