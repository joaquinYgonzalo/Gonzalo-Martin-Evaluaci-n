#include "MPU6050.h"
#include "I2C.h"

int temp;
void MPU6050_Init(){//no me acuerdo de esto
   SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
   I2C0_Init();
   I2C_Start();
   
}

int MPU6050_AcelX(){
   I2C_ReadRegister();
   if(data != 0){
      I2C_WriteRegister(data);
      return data;
   }else {
      return 0;
   }
}
int MPU6050_AcelY(){
   I2C_ReadRegister();
   if(data != 0){
      I2C_WriteRegister(data);
      return data;
   }else {
      return 0;
   }
}
int MPU6050_AcelZ(){
   I2C_ReadRegister();
   if(data != 0){
      I2C_WriteRegister(data);
      return data;
   }else {
      return 0;
   }
}
int MPU6050_GiroX(){
   I2C_ReadRegister();
   if(data != 0){
      I2C_WriteRegister(data);
      return data;
   }else {
      return 0;
   }
}
int MPU6050_GiroY(){
   I2C_ReadRegister();
   if(data != 0){
      I2C_WriteRegister(data);
      return data;
   }else {
      return 0;
   }
}
int MPU6050_GiroZ(){
   I2C_ReadRegister();
   if(data != 0){
      I2C_WriteRegister(data);
      return data;
   }else {
      return 0;
   }
}
int MPU6050_Temp(){
   if((temp >= 0)&&(temp <=70)){
      return temp;
   }else{
      return 0;
   }
}