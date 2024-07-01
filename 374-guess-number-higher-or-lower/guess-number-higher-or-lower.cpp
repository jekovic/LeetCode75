/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    long long result = 0;
    int guessNumber(int n) {
        long long left = 1, right = n;
        while(left<=right) {
            long long k = (left+right)/2;
            if(guess(k) == 0) {
                result = k;
                break;
            }
            else if(guess(k) == -1){
                right = k - 1;
            }
            else if(guess(k) == 1) {
                left = k + 1;
            }
        }
        return result;
    }
};