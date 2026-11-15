// -----------------------------------------------------------------------------
// 10_digraphs.c - alternative spellings for six punctuators
//
// Run:  scripts/run.sh 02-translation-and-lexical/10_digraphs.c
// -----------------------------------------------------------------------------
//
// Some national keyboards and character sets of the 1980s had no brackets,
// braces or number sign. C95 added six two-character tokens for them:
//
//     <:   [          <%   {          %:     #
//     :>   ]          %>   }          %:%:   ##
//
// A digraph is a token in its own right that means the same as the
// punctuator it replaces. It is recognised only where a token can start, so
// "<:" inside a string literal stays as it is.
//
// The header <iso646.h> does the same for operators, with macros:
//
//     and  &&      or   ||      not  !       xor  ^      compl  ~
//     bitand  &    bitor  |     not_eq  !=
//     and_eq  &=   or_eq  |=    xor_eq  ^=
//
// Nobody writes new code this way. Digraphs matter because the tokeniser
// still knows them, and obfuscated code uses them.

%:include <stdio.h>
%:include <iso646.h>

%:define JOIN(a, b) a %:%: b

int main(void) <%
    int values<:3:> = <% 10, 20, 30 %>;
    int JOIN(to, tal) = values<:0:> + values<:1:> + values<:2:>;

    if (total > 50 and not (total == 100)) <%
        printf("total = %d\n", total);
    %>

    // Not replaced inside a string literal.
    puts("<: and :> stay as they are in a string");
    return 0;
%>

// Output:
// total = 60
// <: and :> stay as they are in a string
