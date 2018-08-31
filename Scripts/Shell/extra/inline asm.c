// Power2_inline_asm.c  
// compile with: /EHsc  
// processor: x86  
  
#include <stdio.h>  
  
int power2( int num, int power );  
  
int main( void )  
{  
    power2( 3, 5);
}  
int power2( int num, int power )  
{  
   __asm__
   (  
      mov r0, num    ; Get first argument  
      mov r1, power  ; Get second argument  
      shl eax, cl     ; EAX = EAX * ( 2 to the power of CL )  
   )  ;
   return 0;
   // Return with result in EAX  
}  
