
//smoothing average - 0.1 = slow change; 0.5 = normal average;  0.9 = fast change

float smooth(float lastValue, float newValue, float factor) {

    return (newValue * factor) + (lastValue * (1.0 - factor));

}
