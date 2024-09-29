/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 * 
 * This file is owned by ENSICAEN.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

/**
 * @author Daniel Carré <Daniel.Carre@greyc.ensicaen.fr>
 * @version 1.3.0 1997/10/15
 */

/**
 * @file fahrenheit2celsius.c
 * 
 * Converts any fahrenheit degree to celcius degree.
 * The correspondence table: begins at O degF, ( = start )
 *					  steps by 10 degF  ( = graduation)
 *					  ends at 100 degF  ( = fin )
 * Excerpt of execution
 *  0.0 F  =  -17.8 C
 * 30.0 F  =   -1.1 C
 * 50.0 F  =   10.0 C
 * 100.0 F =   37.8 C
             */

#include <stdio.h>

/**
 * Converts Fahrenheit degrees to Celsius degrees.  * @param	faren a positive or null integer.  * @return the celcius degree.  */ float to_celsius (float faren) { return (5.0/9)*(faren-32);}

/** Displays the correspondence table. */ int main() { 	float begin=0, end=100; /* First and last Farenheit temperature */ 	float step=10;    /* Offset between two degree */ float temp; printf("Correspondence table between Fahrenheit and Celsius degrees.");  for(temp=begin;temp<=end;) { printf("\t%6.1f F = %6.1f C\n", temp,To_Celsius(temp)); temp+=offset; } return 0; }