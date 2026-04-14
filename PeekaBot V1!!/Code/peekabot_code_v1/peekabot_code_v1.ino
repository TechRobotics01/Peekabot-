#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <esp_camera.h>
#include <ArduinoJson.h>

#define CAMERA_MODEL_AI_THINKER

#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27
#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22
#define LED_GPIO_NUM      4

const char* ssid = "Redmi_Note_10T_5G";
const char* password = "88888888";
const char* bottoken = "8618369274:AAHw-g_aMBWGjgkCW_63dtZRbnBc93KkUzM";

WiFiClientSecure secured_client;
UniversalTelegramBot bot(bottoken, secured_client);

const unsigned long BOT_MTBS = 1000;
unsigned long bot_lasttime;

camera_fb_t *fb = NULL;

bool isMoreDataAvailable();
byte *getNextBuffer();
int getNextBufferLen();

bool dataAvailable = false;
bool autoflash = true;

void setflash(bool state){
  digitalWrite(LED_GPIO_NUM, state ? HIGH : LOW);
}

void setquality(int quality){
  sensor_t *s = esp_camera_sensor_get();
  if(s){
    s->set_quality(s, quality);
  }
}

void handleNewMessages(int numNewMessages){
  for (int i = 0; i < numNewMessages; i++){

    String chat_id = String(bot.messages[i].chat_id);
    String text = bot.messages[i].text;

    if(text == "/photo"){

      if(autoflash){
        setflash(true);
        delay(200);
      }

      // Flush both buffered frames (fb_count=2)
      for(int j = 0; j < 2; j++){
        camera_fb_t *discard = esp_camera_fb_get();
        if(discard){
          esp_camera_fb_return(discard);
        }
      }

      // Wait for fresh frame to be captured
      delay(100);

      // Get the fresh frame
      fb = esp_camera_fb_get();

      if(autoflash){
        setflash(false);
      }

      if(!fb){
        bot.sendMessage(chat_id, "Camera capture failed", "");
        return;
      }

      dataAvailable = true;

      bot.sendPhotoByBinary(chat_id, "image/jpeg", fb->len,
                            isMoreDataAvailable, nullptr,
                            getNextBuffer, getNextBufferLen);

      esp_camera_fb_return(fb);
    }

    if (text == "/start"){
      String welcome = "Welcome to *Peekabot*\n\n";
      welcome += "Use /help to see commands";
      bot.sendMessage(chat_id, welcome, "Markdown");
    }

    if(text == "/flash on"){
      setflash(true);
      bot.sendMessage(chat_id, "Flash ON", "");
    }

    if(text == "/flash off"){
      setflash(false);
      bot.sendMessage(chat_id, "Flash OFF", "");
    }

    if(text.startsWith("/quality")){
      int q = text.substring(9).toInt();

      if(q >= 10 && q <= 63){
        setquality(q);
        bot.sendMessage(chat_id, "Quality set to " + String(q), "");
      } else {
        bot.sendMessage(chat_id, "Enter value between 10-63", "");
      }
    }

    if(text == "/autoflash on"){
      autoflash = true;
      bot.sendMessage(chat_id, "Auto Flash ON", "");
    }

    if(text == "/autoflash off"){
      autoflash = false;
      bot.sendMessage(chat_id, "Auto Flash OFF", "");
    }

    if(text == "/help"){
      String help = "*Peekabot Commands*\n\n";
      help += "/start - Start bot\n";
      help += "/photo - Take photo\n";
      help += "/flash on/off - Control flash\n";
      help += "/autoflash on/off - Auto flash control\n";
      help += "/quality X - Set quality (10-63)\n";

      bot.sendMessage(chat_id, help, "Markdown");
    }
  }
}

bool isMoreDataAvailable(){
  return dataAvailable;
}

byte *getNextBuffer(){
  dataAvailable = false;
  return fb ? fb->buf : nullptr;
}

int getNextBufferLen(){
  return fb ? fb->len : 0;
}

void setup(){
  Serial.begin(115200);

  pinMode(LED_GPIO_NUM, OUTPUT);
  digitalWrite(LED_GPIO_NUM, LOW);

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sccb_sda = SIOD_GPIO_NUM;
  config.pin_sccb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_VGA;
  config.jpeg_quality = 10;
  config.fb_count = 2;

  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;

  esp_camera_init(&config);

  WiFi.begin(ssid, password);
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT);

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
  }

  configTime(0, 0, "pool.ntp.org");

  bot.longPoll = 60;
}

void loop(){

  if (millis() - bot_lasttime > BOT_MTBS){
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages){
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }

    bot_lasttime = millis();
  }
}