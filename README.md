# get_next_line
Function for line-by-line reading. Project from Ecole42.

## Usage
- `make compile`: compile program.
- `make clean`: delete "out" and "gnl"(program).
- `make re`: make clean and recompile program.
- `make war`: run program with text "War and piece", write it into "out" and show you time.
- `make text`: run program with text "text", write it into "out" and show you time.
- `make null`: run program with text "null"(empty file), write it into "out" and show you time.

## Description
Function write in line which read from a
file descriptor, without the newline.

## Return value
`1` : A line has been read

`0` : EOF has been reached

`-1` : An error happened
