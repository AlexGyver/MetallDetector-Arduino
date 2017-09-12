/*
   Исходный алгоритм разработан Dzl, 2013 ( http://dzlsevilgeniuslair.blogspot.ru/2013/07/diy-arduino-based-metal-detector.html )
   Переведено, чутка переделано, добавлена куча функций, режимов и кнопок - AlexGyver, 2017
*/

//------------НАСТРОЙКИ-------------
#define sound 1              // 0 - в стиле счётчика гейгера, 1 - пищалка верещалка
#define default_mode 1       // если нет переключателя режимов, то по умолчанию стоит: 1 - статический, 0 - динамический
#define sens_change 1        // 0 - нет регулировки чувствительности, 1 - есть
float SENSITIVITY = 1000.0;  // ручная установка чувствительности
//------------НАСТРОЙКИ-------------


#define soundPin 12
#define resetPinGND 2
#define resetPin 3
#define switchPinGND 9
#define switchPin 10
#define sens 6

#define SET(x,y) (x |=(1<<y))            //-Bit set/clear macros
#define CLR(x,y) (x &= (~(1<<y)))         // |
#define CHK(x,y) (x & (1<<y))             // |
#define TOG(x,y) (x^=(1<<y))              //-+

float koef = 0.5;
unsigned long t0 = 0;
unsigned long last_step;
int t = 0;
unsigned char tflag = 0;
float clf;
int v0 = 0;
float f = 0;
unsigned int FTW = 0;
unsigned int PCW = 0;
unsigned long timer = 0;

// Срабатываем каждые 1000 импульсов с генератора
SIGNAL(TIMER1_COMPA_vect)
{
  OCR1A += 1000;
  t = micros() - t0;
  t0 += t;
  tflag = 1;
}

void setup() {
  Serial.begin(9600);
  pinMode(soundPin, OUTPUT);
  pinMode(resetPin, INPUT_PULLUP);
  pinMode(resetPinGND, OUTPUT);
  digitalWrite(resetPinGND, 0);
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(switchPinGND, OUTPUT);
  digitalWrite(switchPinGND, 0);

  //-Set up counter1 to count at pin 5
  TCCR1A = 0;
  TCCR1B = 0x07;
  SET(TIMSK1, OCF1A);
}

// функция модуля
float absf(float f)
{
  if (f < 0.0)
    return -f;
  else
    return f;
}

void loop() {
  if (tflag)  {
    Serial.print("$");
    Serial.print(f);
    Serial.println(";");

    if (digitalRead(switchPin) == default_mode) {   // если кнопка режимов не нажата
      if (!digitalRead(resetPin))                   // если нажата кнопка сброса частоты
        v0 = t;                                     // запомнить текущую частоту
    } else {                                        // нажат другой режим
      if (millis() - last_step > 300) {             // каждые 300 мсек
        last_step = millis();                       // таймер
        v0 = v0 * koef + (1 - koef) * t;            // плавно сбрасываем частоту
      }
    }
    f = f * 0.85 + absf(t - v0) * 0.15;             // фильтруем сигнал 

    if (sens_change)                                // если разрешено внешнее изменение чувствительности
      SENSITIVITY = map(analogRead(sens), 0, 1023, 500, 2000);        // принять с аналогового пина, преобразовать
    clf = f * SENSITIVITY;                          // конвертация частоты в писк
    if (clf > 10000)
      clf = 10000;
    FTW = clf;
    tflag = 0;                //-Reset flag
  }

  if (sound) {
    if (millis() > timer) {
      timer += 10;
      PCW += FTW;
      if (PCW & 0x8000)
      {
        digitalWrite(13, HIGH);
        PCW &= 0x7fff;
      }
      else
        digitalWrite(13, LOW);
    }
  } else {
    if (millis() > timer) {
      timer += 10;
      PCW += FTW;
      if (PCW & 0x8000)
      {
        PCW &= 0x7fff;
        tone(soundPin, 3000, 30); // Play over pin D13 tone, pitch
        delay(20); // delay in between
        noTone(soundPin); // Stop tone
      }
      else
        noTone(soundPin); // Stop tone
    }
  }

}
