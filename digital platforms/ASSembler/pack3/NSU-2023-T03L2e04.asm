	asect 	0x00
	# WRITE YOUR CODE HERE
	ldi r0,array
	ldi r2,8
	ldi r3,res
	while 
	tst r2
	stays nz
	ld r0,r1
	if
	tst r1
	is lt
	st r3,r1
	inc r3
	fi
	inc r0
	dec r2
	wend
	
	ldi r0,array
	ldi r2,8
	
	while
	tst r2
	stays nz
	ld r0,r1
	if
	tst r1
	is lt
	else
	st r3,r1
	inc r3
	fi
	inc r0
	dec r2
	wend 

	# at this point 'res' has the answer
	ldi   r0,res
	halt
inputs>
array:	dc	 -5,-1,-3,7,4,2,2,-8 # choose some numbers for testing
endinputs>
res:	ds	8
	end
