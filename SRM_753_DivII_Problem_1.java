// code_report Solution
// Video Link: https://youtu.be/mdn7bsuK0Wo
// Problem Link: https://arena.topcoder.com/#/u/practiceCode/17449/85533/15355/2/332231

// Solution 1

import java.lang.String;

public class KerimJavati {
    public int howLong(String text) {
        int ans = 0;
        for (char c : text.toCharArray()) {
            ans += 2 * (c - 'a') + 1;
        }
        return ans;
    }
}

// Solution 2

import java.lang.String;

public class KerimJavati {
    public int howLong(String text) {
        return text
            	.chars()
            	.reduce(0, (a, b) -> a + 2 * (b - 'a') + 1);
    }
}
