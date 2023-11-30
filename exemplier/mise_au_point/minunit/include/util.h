#ifndef UTIL_H
#define UTIL_H

#define STR_SIZE 50

typedef struct character_s character_t;

/**
 * A character within the game. Bla bla bla.
 */
struct character_s {
	char name[STR_SIZE]; /*!< The name of the character within the game */ 
	int health;      /*!< The health of the character at the beginning of the game */ 
};

/** 
 * Returns a void pointer according to the given value. 
 */
void *f1(int n);

#endif
