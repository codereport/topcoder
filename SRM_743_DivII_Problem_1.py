# code_report Solution
# https://youtu.be/5zQQSeatnOE

class PlayingWithPlanks():
    def canItBeDone(self, l, p):
        return "possible" if (p*(p + 1))/2 <= l else "impossible"
