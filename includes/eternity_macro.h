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


#define _A		  1
#define	_B		  2
#define	_C		  3
#define	_D		  4
#define	_E		  5
#define	_F		  6
#define	_G		  7
#define	_H		  8
#define	_I		  9
#define	_J		 10
#define	_K		 11
#define	_L		 12
#define	_M		 13
#define	_N		 14
#define	_O		 15
#define	_P		 16
#define	A_		 17
#define	B_		 18
#define	C_		 19
#define	D_		 20
#define	E_		 21
#define	F_		 22
#define	G_		 23
#define	H_		 24
#define	I_		 25
#define	J_		 26
#define	K_		 27
#define	L_		 28
#define	M_		 29
#define	N_		 30
#define	O_		 31
#define	P_		 32


#define P_0		  0
#define P_1		 32
#define P_2		 64
#define P_3		 96


#endif