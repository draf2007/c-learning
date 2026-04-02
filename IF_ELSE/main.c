#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
  float a,b,c,dis,x_1,x_2;
  a=b=c=dis=x_1=x_2=0;
  printf("Введите коэффициент A: ");
  float input = scanf("%f",&a);

  if (input != 0) {
            
    } else {
        printf("Ошибка ввода. Введено не число.\n");
        return(0);
    }
  
  printf("Введите коэффициент B: ");
  input = scanf("%f",&b);
  if (input != 0) {
        
    } else {
        printf("Ошибка ввода. Введено не число.\n");
        return(0);
    }

  printf("Введите коэффициент C: ");
  input = scanf("%f",&c);
  if (input != 0) {
        
    } else {
        printf("Ошибка ввода. Введено не число.\n");
        return(0);
    }

  if (a==0) {
        printf("Коэффициент A=0. Уравнение является линейным.\n");
        if (b != 0) {
          x_1=-(c/b);
          printf("x=%.2f", x_1);
          return(0);
        }
          else if (c!=0) {

            printf("Уравнение не имеет корней");
            return(0);

            }
            else {

            printf("Уравнение имеет бесконечное множество корней");
            return(0);

            }
  }

  dis=(pow(b,2))-(4*a*c);

  /*Решение когда D<0*/
  if (dis < 0) {
    
    printf("Уравнение не имеет корней\n");
    return(0);

  }
  /*Решение когда D=0*/
  else if (dis==0) {
    
    x_1=(-(b))/(2*a);
    printf("Уравнение имеет один корень:\n");
    printf("x = %.2f\n", x_1);
    return(0);

  }
  /*Решение когда D>0*/
  else if (dis>0) {
    
    x_1=(-(b)+sqrt(dis))/(2*a);
    x_2=(-(b)-sqrt(dis))/(2*a);
    printf("Уравнение имеет два корня:\n");
    printf("x1 = %.2f\n", x_1);
    printf("x2 = %.2f\n", x_2);

  }
return 0;
}
