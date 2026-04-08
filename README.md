# Peekabot-
So this project is beased on an esp32 spy camera and it will basically take a picture and send it to the user via telegram bot it will also have custom built PCBs and 3D printed case!!!


what this basically does is that when it recieves a /capture string on telegram it takes an image through the esp32 camera module in some part of the world and then through the telegram's api it can send the captured image anywhere in the world and it also has other functions such as adjusting jpecg quality by using "?jpeg "val"" and also an option for enabeling the flash of the esp32 camera module 



# HARDWARE!
so this is a rough idea of what hardware will be used for this project!
1. Esp32 Ai-Thinker camera module
2. custom PCB base module with reset button and a usb port to power it easily 
3. 3d printed enclosure
4. battery

#PCB!!
so the pcb for the V1 of this project consists of 
1. IP5306 battery charging module 
2. micro usb connector 
3. battery connector
4.  header pins (to connect esp32 camera module)

the pcb has a samll form factor overall and will be powered by 2 li-ion battries which should give it a battery life of aproximately 8-12 hours which is enough for certain applications

furthermore i will optimize the code so that the esp32 will go to deep sleep so that it could possibly in theory survive for months on a singular charge!!

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
