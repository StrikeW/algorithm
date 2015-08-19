#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    bool exist;
    TrieNode* next[26];
    TrieNode() {
        exist=false;
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        root->exist=false;
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int sz=word.size();
        if(sz==0)
            return ;
        TrieNode* iter=root;
        int curr=0;
        while(curr<sz){
            if(iter->next[word[curr]-'a']==NULL){
                iter->next[word[curr]-'a']=new TrieNode();
            }
            iter=iter->next[word[curr]-'a'];
            curr++;
        }
        iter->exist=true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int sz=word.size();
        if(sz==0)
            return true;
        TrieNode* iter=root;
        int curr=0;
        while(curr<sz){
            if(iter->next[word[curr]-'a']==NULL){
                return false;
            }
            iter=iter->next[word[curr]-'a'];
            curr++;
        }
        return iter->exist;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int sz=prefix.size();
        if(sz==0)
            return true;
        TrieNode* iter=root;
        int curr=0;
        while(curr<sz){
            if(iter->next[prefix[curr]-'a']==NULL){
                return false;
            }
            iter=iter->next[prefix[curr]-'a'];
            curr++;
        }
        return true;
    }

private:
    TrieNode* root;
};



int main(){
    Trie trie;
    trie.insert("app");
    trie.insert("apple");
    trie.insert("beer");
    trie.insert("addd");

    cout<<trie.search("apps")<<endl;
    cout<<trie.search("a")<<endl;
    cout<<trie.search("ap")<<endl;
    cout<<trie.search("app")<<endl;
    cout<<trie.search("appl")<<endl;
    cout<<trie.search("ad")<<endl;

}