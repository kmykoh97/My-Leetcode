#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// Given an array of strings, group anagrams together.

// Example:

// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]

// Note:

// All inputs will be in lowercase.
// The order of your output does not matter.

// solution: sort all strings in array. Place in same array if match

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> hashmap;
        vector<vector<string>> ret;

        // place anagrams in mapped array
        for (string str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            hashmap[temp].push_back(str);
        }

        // place arrays in result array
        for (auto hashmapitem : hashmap) {
            ret.push_back(hashmapitem.second);
        }

        return ret;
    }
};