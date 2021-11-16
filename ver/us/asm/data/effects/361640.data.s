.include "macro.inc"

.section .data

dlabel D_E005C700
.word 0x09000F30

dlabel D_E005C704
.word 0x09000E00, 0x00000000, 0x00000000

dlabel D_E005C710
.double 0.1

dlabel D_E005C718
.double 0.04

dlabel D_E005C720
.double 0.9, 0.0
