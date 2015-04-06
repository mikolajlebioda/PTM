
#include "main.h"


/* Private typedef -----------------------------------------------------------*/
TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint16_t PrescalerValue = 0;
uint8_t Buffer[6];
__IO uint32_t TimingDelay = 0;
__IO int8_t XOffset;
__IO int8_t YOffset;


/* Private function prototypes -----------------------------------------------*/
//static void TIM_Config(void);

/* Private functions ---------------------------------------------------------*/

int main(void)
{
  //uint8_t ctrl = 0;
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);
  STM_EVAL_LEDInit(LED5);
  STM_EVAL_LEDInit(LED6);
  
  LIS302DL_InitTypeDef  LIS302DL_InitStruct;


  

  /* Set configuration of LIS302DL*/
  LIS302DL_InitStruct.Power_Mode = LIS302DL_LOWPOWERMODE_ACTIVE;
  LIS302DL_InitStruct.Output_DataRate = LIS302DL_DATARATE_400;
  LIS302DL_InitStruct.Axes_Enable = LIS302DL_X_ENABLE | LIS302DL_Y_ENABLE | LIS302DL_Z_ENABLE;
  LIS302DL_InitStruct.Full_Scale = LIS302DL_FULLSCALE_2_3;
  LIS302DL_InitStruct.Self_Test = LIS302DL_SELFTEST_NORMAL;
  LIS302DL_Init(&LIS302DL_InitStruct);
  /* SysTick end of count event each 100ms */
  SysTick_Config(SystemCoreClock/1000);

  /* Required delay for the MEMS Accelerometre: Turn-on time = 3/Output data Rate 
                                                             = 3/100 = 30ms */
  Delay(30);
  

  LIS302DL_Read(Buffer, LIS302DL_OUT_X_ADDR, 6);
                  
  XOffset = Buffer[0];
  YOffset = Buffer[2];

  while(1)
  {

  }
}

void Delay(__IO uint32_t nTime)
{ 
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}


uint32_t LIS302DL_TIMEOUT_UserCallback(void)
{
  while (1)
  {   
  }
}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t* file, uint32_t line)
{ 

  while (1)
  {
  }
}
#endif

