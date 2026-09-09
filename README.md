# Estação de Monitoramento - Sistemas Automatizados

**Autor:** Pedro Hipolito

## Descrição do Projeto
Este projeto consiste em um protótipo simulado de uma estação de monitoramento desenvolvido no Wokwi, integrando entradas digitais e analógicas e executando decisões lógicas baseadas em prioridades de alarme. O circuito utiliza um botão como sensor digital, um potenciômetro como entrada analógica, um DHT22 para simulação de temperatura e um LED para atuação/sinalização.

## Instruções de Reprodução
1. Acesse o [Wokwi](https://wokwi.com) e crie um novo projeto com a placa Arduino Uno.
2. Adicione os componentes e realize as seguintes conexões:
   - **Pushbutton:** Conecte um terminal ao pino D2 e o oposto ao GND.
   - **LED + Resistor:** Conecte o pino D8 ao resistor de 220 Ω, este ao ânodo do LED, e o cátodo ao GND.
   - **Potenciômetro:** Conecte o VCC em 5V, GND no GND e o pino de sinal (SIG) no A0.
   - **DHT22:** Conecte o VCC em 5V, GND no GND e o pino DATA no D4.
3. Acesse o "Library Manager" (Gerenciador de Bibliotecas) e adicione a biblioteca **DHT sensor library** (da Adafruit). Aceite dependências adicionais se solicitado.
4. Cole o código-fonte no arquivo `sketch.ino`.
5. Pressione o botão de simulação (Play) e abra o Monitor Serial (baud rate 9600).
6. Altere os valores no simulador (girando o potenciômetro, clicando no DHT22 para alterar a temperatura e pressionando o botão) para observar o comportamento.

## Tabela de Casos de Teste Integrados

| Caso | Potenciômetro | Temperatura | Botão | Resposta Esperada (Monitor Serial) | Resultado Obtido |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **T1** | 200 | 25 °C | Livre | NORMAL; LED off | Aprovado |
| **T2** | 500 | 25 °C | Livre | ATENÇÃO; LED off | Aprovado |
| **T3** | 800 | 25 °C | Livre | ALARME; LED off | Aprovado |
| **T4** | 200 | 35 °C | Livre | ATENÇÃO; LED off | Aprovado |
| **T5** | 200 | 45 °C | Livre | ALARME; LED off | Aprovado |
| **T6** | 200 | 25 °C | Pressionado | NORMAL; LED on | Aprovado |
| **T7** | (Indiferente) | Inválida | Livre | FALHA DE SENSOR | Aprovado |

## Análise de Limitações da Simulação
A simulação comprova com sucesso a coerência funcional da leitura, das regras de decisão, da atuação e dos diagnósticos no Monitor Serial. Contudo, ela apresenta limitações essenciais do mundo físico. Este modelo não comprova imunidade a ruídos elétricos industriais, aterramento, compatibilidade eletromagnética, robustez da montagem mecânica (como o encapsulamento ou grau de proteção), calibração metrológica dos sensores ou confiabilidade e segurança funcional do sistema a longo prazo.
