#include "MPU6050.h"
#include "I2C.h"
#define UMBRALES_X 400
#define UMBRALES_Y 200 
#define UMBRALES_Z 550
int led_x= 4;
int led_y= 5;
int led_z= 6;

int main(void){
    SIM_SCGC5_PORTA_MASK;
    PORTB->PCR[led_y] = PORT_PCR_MUX(1<<8);
    PTA->PCR(led_y <<0);
    PTA->PSOR(led_y << 0);
    PORTB->PCR[led_y] = PORT_PCR_MUX(1<<8);
    PTA->PCR(led_y <<0);
    PTA->PSOR(led_y <<0);
    PORTB->PCR[led_x] = PORT_PCR_MUX(1<<8);
    PTA->PCR(led_x <<0);
    PTA->PSOR(led_x <<0);
    MPU6050_Init();

    while(1){
        MPU6050_AcelX();
        MPU6050_AcelY();
        MPU6050_AcelZ();
        MPU6050_GiroX();
        MPU6050_GiroY();
        MPU6050_GiroZ();
        MPU6050_Temp();
        if(UMBRALES_X > 400){
            PTA-> PTOR(led_x << 1);
        }else if(UMBRALES_Y > 200){
            PTA-> PTOR(led_x << 1);
            PTA-> PTOR(led_y << 1);
        }else if(UMBRALES_Z > 200){
            PTA-> PTOR(led_y << 1);
            PTA-> PTOR(led_z << 1);
        }
    }
    return 0;
}