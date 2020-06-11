// Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

// Note:
// The number of people is less than 1,100.

 
// Example

// Input:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

// Output:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

// solution: compare and sort

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        
        return a[0] < b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compare);
        vector<vector<int>> ans(people.size(), vector<int>(2, -1));

        for (int i = 0; i < people.size(); i++) {
            int count = people[i][1];

            for (int j = 0; j < ans.size(); j++) {
                if (ans[j][0] == -1 && count == 0) {
                    ans[j][0] = people[i][0];
                    ans[j][1] = people[i][1];
                    break;
                } else if (ans[j][0] == -1 || ans[j][0] >= people[i][0]) {
                    count -= 1;
                }
            }
        }

        return ans;
    }
};