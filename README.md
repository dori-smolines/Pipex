*This project has been created as part of the 42 curriculum by smolines.*

# pipex

## Description

`pipex` is a 42 School project that explores a UNIX mechanism you already use every day in the shell: **pipes**. The goal is to reimplement, in C, the behavior of a shell pipeline like:

```bash
< file1 cmd1 | cmd2 > file2
```

The program takes 4 arguments — an input file, two commands (with their own arguments), and an output file — and reproduces exactly what the shell does: it redirects `file1` as input to `cmd1`, pipes `cmd1`'s output into `cmd2`, and redirects `cmd2`'s output into `file2`.

This project is a deep dive into:
- Process creation and management (`fork`)
- Inter-process communication via `pipe`
- File descriptor redirection (`dup2`)
- Program execution (`execve`) and `PATH` resolution
- Proper error handling and process synchronization (`wait`/`waitpid`)

**Status:** Solo project — mandatory part only, no bonus (no multiple pipes, no `here_doc`).

## Instructions

### Compilation

```bash
make
```

This compiles the source files according to the Norm and produces the `pipex` executable. The Makefile includes the required `$(NAME)`, `all`, `clean`, `fclean`, and `re` rules, without unnecessary relinking.

### Usage

```bash
./pipex file1 cmd1 cmd2 file2
```

- `file1` — input file, used as standard input for `cmd1`
- `cmd1` — first shell command (with its arguments, passed as a single quoted string)
- `cmd2` — second shell command (with its arguments, passed as a single quoted string)
- `file2` — output file, receiving the standard output of `cmd2`

### Example

```bash
./pipex infile "ls -l" "wc -l" outfile
```

This behaves exactly like:

```bash
< infile ls -l | wc -l > outfile
```

Another example:

```bash
./pipex infile "grep a1" "wc -w" outfile
```

Equivalent to:

```bash
< infile grep a1 | wc -w > outfile
```

### How it works

1. `main` validates that exactly 4 arguments were given, then creates a pipe with `pipe()`.
2. A first child process (`fork`) is created: it redirects `file1` onto its standard input and the write end of the pipe onto its standard output, resolves `cmd1`'s executable path, and runs it with `execve`.
3. A second child process is created: it redirects the read end of the pipe onto its standard input and `file2` onto its standard output, resolves `cmd2`'s executable path, and runs it with `execve`.
4. The parent process closes both ends of the pipe and waits for the second child to finish, returning its exit status.

Executable path resolution is handled by parsing the `PATH` environment variable and checking each candidate path with `access()`, so commands don't need to be given as absolute paths.

### Error handling

The program follows the same behavior as the equivalent shell command for invalid input files, missing commands, or permission issues, and cleans up all allocated resources and open file descriptors before exiting.

## Resources

- `man` pages: `pipe(2)`, `fork(2)`, `execve(2)`, `dup2(2)`, `wait(2)`, `waitpid(2)`
- General documentation on UNIX inter-process communication and file descriptor manipulation
- Class references and peer discussions on process management in C

**AI usage:** AI assistance was used to help draft and structure this README file (organizing sections, describing the program's behavior and usage) based on the actual project source code and the official subject requirements. No AI-generated code was used in the implementation of `pipex` itself; all process handling, piping, and execution logic were written and understood by the author.

## Project Structure

```
.
├── Makefile
├── include/
│   └── pipex.h
└── src/
    ├── pipex.c          # main entry point, fork/pipe orchestration, exec of both commands
    ├── cmd.c            # command parsing and PATH resolution
    ├── error.c          # error handling and messages
    ├── free.c           # memory and file descriptor cleanup helpers
    ├── freesuite.c      # additional cleanup helpers
    ├── ft_split.c       # string splitting (libft)
    ├── ft_strdup.c      # string duplication (libft)
    ├── ft_strjoin.c     # string joining (libft)
    ├── ft_strncmp.c     # string comparison (libft)
    ├── ft_strrchr.c     # reverse character search (libft)
    └── ft_substr.c      # substring extraction (libft)
```
