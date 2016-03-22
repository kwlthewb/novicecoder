import sys
import io

def main():
    for step in range(9):
        print(step)
    words = ['cat','bat','hat','rat','sat']
    for w in words:
        print(w)

    num = 0
    while num <= 0:
        num = int(input("Number: "))
    print(num)



if __name__ == "__main__":
    # main()
    l = [1,2,3,4.4,5.5,'billy','bob',99,'100..000',-200.29]
    tt = (l) # by reference
    print(tt[0])
    print(tt[6])
    print(tt[8])
    l[0] = "a"

    tt[6] = 99
    tt.append('dkfj')
    l.remove(2)

    print(tt[0])
    print(tt[6])
    print(tt[8])
    print(tt[-1])
    print(tt)

    tt2 = (1,2,3,4,'dfkj,',66.777,'kkk',[1,2,3,4,5])
    print(tt2)
    print(tt2[0])
    print(tt2[4])
    print(tt2[6])
    print(tt2[7])
    tt2[7].remove(3)
    tt2[7].remove(4)
    tt2[7] = [1,2,99]
    print(tt2[0])
    print(tt2[4])
    print(tt2[6])
    print(tt2[7])