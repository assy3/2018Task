def add(number1, number2):
    if(number1[0] < 0):
        child1 = 1 * number1[1]  * number1[3] + number1[2]
        child1 = child1 * (-1)
    else:    
        child1 = number1[0] * number1[1]  * number1[3] + number1[2]    
    child1 = child1 * number2[3]
    
    if(number2[0] < 0):
        child2 = 1 * number2[1]  * number2[3] + number2[2]
        child2 = child2 * (-1)
    else:    
        child2 = number2[0] * number2[1]  * number2[3] + number2[2]
    child2 = child2 * (number1[3])

    mother = number1[3] * number2[3]
    children = child1 + child2
    count = 0
    flag = 0
    #帯分数の整数の数
    if(children < 0):
        children = children * (-1)
        flag = 1

    for i in range(children // mother):
        children -= mother
        count += 1
    saidaikouyaku = gcd(children, mother)

    if(children != 0):
        children = children / saidaikouyaku
        mother = mother / saidaikouyaku 
    else:
        mother = 1
    if(flag == 0):
        number3 = (number1[0], count, children, mother)
    else:
        if(children < 0):
            children = children * (-1)
        number3 = (number1[0], count, children, mother)
    return number3

def sub(number1, number2):
    if(number1[0] < 0):
        child1 = 1 * number1[1]  * number1[3] + number1[2]
        child1 = child1 * (-1)
    else:    
        child1 = number1[0] * number1[1]  * number1[3] + number1[2]    
    child1 = child1 * number2[3]
    
    if(number2[0] < 0):
        child2 = 1 * number2[1]  * number2[3] + number2[2]
        child2 = child2 * (-1)
    else:    
        child2 = number2[0] * number2[1]  * number2[3] + number2[2]
    child2 = child2 * (number1[3])

    mother = number1[3] * number2[3]
    children = child1 - child2
    count = 0
    flag = 0
    #帯分数の整数の数
    if(children < 0):
        children = children * (-1)
        flag = 1

    for i in range(children // mother):
        children -= mother
        count += 1
    saidaikouyaku = gcd(children, mother)

    if(children != 0):
        children = children / saidaikouyaku
        mother = mother / saidaikouyaku 
    else:
        mother = 1
    if(flag == 0):
        number3 = (number1[0], count, children, mother)
    else:
        if(children < 0):
            children = children * (-1)
        number3 = (number1[0], count, children, mother)
    return number3
 
def mul(number1, number2):
    puls_minus = number1[0] * number2[0] 
    if(number1[0] < 0):
        child1 = 1 * number1[1]  * number1[3] + number1[2]
        child1 = child1 * (-1)
    else:    
        child1 = number1[0] * number1[1]  * number1[3] + number1[2]    
    
    if(number2[0] < 0):
        child2 = 1 * number2[1]  * number2[3] + number2[2]
        child2 = child2 * (-1)
    else:    
        child2 = number2[0] * number2[1]  * number2[3] + number2[2]

    children = child1 * child2
    children = abs(children)
    mother =  number1[3] * number2[3]
    mother = abs(mother)

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

    return number3

def div(number1, number2):
    puls_minus = number1[0] * number2[0] 
    if(number1[0] < 0):
        child1 = 1 * number1[1]  * number1[3] + number1[2]
        child1 = child1 * (-1)
    else:    
        child1 = number1[0] * number1[1]  * number1[3] + number1[2]    
    
    if(number2[0] < 0):
        child2 = 1 * number2[1]  * number2[3] + number2[2]
        child2 = child2 * (-1)
    else:    
        child2 = number2[0] * number2[1]  * number2[3] + number2[2]

    children = child1 * (number2[3])
    children = abs(children)
    mother = child2 * (number1[3])
    mother = abs(mother)
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
    gcd(52,8)
    sub(number1, number2)
    mul(number1, number2)
    div(number1, number2)