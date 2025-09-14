class Solution {
public:
    /*
    int reverse(int x) {
        // find p where 10^(p+1) > INT_MAX >= 10^p -- 10^p = INT_MAX -- log 10 of INT_MAX
        //const int max_place = pow(10, (int)log10(INT_MAX));
        int place = 1000000000;
        int new_place = 1;
        int digits = 0;
        int result = 0;

        // find place of first digit

        if (x / place) {
            // it could overflow so do a check
            // this is not ideal
        }
        while (!(x / place)) {
            place /= 10;
        }

        while (place > 0) {
            digits = x / place;
            x -= place*digits;
            result += digits * new_place;
            place /= 10;
            new_place *= 10;
        }

        // TODO: handle overflow

        return result;
    }
    */

    // array impl to make overflow check easier

    int reverse (int x) {
        int place = 1000000000;
        int result = 0;
        int8_t digits[10];

        if (x == 0) {
            return 0;
        }

        while (!(x / place)) {
            place /= 10;
        }

        int max_place = place;

        int i = -1;
        while (place > 0) {
            ++i;
            digits[i] = x/place;
            x -= digits[i] * place;
            place /= 10;
        }

        place = max_place;

        // set up for overflow check if needed
        // reuse variable to save space
        bool check_over = false;
        if (i >= 9) {
            check_over = true;
            x = INT_MAX;
        }

        while (i >= 0) {
            if (check_over) {
                int max_val = x / place;
                x -= max_val * place;
                if (abs(digits[i]) > max_val) {
                    return 0;
                } 
                if (abs(digits[i]) < max_val) {
                    check_over = false;
                }
            }

            result += digits[i] * place;
            place /= 10;
            --i;
        }

        return result;
    }
};