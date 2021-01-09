 .MODEL SMALL   
 
 .STACK 100H

 .DATA 
 
 
    PROMPT  DB  'Highest decimal on',0DH,0AH,'$' 
    PROMPT1  DB  'Column ' 
    IND   DB  ?, ': $' 
      
    TEMP    DW  0
    COUNT   DW  0
    SIZE    DW  2
    SIZE1   DW  8 
    MIN     DW  0

    ARRAY   DW  4 DUP(?)
            DW  4 DUP(?)
            DW  4 DUP(?) 
            

 .CODE 
 
 
   MAIN PROC
     MOV AX, @DATA                
     MOV DS, AX    
               
     MOV IND,49
               
     LEA SI, ARRAY                
     MOV CX, 3 
     
      @L_1:                     
       MOV BX, 4                  

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
     

 
     
     ;a) Display the Matrix

     LEA SI, ARRAY                
     MOV CX, 3                    

     @L_3:                     
       MOV BX, 4                  

       @L_4:                   
         MOV AX, [SI]             

         CALL OUTDEC 
         
         MOV DL, ' '
         MOV AH, 2
         INT 21H             

         ADD SI, 2               
         DEC BX                  
       JNZ @L_4                

       MOV AH, 2                  
       MOV DL, 0DH                
       INT 21H                    

       MOV DL, 0AH                
       INT 21H                    
     LOOP @L_3  
     
     
     
     
     ;b) Display the highest decimal on each column
     
     
     MOV AH, 2                  
     MOV DL, 0DH                
     INT 21H                    

     MOV DL, 0AH                
     INT 21H
       
       
     LEA DX, PROMPT               
     MOV AH, 9
     INT 21H 
     
     
     LEA SI, ARRAY 
     MOV TEMP, SI               
     MOV CX, 4                    

     @L_5:
       MOV SI, TEMP
       MOV AX, CX
       NEG AX
       ADD AX, 4
       MUL SIZE
       MOV COUNT, AX
       ADD SI, COUNT
                            
       MOV BX, 3                  

       @L_6:
                            
         MOV AX, [SI]
         CMP AX, MIN
         JG  @MAX
         JMP @ELSE
         
         @MAX:
         MOV MIN, AX
         JMP @ELSE
           
         @ELSE:
         ADD SI, SIZE1              
         DEC BX
               
                           
       JNZ @L_6
       
       LEA DX, PROMPT1              
       MOV AH, 9
       INT 21H                
                
       MOV AX, MIN
       CALL OUTDEC
       MOV MIN, 0 
       
       ADD IND,1        
                
       MOV AH, 2                  
       MOV DL, 0DH                
       INT 21H                    

       MOV DL, 0AH                
       INT 21H
                           
     LOOP @L_5
     
     
      
                    

     MOV AH, 4CH                  
     INT 21H 
     
     
   MAIN ENDP
   
   INCLUDE D:\emu8086\MySource\INDEC.ASM
   INCLUDE D:\emu8086\MySource\OUTDEC.ASM   
   
   END MAIN