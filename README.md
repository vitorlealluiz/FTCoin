# FTCoin
Neste projeto, desenvolvi junto com meu grupo um sistema de acompanhamento de carteira de moeda virtual em C++ com uma interface de linha de comando (CLI). O objetivo é criar um sistema organizado, seguindo padrões de programação orientada a objetos (POO) e práticas de programação robustas.

Requisitos do Sistema

1. Linguagem:

Implementação em C++.

2. Interface:

Interface de linha de comando (CLI) com menu principal e submenus.

Uso de cores quando apropriado.

Menu principal com opções: Carteira, Movimentação, Relatórios, Ajuda, Sair.


3. Funcionalidades:

Carteira:

Incluir um novo registro de carteira.

Recuperar um registro de carteira por identificador.

Editar um registro de carteira existente.

Excluir um registro de carteira.

Movimentação:

Registrar compra de moeda virtual em uma carteira.

Registrar venda de moeda virtual de uma carteira.

Relatórios:

Listar carteiras ordenadas por identificador.

Listar carteiras ordenadas por nome do titular.

Exibir saldo atual de uma carteira específica.

Exibir histórico de movimentação de uma carteira específica.

Apresentar ganho ou perda total de cada carteira, calculado com base nas cotações do oráculo.

Ajuda:

Texto longo de ajuda do programa

Tela de créditos (autores, copyright, data, versão)

Sair:

Saída imediata do programa, com fechamento de conexões

4. Oráculo:

O sistema deve consultar um banco de dados oráculo que contém a cotação diária da moeda virtual em moeda real.

5. Persistência de Dados:

Duas implementações de persistência de dados (padrão DAO):

Simulação de banco de dados em memória local.

Banco de dados relacional remoto (MariaDB).

Estrutura do Banco de Dados

1. Tabela: Carteira

Identificador (int, chave primária, único)

Nome do titular (varchar)

Corretora (varchar)

2. Tabela: Movimentação

Identificador da carteira (int, chave estrangeira)

Identificador do movimento (int, chave primária, único)

Data da operação (date)

Tipo da operação (char: 'C' para compra, 'V' para venda)

Quantidade movimentada (decimal, não negativo)

3. Tabela: Oráculo

Data (date, chave primária, único)

Cotação (decimal, não negativo)

Boas Práticas de Programação

Use o paradigma da Programação orientada a objetos (POO) com classes bem definidas e uso correto das ferramentas de encapsulamento, herança, sobrecarga e polimorfismo.

Escreva código C++ organizado e autodocumentado.

Mantenha o código limpo, organizado e legível.

Utilize nomes significativos para classes, métodos e variáveis.

Divida o código em classes separadas para promover a modularidade e a reutilização de código.

Comente o código de forma clara e concisa para explicar o propósito de classes, métodos e trechos complexos, mas seja econômico na quantidade de comentários.

Utilize constantes e enumerações para representar valores fixos e evitar números mágicos.

Implemente tratamento de erros (exceções) e validações adequadas para garantir a robustez do sistema desde o nível de projeto.

Faça uso de padrões de projeto apropriados, como DAO (Data Access Object) e DTO (Data Transfer Object), para separar a lógica de acesso a dados do restante do código.

Desenvolvimento do Projeto

Comece projetando a estrutura geral do sistema, identificando as classes necessárias e suas relações.

Divida o trabalho equilibradamente entre os membros do grupo, relembrando que trabalhar em equipes é um do benefícios do uso da POO, que permite codificação em paralelo

Implemente as classes e métodos de acordo com o design estabelecido, seguindo as boas práticas de programação.

Teste o sistema cuidadosamente para garantir que todas as funcionalidades estejam funcionando corretamente e que não haja erros.

Refatore o código conforme necessário para melhorar a qualidade e a eficiência do sistema.

Documente o código adequadamente, incluindo instruções de compilação e execução, bem como descrições dos principais componentes e funcionalidades.

Explore a possibilidade de adicionar testes unitários para garantir a qualidade do código.

Incentive na equipe o uso de controle de versão (ex: Git).

Observações:

No Bando de Dados, o tipo de dados double foi substituído por decimal para maior precisão em valores monetários e o tipo de dados string foi substituido por varchar, para melhor compatibilidade.

Entrega do Projeto:

Atenção: Serão considerados apenas programas que compilem sem erros ou avisos!

A entrega do projeto será realizada através da plataforma Moodle e deve incluir os seguintes itens:

1. Relatório de Contribuição Comentado:

Utilize o modelo disponibilizado na plataforma (anexo a esta tarefa).

Os percentuais atribuídos a cada integrante devem ser números inteiros e únicos (caso essas condições sejam violadas, valores arbitrários serão utilizados).

2. Código-fonte:

Forneça um arquivo .zip, contendo:

os arquivos .h/.hpp

os arquivos .cpp

script de compilação para Linux

O código deve compilar sem erros ou avisos, utilizando apenas recursos da linguagem C++ (C++11) e suas bibliotecas padrão.

Não serão aceitas correções ou alterações no código ou no script após a entrega.

3. Arquivo PDF com o Código-fonte Completo:

Cada arquivo .h/.hpp e .cpp deve iniciar em uma nova página.

Este arquivo será utilizado para a correção geral e avaliação da qualidade do código.

4. Link para Vídeo Demonstrativo (5 a 7 minutos):

O vídeo deve demonstrar o programa em funcionamento (desde a compilação).

Não é necessário instalar ou ter acesso a um banco de dados relacional remoto. Utilize a implementação DAO em memória para a demonstração.

Utilize o campo de texto do Moodle para indicar o link e certifique-se de que o professor e o PED tenham acesso.

5. Diagrama de Classes UML em PDF:

O diagrama deve mostrar os relacionamentos entre as classes, especialmente a herança.

Considerações Finais:

Este projeto oferece uma oportunidade para aplicar e aprimorar seus conhecimentos em programação C++ e práticas de desenvolvimento de software.

Aproveite ao máximo esta experiência e busque ajuda ou esclarecimentos sempre que necessário.

Uma boa forma de aprendizado é incluir funcionalidades e recursos além do mínimo solicitado.

