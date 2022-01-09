class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        direction = ['N','E','S','W']
        crr = 0
        x = 0
        y = 0
        for i in range(0,len(instructions)):
            if(instructions[i] == 'G'):
                if(direction[crr] == 'N'):
                    y += 1
                elif(direction[crr] == 'E'):
                    x += 1
                elif direction[crr] == 'S':
                    y -= 1
                else: 
                    x -= 1
            elif(instructions[i] == 'L'):
                crr -= 1
                if crr<0: 
                    crr = 3
            else: 
                crr += 1 
                if crr == 4:
                    crr = 0
        if(x == 0 and y == 0): return True
        else: return direction[crr] != 'N'
                
                
                
        