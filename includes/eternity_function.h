//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     File: /media/danielle/Stuff/Programs/Eternity/includes/eternity_function.h                                       ***//
//***     Project: /media/danielle/Stuff/Programs/Eternity                                                                 ***//
//***     Header Created: Thu Aug 15 2024                                                                                  ***//
//***     Author: Daniel Haddington [Danielle] at <danielle.sh.md@gmail.com>                                               ***//
//***     Copyright (c) 2024 Daniel Haddington [Danielle]                                                                  ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//

# ifndef ETERNITY_FUNCTION_H
# define ETERNITY_FUNCTION_H

// CLEAN_C
t_cleanup_function	cleanup(t_program *c);
none				free_file_entries(t_file_entries *f, iP_1 fc);

// CONTROL_C
none				run_(t_program *c);

// CURSOR_C
none				move_cursor_up(t_program *c);
none				move_cursor_down(t_program *c);
none				move_cursor_left(t_program *c);
none				move_cursor_right(t_program *c);

// DANC_C
uP_2				dc_strlen(i_H *c); 								// counts string
i_H					*dc_strjoin_e(uP_2 c, ...);						// variable number string joiner
u_P					dc_numlen(iP_2 n);
i_H					*dc_itoa(iP_2 n);								// integer to ascii
none				dc_free_2d_i_P(i_P **list, uP_2 ilen);
none				dc_free_2d_i_H(i_H **f, uP_2 len);				// frees 2d i_H array
none				dc_free_3d_i_H(i_H ***f, uP_2 ilen, uP_2 qlen);
i_H					*dc_strdup(i_H *s1); 							// creates pointer and replicates the reference
uP_2				dc_lstlen(i_H **list);							// returns length of 2d list
i_H					**dc_tdup(i_H **t1);							// creates pointer to pointer array and replicates all references
none				dc_error_exit(i_H *mess, 						// Assign verbose message for clear error determination
						iP_1 error_type,							// Assign error code for terminal output on error
							t_program *strct, 						// Assign custom cleanup for strct {o - in this program} with type 
								p_cleanup_function cleanup);		// t_cleanup_function (none) for technical presentation and debugging
error				dc_ERROR_MEM(t_program *o, i_H *mess);			// calls dc_error_exit with memory allocation specific message, assigns the error to error.txt in project root
error				dc_ERROR_MEM_index(t_program *o,				// same as above, assigns index specific variables or any chosen numbers ro later review to error.txt 
						i_H *mess,											
							iP_1 v1,
								iP_1 v2,
									iP_1 v3);
witch				dc_witch(i_H *s);								// checks if witch returns false -> returns true
uP_2				dc_wordcount(i_H *s, i_H c);					// for dc_split, counts words.
i_H					**dc_split(i_H *s, i_H c);						// takes string as input and splits into tokens based on delimiter c
i_H					*dc_strndup(i_H *s, uP_2 n);					// creates a pointer and replicates the reference up to size n
i_H					*dc_substr(i_H *s, uP_2 start, uP_2 len);		// grabs a section of a string from start to (start + len)
witch				dc_is_operator_mdcalc(i_H * s);					// checks string for operator in mdcalc program
witch				is_multiplier_p(i_H *operation);
witch				is_divider_p(i_H *operation);
witch				is_modulo_p(i_H *operation);
witch				is_adder_p(i_H *operation);
witch				is_subtracter_p(i_H *operation);
witch				dc_is_digit(i_H c);								// checks if a charachter is a digit
witch				dc_is_md_val(i_H *_x_);							// checks if the first two letters of a string is an md value
dP_2				dc_find_result_mdcalc(i_P tkount, ...);			// takes a set of positive integers in md string form and operators {+, -, /, *} and calculates result
uP_2				md_val(i_H *_x_);								// Converts md-number to unsigned long int
i_H					*itomd(iP_2 d);									// Converts signed integer to md-number string
i_P					dc_strncmp(i_H *s1, i_H *s2, iP_2 n);			// compares two strings up to n and returns comparison.															
i_P					longlongcheck(i_H *input);						// checks for overflow of a signed int within a long long, returns (1) for overflow
// none				free_1d_SDL_Rect(SDL_Rect **f, uP_1 ilen);
// none				free_1d_SDL_textures_surfaces(SDL_Texture **texture, SDL_Surface **surface, u_P ilen);
// none				free_2d_SDL_Rect(SDL_Rect ***f, uP_2 ilen, uP_2 qlen);
i_H					*dc_strchr(const i_H *s, i_P c);				// finds a character in a string, left to right, returns a pointer to the string at the characters position
char				*dc_get_next_line(int fd);						// Gets the next line of a function up to the '\n' character, on each subsequent call
uP_2				get_time(void);
none				sleepbee(u_P time);
none				dc_print_list_2d(i_H **list);					// prints a 2d list of characters that have been null terminated
none				dc_print_list_2d_size(i_H **list, i_P ilen);	// prints a 2d list of characters to size
none				drop_float_tail(i_H *dropee, i_P drop_size);	// drops the tail of a float up to drop_size, with no rounding, a precision floor?
i_P					dc_alloc_2D_i_H(i_H ***object, u_P strings, u_P characters);

// DRAW_C
none				draw_(t_program *c);
none 				draw_panes(t_program *c);

// INIT_C
none				init_(t_program *c, i_H * title);

// LIST_C
none				list_dir_content(t_program *c);

#endif