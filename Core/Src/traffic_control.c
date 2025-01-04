#include "main.h"
#include "traffic_control.h"
#include "traffic_control_Config.h"

// Initialize the current state to NS_Green_EW_Red
Traffic_State currentState = NS_Green_EW_Red;
uint32_t previousMillis = 0;

// Flags for pedestrian requests
volatile uint8_t nsPedestrianRequest = 0;
volatile uint8_t ewPedestrianRequest = 0;



void updateTrafficState(void) {
    uint32_t currentMillis = HAL_GetTick();

    switch (currentState) {
        case NS_Green_EW_Red:
            configureTrafficLights(GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET);
            configurePedestrianSignals(GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_SET);

            if (currentMillis - previousMillis >= greenDuration) {
                previousMillis = currentMillis;
                currentState = NS_Yellow_EW_Red;
            }
            break;

        case NS_Yellow_EW_Red:
            configureTrafficLights(GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET);

            if (currentMillis - previousMillis >= yellowDuration) {
                previousMillis = currentMillis;
                currentState = NS_Red_EW_Green;
                processPedestrianRequest();
            }
            break;

        case NS_Red_EW_Green:
            configureTrafficLights(GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET);
            configurePedestrianSignals(GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_SET);

            if (currentMillis - previousMillis >= greenDuration) {
                previousMillis = currentMillis;
                currentState = NS_Red_EW_Yellow;
            }
            break;

        case NS_Red_EW_Yellow:
            configureTrafficLights(GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_RESET);

            if (currentMillis - previousMillis >= yellowDuration) {
                previousMillis = currentMillis;
                currentState = NS_Green_EW_Red;
                processPedestrianRequest();
            }
            break;

        case Pedestrian_Crossing_NS:
            configureTrafficLights(GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET);
            configurePedestrianSignals(GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET);

            if (currentMillis - previousMillis >= pedestrianDuration) {
                previousMillis = currentMillis;
                currentState = NS_Red_EW_Green;
            }
            break;

        case Pedestrian_Crossing_EW:
            configureTrafficLights(GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_RESET, GPIO_PIN_RESET, GPIO_PIN_SET);
            configurePedestrianSignals(GPIO_PIN_RESET, GPIO_PIN_SET, GPIO_PIN_SET, GPIO_PIN_RESET);

            if (currentMillis - previousMillis >= pedestrianDuration) {
                previousMillis = currentMillis;
                currentState = NS_Green_EW_Red;
            }
            break;
    }
}



void configureTrafficLights(uint8_t nsGreen, uint8_t nsYellow, uint8_t nsRed, uint8_t ewGreen, uint8_t ewYellow, uint8_t ewRed) {
    HAL_GPIO_WritePin(GPIOA, NS_GREEN_Pin, nsGreen);
    HAL_GPIO_WritePin(GPIOA, NS_YELLOW_Pin, nsYellow);
    HAL_GPIO_WritePin(GPIOA, NS_RED_Pin, nsRed);
    HAL_GPIO_WritePin(GPIOA, EW_GREEN_Pin, ewGreen);
    HAL_GPIO_WritePin(GPIOA, EW_YELLOW_Pin, ewYellow);
    HAL_GPIO_WritePin(GPIOA, EW_RED_Pin, ewRed);
}

/**
 * @brief Configure the pedestrian signals for both NS and EW directions.
 *
 * @param nsWalk State of the NS walk signal.
 * @param nsDontWalk State of the NS don't walk signal.
 * @param ewWalk State of the EW walk signal.
 * @param ewDontWalk State of the EW don't walk signal.
 */
void configurePedestrianSignals(uint8_t nsWalk, uint8_t nsDontWalk, uint8_t ewWalk, uint8_t ewDontWalk) {
    HAL_GPIO_WritePin(GPIOB, NS_WALK_Pin, nsWalk);
    HAL_GPIO_WritePin(GPIOB, NS_DONT_WALK_Pin, nsDontWalk);
    HAL_GPIO_WritePin(GPIOB, EW_WALK_Pin, ewWalk);
    HAL_GPIO_WritePin(GPIOB, EW_DONT_WALK_Pin, ewDontWalk);
}

/**
 * @brief Process pedestrian requests and transition to the appropriate crossing state if needed.
 */
void processPedestrianRequest(void) {
    if (nsPedestrianRequest) {
        nsPedestrianRequest = 0;
        currentState = Pedestrian_Crossing_NS;
        previousMillis = HAL_GetTick();
    } else if (ewPedestrianRequest) {
        ewPedestrianRequest = 0;
        currentState = Pedestrian_Crossing_EW;
        previousMillis = HAL_GetTick();
    }
}
