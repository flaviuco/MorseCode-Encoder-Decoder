//dot: 40 ms | dash: 120 ms => 30 cuv pe min
//dot: 50 ms | dash: 150 ms => 35 cuv pe min
// 
#define TIME_UNIT 50
#define MIN_TIME 20  //filtrarea semnalelor incorecte primite de la buton
#define MORSE_CODE_SIZE 26
#define MORSE_NUMBER_SIZE 10
const int ledPin = 24;
const int buzzerPin = 52;
const int buttonPin = 38;

//Reguli:
//dupa fiecare simbol al unei litere urmeaza un TIME_UNIT
//dupa fiecare litera urmeaza 3 TIME_UNIT-uri
//dupa fiecare cuvant urmeaza 7 TIME_UNIT-uride
//presupunem ca dupa fiecare litera urmeaza o alta litera, astfel dupga fiecare litera utilizam
//un delay de 3* TIME_UNIT, iar daca este un spatiu vom completa nr de TIME_UNIT-uri pana la 7
const int dotlength = TIME_UNIT;  //50 de ms
const int dashlength = 3 * TIME_UNIT;  //150 ms
const int symbolGap = TIME_UNIT;
const int letterGap = 3 * TIME_UNIT;
//completam TIME_UNIT pana la 7
const int wordGap = 4 * TIME_UNIT;  //daca e spatiu se mai adauga inca 7 time unituri

const int letterGap2 = 600; //400

//PENTRU DECODER
int buttonState = 1;               // starea curenta a butonului -> la inceput este 1(folosind un INPUT_PULLUP activarea este inversa)
int lastButtonState = 1;           // starea anterioara a butonului
unsigned long startPressed = 0;    // momentul in care butonul a fost apasat
unsigned long endPressed = 0;      // momentul in care butonul o fost lasat
unsigned long holdTime = 0;        // cat timp o fost apasat butonul
String letterCode ="";             // codificarea literei in cod morse


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  //folosim pull-up-ul intern din placuta
}

void loop() {
  if(Serial.available() > 0){
    String text = Serial.readString();  //citim un string de la monitorul serial
    if(!isEmpty(text)){
      Serial.print(text);  //trebuie setat din monitorul serial sa nu adauge newLine pt a afisa corect
      Serial.print(" = ");  //afiseaza stringul urmat de un '=' dupa care se va afisa codificarea in cod morse a stringului
      int i = 0;
      while(text[i] != 0){
        encode(text[i]);  //codificam fiecare caracter al stringului
        i++;
      }
      Serial.print("\n");
    }
  }else {
    buttonState = digitalRead(buttonPin);  //daca nu avem string in monitorul serial => se va citi valoarea butonului
    if(buttonState != lastButtonState){  //daca s-a detectat o modificare a butonului se actualizeaza starea butonului
      updateState();
    }else{
      if((millis() - endPressed) > letterGap2 && letterCode[0]!=0){
        decodeMorse();       
      }
    }
    lastButtonState = buttonState;  
  }  
}

