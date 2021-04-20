.include "macro.inc"

.section .data

glabel D_80077980
.word 0x8038F800, 0x803B5000, D_803DA800

glabel D_8007798C
.word 0x00163400, 0x0016C8E0, pause_set_cursor_opacity, pause_set_cursor_opacity, 0x80249B80, 0x80249B80, D_8024C080, D_8024C080, 0x8024C120

glabel D_800779B0
.word 0x00000000, 0x00000000, 0x00000000, 0x00000000
