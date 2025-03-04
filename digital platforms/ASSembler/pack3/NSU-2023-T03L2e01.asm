	asect	0x00
	# WRITE YOUR CODE HERE
	ldi r0, n
	ld r0, r0
	
	ldi r1, s
	ld r1, r2
	
	while
	tst r0
	stays gt
		if
		tst r2
		is nz
			dec r0
			inc r1
			ld r1, r2
		else
			ldi r2, "?"
			ldi r0, 0
		fi
	wend
	
	ldi r0, res
	st r0, r2



	# at this point 'res' has the answer
	ldi   r0,res
	halt
inputs>
n:	dc	10 		# replace 0 by your choice of n for testing
s:	dc	"priтtf",0 	# replace ... by some text for testing
	ds	18 	# reserve more space in case the string from tester is longer than ours
endinputs>
res:	ds	1
	end
