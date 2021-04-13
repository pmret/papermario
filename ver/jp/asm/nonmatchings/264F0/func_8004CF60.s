.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CF60
/* 28360 8004CF60 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 28364 8004CF64 AFBF0010 */  sw        $ra, 0x10($sp)
/* 28368 8004CF68 8C860004 */  lw        $a2, 4($a0)
/* 2836C 8004CF6C 908200BC */  lbu       $v0, 0xbc($a0)
/* 28370 8004CF70 90C30045 */  lbu       $v1, 0x45($a2)
/* 28374 8004CF74 14620004 */  bne       $v1, $v0, .L8004CF88
/* 28378 8004CF78 00000000 */   nop
/* 2837C 8004CF7C 908500BF */  lbu       $a1, 0xbf($a0)
/* 28380 8004CF80 0C014D5D */  jal       func_80053574
/* 28384 8004CF84 00C0202D */   daddu    $a0, $a2, $zero
.L8004CF88:
/* 28388 8004CF88 8FBF0010 */  lw        $ra, 0x10($sp)
/* 2838C 8004CF8C 03E00008 */  jr        $ra
/* 28390 8004CF90 27BD0018 */   addiu    $sp, $sp, 0x18
