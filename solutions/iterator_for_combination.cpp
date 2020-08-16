// Design an Iterator class, which has:

// A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
// A function next() that returns the next combination of length combinationLength in lexicographical order.
// A function hasNext() that returns True if and only if there exists a next combination.
 

// Example:

// CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

// iterator.next(); // returns "ab"
// iterator.hasNext(); // returns true
// iterator.next(); // returns "ac"
// iterator.hasNext(); // returns true
// iterator.next(); // returns "bc"
// iterator.hasNext(); // returns false
 

// Constraints:

// 1 <= combinationLength <= characters.length <= 15
// There will be at most 10^4 function calls per test.
// It's guaranteed that all calls of the function next are valid.

// solution: premutation

class CombinationIterator {
public:
    string s;
    queue<string> q;
    
    void helper(int start, int len, string txt) {
        if (!len) {
            q.push(txt);
            return;
        }
        
        for (int i = start; i <= s.length() - len; ++i) {
            helper(i+1, len-1, txt + s[i]);
        }
    }

    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        helper(0, combinationLength, "");
    }
    
    string next() {
        string temp = q.front();
        q.pop();
        return temp;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */