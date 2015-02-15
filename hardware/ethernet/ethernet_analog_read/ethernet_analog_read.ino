/*
  Analog read
  
  Read a value from a Arduino sensor and publish
  it in a web page.
  
  Note: you can set up the NIC with DHCP or static address
  
  */

#include <EtherCard.h>

// ethernet interface mac address, must be unique on the LAN
static byte mymac[] = { 
  0x74,0x69,0x69,0x2D,0x30,0x31 };
//static byte myip[] = { 192,168,0,100 };

byte Ethernet::buffer[500];
BufferFiller bfill;

// Analog vars:
int analogSensor = A0;
int sensorRead = 0;

void setup () {
  /* Static IP code
  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0)
   Serial.println( "Failed to access Ethernet controller");
   ether.staticSetup(myip);
   
   
   
   */
   // DHC code 
  Serial.begin(57600);
  Serial.println("\n[getDHCPandDNS]");
  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0) 
    Serial.println( "Failed to access Ethernet controller");

  if (!ether.dhcpSetup())
    Serial.println("DHCP failed");
}

static word homePage() {
  bfill = ether.tcpOffset();
  bfill.emit_p(PSTR(
  "HTTP/1.0 200 OK\r\n"
    "Content-Type: text/html\r\n"
    "Pragma: no-cache\r\n"
    "\r\n"
    "<meta http-equiv='refresh' content='1'/>"
    "<title>Arduino WebServer</title>"
    "<h1>Arduino analog Read</h1>"
    "<p>Analog Value from Arduino: $D</p>"),
    sensorRead );
  return bfill.position();
}

void loop () {
  sensorRead = analogRead(analogSensor);

  word len = ether.packetReceive();
  word pos = ether.packetLoop(len);

  if (pos)  // check if valid tcp data is received
    ether.httpServerReply(homePage()); // send web page data
}


