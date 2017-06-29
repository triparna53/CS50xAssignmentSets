import cs50
import sys

def main():
    if len(sys.argv) != 2:
        print("Error!")
        exit(1)
    
    key = int(sys.argv[1])
    cipher = []
    plaintext = cs50.get_string()
    for c in plaintext:
        if c.isalpha():
            cipher.append(caesar(c, key))
        else:
            cipher.append(c)
                
    print("".join(cipher))
    exit(0)

def caesar(char, key):
    if char.isupper():
        return chr(((ord(char) - 65 + key) % 26) + 65)
    else:
        return chr(((ord(char) - 97 + key) % 26) + 97)
        
if __name__ == "__main__":
    main()