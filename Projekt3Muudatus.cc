// C++ code
//
const int sensorPin = A0;
const float baselineTemp = 20.0;
void setup(){
	Serial.begin(9600); // open a serial port
for(int pinNumber = 2; pinNumber<7; pinNumber++){
		pinMode(pinNumber,OUTPUT);
		digitalWrite(pinNumber, LOW);
	}
}
void loop(){
	int sensorVal = analogRead(sensorPin);
    Serial.print("Sensor Value: ");
    Serial.print(sensorVal);
	// convert the ADC reading to voltage
	float voltage = (sensorVal/1024.0) * 5.0;
    Serial.print(", Volts: ");
    Serial.print(voltage);
	Serial.print(", degrees C: ");
	// convert the voltage to temperature in degrees
	float temperature = (voltage - .25) * 200;
	Serial.println(temperature);
	if(temperature < baselineTemp){
		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
      	digitalWrite(5, LOW);
      	digitalWrite(6, LOW);
    }else if(temperature >= baselineTemp+2 &&
		temperature < baselineTemp+4){
		digitalWrite(2, HIGH);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
      	digitalWrite(5, LOW);
      	digitalWrite(6, LOW);
	}else if(temperature >= baselineTemp+4 &&
        temperature < baselineTemp+16){
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
      	digitalWrite(5, LOW);
      	digitalWrite(6, LOW);
	}else if(temperature >= baselineTemp+8 &&
        temperature < baselineTemp+64){
		digitalWrite(2, HIGH);
		digitalWrite(3, HIGH);
		digitalWrite(4, HIGH);
      	digitalWrite(7, LOW);
      	digitalWrite(6, LOW);
	}else if(temperature >= baselineTemp+16 &&
        temperature < baselineTemp+128){
      	digitalWrite(2, HIGH);
		digitalWrite(3, HIGH);
		digitalWrite(4, HIGH);
      	digitalWrite(5, HIGH);
      	digitalWrite(6, LOW);
    }else if(temperature >= baselineTemp+32 &&
        temperature < baselineTemp+256){
      	digitalWrite(2, HIGH);
		digitalWrite(3, HIGH);
		digitalWrite(4, HIGH);
      	digitalWrite(5, HIGH);
      	digitalWrite(6, HIGH);
    }
	delay(1);
}