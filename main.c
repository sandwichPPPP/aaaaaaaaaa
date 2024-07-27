#include "stm32f10x.h"                  // Device header
#i
#include "Serial.h"
#include "Delay.h"
uint8_t key=0,n=0;
void dac_config_init();

unsigned char Counter=0;
unsigned long TimeCounter=0;

void LED4_Display (void)
{
unsigned char  *led_table;          // 查表指针
unsigned char i;
	//显示第1位
	led_table = LED_0F + LED[0];
	i = *led_table;
	LED_OUT(i);			
	LED_OUT(0x01);		
	GPIO_ResetBits(GPIOA, GPIO_Pin_5);
  Delay_ms(1);
	GPIO_SetBits(GPIOA, GPIO_Pin_5);
	//显示第2位
	led_table = LED_0F + LED[1];
	i = *led_table;
	LED_OUT(i);		
	LED_OUT(0x02);		
	GPIO_ResetBits(GPIOA, GPIO_Pin_5);
  Delay_ms(1);
	GPIO_SetBits(GPIOA, GPIO_Pin_5);
	//显示第3位
	led_table = LED_0F + LED[2];
	i = *led_table&0X7F;//带小数点
	LED_OUT(i);			
	LED_OUT(0x04);	
	GPIO_ResetBits(GPIOA, GPIO_Pin_5);
  Delay_ms(1);
	GPIO_SetBits(GPIOA, GPIO_Pin_5);
	//显示第4位
	led_table = LED_0F + LED[3];
	i = *led_table;
	LED_OUT(i);			
	LED_OUT(0x08);		
	GPIO_ResetBits(GPIOA, GPIO_Pin_5);
  Delay_ms(1);
	GPIO_SetBits(GPIOA, GPIO_Pin_5);
}
//管脚输出控制
void LED_OUT(unsigned char X)
{
	unsigned char i;
	for(i=8;i>=1;i--)
	{
		if (X&0x80) 
		{
			GPIO_SetBits(GPIOA, GPIO_Pin_6);
		}else 
		{
				GPIO_ResetBits(GPIOA, GPIO_Pin_6);
		}
		X<<=1;
	 GPIO_ResetBits(GPIOA, GPIO_Pin_5);
	 GPIO_SetBits(GPIOA, GPIO_Pin_5);
}
}
DMA_InitTypeDef DMA_InitStructure;											//???????
uint16_t abbb[1024];
int i=0;
int main(void)
{
    key_init();
//	dac_config_init(); 
    LED_Init();
	Serial_Init();
//		printf("\r\nNum2=%d", 222);
	while (1)
	{
        key=KEY_SCAN();
		if(key==1)
		{
			for(int j=0;j<26;j++){abbb[j]=aa[j];}
			if(n==0){for(i=26;i<128;i++){abbb[i]=square_wave0[i-26];}}
			else if(n==1){for(i=26;i<128;i++){abbb[i+102]=square_wave0[i-26];}}
			else if(n==2){for(i=26;i<128;i++){abbb[i+204]=square_wave0[i-26];}}
			else if(n==3){for(i=26;i<128;i++){abbb[i+306]=square_wave0[i-26];}}	
			else if(n==4){n=0;}
			for(int k=434;k<460;k++){abbb[k]=aa[k-434];}
			n++;
		}
		if(key==2)
		{
			for(int j=0;j<26;j++){abbb[j]=aa[j];}
			if(n==0){for(i=26;i<128;i++){abbb[i]=square_wave1[i-26];}}
			else if(n==1){for(i=26;i<128;i++){abbb[i+102]=square_wave1[i-26];}}
			else if(n==2){for(i=26;i<128;i++){abbb[i+204]=square_wave1[i-26];}}
			else if(n==3){for(i=26;i<128;i++){abbb[i+306]=square_wave1[i-26];}}		
			else if(n==4){n=0;}	
			for(int k=434;k<460;k++){abbb[k]=aa[k-434];}
			n++;
		}
		if(key==3)
		{
			for(int j=0;j<26;j++){abbb[j]=aa[j];}
			if(n==0){for(i=26;i<128;i++){abbb[i]=square_wave2[i-26];}}
			else if(n==1){for(i=26;i<128;i++){abbb[i+102]=square_wave2[i-26];}}
			else if(n==2){for(i=26;i<128;i++){abbb[i+204]=square_wave2[i-26];}}
			else if(n==3){for(i=26;i<128;i++){abbb[i+306]=square_wave2[i-26];}}	
      else if(n==4){n=0;}	
			for(int k=434;k<460;k++){abbb[k]=aa[k-434];}
			n++;			
		}
		if(key==4)
		{
			for(int j=0;j<26;j++){abbb[j]=aa[j];}
			if(n==0){for(i=26;i<128;i++){abbb[i]=square_wave3[i-26];}}
			else if(n==1){for(i=26;i<128;i++){abbb[i+102]=square_wave3[i-26];}}
			else if(n==2){for(i=26;i<128;i++){abbb[i+204]=square_wave3[i-26];}}
			else if(n==3){for(i=26;i<128;i++){abbb[i+306]=square_wave3[i-26];}}	
		  else if(n==4){n=0;}	
			for(int k=434;k<460;k++){abbb[k]=aa[k-434];}
			n++; 
		}
		if(key==5)
		{
			for(int j=0;j<26;j++){abbb[j]=aa[j];}
			if(n==0){for(i=26;i<128;i++){abbb[i]=square_wave4[i-26];}}
			else if(n==1){for(i=26;i<128;i++){abbb[i+102]=square_wave4[i-26];}}
			else if(n==2){for(i=26;i<128;i++){abbb[i+204]=square_wave4[i-26];}}
			else if(n==3){for(i=26;i<128;i++){abbb[i+306]=square_wave4[i-26];}}	
			else if(n==4){n=0;}	
			for(int k=434;k<460;k++){abbb[k]=aa[k-434];}
			n++;			
		}
		if(key==6)
		{
			for(int j=0;j<26;j++){abbb[j]=aa[j];}
			if(n==0){for(i=26;i<128;i++){abbb[i]=square_wave5[i-26];}}
			else if(n==1){for(i=26;i<128;i++){abbb[i+102]=square_wave5[i-26];}}
			else if(n==2){for(i=26;i<128;i++){abbb[i+204]=square_wave5[i-26];}}
			else if(n==3){for(i=26;i<128;i++){abbb[i+306]=square_wave5[i-26];}}	
			else if(n==4){n=0;}	
			for(int k=434;k<460;k++){abbb[k]=aa[k-434];}
			n++;			
		}
		if(key==7)
		{
			for(int j=0;j<26;j++){abbb[j]=aa[j];}
			if(n==0){for(i=26;i<128;i++){abbb[i]=square_wave6[i-26];}}
			else if(n==1){for(i=26;i<128;i++){abbb[i+102]=square_wave6[i-26];}}
			else if(n==2){for(i=26;i<128;i++){abbb[i+204]=square_wave6[i-26];}}
			else if(n==3){for(i=26;i<128;i++){abbb[i+306]=square_wave6[i-26];}}		
			else if(n==4){n=0;}	
			for(int k=434;k<460;k++){abbb[k]=aa[k-434];}
			n++;			
		}
			if(key==8)
		{
			for(int j=0;j<26;j++){abbb[j]=aa[j];}
			if(n==0){for(i=26;i<128;i++){abbb[i]=square_wave7[i-26];}}
			else if(n==1){for(i=26;i<128;i++){abbb[i+102]=square_wave7[i-26];}}
			else if(n==2){for(i=26;i<128;i++){abbb[i+204]=square_wave7[i-26];}}
			else if(n==3){for(i=26;i<128;i++){abbb[i+306]=square_wave7[i-26];}}		
			else if(n==4){n=0;}	
			for(int k=434;k<460;k++){abbb[k]=aa[k-434];}
			n++;			
		}
			if(key==9)
		{
			for(int j=0;j<26;j++){abbb[j]=aa[j];}
			if(n==0){for(i=26;i<128;i++){abbb[i]=square_wave8[i-26];}}
			else if(n==1){for(i=26;i<128;i++){abbb[i+102]=square_wave8[i-26];}}
			else if(n==2){for(i=26;i<128;i++){abbb[i+204]=square_wave8[i-26];}}
			else if(n==3){for(i=26;i<128;i++){abbb[i+306]=square_wave8[i-26];}}		
			else if(n==4){n=0;}	
			for(int k=434;k<460;k++){abbb[k]=aa[k-434];}
			n++;			
		}
				if(key==10)
		{
			for(int j=0;j<26;j++){abbb[j]=aa[j];}
			if(n==0){for(i=26;i<128;i++){abbb[i]=square_wave9[i-26];}}
			else if(n==1){for(i=26;i<128;i++){abbb[i+102]=square_wave9[i-26];}}
			else if(n==2){for(i=26;i<128;i++){abbb[i+204]=square_wave9[i-26];}}
			else if(n==3){for(i=26;i<128;i++){abbb[i+306]=square_wave9[i-26];}}		
			else if(n==4){n=0;}	
			for(int k=434;k<460;k++){abbb[k]=aa[k-434];}
			n++;			
		}
		if(key==12)
		{
			for(int j=0;j<512;j++){abbb[j]=ab[j];}
		}
		if(key==11)
		{
			DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)abbb ;           //??????
      dac_config_init();		 
		}
//		if(key==12)
//		{
//			DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)ab ;           //??????
//      dac_config_init();		 
//		}
//			for(i=208;i<512;i++)
//			{
//				
//			}
	   
     
            
//		else if(key==2)
//		{
//	    DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)square_wave2 ;           //??????
//      dac_config_init();
//     
//            
//		}
		
 
	}
}


