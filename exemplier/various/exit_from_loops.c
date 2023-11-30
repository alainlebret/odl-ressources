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
 * @file quit_loops.c
 * @brief Two ways to break a loop.
 *
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @date 1995-2023
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>

static volatile bool exit_required = false;

void signal_handler(int sig) {
	exit_required = true;
}

void exit_loop_on_signal() {
	for (;;) {
		/*
		 * Placeholder for your code ...
		 */
		if (exit_required) {
			break;
		}
		sleep(1);
	}
}

void exit_loop_after_delay(int delay) {
	time_t end_time = time(NULL) + delay;
	for (;;) {
		/* 
		 * Placeholder for your code ...
		 */
		if (time(NULL) >= end_time) {
			break;
		}
	}
}

int main(void) {
	struct sigaction sa;
	
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = signal_handler;

	if (sigaction(SIGALRM, &sa, NULL) == -1) {
		perror("Error setting signal handler");
		exit(EXIT_FAILURE);
	}
	
	exit_loop_after_delay(6);
	printf("\nExited loop after a delay.\n");
	
	alarm(6);
	exit_loop_on_signal();
	printf("\nExited loop after receiving a signal.\n");

	return 0;
}
