//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/danielle/Stuff/Programs/Eternity/includes/eternity_macro.h                                          ***//
//***     Project: /media/danielle/Stuff/Programs/Eternity                                                                 ***//
//***     Header Created: Thu Aug 15 2024                                                                                  ***//
//***     Author: Daniel Haddington [Danielle] at <danielle.sh.md@gmail.com>                                               ***//
//***     Copyright (c) 2024 Daniel Haddington [Danielle]                                                                  ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//

#ifndef  ETERNITY_MACRO_H
# define ETERNITY_MACRO_H

# define MEMORY_ALLOCATION_ERROR 12
# define ENDSET 33

//---------------------------------------------------------
//	DC_GETNEXT_LINE_C
// BUFFER_SIZE is 256 if not already defined elsewhere

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

// OPEN_MAX is a reasonable limit to the number of files which
// can be open at one time.

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif
//---------------------------------------------------------

# define CTRL_q 					('q' & 0x1f)
# define CTRL_DEL					(100)
# define CTRL_i						('i' & 0x1f)


# define DIRECTORY		4
# define REG_FILE		8
# define DIRECTORY_H	1
# define REG_FILE_H		2

# define PANE_SIZE		90
# define BORDER_A		0
# define BORDER_B		32
# define BORDER_C		64
# define BORDER_D		96


#define P_0		  0
#define _A1		  1
#define	_B1		  2
#define	_C1		  3
#define	_D1		  4
#define	_E1		  5
#define	_F1		  6
#define	_G1		  7
#define	_H1		  8
#define	_I1		  9
#define	_J1		 10
#define	_K1		 11
#define	_L1		 12
#define	_M1		 13
#define	_N1		 14
#define	_O1		 15
#define	_P1		 16
#define	A_1		 17
#define	B_1		 18
#define	C_1		 19
#define	D_1		 20
#define	E_1		 21
#define	F_1		 22
#define	G_1		 23
#define	H_1		 24
#define	I_1		 25
#define	J_1		 26
#define	K_1		 27
#define	L_1		 28
#define	M_1		 29
#define	N_1		 30
#define	O_1		 31
#define	P_1		 32

#define P_2		 64
#define P_3		 96


#endif