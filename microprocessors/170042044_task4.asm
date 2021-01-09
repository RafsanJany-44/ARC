.MODEL SMALL
.STACK 10H
.DATA 
    str1 DB "*******",10,13,"*******",10,13,"*******",10,13,"**"
    i1 DB ?
    i2 DB ?
    i3 DB ?
    str2 DB "**",10,13,"*******",10,13,"*******",10,13,"*******$"
    

.CODE
    MAIN PROC
        ;
        ;
        Mov AX, @DATA
        Mov DS, AX
        ;
        Mov AH, 2
        Mov DL, '?'
        INT 21H
        ;
        Mov AH, 1
        INT 21H
        Mov i1, AL
        ;
        INT 21H
        Mov i2, AL
        ;
        INT 21H
        MoV i3, AL
        ;
        ;
        Mov AH, 2
        Mov DL, 0DH
        INT 21H
        Mov DL,0AH
        INT 21H
        ;
        ;bell 7   dl
        ;
        ;
        Mov AH, 9
        LEA DX, str1
        INT 21H
        ;
        ;
        Mov AH, 2
        Mov DL, 7
        INT 21H
        ;
        ;
        Mov AH, 4CH
        INT 21H
        ;
    MAIN ENDP


END MAIN