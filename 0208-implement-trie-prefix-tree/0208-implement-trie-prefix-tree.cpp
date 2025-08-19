class Trie {
public:
    Trie* child[26];
    bool wordEnd;

    Trie() {
        for(int i=0;i<26;i++)child[i]=nullptr; 
        wordEnd=false;
    }
    
    void insert(string word) {
        Trie *node=this;
        for(char ch: word){
            if(!node->containsKey(ch)){
                node->put(ch , new Trie());
            }
            node = node->get(ch);//move to next char level in trie
        }
        node->wordEnd = true;
    }
    
    bool search(string word , bool isPrefix=false) {
        Trie *node = this;
        for(char ch:word){
            if(!node->containsKey(ch)){
                return false;
            }
            node=node->get(ch);
        }
        if(!isPrefix)return node->wordEnd;
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix , true);
    }

    bool containsKey(char ch){
        return child[ch - 'a'] != nullptr;
    }

    void put(char ch , Trie* node){
        child[ch - 'a'] = node;
    }

    Trie* get(char ch){
        return child[ch - 'a'];
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */