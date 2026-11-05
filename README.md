*This project was created as part of the 42 curriculum by mrosas-n.*

# ft_printf

## Description

ft_printf is a reimplementation of the `printf` function from the C standard
library (`libc`), developed as part of the 42 curriculum. The goal of the
project is to learn how a variadic function works in C: how it receives an
unknown number of arguments, how it reads them with the correct type, and how
it turns each one into text.

The function has the following prototype:

```c
int ft_printf(const char *format, ...);
```

It writes to the standard output and returns the number of characters printed,
or `-1` if `format` is `NULL` or ends with an incomplete `%`.

The project compiles into a static archive, `libftprintf.a`, which also contains
my `libft`. It can be reused in later projects of the cursus by linking a single
file.

## Instructions

### Compilation

The project is compiled with `cc` and the flags `-Wall -Wextra -Werror`, using
`ar` to generate the static library. The `libft` in the `libft/` directory is
built automatically.

```bash
make        # Builds libftprintf.a (and libft.a)
make clean  # Removes object files (.o), including those of libft
make fclean # Removes .o files, libftprintf.a and libft.a
make re     # Rebuilds everything from scratch (fclean + all)
```

The result is the `libftprintf.a` file at the root of the repository.

### Usage

To use the function in your own program, include the header and link against
`libftprintf.a` during compilation:

```c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("%s has %d%% of %c, %u, %x, %X and %p\n",
            "ft_printf", 100, 'c', 42u, 255u, 255u, (void *)0);
    ft_printf("Printed %d characters\n", len);
    return (0);
}
```

```bash
cc main.c -L. -lftprintf -o program
./program
```

```text
ft_printf has 100% of c, 42, ff, FF and (nil)
Printed 46 characters
```

- `-L.` tells the compiler to look for libraries in the current directory.
- `-lftprintf` links against `libftprintf.a` (the `lib` prefix and `.a` extension
  are omitted).

## Features

The following conversions are supported:

| Conversion | Argument type  | Output                                     |
| ---------- | -------------- | ------------------------------------------ |
| `%c`       | `int`          | A single character                         |
| `%s`       | `char *`       | A string, or `(null)` if the pointer is `NULL` |
| `%p`       | `void *`       | The address in hexadecimal with the `0x` prefix, or `(nil)` if it is `NULL` |
| `%d`       | `int`          | A signed decimal number                    |
| `%i`       | `int`          | A signed decimal number                    |
| `%u`       | `unsigned int` | An unsigned decimal number                 |
| `%x`       | `unsigned int` | A hexadecimal number in lowercase          |
| `%X`       | `unsigned int` | A hexadecimal number in uppercase          |
| `%%`       | None           | A literal percent sign                     |

Each conversion has its own function and source file:

| File                  | Function               | Used by                            |
| --------------------- | ---------------------- | ---------------------------------- |
| `ft_printf.c`         | `ft_printf`, `process` | Entry point                        |
| `ft_putchar_pf.c`     | `ft_putchar_pf`        | `%c`, `%%`, the sign of `%d`/`%i`  |
| `ft_putstr_pf.c`      | `ft_putstr_pf`         | `%s`                               |
| `ft_putnbr_pf.c`      | `ft_putnbr_pf`         | `%d`, `%i`                         |
| `ft_putunbr_pf.c`     | `ft_putunbr_pf`        | `%u`                               |
| `ft_puthex_pf.c`      | `ft_puthex_pf`         | `%x`, `%X`                         |
| `ft_putptr_pf.c`      | `ft_putptr_pf`         | `%p`                               |
| `ft_putnbr_base_pf.c` | `ft_putnbr_base_pf`    | `%d`, `%i`, `%u`, `%x`, `%X`, `%p` |

## Algorithm and data structures

### Algorithm

`ft_printf` reads the format string once, from left to right:

