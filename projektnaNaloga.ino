const int pinTipka12 = 12;
const int pinTipka10 = 10;
const int pinTipka11 = 11;
const int pinTipka9 = 9;

// Definicija pinov za LED-diode
const int pinZelenaLED = 6;
const int pinModraLED = 7;
const int pinRdecaLED = 5;

// Spremenljivke za sledenje stanju tipk
int stanjeTipka12 = 0;
int stanjeTipka10 = 0;
int stanjeTipka11 = 0;
int stanjeTipka9 = 0;

// Spremenljivke za sledenje stanja LED-diod
bool zelenaLEDVklopljena = false;
bool modraLEDVklopljena = false;
bool rdecaLEDVklopljena = false;

void setup() {
  // Nastavitev pinov za tipke kot vhodne
  pinMode(pinTipka12, INPUT);
  pinMode(pinTipka10, INPUT);
  pinMode(pinTipka11, INPUT);
  pinMode(pinTipka9, INPUT);

  // Nastavitev pinov za LED-diode kot izhodne
  pinMode(pinZelenaLED, OUTPUT);
  pinMode(pinModraLED, OUTPUT);
  pinMode(pinRdecaLED, OUTPUT);
}

void loop() {
  // Branje stanja tipk
  stanjeTipka12 = digitalRead(pinTipka12);
  stanjeTipka10 = digitalRead(pinTipka10);
  stanjeTipka11 = digitalRead(pinTipka11);
  stanjeTipka9 = digitalRead(pinTipka9);

  // Vklop/zaklop zelene LED-diode ob pritisku tipke 12
  if (stanjeTipka12 == HIGH) {
    if (!zelenaLEDVklopljena) {
      digitalWrite(pinZelenaLED, HIGH);
      zelenaLEDVklopljena = true;
    }
  } else {
    zelenaLEDVklopljena = false;
  }

  // Vklop/zaklop modre LED-diode in izklop zelene LED-diode ob pritisku tipke 10
  if (stanjeTipka10 == HIGH) {
    if (!modraLEDVklopljena) {
      digitalWrite(pinModraLED, HIGH);
      digitalWrite(pinZelenaLED, LOW);
      modraLEDVklopljena = true;
      zelenaLEDVklopljena = false;
    }
  } else {
    modraLEDVklopljena = false;
  }

  // Vklop/zaklop rdeče LED-diode ob pritisku tipke 11
  if (stanjeTipka11 == HIGH) {
    if (!rdecaLEDVklopljena) {
      digitalWrite(pinRdecaLED, HIGH);
      rdecaLEDVklopljena = true;
    }
  } else {
    rdecaLEDVklopljena = false;
  }

  // Izklop modre LED-diode ob pritisku tipke 9
  if (stanjeTipka9 == HIGH) {
    digitalWrite(pinModraLED, LOW);
    modraLEDVklopljena = false;
  }


}