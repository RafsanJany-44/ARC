.MODEL SMALL
    .STACK 100H
    .DATA
        PROMPT1  DB  'First Number: $' 
        PROMPT2  DB  'Second Number: $'
        NUM1 DW ?     
        NUM2 DW ?
        PROMPT3  DB  'Product: $'
    .CODE
        MAIN PROC
            
            MOV AX,@DATA
            MOV DS,AX 
            
            ;show msg1
            LEA DX,PROMPT1
            MOV AH,9
            INT 21H
            ;input procedure
            CALL INDEC
            MOV 3000H,AX

            ; line break
            MOV AH, 2                  
            MOV DL, 0DH                
            INT 21H                    

            MOV DL, 0AH                
            INT 21H

            ;show msg2
            LEA DX,PROMPT2
            MOV AH,9
            INT 21H 
            
            ;input procedure
            CALL INDEC
            MOV 3002H,AX

            ; line break
            MOV AH, 2                  
            MOV DL, 0DH                
            INT 21H                    

            MOV DL, 0AH                
            INT 21H
            
            ; show msg3
            LEA DX,PROMPT3
            MOV AH,9
            INT 21H
            
            ; CALCULATION
            MOV AX, [3000H]
            MOV BX, [3002H]
            MUL BX
            MOV [3004H], AX
            MOV [3006H], AX

            ;output 
            CALL OUTDEC
            
            MOV AH,4CH
            INT 21H
            
        MAIN ENDP
        
        INCLUDE D:\emu8086\MySource\INDEC.ASM
        INCLUDE D:\emu8086\MySource\OUTDEC.ASM
    
    END MAIN