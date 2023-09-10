

// Left rotations by -> 'x' places
// Right rotations will be by -> (n-x) places


// Method - 1
// We can create partitions in string 'a' and move them if the updated string 'a' is not equal to rotated string 'b'
// if all partitions are done, and the strings donot match anytime, then return false

// Conditions - 
// length of s1 = length of s2
// there should be a match in any rotation

// TC -> O(N^2) 
// partitions -> N-1
// comparing both strings of length N for each partition 


// Method - 2
// better TC
// KMP Algorithm approach - string matching

// just add s2 pattern to s1 to form a 'text' string
// find if s2 lies in 'text' string or not
// if it lies, return true else false

bool areRotations(string str1, string str2) {
    /* Check if sizes of two strings are same */
    if (str1.length() != str2.length())
        return false;
 
    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
}
 
// TC -> O(length of temp + length of str1);
// i.e.
// TC -> O(3n) ~ O(n)