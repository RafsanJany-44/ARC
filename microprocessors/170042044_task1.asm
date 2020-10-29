.MODEL SMALL

.STACK 10H 


.DATA
    A DB ?
    B DB 10D


.CODE  

    MAIN    PROC
        
        ;Initialize the value of data segment
        MOV AX,@DATA
        MOV DS,AX
        
        ;Display '?' Char
        
        MOV AH,2 
        MOV DL, '?'
        INT 21H
        ; 
        ;Single key input
        
        MOV AH,1
        INT 21H
        MOV A,AL
        
         
        MOV AL,A 
        
        SUB AL,30h
        
        MOV BL,B
        SUB BL,AL
        SUB BL,AL
        SUB BL,1D 
        
        add BL,30H
        
        MOV A,BL 
        
        
        
        ;Display input character
        MOV AH,2   
        
        MOV DL,0Dh  
        INT 21H 
        
        MOV DL,0AH
        INT 21H 
        
        MOV DL,A
        INT 21H 
        
      
        ;DOS RETURN  
        
        MOV AH,4CH
        INT 21H
    MAIN    ENDP
        
        
END MAIN
