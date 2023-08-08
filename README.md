# LIE
Lie - **LI**ne **E**ditor or **L**ie **I**s **E**ditor. 

This is line text editor inspired by *ed*. Now it in early alpha.

## Why I write this editor?

I like using ed for small tasks like config editing. It is very light and simple.
Currently I am learning C++ and I think it is good project to test my skills.

So I decided to write my own ed, but better. 

## What are differences between ed and lie?

1. As I know, ed is written in C and lie is written in C++
2. Lie shows **normal** error messages, not "?" :)
3. Some commands have different names
4. I want to create other helpful commands
5. Lie has different syntax. Lie command pattern is:
```
command_name arg1 keyword_arg1=value1 arg2 keyword_arg2=value2
```
(Args are optional)

6. Lie has `help` command like in *Vi*

## Installation

Dependencies: `gcc`, `make`

Clone this repository and `cd` into.

Run `make`. Then you can move `lie` binary file to `/usr/bin`, `~/.local/bin`, etc path in your PATH.

## Usage

Lie is **VERY UNSTABLE AND IN EARLY ALPHA**, so I recommend use it only for fun and editing not important files, not for serious work.

After intstallation run it: `./lie`. You can see `1> ` command prompt. `1` is current line number. Try to type: `help help`. You get help about help command. Command `h h` does same thing.

To open a file in it, run `./lie file`. Then type `print` or `p` to see file content. Loaded file is called *buffer*.

Now these commands are implemented:
- `q[uit]` - quits the editor
- `h[elp] command` - prints help about command.
- `o[pen] file` - loads file to buffer 
- `p[rint]` - prints buffer content.
- `g[oto] line` - changes current line number.
- `c[hange] line` - edits line if passed, if not -- edits current line

## Contribution

There is no contribution guide, but you can contact me `stepanzubkov@florgon.com`. Or `@stepan-zubkov:matrix.org` at matrix.

## Help

If you like my work, you can donate me. Contact me `stepanzubkov@florgon.com` to donate.

## License
Copyright (C) 2023 Stepan Zubkov <stepanzubkov@florgon.com>

This program is Free Software and licensed under GNU GPL version 3 or later (You can choose version 3 or any version later then 3). 

See `COPYING` file for more.


