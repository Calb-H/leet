class Solution {
public:

    /* writing my thought process as an exercise, and because I legitimately needed to for this one (sleepy/rusty ig)*/

    // number of letters in a zag = rows - 2 ? -- if the value is <= 0, then there is no zag
    // if row

    // I could write this thing into a 2D array and then read out the new structure, but
    // skipping over the empty spaces is a (mem and cycle) waste. I would also have to loop twice
    // defining an algorithm for picking the right indices should be better.
    /*
    P A Y P
        A
      L
    I S H I
        R
      I
    N G
    */
    // 5 rows
    // o    o
    // o   oo
    // o  o o
    // o o  o
    // o    o

    // 2 rows
    // oooooo
    // oooooo

    // top row math:
    // 1 row - every letter goes into the string as-is (bottom, special?)
    // 2 rows - every other (2nd) letter is printed
    // 3 rows - every 4th letter is printed 
    // 4 rows - every 6th letter is printed

    // 2nd row math
    // 1 row - N/A
    // 2 rows - every other (2nd) letter, but starting at i=1 (bottom, special?)
    // 3 rows - every other (2nd) letter, starting at i=1
    // 4 rows - every 7th letter starting at i=1 (ofc) AND every 4th letter (due to zag)

    // 3rd row math
    // 1 row - N/A
    // 2 rows - N/A
    // 3 rows - every 4th letter starting at i=2 (bottom)
    // 4 rows - every 6th letter starting at duh AND every 2nd letter starting

    // first and last rows may be special cases
    // middle rows have a pattern
    // distance from a middle letter to the next column is (zero-indexed) 
    // origin column h       zag length     next column h
    // (rowMax - rowIndex) + (rowMax - 1) + (rowIndex + 1) = rowMax*2 --- hmmm, this will fail.

    // without zag, we need to add the full height of a column to get to the next character...
    // with zag (h > 2) we need to add the number of chars in the zag, so h - 2
    // next *row* character index equation is then, rowHeight*2 -2 + sourceIndex ---- 
    // rowMax*2 = (rowHeight - 1)*2  <- this is where my mistake was

    // This next row equation also works for the first and last row

    // calculating zag index for each consecutive row -- pattern is........
    // columnWidth = zagHeight = rowHeight -2, relative index moves closer to the pivot index as the row descends
    // next character = 2*(rowHeight - 1 - rowDepth) + sourceIndex
    // example: the S in the example string (PAYPALISFIRING) is at sourceIndex=7 and rowDepth = 1 when rowHeight = 4
    // 2*(4 -1 -1) +7 = 11 = the index of the last 'I', which is correct

    string convert(string s, int numRows) {

        if (numRows == 1) {
            return s;
        }

        // loop once for each row
        // loop once for each non-zag column (zig?)
        const int strLen = s.length();
        const int zigzagSize = 2*numRows - 2; // (numRows - 1) * 2 -- represents number of chars in the |/ excluding nex column start
        const int numZigzags = (strLen / zigzagSize) + ((strLen % zigzagSize != 0) ? 1 : 0); // ceiling(string size / chars per zigzag)

        std::string retStr;

        for (int rd=0 ; rd < numRows ; ++rd) {

            int zagOffset = 2*(numRows - rd - 1);
            int startIndex = rd;

            for (int col=0 ; col < numZigzags ; ++col) {

                // append row first letter
                if(startIndex >= strLen) {
                    break;
                }
                retStr.push_back(s[startIndex]);

                // calculate row zag letter
                int zagIndex = startIndex + zagOffset;
                if (zagIndex >= strLen) {
                    break;
                }

                // append row zag letter (if extant)
                if ((rd != 0) && (rd != numRows-1)) {
                    retStr.push_back(s[zagIndex]);
                }

                // calculate next row index
                startIndex += zigzagSize;
            }
        }
        return retStr;
    }
};