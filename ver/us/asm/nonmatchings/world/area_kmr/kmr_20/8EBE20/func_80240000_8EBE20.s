.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_8EBE20
/* 8EBE20 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8EBE24 80240004 0000202D */  daddu     $a0, $zero, $zero
/* 8EBE28 80240008 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8EBE2C 8024000C 0C01553A */  jal       func_800554E8
/* 8EBE30 80240010 240501F4 */   addiu    $a1, $zero, 0x1f4
/* 8EBE34 80240014 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8EBE38 80240018 24020002 */  addiu     $v0, $zero, 2
/* 8EBE3C 8024001C 03E00008 */  jr        $ra
/* 8EBE40 80240020 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8EBE44 80240024 00000000 */  nop
/* 8EBE48 80240028 00000000 */  nop
/* 8EBE4C 8024002C 00000000 */  nop
