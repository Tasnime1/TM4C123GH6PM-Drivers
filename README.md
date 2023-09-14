
# LED Control | ARM-based | TivaC | TM4C123GH6PM

This project aims to control LED blinking for a user-defined ON and OFF periods changed during runtime.

The project is simulated using KEIL Uvision.

The project consists of APP, HAL and MCAL layers. Each driver in a layer has got 4 files; 2 (.c) files and 2 (.h) files. One pair of (.c and .h) files for the initialization and another pair for the configuration.
It utilizes the GPIO, Systick, GPT and  Interrupt(NVIC) for the MCAL Layer.
Also, LED and PushButton for the HAL Layer.
Finally, APP layer is the upper most layer implementing all logic.

You can change the blinking on and off time through two buttons, each of them is used for both specifying time and confirmation.<br>
Eg. Knowint that on time is controlled using PushButton 1 and Push Button 2 is its confirmation, while off time is controlled using PushButton 2 and Push Button 1 is its confirmation.<br>
    So now if you want to make the on time 5 seconds and off time 3 seconds, what will you do?
    You'll press PushButton 1 for 5 times and then hit PushButton 2 for confirmation, and that's the on time part.
    Then for off time, you press PushButton 2 for 3 times and then hit PushButton 1 for confirmation.
    Voila, you have a blinking LED system of 5 seconds on and 3 seconds off, easy.

Feel free to check the project's simulation through KEIL project provided.



