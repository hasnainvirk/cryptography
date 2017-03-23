/*
 * substitution_cypher.h
 *
 *  Created on: 8 Mar 2017
 *      Author: Alien
 */

#ifndef SUBSTITUTION_CYPHER_H_
#define SUBSTITUTION_CYPHER_H_

/** Letter frequency table for substitution cipher
 *
 * These are relative frequencies for cryptoanalysis for general analytical
 * appearance in English text
 */
#define     A       0.0817
#define     B       0.0150
#define     C       0.0278
#define     D       0.0425
#define     E       0.1270
#define     F       0.0223
#define     G       0.0202
#define     H       0.0609
#define     I       0.0697
#define     J       0.0015
#define     K       0.0077
#define     L       0.0403
#define     M       0.0241
#define     N       0.0675
#define     O       0.0751
#define     P       0.0193
#define     Q       0.0010
#define     R       0.0599
#define     S       0.0633
#define     T       0.0906
#define     U       0.0276
#define     V       0.0098
#define     W       0.0236
#define     X       0.0015
#define     Y       0.0197
#define     Z       0.0007

const double known_relative_frequencies[26] = { A, B, C, D ,E , F ,G, H, I, J, K,
                                              L, M, N, O, P, Q, R, S, T, U, V,
                                              X, Y, Z };


#endif /* SUBSTITUTION_CYPHER_H_ */
