//dot: 40 ms | dash: 120 ms => 30 cuv pe min
//dot: 50 ms | dash: 150 ms => 35 cuv pe min
// 
#define TIME_UNIT 50
const int ledPin = 24;
const int buzzerPin = 52;
const int buttonPin = 38;

//Reguli:
//dupa fiecare simbol al unei litere urmeaza un TIME_UNIT
//dupa fiecare litera urmeaza 3 TIME_UNIT-uri
//dupa fiecare cuvant urmeaza 7 TIME_UNIT-uri
//presupunem ca dupa fiecare litera urmeaza o alta litera, astfel dupa fiecare litera utilizam
//un delay de 3* TIME_UNIT, iar daca este un spatiu vom completa nr de TIME_UNIT-uri pana la 7
const int dotlength = TIME_UNIT;  //50 de ms
const int dashlength = 3 * TIME_UNIT;  //150 ms
const int symbolGap = TIME_UNIT;
const int letterGap = 3 * TIME_UNIT;
//completam TIME_UNIT pana la 7
const int wordGap = 4 * TIME_UNIT; 

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
    String text = Serial.readString();
    if(!isEmpty(text)){
      Serial.print(text);  //trebuie setat din monitorul serial sa nu adauge newLine pt a afisa corect
      Serial.print(" = ");
      int i = 0;
      while(text[i] != 0){
        encode(text[i]);
        i++;
      }
      Serial.print("\n");
    }
  }else {
    buttonState = digitalRead(buttonPin);
    if(buttonState != lastButtonState){
      updateState();
    }
    lastButtonState = buttonState;  
  }  
}

void dot(){
  Serial.print(".");
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
  delay(dotlength);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

void dash(){
  Serial.print("-");
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
  delay(dashlength);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

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

void updateState(){
  if(buttonState == LOW){
    //s-a apasat butonul si se poate calcula timpul cat butonul a fost lasat
    startPressed = millis();
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    Serial.print("butonul a fost lasat: ");
  }else{
    //s-a last butonul si se poate calcula timpul cat butonul a fost apasat
    endPressed = millis();
    holdTime = endPressed - startPressed;
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    Serial.print("butonul a fost apasat: ");
    Serial.println(holdTime);
  }
}
