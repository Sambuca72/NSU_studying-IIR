	asect 	0x00
	# WRITE YOUR CODE HERE
	
	ldi r0,0
	while 
		ldi r1,8
		cmp r1,r0
	stays ne
		ldi r1,x
		add r0,r1
		ld r1,r2
		addc r3,r2
		
		ldi r1,y
		add r0,r1
		ld r1,r3
		
		
		add r2,r3
		move r2,r1
		ldi r2,sum
		add r0,r2
		st r2,r3
		
		ldi r3,127
		neg r1
		add r1,r3
		ldi r1,x
		ld r1,r1
		if 
			cmp r1,r3
		is gt
			clr r3
			ldi r3,1
		else 
			clr r3
		fi
		inc r0
	wend
		
	
	


	# at this point 'res' has the answer
	ldi   r0,sum
	halt


	

inputs>
x:	dc	0x07,0xab,0x07,0xab,0x07,0xab,0x07,0xab # choose your data
y:	dc	0x07,0xab,0x07,0xab,0x07,0xab,0x07,0xab # choose your data
c:  dc  8
endinputs>
sum:	ds	8
	end
