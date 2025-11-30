# Informações gerais e links

# Introdução a Técnicas de Programação - Unidade 1 e Unidade 2
**Aluno**: Gabriel Henrique Rocha Melo
**Matrícula**: 20250059916
**Período**: 2025.2

## 📁 Estrutura do Projeto
- `projeto/`: Projeto principal da unidade
- `listas/`: Soluções das listas de exercícios
- `README.md`: Este arquivo

## 🚀 Projeto: Conversor de Unidades Brazuca e Calculadora Científica
**Descrição - UNIDADE 1**: Um conversor de unidades de medidas
**Descrição - UNIDADE 2**: Uma calculadora de operações matemáticas diversas
**Repositório**: [(https://github.com/GabrielHRM/repositorio.git)]
**Vídeo de Demonstração - Unidade 1**: https://youtu.be/kg22OH_BofI
**Vídeo de Demonstração - Unidade 2**: https://youtu.be/xcLlB28xa_s

### Funcionalidades Implementadas - UNIDADE 1:
- Seletor de opções em um menu principal
- Seletor de opções em um menu de Categoria de Unidade
- Multiplas opções de conversão
- Pode-se converter valores dentro de um sistema de medida(de SI para SI) ou entre sistemas(de SI para Sistema Imperial).
### Funcionalidades Implementadas - UNIDADE 2:
- Seletor de opções em um menu principal
- Seletor de opções nos menus das operações
- Multiplas operações matemáticas
- Histórico de resultados com tamanho expandível
- Fucionalidade para o apagamento do histórico


### Conceitos da U1 Aplicados:
- Estruturas condicionais: Exeto na função do menu principal e do menu de categorias, foram usadas em todas as outras funções.
- Estruturas de repetição: Apenas uma estrutura de repetição do-while foi utilizado dentro da função main na forma de um laço infinito para atualização contante dos valores pertinentes para a conversão, com o numero zero sendo utilizado para quebrar o laço(comando break) e, caso o usuario digite valores fora das opções disponiveis em ambos os menus, ele retornara para o menu principal para que possa escolher uma nova opção.
- Vetores: os vetores foram utilizados de 2 formas: a primeira forma foi utilizando-os para armazenamento dos fatores de conversão em um vetor e utilizá-los posteriormente, transformando o valor digitado pelo usuário no valor inicial que será então utilizado para as convenções futuras, já a segunda forma foi múltiplos vetores de caracteres simbolizando as siglas de cada respectivas unidade como forma de organização, evitando a poluição de informações no código.
- Funções: A implementação das funções se deu pela criação de várias delas: 2 funções para os menus principal e de unidades de medida, 7 funções para os diferentes tipos de conversões e 9 
funções para as questões técnicas necessárias para o processo de conversão: 2 funções para o menu princiapl e para o menu de categoria, 1 função que retorna um valor inteiro conrrespondente ao total de opções permitidas dentro do menu de categorias, 3 funções de leitura para ler o valor real a ser convertido, sua unidade de medida(vairavel de) e a unidade de medida que esse numero será convertido(variavel para), 1 função para validar se a opção digita pelo usuario no menu de categorias está correto, 1 função para chamar outras 7 funções de conversão, dependendo das opções escolhidas pelo ususario e, por ultimo, 1 função para processar todos os dados que são a fundação do projeto, alocada na função main, e que apartir dela são chamadas todas as outras funções do projeto.
### Conceitos da U2 Aplicados:
- Strings: Foram utilizados para implementação do histórico, transformando todos os resultados em strings, sendo armazenadas em uma string chamada entrada, que por fim seria transferida para a string final do histórico, com o auxílio das funções strcat e sprintf, funções da biblioteca de string da linguegem c.
- Estrutura de Repetição Aninhada: Utilizada em todas as funções de operações matriciais e auxiliares, como a leitura de uma matriz, a transformação da matriz resultado em uma string que seria posteriormente armazenada na string do histórico e a propria impressão da string resultado na tela do usuário. A repetição aninhada foi utilizada também na função de ordenação e moda da biblioteca altoral de operações estatitiscas, para a ordenação do vetor númérico digitado pelo usuário e sua comparação interna de valores, que é pertinente para a função de moda.
- Matrizes: Foram implementadas em todas as operações e funções auxiliares envolvendo matrizes e apenas nelas, como nas funções de leitura e impressão que utilizaram de laços de repetição aninhados(um for i e um for j), já que esse é o algoritmo padrão ao lidar com matrizes.
- Ponteiros: Foram utilizados sempre que um vetor exigia um tamanho variável e principalmente para a função do histórico que, pelo algoritmo implementado, precisava ter seu tamanho e conteúdo alterados. Por isso os parâmetros necessários para essa operação fazem parte do cabeçalho de cada função principal, já que esses valores serão pertinentes para adicionar novas operações ao histórico e aumentar seu tamanho caso precise. Vale ressaltar a passagem por referencia(&variavel) como de suma importancia, também, para o aumento do tamanho da string do histórico.
- Alocação Dinâmica: Foi necessária em todas as operações que envolvem vetores(vetores simples, matrizes e strings), já que essa funções tem valores definidores de tamanho(linha, clona, tamanho da string) variáveis, por tanto a alocação dinamica ajudou separar apenas o espaço necessário na memória ram para o armazenamento desses vetores.


## 📚 Listas de Exercícios
### Semana 2 - Variáveis, Tipos e Operadores:
- ✅ Problema 1: Calculadora de IMC
- ✅ Problema 2: Conversão de temperatura
- ✅ Problema 3: Cálculo de juros compostos
- ✅ Problema 4: Operações aritméticas básicas

### Semana 3 - Condicionais:
- ✅ Problema 1: Classificação de IMC
- ✅ Problema 2: Calculadora de energia elétrica
- ✅ Problema 3: Sistema de notas
- ✅ Problema 4: Pedra, papel, tesoura
- ✅ Problema 5: Calculadora de desconto progressivo
- ✅ Problema 6: Diagnóstico médico simples
- ✅ Problema 7: Sistema de equações do 2º grau
- ✅ Problema 8: Validador de triângulos

### Semana 4A - Repetições:
- ✅ Problema 1: Dobrar folha
- ✅ Problema 2: Homem Aranha
- ✅ Problema 3: Números colegas
- ✅ Problema 4: Jogo de dardos

### Semana 4B - Análise e Padrões:
- ✅ Questões 1-4: Análise de código
- ✅ Questões 5-10: Implementações

### Semana 5 - Funções (Parte 1):
- ✅ Problema 1: Horários das rondas
- ✅ Problema 2: Primos triplos
- ✅ Problema 3: Pousando a sonda espacial

### Semana 6 - Vetores:
- ✅ Problema 1: MEC - Correção ENEM
- ✅ Problema 2: Álbum de figurinhas
- ✅ Problema 3: A construção da ponte
- ✅ Problema 4: Em busca do tesouro perdido

### Semana 7 - Strings:
- ✅ Problema 1: Campo minado 1D
- ✅ Problema 2: Detecção de placas
- ✅ Problema 3: OpenMeet

### Semana 8 - Repetição Aninhada:
- ✅ Problema 1: Estou com sorte (ou não)
- ✅ Problema 2: Os dias mais chuvosos
- ✅ Problema 3: Esse sim é piloto

### Semana 9 - Matrizes:
- ✅ Problema 1: Campo Agrícola
- ✅ Problema 2: Sugestão de amigos
- ✅ Problema 3: Campeonato de empates
- ✅ Problema 4: Uma pechincha!

### Semana 10 - Ponteiros:
- ✅ Problema 1: Soma de Vetores
- ✅ Problema 2: Ocorrências no vetor
- ✅ Problema 3: Sopa de letrinhas

## 🎯 Principais Aprendizados
## UNIDADE 1
A utilização dos conceitos aprendidos na unidade foi essencial para um melhor entendimento acerca do gerenciamento eficiente de memoria ram, principalmente quando se fala na utilização de apenas um laço de repetição e variaveis locais para uma atualização constante dos valores digitados pelo usuario, liberando espaço na memoria a cada nova iteração e evitando situações de acumulo de informações desnecessarias na mesma.
## Unidade 2
O conhecimento adquirido e as habilidades desenvolvidas na Unidade 2 e aplicadas no projeto, especialmente o domínio sobre ponteiros, alocação e manipulação dinâmica de memória, representam um avanço significativo que será extremamente útil não apenas para futuros trabalhos acadêmicos, mas também em projetos pessoais e no mundo profissional, solidificando uma base técnica essencial. Paralelamente, houve uma consolidação e aprimoramento dos conteúdos vistos na Unidade 1, notando-se uma preferência por abordagens mais eficientes e claras, como o uso de switch-case em detrimento de aninhamentos complexos de if-else em estruturas condicionais, o manejo mais seguro e eficaz de vetores (incluindo strings e laços aninhados), e a melhor compreensão da passagem de variáveis por referência (em oposição à passagem por valor), demonstrando uma evolução completa no entendimento da programação.

## 🔧 Ambiente de Desenvolvimento
- **SO**: [Windows]
- **Compilador**: GCC versão [15.2]
- **Editor**: Visual Studio Code
