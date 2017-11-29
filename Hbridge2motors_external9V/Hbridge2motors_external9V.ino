/**
* Copyright © 2017 Psecto, Psecto Productions ltd, Mihai FLOARES
*/

//Arduino + H bridge 2 powered Motors with separate 9V power supply used to control Lego Technics Robotic arm

// Define Arduino pins

const int Claw1 = 2;                
const int Claw2 = 5;                 
const int EnableClaw = 9;

const int Piston1 = 6;              
const int Piston2 = 8;                  
const int EnablePiston = 3;


// Set pins as output

void setup()
{
  pinMode(EnableClaw, OUTPUT);  
  pinMode(Claw1, OUTPUT);     
  pinMode(Claw2, OUTPUT);

  pinMode(EnablePiston, OUTPUT); 
  pinMode(Piston1, OUTPUT);     
  pinMode(Piston2, OUTPUT);     
}

//Actions

void loop()
{
      digitalWrite(Claw1, HIGH);
      digitalWrite(Claw2, LOW);    
      digitalWrite(EnableClaw, HIGH);
      delay(2000);
      digitalWrite(EnableClaw, LOW);
      delay(5000);

      digitalWrite(Piston1, HIGH);
      digitalWrite(Piston2, LOW);    
      digitalWrite(EnablePiston, HIGH);
      delay(3000);
      digitalWrite(EnablePiston, LOW);
      delay(5000);      

      digitalWrite(Claw1, LOW);
      digitalWrite(Claw2, HIGH);    
      digitalWrite(EnableClaw, HIGH);
      delay(14000);
      digitalWrite(EnableClaw, LOW);
      delay(2000);

      digitalWrite(Piston2, HIGH);
      digitalWrite(Piston1, LOW);    
      digitalWrite(EnablePiston, HIGH);
      delay(2000);
      digitalWrite(EnablePiston, LOW);
      delay(2000);
         
   }

