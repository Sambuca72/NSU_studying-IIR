asect  0x00

# =================================
# INSERT YOUR CODE BELOW
# Executable instructions only
# No dc or ds pseudo-instructions
# Do not include a halt instruction: that has been done already (below)
# ---------------------------------------------------------------------
	ldi r0,a
	ld r0,r0
	
	
	
	shr r0
	shra r0
	shra r0
	shra r0
	
	if 
	ldi r1, 0b00001010
	cmp r0,r1
	is mi
	ldi r1,48
	add r1,r0
	else
	ldi r1,55
	add r1,r0 
	fi
	ldi r2,res
	st r2,r0
	ldi r0, a
	ld r0,r0
	
	shla r0
	shla r0
	shla r0
	shla r0
	
	tst r0
	shr r0
	shr r0
	shr r0
	shr r0
	
	if 
	ldi r1, 0b00001010
	cmp r0,r1
	is mi
	ldi r1,48
	add r1,r0
	else
	ldi r1,55
	add r1,r0 
	fi
	
	ldi r2,res+1
	st r2,r0


# =================================
# LEAVE THIS PART OF THE FILE ALONE
# Do not change the next two instructions: they must be the last two
# instructions executed by your program.
     # Loads the address of your result into r0 for the robot
    halt         # Brings execution to a halt

# =================================
# DATA GOES BELOW
# We have set this up for you, but you will need to test your program by
# compiling and running it several times with different input data values
# (different bit-strings placed at address a)
# ---------------------------------------------------------------------

INPUTS>
a:    dc  0b01011010   # The output for this bit-string should be "E7"
ENDINPUTS>

res:  ds 2             # Two bytes reserved for the result
end


