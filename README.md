Sistema de Hotel

Sistema de gerenciamento de hotel desenvolvido em C++ para controle de reservas, hóspedes, ocupação de quartos e faturamento.

Descrição do Projeto

O sistema foi desenvolvido para simular o funcionamento de um hotel, permitindo realizar operações de check-in, check-out, gerenciamento de quartos e emissão de relatórios administrativos.

O projeto utiliza programação estruturada e manipulação de dados através de structs, funções e vetores.

Funcionalidades

* Mapa de quartos do hotel
* Controle de quartos livres e ocupados
* Sistema de check-in
* Sistema de check-out
* Cadastro de hóspedes
* Validação básica de CPF
* Controle de diárias
* Controle de faturamento
* Relatório geral do hotel
* Listagem de hóspedes atuais
* Controle de ocupação por tipo de quarto

Tipos de Quartos

* Simples
* Duplo
* Suíte

Tecnologias Utilizadas

* C++

Explicação do Código

O sistema utiliza duas structs principais:

* Hospede:
  Responsável por armazenar informações do hóspede, como nome, CPF e telefone.

* Quarto:
  Responsável por armazenar dados do quarto, incluindo número, andar, tipo, status de ocupação, diária e informações do hóspede.

O programa trabalha com um vetor de 20 quartos previamente inicializados, divididos entre quartos simples, duplos e suítes.

As funcionalidades principais são controladas através de funções específicas:

* inicializarQuartos()
* mostrarMapaQuartos()
* fazerCheckIn()
* fazerCheckOut()
* mostrarRelatorio()
* listarHospedesAtuais()

O menu principal utiliza um loop `do while`, permitindo a navegação contínua no sistema até o encerramento do programa.

Objetivo do Projeto

O objetivo do projeto é praticar conceitos de:

* Programação estruturada
* Structs
* Vetores
* Funções
* Manipulação de dados
* Estruturas condicionais
* Laços de repetição
* Desenvolvimento de sistemas de gerenciamento

Exemplo de Funcionalidades

* Reservar quartos
* Visualizar ocupação do hotel
* Gerenciar hóspedes
* Calcular faturamento total
* Realizar check-out de clientes
