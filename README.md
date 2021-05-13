# get_next_line
Function for line-by-line reading. Project from Ecole42.

## Usage
1. Emm... look at main and figure it out.
2. Compile file with `gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -I get_next_line.h -o gnl`.
3. Write in terminal `./gnl`.

## Description
Function write in line which read from a
file descriptor, without the newline.

## Return value
`1` : A line has been read

`0` : EOF has been reached

`-1` : An error happened
