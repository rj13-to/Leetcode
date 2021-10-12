/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int st=1,ed=n;
        int mid;
        while(st<=ed){
            mid=st+(ed-st)/2;
            if(guess(mid)==0) return mid;
            else if(guess(mid)<0) ed=mid-1;
            else st=mid+1;
        }
        return 0;
    }
};