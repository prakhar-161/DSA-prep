// OPTIMAL APPROACHES
// without extra space

// Solution - 1   (will be accepted)
class Solution {
public:
    void merge(long long arr1[], long long arr2[], int n, int m) { 
        int left = n-1, right = 0;
        while(left >= 0 && right < m) {
            if(arr1[left] > arr2[right]) {
                swap(arr1[left], arr2[right]);
                left--;
                right++;
            }
            else {
                break;
            }
        }     

        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    } 
};
// TC -> O(min(n, m)) + O(n*logn) + O(m*logm)



// Solution - 2 (this will also be accepted)
// shell sort
// reducing the gap with ceil(gap/2) everytime
void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge(long long arr1[], long long arr2[], int n, int m) {
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}
// TC -> O((n+m)*log(n+m))
// SC -> O(1)