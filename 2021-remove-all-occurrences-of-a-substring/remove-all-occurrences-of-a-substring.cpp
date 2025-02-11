class Solution {
public:
    string removeOccurrences(string s, string part) {
       int n = s.find(part);
    
    while (n != string::npos) {
        s.erase(n, part.length());
        n = s.find(part); // Find again after erasing
    }
    
    return s; 
    }
};