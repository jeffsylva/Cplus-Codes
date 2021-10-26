#This sample program is to let user input one element in the array (list)
#and store the list in the memory

# COPYRIGHT H. LI

.text
main:
	#print "Please enter the size of the list:"
la $a0, prompt_input_size 		# load address of "prompt_input_size" string to a0
li $v0, 4						# print string function in syscall	
syscall

li $v0, 5 						#input the size, syscall  of v0 = 5
syscall

	#copy the size from v0 to the variable "size"
la $t0, size 					# load address of "size" in t0
sw $v0 , 0($t0) 				# store v0(size) to address of t0
move $a1, $v0					# copy "size" to a1(number of element to be input)

	#input the elements of the list 
li $s1, 0						# initialize s1(index) to 0
la $t0, list 					# load address of list into t0
li $t2, 0 						# initialize "offset(t2)" to 0

#printing the prompt of input element 
la $a0, prompt_input_element	# load address of "prompt_input_element" string to a0
li $v0,4						# print string function in syscall
syscall

#################################
input_loop:

addi $s1, $s1, 1 				# increase index by 1
bgt $s1, $a1, end_input_loop 	# if index(s1) > size(a1) then end the input loop

	

li $v0, 5						# taking the input
syscall 


add $t3, $t0, $t2 				# calculating address to store the next input
sw $v0, 0($t3)					# store input(v0) in memory address $t3
addi $t2, $t2, 4				# add 4 to "offset(t2)" to adjust to next element space

j input_loop

end_input_loop:
#################################

	#print the elements of the list 
la $t0, size 					# load address of "size" in $t0
lw $a1, 0($t0)					# load value "size" into a1

li $s1, 0 						# "index(s1)" is initialize to 0
la $t0, list 					# load address of list into t0
li $t2, 0 						# initialize "offset(t2)" to 0


	#printing the prompt of output element 
la $a0, prompt_output_element	# load address of "prompt_output_element" string to a0
li $v0,4						# print string function in syscall
syscall

#################################
output_loop:

addi $s1, $s1, 1 				# increase index by 1
bgt $s1 $a1, end_output_loop 	# if index(s1) > size(a1) then end_output_loop


	#printing the elements 
add $t3, $t0, $t2				# calculating address of current element 
lw $a0, 0($t3)					# load address of current element in $a0
li $v0, 1 						# syscall to print integer
syscall

	#printing space
la $a0, prompt_space 			# load address of "prompt_space" string to a0
li $v0, 4						# print strng for v0=4
syscall

addi $t2, $t2, 4				# offset to next spac, t2+=4

j output_loop

end_output_loop: 

#########################################

la $a0, list 					# load pointer to list
la $t0, size 					# load address of "size" in $t0
lw $a1, 0($t0)					# load word "size" into a1
addi $a1, $a1, -1				# offset in word to last element 
sll $a1, $a1, 2					# shift left logical by 2 bits
add $a1, $a0, $a1				# a1 is pointer to last element

#################################
	#sorting the list of elements
sort: 
beq $a0,$a1,end_sort			# single-element list is sorted
jal max							# call the max procedure
lw $t0,0($a1)					# load last element into $t0
sw $t0,0($v0) 					# copy the last element to max loc v0
sw $v1,0($a1) 					# copy max value to last element
addi $a1,$a1,-4					# decrement pointer to last element
j sort 							# repeat sort for smaller list

max:
addi $v0, $a0, 0				# max pointer to the first element
lw $v1,0($v0)					# initialize maximum to A[0] 
addi $t0, $a0, 0				# next pointer to first element
loop: 
beq $t0,$a1,ret 				# single element is returned as the max
addi $t0, $t0, 4				# adjust t0 to next element
lw $t1, 0($t0)					# load next element to t1
slt	 $t2, $t1, $v1				# compare (next element) < (max value)
bne $t2, $zero, loop 			# if (next element) < (max value), continue to next element 
addi $v0, $t0, 0				# move value to next element
addi $v1, $t1, 0				# continue compare the next element in list 

j loop 							# change completed and  now repeat
ret: jr $ra
end_sort:

	# Finding minimum number
la $a0, list
move $a3, $a0					# store first element of sorted list in $a3

	#Finding maximum number
la $t0, size 					# load address of "size" in $t0
lw $a1, 0($t0)					# load word "size" into a1

sll $t4, $a1, 2
add $a2, $t4, $a0
addi $a2, $a2, -4

########################################

	#printing the prompt of max element 
la $a0, prompt_max_element		# load address of "prompt_max_element" string to a0
li $v0,4						# print string function in syscall
syscall

lw $a0, 0($a2)					# load address of current element in $a0
li $v0, 1 						# syscall to print integer
syscall

##########################################

	#printing the prompt of min element 
la $a0, prompt_min_element		# load address of "prompt_min_element" string to a0
li $v0,4						# print string function in syscall
syscall

lw $a0, 0($a3)					# load address of current element in $a0
li $v0, 1 						# syscall to print integer
syscall
######################################

li $v0, 10	 #v0=10, exit function
syscall

.data
list: .space 100 #maximum size of list is 25, you can change this defenition
size: .word 0
dataflag1: .word 0x12345678
charflag1: .ascii "abc"
dataflag4: .word 0x22227890
prompt_input_size: .asciiz "Please enter the size of the list: \n"
prompt_input_element: .asciiz "Please input the elements of the list: \n"
prompt_space: .asciiz " "
prompt_output_element: .asciiz "The element(s) in the list  "
prompt_max_element: .asciiz  "\nThe Max is "
prompt_min_element: .asciiz  "\nThe Min is "
prompt_sort_element: .asciiz "\nThe element(s) in the array after a sort: \n"
dataflag2: .word 0x88881111
Input: .space 20 #Allocate 20 bytes of storage for the input string
dataflag3: .word 0x99996666
