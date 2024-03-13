#include <iostream>
using namespace std;

class TrieNode {
    public:

    char data;
    TrieNode **children;
    bool isTerminal;

    // constructor
    TrieNode(char ch) {
        data = ch;
        children = new TrieNode*[26];
        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }

        isTerminal = false;
    }

};

class Trie {
    TrieNode* root;

    public:

    Trie() {
        root = new TrieNode('\0');
    }

    void insertWord(root, word) {
        // base case
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        TrieNode *child;
        int idx = word[0]-'a';
        if(root->children[idx] != NULL) {
            child = root->children[idx];
        }
        else {
            child = new TrieNode(word[0]);
            root->children[idx] = child;
        }

        // recursive call
        insertWord(child, word.substr(1));
    }
    // for user
    void insert(string word) {
        insertWord(root, word);
    }

    bool searchWord(root, word) {
        // base case
        if(word.length() == 0) {
            return root->isTerminal;
        }

        // check if root's child contains character word[0]
        int idx = word[0]-'a';
        if(root->children[idx] != NULL) return searchWord(root->children[idx], word.substr(1));
        else return false;
    }
    // for user
    bool search(string word) {
        return searchWord(root,word);
    }

    void removeWord(root, word) {
        
        if(word.length() == 0) {
            root->isTerminal = false;
        }

        // check if word[0] char is in root's child
        int idx = word[0]-'a';
        if(root->children[idx] != NULL) {
            removeWord(root->children[idx], word.substr(1));
        }
    }
    // for user
    void remove(string word) {
        removeWord(root, word);
    }
};
