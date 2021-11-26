
///////////////////////////////////////////////////////////////////////////////////
//      Napco Magnum 1008e alarm systems keybus monitor
//      tested on models : Magnum 1008e
///////////////////////////////////////////////////////////////////////////////////

#define BUS_CLK             5
#define BUS_DATA            6

int totalDelayUs = 0;
int clkCount = 0;
String packet = "";
String previousPacket = "";


void setup() {
  
  pinMode(BUS_CLK, INPUT);
  pinMode(BUS_DATA, INPUT);
  Serial.begin(115200);

}

void loop() {
  Serial.println("-- Starting -- ");
  loopback();
}

void loopback() {

    while(1) {
//      for(int n=0; n<=3; n++) {    //for better noise tolerance
        waitForPause();
        waitForPackageStart();
  //      displayClockCount();
        packet = readPacket();
        delayMicroseconds(50);
//      }
      String pkt = "";
      for (int n=0; n<packet.length(); n++) {
        if (n%8 == 0) {
        pkt = pkt + " ";
        }
        pkt = pkt + String(packet[n]);
      }

      Serial.print(pkt + " ");
      if(!packet.equals(previousPacket)) {
        processPacket();
        previousPacket = packet;
      }
      Serial.println();
      delayMicroseconds(150);
    }
}

void processPacket() {
  int bitNum = 0;
   while (bitNum < 47) {
    if(packet.charAt(bitNum) != previousPacket.charAt(bitNum) && packet.charAt(bitNum) == '0') {
      switch(bitNum) {
        case 0: Serial.print("TRBL pressed"); break;
        case 2: Serial.print("4 pressed"); break;
        case 4: Serial.print("5 pressed"); break;
        case 6: Serial.print("6 pressed"); break;
        case 8: Serial.print("2nd pressed"); break;
        case 10: Serial.print("1 pressed"); break;
        case 12: Serial.print("2 pressed"); break;
        case 14: Serial.print("3 pressed"); break;
        case 16: Serial.print("BYP pressed"); break;
        case 18: Serial.print("0-10 pressed"); break;
        case 20: Serial.print("11-Stay pressed"); break;
        case 22: Serial.print("12-Away pressed"); break;
        case 24: Serial.print("MEM pressed"); break;
        case 26: Serial.print("7 pressed"); break;
        case 28: Serial.print("8 pressed"); break;
        case 30: Serial.print("9 pressed"); break;
        case 42: Serial.print("CLEAR pressed"); break;
        case 44: Serial.print("ENTER pressed"); break;
      }
    }

    bitNum++;
  }
}




String readPacket() {
  clkCount=0;
  int dataBit=0;
//  char value;
  String packet ="";
  while(1) {
    int val = digitalRead(BUS_CLK);
    if(val == HIGH) {

      
      delayMicroseconds(100);
      
      val = digitalRead(BUS_CLK);
        if(val == HIGH) {
                totalDelayUs=0;
      clkCount++;
        
      dataBit = digitalRead(BUS_DATA);
      
      if(previousPacket.length() < 48)
        previousPacket.concat(String(dataBit));

      packet.concat(String(dataBit));
      
      while(1) {
        val = digitalRead(BUS_CLK);
        if(val == LOW) {
          //button pushed
          delayMicroseconds(100);
          val = digitalRead(BUS_CLK);
          if(val == LOW) {
            dataBit = digitalRead(BUS_DATA);
  
            if(previousPacket.length() < 48)
              previousPacket.concat(String(dataBit));
            
            packet.concat(String(dataBit));
                
            break;
          }
        }
        delayMicroseconds(3);
      }
    } 
    }
    delayMicroseconds(25);
    totalDelayUs+=25;
    if (totalDelayUs >= 1250) {
      totalDelayUs = 0;
      return packet;
//      return clkCount;
    }
  }
}

void waitForPause() {
  while(1) {
    int val = digitalRead(BUS_CLK);
    
    if(val == HIGH) {
      delayMicroseconds(150);
      totalDelayUs = 0;
    } else {
      
      delayMicroseconds(50);
      totalDelayUs+=50;
      if (totalDelayUs >= 2000) {
        totalDelayUs = 0;
        return;
      }
    }
  }
}

void waitForPackageStart() {
  while(1) {
    int val = digitalRead(BUS_CLK);
    if(val == HIGH) {
      return;
    } 
    delayMicroseconds(2);
  }
}

int displayClockCount() {
  clkCount=0;
  while(1) {
    int val = digitalRead(BUS_CLK);
    if(val == HIGH) {
      totalDelayUs=0;
      clkCount++;
      while(1) {
        val = digitalRead(BUS_CLK);
        if(val == LOW) break;
        delayMicroseconds(50);
      }
    } 
    delayMicroseconds(50);
    totalDelayUs+=50;
    if (totalDelayUs >= 1000) {
      totalDelayUs = 0;
      return clkCount;
    }
  }
}
