.MODEL SMALL
 .STACK 100H

 .DATA
    MSG1  DB  'Enter a Hex digit (A-F) : $\'
    MSG2  DB  'In decimal it is : $\'

 .CODE
   MAIN PROC
    
     ; initialize DS
     MOV AX, @DATA   
     MOV DS, AX
     
     ; load and display MSG1
     LEA DX, MSG1 
     MOV AH, 9
     INT 21H
     
     ; read AND save the hex digit
     MOV AH, 1                    
     INT 21H

     MOV BL, AL               
     
     MOV dl, 10
     MOV ah, 02h
     INT 21h
     MOV dl, 13
     MOV ah, 02h
     INT 21h
     
     ; load and display MSG2
     LEA DX, MSG2      
     MOV AH, 9
     INT 21H
     
     ; display the first decimal digit
     MOV AH, 2                    
     MOV DL, 31H
     INT 21H
     
     ; convert and displaY second digit
     SUB BL, 11H                 

     MOV DL, BL                  
     INT 21H
     
     ;DOS return
     MOV AH, 4CH                 
     INT 21H
   MAIN ENDP
 END MAIN