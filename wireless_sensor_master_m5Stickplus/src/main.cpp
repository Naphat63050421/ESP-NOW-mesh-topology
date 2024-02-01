#include "M5StickCPlus.h"
#include <esp_now.h>
#include "WiFi.h"

#define LENGTH_OFF_MACADDRS 6
#define BAUD_RATE 115200
typedef struct struct_message
{
  String num_node;
  String temperature_string;

} struct_message;

String recv_num_node = "node: ";
String recv_temperature_message = "00.0";


// Create a struct_message called myData
struct_message my_message;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len)
{
  memcpy(&my_message, incomingData, sizeof(my_message));
  // Serial.print("device_node: ");
  recv_num_node = my_message.num_node;
  recv_temperature_message = my_message.temperature_string;

  if (recv_num_node == "node:1")
  {
    M5.Lcd.setCursor(10, 10);
    M5.Lcd.print(recv_num_node);
    M5.Lcd.setCursor(10, 20);
    M5.Lcd.print("temperature: ");
    M5.Lcd.setCursor(87, 20);
    M5.Lcd.print(recv_temperature_message);
    M5.Lcd.setCursor(120, 20);
    M5.Lcd.print("C");
  }
  else if (recv_num_node == "node:2")
  {
    M5.Lcd.setCursor(10, 33);
    M5.Lcd.print(recv_num_node);
    M5.Lcd.setCursor(10, 43);
    M5.Lcd.print("temperature: ");
    M5.Lcd.setCursor(87, 43);
    M5.Lcd.print(recv_temperature_message);
    M5.Lcd.setCursor(120, 43);
    M5.Lcd.print("C");
  }
  else if (recv_num_node == "node:3")
  {
    M5.Lcd.setCursor(10, 56);
    M5.Lcd.print(recv_num_node);
    M5.Lcd.setCursor(10, 66);
    M5.Lcd.print("temperature: ");
    M5.Lcd.setCursor(87, 66);
    M5.Lcd.print(recv_temperature_message);
    M5.Lcd.setCursor(120, 66);
    M5.Lcd.print("C");
  }
  else
  {
    // noting
  }
}

void setup()
{
  Serial.begin(BAUD_RATE);
  M5.begin();
  M5.Lcd.setRotation(1);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(YELLOW, BLACK);

  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK)
  {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  M5.Lcd.setCursor(10, 10);
  M5.Lcd.print(recv_num_node);
  M5.Lcd.setCursor(10, 20);
  M5.Lcd.print("temperature: ");
  M5.Lcd.setCursor(87, 20);
  M5.Lcd.print(recv_temperature_message);
  M5.Lcd.setCursor(120, 20);
  M5.Lcd.print("C");

  M5.Lcd.setCursor(10, 33);
  M5.Lcd.print(recv_num_node);
  M5.Lcd.setCursor(10, 43);
  M5.Lcd.print("temperature: ");
  M5.Lcd.setCursor(87, 43);
  M5.Lcd.print(recv_temperature_message);
  M5.Lcd.setCursor(120, 43);
  M5.Lcd.print("C");

  M5.Lcd.setCursor(10, 56);
  M5.Lcd.print(recv_num_node);
  M5.Lcd.setCursor(10, 66);
  M5.Lcd.print("temperature: ");
  M5.Lcd.setCursor(87, 66);
  M5.Lcd.print(recv_temperature_message);
  M5.Lcd.setCursor(120, 66);
  M5.Lcd.print("C");

  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);
}

void loop()
{
}
