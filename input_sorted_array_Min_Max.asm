#This sample program is to let user input one element in the array (list)
#and store the list in the memory
#COPYRIGHT H. Li 
#EDITED BY JEFFERSON SYLVA-IRIOGBE
#001163953

.text
main:
#input size of list
#printing prompt "Please enter the size of the list: \n"
la $a0, prompt_input_size #load address of "prompt_input_size" to a0
li $v0, 4 #set v0 as 4 for output string function in syscall
syscall

#taking the input
li $v0, 5 #v0 = 5 for input integer function in syscall
syscall

#copy the size from v0 to the variable "size"
la $t0, size #loading the size address of list in $t0
sw $v0, 0($t0) #store input integer to the size of list
move $a1, $v0 #copy v0 to a1

addi $s1, $0, 0
la $t0, list
addi $t2, $0, 0

input_loop:
addi $s1, $s1, 1
blt $a1, $s1, end_input_loop
#printing the prompt of "Please enter the element\n"
la $a0, prompt_input_element #load address of "prompt_input_element" to a0
li $v0, 4 #li: load integer, set v0 as 4 for output string function in syscall
syscall

#taking the input
li $v0, 5 #v0 = 5 for input integer function in syscall
syscall

#move the input integer to the array
add $t3, $t2, $t0
sw $v0, 0($t3)
addi $t2, $t2, 4

j input_loop


end_input_loop:

#showing elements in the array
la $a0, prompt_output_element
li $v0, 4
syscall

#Added function

addi $s1, $0, 0
#la $t0, list
addi $t2, $0, 0


output_element:
 
addi $s1, $s1, 1
blt $a1, $s1, fin
#beq $t0, $t3, fin
add $t3, $t0, $t2
lw $a0, 0($t3)
li $v0, 1
syscall



#Printing Space
la $a0, prompt_space #load address of "prompt_input_size" to a0
li $v0, 4 #set v0 as 4 for output string function in syscall
syscall

addi $t2, $t2, 4
j output_element
fin:


# SORT 
#storing_sorted_input

la	$a0, list	#load address of list to a0
la	$t0, size	#load address of size to t0
lw $a1, 0($t0) #copy/load the value of "size" to a1
addi $a1, $a1, -1 #offset in word to last element, a1 - 1
sll  $a1, $a1, 2 #shift logical by 2 bits, a1 *4
add $a1, $a1, $a0 #a1 points to the last element, a1 = a1 + a0


sort:
beq $a0, $a1, done 
jal max  #call the max procedure
lw $t0, 0($a1) #load the last element into t0
sw $t0, 0($v0) #copy the last element to max location
sw $v1, 0($a1) # copy max value to last element
addi $a1, $a1, -4 #decrement pointer to last element
j sort 


max:
addi $v0, $a0, 0 
lw $v1, 0($v0)
addi $t0, $a0, 0 

loop: 
beq $t0, $a1, ret 
addi $t0, $t0, 4 
lw $t1, 0($t0) 
slt $t2, $t1, $v1 
bne $t2, $zero, loop 
addi $v0, $t0, 0
addi $v1, $t1, 0 
j loop 
ret: jr $ra 
 done: 

#printing the prompt of "The sorted element(s) in the array is:\n"
la $a0, prompt_output_sorted #load address of "prompt_output_sorted" to a0
li $v0, 4 #li: load integer, set v0 as 4 for output string function in syscall
syscall

#print the elements in the array
la $t0, size #load the address of "size" to t0
lw $a1, 0($t0) #copy the value of "size" to a1

li $s1, 0 	 #s1 is the index
la $t0, list #loading the address of list in $t0
li $t2, 0	 #t2 is offset 

loop2: #label for output-loop in multiple-elements array
addi $s1, $s1, 1 #increase index s1 by 1
bgt $s1, $a1, end_loop2 #if index s1 > size a1, go to "end_loop2"

#printing the element
add $t3, $t0, $t2 #calculating the address of current element, t3 = t0 + t2
lw $a0, 0($t3) #load the current element from the address of t3 to a0
li $v0, 1 #syscall to print integer
syscall

#printing space
la $a0, prompt_space #load address of "prompt_space" to a0
li $v0, 4 #li: load integer, set v0 as 4 for output string function in syscall
syscall

addi $t2, $t2, 4 #offset to the next space, t2 = t2 + 4 
j loop2
end_loop2:
syscall

	# Finding minimum number
la $a0, list
move $a3, $a0					# store first element of sorted list in $a3

	#Finding maximum number
la $t0, size 					
lw $a1, 0($t0)					

sll $t4, $a1, 2
add $a2, $t4, $a0
addi $a2, $a2, -4

#------------------------------------------------------------------------------------------------#

	#printing the prompt of maximum element 
la $a0, prompt_maximum_element		# load address of "prompt_max_element" string to a0
li $v0,4						# print string function in syscall
syscall

lw $a0, 0($a2)					# load address of current element in $a0
li $v0, 1 						# syscall to print integer
syscall

	#printing the minimum element 
la $a0, prompt_minimum_element		# load address of "prompt_min_element" string to a0
li $v0,4						# print string function in syscall
syscall

lw $a0, 0($a3)					#load address of current element in $a0
li $v0, 1 						#print integer
syscall
#jr	$ra


li $v0, 10 #v0 = 10, exit function
syscall

.data
list: .space 100 #maximum size of list is 25 (100/4), you can change this definition
size: .word 0
dataflag1: .word 0x12345678
charflag1: .ascii "abc"
dataflag4: .word 0x22227890
prompt_input_size: .asciiz "Please enter the size of the list: \n"
prompt_input_element: .asciiz "Please enter the element: \n"
prompt_output_element: .asciiz "The element(s) in the array: \n"
prompt_output_sorted: .asciiz "\nThe sorted element(s) in the array: \n"
prompt_maximum_element: .asciiz  "\nThe Maximum element is: \n"
prompt_minimum_element: .asciiz  "\nThe Minimum element is: \n"
prompt_space: .asciiz "  "
dataflag2: .word 0x88881111
Input: .space 20 #Allocate 20 bytes of storage for the input string
dataflag3: .word 0x99996666