# Background Context

A simple UNIX command interpreter.

“The Gates of Shell”, by [Spencer Cheng](https://intranet.alxswe.com/rltoken/AtYRSM03vJDrko9xHodxFQ), featuring [Julien Barbier](https://intranet.alxswe.com/rltoken/-ezXgcyfhc8qU1DeUInLUA)

# Resources

**Read or watch:**

[Unix shell](https://intranet.alxswe.com/rltoken/f0YU9TAhniMXWlSXtb64Yw)
[Thompson shell](https://intranet.alxswe.com/rltoken/7LJOp2qP7qHUcsOK2-F3qA)
[Ken Thompson](https://intranet.alxswe.com/rltoken/wTSu31ZP1f7fFTJFgRQC7w)
Everything you need to know to start coding your own shell concept page

man or help:

`sh` (Run `sh` as well)

# Learning Objectives

At the end of this project, you are expected to be able to [explain to anyone](https://intranet.alxswe.com/rltoken/9LNz86CtOTos9oL3zxIO3A), **without the help of Google**:

## General Research Made

- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of `main`
- How does the shell use the `PATH` to find the programs
- How to execute another program with the `execve` system call
- How to suspend the execution of a process until one of its children terminates
- What is `EOF` / “end-of-file”?

# Copyright - Plagiarism

- You are tasked to come up with solutions for the tasks below yourself to meet with the above learning objectives.
- You will not be able to meet the objectives of this or any following project by copying and pasting someone else’s work.
- You are not allowed to publish any content of this project.
- Any form of plagiarism is strictly forbidden and will result in removal from the program.

# Requirements

## General

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files end with a new line
- A README.md file
- code use the Betty style. checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
- Your shell not have any memory leaks
- No more than 5 functions per file
- All your header files include guarded
- Use system calls only when need to ([why?](https://intranet.alxswe.com/rltoken/EU7B1PTSy14INnZEShpobQ))
- README with the description of project
- have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see [Docker](https://intranet.alxswe.com/rltoken/UL8J3kgl7HBK_Z9iBL3JFg)

## GitHub

**_There should be one project repository per group. If you and your partner have a repository with the same name in both your accounts, you risk a 0% score. Add your partner as a collaborator._**

# More Info

## Output

- Unless specified otherwise, program have the exact same output as sh (/bin/sh) as well as the exact same error output.
- The only difference is when you print an error, the name of the program is equivalent to your argv[0] (See below)

Example of error with `sh`:

```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```

Same error with your program `hsh`:
```

$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

# List of allowed functions and system calls

- `access` (man 2 access)
- `chdir` (man 2 chdir)
- `close` (man 2 close)
- `closedir` (man 3 closedir)
- `execve` (man 2 execve)
- `exit` (man 3 exit)
- `_exit` (man 2 _exit)
- `fflush` (man 3 fflush)
- `fork` (man 2 fork)
- `free` (man 3 free)
- `getcwd` (man 3 getcwd)
- `getline` (man 3 getline)
- `getpid` (man 2 getpid)
- `isatty` (man 3 isatty)
- `kill` (man 2 kill)
- `malloc` (man 3 malloc)
- `open` (man 2 open)
- `opendir` (man 3 opendir)
- `perror` (man 3 perror)
- `read` (man 2 read)
- `readdir` (man 3 readdir)
- `signal` (man 2 signal)
- `stat` (_xstat) (man 2 stat)
- `lstat` (_lxstat) (man 2 lstat)
- `fstat` (_fxstat) (man 2 fstat)
- `strtok` (man 3 strtok)
- `wait` (man 2 wait)
- `waitpid` (man 2 waitpid)
- `wait3` (man 2 wait3)
- `wait4` (man 2 wait4)
- `write` (man 2 write)

# Compilation

shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

# Testing

shell should work like this in interactive mode:
```

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

But also in non-interactive mode:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## The "hsh" Shell

The "hsh" shell works when you follow these steps:

1. The user launches the shell by running the compiled executable.

2. The shell displays a prompt (e.g., `$ `) indicating that it is ready to receive a command.

3. The user enters a command, which is read by the shell.

4. The shell tokenizes the command into individual words, separating them based on whitespace characters.

5. The shell checks if the command is a built-in command. If it is, the corresponding built-in function is executed.

6. If the command is not a built-in, the shell searches for the command in the directories specified by the `PATH` environment variable. If the command is found, it is executed.

7. If the command is not found in the directories specified by `PATH`, an error message is displayed.

8. The shell waits for the execution of the command to complete.

9. The shell prints the prompt again, indicating that it is ready to receive the next command.

10. The above steps are repeated until the user exits the shell.


Additionally, the shell handles signals such as `Ctrl+C` (SIGINT) to ignore the keyboard interrupt and `Ctrl+D` (EOF) to exit the shell.


## Features

The "hsh" shell provides the following features:

- Execution of system commands.
- Handling command line arguments.
- Environment variable replacement.
- Variable assignment and substitution.
- Control operator (`;`) for command sequencing.
- Built-in commands, including `exit` and `env`.
- Ignoring keyboard interrupts (SIGINT) with `Ctrl+C`.
- Exiting the shell using `Ctrl+D` (EOF).

## Built-in Commands

The "hsh" shell supports the following built-in commands:

- `exit [STATUS]`: Exit the shell with an optional status.
- `env`: Display the current environment variables.

For more details on the usage and behavior of each built-in command, refer to the [Usage](#usage) section or consult the shell's help using the `help` command.

## Usage

To use the "hsh" shell, follow these steps:

1. Launch the shell by running the compiled executable.

2. The shell will display a prompt (e.g., `$ `).

3. Enter a command and press Enter to execute it.

4. The shell will execute the command and display the output, if any.

5. Enter another command or use any of the supported features.

6. To exit the shell, type `exit` and press Enter, or press `Ctrl+D`.

## Example Usage of "hsh" Shell

Here's an example of how to use the **"hsh" shell** for executing commands and utilizing its features:

1. Start the shell by running the executable:
   ```
   $ ./hsh
   ```

2. The shell will display a prompt indicating it's ready to accept commands:
   ```
   $
   ```

3. Execute a system command, such as listing the files in the current directory:
   ```
   $ ls
   file1.txt  file2.txt  directory
   ```

4. Verify the current directory has changed:
   ```
   $ pwd
   /path/to/directory
   ```

5. Display environment variables using the `env` command:
   ```
   $ env
   PATH=/usr/bin:/usr/local/bin:/usr/sbin
   HOME=/home/user
   ...
   ```

6. Exit the shell:
    ```
    $ exit
    ```


The **"hsh" shell** can also be used in non-interactive mode, where commands are read from a file or provided directly as input. Here's an example of using the shell in non-interactive mode:

### 1. Using files
1. Create a file named `commands.txt` containing the commands you want to execute:
   ```shell
   $ echo "ls" > commands.txt
   $ echo "pwd" >> commands.txt
   $ echo "echo Hello, world!" >> commands.txt
   ```

2. Run the **"hsh" shell** with the input file:
   ```shell
   $ ./hsh commands.txt
   ```
   The shell will read the commands from the file and execute them sequentially.

3. The output will be displayed for each command:
   ```shell
   file1.txt  file2.txt  directory
   /path/to/current/directory
   Hello, world!
   ```
### 2. using directly input

You can directly pass commands as input using command substitution or by piping the commands from another command's output. Here's an example:

1. Using command substitution:
   ```shell
   $ ./hsh <<< "ls -l"
   ```
   This command passes the `ls -l` command as input using command substitution (`<<<`). The shell will execute the command and display the output.

2. Piping commands from another command's output:
   ```shell
   $ echo "pwd" | ./hsh
   ```
   This command pipes the `echo "pwd"` command's output as input to the **"hsh" shell**. The shell will execute the command and display the output.

Both methods allow you to provide commands directly as input without the need for an intermediate file. You can customize the commands as per your requirements, and the shell will execute them accordingly.

#### Note
This is just a brief example of the **"hsh" shell** usage. Feel free to explore more commands, functionalities, and features provided by the shell. Refer to the documentation or source code for detailed instructions and additional information.

## Contributing

Contributions to the "hsh" shell project are welcome and encouraged. If you would like to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch for your contribution.
3. Make the necessary changes and commit them.
4. Push your

## Contact

For any questions, issues, or feedback, please contact us at [Perpetual Okorie](https://github.com/AmazedWonder)

Enjoy using **"hsh" shell** ^_^!
 simple_shell


