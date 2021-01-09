.MODEL SMALL
.STACK 10H
.DATA
    num1 DB ?
    num2 DB ?
    sum DB ? 

.CODE
    MAIN PROC
        ;
        ;
        Mov AH, 1
        INT 21H
        Mov num1, AL
        ;
        INT 21H
        Mov num2, AL
        ;
        ;
        ADD AL, num1
        SUB AL, 30H
        Mov SUM, AL 
        ;
        ;
        Mov AH, 2 
        Mov DL, 0DH
        INT 21H
        Mov DL, 0AH
        INT 21H
        Mov DL, sum
        INT 21H
        ;
        Mov AH, 4CH
        INT 21H
        ;
     MAIN ENDP

END MAIN