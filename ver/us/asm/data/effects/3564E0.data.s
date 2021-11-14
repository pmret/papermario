.include "macro.inc"

.section .data

dlabel D_E0046600
.word 0x090002E8

dlabel D_E0046604
.word 0x090003F0, 0x09000410, 0x090003F0, 0x09000430

dlabel D_E0046614
.word 0x09000200

dlabel D_E0046618
.word 0x09000308, 0x00000000

dlabel D_E0046620
.double 0.1

dlabel D_E0046628
.double 0.7

dlabel D_E0046630
.double 0.4

dlabel D_E0046638
.double 0.3

dlabel D_E0046640
.double 0.1, 0.0
