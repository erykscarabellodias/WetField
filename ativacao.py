import serial
import time
from datetime import datetime

port = "/dev/ttyACM0"
velocidade = 9600
conexao = serial.Serial(port, velocidade)


condicao = True
horaAgora = datetime.now()
hora = horaAgora.hour
minuto = horaAgora.minute

horaDesejada = int (input ('Que hora você quer que o sistema trabalhe? '))
minutoInicial = int (input ('A partir de que minuto você quer que o sistema trabalhe? '))
minutoFinal = int( input ('Em qual minuto você quer que o sistema pare de funcionar? '))

while condicao:
    if (hora == horaDesejada) and (minuto < minutoFinal) and (minuto > minutoInicial):
        horaAgora = datetime.now()
        hora = horaAgora.hour
        minuto = horaAgora.minute
        teste = '1'
        print (teste)
        conexao.write(teste.encode())
        time.sleep (10)
    else:
        print(0)
        teste = '0'
        conexao.write(teste.encode())
        time.sleep (10)