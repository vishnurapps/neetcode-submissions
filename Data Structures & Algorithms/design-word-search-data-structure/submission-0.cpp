class WordDictionary {
private:
    struct Node {
        Node* children[26]{};
        bool isEnd;
    };
    
    Node* root;

    bool dfs(Node* curr, const string &word, int pos){
        if(pos == word.size()){
            return curr->isEnd;
        }

        if(word[pos] == '.'){
            for(int i = 0; i < 26; i++){
                if(curr->children[i] != nullptr){
                    if(dfs(curr->children[i], word, pos+1)){
                        return true;
                    }
                }
            }
            return false;
        } else {
            int idx = word[pos] - 'a';
            if(curr->children[idx] == nullptr){
                return false;
            }
            return dfs(curr->children[idx],word, pos+1 );
        }
        
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(char c: word){
            int idx = c - 'a';
            if(curr->children[idx] == nullptr){
                curr->children[idx] = new Node();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;

    }
    
    bool search(string word) {
        Node *curr = root;
        return dfs(curr, word, 0);
    }
};