//uint16_t finnal[512];
//uint16_t square_wave(uint16_t x)
//{
//	uint16_t n;
//	if(x==0)
//	{
//		return ;
//	}
//		
//}

void dac_config_init()
{
	
		/*????*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//??GPIOA???
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);	//??DAC??
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);	//??DMA??
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	//?????2??
	
		/*GPIO???*/
	GPIO_InitTypeDef GPIO_InitStructure;					//?????
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		//??????
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;				//GPIO??A4
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//GPIO??50MHz	
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
 
		/*???2??*/
	TIM_PrescalerConfig(TIM2,36-1,TIM_PSCReloadMode_Update);
	TIM_SetAutoreload(TIM2,1000-1);
	TIM_SelectOutputTrigger(TIM2,TIM_TRGOSource_Update);
	
		/*DAC_InitStruct ?????*/
	DAC_InitTypeDef DAC_InitStruct;
 
	DAC_InitStruct.DAC_Trigger = DAC_Trigger_T2_TRGO;      //????:???2??
	DAC_InitStruct.DAC_WaveGeneration = DAC_WaveGeneration_None;  //?????
	DAC_InitStruct.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
	DAC_InitStruct.DAC_OutputBuffer = DAC_OutputBuffer_Enable;   //??????
	DAC_Init(DAC_Channel_1,&DAC_InitStruct);  //
	
 
		/*DMA???*/

 
	DMA_InitStructure.DMA_PeripheralBaseAddr =  (uint32_t)&DAC -> DHR12R1;        //?????
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;	//??????,????
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;			//??????,????
	
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;			//???????,????,????????
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;						//???????,????,?????,?????????
	
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;							//??????,????????
	DMA_InitStructure.DMA_BufferSize = 1024;										//???????
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;								//??,??????
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;						//???,????
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;									//??????
	DMA_Init(DMA2_Channel3, &DMA_InitStructure);								//????????DMA_Init,??DMA2???3
	
	
		/*??*/
	TIM_Cmd(TIM2, ENABLE);					//???2??
	DMA_Cmd(DMA2_Channel3,ENABLE);  //??dma
	DAC_Cmd(DAC_Channel_1, ENABLE); //??DAC??1
	DAC_DMACmd(DAC_Channel_1, ENABLE);  //??DAC???DMA
	
}
