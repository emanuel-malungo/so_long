# 🎮 so_long

> Jogo 2D simples desenvolvido em C utilizando a biblioteca gráfica **MiniLibX**, como parte do currículo da [42 School](https://42.fr).

O jogador navega por um mapa em vista de cima, recolhe todos os coleccionáveis e alcança a saída no menor número de movimentos possível.

---

## 📋 Índice

- [Sobre o Projecto](#-sobre-o-projecto)
- [Funcionalidades](#-funcionalidades)
- [Arquitectura](#-arquitectura)
- [Pré-requisitos](#-pré-requisitos)
- [Compilação e Execução](#-compilação-e-execução)
- [Controlos](#-controlos)
- [Formato do Mapa](#-formato-do-mapa)
- [Pipeline de Validação](#-pipeline-de-validação)
- [Estrutura de Directórios](#-estrutura-de-directórios)
- [Autor](#-autor)

---

## 🕹 Sobre o Projecto

**so_long** é um pequeno jogo 2D com as seguintes regras:

1. O jogador (`P`) movimenta-se num mapa rectangular delimitado por paredes (`1`).
2. Deve recolher **todos** os coleccionáveis (`C`) espalhados pelo mapa.
3. Só depois de recolher todos os coleccionáveis é que a saída (`E`) se torna acessível.
4. A cada movimento, o contador é incrementado e impresso no terminal.
5. O jogo termina quando o jogador atinge a saída com todos os coleccionáveis recolhidos, ou quando fecha a janela / pressiona `ESC`.

O projecto foi desenvolvido seguindo as normas da **42** (Norminette), sem fugas de memória e compilado com as flags `-Wall -Wextra -Werror`.

---

## ✨ Funcionalidades

| Funcionalidade | Descrição |
|---|---|
| **Renderização com texturas XPM** | Cada elemento do mapa (chão, parede, jogador, coleccionável, saída) é representado por uma sprite `.xpm` personalizada |
| **Validação robusta do mapa** | Verifica forma rectangular, paredes fechadas, caracteres válidos, quantidade de elementos e acessibilidade via flood fill |
| **Contador de movimentos** | Cada passo do jogador é contado e apresentado no terminal em tempo real |
| **Gestão de memória** | Alocação dinâmica com libertação completa de todos os recursos (imagens, janela, mapa, estruturas) |
| **Múltiplos mapas de teste** | 21 mapas válidos + 13 mapas inválidos para testes abrangentes |

---

## 🏗 Arquitectura

O projecto está organizado em módulos com responsabilidades bem definidas:

```
so_long.c              → Ponto de entrada (main)
├── input_validation.c → Validação dos argumentos e extensão .ber
├── parse_map.c        → Leitura do ficheiro e parsing do mapa
├── map_validation.c   → Validação da forma, paredes e caracteres
├── check_path_map.c   → Flood fill para verificar caminhos válidos
├── game.c             → Inicialização do jogo, janela e loop de eventos
├── render.c           → Carregamento de texturas e desenho do mapa
├── player_movement.c  → Lógica de movimentação (W/A/S/D e setas)
├── check_collection.c → Verificação de coleccionáveis ao atingir a saída
└── utils.c            → Funções auxiliares (init, free, copy, print)
```

### Estruturas de Dados Principais

```c
t_game  → Estrutura principal: ponteiros MLX, janela, imagens, mapa e jogador
t_map   → Buffer de leitura, grelha 2D (char **), dimensões e file descriptor
t_play  → Posição do jogador (x, y), contadores de P/E/C e movimentos
t_point → Par de coordenadas (x, y) usado no flood fill
```

---

## 📦 Pré-requisitos

| Dependência | Motivo |
|---|---|
| `gcc` ou `cc` | Compilador C |
| `make` | Sistema de build |
| **MiniLibX** | Biblioteca gráfica (incluída como submódulo em `mlx/`) |
| `libXext` | Extensões X11 |
| `libX11` | Interface com o servidor X |
| `libm` | Funções matemáticas |
| `libz` | Compressão (usado pelo MiniLibX) |

### Instalar dependências no Ubuntu/Debian:

```bash
sudo apt-get update
sudo apt-get install gcc make libx11-dev libxext-dev libbsd-dev
```

> **Nota:** A MiniLibX deve estar presente no directório `mlx/` na raiz do projecto.

---

## 🔨 Compilação e Execução

```bash
# Compilar o projecto
make

# Executar com um mapa válido
./so_long map/valid/map4.ber

# Limpar ficheiros objecto
make clean

# Limpar tudo (objectos + executável)
make fclean

# Recompilar do zero
make re
```

---

## 🎮 Controlos

| Tecla | Acção |
|---|---|
| `W` / `↑` | Mover para cima |
| `A` / `←` | Mover para a esquerda |
| `S` / `↓` | Mover para baixo |
| `D` / `→` | Mover para a direita |
| `ESC` | Sair do jogo |
| Botão ✕ da janela | Sair do jogo |

---

## 🗺 Formato do Mapa

Os mapas utilizam o formato `.ber` — ficheiros de texto com os seguintes caracteres:

| Caractere | Elemento |
|---|---|
| `1` | Parede |
| `0` | Espaço livre |
| `P` | Posição inicial do jogador (exactamente 1) |
| `E` | Saída (exactamente 1) |
| `C` | Coleccionável (pelo menos 1) |

### Exemplo de mapa válido (`map4.ber`):

```
1111111111
1P00000001
1000111111
1000010001
101C001001
1000000C01
1010000001
100C000001
1000000E01
1111111111
```

### Regras do mapa:

- Deve ser **rectangular**
- Deve estar completamente rodeado por **paredes** (`1`)
- Deve conter **exactamente 1** jogador (`P`) e **1** saída (`E`)
- Deve conter **pelo menos 1** coleccionável (`C`)
- Apenas os caracteres `0`, `1`, `P`, `E`, `C` são permitidos
- Não pode conter **linhas vazias** (newlines consecutivos)
- Não pode **começar nem terminar** com newline
- Deve existir um **caminho válido** do jogador até à saída e todos os coleccionáveis

---

## 🔍 Pipeline de Validação

O mapa passa por uma cadeia rigorosa de verificações antes do jogo iniciar:

```
Argumentos (argc == 2)
    │
    ▼
Extensão .ber
    │
    ▼
Leitura do ficheiro → buffer dinâmico com realloc
    │
    ▼
Verificação de newlines inválidos no buffer
    │
    ▼
Parsing com ft_split('\n') → grelha 2D
    │
    ▼
Contagem de elementos (P=1, E=1, C≥1)
    │
    ▼
Forma rectangular (todas as linhas com o mesmo comprimento)
    │
    ▼
Paredes fechadas (bordas compostas apenas por '1')
    │
    ▼
Caracteres válidos (apenas 0, 1, P, E, C)
    │
    ▼
Flood fill a partir de P → todos os C e E devem ser alcançáveis
    │
    ▼
✅ Jogo inicia
```

Se qualquer validação falhar, o programa imprime uma mensagem de erro descritiva em `stderr` e termina com `EXIT_FAILURE`.

---

## 📁 Estrutura de Directórios

```
so_long/
├── Makefile                 # Sistema de build
├── README.md                # Este ficheiro
├── include/
│   └── so_long.h            # Header principal com structs e protótipos
├── src/
│   ├── so_long.c            # main()
│   ├── input_validation.c   # Validação de argumentos
│   ├── parse_map.c          # Leitura e parsing do mapa
│   ├── map_validation.c     # Validação estrutural do mapa
│   ├── check_path_map.c     # Flood fill (verificação de caminhos)
│   ├── game.c               # Inicialização e loop do jogo
│   ├── render.c             # Carregamento de texturas e renderização
│   ├── player_movement.c    # Movimentação do jogador
│   ├── check_collection.c   # Lógica de recolha e condição de vitória
│   └── utils.c              # Funções utilitárias
├── libft/                   # Biblioteca libft (reimplementação de libc)
├── mlx/                     # MiniLibX (biblioteca gráfica)
├── texture/                 # Sprites XPM (chão, parede, jogador, etc.)
└── map/
    ├── valid/               # 21 mapas válidos para jogar
    └── invalid/             # 13 mapas inválidos para testes de erro
```

---

## 👤 Autor

**Emanuel Malungo** (emalungo)
- 42 Intra: [emalungo](https://profile.intra.42.fr/users/emalungo)

---

<p align="center">
  Desenvolvido com ❤️ na <strong>42 School</strong>
</p>
