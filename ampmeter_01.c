

#include <16F877.h>
#INCLUDE <stdlib.h>
#Fuses HS
//#device ADC=10
#use delay(clock=12000000)
#define sclk pin_c4
#define rclk pin_c5
#define ser  pin_c6

#DEFINE DOT1 PIN_B1
#DEFINE DOT2 PIN_B2

   INT8 COUNT,A,B,out;
   //INT8 NUM[]={0Xff,0Xff,0Xff,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
     INT8 NUM[]={0Xc0,0Xf9,0Xa4,0Xb0,0X99,0X92,0X82,0Xf8,0X80,0X90};
   
INT16 adc0,adc1;
char current[9];
unsigned int16 i;
int8 k;
int8 dot;
int8 n1,n2,n3,n4;
static char x,C;
int8 y;
int8 num_y[5];
   VOID HEX_BCD(INT8 VAL);
void serial(byte dat,int1 point);
void main()
{
   setup_adc_ports(AN0_AN1_AN4_VREF_VREF);
   setup_adc(ADC_CLOCK_INTERNAL);
   set_tris_b(0x00);
   output_low(ser);
   output_low(sclk);
   output_low(rclk); 

     I= 500;
     I *= 50;
           
    sprintf(current, "%6f", (float)I/1023); 

 

    for(k=0;k<5;k++)
    {
      x=current[k];
         if(x!='.')
         {    
          num_y[k]=atoi(&x);
         }
          else
         {
           dot=k;  
         }    
      
    }
    
  switch (dot) {

    case 0:
           x=current[1];
           n1=atoi(&x);
           
           x=current[2];
           n2=atoi(&x);   
           
           x=current[3];
           n3=atoi(&x);   
           
           x=current[4];
           n4=atoi(&x);      
           
     serial(n4,0);
     serial(n3,0);
     serial(n2,0);
     serial(n1,1);
     delay_us(100);
     output_high(rclk);
     delay_us(50);
     output_low(rclk);           
    

           break;

    case 1:
           x=current[0];
           n1=atoi(&x);
           
           x=current[2];
           n2=atoi(&x);   
           
           x=current[3];
           n3=atoi(&x);   
           
           x=current[4];
           n4=atoi(&x); 
        
     serial(n4,0);
     serial(n3,0);
     serial(n2,0);
     serial(n1,1);
     delay_us(100);
     output_high(rclk);
     delay_us(50);
     output_low(rclk);           

           break;
           
    case 2:
           x=current[0];
           n1=atoi(&x);
           
           x=current[1];
           n2=atoi(&x);   
           
           x=current[3];
           n3=atoi(&x);   
           
           x=current[4];
           n4=atoi(&x); 

     serial(n4,0);
     serial(n3,0);
     serial(n2,1);
     serial(n1,0);
     
     delay_us(100);
     output_high(rclk);
     delay_us(50);
     output_low(rclk); 
           break;       
           

    default:

            break; }

  
    
    
    
    
    
    
    
 
    
      C= CURRENT[1];
    IF(C =='.')
    {
     //num_y[3]&=0X7F;
      OUTPUT_LOW(DOT1);
      OUTPUT_HIGH(DOT2);
    }
    ELSE
    {
      OUTPUT_HIGH(DOT1);
      OUTPUT_LOW(DOT2);
    } 

    


     count=0;
    

  
     output_high(rclk);
     delay_us(50);
     output_low(rclk);
     

 



     while(TRUE)
   {
    output_toggle(pin_c2);
    delay_ms(300);
      
    // serial(n4);
    // serial(n3);
    // serial(n2);
    // serial(n1);
    // delay_us(100);
    // output_high(rclk);
    // delay_us(50);
    // output_low(rclk); 
     

   }

}


void serial(byte dat,int1 point)
{INT8 I;
     
     out=NUM[dat];
     if(point==1)
     {
     out&=0x7f;
     }
     
     for(i=0;i<8;++i)
     {
     output_bit(ser,shift_left(&out,1,0));
     output_high(sclk);
     delay_us(100);
     output_low(sclk);
     delay_us(100);
     }
}
