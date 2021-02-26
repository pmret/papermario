.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80044B78
/* 1FF78 80044B78 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1FF7C 80044B7C AFB10014 */  sw        $s1, 0x14($sp)
/* 1FF80 80044B80 0080882D */  daddu     $s1, $a0, $zero
/* 1FF84 80044B84 AFBF0020 */  sw        $ra, 0x20($sp)
/* 1FF88 80044B88 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1FF8C 80044B8C AFB20018 */  sw        $s2, 0x18($sp)
/* 1FF90 80044B90 AFB00010 */  sw        $s0, 0x10($sp)
/* 1FF94 80044B94 8E30000C */  lw        $s0, 0xc($s1)
/* 1FF98 80044B98 8E330148 */  lw        $s3, 0x148($s1)
/* 1FF9C 80044B9C 8E050000 */  lw        $a1, ($s0)
/* 1FFA0 80044BA0 0C0B1EAF */  jal       func_802C7ABC
/* 1FFA4 80044BA4 26100004 */   addiu    $s0, $s0, 4
/* 1FFA8 80044BA8 0040902D */  daddu     $s2, $v0, $zero
/* 1FFAC 80044BAC 8E050000 */  lw        $a1, ($s0)
/* 1FFB0 80044BB0 0C0B1EAF */  jal       func_802C7ABC
/* 1FFB4 80044BB4 0220202D */   daddu    $a0, $s1, $zero
/* 1FFB8 80044BB8 0040802D */  daddu     $s0, $v0, $zero
/* 1FFBC 80044BBC 2402FFFF */  addiu     $v0, $zero, -1
/* 1FFC0 80044BC0 16420002 */  bne       $s2, $v0, .L80044BCC
/* 1FFC4 80044BC4 00000000 */   nop
/* 1FFC8 80044BC8 86720008 */  lh        $s2, 8($s3)
.L80044BCC:
/* 1FFCC 80044BCC 0C00FA6A */  jal       func_8003E9A8
/* 1FFD0 80044BD0 0240202D */   daddu    $a0, $s2, $zero
/* 1FFD4 80044BD4 AC50002C */  sw        $s0, 0x2c($v0)
/* 1FFD8 80044BD8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1FFDC 80044BDC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1FFE0 80044BE0 8FB20018 */  lw        $s2, 0x18($sp)
/* 1FFE4 80044BE4 8FB10014 */  lw        $s1, 0x14($sp)
/* 1FFE8 80044BE8 8FB00010 */  lw        $s0, 0x10($sp)
/* 1FFEC 80044BEC 24020002 */  addiu     $v0, $zero, 2
/* 1FFF0 80044BF0 03E00008 */  jr        $ra
/* 1FFF4 80044BF4 27BD0028 */   addiu    $sp, $sp, 0x28
