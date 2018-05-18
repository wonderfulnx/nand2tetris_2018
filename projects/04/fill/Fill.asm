// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

(CHECK)
	@24576
	D=M
	@WHITE
	D;JEQ
	@BLACK
	D;JNE
	@CHECK
	0;JMP

(WHITE)
	@16384
	D=A
	@i
	A=D
	@i
	M=0
	@i
	D=A
	@8191
	D=D-A
	@CHECK
	D;JGT
	@i
	A=A+1
	@WHITE
	0;JMP
(BLACK)
	@16384
	D=A
	@i
	A=D
	@i
	M=1
	@i
	D=A
	@8191
	D=D-A
	@CHECK
	D;JGT
	@i
	A=A+1
	@WHITE
	0;JMP