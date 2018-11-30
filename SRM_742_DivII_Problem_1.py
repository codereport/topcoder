# code_report Solution
# https://youtu.be/y3vnhJ2rrd0

class BirthdayCandy:   
    def mostCandy(self, k, c):
    	return max(e // (k+1) + e % (k+1) for e in c)
