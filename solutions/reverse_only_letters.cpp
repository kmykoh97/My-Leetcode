// Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

 

// Example 1:

// Input: "ab-cd"
// Output: "dc-ba"
// Example 2:

// Input: "a-bC-dEf-ghIj"
// Output: "j-Ih-gfE-dCba"
// Example 3:

// Input: "Test1ng-Leet=code-Q!"
// Output: "Qedo1ct-eeLg=ntse-T!"
 

// Note:

// S.length <= 100
// 33 <= S[i].ASCIIcode <= 122 
// S doesn't contain \ or "

// solution: 2 pointers

class Solution {
public:
    bool isValidCharacter(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;

        return false;
    }

    string reverseOnlyLetters(string S) {
        int i = 0;
        int j = S.length()-1;

        while (i < j) {
            if (isValidCharacter(S[i]) && isValidCharacter(S[j])) swap(S[i++], S[j--]);
            else {
                if (!isValidCharacter(S[i])) ++i;
                if (!isValidCharacter(S[j])) --j;
            }
        }
        
        return S;
    }
};