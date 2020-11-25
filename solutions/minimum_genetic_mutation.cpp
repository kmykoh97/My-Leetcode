// A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".

// Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.

// For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.

// Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.

// Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.

// Note:

// Starting point is assumed to be valid, so it might not be included in the bank.
// If multiple mutations are needed, all mutations during in the sequence must be valid.
// You may assume start and end string is not the same.
 

// Example 1:

// start: "AACCGGTT"
// end:   "AACCGGTA"
// bank: ["AACCGGTA"]

// return: 1
 

// Example 2:

// start: "AACCGGTT"
// end:   "AAACGGTA"
// bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

// return: 2
 

// Example 3:

// start: "AAAAACCC"
// end:   "AACCCCCC"
// bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

// return: 3

// solution: bfs

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {    
        queue<string> q;
        q.push(start);
        unordered_set<string> visited;
        visited.insert(start);
        int mutations = 0;
        
        while (!q.empty()) {
            size_t size = q.size();
            
            while (size--) {
                string curr = q.front();
                q.pop();
                if (curr == end) return mutations;
                for (const string& gene : bank) {
                    if (visited.count(gene) || !validMutation(curr, gene)) continue;
                    visited.insert(gene);
                    q.push(gene);
                }
            }
            
            ++mutations;
        }

        return -1;
    }

    bool validMutation(const string& s1, const string& s2) {
        int count = 0;

        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i] && count++) return false;
        }

        return true;
    }
};