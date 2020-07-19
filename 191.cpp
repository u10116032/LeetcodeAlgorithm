class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        /*
            O(32) with a for loop to count bit 1.
            Use n&(n-1) to quickly move to the next bit 1.

            0101100 n
            0101011 n-1
            0101000 n&n-1

            0101000 n
            0100111 n-1
            0100000 n&n-1

            0100000 n
            0011111 n-1
            0000000 n&n-1
        */
        int count=0;
        while(n) {
            count++;
            n=n&(n-1);
        }
        return count;
    }
};