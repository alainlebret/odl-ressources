
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
 * @file caloric_intake.h
 * @brief Prototypes of functions used to compute human caloric intake needs.
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
 */

/**
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @version 1.0.0
 * @date 13 septembre 2017
 */

#ifndef CALORIC_INTAKE_H
#define CALORIC_INTAKE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MALE            1   /*!< Male gender */
#define FEMALE          2   /*!< Female gender */
#define PREGNANT        3   /*!< Pregnancy status for a female */ 
#define BREASTFEEDING   4   /*!< Breast feeding status for a female */
#define NONE           -1   /*!< No pregnancy status */
#define LITTLE_TO_NONE  5   /*!< Little to none exercise per week */
#define LIGHT           6   /*!< 1–3 days of exercise per week */ 
#define MODERATE        7   /*!< 3-5 days of exercise per week */
#define HEAVY           8   /*!< 6–7 days of exercise per week */
#define VERY_HEAVY      9   /*!< Twice per day, extra heavy workouts */

/**
 * @brief Calculates the coefficient used to compute the basal metabolic rate.
 *
 * @param age The age to consider. 
 *
 * @return The age coefficient.
 */
int age_coefficient(int age);

/**
 * @brief Calculates the simplified body surface area for a human.
 *
 * The calculation of the area \f$a\f$ uses the Mosteller formula [3]: 
 * \f$ a = \sqrt{\frac{h \times w}{3600}} \f$
 * where \f$ h \f$ is the height [cm| and \f$ w \f$ is the weight [kg].
 *
 * @param weight The weight in kg.
 * @param height The height in m.
 *
 * @return The body surface area in m<sup>2</sup>.
 */
double simplified_body_surface_area(double weight, double height);

/**
 * @brief Calculates the body surface area for a human.
 *
 * The calculation of the area \f$a\f$ uses the Dubois & Dubois formula [1]:
 * \f$ a = 0.2 \times h^{0.7} \times w^{0.4} \f$
 * where \f$ h \f$ is the height [m] and \f$ w \f$ is the weight [kg].
 *
 * @param weight The weight in kg.
 * @param height The height in m.
 *
 * @return The body surface area in m<sup>2</sup>.
 */
double body_surface_area(double weight, double height);

/**
 * @brief Calculates the basal metabolic rate for a human. 
 *
 * The calculation considers the given \p age, \p weight, \p height, \p gender 
 * and the \p status if a female (pregnant or not). It is based on a simplified 
 * version of the article by Robertson [4].  
 *
 * @param age    The age in years. 
 * @param weight The weight in kg.
 * @param height The height in m.
 * @param gender The gender of the person (\c MALE or \c FEMALE).
 * @param status The pregnancy status (\c PREGNANT or \c NONE for female, 
 *               \c NONE otherwise). 
 *
 * @return The basal metabolic rate in cal/days.
 */
double basal_metabolic_rate(int age, double weight, double height, int gender,
                           int status);

/**
 * @brief Calculates the daily caloric intake needs for a human.
 *
 * The calculation considers the given basal metabolic rate and its physical 
 * activity level. It uses the Harris-Benedict principle for a physical activity 
 * level [2].
 *
 * @param bmr                     The basal metabolic rate. 
 * @param physical_activity_level The level of physical activity. 
 *
 * @return The daily caloric intake needs in cal/day.
 */
double daily_caloric_intake(double bmr, int physical_activity_level);

#endif /* CALORIC_INTAKE_H */
