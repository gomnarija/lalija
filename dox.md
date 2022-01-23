# Documentation
### Basic Structure
lalija interpreter follows the REPL structure when interacting with users:
```
    LOOP(
        PRINT(EVAL(READ()))
        )
```
Interpreter reads in an expression, evaluates it, prints out the result and awaits the next expression.
```
    laza>(+ 2 2)
    4
    laza>
``` 
### Atoms
Atoms are basic building blocks in lalija. 
An atom is a string of contiguous characters, 
which can include numbers and special characters.
Examples of valid atoms:
```
    26
    "zdravo svete"
    saberi-dva-broja
    /|\
``` 
There are 3 atom types in lalija:
- Numbers
- Strings
- Symbols
##### -Numbers
Numbers are atoms that start with a digit, followed by another digit or '.' character.
Valid number atoms:
```
    26
    666
    6.9
    0
``` 
Numbers are self-evaluating:
```
    laza>26
    26
    laza>
``` 
##### -Strings
Strings are atoms that are encapsulated within two '"' characters.
Valid string atoms:
```
    "zdravo svete"
    ""
    "26"
``` 
Strings are self-evaluating:
```
    laza>"zdravo svete"
    "zdravo svete"
    laza>
``` 
##### -Symbols
Symbols are atoms that don't start with a digit, '(' or '"'. Symbols can't contain whitespaces.
Valid symbol atoms:
```
    zdravo-svete
    x
    x26
``` 
In lalija symbols are used as environmental variables.
They represent bindings to values or functions.
```
    laza>(val x 26)
    x
    laza>x
    26
    laza>(function get-x () x)
    get-x
    laza>(get-x)
    26
``` 
 ### Lists
 Lists are collections of one or more atoms, or lists.
 Elements in a list are separated by white space, and surrounded by brackets.
 Valid lists:
 ```
   ()
   (+ 2 2)
   (factorial 5)
   (("zdravo" "svete") "zdravo svete")
``` 
lalija uses prefix notation, so when evaluating lists first element
is taken as a symbol that represents a function, 
and the rest of the elements are arguments for that function.
 ```
   (* 3 26)
   (< (+ 25 26) 50 )
   (moja-funkcija "stogod")
``` 
  ### Variables
  User defined variables in lalija are stored in environments, with a
  symbol that represents given value.
  ```
    (val promenljiva "vrednost")
    (set promenljiva 26)
    (fset nova-promenljiva promenljiva)
``` 
  Each of these functions changes only the current environment.
  - val - creates new variable.
  - set - changes variable value, only if variable exists.
  - fset - if variable exists, change it's value, if not, create new one
 ### Functions
To define a new function in lalija use 'function' function.
  ```
    (function +1 (n) (+ n 1))
``` 
The example from above will create a new function called +1,
with argument n and body (+ n 1).
To call above defined function:
  ```
    laza>(+1 25)
    26
    laza>
``` 
Functions can contain multiple expressions in it's body and only return the last one.
  ```
    (function fun (n) (+ n 1) (- n 1))
``` 
When evaluating functions a new environment is created, which gets deleted when evaluating the function is done.
  ```
    laza>(val x 26)
    x
    laza>x
    26
    laza>(function stogod () (val x 35) x)
    stogod
    laza>(stogod)
    35
    laza>x 
    26
    laza>
``` 
Recursion:
  ```
  laza>(function factorial (n) 
            (if (= n 1) n (* (factorial (-  n 1)) n)))
factorial
laza>(factorial 5)
120
laza>
``` 
### Conditioning
In lalija truth values are represented with 1(T) and Nil(F).
Operator for checking truth values is ?
  ```
  (? 1) => 1
  (? 0) => Nil
  (? "stogod") => 1
  (? "") => Nil
``` 
lalija also supports basic logic operators.
```
  (= 1 1) => 1
  (< 1 2) => Nil
  (>= 2 2) => 1
  (& 1 Nil) => Nil
``` 
The if function:
```
  (if (= 1 1) "true" "false") => "true"
  (if (| (= 1 2) (> 3 5)) "true" "false") => "false"
``` 
If condition is true, first expression is evaluated, if not, the second one.
### Environments
Environmets hold bindings.
At the start of the REPL global environment gets created and set as the
current one. After that every other one that gets created holds the 
previous one as the upper environment, and becomes the current one.
Different environments can contain same symbols.
When searching for a binding, current environment gets searched, and
if it doesn't contain a given symbol, the upper one comes next, 
and so on.
To create an environment, other than functions, we can use 'let'.
```
  laza>(val x 26)
  x
  laza>(let ((x 32) (y 32)) (set x 64) (+ x y))
  96   
  laza>x
  26
  laza>
``` 
