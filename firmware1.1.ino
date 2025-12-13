#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Definir la dirección I2C del display LCD 
#define I2C_ADDR 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

// Definición de pines
const int buttonUpPin = D3;
const int buttonDownPin = D4;
const int buttonSelectPin = D6;
const int buttonActionPin = D7;
const int servoPin = D5;

// Variables
int value = 100;
int selectedValue = 0;
boolean isSelected = false;
boolean actionButtonPressed = false;

Servo myServo;
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_ROWS);

void setup() {
  // Configurar pines de botones como entrada con pull-up interno
  pinMode(buttonUpPin, INPUT_PULLUP);
  pinMode(buttonDownPin, INPUT_PULLUP);
  pinMode(buttonSelectPin, INPUT_PULLUP);
  pinMode(buttonActionPin, INPUT_PULLUP);

  // Configurar pin del servo
  myServo.attach(servoPin);

  // Inicializar el display LCD
  Wire.begin(D2, D1); // SDA = D2, SCL = D1
  lcd.init();
  lcd.backlight(); // Encender la luz de fondo
  lcd.setCursor(0, 0);
  lcd.print("Contador de pasos");
  lcd.setCursor(0, 1);
  lcd.print(" Firmware 1.0");
  delay(1000); //Espera 1 seg
  lcd.clear();
  lcd.print("E.G.S Electronica");
  delay(1000); //Espera 1 seg

  // Posición inicial del servo
  myServo.write(0);

  Serial.begin(115200);

  // Mostrar valor inicial 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Valor: ");
  lcd.setCursor(0, 1);
  lcd.print(value);
}

void loop() {
  // Leer estado de los botones
  int buttonUpState = digitalRead(buttonUpPin);
  int buttonDownState = digitalRead(buttonDownPin);
  int buttonSelectState = digitalRead(buttonSelectPin);
  int buttonActionState = digitalRead(buttonActionPin);

  // Incrementar valor si se presiona botón de subir
  if (buttonUpState == LOW) {
    value++;
    Serial.print("Value: ");
    Serial.println(value);
    lcd.setCursor(0, 1);
    lcd.print("                "); // Limpiar línea
    lcd.setCursor(0, 1);
    lcd.print(value);
    delay(200); // Debounce
  }

  // Decrementar valor si se presiona botón de bajar
  if (buttonDownState == LOW) {
    value--;
    Serial.print("Value: ");
    Serial.println(value);
    lcd.setCursor(0, 1);
    lcd.print("                "); // Limpiar línea
    lcd.setCursor(0, 1);
    lcd.print(value);
    delay(200); // Debounce
  }

  // Seleccionar valor si se presiona botón de seleccionar
  if (buttonSelectState == LOW) {
    selectedValue = value;
    isSelected = true;
    Serial.print("Selected Value: ");
    Serial.println(selectedValue);
    lcd.setCursor(0, 0);
    lcd.print("Seleccionado:   ");
    lcd.setCursor(0, 1);
    lcd.print("                "); // Limpiar línea
    lcd.setCursor(0, 1);
    lcd.print(selectedValue);
    delay(200); // Debounce
  }

  // Accionar si se presiona botón de acción
  if (buttonActionState == LOW && isSelected) {
    if (!actionButtonPressed) {
      actionButtonPressed = true;

      if (selectedValue > 0) {
        selectedValue--;
        Serial.print("Counting down: ");
        Serial.println(selectedValue);
        lcd.setCursor(0, 1);
        lcd.print("                "); // Limpiar línea
        lcd.setCursor(0, 1);
        lcd.print(selectedValue);
        delay(200); // Debounce
      }

      if (selectedValue == 0) {
        // Accionar servo
        myServo.write(180); // Mover a 90 grados
        delay(1000); // Esperar 1 segundo
        myServo.write(0); // Regresar a 0 grados
        isSelected = false; // Resetear selección
        lcd.setCursor(0, 0);
        lcd.print("Valor:          ");
        lcd.setCursor(0, 1);
        lcd.print("                "); // Limpiar línea
        lcd.setCursor(0, 1);
        lcd.print(value);
      }
    }
  } else {
    actionButtonPressed = false;
  }
}
