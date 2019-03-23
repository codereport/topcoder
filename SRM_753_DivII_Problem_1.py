# code_report Solution
# Video Link:
# Problem Link: https://arena.topcoder.com/#/u/practiceCode/17449/85533/15355/2/332231

class KerimJavati: 
    def howLong(self, text):
        return sum (2 * (ord(c) - ord('a')) + 1 for c in text)