1. If `format` is `NULL`, it returns `-1`.
2. It starts the argument list with `va_start` and sets the counter to `0`.
3. Any character other than `%` is written directly and counted.
4. When it finds a `%`, it moves to the next character. If the string ends
   there, it closes the list and returns `-1`. Otherwise it calls `process`,
   which reads the next argument with the type that the conversion requires and
   calls the matching function.
5. At the end of the string, it closes the list with `va_end` and returns the
   counter.

A single pass is enough because the mandatory part has no flags, width or
precision. The character after the `%` fully defines the conversion, so there is
nothing to parse or store before printing.

Numbers in any base are printed by `ft_putnbr_base_pf`, a recursive function:

```c
if (nbr >= base_len)
    ft_putnbr_base_pf(nbr / base_len, counter, base);
write(1, &base[nbr % base_len], 1);
```

Dividing a number by its base produces its digits from right to left, but they
must be printed from left to right. The recursion solves this: each call first
handles the higher digits and then prints its own. For example, `255` in base 16
calls itself with `15`, which prints `f`, and then prints its own `f`.

I chose this approach for the following reasons:

- It needs no temporary buffer and no `malloc`, so it has no allocation that
  could fail or leak.
- The recursion depth is small and bounded: at most 16 levels for a 64-bit
  pointer in hexadecimal, and 10 for an `unsigned int` in decimal.
- The same function serves every base. The base is only a string of digits, so
  all the numeric conversions differ only in the string they pass.

### Data structures

The project does not need any dynamic data structure:

- `va_list` holds the position in the variable arguments. It is passed to
  `process` by pointer, because the C standard only guarantees that the caller
  can keep using the list after another function reads from it in that case.
- A single `size_t` counter is passed by pointer to every function, so they all
  add to the same total and can keep a `void` return type.
- The bases are constant strings (`DEC_BASE`, `LOWER_HEX_BASE`,
  `UPPER_HEX_BASE`), where the digit for a value is simply `base[value]`.

Output is not buffered. Each piece of text goes straight to `write`, which keeps
the code simple. A buffer would reduce the number of system calls, but it would
add state to manage, and the project has no need for that performance.

## Technical decisions

- The archive merges the object files of `libft` into `libftprintf.a`, so a
  program only has to link one library instead of two.
- `%d` and `%i` do not use `ft_itoa`, so printing a number never allocates memory
  and cannot fail because of `malloc`. `ft_putnbr_pf` prints the sign and passes
  the absolute value to `ft_putnbr_base_pf`.
- `ft_putnbr_pf` copies the number into a `long` before changing its sign,
  because negating `INT_MIN` would overflow in an `int`.
- `ft_putnbr_base_pf` takes a `uintptr_t`, which is wide enough for a pointer, so
  the same function handles `%p` and the 32-bit conversions. An `unsigned int`
  above `INT_MAX` also fits without overflow.
- A `format` that ends with an incomplete `%` returns `-1`, like the `printf` in
  Linux `glibc`. The C standard leaves this case undefined, but stopping there
  avoids reading past the end of the string.
- `(null)` and `(nil)` match the output of the `printf` in Linux `glibc`, which
  was the reference used for testing.
- Unknown conversions are ignored: nothing is printed and no argument is read.

## Resources

- The C manual pages: `man 3 printf` and `man 3 stdarg`.
- [cppreference](https://en.cppreference.com/) for variadic functions and the
  `printf` conversions.
- GNU Make documentation for writing the `Makefile`, in particular for building
  `libft` with a recursive `make`.
- The `ar` manual page for merging the two archives.
- Community `printf` testers, and a local test program comparing the output and
  return value of `ft_printf` and `printf`.

### Use of AI

During the development of this project, an AI assistant was used as occasional
support for:

- Explaining theoretical concepts (variadic functions, how to integrate `libft`
  into the `Makefile`).
- Debugging specific errors by identifying the root cause of failures in my own
  code.
- Assisting in the generation of test programs (`main`) to compare `ft_printf`
  with `printf`.

The logic and implementation of each function were developed and reasoned out by
me; the AI was used as a learning and verification tool, not as a source of
direct solutions.
