.macro glabel label
    .global \label
    .type \label, @function
    \label:
.endm
