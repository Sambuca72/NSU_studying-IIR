asect  0x00

# =================================
# INSERT YOUR CODE BELOW
# Executable instructions only
# No dc or ds pseudo-instructions
# Do not include a halt instruction: that has been done already (below)
# ---------------------------------------------------------------------
	ldi r0, 0
	ldi r1, n
	ld r1, r1
	while 
	cmp r1,r0
	stays gt
	add r1, r0
	if
	is cs
		ldi r0, 255
		ldi r1, res
		st r1, r0
		ldi r0, 1
		ldi r1, oflow
		st r1, r0
		ldi r0, res
    	halt
	fi
	dec r1
	wend
	ldi r1, res
	st r1, r0
	ldi r0, -1
	ldi r1, oflow
	st r1,r0
	



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
# (different unsigned numbers placed at address n)
# ---------------------------------------------------------------------

INPUTS>
n:     dc 100    # replace this with your choice of unsigned number for testing
ENDINPUTS>

res:   ds 1    # one byte reserved for the (unsigned number) total
oflow: ds 1    # one byte to indicate whether or not an overflow has occurred
end

