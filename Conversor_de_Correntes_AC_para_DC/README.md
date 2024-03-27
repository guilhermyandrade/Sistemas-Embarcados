# Conversor de Correntes AC para DC

Explicação dos componentes:

- **Transformador**: Reduz a tensão da corrente elétrica de 127V para 12V.
- **Led**: Converte eletricidade em luz.
- **Diodo**: Conduz apenas corrente positiva.
- **Resistor**: Reduz a corrente de acordo com o número de Ohms. Quanto mais resistência (Ohms), menor a corrente conduzida.
- **Capacitor**: Armazena cargas elétricas.
- **Regulador de tensão**: Reduz a tensão da corrente.

## Resolução do Problema

O objetivo é fazer com que o LED emita luz. Para isso, uma corrente alternada (AC) com 12V de tensão deve ser convertida em corrente contínua (DC) de, no máximo, 5V.

#### Corrente Alternada

A corrente alternada alterna o sentido para o qual a corrente flui. Assim como apresentado na imagem 1, sempre há variações entre corrente positiva e negativa.

<div align="center"><h4>Imagem 1 - Corrente Alternada</h4></div>

<div align="center"><img title="Imagem 1" src="https://github.com/guilhermyandrade/Sistemas-Embarcados/blob/main/Conversor_de_Correntes_AC_para_DC/Imagens/Corrente_Alternada.png" ></div>

#### Ponte retificadora

A ponte retificadora é usada para conversão da corrente alternada para corrente contínua. É composta por quatro diodos, posicionados como na imagem 2.

<div align="center"><h4>Imagem 2 - Ponte Retificadora com Diodos</h4></div>

<div align="center"><img title="Imagem 2" src="https://github.com/guilhermyandrade/Sistemas-Embarcados/blob/main/Conversor_de_Correntes_AC_para_DC/Imagens/Ponte_Retificadora.png" ></div>

#### Estabilizando a Corrente

Assim que a corrente fluir pela ponte retificadora, apenas a carga positiva será conduzida. Entretanto, a corrente proveniente da ponte ainda terá variações. Para estabilizar a corrente, o capacitor pode ser usado para compensar a temporária falta de corrente positiva, assim como na imagem 3.

<div align="center"><h4>Imagem 3 - Estabilização da Corrente com Capacitores</h4></div>

<div align="center"><img title="Imagem 3" src="https://github.com/guilhermyandrade/Sistemas-Embarcados/blob/main/Conversor_de_Correntes_AC_para_DC/Imagens/Corrente_Estabilizada.png" ></div>

#### Regulador de Tensão

O regulador de tensão é um semi-condutor que reduz a tensão sem alterar o fluxo da corrente. Nesse contexto, está sendo usado na diminuição da corrente de 12V para 5V, conduzindo-a para o terminal positivo do LED.

## Desenvolvimento do projeto

O projeto foi iniciado com a simulação do circuito elétrico com o software Proteus e, em seguida, aplicado na prática usando uma [protoboard](https://pt.wikipedia.org/wiki/Placa_de_ensaio), como na imagem 4 e 5, respectivamente.

<div align="center"><h4>Imagem 4 - Simulação com o software Proteus</h4></div>

<div align="center"><img title="Imagem 4" src="https://github.com/guilhermyandrade/Sistemas-Embarcados/blob/main/Conversor_de_Correntes_AC_para_DC/Imagens/Simulacao.png" ></div>

<div align="center"><h4>Imagem 5 - Prototipagem</h4></div>

<div align="center"><img title="Imagem 5" src="https://github.com/guilhermyandrade/Sistemas-Embarcados/blob/main/Conversor_de_Correntes_AC_para_DC/Imagens/Conversor_de_Correntes_AC_para_DC.jpeg" ></div>

<div align="center"><h4>Imagem 6 - PCB - Placa de Circuito Impresso</h4></div>

<div align="center"><img title="Imagem 6" src="https://github.com/guilhermyandrade/Sistemas-Embarcados/blob/main/Conversor_de_Correntes_AC_para_DC/Imagens/PCB.png" ></div>

<div align="center"><h4>Imagem 7 - Visualização 3D</h4></div>

<div align="center"><img title="Imagem 7" src="https://github.com/guilhermyandrade/Sistemas-Embarcados/blob/main/Conversor_de_Correntes_AC_para_DC/Imagens/3D.png" ></div>
