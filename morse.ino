//dot: 40 ms | dash: 120 ms => 30 cuv pe min
//dot: 50 ms | dash: 150 ms => 30 cuv pe min
// 
#define TIME_UNIT 50
const int ledPin = 24;
const int buzzerPin = 52;

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

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if(Serial.available()){
    String text = Serial.readString();
    Serial.print(text);  //trebuie setat din monitorul serial sa nu adauge newLine pt a afisa corect
    Serial.print(" = ");
    int i = 0;
    while(text[i] != 0){
      encode(text[i]);
      i++;
    }
    Serial.print("\n");
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
