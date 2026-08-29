class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        left = right = NULL;

    }
};

class LRUCache {
public:
    
    map<int , pair<Node*,int>> mp;
    Node* tail  ;
    Node* head;
    int cap;

    LRUCache(int capacity) {
        tail = new Node(-1);
        head  = new Node(-1);
        tail->right = head;
        head->left = tail;
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;

        Node* temp = mp[key].first;


        temp->left->right = temp->right;
        temp->right->left = temp->left;
        

        tail->right->left = temp;
        temp->right = tail->right;
        tail->right = temp;
        temp->left = tail;



        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* temp = mp[key].first;
            temp->left->right = temp->right;
            temp->right->left = temp->left;
            mp.erase(key);
            delete(temp);
        }

        int sz = mp.size();

        if(sz>=cap){
            Node* lol = head->left;
            lol->right->left = lol->left;
            lol->left->right = lol->right;
            mp.erase(lol->val);
            delete(lol);
        }

        Node* temp = new Node(key);
        mp[key] = {temp,value};

        tail->right->left = temp;
        temp->right = tail->right;
        tail->right = temp;
        temp->left = tail;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */