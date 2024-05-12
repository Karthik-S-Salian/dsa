no_chars = ["abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]

def d2c(digit:str)->list[str]:
    combos = []
    if not digit:
        return combos

    def inner(digits,p):
        for char in no_chars[int(digits[0])-2]:
            if len(digits)==1:
                combos.append(p+char)
            else:
                inner(digits[1:],p+char)

    inner(digit,"")

    return combos

print(d2c("23"))