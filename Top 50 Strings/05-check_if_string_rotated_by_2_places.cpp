

// Method - 1
// TC -> O(N)
// SC -> O(N)

class Solution {
public:
    bool check(string a, string b) {
        // for anti-clockwise
        string b1 = b.substr(b.size() - 2, b.size());
        string b2 = b.substr(0, b.size() - 2);
        string b3 = b1 + b2;
        if(b3 == a) return true;

        // for clockwise
        b1 = b.substr(2, b.size());
        b2 = b.substr(0, 2);
        b3 = b1 + b2;
        if(b3 == a) return true;

        return false;
    }
};

// Method - 2 (Space optimization
// TC -> O(N)
// SC -> O(1)

class Solution {
public:
    bool isRotated(string str1, string str2)
{
    // Your code here
    // clockwise direction check
    int n = str1.length();
    bool clockwise = true, anticlockwise = true;
    for (int i = 0; i < n; i++)
    {
        if (str1[i] != str2[(i + 2) % n])
        {
            clockwise = false; // not rotated clockwise
            break;
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        if (str1[(i + 2) % n] != str2[i])
        {
            anticlockwise = false; // not rotated anticlockwise
            break;
        }
    }
 
    return clockwise or anticlockwise; // if any of both is true, return true
}
};