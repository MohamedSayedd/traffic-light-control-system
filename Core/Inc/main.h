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
#include "stm32f1xx_hal.h"

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
//North-South Traffic Lights

#define NS_GREEN_Pin GPIO_PIN_0
#define NS_GREEN_Pin_GPIO_Port GPIOA
#define NS_YELLOW_Pin GPIO_PIN_1
#define NS_YELLOW_Pin_GPIO_Port GPIOA
#define NS_RED_Pin GPIO_PIN_2

//East-West Traffic Lights
#define NS_RED_Pin_GPIO_Port GPIOA
#define EW_GREEN_Pin GPIO_PIN_3
#define EW_GREEN_Pin_GPIO_Port GPIOA
#define EW_YELLOW_Pin GPIO_PIN_4
#define EW_YELLOW_Pin_GPIO_Port GPIOA
#define EW_RED_Pin GPIO_PIN_5
#define EW_RED_Pin_GPIO_Port GPIOA

#define NS_WALK_Pin GPIO_PIN_0
#define NS_WALK_Pin_GPIO_Port GPIOB

#define NS_DONT_WALK_Pin GPIO_PIN_1
#define NS_DONT_WALK_Pin_GPIO_Port GPIOB

#define EW_WALK_Pin GPIO_PIN_10
#define EW_WALK_Pin_GPIO_Port GPIOB
#define EW_DONT_WALK_Pin GPIO_PIN_11
#define EW_DONT_WALK_Pin_GPIO_Port GPIOB


#define NS_BUTTON_Pin GPIO_PIN_6
#define NS_BUTTON_Pin_GPIO_Port GPIOA
#define EW_BUTTON_Pin GPIO_PIN_7
#define NS_BUTTON_Pin_GPIO_Port GPIOA



















/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
