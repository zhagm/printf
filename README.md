# ft_printf

Regardless of the programming language considered, the printf function,(or its equivalents)
is always highly useful. The main reason is the ease of its formatting, and the
support of diverse types in variable numbers. Some variations even propose to be able to
write the resulting string of characters either in a file descriptor or in a particular stream.
Some also propose to recall this string without printing it. In short, undeniably, printf
is a vital function. In this project, we ask you to recode it and add it to your libft so that you can use it in all your future projects.

## Objectives
The key to a successful ft_printf is a well-structured and good extensible code. This
is because as time goes by, you will be more and more tempted to continue to extend
your ft_printf, making your life easier for your future projects.

## General Instructions
* Your function must be called ft_printf.
* Your project must be written in accordance with the Norm.
* You have to handle errors carefully. In no way can your program quit in an unexpected
manner (Segmentation fault, bus error, double free, etc).
* Your must submit a Makefile which will compile a libftprintf.a. This lib will be
linked to our testing main to give you your results.
* You’ll have to submit a file called author containing your username followed by a
’\n’ at the root of your repository.
* You are allowed to use the following functions:
    ◦ write
    ◦ malloc
    ◦ free
    ◦ exit
    ◦ The functions of man 3 stdarg

## Mandatory Part
* c - The first byte of argument is printed.
* s - Bytes from the string argument are printed until the end is reached or until the number of bytes indicated by the precision specification is reached; however if the precision is 0 or missing, the string is printed entirely.
* p - pointer address

* di - The argument is printed as a signed decimal (d or i)
* o - unsigned octal
* u - unsigned decimal
* xX - unsigned hexadecimal

* f with flags l and L - The argument is printed in the style [-]ddd.ddd where the number of d's after the decimal point is equal to the precision specification for the argument.  If the precision is missing, 6 digits are given; if the precision is explicitly 0, no digits and no decimal point are printed.  The values infinity and NaN are printed as inf and nan, respectively.

* %% - prints '%'

* \# - specifying that the value should be printed in an ''alternate form''.  For b, c, d, s and u formats, this option has no effect. For the o formats the precision of the number is increased to force the first character of the output string to a zero.  For the x (X) format, a non-zero result has the string 0x (0X) prepended to it.  For a, A, e, E, f, F, g and G formats, the result will always contain a decimal point, even if no digits follow the point (normally, a decimal point only appears in the results of those formats if a digit follows the decimal point). For g and G formats, trailing zeros are not removed from the result as they would otherwise be;
* - - specifies left adjustment of the output in the indicated field;
* + - specifying that there should always be a sign placed before the number when using signed formats.
* ' ' - specifying that a blank should be left before a positive number for a signed format. A '+' overrides a space if both are used;
* 0 - indicating that zero-padding should be used rather than blank-padding. A '-' overrides a '0' if both are used;

* Minimum field width - optional digit string that sets a min field width. If the output has fewer bytes than the min, it will be blank padded on the lef (or right, if the left adjustment indicator has been given (-)) to make up the field width. (note that a leading zero is a flag, but an embedded zero is part of a field width)

* Precision - An optional period, '.', followed by an optional digit string giving a precision which specifies the number of digits to appear after the decimal point, for e and f formats, or the maximum number of bytes to be printed from a string; if the digit string is missing, the precision is treated as zero;

# My Step-by-step Process
* Outline instruction pdf and understand each thing I'll be implementing for this project
* Read the man 3 stdarg page and understand how to use:
    - set param of function accepting a dynamic number of arguments to have ... ie. (char *str, ...) for printf
    - initialize variable of type va_list (named ap for example)
    - to initialize ap, first do va_start(ap, <last_variable_in_params_before_arg_list>(so va_start knows where to start the arg list)). Each call to va_start must be matched with va_end when done.
    - ap can be passed to va_arg(ap, <type_of_ap>) to get the next argument
    - each call to va_arg modifies ap so the next call to va_arg can return the next arg
    - if there's no next arg or the <type_of_ap> provided doesn't match with the arg, random errors will be thrown
* created a struct (t_arg) to hold properties of each argument
* Using the polytechnique website, figured out the order of flags/extras for each type and set up basic parsing, populating the t_arg with the info
*

# Helpful resources:
* man 3 stdarg
* https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html
* https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html
*
