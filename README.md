# eigenForth

A simple, mathematical, Forth-like programming language in modern C++.

## Currently supported features

- Integer Arithmetic (+, -, *, /)
- Basic Stack Manipulation (DUP, DUPN, DROP)
- If-Blocks (IF, END)
- Entering arbitrary Giac-expressions

## How to set it up
### Linux
#### Required Packages
The following requirements are needed for compiling this project:

- `cmake`
- `gcc` (or another reasonably modern C++-compiler)
- `libgiac-dev` (Ubuntu) | `giac-devel` (openSUSE)

Furthermore you need to clone or download this repository onto your computer.

#### Compiling

To compile the program, execute the following steps (starting in the the base folder of the repository):

- `mkdir build`
- `cd build`
- `cmake ..`
- `cmake --build . --parallel`

Now the program should be compiled.

#### Running
If you want to execute it, do as follows (still from within the build directory):

- `src/eigenforth`

### Windows
There is nothing Linux-specific about the program, so it should build on Windows.
There are no tried-out instructions for that, at the moment. - Feel free to try it and add those.


## How to use

At the moment eigenForth only supports interactive use.
This means once you start is, you can type in any command by hand.

Every line you enter is then parsed. If it is among the keywords mentioned above 
(defined in [Grammar.cpp](src/Grammar.cpp)), the appropriate action will be carried out.

If you enter something else, it is directly handed to Giac, which parses it and puts it on the stack.

After every line entered the current stack is printed out.

### Example Program #1

```
1
2
+
```

### Example Program #2

```
3
3
*
DUP
```

### Example Program #3

Note that the `IF`-keyword takes its condition from the top of the stack.
This means we have the ordering `condition IF executed-if-true END`.

```
1
IF
1
2
+
END
```
