.include "macro.inc"

.section .data

glabel D_E0046600
.word 0x090002E8

glabel D_E0046604
.word 0x090003F0, 0x09000410, 0x090003F0, 0x09000430

glabel D_E0046614
.word 0x09000200

glabel D_E0046618
.word 0x09000308, 0x00000000

glabel D_E0046620
.double 0.1

glabel D_E0046628
.double 0.7

glabel D_E0046630
.double 0.4

glabel D_E0046638
.double 0.3

glabel D_E0046640
.double 0.1, 0.0
