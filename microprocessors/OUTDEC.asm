OUTDEC PROC
;prints AX as a signed decimal integer
; input : AX
;output: none
    PUSH AX  ;save registers
    PUSH BX
    PUSH CX
    PUSH DX  

    OR AX,AX    ;ax<0 ?                     
    JGE @END_IF1  ;no , >0
    PUSH AX       ;save numbers    
    MOV DL,'-'    ;get '-'                                       
    MOV AH,2
    INT 21H      ; PRINT '-'
    POP AX       ; GET AX BACK
    NEG AX       ;AX = -AX                                     
@END_IF1:
;Get decimal degits 
    XOR CX,CX    ;CX counts digits
    MOV BX,10D   ;BX has Divisor
@REPEAT1:
    XOR DX,DX    ;Prepare high word of divident   
    DIV BX       ;AX= quitent DX= remainder
    PUSH DX      ;save remainder in stack
    INC CX       ; count++
;until    
    OR AX,AX     ;quitent =0 ?
    JNZ @REPEAT1 ;no, keep going
;convert digits to caracter and print
    MOV AH,2
;for count times do
@PRINT_LOOP:
    POP DX       ;digit in DL
    OR DL,30H    ; convert to char
    INT 21H      ;print digit
    LOOP @PRINT_LOOP  ;loop until done
;end for
    POP DX      ;restore registers
    POP CX
    POP BX
    POP AX
    RET
OUTDEC ENDP