FIND_IJ PROC  
    SUB AX,1 
    IMUL CX
    SUB BX,1
    ADD AX,BX
    IMUL SIZE
    ADD AX,DX
    MOV DX,AX
    RET
    
FIND_IJ ENDP 
    
    