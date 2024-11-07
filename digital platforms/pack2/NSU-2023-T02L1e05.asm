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
	move r0,r3
	ldi r2, 5
	add r2,r3
	clr r2
	if  
	cmp r1, r3
	is le 
	clr r3
	move r0,r3
	shla r0
	add r3,r0
	clr r1
	move r0,r1
	
	else 
	clr r3
	clr r0
	ldi r3,7
	ldi r0,z
	ld r0,r0
	add r0,r3
	shla r1
	sub r3,r1
	
	fi
	ldi r2,ans
	st r2, r1
	



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
# (different bit-strings placed at addresses x, y and z)
# ---------------------------------------------------------------------

INPUTS>
x:    dc 5    # replace these three numbers
y:    dc 5     # by your choice of integers
z:    dc 3     #  for testing purposes
ENDINPUTS>

ans:  ds 1     # one byte reserved for the result
end

