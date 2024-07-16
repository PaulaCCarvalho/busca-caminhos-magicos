# Instruções de Uso

## Compilar a Aplicação

Para compilar a aplicação, execute o seguinte comando no terminal:

```bash
make
```

Este comando compilará todos os arquivos fonte e gerará o executável ***main***.

## Executar a Aplicação

Para executar a aplicação após a compilação e passar argumentos, utilize o comando:

```bash
make run ARGS="-i /path/input.txt -o /path/output.txt"
```
Neste exemplo:

- **"-i /path/input.txt"**:  especifica o caminho para o arquivo de entrada.
- **"-o /path/output.txt"**: especifica o caminho para o arquivo de saída.

## Limpar Arquivos Compilados

Para remover os arquivos gerados durante a compilação, execute:

```bash
make clean
```