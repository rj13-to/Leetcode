class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m=minutes;
        double h=hour*5+m/12.0;
        double deg=6*(max(h,m)-min(h,m));
        return min(deg,360-deg);
    }
};