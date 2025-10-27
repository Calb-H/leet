// equation being maximized: (i2-i1)*min(height[i1], height[i2])
// obvious solution is O(n^2) checking for max of every combination

int min(int i_cmp, int i_s, int* height) {
    return (height[i_cmp] > height[i_s]) ? height[i_s] : height[i_cmp];
}

/*
int maxArea(int* height, int heightSize) {
    int max = 0;
    for (int i_s = 0; i_s < heightSize; ++i_s) {
        for (int i_cmp = i_s+1; i_cmp < heightSize; ++i_cmp) {
            int a_water = min(i_cmp, i_s, height) * (i_cmp - i_s);
            if (a_water > max) {
                max = a_water;
            }
        }
    }

    return max;
}
*/

int maxArea(int* height, int heightSize) {
    int max = 0;
    for (int i_s = 0; i_s < heightSize; ++i_s) {
        for (int i_cmp = heightSize-1; i_cmp > i_s; --i_cmp) {
            int width = i_cmp - i_s;

            // there is no height[i_cmp] that will produce a higher max
            if (height[i_s] * width <= max) {
                break;
            }

            int min_h = min(i_cmp, i_s, height);
            int a_water = min_h * width;
            if (a_water > max) {
                max = a_water;
            }

            // largest value for this iteration found
            if (min_h == height[i_s]) {
                break;
            }
        }
    }

    return max;
}