asect  0x00

# =================================
# INSERT YOUR CODE BELOW
# Executable instructions only
# No dc or ds pseudo-instructions
# Do not include a halt instruction: that has been done already (below)
# ---------------------------------------------------------------------
	ldi r0,x
	ld r0,r0
	
	ldi r1,y
	ld r1,r1
	
	ldi r3,0
	
	
	while 
	cmp r0,r1
	stays ge
	move r1,r2
	sub r0,r2
	move r2,r0	
	inc r3
	wend
	
	ldi r1,quot
	st r1,r3
	ldi r1,remain
	st r1,r0
	


# =================================
# LEAVE THIS PART OF THE FILE ALONE
# Do not change the next two instructions: they must be the last two
# instructions executed by your program.
    ldi r0, quot  # Loads the address of your result into r0 for the robot
    halt          # Brings execution to a halt

# =================================
# DATA GOES BELOW
# We have set this up for you, but you will need to test your program by
# compiling and running it several times with different input data values
# (different unsigned numbers placed at addresses x and y)
# ---------------------------------------------------------------------

INPUTS>
x:      dc 10   # replace these with your choice
y:      dc 5    # of unsigned numbers for testing
ENDINPUTS>

quot:   ds 1    # one byte reserved for the quotient
remain: ds 1    # one byte reserved for the remainder
end

