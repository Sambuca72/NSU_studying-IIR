	asect	0x00
	# WRITE YOUR CODE HERE

	ldi r0, S
	ld r0, r1
	
	
	if
	ldi r2, "{"
	cmp r1, r2
	is ne
		jsr off
	fi
	
	inc r0
	ld r0, r1
	
	while
	ldi r2, "}"
	cmp r1, r2
	stays ne
		#проверка на 0
		if
		tst r1
		is z
			jsr off
		fi
		
		#сли символ меньше
		if
		ldi r2, 96
		cmp r1, r2
		is ls
			jsr off
		fi
		
		#если символ больше
		if
		ldi r2, 122
		cmp r1, r2
		is hi
			jsr off
		fi
		
		#сравнение с 'a'
		ldi r2, -97
		add r2, r1
		ldi r3, 0
		while
		ldi r2, 7 
		cmp r1, r2
		stays hi
		ldi r2, -8
		add r2, r1
		inc r3
		wend
		
		ldi r2, 7
		sub r2, r1
		
		ldi r2, 0b00000001
		while
		tst r1
		stays nz
		shla r2
		dec r1
		wend
		
		if
		ldi r1, result
		add r3, r1
		ld r1, r3
		and r2, r3
		tst r3
		is z
			ld r1, r3
			add r2, r3
			st r1, r3
		else
			jsr off
		fi
		
		
		inc r0
		ld r0, r1
		
		#если нет запятой и нет закрывающей скобки
		if
		ldi r2, "}"
		cmp r1, r2
		is ne, and
		ldi r2, ","
		cmp r1, r2
		is ne
			jsr off
		fi
		
		if
		ldi r2, "}"
		cmp r1, r2
		is eq
		else
			inc r0
			ld r0, r1
		fi
	wend
	
	inc r0
	ld r0, r1
	if
	tst r1
	is nz
		jsr off
	fi

    # at this point 'result' has the answer
    ldi r0, result
    halt
off:
		ldi r0, result
		ldi r1, 0
		st r0, r1
		inc r0
		st r0, r1
		inc r0
		st r0, r1
		inc r0
		ldi r1, "?"
		st r0, r1
		ldi r0, result
        halt
inputs>
S:	dc	"{a,g,h,i,jk,l,q,r,s,t,u,v,w,x,y,z}",0 	# replace by your choice of S for testing
endinputs>
result: ds	4
        end
