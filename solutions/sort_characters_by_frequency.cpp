// Given a string, sort it in decreasing order based on the frequency of characters.

// Example 1:

// Input:
// "tree"

// Output:
// "eert"

// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input:
// "cccaaa"

// Output:
// "cccaaa"

// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input:
// "Aabb"

// Output:
// "bbAa"

// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

// solution: map & heap/priorityqueue

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hashmap;
        priority_queue<pair<int, char>> pq;
        string result = "";

        for (char c : s) {
            hashmap[c]++;
        }

        for (auto m : hashmap) {
            pq.push(make_pair(m.second, m.first));
        }

        while (!pq.empty()) {
            pair<int, char> temp = pq.top();

            for (int i = 0; i < temp.first; i++) {
                result += temp.second;
            }
            
            pq.pop();
        }

        return result;
    }
};