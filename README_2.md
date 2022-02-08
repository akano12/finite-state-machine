-Overview

We define the language L to consist of strings that represent certain email addresses
(specified below). For this assignment you are to design a DFA to recognize L and write
a program that implements your DFA.

2-The Language L

To precisely specify L, first define Γ = {a, b, c, . . . , z} as the set of lower-case Roman
letters. Also, define ∆ = {.} and Φ = {@}, and let Σ = Γ ∪ ∆ ∪ Φ; i.e., Σ is the set
consisting of all the lower-case Roman letters, the dot (or period), and the @ symbol.
Define the following sets of strings:
• S1 = ΓΓ∗, which consists of strings over Γ of length one or more
• S2 = ∆ΓΓ∗, which consists of strings starting with a dot and followed by one or
more symbols from Γ
• S3 = {.net}

Then we define the following sets of strings over Σ:
• L1 = S1 ΦS1 S3
• L2 = S1 S2∗ ΦS1 S2∗ S3
• L = L1 ∪ L2


Strings in L1 and L2 are (subsets of) email addresses.The specification of L does not
include all valid email addresses because we included
several restrictions to simplify the assignment. For example, only lower-case Roman
letters, dots, and the @ symbol are allowed, strings in L must end with .net, etc.

3-DFA for L

First construct a DFA M = (Q, Σ, δ, q1 , F ) that recognizes L. The DFA must satisfy
each of the following properties:
• The DFA must be defined with the above alphabet Σ. Your DFA does not have
to handle symbols that are not in Σ.
• The states in the DFA must be labeled q1 , q2 , q3 , . . . , qn , where q1 is the start
state and n is the number of states in the DFA. (It is also acceptable for the states
to be labeled q0 , q1 , . . . , qn−1 , with q0 the start state.)

You will lose points if your DFA is overly complicated (e.g., having more states than
necessary). To simplify your DFA drawing, you may omit any edges going from any
state q to a “trap state” (i.e., a non-accepting state from which the DFA can never
leave). All other edges must be included in your drawing. Clearly identify which state
is the trap state in the drawing of your DFA, and your drawing should include a note
stating that all edges not specified go to a trap state. Also, to simplify your drawing, you
should define Γ−ℓ = Γ − {ℓ} for any symbol ℓ ∈ Γ; i.e., Γ−ℓ is the set of all lower-case
Roman letters except for ℓ. For example, Γ−e = {a, b, c, d, f, g, . . . , z}, so your DFA
might include something like the following:
qj
e
qi
Γ−e

qk

Thus, if the DFA is currently in state qi , then it moves to qj on reading e, and it moves
to state qk on reading any other lower-case Roman letter. You could also define the
notation Γ−a,b = Γ − {a, b}.

4

Program Specifications

You must write your program in either C, C++, Java, or Python. All input/output
must be through standard input/output, and your program is to work as follows:


2. Your program next asks the user if they want to enter a string. The user then
enters “y” for “yes”, or “n” for “no”.
• If the user enters “n”, then the program terminates.
• If the user enters “y”, then the user is prompted to enter a string over Σ.

3. If the user chooses to input a string, your program then reads in the string. After
reading in the string, your program prints it. Then your program processes the
entire string on the DFA, one character at a time, in the following manner.
• Your program must begin in the start state of the DFA and print out the
name of that state (q1 or q0 ).
• After each character from the string is processed on the DFA, your program
must print out the character and the name of the current state of the DFA.
Even if your DFA is in a trap state, your program must do this for each
character in the string until it reaches the end of the string.

To simplify your program, you can check the ASCII code of each character of the
string and process on the DFA accordingly.
4. After processing the entire string on the DFA, your program must indicate if the
string is accepted or rejected based on the state in which the DFA ended. Your
program then should return to step 2.

5

Test Cases

Test your program on each of the following input strings:
1. foo@abcdef.net
2. z@n.net
3. ba@ba.ne
4. edfg@.net
5. webweb.ab.c.net@cs.defgh.net
6. foo@goo.net..net
7. abqe.@boom.net
8. educ@netw.netw
9. redblue@green..net
10. random@net
11. poke@a.net.net
12. www@net.nett
13. wwwb@net.ne
14. www.net@bbdef.net
15. food@for.net@
16. net@network.ne.net
17. network@network.net.ne
18. @abcde.net
19. people.dog.cat@.net
20. cable..cord@fort.net

You must create an output file containing your program’s output from each test case
in the order above.
