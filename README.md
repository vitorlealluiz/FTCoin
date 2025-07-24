# FTCoin
Este projeto consiste em um sistema para gerenciamento e acompanhamento de carteiras de moedas virtuais, desenvolvido em C++ com interface de linha de comando (CLI). O sistema é estruturado com foco em programação orientada a objetos (POO) e boas práticas de desenvolvimento, garantindo modularidade, robustez e manutenção facilitada.

- Funcionalidades Principais
1. Carteira: Cadastro, edição, recuperação e exclusão de carteiras.
2. Movimentação: Registro de compra e venda de moedas virtuais associadas às carteiras.
3. Relatórios: Listagem de carteiras ordenadas por ID ou nome, exibição do saldo atual e histórico de movimentações, cálculo de ganho ou perda total com base em cotações diárias.
4. Oráculo: Consulta a banco de dados com cotações diárias da moeda virtual em moeda real.
5. Ajuda e Créditos: Documentação de uso e informações sobre os autores do projeto.
6. Tecnologias Utilizadas
- Linguagem: C++ (padrão C++11)
- Interface: Linha de comando (CLI), com uso de cores para melhor experiência.
- Persistência de Dados: Implementações DAO (Data Access Object) para simulação em memória local.

Instruções para Compilação e Execução:
- Compilação com padrão C++11 e bibliotecas padrão.
- Scripts fornecidos para compilação em ambiente Linux.
- Para demonstração, utilize a implementação DAO em memória (sem necessidade de banco remoto).

