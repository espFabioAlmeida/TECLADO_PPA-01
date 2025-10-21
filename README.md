# TECLADO PPA-01
Projeto Automasensor: TECLADO PPA-01
# Escopo
Esse teclado tem o objetivo de comunicar com o placar PPA-01. <br>
Deve transmitir so comandos da pontuação diretamente, sem lógica adicional. <br>
Os comandos para zerar deverão funcionar apenas com o cronômetro parado. <br>
O usuário deverá conseguir ajustar o cronômetro para as funções de progressivo e regressivo. <br>
# Mapa dos Botões
SW1 - Programação - L1C1: Acessa o menu de configurações <br>
SW2 - +5 Min - L1C2: Adiciona +5min no cronômetro <br>
SW3 - +20 Min - L1C3: Adiciona +20min no cronômetro <br>
SW4 - Falta +1 - L1C4: Adiciona falta/set no Time A <br>
SW5 - Ponto +1 - L1C5: Adiciona ponto no Time A <br>
SW6 - Ponto +2 - L1C6: Adiciona mais 2 pontos no Time A <br>
SW7 - Prog/Regr - L2C1: Seleciona o modo do cronômetro <br>
SW8 - +10 Min - L2C2: Adiciona +10min no cronômetro <br>
SW9 - Zera Tudo - L2C3: Zera todo o placar <br>
SW10 - Falta -1 - L2C4: Remove falta/set no Time A <br>
SW11 - Ponto -1 - L2C5: Remove ponto no Time A <br>
SW12 - Ponto +3 - L2C6: Adiciona mais 3 pontos no Time A <br>
SW13 - Tempo A - L3C1: Tempo Time A <br>
SW14 - Campainha - L3C2: Chamada avulsa na campainha <br>
SW15 - Solta Cronômetro - L3C3: Solta o cronômetro <br>
SW16 - Tempo B - L3C4: Tempo Time B <br>
SW17 - Período - L3C5: Pressiona simples adiciona Período, pressiona e mantém pressionado remove Período <br>
SW18 - Para Cronômetro - L3C6: Para o cronômetro <br>
SW19 - +1 Min - L4C1: Adiciona +1min no cronômetro <br>
SW20 - +1 Seg - L4C2: Adiciona +1seg no cronômetro <br>
SW21 - Zera Falta - L4C3: Zera as faltas/sets <br>
SW22 - Falta +1 - L4C4: Adiciona falta/set no Time B <br>
SW23 - Ponto +1 - L4C5: Adiciona ponto no Time B <br>
SW24 - Ponto +2 - L4C6: Adiciona mais 2 pontos no Time B <br>
SW25 - -1 Min - L5C1: Remove 1 minuto do cronômetro <br>
SW26 - -1 Seg - L5C2: Remove 1 segundo do cronômetro <br>
SW27 - Zera cronômetro - L5C3: Zera o cronômetro <br>
SW28 - Falta -1 - L5C4: Remove falta/set Time B <br>
SW29 - Ponto -1 - L5C5: Remove ponto no Time B <br>
SW30 - Ponto +3 - L6C6: Adiciona mais 3 pontos no Time B <br>
# Protocolo RS485
Comando 1: Configuração do teclado, funciona apenas com o placar parado e zerado. <br>
-$,01,20000,00000,1,\r\n <br>
20000 = Tempo de setpoint <br>
00000 = Tempo ajustado <br>
1 = Tipo de cronômetro, sendo 1 para regressivo e 2 para progressivo <br>
<br>
Comando 2 à 23: Ações do teclado.<br> 
02: TIME A +1 <br>
03: TIME A +2 <br>
04: TIME A +3 <br>
05: TIME A -1 <br>
06: TIME A +1 Falta <br>
07: TIME A -1 Falta <br>
08: Tempo A <br>
09: TIME B +1 <br>
10: TIME B +2 <br>
11: TIME B +3 <br>
12: TIME B -1 <br>
13: TIME B +1 Falta <br>
14: TIME B -1 Falta <br>
15: Tempo B <br>
16: Solta Cronômetro <br>
17: Para Cronômetro <br>
18: Campainha <br>
19: Zera Faltas <br>
20: Zera Cronômetro <br>
21: Zera Tudo <br>
22: Período +1 <br>
23: Período -1 <br>
<br>
Todos os comandos são respondidos com $,CMD,\r\n <br>
