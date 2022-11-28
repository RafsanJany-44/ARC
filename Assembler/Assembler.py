# a function to convert binary to hexadecimal
def binToHexa(n):
    return hex(int(n, 2))[2:]

# a function to convert decimal to binary
def deciToBin(n):
  return bin(int(n,10))

def main(assembly):
  #opcode dictionary
  opcode_type_1={   
    "add"   : "0000",
    "sub"   : "0010",
    "and"   : "0011",
    "beq"   : "1010",
    "bne"   : "1011",
    "slt"   : "1100",
    "bge"   : "1110"
  }

  opcode_type_2 = {
    "addi"  : "0001",
    "sll"   : "0100",
    "lw"    : "0101",
    "sw"    : "0110",
    "slti"  : "1101"
  }

  opcode_type_3 = {
    "in"    : "0111",
    "out"   : "1000",
    "disp"  : "1001",
    "j"     : "1111"
  }

  registers={
    "$zero" : "0000",
    "$s0"   : "0001",
    "$s1"   : "0010",
    "$s2"   : "0011",
    "$s3"   : "0100",
    "$s4"   : "0101",
    "$s5"   : "0110",
    "$s6"   : "0111",
    "$t0"   : "1000",
    "$t1"   : "1001",
    "$t2"   : "1010",
    "$t3"   : "1011",
    "$t4"   : "1100",
    "$t5"   : "1101",
    "$t6"   : "1110",
    "$t7"   : "1111",
    "l"     : "1000",

  }

  gateway = list(assembly.lower().split(" "))

  #this section will formate the space (add $s1,$s2 or add $s1, $s2 )
  try:
    if len(gateway)==3:
      instruction = gateway[0]
      reg=[gateway[1].replace(',', ''), gateway[2]]

    elif gateway[0]=="disp":
      instruction="disp"

    else:
      instruction = gateway[0]
      reg=gateway[1].split(",")
  except Exception as e:
      return "Syntex Does not match!!"

  #in this section, R tyep register will be decoded.
  if instruction in opcode_type_1.keys():
    try:
      hexa_opCode = binToHexa(opcode_type_1[instruction])
      hexa_rs     = binToHexa(registers[reg[0]])
      hexa_rd     = binToHexa(registers[reg[1]])
      return hexa_opCode + hexa_rs + hexa_rd
    
    except Exception as e:
      return "Syntex Does not match!!"


  #in this section, I tyep register will be decoded.
  elif instruction in opcode_type_2.keys():
    try:
      if int(reg[1],10)<=15:                #immediate can not be greater then 15 cause register hase only 4 bit
        hexa_opCode   = binToHexa(opcode_type_2[instruction])
        hexa_rs       = binToHexa(registers[reg[0]])
        immediate_bin = deciToBin(reg[1])                     
        hexa_immediate     = binToHexa(immediate_bin)
        return hexa_opCode + hexa_rs + hexa_immediate
      else:
        return "Bits out of bound...."
    
    except Exception as e:
          return "Syntex Does not match!!"


  #in this section, J tyep register will be decoded.
  elif instruction in opcode_type_3.keys():
    try:
      if instruction=="disp":
        hexa_opCode   = binToHexa(opcode_type_3[instruction])
        return hexa_opCode
      
      elif instruction == "in":
        hexa_opCode   = binToHexa(opcode_type_3[instruction])
        hexa_rs       = binToHexa(registers[reg[0]])
        return hexa_opCode + hexa_rs + binToHexa("0000")
      
      elif instruction == "out":
        hexa_opCode   = binToHexa(opcode_type_3[instruction])
        hexa_rs       = binToHexa(registers[reg[0]])
        return hexa_opCode + hexa_rs + binToHexa("0001")
        
      else:
        hexa_opCode   = binToHexa(opcode_type_3[instruction])
        hexa_rs       = binToHexa(registers[reg[0]])
        return hexa_opCode + hexa_rs
    
    except Exception as e:
          return "Syntex Does not match!!"


  else:
    return "Opcode did not match"



#File reading and writing section
input_file =  input("Enter the name of Assembly text File: ")
output_file = input("Enter the name of Hexa text File: ")

hex_list=[]

try:
  #reading the assembly.txt file
  file1 = open(input_file, 'r')
  Lines = file1.readlines()
  for line in Lines:
      hex_list.append(main(line.strip()))

  #wrriting the file
  with open(output_file, 'w') as f:
    for code in hex_list:
      f.write(code)
      f.write('\n')

except Exception as e: print(e)