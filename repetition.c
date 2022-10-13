/********************************************************************************
* repetition.c: Demonstration av beräkning som returneras vid återhopp jämfört
*               med lagring av resultat på angiven adress.
********************************************************************************/
#include <stdio.h>

/********************************************************************************
* multiply: Multiplicerar angivna tre flyttal och returnerar resultatet.
*   
*           - a: Det första flyttalet.
*           - b: Det andra flyttalet.
*           - c: Det tredje flyttalet.
********************************************************************************/
double multiply(const double a, 
                const double b, 
                const double c) 
{
   return a * b * c;
}

/********************************************************************************
* multiply_ptr: Multiplicerar angivna tre flyttal och lagrar resultatet på
*               angiven adress.
*
*               - a     : Det första flyttalet.
*               - b     : Det andra flyttalet.
*               - c     : Det tredje flyttalet.
*               - result: Pekare till adress där resultatet skall lagras.
********************************************************************************/
void multiply_ptr(const double a,
                  const double b,
                  const double c,
                  double* result)
{
   *result = a * b * c;
   return;
}




/********************************************************************************
* main: Beräknar produkten av tre flyttal via två funktioner, en som returnerar
*       produkten och en som lagrar produkten på angiven adress.
********************************************************************************/
int main(void)
{
   double product = 0;
   multiply_ptr(3, 4, 5, &product);

   printf("3 * 4 * 5 = %lg\n", multiply(3, 4, 5));
   printf("3 * 4 * 5 = %lg\n", product);

   return 0;
}