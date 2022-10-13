/********************************************************************************
* repetition.c: Demonstration av ber�kning som returneras vid �terhopp j�mf�rt
*               med lagring av resultat p� angiven adress.
********************************************************************************/
#include <stdio.h>

/********************************************************************************
* multiply: Multiplicerar angivna tre flyttal och returnerar resultatet.
*   
*           - a: Det f�rsta flyttalet.
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
* multiply_ptr: Multiplicerar angivna tre flyttal och lagrar resultatet p�
*               angiven adress.
*
*               - a     : Det f�rsta flyttalet.
*               - b     : Det andra flyttalet.
*               - c     : Det tredje flyttalet.
*               - result: Pekare till adress d�r resultatet skall lagras.
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
* main: Ber�knar produkten av tre flyttal via tv� funktioner, en som returnerar
*       produkten och en som lagrar produkten p� angiven adress.
********************************************************************************/
int main(void)
{
   double product = 0;
   multiply_ptr(3, 4, 5, &product);

   printf("3 * 4 * 5 = %lg\n", multiply(3, 4, 5));
   printf("3 * 4 * 5 = %lg\n", product);

   return 0;
}