#include <Wire.h> 
#include <LiquidCrystal_I2C.h>  // I2C kütüphanesini verdiğim linkten indirip   include edebilirsiniz
LiquidCrystal_I2C lcd(0x27,16,2); 
int sclPin=A5; // Arduino Serial lcd pinleri
int sdaPin=A4;
byte trigger = 12; // Sensörün Trigger bacağının bağlı olduğu pin
byte echo = 13; // Sensörün Echo bacağının bağlı olduğu pin

const int trigger_pin = 12; //12. pini  trigger pin olarak tanımladık.
 
const int echo_pin = 13; //13. pini echo pin  olarak tanımladık.
 
const int aled = 2; //2. pini aled  olarak tanımladık.
 
const int bled = 3; //3. pini bled  olarak tanımladık.
 
const int cled = 4; //4. pini cled  olarak tanımladık.
 
const int dled = 5; //5. pini dled  olarak tanımladık.
 
const int buzzer = 6; //6. pini buzzer  olarak tanımladık.
 
int sure ; //sure adlı bir değişken tanımladık.
 
int mesafe ; //mesafe adlı bir değişken tanımladık.
void setup() {
  pinMode(trigger, OUTPUT); //3. yani trigpini çıkış olarak ayarlıyoruz
  pinMode(echo, INPUT); //2. pin echo input ayarlanır
  lcd.init();                      // initialize the lcd 
 // Print a message to the LCD.
 lcd.backlight();
 
 pinMode(aled , OUTPUT); //aled'i çıkış olarak tanımladık.
 
pinMode(bled , OUTPUT); //bled'i çıkış olarak tanımladık.
 
pinMode(cled , OUTPUT); //cled'i çıkış olarak tanımladık.
 
pinMode(dled , OUTPUT); //dled'i çıkış olarak tanımladık.
 
pinMode(buzzer , OUTPUT); //buzzer'i çıkış olarak tanımladık.
 
pinMode(trigger_pin , OUTPUT); //trigger pin'i çıkış olarak tanımladık.
 
pinMode(echo_pin , INPUT); //echo pin'i giriş olarak tanımladık.

  // LCD Başlangıç ayarları
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);        // 1.satır
  lcd.print("MESAFE"); // 1.satır metin
  lcd.setCursor(0, 1);        // 2.satır
  lcd.print("0");       // 2.satır metin
  lcd.display();    // LCD Ekranı Göster
}

void loop() {
   lcd.setCursor(0, 1); //Kursoru ikinci satır birinci sütuna getiriyoruz
  lcd.print("                "); //Ekranı temizlemek için 16 boşluk yazdırıyoruz.
  lcd.setCursor(0, 1); //Kursoru tekrardan ikinci satır birinci sütuna getiriyoruz
  lcd.print("Mesafe ");
  lcd.setCursor(7, 1); //satırın başında mesafe yazdığı için kursoru 7. sütuna götörüyoruz
  lcd.print(String(mesafe) + " cm"); //Ölçülen mesafeyi yazdırıyoruz

  
digitalWrite(trigger_pin , HIGH); //trigger pin'e enerji verdik.
 
delayMicroseconds(1000); //mesafeyi ölçmesini sağladık.
 
digitalWrite(trigger_pin , LOW); //trigger pinin enerjisini kestik.
 
sure = pulseIn(echo_pin , HIGH); //sure değişkenin echo pin'in değiştirmesini sağladık.
 
mesafe = (sure / 2) / 29.1;
 

 
if (mesafe <= 15) //mesafemiz 10 cm den kısa ise bunları yapar.
 
{
 
digitalWrite(aled , HIGH); //aled'e enerji verdik.
 
digitalWrite(bled , HIGH); //bled'e enerji verdik.
 
digitalWrite(cled , HIGH); //cled'e enerji verdik.
 
digitalWrite(dled , HIGH); //dled'e enerji verdik.
 
digitalWrite(buzzer , HIGH); //buzzer'e enerji verdik.
 
delay(500); //0,25 saniyede bir tekrarlanmasını sağladık.
 
digitalWrite(buzzer , LOW); //buzzer'in enerjisini kestik.
 
}
 
else if (mesafe <= 35) //mesafemiz 25 cm den kısa ise bunları yapar.
 
{
 
digitalWrite(aled , LOW); //aled'in enerjisini kestik.
 
digitalWrite(bled , HIGH); //bled'e enerji verdik.
 
digitalWrite(cled , HIGH); //cled'e enerji verdik.
 
digitalWrite(dled , HIGH); //dled'e enerji verdik.
 
digitalWrite(buzzer , HIGH); //buzzer'e enerji verdik.
 
delay(750); //0,50 saniyede bir tekrarlanmasını sağladık
 
digitalWrite(buzzer , LOW); //buzzer'in enerjisini kestik.
 
}
 
else if ( mesafe <= 55) //mesafemiz 50 cm den kısa ise bunları yapar.
 
{
 
digitalWrite(aled , LOW); //aled'in enerjisini kestik.
 
digitalWrite(bled , LOW); //bled'in enerjisini kestik.
 
digitalWrite(cled , HIGH); //cled'e enerji verdik.
 
digitalWrite(dled , HIGH); //dled'e enerji verdik.
 
digitalWrite(buzzer , HIGH); //buzzer'e enerji verdik.
 
delay(1000); //0,75 saniyede bir tekrarlanmasını sağladık
 
digitalWrite(buzzer , LOW); //buzzer'in enerjisini kestik.
 
}
 
else //alan boş ise bunu yapar
 
{
 
digitalWrite(aled , LOW); //aled'in enerjisini kestik.
 
digitalWrite(bled , LOW); //bled'in enerjisini kestik.
 
digitalWrite(cled , LOW); //cled'in enerjisini kestik.
 
digitalWrite(dled , HIGH); //dled'e enerji verdik.
 
}
    delay(250); //250 milisaniye bekletiyoruz.

}

