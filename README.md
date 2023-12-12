![Simple Shell](https://github.com/jacobleon2117/holbertonschool-simple_shell/assets/143765559/61dfd351-92a0-4d12-ae91-2d3aebe462cb)

![Vim](https://img.shields.io/badge/VIM-%2311AB00.svg?style=for-the-badge&logo=vim&logoColor=white) ![Visual Studio Code](https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white) ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

<details><summary>Table of Contents</summary>
  
- `Introduction`: <i>An introduction to the simple shell</i>
- `Files`: <i>Files used to make the simple shell</i>
- `Headers`: <i>Headers Used</i>
- `Installation | Compilation`: <i>How to install and compile this code</i></details>

<h1 align="center">Introduction</h1>

- `How does a shell work?`: <i>Shells provide a way for you to communicate with the operating system. This communication is carried out either interactively or as a shell script.</i>
- `How does my simple shell work?`: <i>My simple shell prompts the user for input, reads a command line, and executes the command using execlp. It supports basic commands, handles errors during execution, and displays the prompt again for further input. The user can exit the shell by entering 'exit' or 'quit', and the shell also handles the "end of file" condition (Ctrl+D).</i>

<h1 align="center">Files</h1>

<h1 align="center">Headers</h1>

| Headers | |
| ------------- | ------------- |
| #include  |  "shell_commands.h"  |
| #include  |  <stdio.h>  |
| #include  |  <stdlib.h>  |
| #include  |  <string.h>  |

<h1 align="center">Installation | Compilation</h1>

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
https://github.com/jacobleon2117/holbertonschool-simple_shell
