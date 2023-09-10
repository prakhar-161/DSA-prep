

// Returns true if the string is pangram else false
bool checkPangram(string& str)
{
    // Initialize a set of characters
    set<char> set;
 
    for (auto ch : str) {
        // If the character is already
        // a lowercase character
        if (ch >= 'a' and ch <= 'z')
            set.insert(ch);
 
        // In case of a uppercase character
        if (ch >= 'A' and ch <= 'Z') {
            // convert to lowercase
            ch = tolower(ch);
            set.insert(ch);
        }
    }
 
    // check if the size is 26 or not
    return set.size() == 26;
}