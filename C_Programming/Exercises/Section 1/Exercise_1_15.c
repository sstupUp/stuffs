#include <stdio.h>

//rewriting temperature conversion using function

float conversion(float);

main()
{
  float fahr, celsi, step;
  int lower, upper;

  lower = 0;
  upper = 300;
  step = 15.5;

  fahr = lower;

  printf("Fahr \t Celsi\n");
  for(;fahr <= upper; fahr += step)
    printf("%.2f\t%.2f\n", fahr, conversion(fahr));

}

float conversion(float fahr)
{
  return 5.0/9.0*(fahr-32);
}
