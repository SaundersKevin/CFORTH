# FORTH

This is my FORTH implimentation based on the standards outlined at (forth-standard.org)[forth-standard.org].

Since I don't have enough time to impliment all of CORE, I will stay as true as I can while making some things a little easier.

# How it works

Currently, I have some things abstracted away.

The buffer is abstracted away, as well as functions

I use temperary variables in some of my functions that don't exist in data space

The return stack also exists in data space
The dictionary descends from the top while the data stack grows from the bottom
The return stack exists in a small window under the data stack, at 32 cells of space

Strings I have decided to treat as characters with an ENDSTRING character for simplicity

# List of valid words

## Memory Operations
* ! @ ,
## Stack Operations
* DROP DUP SWAP OVER
## Execution
* EXECUTE
