![]("https://www.holbertonschool.com/holberto\n-logo.png")

# First Semester Final Project - Basic Shell
In this project will be recreated the command line of linux shell.

## Simple Shell
This is a simple recreation on shell, it can execute the following builtins; **env**, **exit** (Can accept arguments)

## Flowchart
https://miro.com/welcomeonboard/Jid0XNzR38IYVh19v8Egn1HtRA3hdeMSqwfr6Npr4Vtyzj6l5GPFIrTaIZl0LtYR)

## Compilation Method
This program is wrote in C programming language and it's compiled using:
```Git Bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## How to Use
Run the shell typing **./hsh** it will show you a prompt and you can start typing commands

## Examples Of Use

### Interactive Mode
```Git Bash
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ ./hsh
$ /bin/ls
AUTHORS            hsh     man        shell_functions_five.c  shell_functions_one.c    shell_functions_two.c
holberton_shell.h  main.c  README.md  shell_functions_four.c  shell_functions_three.c
$ 
$ exit
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ ./hsh
$ /bin/ls
AUTHORS            hsh     man        shell_functions_five.c  shell_functions_one.c    shell_functions_two.c
holberton_shell.h  main.c  README.md  shell_functions_four.c  shell_functions_three.c
$ ls
AUTHORS  main.c                README.md               shell_functions_core.c  shell_functions_utility_2.c  shell.h
hsh      man_1_simple_shell.1  shell_functions_buff.c  shell_functions_path.c  shell_functions_utility.c

$ ls -l
total 60
-rw-rw-r-- 1 vagrant vagrant   179 Apr 14 15:57 AUTHORS
-rwxrw-r-- 1 vagrant vagrant 18606 Apr  6 22:06 hsh
-rw-rw-r-- 1 vagrant vagrant   934 Apr 14 02:07 main.c
-rw-rw-r-- 1 vagrant vagrant  2163 Apr 14 16:00 man_1_simple_shell.1
-rw-rw-r-- 1 vagrant vagrant  3872 Apr 14 16:02 README.md
-rw-rw-r-- 1 vagrant vagrant  2017 Apr 14 15:56 shell_functions_buff.c
-rw-rw-r-- 1 vagrant vagrant  1610 Apr 14 15:54 shell_functions_core.c
-rw-rw-r-- 1 vagrant vagrant  1908 Apr 14 15:54 shell_functions_path.c
-rw-rw-r-- 1 vagrant vagrant  1317 Apr 14 15:56 shell_functions_utility_2.c
-rw-rw-r-- 1 vagrant vagrant  1084 Apr 14 15:57 shell_functions_utility.c
-rw-rw-r-- 1 vagrant vagrant  1251 Apr 14 15:53 shell.h

$ 
$ exit
```

## Non-Interactive Mode
```Git Bash
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell/tests$ echo "/bin/ls -l" | ./hsh
total 60
-rw-rw-r-- 1 vagrant vagrant   179 Apr 14 15:57 AUTHORS
-rwxrw-r-- 1 vagrant vagrant 18606 Apr  6 22:06 hsh
-rw-rw-r-- 1 vagrant vagrant   934 Apr 14 02:07 main.c
-rw-rw-r-- 1 vagrant vagrant  2163 Apr 14 16:00 man_1_simple_shell.1
-rw-rw-r-- 1 vagrant vagrant  3510 Apr 14 16:05 README.md
-rw-rw-r-- 1 vagrant vagrant  2017 Apr 14 15:56 shell_functions_buff.c
-rw-rw-r-- 1 vagrant vagrant  1610 Apr 14 15:54 shell_functions_core.c
-rw-rw-r-- 1 vagrant vagrant  1908 Apr 14 15:54 shell_functions_path.c
-rw-rw-r-- 1 vagrant vagrant  1317 Apr 14 15:56 shell_functions_utility_2.c
-rw-rw-r-- 1 vagrant vagrant  1084 Apr 14 15:57 shell_functions_utility.c
-rw-rw-r-- 1 vagrant vagrant  1251 Apr 14 15:53 shell.h
```

---
### Authors
**Sebastian Toro Rodriguez** [Seb1776](https://github.com/Seb1776)
**Juan Felipe Balanta** [F-balanta](https://github.com/F-balanta)