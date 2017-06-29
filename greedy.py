import cs50

def main():
    print("O hai!")
    while True:
        print("How much change is owed?")
        f = cs50.get_float()
        if f >= 0:
            break
    print("")
    pcoins = 0
    p = int(round(f * 100))
    
    pcoins += p // 25
    p %= 25
    
    pcoins += p // 10
    p %= 10
    
    pcoins += p // 5
    p %= 5
    
    pcoins += p
    
    print("{}".format(pcoins))
    
if __name__ == "__main__":
    main()