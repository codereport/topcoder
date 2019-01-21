# code_report Solution
# Video Link: https://youtu.be/g0MsAyI_zGI
# Problem Link: https://arena.topcoder.com/#/u/practiceCode/17404/78412/15285/2/332030

class Sherlock:
    def isItHim(self, f, l):
        isHim = len(f) >= 7 and \
                len(l) >= 7 and \
                f[0] == 'B' and \
                l[0] == 'C' and \
                sum(1 for i in f if i in 'BENEDICT')   >= 3 and \
                sum(1 for i in l if i in 'CUMERBATCH') >= 5
        if isHim: return 'It is him'
        else:     return 'It is someone else'
