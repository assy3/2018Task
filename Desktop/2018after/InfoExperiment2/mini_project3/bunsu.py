def add(number1, number2):
    puls_minus1 = number1[0]
    puls_minus2 = number2[0]
    if(puls_minus1 < 0):
        puls_minus1 = 1
    if(puls_minus2 < 0):
        puls_minus2 = 1
    child1 = puls_minus1 * number1[1]  * number1[3] + number1[2]
    child1 = child1 * number2[3]
    child2 = puls_minus2 * number2[1]  * number2[3] + number2[2]
    child2 = child2 * (number1[3])
    mother = number1[3] * number2[3]

    children = child1 + child2

    count = 0
    #加算用にも追加
    puls_minus = 1
    if(children < 0):
        puls_minus = -1
        children = children*(-1)

    for i in range(children // mother):
        children -= mother
        count += 1
    saidaikouyaku = gcd(children, mother)

    if(children != 0):
        children = children / saidaikouyaku
        mother = mother / saidaikouyaku 
    else:
        mother = 1

    number3 = (number1[0], count, children, mother)
    #print(number3)
    return number3

def sub(number1, number2):
    puls_minus = number1[0]
    child1 = number1[0] * number1[1]  * number1[3] + number1[2]
    child1 += child1 * (number2[3]-1)
    child2 = number2[0] * number2[1]  * number2[3] + number2[2]
    child2 += child2 * (number1[3]-1)
    mother = number1[3] * number2[3]
    children = child1 - child2
    count = 0
    #減算用に追加した処理
    if(children < 0):
        puls_minus = -1
        children = children*(-1)

    for i in range(children // mother):
        children -= mother
        count += 1
    saidaikouyaku = gcd(children, mother)
    if(children != 0):
        children = children / saidaikouyaku
        mother = mother / saidaikouyaku 
    else:
        mother = 1
    number3 = (puls_minus, count, children, mother)
    # print("減算")
    # print(number3)
    return number3
 


def mul(number1, number2):
    puls_minus = number1[0]
    child1 = number1[0] * number1[1]  * number1[3] + number1[2]
    mul1 = child1
    #print(child1)
    child1 += child1 * (number2[3]-1)
    #print(child1)
    child2 = number2[0] * number2[1]  * number2[3] + number2[2]
    mul2 = child2
    #print(child2)
    child2 += child2 * (number1[3]-1)
    #print(child2)
    mother = number1[3] * number2[3]
    #print(mother)
    children = mul1 * mul2
    #print(children)
    count = 0
    for i in range(children // mother):
        children -= mother
        count += 1
    saidaikouyaku = gcd(children, mother)
    if(children != 0):
        children = children / saidaikouyaku
        mother = mother / saidaikouyaku 
    else:
        mother = 1
    number3 = (puls_minus, count, children, mother)
    # print("乗算")
    # print(number3)
    return number3

def div(number1, number2):
    puls_minus = number1[0]
    child1 = number1[0] * number1[1]  * number1[3] + number1[2]
    #print(child1)
    children = child1 * (number2[3])
    #print(children)
    child2 = number2[0] * number2[1]  * number2[3] + number2[2]
    #print(child2)
    mother = child2 * (number1[3])
    #print(mother)
    count = 0
    for i in range(children // mother):
        children -= mother
        count += 1
    saidaikouyaku = gcd(children, mother)
    if(children != 0):
        children = children / saidaikouyaku
        mother = mother / saidaikouyaku 
    else:
        mother = 1
    number3 = (puls_minus, count, children, mother)
    # print("除算")
    # print(number3)
    return number3
    


def gcd(seisu1, seisu2):
    if(seisu1 == 0):
        return 0
    if(seisu2 == 0):
        return 0 
    if(seisu1 < 0):
        seisu1 = seisu1*(-1)
    if(seisu2 < 0):
        seisu2 = seisu2*(-1)
    listA = []
    listB = []
    for i in range(seisu1):
        i += 1
        if(seisu1 % i == 0):
            listA.append(i)
    for i in range(seisu2):
        i += 1    
        if(seisu2 % i == 0):
            listB.append(i) 
    listC = list(set(listA) & set(listB))
    target_num = len(listC) - 1     
    listC.sort()  
    return listC[target_num]

if __name__ == '__main__':
    number1 = (-1, 1, 1, 2)
    number2 = (-1, 2, 2, 3)
    add(number1, number2)
    # gcd(52,8)
    # sub(number1, number2)
    # mul(number1, number2)
    # div(number1, number2)