# Peekabot-
So this project is beased on an esp32 spy camera and it will basically take a picture and send it to the user via telegram bot it will also have custom built PCBs and 3D printed case!!!


what this basically does is that when it recieves a /capture string on telegram it takes an image through the esp32 camera module in some part of the world and then through the telegram's api it can send the captured image anywhere in the world and it also has other functions such as adjusting jpecg quality by using "quality "val"" and also an option for enabeling the flash of the esp32 camera module 

# FUNCTION
1. "/start" to start the bot 
2. "/photo" to capture and send the image
3. "/flash on" to turn on the flash
4. "/flash off" to turn off the flash
5. "/quality" use this command followed by integres from 10-63 eg "/quality 20" (lower the number higher the quality)
6. "/sleep" to make the camera sleep at intervals of 10sseconds to save power
7. "/wakeup" to disable the sleep mode loop\
8. "/autoflash on/off" to enable or disable the functionalty of tunring on flash automatically when taking a photo 
9. "/help" to get list of all the commands inside the bot's UI

*NOTE*
if the camera isn't funtioning properly the camera must be in sleep mode send "/wakeup" command to wake the camera and then it will work properly also do not keep the flash on for extended periods of time because it may cause the camera to overheat and it will also consume very high power around 500mAh wich will greatly reduce the battery life 

THERE CAN BE A MAX DELAY OF 10 seconds AFTER YOU SEND THE "/wakeup" COMMAND BECZ THE CAMERA WILL ONLY RESPOND AFTER IT WOKE UP FROM IT'S SLEEP 



# HARDWARE!
so this is a rough idea of what hardware will be used for this project!
1. Esp32 Ai-Thinker camera module
2. custom PCB base module with reset button and a usb port to power it easily 
3. 3d printed enclosure
4. battery

# PCB!!

so the pcb for the V1 of this project consists of 
1. IP5306 battery charging module 
2. micro usb connector 
3. battery connector
4.  header pins (to connect esp32 camera module)

the pcb has a samll form factor overall and will be powered by 2 li-ion battries which should give it a battery life of aproximately 8-12 hours which is enough for certain applications

furthermore i will optimize the code so that the esp32 will go to deep sleep so that it could possibly in theory survive for months on a singular charge!!
(update) the deepsleep is not implementable for this because deep sleep will result in turning off the wifi which will result in disconnection from the telegram api servers and the esp32 would not be able to wake up and it would remain in deep sleep

# 3D DESIGN!!
so the 3d design of this project is subdivided into 3 majour and minor parts 
1. the pcb enclosure case (3d part 1)
2. the pcb holder lid (3d part 2)
3. The battery holder (3d part 3)

so basically the entire structure is made up of 3 parts one inside thich the pcb is mounted and then the lid of the same box 
then the battery are mounted under these 2 parts and this part is bigger and heavier than majority of the build...

Everything the pcb, the lid and the battery holder part are assembeled using M2 2.2mm screws which hold everything in place sturdily....

i tried to make the entire design as small ad i could but still it is bigger than expected however for the v1 of this build i just need a working prototype and i can impliment a better structure later on

# SOFTWARE USED 
1. arduino ide
2. fusion360
3. kicad

## OVERALL it features a small form factor as it is afterall a spy/surveilance camera ##

# CREDITS
1. google.com
2. random nerd tutorials
3. arduino forms
4. chatgpt/clause FOR DEBUGGING THE CODE
