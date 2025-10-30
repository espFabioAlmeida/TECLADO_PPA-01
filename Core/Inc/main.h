/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_CPU_Pin GPIO_PIN_13
#define LED_CPU_GPIO_Port GPIOC
#define LED_COM_Pin GPIO_PIN_14
#define LED_COM_GPIO_Port GPIOC
#define TECLADO_C2_Pin GPIO_PIN_15
#define TECLADO_C2_GPIO_Port GPIOC
#define TECLADO_L5_Pin GPIO_PIN_0
#define TECLADO_L5_GPIO_Port GPIOC
#define TECLADO_L4_Pin GPIO_PIN_1
#define TECLADO_L4_GPIO_Port GPIOC
#define TECLADO_L3_Pin GPIO_PIN_2
#define TECLADO_L3_GPIO_Port GPIOC
#define TECLADO_C6_Pin GPIO_PIN_5
#define TECLADO_C6_GPIO_Port GPIOC
#define TECLADO_C5_Pin GPIO_PIN_0
#define TECLADO_C5_GPIO_Port GPIOB
#define TECLADO_C4_Pin GPIO_PIN_1
#define TECLADO_C4_GPIO_Port GPIOB
#define TECLADO_C3_Pin GPIO_PIN_2
#define TECLADO_C3_GPIO_Port GPIOB
#define TECLADO_L2_Pin GPIO_PIN_13
#define TECLADO_L2_GPIO_Port GPIOB
#define TECLADO_L1_Pin GPIO_PIN_14
#define TECLADO_L1_GPIO_Port GPIOB
#define TECLADO_C2B15_Pin GPIO_PIN_15
#define TECLADO_C2B15_GPIO_Port GPIOB
#define LCD_RS_Pin GPIO_PIN_6
#define LCD_RS_GPIO_Port GPIOC
#define LCD_ENABLE_Pin GPIO_PIN_7
#define LCD_ENABLE_GPIO_Port GPIOC
#define LCD_D4_Pin GPIO_PIN_8
#define LCD_D4_GPIO_Port GPIOC
#define LCD_D5_Pin GPIO_PIN_9
#define LCD_D5_GPIO_Port GPIOC
#define LCD_D6_Pin GPIO_PIN_8
#define LCD_D6_GPIO_Port GPIOA
#define LCD_D7_Pin GPIO_PIN_9
#define LCD_D7_GPIO_Port GPIOA
#define LCD_BKL_Pin GPIO_PIN_10
#define LCD_BKL_GPIO_Port GPIOA
#define BUZZER_Pin GPIO_PIN_11
#define BUZZER_GPIO_Port GPIOA
#define TECLADO_C1_Pin GPIO_PIN_12
#define TECLADO_C1_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