/*Functia responsabila cu codificarea unui punt in semnal luminos, sonor si in caracterul '.' monitorul serial */
void dot(){
  Serial.print(".");
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
  delay(dotlength);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

/*Functia responsabila cu codificarea unei linii in semnal luminos, sonor si in caracterul '-' in monitorul serial*/
void dash(){
  Serial.print("-");
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
  delay(dashlength);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

/*Functie responsabila de codificare a caracterelor in simboluri de tip punct si linie*/
void encode(char symbol){

  //trasnformam literele mari in litere mici deoarece au acelasi cod
  if(symbol >='A' && symbol <='Z'){
    symbol+=32;
  }
  switch(symbol){
    case ' ':
      delay(wordGap);
      Serial.print("   ");
      break;
    case '\n':
      delay(wordGap);
      Serial.print('\n');
      break;
    case 'a':
      dot();
      delay(symbolGap);
      dash();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'b':
      dash();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'c':
      dash();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dot();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'd':
      dash();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'e': 
      dot();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'f':
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dot();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'g':
      dash();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dot();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'h':
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'i':
      dot();
      delay(symbolGap);
      dot();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'j':
      dot();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dash();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'k':
      dash();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dash();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'l':
      dot();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'm':
      dash();
      delay(symbolGap);
      dash();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'n':
      dash();
      delay(symbolGap);
      dot();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'o':
      dash();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dash();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'p':
      dot();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dot();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'q':
      dash();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dash();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'r':
      dot();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dot();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 's':
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 't':
      dash();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'u':
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dash();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'v':
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dash();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'w':
      dot();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dash();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'x':
      dash();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dash();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'y':
      dash();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dash();
      delay(letterGap);
      Serial.print(" ");
      break;
    case 'z':
      dash();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(letterGap);
      Serial.print(" ");
      break;
    case '0':
      dash();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dash();
      delay(letterGap);
      Serial.print(" ");
      break;
    case '1':
      dot();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dash();
      delay(letterGap);
      Serial.print(" ");
      break;
    case '2':
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dash();
      delay(letterGap);
      Serial.print(" ");
      break;
    case '3':
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dash();
      delay(letterGap);
      Serial.print(" ");
      break;
    case '4':
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dash();
      delay(letterGap);
      Serial.print(" ");
      break;
    case '5':
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(letterGap);
      Serial.print(" ");
      break;
    case '6':
      dash();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(letterGap);
      Serial.print(" ");
      break;
    case '7':
      dash();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(letterGap);
      Serial.print(" ");
      break;
    case '8':
      dash();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dot();
      delay(symbolGap);
      dot();
      delay(letterGap);
      Serial.print(" ");
      break;
    case '9':
      dash();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dash();
      delay(symbolGap);
      dot();
      delay(letterGap);
      Serial.print(" ");
      break;      
    default:
      //daca se introduce un caracter necunoscut se afiseaza in consola seriala caracterul '?'
      Serial.print("?"); 
  }
}

/*Functia care verifica daca stringul este vid*/
boolean isEmpty(String text){
  int i = 0;
  while(text[i]!= 0){
    if(isDigit(text[i]) || isAlpha(text[i])){
      return false;
    }
    i++;
  }
  return true;
}

/*Functia de update al starii butonului*/
void updateState(){
  if(buttonState == LOW){
    //butonul a fost apasat (este activ pe LOW intrucat foloseste rezistenta de PULL UP interna a placii)
    startPressed = millis();  //contorizeaza timpul la care s-a apasat butonul
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  }else{
    //butonul a fost lasat => se poate calcula timpul cat a fost tinut apasat ca diferenta dintre momentul cand o fost lasat
    //si momentul cand o fost apasat
     endPressed = millis();  //se contorizeaza timpul la care o fost lasat butonul
     holdTime = endPressed - startPressed;  //se calculeaza perioada de timp cat butonul a fost tinut
     digitalWrite(ledPin, LOW);
     digitalWrite(buzzerPin, LOW);
     if(holdTime > MIN_TIME){
      //debouncer pentru buton sa nu se apese valori gresite
       letterCode += getSymbol();
     }
  }
}

/*Functie care traduce semnalul de la buton ca 'punct sau 'linie' in functie de timpul cat o fost tinut apasat*/
char getSymbol(){
  if(holdTime < dashlength){
    return '.';
  }else{
    return '-';
  }
}

/*Funtia de decodificare al semnalului primit de la buton*/
void decodeMorse(){
  static String morseNumbers[] = { "-----",".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."}; //10
  String morseCode[] = {".-","-...", "-.-.", "-..", ".", ".._.","--.","....", "..",
                        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
                        ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};     //26
  int i = 0;
  int j = 0;
  boolean letterFound = false;
  
  while(i<MORSE_CODE_SIZE){
    //daca codul caracterului primit de la utilizator este gasit in tabloul de litere 'morsecode[]' atunci 
    //se caluleaza litera corespunzatoare codului ca indicele din tablou adunat la codul ASCII al literei A 
    if(morseCode[i] == letterCode){
      //am gasit litera
      Serial.print(char('A' + i));
      letterFound = true;
      break;
    }
    i++;
  }
  
  //daca codul caracterului primit de la utilizator este gasit in tabloul de litere 'morseNumbers[]' atunci 
  //se caluleaza numarul corespunzator codului ca indicele din tablou adunat la codul ASCII al numarului 0
  while(j<MORSE_NUMBER_SIZE && !letterFound){
    if(morseNumbers[j] == letterCode){
      //am gasit numarul
      Serial.print(char('0' + j));
      break;
    }
    j++;
  }
  
  //caracterul nu a fost gasit
  if(i == MORSE_CODE_SIZE && j==MORSE_NUMBER_SIZE){
    Serial.print("?");
  }
  letterCode = ""; //resetam codul
}
