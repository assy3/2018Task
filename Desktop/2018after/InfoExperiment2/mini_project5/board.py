class Board:
    def __init__(self, data):
        self.data = data

    def filled(self):
        flag = 0
        elements = len(self.data[1])
        for i in range(elements):
            for j in range(elements):
                if(self.data[i][j] == 0):
                    flag += 1
        if(flag == 0):
            return True
        else:
            return False

    # def verify(self):
    #     length = 0
    #     side = 0
    #     block = 0
    #     elements = len(self.data[1])
    #     #length
    #     for i in range(elements):
    #         for j in range(elements):
    #             length += self.data[i][j]
    #         if(length == 45):
    #             length = 0
    #         else:
    #             return False
    #     #side
    #     for i in range(elements):
    #         for j in range(elements):
    #             side += self.data[j][i]
    #         if(side == 45):
    #             side = 0
    #         else:
    #             return False   
    #     #block
    #     for i in range(0, 3):
    #         for j in range(3):
    #             block += self.data[i][j]   
    #         for j in range(3):
    #             block += self.data[i][j+3]   
    #         for j in range(3):
    #             block += self.data[i][j+6] 
    #         if(block == 45):
    #             block = 0
    #         else:
    #             return False
    #     for i in range(3, 6):
    #         for j in range(3):
    #             block += self.data[i][j]   
    #         for j in range(3):
    #             block += self.data[i][j+3]   
    #         for j in range(3):
    #             block += self.data[i][j+6]   
    #         if(block == 45):
    #             block = 0
    #         else:
    #             return False
    #     for i in range(6, 9):
    #         for j in range(3):
    #             block += self.data[i][j]   
    #         for j in range(3):
    #             block += self.data[i][j+3]   
    #         for j in range(3):
    #             block += self.data[i][j+6]   
    #         if(block == 45):
    #             block = 0
    #         else:  
    #             return False
    #     return True

    def verify(self):
        length = []
        side = []
        block = []
        elements = len(self.data[1])
        
        #length
        for i in range(elements):
            # 縦9の数字をリストに追加
            for j in range(elements):
                length.append(self.data[i][j])
            
            #リストから0だけを消す
            for k in length:
                if(k == 0):
                    length.remove(0)
            # もし1~9の中で重複があれば
            if(len(set(length)) == len(length)):
                return False
            else:
                length.clear()

        print("length成功")

        # side
        for i in range(elements):
            # 横9の数字をリストに追加
            for j in range(elements):
                side.append(self.data[j][i])
            
            #リストから0だけを消す
            for k in side:
                if(k == 0):
                    side.remove(0)
            # もし1~9の中で重複があれば
            if(len(set(side)) == len(side)):
                return False
            else:
                side.clear()
        print("side成功")



        #block
        for i in range(0, 3):
            for j in range(3):
                block.append(self.data[i][j])   
            for j in range(3):
                block.append(self.data[i][j+3])   
            for j in range(3):
                block.append(self.data[i][j+6]) 
            #リストから0だけを消す
            for k in block:
                if(k == 0):
                    block.remove(0)
            #もし1~9の中で重複があれば
            if(len(set(block)) == len(block)):
                return False
            else:
                block.clear()

        for i in range(3, 6):
            for j in range(3):
                block.append(self.data[i][j])   
            for j in range(3):
                block.append(self.data[i][j+3])   
            for j in range(3):
                block.append(self.data[i][j+6]) 
            #リストから0だけを消す
            for k in block:
                if(k == 0):
                    block.remove(0)
            #もし1~9の中で重複があれば
            if(len(set(block)) == len(block)):
                return False
            else:
                block.clear()
        
        for i in range(6, 9):
            for j in range(3):
                block.append(self.data[i][j])   
            for j in range(3):
                block.append(self.data[i][j+3])   
            for j in range(3):
                block.append(self.data[i][j+6]) 
            #リストから0だけを消す
            for k in block:
                if(k == 0):
                    block.remove(0)
            #もし1~9の中で重複があれば
            if(len(set(block)) == len(block)):
                return False
            else:
                block.clear()
        return True



    def get_allowed_digits(self, x, y):
        elements = len(self.data[1])
        print(elements)
        allowed_list = [1,2,3,4,5,6,7,8,9]
        enpty_list = []
        if(self.data[x][y] != 0):
            return enpty_list

        #横検索
        for i in range(elements):
            if self.data[x][i] in allowed_list:
                allowed_list.remove(self.data[x][i])
        #縦検索
        for i in range(elements):
            if self.data[i][y] in allowed_list:
                allowed_list.remove(self.data[i][y])

        #ブロック検索

        if(x >= 0 and x < 3): 
            for i in range(0, 3):
                if(y >= 0 and y < 3):
                    for j in range(3):
                        if self.data[i][j] in allowed_list:
                            allowed_list.remove(self.data[i][j])
                if(y >= 3 and y < 6):   
                    for j in range(3):
                        if self.data[i][j+3] in allowed_list:
                            allowed_list.remove(self.data[i][j+3])   
                if(y >= 6 and y < 9):
                    for j in range(3):
                        if self.data[i][j+6] in allowed_list:
                            allowed_list.remove(self.data[i][j+6])
          
        
        #中段のまとまり
        if(x >= 3 and x < 6):
            for i in range(3, 6):
                if(y >= 0 and y < 3):
                    for j in range(3):
                        if self.data[i][j] in allowed_list:
                            allowed_list.remove(self.data[i][j])
                if(y >= 3 and y < 6):   
                    for j in range(3):
                        if self.data[i][j+3] in allowed_list:
                            allowed_list.remove(self.data[i][j+3])   
                if(y >= 6 and y < 9):
                    for j in range(3):
                        if self.data[i][j+6] in allowed_list:
                            allowed_list.remove(self.data[i][j+6])   
           

        #下段のまとまり
        if(x >= 6 and x < 9):
            for i in range(6, 9):
                if(y >= 0 and y < 3):
                    for j in range(3):
                        if self.data[i][j] in allowed_list:
                            allowed_list.remove(self.data[i][j])
                if(y >= 3 and y < 6):   
                    for j in range(3):
                        if self.data[i][j+3] in allowed_list:
                            allowed_list.remove(self.data[i][j+3])   
                if(y >= 6 and y < 9):
                    for j in range(3):
                        if self.data[i][j+6] in allowed_list:
                            allowed_list.remove(self.data[i][j+6])           
        
        return allowed_list    


    def move(self, x, y, d):
        # deep_copy
        elements = len(self.data[1]) #9
        
        sub = Board([list(self.data[0]), list(self.data[1]), list(self.data[2]), list(self.data[3]), list(self.data[4]), list(self.data[5]), list(self.data[6]), list(self.data[7]), list(self.data[8])])
        sub.data[x][y] = d 
        assert self.data[x][y] == 0
        return sub

    def __str__(self):
        separator = '+---+---+---+'
        lines = [separator]
        for i in range(0, 9, 3):
            for j in range(i, i + 3):
                lines.append('|%d%d%d|%d%d%d|%d%d%d|' % tuple(self.data[j]))
            lines.append(separator)
        return '\n'.join(lines).replace('0', ' ')


