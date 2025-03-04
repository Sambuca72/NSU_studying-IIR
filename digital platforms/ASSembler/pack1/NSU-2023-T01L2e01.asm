asect  0x00

# =================================
# INSERT YOUR CODE BELOW
# Executable instructions only
# No dc or ds pseudo-instructions
# Do not include a halt instruction: that has been done already (below)
# ---------------------------------------------------------------------
	ldi r0, a
	ldi r1, b
	ldi r3,c
	ld r3,r3
	ld r0, r0
	ld r1, r1
		
	add r0, r2
	add r0, r2 
	add r0,r2
	clr r0
	add r2, r0
	add r2, r0
	add r2,r0
	
	
	shla r1
	shla r1
	
	sub r0, r1
	add r1,r3
	
	st r0,r3

# =================================
# LEAVE THIS PART OF THE FILE ALONE
# Do not change the next two instructions: they must be the last two
# instructions executed by your program.
    ldi r0, res  # Loads the address of your result into r0 for the robot
    halt         # Brings execution to a halt

# =================================
# DATA GOES BELOW
# We have set this up for you, but you will need to test your program by
# compiling and running it several times with different input data values
# (different bit-strings placed at addresses a and b)
# ---------------------------------------------------------------------

INPUTS>
a:  dc 	1       # replace 0 by your choice of integer for testing
b:  dc  4       # replace 0 by your choice of integer for testing
c: dc 12
d: dc 9
ENDINPUTS>

res:	ds	1		# one byte reserved for the result
end

