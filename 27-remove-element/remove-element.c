int removeElement(int* nums, int numsSize, int val) {
    int si = numsSize - 1; // swap index (last-most non-val element)

    for (int i = si; i >= 0 ; --i) {
        if (nums[i] == val) {
            nums[i] = nums[si];
            --si;
        }
    }

    return si + 1;
}