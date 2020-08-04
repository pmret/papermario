.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel does_script_exist_by_ref
/* 0E8B54 802C41A4 0000282D */  daddu $a1, $zero, $zero
/* 0E8B58 802C41A8 3C03802E */  lui   $v1, 0x802e
/* 0E8B5C 802C41AC 8C63A890 */  lw    $v1, -0x5770($v1)
.L802C41B0:
/* 0E8B60 802C41B0 8C620000 */  lw    $v0, ($v1)
/* 0E8B64 802C41B4 14820003 */  bne   $a0, $v0, .L802C41C4
/* 0E8B68 802C41B8 24A50001 */   addiu $a1, $a1, 1
/* 0E8B6C 802C41BC 03E00008 */  jr    $ra
/* 0E8B70 802C41C0 24020001 */   addiu $v0, $zero, 1

.L802C41C4:
/* 0E8B74 802C41C4 28A20080 */  slti  $v0, $a1, 0x80
/* 0E8B78 802C41C8 1440FFF9 */  bnez  $v0, .L802C41B0
/* 0E8B7C 802C41CC 24630004 */   addiu $v1, $v1, 4
/* 0E8B80 802C41D0 03E00008 */  jr    $ra
/* 0E8B84 802C41D4 0000102D */   daddu $v0, $zero, $zero

