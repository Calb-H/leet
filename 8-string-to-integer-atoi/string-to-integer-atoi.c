int myAtoi(char* s) {
    // process
    // skip whitespace
    // check for +/- (positive if not present)
    // skip leading zeros
    // if the value is out of range [-2,147,483,648, 2,147,483,647] round to bound

    int result = 0;

    if (s == NULL) {
        return result;
    }

    int i = 0;

    while (s[i] == ' ') {
        ++i;
    }

    bool negative = false;
    switch (s[i]) {
        case '-':
            negative = true;
        case '+':   // intentional fallthrough
            ++i;
        default:
            break;
    }

    while (s[i] == '0') {
        ++i;
    }

    int digits = 0;
    while (s[i] >= '0' && s[i] <= '9' && digits < 9) { // if digits > 9, do overflow handling
        result = result * 10 + s[i] - '0';
        ++i; ++digits;
    }

    if (s[i] >= '0' && s[i] <= '9') {
        if (s[i+1] >= '0' && s[i+1] <= '9') {
            return negative ? INT_MIN : INT_MAX;
        }
        //int max_lsd = negative ? 8 : 7
        if (result > INT_MAX / 10) {
            return negative ? INT_MIN : INT_MAX;
        }
        if (result == INT_MAX / 10) {
            if (negative && s[i] >= '8') { // ok because 7 can be stored
                return INT_MIN;
            } else if (s[i] > '7') {
                return INT_MAX;
            }
        }
        result = result * 10 + (s[i] - '0');
    }

    return negative ? result * -1 : result;
}