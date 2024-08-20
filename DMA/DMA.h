/*
 * DMA.h
 *
 *  Created on: Jul 20, 2024
 *      Author: kunal
 */

#ifndef DMA_H_
#define DMA_H_

#include "main.h"
#include "DMA_Defs.h"


extern DMA_Flags_Typedef DMA1_Stream0_Flag;
extern DMA_Flags_Typedef DMA1_Stream1_Flag;
extern DMA_Flags_Typedef DMA1_Stream2_Flag;
extern DMA_Flags_Typedef DMA1_Stream3_Flag;
extern DMA_Flags_Typedef DMA1_Stream4_Flag;
extern DMA_Flags_Typedef DMA1_Stream5_Flag;
extern DMA_Flags_Typedef DMA1_Stream6_Flag;
extern DMA_Flags_Typedef DMA1_Stream7_Flag;

extern DMA_Flags_Typedef DMA2_Stream0_Flag;
extern DMA_Flags_Typedef DMA2_Stream1_Flag;
extern DMA_Flags_Typedef DMA2_Stream2_Flag;
extern DMA_Flags_Typedef DMA2_Stream3_Flag;
extern DMA_Flags_Typedef DMA2_Stream4_Flag;
extern DMA_Flags_Typedef DMA2_Stream5_Flag;
extern DMA_Flags_Typedef DMA2_Stream6_Flag;
extern DMA_Flags_Typedef DMA2_Stream7_Flag;





typedef struct DMA_Config
{
	DMA_Request Request;
	uint32_t flow_control;                //Use DMA_Flow_Control
	uint32_t transfer_direction;          //Use DMA_Transfer_Direction
	uint32_t priority_level;              //Use DMA_Priority_Level
	uint32_t circular_mode;               //Use DMA_Circular_Mode
	uint32_t interrupts;                  //Use DMA_Interrupts
	uint16_t memory_pointer_increment;
	uint16_t peripheral_pointer_increment;

	uint32_t peripheral_data_size;        //Use DMA_Peripheral_Data_Size
	uint32_t memory_data_size;            //Use DMA_Memory_Data_Size
	uint32_t peripheral_address;
	uint32_t memory_address;
	uint16_t buffer_length;
}DMA_Config;



void DMA_Clock_Enable(DMA_Config *config);
void DMA_Clock_Disable(DMA_Config *config);
void DMA_Reset(DMA_Config *config);
void DMA_Reset_Flags(DMA_Flags_Typedef flag);
int8_t DMA_Init(DMA_Config *config);
void DMA_Set_Target(DMA_Config *config);
void DMA_Set_Trigger(DMA_Config *config);

void DMA_Memory_To_Memory_Transfer(uint32_t *source,
						  uint8_t source_data_size, uint8_t dest_data_size,
						  uint32_t *destination, bool source_increment,
						  bool destination_increment, uint16_t length);


#endif /* DMA_H_ */
