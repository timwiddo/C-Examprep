#include <stdio.h>


//Prozedur
void bigger(int a, int b){
  
  if (a >= b){
    printf("%d", a);
  }
  
  if (b > a){
    printf("%d", b);
  }
  
}



//Funktion
int getbigger(int a, int b){
  if (a>=b){
    return a;
  }
  else{
    return b;
  }
}

int main()
{
    bigger(5,3);
    printf("\n");
    printf("%d", getbigger(10,7));
}