	asect 	0x00
	# WRITE YOUR CODE HERE

	ldi r0, s
	ld r0, r2
	ldi r3, 0
	
	while
	tst r2
	stays nz
		if
		ldi r1, " "
		cmp r2, r1
		is eq
			ldi r3, 0
			st r0, r3
		else
			inc r3	
		fi
		if
		ldi r1, 1
		cmp r3, r1
		is eq
			ldi r1, res
			ld r1, r2
			while 
			tst r2
			stays nz
			inc r1
			ld r1, r2
			wend
			st r1, r0
		fi
		inc r0
		ld r0, r2
	wend

	# at this point 'res' has the answer
	ldi   r0,res
	halt
res:	ds	9	# pointers to at most 8 words and the null
inputs>
s:	dc	"a f b fd d",0 # replace ... by some text for testing
	ds      57      # reserve more space in case the string from tester is longer than ours
endinputs>
	end
	