// Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

// Example:

// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
// Note:  

// 1 is typically treated as an ugly number.
// n does not exceed 1690.

// solution: dp

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> result;
        int i = 0, j = 0, k = 0;
        
        if (n == 0) return 0;
        result.push_back(1);
        
        while (result.size() < n) {
            int temp1 = result[i] * 2;
            int temp2 = result[j] * 3;
            int temp3= result[k] * 5;
            int minNum = min(temp1, min(temp2, temp3));
            result.push_back(minNum);
            
            if (minNum == temp1) i++;
            if (minNum == temp2) j++;
            if (minNum == temp3) k++;
        }
        
        return result[result.size()-1];
    }
};