if __name__ == '__main__':
    board = Board([[5, 3, 0, 0, 7, 0, 0, 0, 0],
                   [6, 0, 0, 1, 9, 5, 0, 0, 0],
                   [0, 9, 8, 0, 0, 0, 0, 6, 0],
                   [8, 0, 0, 0, 6, 0, 0, 0, 3],
                   [4, 0, 0, 8, 0, 3, 0, 0, 1],
                   [7, 0, 0, 0, 2, 0, 0, 0, 6],
                   [0, 6, 0, 0, 0, 0, 2, 8, 0],
                   [0, 0, 0, 4, 1, 9, 0, 0, 5],
                   [0, 0, 0, 0, 8, 0, 0, 7, 9]])

    solution = Board([[5,3,4,6,7,8,9,1,2],
                    [6,7,2,1,9,5,3,4,8],
                    [1,9,8,3,4,2,5,6,7],
                    [8,5,9,7,6,1,4,2,3],
                    [4,2,6,8,5,3,7,9,1],
                    [7,1,3,9,2,4,8,5,6],
                    [9,6,1,5,3,7,2,8,4],
                    [2,8,7,4,1,9,6,3,5],
                    [3,4,5,2,8,6,1,7,9]])
    print(board)
    print(board.filled())
    print(board.verify())
    print(board.get_allowed_digits(0,2))
    print(board.move(1,2,4))

    print(solution.verify())

