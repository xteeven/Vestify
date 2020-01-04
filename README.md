# Vestify: Providing humans with new artificial sensorial modalities

We perceive the world based on the processing of sensorial inputs we get from many receptors through our body; however, evolution focused these inputs on supplying the most relevant information for our subsistence. Nowadays, the paradigm for human changed, and there are many types of information which can be useful from individual to individual, in a specific context. 

## Getting Started
1. Turn On the vest

2. Plug in the sender to your pc and wait for the geen light

![sender](im1.gif)

3. Then, check the serial port in arduino ide.

4. From any language, send a String to the Port found in step 3 with the following structure (see Serial.py as example):
```
 String message = "AA;FF;MMMMMM"
``` 
- AA = Amplitude [0-64]
  - It is necessary to keep two digits i.e Amplitude 7 should be send as 07
- FF = Frequency [0-40] (Could be a bit higher)
  - It is necessary to keep two digits i.e Frequency 7 should be send as 07
- MMMMMM = Active Motors [0-1]
  - The table below shows the number of each motor so that "100000" will activate only the bottom rigth motor and "000001" the bottom left motor
  - multimple motors could be activated at once. i.e. "001100" would activate the two motors of the first row

| L | R |
|---|---|
| 3 | 2 |
| 4 | 1 |
| 5 | 0 |

- A valid message should look like this: (for amplitude 25, frequency 10 and the only the second row of motors activated)
```
 String message = "25;10;010010"
``` 
 
5. Remember to close the serial port before leaving the app.


### Prerequisites

* Arduino IDE
    * Adafruit DRV2605 Library
    * ESP32 Boards



## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

