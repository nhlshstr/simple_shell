# Simple Shell
A functional shell that works the same as the sh. This Simple Shell will work in both interactive and non-interactive mode.

## Getting Started
The project was written in C programming language. When compiled, it will function as the shell terminal.

**Compilation and Implementation**

After you have cloned this Repo you will compile, using the following flags:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Testing
After the Shell is compiled it should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
And also in non-interactive mode:
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
## Project restrictions

This is the list of allowed functions and system calls for the making of this pro\
ject.

```
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
fork (man 2 fork)
free (man 3 free)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
getcwd (man 3 getcwd)
getline (man 3 getline)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)
_exit (man 2 _exit)
isatty (man 3 isatty)
fflush (man 3 fflush)
```
## Authors
Nehal Shastri, Raudo Rivas