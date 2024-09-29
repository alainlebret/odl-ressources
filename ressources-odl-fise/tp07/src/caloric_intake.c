/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex 
 * 
 * This file is owned by ENSICAEN students. No portion of this 
 * document may be reproduced, copied or revised without written 
 * permission of the authors.
 */

/**
 * @file caloric_intake.c
 * @brief Functions used to compute human caloric intake needs.
 *
 * References
 *
 * [1] D. Dubois and E.F. Dubois. "A formula to estimate the approximate 
 * surface area if height and weight be known". Arch Intern Med., vol. 17, 
 * pp. 863-871, 1916.
 *
 * [2] J.A. Harris and F.G. Benedict. "A Biometric Study of Human Basal 
 * Metabolism". Proceedings of the National Academy of Sciences of the United
 * States of America, vol. 4(12), pp. 370–773, 1918.
 *
 * [3] R.D. Mosteller. "Simplified calculation of body-surface area". N. Engl. 
 * J. Med., vol. 317, pp. 1098, 1987.
 *
 * [4] J.D. Robertson and D.D. Reid. "Standards for the basal metabolism of 
 * normal people in Britain". Lancet, vol. 1, pp. 940-943, 1952.
 *
 */

/**
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @version 1.0.0
 * @date 13 septembre 2017
 */

#include "caloric_intake.h"

int age_coefficient(int age) {
	int alpha = 0;
	
	if (age >= 10 && age <= 14) {
		alpha = 45;
	} else if (age >= 15 && age <= 19) {
		alpha = 40;
	} else if (age >= 20 && age <= 60) {
		alpha = 35;
	} else if (age >= 60) {
		alpha = 40;
	} 
	return alpha;
}

double simplified_body_surface_area(double weight, double height) {
	return sqrt((weight*(height*100))/3600);
}

double body_surface_area(double weight, double height) {
	return (0.2 * pow(height, 0.7) * pow(weight, 0.4));
}

double basal_metabolic_rate(int age, double weight, double height, int gender,
                           int status) {
	float basal_metabolism;
	
	basal_metabolism = 24 * age_coefficient(age) 
		                  * body_surface_area(weight, height);

	if (gender == FEMALE) {
		basal_metabolism = basal_metabolism * 0.9;
		if (status == PREGNANT || status == BREASTFEEDING) {
			basal_metabolism += 600;
		}
	}	
	return basal_metabolism;	
}

double daily_caloric_intake(double bmr, int physical_activity_level) {
	double daily_kilocalories_needed;
		
	switch (physical_activity_level) {
		case LITTLE_TO_NONE : 
			daily_kilocalories_needed  = 1.2 * bmr;
			break;
		case LIGHT :
			daily_kilocalories_needed  = 1.375 * bmr;
			break;
		case MODERATE :
			daily_kilocalories_needed  = 1.55 * bmr;
			break;
		case HEAVY : 
			daily_kilocalories_needed  = 1.725 * bmr;
			break;
		case VERY_HEAVY :
			daily_kilocalories_needed  = 1.9 * bmr;
			break;
		default :
			daily_kilocalories_needed = bmr;
	}
	return daily_kilocalories_needed;
}
	
