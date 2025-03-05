# projeto_cadastros
# Sistema de Cadastro de Usuários

Este projeto implementa um sistema simples de cadastro de usuários utilizando a linguagem C e manipulação de arquivos.

## Funcionalidades

- **Registro de Usuários**: Permite cadastrar usuários inserindo CPF, nome, sobrenome e cargo.
- **Consulta de Usuários**: Busca informações de um usuário através do CPF.
- **Exclusão de Usuários**: Remove um registro baseado no CPF informado.
- **Interface Simples**: Exibe um menu no terminal para interação.

## Como Compilar e Executar

1. Certifique-se de ter um compilador C instalado, como o `gcc`.
2. Compile o programa com o seguinte comando:
   ```sh
   gcc main.c -o sistema
   ```
3. Execute o programa:
   ```sh
   ./sistema  # No Linux/Mac
   sistema.exe  # No Windows
   ```

## Estrutura do Projeto

```
/
├── main.c       # Código-fonte principal
├── README.md    # Documentação do projeto
```

## Melhorias Futuras

- Adicionar um banco de dados em vez de arquivos individuais.
- Melhorar a validação dos dados inseridos.
- Criar uma interface gráfica simples.
- Implementar login e autenticação.

## Licença

Este projeto é de livre uso para estudos e pode ser modificado conforme necessário.

