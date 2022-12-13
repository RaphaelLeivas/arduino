#include <SoftwareSerial.h>

const int pinoRX = 4; // PINO DIGITAL 4 (RX)
const int pinoTX = 5; // PINO DIGITAL 5 (TX)
const int buttonPin = 2; // PINO DIGITAL 2 - interrupt0
int dadoBluetooth = 0;
int buttonState = 0; 
 
SoftwareSerial bluetooth(pinoRX, pinoTX); 

bool sentHighBluetoothFlag = false;
bool sentLowBluetoothFlag = false;
 
void setup(){
  pinMode(buttonPin, INPUT);

  Serial.begin(9600); 
  bluetooth.begin(9600);
  delay(100); 
}
 
void loop(){
  // if(bluetooth.available()){ //SE O BLUETOOTH ESTIVER HABILITADO, FAZ
  //      dadoBluetooth = bluetooth.read(); //VARIÁVEL RECEBE O VALOR ENVIADO PELO BLUETOOTH
 
  //   if(dadoBluetooth == '1'){ //SE O VALOR RECEBIDO FOR IGUAL A 1, FAZ
  //     Serial.println("LED LIGADO"); //IMPRIME O TEXTO NA SERIAL
  //   }
  //   if(dadoBluetooth == '0'){ //SE O VALOR RECEBIDO FOR IGUAL A 0, FAZ
  //     Serial.println("LED DESLIGADO"); //IMPRIME O TEXTO NA SERIAL
  //   }
  //   if(dadoBluetooth == 'b'){ //SE O VALOR RECEBIDO FOR IGUAL A b, FAZ
  //     Serial.println("LOOP DO LED ATIVADO"); //IMPRIME O TEXTO NA SERIAL
  //   }
  // }

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    if (!sentHighBluetoothFlag) {
      bluetooth.write("testeEnviadoViaHC05 - HIGH");
      bluetooth.write("\n");

      sentHighBluetoothFlag = true;
    }
    sentLowBluetoothFlag = false;
  } else if (buttonState == LOW) {
    if (!sentLowBluetoothFlag) {
      bluetooth.write("testeEnviadoViaHC05 - LOW");
      bluetooth.write("\n");

      sentLowBluetoothFlag = true;
    }
    sentHighBluetoothFlag = false;
  }

  delay(100);
}


