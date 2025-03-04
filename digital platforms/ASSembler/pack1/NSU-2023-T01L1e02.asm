asect  0x00

# =================================
# INSERT YOUR CODE BELOW
# Executable instructions only
# No dc or ds pseudo-instructions
# Do not include a halt instruction: that has been done already (below)
# ---------------------------------------------------------------------
	ldi r0,a
	ldi r1,b
	ldi r2,d
	ld r0,r0
	ld r1,r1
	ld r2,r2
	sub r2,r0
	sub r0,r1
	ldi r3,res
	st r3,r1



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
a:  dc  121       # replace 0 by your choice of integer for testing
b:  dc  3  
d: dc 7     # replace 0 by your choice of integer for testing
ENDINPUTS>

res:	ds	1		# one byte reserved for the result
	end
