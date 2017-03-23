/*
 * substitution_cipher.c
 *
 *  Created on: 8 Mar 2017
 *      Author: Alien
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "substitution_cypher.h"
#include "ciphertext1_1.h"

//ACII 'Z' = 122, for example character = 'a' = 97, i.e., 97-122+25 = 0 which
//is the required index
#define    GET_INDEX(character)    (character-122+25)

// ASCII 'a' = 97. 'a' + 0 = 'a' etc
#define    GET_CHAR(index)         (97+index)

#define    MIN(X, Y)               (((X) < (Y)) ? (X) : (Y))
#define    MAX(X, Y)               (((X) > (Y)) ? (X) : (Y))

/**
 * Array to hold computed relative frequencies of the letters appearing in
 * cipher text.
 */
static double rel_freq_ciphertext[26];


typedef struct {
    char coded;
    char matching;
    struct matching_list *next;
} matching_list;

static matching_list list;

static void add_to_list()
{

}


/** Function to compute relative frequency in cipher text
 *
 * @param ciphertext    pointer to the cipher text
 */
static void compute_relative_frequency_in_ciphertext()
{
    uint8_t *ptr = (uint8_t *) ciphertext;
    size_t total_length_of_ciphertext = strlen(ciphertext);

    printf("Computing relative frequencies, cipher text length = %i  ...\n",
            total_length_of_ciphertext);

    while (*ptr)
    {
        if (isspace(*ptr)) {
            ptr++;
            continue;
        }
        rel_freq_ciphertext[GET_INDEX(*ptr++)] += 1;
    }

    double min;
    double euclidean_distances[26];
    int idx = 0;
    min = 100;
    char decoded_text[total_length_of_ciphertext];

    memset(decoded_text, 0 , strlen(decoded_text));

    for (int i = 0; i < 26; i++) {

        idx = 0;
        memset(euclidean_distances, 0, 26);

       rel_freq_ciphertext[i] = (rel_freq_ciphertext[i]
                                              /total_length_of_ciphertext);

       printf("Relative Frequency of \'%c\', freq = %f\n", GET_CHAR(i),
                  rel_freq_ciphertext[i]);

       /*Loop over relative frequencies and calculate their euclidean distances
        * with the known letter frequencies*/
       for (int j = 0; j < 26; j++) {
           euclidean_distances[j] = (rel_freq_ciphertext[i]
                                    -known_relative_frequencies[j]);
           if (euclidean_distances[j] < 0) {
               /* In order to normalize the value, i.e., to get the absolute
                * value we need to multiply with -1 if the values are -ve */
               euclidean_distances[j] = -1*(euclidean_distances[j]);
           }

           /* check and mark the smallest euclidean distance */
           /* remember the index of the smallest relative frequecy */
//           if (min < euclidean_distances[j]) {
//               idx = j;
//           }
//           min = MIN(min, euclidean_distances[j]);

       }

       for (int j = 1; j < 26; j++) {
           if (euclidean_distances[j] < euclidean_distances[idx]) {
               idx = j;
           }
       }

       printf("Minimum Euclidean Distance = %f, index = %d \n", euclidean_distances[idx], idx);
       printf("Coded character ='%c', Matched Character is = '%c'\n",
                                                               GET_CHAR(i),
                                                               GET_CHAR(idx));

       list.

        ptr = NULL;
        ptr = (uint8_t *) ciphertext;
        int cur = 0;
        while (*ptr)
        {
            if (isspace(*ptr))
            {
                ptr++;
                cur++;
                continue;
            }

            if (*ptr == GET_CHAR(i)) {
                decoded_text[cur] = GET_CHAR(idx);
            }

            ptr++;
            cur++;
        }

        idx = 0;
    }

    printf("######### Decoded Text ###########\n\n");
    printf("%s", decoded_text);
}



int main()
{
    printf("App ready.");
    compute_relative_frequency_in_ciphertext();

}
