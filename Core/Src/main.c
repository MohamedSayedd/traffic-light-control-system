#include "main.h"
#include "traffic_control.h"
#include "System_Init.h"

// Initialize the current state to NS_Green_EW_Red
// These variables are declared as external so they are defined  Globally elsewhere
// and can be accessed across different files in the project.
extern Traffic_State currentState;          // Current traffic light state
extern volatile uint8_t nsPedestrianRequest; // Flag for North-South pedestrian crossing request
extern volatile uint8_t ewPedestrianRequest; // Flag for East-West pedestrian crossing request

/**
 * @brief Main program entry point.
 *
 * Initializes the system and enters the main program loop to continuously
 * update the traffic state based on current light configurations and
 * pedestrian requests.
 */
int main(void) {

    // Initialize system configurations (clocks, GPIO, peripherals)
	System_Init();
    while (1) {
        // Main loop: continuously monitor and update traffic signal states
    	 updateTrafficState(); // Update traffic lights and handle pedestrian requests
    		}
}



















// Interrupt Service Routines for button presses
void EXTI9_5_IRQHandler(void) {
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_6) != RESET) {
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_6);
        nsPedestrianRequest = 1;
    }
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_7) != RESET) {
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_7);
        ewPedestrianRequest = 1;
    }
}



