asect  0x00

# =================================
# INSERT YOUR CODE BELOW
# Executable instructions only
# No dc or ds pseudo-instructions
# Do not include a halt instruction: that has been done already (below)
# ---------------------------------------------------------------------
	ldi r0,a
	ldi r1,b
	ld r0,r0
	ld r1,r1

	if 
	cmp r0,r1
	is lt
	ldi r2,x
	ld r2,r2
	fi
	
	if 
	cmp r0,r1
	is eq
	ldi r2,y
	ld r2,r2
	fi
	
	if 
	cmp r0,r1
	is gt
	ldi r2,z
	ld r2,r2
	fi
	
	ldi r0,ans
	st r0,r2
	
	


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
# (different integers placed at addresses a, b, x, y and z)
# ---------------------------------------------------------------------

INPUTS>
a:    dc 5   # replace these five numbers
b:    dc 5     # by your choice of integers
x:    dc 5     # for testing purposes
y:    dc 3
z:    dc 7
ENDINPUTS>

ans:  ds 1     # one byte reserved for the result
end

