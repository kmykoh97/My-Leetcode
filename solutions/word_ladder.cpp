// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

// Only one letter can be changed at a time.
// Each transformed word must exist in the word list.
// Note:

// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.
// Example 1:

// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]

// Output: 5

// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
// Example 2:

// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]

// Output: 0

// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

// solution: bfs

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> setlist;

        for (string word : wordList) {
            setlist.insert(word);
        }

        queue<string> q;
        q.push(beginWord);
        int ans = 0;

        while (!q.empty()) {
            ans++;
            int qcount = q.size();

            for (int i = 0; i < qcount; i++) {
                string temp = q.front();
                q.pop();

                if (temp == endWord) return ans;

                for (int j = 0; j < beginWord.length(); j++) {
                    int ori = temp[j];

                    for (int k = 'a'; k <= 'z'; k++) {
                        temp[j] = k;
                        if (!setlist.count(temp)) continue;
                        setlist.erase(temp);
                        q.push(temp);
                    }

                    temp[j] = ori;
                }
            }
        }

        return 0;
    }
};