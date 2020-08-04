class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2) // need smaller array first (to get log(min(n1, n2)) solution)
            return findMedianSortedArrays(nums2, nums1);

        // l and r represents the minimum and maximum number of elements respectively, that we can
        // pick from nums1 array to get the elements that fall to the left of the final median
        int l = 0, r = n1;
        while(l <= r) {
            // total number of elements including median to the left of it will be: (n1 + n2 + 1) / 2
            
            // choose the number of elements to pick in such a way that we can 
            // eliminate half of the available range at each step (ie. pick from the middle).
            int numbersFromNums1 = (l + r) / 2;
            int numbersFromNums2 = ((n1 + n2 + 1) / 2) - numbersFromNums1;

            // get last number selected from nums1 and nums2
            // also get next number in nums1 and nums2
            int lastNumFromNums1 = (numbersFromNums1 == 0) ? INT_MIN : nums1[numbersFromNums1-1];
            int nextNumFromNums1 = (numbersFromNums1 == n1) ? INT_MAX : nums1[numbersFromNums1];
            int lastNumFromNums2 = (numbersFromNums2 == 0) ? INT_MIN : nums2[numbersFromNums2-1];
            int nextNumFromNums2 = (numbersFromNums2 == n2) ? INT_MAX : nums2[numbersFromNums2];

            // check whether we got all elements to left of median
            // if yes, return median. else, update l or r value accordingly and continue.
            if (lastNumFromNums1 <= nextNumFromNums2 && lastNumFromNums2 <= nextNumFromNums1) {
                if ((n1 + n2) % 2 == 1) return max(lastNumFromNums1, lastNumFromNums2);
                else return (max(lastNumFromNums1, lastNumFromNums2) + min(nextNumFromNums1, nextNumFromNums2)) / 2.0;
            }
            else if (lastNumFromNums1 < nextNumFromNums2) {
                l = numbersFromNums1 + 1;
            }
            else {
                r = numbersFromNums1 - 1;
            }
        }
        
        return -1; // this won't get executed
    }
};