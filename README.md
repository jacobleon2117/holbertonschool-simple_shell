![Simple Shell](https://github.com/jacobleon2117/holbertonschool-simple_shell/assets/143765559/61dfd351-92a0-4d12-ae91-2d3aebe462cb)

![Vim](https://img.shields.io/badge/VIM-%2311AB00.svg?style=for-the-badge&logo=vim&logoColor=white) ![Visual Studio Code](https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white) ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

<details><summary>Table of Contents</summary>
  
- `Introduction`: <i>An introduction to the simple shell</i>
- `Files`: <i>Files used to make the simple shell</i>
- `Headers | Constants`: <i>Headers and Constants</i>
- `FlowChart`: <i>Flow process of the shell</i>
- `Installation | Compilation`: <i>How to install and compile this code</i></details>

<h1 align="center">Introduction</h1>

- `How does a shell work?`: <i>Shells provide a way for you to communicate with the operating system. This communication is carried out either interactively or as a shell script.</i>
- `How does my simple shell work?`: <i>My simple shell prompts the user for input, reads a command line, and executes the command using execlp. It supports basic commands, handles errors during execution, and displays the prompt again for further input. The user can exit the shell by entering 'exit' or 'quit', and the shell also handles the "end of file" condition (Ctrl+D).</i>

<h1 align="center">Files</h1>

- `shell_commands.h`: <i>Header file containing the function declaration for execute_command.</i>
- `shell_commands.c`: <i>Contains the implementation of the execute_command function.</i>
- `simple_shell.c`: <i>Main file that orchestrates the interaction with the user and calls the execute_command function.</i>

<h1 align="center">Headers | Constants</h1>

| Headers | Constants |
| ------------- | ------------- |
|  "shell_commands.h"  | MAX_INPUT_SIZE 1024|
|  <stdio.h>  |
|  <stdlib.h>  |
|  <string.h>  |

<h1 align="center">FlowChart</h1>

![Blank diagram](https://github.com/jacobleon2117/holbertonschool-simple_shell/assets/143765559/34eba705-5e7d-4abb-9d02-e20ae3d9356b)

<h1 align="center">Installation | Compilation</h1>

<h3 align="center">Fork this repo</h3>
<h3 align="center">https://github.com/jacobleon2117/holbertonschool-simple_shell</h3>

<h3 align="center">Use this code to compile the program</h3>

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

