/*
  @file layover.c
  @brief Implements flight structure and methods
*/
#include <stdlib.h>
#include "flight.h"

static const int AMOUNT_OF_FLIGHT_VARS = 3;

Flight flight_from_file(FILE* file)
{
    Flight flight;
    int scan= fscanf(file, EXPECTED_FLIGHT_FILE_FORMAT,flight.hour,flight.delay,flight.passengers_amount){
      if(scanf != AMOUNT_OF_FLIGHT_VARS){
        fprintf(stderr,"Invalid data \n");
        exit(EXIT_FAILURE);
      }
    }

    return flight;
}
