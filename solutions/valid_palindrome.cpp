// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// Note: For the purpose of this problem, we define empty string as valid palindrome.

// Example 1:

// Input: "A man, a plan, a canal: Panama"
// Output: true
// Example 2:

// Input: "race a car"
// Output: false

// solution: iteration

class Solution {
public:
    bool isInvalid(char &c) {
        if ((c >= 'a' && c <='z') || (c >= '0' && c <='9') || (c >='A' && c <= 'Z')) {
            if (c > 'Z') {
                c = (char)((c -'a') + 'A');
            }
        
            return false;
        }

        return true;
    }

    bool isPalindrome(string s) {    
        if (s.length() > 1) {
            int left = 0;
            int right = s.length() - 1;

            while (left <= right) {
                while (isInvalid(s[left]) && left < s.length()) left++;

                while (isInvalid(s[right]) && right > 0) right--;

                if (left <= right) {
                    if (s[left] != s[right]) return false;

                    left++;
                    right--;
                } else break;
            }
        }

        return true;  
    }
};