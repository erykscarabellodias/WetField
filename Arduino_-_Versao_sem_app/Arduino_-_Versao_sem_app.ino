#include <DS3231.h>
DS3231  rtc(SDA, SCL);
Time t;

//parâmetros de horário que serão atualizados 
int horaAtual, minutoAtual;

//quantas vezes vai ligar
int registrarVezesPorDia = 8;
int acumulaDistribuicaoNoDia = 0;
int registrarMinutosPorLigacao = 0;
int arrayVezesPorDia [8]; //dar um jeito de transformar o tamanho em [registrarVezesPorDia];
int distribuicaoNoDia = 24/registrarVezesPorDia;

void setup() {

//inicia o módulo relógio
rtc.begin(); 
//inicia o monitor serial
Serial.begin(115200);//verificar o serial

//determina o pino do relé
pinMode(13, OUTPUT);//verificar qual porta estamos usando

for (int i = 0; i < sizeof (arrayVezesPorDia); i++) {
      arrayVezesPorDia [i] = acumulaDistribuicaoNoDia + distribuicaoNoDia;
      acumulaDistribuicaoNoDia = acumulaDistribuicaoNoDia + distribuicaoNoDia;
    }

//as linhas abaixo devem ser descomentadas para configurar o relógio interno. Descomente, carregue o código para o arduino, comente novamente e suba o código mais uma vez.
 // rtc.setDate(18,5,2019);    // determina a data (dia, mes, ano)
 // rtc.setDOW(FRIDAY);     // determina o dia da semana
 // rtc.setTime(15,41, 0);     // determina o horário (hora, minuto, segundo)

// desliga o relé para começar.
digitalWrite(13, HIGH);
 
}

void loop() {

//determina o horário atual
t = rtc.getTime();
horaAtual = t.hour;
minutoAtual = t.min;

if (registrarVezesPorDia == 1) {
  if (arrayVezesPorDia[0] == horaAtual && registrarMinutosPorLigacao < minutoAtual) {
    digitalWrite(13, HIGH);
    Serial.print("Funcionando!");
  } else {
    Serial.print("Aguardando.");
    digitalWrite(13, LOW);
  }
} else if (registrarVezesPorDia == 2) {
  if ((arrayVezesPorDia[0] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[1] == horaAtual && registrarMinutosPorLigacao < minutoAtual)) {
    digitalWrite(13, HIGH);
     Serial.print("Funcionando!");
  } else {
    Serial.print("Aguardando.");
    digitalWrite(13, LOW);
  }
} else if (registrarVezesPorDia == 3) {
  if ((arrayVezesPorDia[0] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[1] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[2] == horaAtual && registrarMinutosPorLigacao < minutoAtual)) {
    digitalWrite(13, HIGH);
    Serial.print("Funcionando!");
  } else {
    Serial.print("Aguardando.");
    digitalWrite(13, LOW);
  }
} else if (registrarVezesPorDia == 4) {
  if ((arrayVezesPorDia[0] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[1] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[2] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[3] == horaAtual && registrarMinutosPorLigacao < minutoAtual)) {
    digitalWrite(13, HIGH);
    Serial.print("Funcionando!");
  } else {
    Serial.print("Aguardando.");
    digitalWrite(13, LOW);
  }
} else if (registrarVezesPorDia == 5) {
  if ((arrayVezesPorDia[0] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[1] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[2] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[3] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[4] == horaAtual && registrarMinutosPorLigacao < minutoAtual)) {
    digitalWrite(13, HIGH);
    Serial.print("Funcionando!");
  } else {
    Serial.print("Aguardando.");
    digitalWrite(13, LOW);
  }
} else if (registrarVezesPorDia == 6) {
  if ((arrayVezesPorDia[0] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[1] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[2] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[3] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[4] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[5] == horaAtual && registrarMinutosPorLigacao < minutoAtual)) {
    digitalWrite(13, HIGH);
    Serial.print("Funcionando!");
  } else {
    Serial.print("Aguardando.");
    digitalWrite(13, LOW);
  }
} else if (registrarVezesPorDia == 7) {
  if ((arrayVezesPorDia[0] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[1] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[2] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[3] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[4] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[5] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[6] == horaAtual && registrarMinutosPorLigacao < minutoAtual)) {
    digitalWrite(13, HIGH);
    Serial.print("Funcionando!");
  } else {
    Serial.print("Aguardando.");
    digitalWrite(13, LOW);
  }
} else if (registrarVezesPorDia == 8) {
  if ((arrayVezesPorDia[0] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[1] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[2] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[3] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[4] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[5] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[6] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[7] == horaAtual && registrarMinutosPorLigacao < minutoAtual)) {
    digitalWrite(13, HIGH);
    Serial.print("Funcionando!");
  } else {
    Serial.print("Aguardando.");
    digitalWrite(13, LOW);
  }
} else if (registrarVezesPorDia == 12) {
  if ((arrayVezesPorDia[0] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[1] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[2] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[3] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[4] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[5] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[6] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[7] == horaAtual && registrarMinutosPorLigacao < minutoAtual) || (arrayVezesPorDia[8] == horaAtual && registrarMinutosPorLigacao < minutoAtual)) {
    digitalWrite(13, HIGH);
    Serial.print("Funcionando!");
  } else {
    Serial.print("Aguardando.");
    digitalWrite(13, LOW);
  }
}
}
