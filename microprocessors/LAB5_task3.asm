 .MODEL SMALL   
 
 .STACK 100H

 .DATA 
 
 
    PROMPT  DW  'ROW(M) : $'
    M    DW  ?  
    
    PROMPT1  DW  'COLUMN(N) : $' 
    N     DW  ? 
      
    PROMPT2  DW  'I : $'
    I    DW  ?  
    
    PROMPT3  DW  'J : $' 
    J     DW  ?
	
    SIZE  DW   2

    PROMPT4  DW  'OFFSET ADDRESS : $'    
    PROMPT5  DW  'VALUE : $' 

    
    
    ARRAY   DW  80 DUP(?)
 
            

 .CODE 
 
 
   MAIN PROC
     MOV AX, @DATA                
     MOV DS, AX    
               
     LEA DX, PROMPT               
     MOV AH, 9
     INT 21H  
     
     CALL INDEC
     MOV M, AX     
     
     MOV AH, 2                  
     MOV DL, 0DH                
     INT 21H                    

     MOV DL, 0AH                
     INT 21H
      
     
     LEA DX, PROMPT1               
     MOV AH, 9
     INT 21H  
     
     CALL INDEC
     MOV N, AX

     MOV AH, 2                  
     MOV DL, 0DH                
     INT 21H                    

     MOV DL, 0AH                
     INT 21H     
               
     LEA SI, ARRAY                
     MOV CX, M
      
     
      @L_1:                     
       MOV BX, N                  

       @L_2:                   
         CALL INDEC                 

         MOV [SI], AX
         
         MOV AH, 2                  
         MOV DL, 0DH                
         INT 21H                    

         MOV DL, 0AH                
         INT 21H             

         ADD SI, 2               
         DEC BX                   
       JNZ @L_2                

       MOV AH, 2                  
       MOV DL, 0DH                
       INT 21H                    

       MOV DL, 0AH                
       INT 21H 
      LOOP @L_1 
      
      
     ;TAKING I, J
     LEA DX, PROMPT2               
     MOV AH, 9
     INT 21H  
     
     CALL INDEC
     MOV I, AX     
     
     MOV AH, 2                  
     MOV DL, 0DH                
     INT 21H                    

     MOV DL, 0AH                
     INT 21H
      
     
     LEA DX, PROMPT3               
     MOV AH, 9
     INT 21H  
     
     CALL INDEC
     MOV J, AX

     MOV AH, 2                  
     MOV DL, 0DH                
     INT 21H                    

     MOV DL, 0AH                
     INT 21H     
                    
     
     ;a) Display the Matrix

;     LEA SI, ARRAY                
;     MOV CX, M                    

;     @L_3:                     
;       MOV BX, N                  

;       @L_4:                   
;         MOV AX, [SI]             

;         CALL OUTDEC 
         
;         MOV DL, ' '
;         MOV AH, 2
;         INT 21H             

;         ADD SI, 2               
;         DEC BX                  
;       JNZ @L_4                

;       MOV AH, 2                  
;       MOV DL, 0DH                
;       INT 21H                    

;       MOV DL, 0AH                
;       INT 21H                    
;     LOOP @L_3  
     
;     MOV AH, 2                  
;     MOV DL, 0DH                
;     INT 21H                    

;     MOV DL, 0AH                
;     INT 21H
     
     
                             
     
     ;FIND_IJ
     MOV AX, I
     MOV BX, J
     MOV CX, N 
     LEA SI, ARRAY
     MOV DX, SI
     CALL FIND_IJ 
     
     MOV SI,DX
     
     
     LEA DX, PROMPT4               
     MOV AH, 9
     INT 21H
     
     MOV AX,SI
     CALL OUTDEC 
     
     MOV AH, 2                  
     MOV DL, 0DH                
     INT 21H                    

     MOV DL, 0AH                
     INT 21H
     
     
     LEA DX, PROMPT5               
     MOV AH, 9
     INT 21H
     
     MOV AX,ARRAY[SI]
     CALL OUTDEC 
       
                       

     MOV AH, 4CH                  
     INT 21H 
     
     
   MAIN ENDP
   
   INCLUDE D:\emu8086\MySource\INDEC.ASM
   INCLUDE D:\emu8086\MySource\OUTDEC.ASM
   INCLUDE D:\emu8086\MySource\FIND_IJ.ASM
      
   
   END MAIN