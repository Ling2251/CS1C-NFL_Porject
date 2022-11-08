#include "NFL_input.h"

# include "sortfunction.h"

void sortfunction (NFLInput inputarray[], int arraysize) {

int i, j;

NFLInput temp;

for(i = 0; i<arraysize; i++) {


  for(j = i+1; j<arraysize; j++)

  {

      if(inputarray[j].getTeamName()< inputarray[i].getTeamName()) {

        temp = inputarray[i];

        inputarray[i] = inputarray[j];

        inputarray[j] = temp;

      }

  }

}

}
