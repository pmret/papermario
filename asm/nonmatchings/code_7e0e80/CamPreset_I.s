.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel CamPreset_I
/* 7E1BD8 80280D58 10620138 */  beq   $v1, $v0, .L8028123C
/* 7E1BDC 80280D5C 0000102D */   daddu $v0, $zero, $zero
/* 7E1BE0 80280D60 080A0506 */  j     .L80281418
/* 7E1BE4 80280D64 00000000 */   nop   

.L80280D68:
/* 7E1BE8 80280D68 0C0B1059 */  jal   does_script_exist
/* 7E1BEC 80280D6C 8E240074 */   lw    $a0, 0x74($s1)
/* 7E1BF0 80280D70 144001A9 */  bnez  $v0, .L80281418
