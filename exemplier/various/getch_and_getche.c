/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * Examples from the course "Software development tools"
 * Exemplier du cours "Outils de développement logiciel" (ODL)
 *
 *
 * Copyright (C) 1995-2023 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @file getch_and_getche.c
 *
 * @brief Provides getch() and getche() functions on Linux
 *
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @date 1995-2023
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

static struct termios old, new;

/**
 * Initializes new terminal i/o settings
 */
void init_termios(int echo, struct termios *old, struct termios *new) {
	if (tcgetattr(STDIN_FILENO, old) != 0) { /* grab old terminal i/o settings */
		perror("init_termios - tcgetattr");
		exit(EXIT_FAILURE);
	}
	*new = *old; /* make new settings same as old settings */
	new->c_lflag &= ~ICANON; /* disable buffered i/o */
	new->c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
	if (tcsetattr(STDIN_FILENO, TCSANOW, new) != 0) { /* use these new terminal i/o settings now */
		perror("init_termios - tcsetattr");
		exit(EXIT_FAILURE);
	}
}

/**
 * Restores old terminal i/o settings
 */
void reset_termios(const struct termios *old) {
	if (tcsetattr(STDIN_FILENO, TCSANOW, old) != 0) {
		perror("reset_termios - tcsetattr");
		exit(EXIT_FAILURE);
	}
}

/**
 * Reads 1 character - echo defines echo mode
 */
char read_char(int echo) {
	struct termios old, new;
	char ch;

	init_termios(echo, &old, &new);
	ch = getchar();
	reset_termios(&old);

	return ch;
}

/**
 * Reads 1 character without echo.
 */
char getch(void) {
	return read_char(0);
}

/**
 * Reads 1 character with echo.
 */
char getche(void) {
	return read_char(1);
}

int main(void) {
	char c;

	printf("(getche example) please type a letter: ");
	c = getche();
	printf("\nYou typed: %c\n", c);

	printf("(getch example) please type a letter: ");
	c = getch();
	printf("\nYou typed: %c\n", c);

	return 0;
}
