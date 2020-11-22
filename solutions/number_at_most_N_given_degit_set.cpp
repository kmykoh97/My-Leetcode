// Given an array of digits, you can write numbers using each digits[i] as many times as we want.  For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.

// Return the number of positive integers that can be generated that are less than or equal to a given integer n.

 

// Example 1:

// Input: digits = ["1","3","5","7"], n = 100
// Output: 20
// Explanation: 
// The 20 numbers that can be written are:
// 1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
// Example 2:

// Input: digits = ["1","4","9"], n = 1000000000
// Output: 29523
// Explanation: 
// We can write 3 one digit numbers, 9 two digit numbers, 27 three digit numbers,
// 81 four digit numbers, 243 five digit numbers, 729 six digit numbers,
// 2187 seven digit numbers, 6561 eight digit numbers, and 19683 nine digit numbers.
// In total, this is 29523 integers that can be written using the digits array.
// Example 3:

// Input: digits = ["7"], n = 8
// Output: 1
 

// Constraints:

// 1 <= digits.length <= 9
// digits[i].length == 1
// digits[i] is a digit from '1' to '9'.
// All the values in digits are unique.
// 1 <= n <= 109

// solution: iteration

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int m = digits.size(); 
        int total = 0;
        string nums = to_string(n);
        int n_digits = nums.size();

        for (int i = 1; i < n_digits; i++ ) {
            total += pow(m, i); 
        }        
        
        for (int i = 0; i < n_digits; i++) {
            int lesser = 0;
            int equal = 0;

            for (auto& digit : digits) {
                if (digit < nums.substr(i, 1)) lesser +=1; 
                else if (digit == nums.substr(i, 1)) equal +=1; 
            }

            int remaining = n_digits-i-1;
            total += lesser*pow(m, remaining);

            if (equal == 0) break; 
            if ( i == n_digits-1 && equal == 1 ) total += 1; 
        }

        return total ; 
    }
};