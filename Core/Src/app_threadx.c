/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    app_threadx.c
  * @author  MCD Application Team
  * @brief   ThreadX applicative file
  ******************************************************************************
    * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "app_threadx.h"
#include <stdio.h>
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define BTN_STATUS_STACK_SIZE 512
#define LED_ACTION_STACK_SIZE 512
#define LED_STATUS_STACK_SIZE 512
#define QUEUE_STACK_SIZE  16
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
uint8_t btn_status_stack[BTN_STATUS_STACK_SIZE];
uint8_t led_action_stack[LED_ACTION_STACK_SIZE];
uint8_t led_status_stack[LED_STATUS_STACK_SIZE];
uint8_t queue0_stack[QUEUE_STACK_SIZE];
uint8_t queue1_stack[QUEUE_STACK_SIZE];
TX_THREAD btn_status_ptr;
TX_THREAD led_action_ptr;
TX_THREAD led_status_ptr;
TX_QUEUE  queue0_ptr;
TX_QUEUE  queue1_ptr;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
VOID btn_status(ULONG initial_input);
VOID led_action(ULONG initial_input);
VOID led_status(ULONG initial_input);
/* USER CODE END PFP */

/**
  * @brief  Application ThreadX Initialization.
  * @param memory_ptr: memory pointer
  * @retval int
  */
UINT App_ThreadX_Init(VOID *memory_ptr)
{
  UINT ret = TX_SUCCESS;
  /* USER CODE BEGIN App_ThreadX_MEM_POOL */

  /* USER CODE END App_ThreadX_MEM_POOL */
  /* USER CODE BEGIN App_ThreadX_Init */
  tx_queue_create(&queue0_ptr, "message_btn_status", TX_1_ULONG ,queue0_stack,QUEUE_STACK_SIZE);
  tx_queue_create(&queue1_ptr, "message_led_status", TX_1_ULONG ,queue1_stack,QUEUE_STACK_SIZE);

  tx_thread_create(&btn_status_ptr,"btn_status",btn_status,0,btn_status_stack, BTN_STATUS_STACK_SIZE,15,15,1,TX_AUTO_START);

  tx_thread_create(&led_action_ptr,"led_action",led_action,0,led_action_stack, LED_ACTION_STACK_SIZE,15,15,1,TX_AUTO_START);

  tx_thread_create(&led_status_ptr,"led_status",led_status,0,led_status_stack, LED_STATUS_STACK_SIZE,15,15,1,TX_AUTO_START);
  /* USER CODE END App_ThreadX_Init */

  return ret;
}

  /**
  * @brief  Function that implements the kernel's initialization.
  * @param  None
  * @retval None
  */
void MX_ThreadX_Init(void)
{
  /* USER CODE BEGIN  Before_Kernel_Start */

  /* USER CODE END  Before_Kernel_Start */

  tx_kernel_enter();

  /* USER CODE BEGIN  Kernel_Start_Error */

  /* USER CODE END  Kernel_Start_Error */
}

/* USER CODE BEGIN 1 */
VOID btn_status (ULONG initial_input) {
ULONG message_pin_status = DISABLE;
ULONG message_pin_status_new = DISABLE;

while(1) {
tx_thread_sleep(10);

   if(!HAL_GPIO_ReadPin(User_Button_GPIO_Port, User_Button_Pin)) {
   message_pin_status_new = ENABLE;
   }

   else {
   message_pin_status_new = DISABLE;
   }

   if (message_pin_status != message_pin_status_new) {
   message_pin_status = message_pin_status_new;
   tx_queue_send(&queue0_ptr,&message_pin_status,TX_NO_WAIT);
   }
   }
   }

VOID led_action(ULONG initial_input) {

ULONG message_status;

while(1) {
tx_queue_receive(&queue0_ptr,&message_status,TX_WAIT_FOREVER);

   if(message_status) {
   HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin,GPIO_PIN_SET);
   }

   else {
   HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin,GPIO_PIN_RESET);
   }

   tx_queue_send(&queue1_ptr,&message_status,TX_NO_WAIT);
  }
  }

VOID led_status(ULONG initial_input) {

ULONG message_status = DISABLE;

while(1) {

   tx_queue_receive(&queue1_ptr,&message_status,TX_WAIT_FOREVER);

   if(message_status)
   printf("The LED is ON\r\n");

   else
   printf("The LED is OFF\r\n");

   }
   }
/* USER CODE END 1 */
