# Peekabot-
Peekabot is a esp32 based spy /surveillance camera system it is accessible from anywhere in the world (as long as it is connected to wifi) and it is accessed through telegram bot..

# REASON FOR BUILDING THIS 
why was this made you may ask well i previousely made a esp32 spy camera but it was based on wifi and it didn't have that long of a range also it was not battery operated and no custom pcb or any BMS so i made this and this project has all what the previous one lacked  
# LOGIC 
1. powers on 
2. searches for saved wifi
3. connects to wifi
4. connects to telegram bot via generated API key
5. bot starts
6. checks for incoming commands
7. returns output based on the input

# COMMANDS
1. "/start" to start the bot 
2. "/photo" to capture and send the image
3. "/flash on" to turn on the flash
4. "/flash off" to turn off the flash
5. "/quality" use this command followed by integres from 10-63 eg "/quality 20" (lower the number higher the quality)
8. "/autoflash on/off" to enable or disable the functionalty of tunring on flash automatically when taking a photo 
9. "/help" to get list of all the commands inside the bot's UI


# HARDWARE!
so this is a rough idea of what hardware will be used for this project!
1. Esp32 Ai-Thinker camera module
2. custom PCB base module with reset button and a usb port to power it easily 
3. 3d printed enclosure
4. 2x li-ion batteries

# PCB!!

so the pcb for the V1 of this project consists of 
1. IP5306 battery charging module 
2. micro usb connector 
3. battery connector
4.  header pins (to connect esp32 camera module)

the pcb has a samll form factor overall and will be powered by 2 li-ion battries which should give it a battery life of aproximately 8-12 hours which is enough for most applications furthermore you can just keep it plugged in via a micro usb port and keep it at a fixed place connect it to your wifi and not worry

Furthermore i will optimize the code so that the esp32 will go to deep sleep so that it could possibly in theory survive for months on a singular charge!! 

(update) the deepsleep is not implementable for this because deep sleep will result in turning off the wifi which will result in disconnection from the telegram api servers and the esp32 would not be able to wake up and it would remain in deep sleep
# SCHEMATICS
<img width="1037" height="631" alt="image" src="https://github.com/user-attachments/assets/2ab69c0a-0ccc-4e71-adba-929e1d0b47f1" />
<img width="549" height="640" alt="image" src="https://github.com/user-attachments/assets/a42e1c3e-6164-42a6-bbc7-7a355b9d0669" />

<img width="581" height="804" alt="image" src="https://github.com/user-attachments/assets/43f381a4-6e43-45a2-a0fa-4bfb8bb286c6" />
<img width="481" height="661" alt="image" src="https://github.com/user-attachments/assets/a75519ac-6ce5-486f-8f08-dced0b2878d7" />



# 3D DESIGN!!
so the 3d design of this project is subdivided into 3 majour and minor parts 
1. the pcb enclosure case (3d part 1)
2. the pcb holder lid (3d part 2)
3. The battery holder (3d part 3)
4. 8x M2 2.2mm screws 

so basically the entire structure is made up of 3 parts one inside thich the pcb is mounted and then the lid of the same box 
then the battery are mounted under these 2 parts and this part is bigger and heavier than majority of the build...

Everything the pcb, the lid and the battery holder part are assembeled using M2 2.2mm screws which hold everything in place sturdily....

i tried to make the entire design as small ad i could but still it is bigger than expected however for the v1 of this build i just need a working prototype and i can impliment a better structure later on

<img width="1920" height="1080" alt="peekabot_pcb_v1 v13" src="https://github.com/user-attachments/assets/418887c4-149d-4bf2-b5dd-26ea3a49fa33" />
<img width="1920" height="1080" alt="peekabot_pcb_v1 v13 PG2" src="https://github.com/user-attachments/assets/34492c1c-b8ce-4a5a-8e6f-f38b9d95e88f" />
<img width="793" height="627" alt="image" src="https://github.com/user-attachments/assets/05de0f6a-f058-44fb-8421-d5b6bff77c95" />

## HOW TO ASSEMBLE IT ##
1. print all the parts in the 3D designs folder
2. get the pcb shipped from anywhere you can use PCBA but soldering everything yourself would be much cheaper
3. put all the SMD components for the pcb put them on the pcb with some solder paste and then put it on a hotplate and let the solder paste melt and all the smd components will be soldered in place
4. now connect 2 li-ion battery in series and solder the output wires and then add a male JST connector
5. now place the pcb in the middle piece 3d print and then screw it on using M2 allen screws
6. then connect the battery JST connector to the PCB
7. then put the esp32 camera on the PCb female header pins
8. now put all the parts together and screw it together with M2 2.2mm 10mm deep screws and refer to the exploded view.avi video for detaled instructions on where to put the screws in 

# EXPLODED VIEW
<img width="755" height="330" alt="Screenshot_2026-04-18_185436-removebg-preview (1)" src="https://github.com/user-attachments/assets/3d2664d1-ac21-4c12-9f4a-ecee83a412d9" />

# ZINE PAGE!
<img width="552" height="791" alt="image" src="https://github.com/user-attachments/assets/1b87a18f-60d2-4c65-b791-b58a14f15983" />




# SOFTWARE USED 
1. arduino ide
2. fusion360
3. kicad
4. canava (for zine page)
5. brain.exe💀

## overall it features a small form factor as it is...afterall a spy/surveilance camera ##

# CREDITS
1. google.com
2. random nerd tutorials
3. arduino forms
4. instructuables
5. chatgpt/claude ai ONLY FOR DEBUGGING OF THE CODE
