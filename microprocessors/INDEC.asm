INDEC PROC

;READ NUMBER IN RANGE -32768 TO 32767
;input :none
;output :AX =binary equivalent of number
    PUSH BX
    PUSH CX
    PUSH DX
;print prompt
@BEGIN:
;total =0
    XOR BX,BX ;BX hold total
;negative =false
    XOR CX,CX ;CX hold sign
;read char.
    MOV AH,1
    INT 21H
;case char. of
    CMP AL,'-' ;minus sign
    JE @MINUS ;yes,set sign
    CMP AL,'+' ;plus sign
    JE @PLUS ;yes,get another char.
    JMP @REPEAT2 ;start processing char.
@MINUS: 
    MOV CX,1
@PLUS:
    INT 21H
;end case
@REPEAT2:
;if char. is between '0' and '9'
    CMP AL,'0' ;char >='0'?
    JNGE @NOT_DIGIT ;illegal char.
    CMP AL,'9' ;char<='9' ?
    JNLE @NOT_DIGIT
;then convert char to digit
    AND AX,000FH
    PUSH AX   ;Save on stack
;total =total *10 +digit
    MOV AX,10
    MUL BX      ;AX= total * 10                                                  
    POP BX      ;retrive degit
    ADD BX,AX   ;total= total * 10 + degit
;Read a char
    MOV AH,1
    INT 21H
    CMP AL,0DH  ;carriage return?
    JNE @REPEAT2 ;no, keep going
;Untill CR
    MOV AX,BX   ;store number in AX
;if negetive
    OR CX,CX 
    JE @EXIT ;NO, EXIT
;THEN
    NEG AX ; YES, NEG
;END_IF
@EXIT:
    POP DX ; RESTORE REGISTERS
    POP CX  
    POP BX
    RET
;HERE IF ILLIGAL CHAR ENTERED
@NOT_DIGIT:
    ;MOVE CURSORE TO A NEW LINE
    MOV AH,2
    MOV DL,0DH
    INT 21H
    MOV DL,0AH
    INT 21H  
    JMP @BEGIN  ;GO TO BEGININIG   

INDEC ENDP

