#include <GSM_Client.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(8, 7);
GSM_Client client(mySerial);
const char host[] = "server";
uint16_t port = 8080;
// byte connect_str[] = {0x10, 0x2A, 0x00, 0x06, 0x4D, 0x51, 0x49, 0x73, 0x64, 0x70, 0x03, 0xC2, 0x00, 0x3C, 0x00, 0x04, 0x73, 0x77, 0x61, 0x70, 0x00, 0x08, 0x6E, 0x73, 0x65, 0x6B, 0x73, 0x68, 0x72, 0x62, 0x00,
// 0x0C, 0x38, 0x79, 0x54, 0x45, 0x38, 0x55, 0x63, 0x6f, 0x36, 0x41, 0x79, 0x68, 0x1A};
// byte publish_str[] = {0x30, 0x10, 0x00, 0x04, 0x74, 0x65, 0x73, 0x74, 0x68, 0x65, 0x6C, 0x6C, 0x6F, 0x77, 0x6F, 0x72, 0x6C, 0x64, 0x1A};
void setup() {
  int connection_status = 0;
  Serial.begin(9600);
  delay(100);
  mySerial.begin(9600);
  while (client.connected() != 1)
  {
    connection_status = client.connect( host, port );
    if ( connection_status == 1 )
    {
      client.write(connect_str, sizeof(connect_str));
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  client.write(publish_str, sizeof(publish_str));

}