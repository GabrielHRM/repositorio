# Informações gerais e links

# Introdução a Técnicas de Programação - Unidade 1
**Aluno**: Gabriel Henrique Rocha Melo
**Matrícula**: 20250059916
**Período**: 2025.2

## 📁 Estrutura do Projeto
- `projeto/`: Projeto principal da unidade
- `listas/`: Soluções das listas de exercícios
- `README.md`: Este arquivo

## 🚀 Projeto: Conversor de Unidades Brazuca
**Descrição**: Um conversor de unidades de medidas
**Repositório**: [(https://github.com/GabrielHRM/repositorio.git)]
**Vídeo de Demonstração**: https://youtu.be/kg22OH_BofI

### Funcionalidades Implementadas:
- Seletor de opções em um menu principal
- Seletor de opções em um menu de Categoria de Unidade
- Multiplas opções de conversão
- Pode-se converter valores dentro de um sistema de medida(de SI para SI) ou entre sistemas(de SI para Sistema Imperial).


### Conceitos da U1 Aplicados:
- Estruturas condicionais: Exeto na função do menu principal e do menu de categorias, foram usadas em todas as outras funções.
- Estruturas de repetição: Apenas uma estrutura de repetição do-while foi utilizado dentro da função main na forma de um laço infinito para atualização contante dos valores pertinentes para a conversão, com o numero zero sendo utilizado para quebrar o laço(comando break) e, caso o usuario digite valores fora das opções disponiveis em ambos os menus, ele retornara para o menu principal para que possa escolher uma nova opção.
- Vetores: os vetores foram utilizados de 2 formas: a primeira forma foi utilizando-os para armazenamento dos fatores de conversão em um vetor e utilizá-los posteriormente, transformando o valor digitado pelo usuário no valor inicial que será então utilizado para as convenções futuras, já a segunda forma foi múltiplos vetores de caracteres simbolizando as siglas de cada respectivas unidade como forma de organização, evitando a poluição de informações no código.
- Funções: A implementação das funções se deu pela criação de várias delas: 2 funções para os menus principal e de unidades de medida, 7 funções para os diferentes tipos de conversões e 9 
funções para as questões técnicas necessárias para o processo de conversão: 2 funções para o menu princiapl e para o menu de categoria, 1 função que retorna um valor inteiro conrrespondente ao total de opções permitidas dentro do menu de categorias, 3 funções de leitura para ler o valor real a ser convertido, sua unidade de medida(vairavel de) e a unidade de medida que esse numero será convertido(variavel para), 1 função para validar se a opção digita pelo usuario no menu de categorias está correto, 1 função para chamar outras 7 funções de conversão, dependendo das opções escolhidas pelo ususario e, por ultimo, 1 função para processar todos os dados que são a fundação do projeto, alocada na função main, e que apartir dela são chamadas todas as outras funções do projeto.

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

## 🎯 Principais Aprendizados
A utilização dos conceitos aprendidos na unidade foi essencial para um melhor entendimento acerca do gerenciamento eficiente de memoria ram, principalmente quando se fala na utilização de apenas um laço de repetição e variaveis locais para uma atualização constante dos valores digitados pelo usuario, liberando espaço na memoria a cada nova iteração e evitando situações de acumulo de informações desnecessarias na mesma.

## 🔧 Ambiente de Desenvolvimento
- **SO**: [Windows]
- **Compilador**: GCC versão [15.2]
- **Editor**: Visual Studio Code
