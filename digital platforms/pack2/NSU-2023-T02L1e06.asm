asect  0x00

# =================================
# INSERT YOUR CODE BELOW
# Executable instructions only
# No dc or ds pseudo-instructions
# Do not include a halt instruction: that has been done already (below)
# ---------------------------------------------------------------------
	ldi r0,x
	ldi r1,y
	ld r0,r0
	ld r1,r1
	move r1,r2
	shla r2
	move r0,r3
	shla r3
	add r0,r3
	neg r3
	if 
	cmp r2,r3
	is lt
	add r0,r1
	move r1,r0
	else 
	ldi r0,z
	ld r0,r0
	sub r1,r0
	fi
	ldi r2,ans
	st r2,r0
		



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
# (different bit-strings placed at addresses x and y)
# ---------------------------------------------------------------------

INPUTS>
x:    dc -6    # replace these numbers by your choice
y:    dc 5     # of integers for testing purposes
z:    dc 3
ENDINPUTS>

ans:  ds 1     # one byte reserved for the result
end

