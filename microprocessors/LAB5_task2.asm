.MODEL SMALL
.STACK 100h
.DATA        
    ARR DB 50 DUP(?) ; declare array with null value initially
    PROMPT1  DB   'ENTER SIZE OF ARRAY: $'
    PROMPT2  DB   'ENTER VALUES FOR ARRAY 1: $'
    PROMPT4  DB   'ENTER VALUES FOR ARRAY 2: $'
    PROMPT3  DB   'OUTPUT: $'
    COUNT DW ?

.CODE
    MAIN PROC
        MOV AX,@DATA
        MOV DS,AX

        LEA DX, PROMPT1            
        MOV AH, 9
        INT 21H

        CALL INDEC        
        MOV COUNT,AX
        MOV SI,501H
        
        
        MOV AH, 2                  
        MOV DL, 0DH                
        INT 21H                    

        MOV DL, 0AH                
        INT 21H
        
        
        
        LEA DX, PROMPT2            
        MOV AH, 9
        INT 21H
        
        
        MOV AH, 2                  
        MOV DL, 0DH                
        INT 21H                    

        MOV DL, 0AH                
        INT 21H
                
                
                
        MOV CX, COUNT
        INPUT:
           CALL INDEC
           MOV [SI], AL
           INC SI
           
           
           
           MOV AH, 2                  
           MOV DL, 0DH                
           INT 21H                    

           MOV DL, 0AH                
           INT 21H
           
           
           LOOP INPUT
               
               
        MOV AH, 2                  
        MOV DL, 0DH                
        INT 21H                    

        MOV DL, 0AH                
        INT 21H 
        

        MOV SI,601H  
        
        
        MOV AH, 2                  
        MOV DL, 0DH                
        INT 21H                    

        MOV DL, 0AH                
        INT 21H   
        
        
        LEA DX, PROMPT4            
        MOV AH, 9
        INT 21H
        
        
        MOV AH, 2                  
        MOV DL, 0DH                
        INT 21H                    

        MOV DL, 0AH                
        INT 21H 
        
        

        MOV CX, COUNT
        INPUT2:
           CALL INDEC
           MOV [SI], AL
           INC SI 
           
           
           MOV AH, 2                  
           MOV DL, 0DH                
           INT 21H                    

           MOV DL, 0AH                
           INT 21H 
           
           
           LOOP INPUT2  
           
        
       MOV AH, 2                  
       MOV DL, 0DH                
       INT 21H                    

       MOV DL, 0AH                
       INT 21H 
       
       
            
        LEA DX, PROMPT3            
        MOV AH, 9
        INT 21H

        MOV CX, COUNT
        MOV SI, 601H
        MOV DI, 501H

        MULDIV:
            MOV AL, [DI]
            MOV BL, [SI]
            MUL BL
            MOV [DI], AL
            INC SI
            INC DI
            LOOP MULDIV 

        MOV CX,COUNT
        MOV SI, 501H
        MOV AH,2  
        OUTPUT:
            MOV AH, 0
            MOV AL,[SI]
            CALL OUTDEC
            INC SI 
            
            
            MOV AH, 2                  
            MOV DL, 0DH                
            INT 21H                    

            MOV DL, 0AH                
            INT 21H
            
            
           LOOP OUTPUT

        MOV AH, 4CH           
        INT 21H
    MAIN ENDP
        INCLUDE D:\emu8086\MySource\INDEC.ASM
        INCLUDE D:\emu8086\MySource\OUTDEC.ASM


END MAIN