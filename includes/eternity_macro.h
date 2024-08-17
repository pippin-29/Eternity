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


#define STARTSET  0
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
#define NL		 33

#define _0_		"STARTSET"
#define _1_		"_A"
#define	_2_		"_B"
#define	_3_		"_C"
#define	_4_		"_D"
#define	_5_		"_E"
#define	_6_		"_F"
#define	_7_		"_G"
#define	_8_		"_H"
#define	_9_		"_I"
#define	_10_	"_J"
#define	_11_	"_K"
#define	_12_	"_L"
#define	_13_	"_M"
#define	_14_	"_N"
#define	_15_	"_O"
#define	_16_	"_P"
#define	_17_	"A_"
#define	_18_	"B_"
#define	_19_	"C_"
#define	_20_	"D_"
#define	_21_	"E_"
#define	_22_	"F_"
#define	_23_	"G_"
#define	_24_	"H_"
#define	_25_	"I_"
#define	_26_	"J_"
#define	_27_	"K_"
#define	_28_	"L_"
#define	_29_	"M_"
#define	_30_	"N_"
#define	_31_	"O_"
#define	_32_	"P_"
#define _33_	"NL"

#endif