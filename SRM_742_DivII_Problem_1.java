// code_report Solution 
// https://youtu.be/y3vnhJ2rrd0

public class BirthdayCandy {
    public int mostCandy(int k, int[] c) {
        int ans = 0;
        for (int e : c) {
            ans = Math.max(ans, e / (k+1) + e % (k+1));
        }
        return ans;
    }
}
