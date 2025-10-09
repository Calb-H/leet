#define MAX_DIGIT 7

/*
bool isPalindrome(int x) {
    int place = 1000000; // max place for 32 bit int is millions
    bool first_found = false;
    //bool digits_odd = false;
    int digits[MAX_DIGIT] = {0};
    int first_index = 0;
    int mirror_offset = 1;
    int thresh_index = 0;

    if (x < 0) {
        return false;
    }

    if (x < 10) {
        return true;
    }

    for (int index = MAX_DIGIT - 1 ; index >= 0 ; --index) {
        int digit = x/place;

        if (!first_found) {
            if (digit) {
                first_found = true;
                //digits_odd = index && 1;
                first_index = index;
                thresh_index = first_index/2; // I think this is wrong for even numbers
                if (first_index && 1) {
                    ++thresh_index;
                    ++mirror_offset;
                }
            } else {
                continue;
            }
        }

        // there is really no need to store values after the midpoint
        // an index can be rolled one way and then another after the midpoint
        // (storage can be 1/2 the size of the max value)
        if (index < thresh_index) {
            if (digit != digits[index + mirror_offset]) {
                return false;
            }
            thresh_index += 2;
        } 

        digits[index] = digit;
    }
    return true;
}
*/

bool isPalindrome(int x) {

    int cache[6] = {};
    int order = 1000000000;
    int place = 10;

    if (x < 0) {
        return false;
    }

    if (x < 10) {
        return true;
    }

    int digit = 0;

    digit = x / order;
    while (!digit) {
        order /= 10;
        digit = x / order;
        --place;
    }

    bool isOdd = place & 1;
    int turnaround = place / 2;
    int i = 0;
    int j = turnaround;

    while (1) {

        if (i < turnaround) {
            cache[i] = digit;
            ++i;
        } else {
            if ((j == turnaround) && isOdd) {
                x %= order;
                order /= 10;
                digit = x / order;
            }

            --j;
            if (digit != cache[j]) {
                return false;
            }
        }

        if (order <= 1)
            return true;

        x %= order;
        order /= 10;
        digit = x / order;
    }

    return true;

}