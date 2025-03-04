asect  0x00

# =================================
# INSERT YOUR CODE BELOW
# Executable instructions only
# No dc or ds pseudo-instructions
# Do not include a halt instruction: that has been done already (below)
# ---------------------------------------------------------------------
	ldi r0,x
	ld r0,r0
	
	ldi r3, 0b10000000
	
	move r0,r1
	move r0,r2
	
	if #первое условие b4=b6
	shr r3
	and r3,r1
	shr r3
	shr r3
	and r3,r2
	shl r2
	shl r2
	cmp r2,r1
	is nz
	ldi r2,ans
	st r2, r0
	halt
	fi
	
	if #второе условие
	move r0,r1
	shr r3
	shr r3
	shr r2
	shr r2
	and r3,r1
	shl r1
	shl r1
	cmp r2, r1
	is eq
	ldi r2,ans 
	st r2,r0
	halt
	fi
	
	ldi r3, 0b00100010
	xor r0,r3
	ldi r2,ans
	st r2,r3
	
	



# =================================
# LEAVE THIS PART OF THE FILE ALONE
# Do not change the next two instructions: they must be the last two
# instructions executed by your program.
    ldi r0, ans  # Loads the address of your result into r0 for the robot
    halt         # Brings execution to a halt

# =================================
# DATA GOES BELOW
# We have set this up for you, but you will need to test your program by
# compiling and running it several times with different input data values
# (different bit-strings placed at addresses a, x, y and z)
# ---------------------------------------------------------------------

INPUTS>
x:    dc 0b01111001
#01001011
#01101011
#011010
ENDINPUTS>

ans:  ds 1     # one byte reserved for the result
end

