.include "macro.inc"

.section .data

dlabel D_E0022CD0
.word 0x09001210, 0x09001228, 0x09001240, 0x09001258, 0x09001270, 0x090011C8, 0x090011E0, 0x090011F8

dlabel D_E0022CF0
.word 0xFEACACFE, 0xACD5FEB4, 0x9AD5B4FE, 0xB4B4FEB4, 0xDDFEB4FE, 0xFEB4FED5, 0xB4FEB4D5, 0xFEB4FEFE, 0xB4FED5AC

dlabel D_E0022D14
.word 0x1E3C505F, 0x64686A00

dlabel D_E0022D1C
.ascii "<Zdhjlm\0\0\0\0\0\0\0\0\0\0\0\0\0"

dlabel D_E0022D30
.word 0xE00221DC, 0xE0022318, 0xE0022318, 0xE00223EC, 0xE00223EC, 0x00000000

dlabel D_E0022D48
.double 0.05

dlabel D_E0022D50
.double 0.05

dlabel D_E0022D58
.double 0.01

dlabel D_E0022D60
.double 0.96

dlabel D_E0022D68
.double 0.1

dlabel D_E0022D70
.double -0.02

dlabel D_E0022D78
.double 0.9
