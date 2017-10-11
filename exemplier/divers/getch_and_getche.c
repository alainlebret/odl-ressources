/**
 * @file getch_and_getche.c
 *
 * @brief Provides getch() and getche() functions on Linux
 */

#include <stdio.h>
#include <termios.h>

static struct termios old, new;

/**
 * Initializes new terminal i/o settings
 */
void init_termios(int echo)
{
	tcgetattr(0, &old); /* grab old terminal i/o settings */
	new = old; /* make new settings same as old settings */
	new.c_lflag &= ~ICANON; /* disable buffered i/o */
	new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
	tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

/**
 * Restores old terminal i/o settings
 */
void reset_termios(void)
{
	tcsetattr(0, TCSANOW, &old);
}

/**
 * Reads 1 character - echo defines echo mode
 */
char getch_(int echo) 
{
	char ch;

	init_termios(echo);
	ch = getchar();
	reset_termios();

	return ch;
}

/**
 * Reads 1 character without echo
 */
char getch(void) 
{
	return getch_(0);
}

/**
 * Read 1 character with echo
 */
char getche(void) 
{
	return getch_(1);
}

/* Let's test it out */
int main(void) {
	char c;

	printf("(getche example) please type a letter: ");
	c = getche();
	printf("\nYou typed: %c\n", c);

	printf("(getch example) please type a letter...");
	c = getch();
	printf("\nYou typed: %c\n", c);

	return 0;
}
