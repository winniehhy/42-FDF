/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:45:18 by hheng             #+#    #+#             */
/*   Updated: 2024/07/22 13:45:18 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define W_WIDTH 1800

// W_HEIGHT: defines the height of the window display
#define W_HEIGHT 1000

// HEX_BASE: defines an uppercase hexadecimal base
#define HEX_BASE "0123456789ABCDEF"

// TRANS: defines the size of a single translation adjustment.
#define TRANS 1.5

// @def ROT: defines the size of a single rotation adjustment.
#define ROT 0.01

//ZOOM: defines the scale factor for a single zoom adjustment.
#define ZOOM 0.1

// FF: defines the flattening factor for a single altitude adjustments.
#define FF  0.01

// SF :defines the scaling factor for the z-coordinate in 3D transformations.
#define SF  10

// ESC_KEY:  represents the ESCAPE key for this OS
#define ESC_KEY 65307

// represents the 'W' key for this OS
#define W_KEY  119

//represents the 'A' key for this OS
#define A_KEY  97

// represents the 'S' key for this OS
#define S_KEY  115

// represents the 'D' key for this OS
#define D_KEY  100

// represents the 'C' key for this OS
#define C_KEY  99

// represents the 'R' key for this OS
#define R_KEY  114

// represents the TAB key for this OS
#define TAB_KEY 65289

// represents the '+' key for this OS
#define PS_KEY  61

// represents the '-' key for this OS
#define MS_KEY  45

// represents the UP ARROW key for this OS
#define UP_KEY  65362

// represents the DOWN ARROW key for this OS
#define DW_KEY  65364

// represents the '1' key for this OS
#define KEY_1  49

// represents the '2' key for this OS
#define KEY_2  50

// represents the '3' key for this OS
#define KEY_3  51

// represents the '4' key for this OS
#define KEY_4  52

// represents the '5' key for this OS
#define KEY_5  53

// represents the '6' key for this OS
#define KEY_6  54

/*The number of bits to shift to the right to 
isolate the red component of a color.*/
#define RS 16

/* The number of bits to shift to the right to isolate 
the green component of a color. */
#define GS 8

// The bitmask to apply to isolate the blue component of a color.
#define BM 0xFF

/*
The number of bits to shift to isolate the alpha component 
in a 32-bit color value.

//This macro represents the number of bits to shift a 32-bit color
 value to the right to isolate the alpha component.

//The color value is assumed to be in the format 0xRRGGBBAA, 
where RR represents the red component, GG the green component,
BB the blue component, and AA the alpha component.
*/
#define AS 24

// This macro represents the RGB color WHITE
#define WHITE 0xFFFFFF

// This macro represents the RGB color CYAN
#define CYAN 0x07C1FF

// This macro represents the RGB color NEON PINK
#define N_PINK 0xFF007F

// This macro represents the RGB color NEON GREEN
#define N_GREEN 0x39FF14

// This macro represents the RGB color NEON BLUE
#define N_BLUE 0x1B03A3

// This macro represents the RGB color NEON YELLOW
#define N_YELLOW 0xFFFF33

// This macro represents the RGB color NEON ORANGE
#define N_ORANGE 0xFF6600

// This macro represents the RGB color NEON PURPLE
#define N_PURPLE 0xB026FF
