.include "macro.inc"

.section .data

glabel D_E00EAA50
.word 0x09001A00, 0x09001A20

glabel D_E00EAA58
.word 0x09001910, 0x00000000

glabel D_E00EAA60
.double 0.1

glabel D_E00EAA68
.double 0.01

glabel D_E00EAA70
.double -0.01, 0.0
