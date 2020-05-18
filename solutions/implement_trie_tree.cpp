#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <set>

using namespace std;

// Implement a trie with insert, search, and startsWith methods.

// Example:

// Trie trie = new Trie();

// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");   
// trie.search("app");     // returns true
// Note:

// You may assume that all inputs are consist of lowercase letters a-z.
// All inputs are guaranteed to be non-empty strings.

// solution: trie/map

class Trie {
public:
    /** Initialize your data structure here. */
    struct TrieNode {
        unordered_map<char, TrieNode*> hashmap;
        bool endOfWord = false;
    };

    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* temp = root;

        for (char c : word) {
            if (!temp->hashmap.count(c)) {
                temp->hashmap[c] = new TrieNode();
            }

            temp = temp->hashmap[c];
        }

        temp->endOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* temp = root;

        for (char c : word) {
            if (!temp->hashmap.count(c)) {
                return false;
            } else {
                temp = temp->hashmap[c];
            }
        }

        return temp->endOfWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* temp = root;

        for (char c : prefix) {
            if (!temp->hashmap.count(c)) {
                return false;
            } else {
                temp = temp->hashmap[c];
            }
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */