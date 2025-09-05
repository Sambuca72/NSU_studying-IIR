	asect 	0x00
	# WRITE YOUR CODE HERE
	ldi r0, s
	ld r0, r1
	
	while 
	tst r1
	stays nz
		ldi r2, 96
		ldi r3, 122
		if
		cmp r1, r2
		is hi, and
		cmp r1, r3
		is ls
		ldi r2, 32
		sub r1, r2
		st r0, r2
		fi
		inc r0
		ld r0, r1
	wend





	# at this point 'res' has the answer
	ldi   r0,res
	halt
inputs>
res:
s:	dc	"printf",0 	# replace ... by some text for testing
	ds      17      # reserve more space in case the string from tester is longer than ours
endinputs>
	end
