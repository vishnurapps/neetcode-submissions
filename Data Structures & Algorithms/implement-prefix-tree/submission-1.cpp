class PrefixTree {
private:
    struct Node{
        Node* children[26]{};
        bool isEnded = false;
    };

    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;

        for(char c: word){
            int idx = c - 'a';
            
            if(curr->children[idx] == nullptr){
                curr->children[idx] = new Node();
            }

            curr = curr->children[idx];
        }
        curr->isEnded = true;
    }
    
    bool search(string word) {
        Node* curr = root;

        for(char c: word){
            int idx = c - 'a';

            if(curr->children[idx] == nullptr){
                return false;
            }

            curr = curr->children[idx];
        }
        
        if(!curr->isEnded){
            return false;
        }

        return true;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;

        for(char c: prefix){
            int idx = c - 'a';
            if(curr->children[idx] == nullptr){
                return false;
            }
            curr = curr->children[idx];
        }

        return true;
    }
};
