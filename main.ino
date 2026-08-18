void setup()
{
  pinMode(13, OUTPUT); // red
  pinMode(12, OUTPUT); // yellow
  pinMode(11, OUTPUT); // green
  
  // pedestrian RGB light
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  
  pinMode(7, OUTPUT); // straight road left turn
  pinMode(6, OUTPUT); // merging road left turn
  
  pinMode(4, INPUT); // ECHO
  pinMode(3, OUTPUT); // TRIG

  pinMode(2, INPUT);    // pedestrian button
}

int getDistance()
{
  digitalWrite(3, LOW);
  delayMicroseconds(2);

  digitalWrite(3, HIGH);
  delayMicroseconds(10);

  digitalWrite(3, LOW);

  long duration = pulseIn(4, HIGH);

  int distance = duration * 0.0133 / 2; // convert to inches

  return distance;
}

void loop()
{
  // GREEN LIGHT
  digitalWrite(11, HIGH);
  
  for (int i = 0; i < 250; i++)
  {
    int ped = digitalRead(2); // loop to keep scanning for pedestrians
    if (ped == HIGH)
    {
      pedestrian();
      return;
    }
    delay(10); // regular delay if no pedestrian
  }
  digitalWrite(11, LOW);
  // YELLOW LIGHT
  digitalWrite(12, HIGH);
  
  for (int i = 0; i < 150; i++)
  {
    int ped = digitalRead(2);
    if (ped == HIGH)
    {
      pedestrian();
      return;
    }
    delay(10);
  }
  digitalWrite(12, LOW);
  // RED LIGHT
  digitalWrite(13, HIGH);
  
  for (int i = 0; i < 100; i++)
  {
    int ped = digitalRead(2);
    if (ped == HIGH)
    {
      pedestrian();
      return;
    }
    delay(10);
  }
  digitalWrite(13, LOW);
  // STRAIGHT ROAD TURN
  digitalWrite(13, HIGH);
  digitalWrite(7, HIGH);
  
  int turnTime = 2000;
  int distance = getDistance();
  if (distance <= 53)
  {
    turnTime = 5000;
  }

  for (int i = 0; i < turnTime / 10; i++) // dynamic turn times based off distance
  {
    int ped = digitalRead(2);

    if (ped == HIGH)
    {
      pedestrian();
      return;
    }

    delay(10);
  }
  digitalWrite(13, LOW);
  digitalWrite(7, LOW);
  // MERGING ROAD TURN
  digitalWrite(13, HIGH);
  digitalWrite(6, HIGH);
  
  turnTime = 2000;
  distance = getDistance();
  if (distance <= 53)
  {
    turnTime = 5000;
  }

  for (int i=0; i < turnTime / 10; i++)
  {
    int ped = digitalRead(2);

    if (ped == HIGH)
    {
      pedestrian();
      return;
    }

    delay(10);
  }
  digitalWrite(13, LOW);
  digitalWrite(6, LOW);
  
}

void pedestrian()
{
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW); // turn off all lights except red
  digitalWrite(11, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  setColor(255, 0, 168); // set to yellow caution
  delay(1000);
  setColor(0, 0, 0); // reset color
  
  setColor(255, 255, 255);// set white proceed
  
  delay(3000);
  setColor(255, 0, 168); // yellow caution
  delay(1000);
  setColor(0, 0, 0); // lights off
}

void setColor(int red, int blue, int green)
{
  analogWrite(10, red);
  digitalWrite(9, green);
  analogWrite(8, blue);
}
