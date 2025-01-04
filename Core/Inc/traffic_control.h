
#ifndef INC_TRAFFIC_CONTROL_H_
#define INC_TRAFFIC_CONTROL_H_

// Define the states of the traffic light system
typedef enum {
    NS_Green_EW_Red,        // North-South direction has a green light, East-West direction has a red light
    NS_Yellow_EW_Red,       // North-South direction has a yellow light, East-West direction remains red
    NS_Red_EW_Green,        // North-South direction has a red light, East-West direction has a green light
    NS_Red_EW_Yellow,       // North-South direction remains red, East-West direction has a yellow light
    Pedestrian_Crossing_NS, // All vehicle lights are red, North-South pedestrian signal shows "Walk"
    Pedestrian_Crossing_EW  // All vehicle lights are red, East-West pedestrian signal shows "Walk"
} Traffic_State;


// Function prototypes for traffic light control

/**
 * @brief Update the traffic light and pedestrian signal states based on the current state and timing.
 */
void updateTrafficState(void);

/**
 * @brief Configure the traffic lights for both NS and EW directions.
 *
 * @param nsGreen State of the NS green light.
 * @param nsYellow State of the NS yellow light.
 * @param nsRed State of the NS red light.
 * @param ewGreen State of the EW green light.
 * @param ewYellow State of the EW yellow light.
 * @param ewRed State of the EW red light.
 */
void configureTrafficLights(uint8_t nsGreen, uint8_t nsYellow, uint8_t nsRed, uint8_t ewGreen, uint8_t ewYellow, uint8_t ewRed);

/**
 * @brief Configure the pedestrian signals for both NS and EW directions.
 *
 * @param nsWalk State of the NS walk signal.
 * @param nsDontWalk State of the NS don't walk signal.
 * @param ewWalk State of the EW walk signal.
 * @param ewDontWalk State of the EW don't walk signal.
 */
void configurePedestrianSignals(uint8_t nsWalk, uint8_t nsDontWalk, uint8_t ewWalk, uint8_t ewDontWalk);

/**
 * @brief Process pedestrian requests and transition to the appropriate crossing state if needed.
 */
void processPedestrianRequest(void); // Processes pedestrian requests and transitions to the appropriate crossing state if needed



#endif /* INC_TRAFFIC_CONTROL_H_ */
