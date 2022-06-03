# Linux-Terminal-Clone-
My personal attempt at implementing a linux terminal using C. Currently, it supports every command and, additionally, is capable of executing two piped commands


The terminal is capable of executing the standard commands found in Bash, Zsh, and so on. Besides that, some commands (mv, rm, dir, ls) are custom implemented by me. 
The other commands are exectuted using a child process, which runs the respective command.

The terminal is also able to execute piped commands, where the output of the first is treated as input for the second. However, it is a bit buggy. Some combinations work,
others don't.
