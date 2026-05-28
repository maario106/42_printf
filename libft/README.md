*This project was created as part of the 42 curriculum by mrosas-n.*

# Libft

## Description

Libft is my first C library, developed as part of the 42 curriculum.
The goal of the project is to reimplement from scratch a collection of
general-purpose functions, including several functions from the C standard
library (`libc`), additional string and memory manipulation functions, and a
set of functions for working with linked lists.

The library compiles into a static archive `libft.a` that can be reused and
extended in later projects of the cursus. The main purpose of the project is to
deeply understand how these utilities work at a low level: manual memory
management, pointer arithmetic, function pointers, and linked data structures.

## Instructions

### Compilation

The project is compiled with `cc` and the flags `-Wall -Wextra -Werror`, using
`ar` to generate the static library.

```bash
make        # Builds libft.a (mandatory part)
make clean  # Removes object files (.o)
make fclean # Removes .o files and libft.a
make re     # Rebuilds everything from scratch (fclean + all)
```

The result is the `libft.a` file at the root of the repository.

### Usage

To use the library in your own program, include the header and link against
`libft.a` during compilation:

```c
#include "libft.h"

int main(void)
{
    char *s = ft_strdup("Hello, libft!");
    ft_putendl_fd(s, 1);
    free(s);
    return (0);
}
```

```bash
cc main.c -L. -lft -o program
./program
```

- `-L.` tells the compiler to look for libraries in the current directory.
- `-lft` links against `libft.a` (the `lib` prefix and `.a` extension are omitted).

## Features

The library is organized into three blocks:

### Part 1 — `libc` functions

Reimplementations of standard functions: character classification
(`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`),
memory manipulation (`ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`,
`ft_memchr`, `ft_memcmp`, `ft_calloc`), string manipulation (`ft_strlen`,
`ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`,
`ft_strnstr`, `ft_strdup`), case conversion (`ft_toupper`, `ft_tolower`),
and string-to-integer conversion (`ft_atoi`).

### Part 2 — Additional functions

Functions that either do not belong to `libc` or behave differently:
`ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`,
`ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, and
`ft_putnbr_fd`.

### Part 3 — Linked lists

Functions to handle singly linked lists through the `t_list` structure:
`ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`,
`ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, and `ft_lstmap`.

A node's structure is:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

## Technical decisions

- Internal helper functions (for example those used by `ft_split` or `ft_itoa`)
  are declared as `static` to restrict their scope to the corresponding file and
  avoid polluting the library's namespace.
- `ft_itoa` uses an internal `long` to correctly handle the edge case `INT_MIN`,
  whose negation would cause overflow in an `int`.
- `ft_calloc` checks for overflow of the `nmemb * size` multiplication before
  allocating, using the condition `nmemb > SIZE_MAX / size`, preventing unsafe
  allocations.
- All allocated memory is properly freed; functions that may fail midway through
  an operation (such as `ft_split` or `ft_lstmap`) free what has been allocated
  so far before returning `NULL`.

## Resources

- The C manual pages (`man`) for each reimplemented function.
- [cppreference](https://en.cppreference.com/) for checking standard prototypes
  and behaviors.
- GNU Make documentation for writing the `Makefile`.
- Material on function pointers and linked lists in C.

### Use of AI

During the development of this project, an AI assistant was used as occasional
support for:

- Explaining theoretical concepts (function pointers, levels of indirection in
  linked lists, overflow detection, `ft_calloc` behavior).
- Debugging specific errors by identifying the root cause of failures in my own
  code (uninitialized variables, pointer arithmetic mistakes, memory leaks).
- Assisting in the generation of test programs (`main`) to verify the functions
  in isolation.

The logic and implementation of each function were developed and reasoned out by
me; the AI was used as a learning and verification tool, not as a source of
direct solutions.