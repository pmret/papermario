.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055D18
/* 31118 80055D18 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3111C 80055D1C 30A200FF */  andi      $v0, $a1, 0xff
/* 31120 80055D20 3C057F00 */  lui       $a1, 0x7f00
/* 31124 80055D24 AFBF0010 */  sw        $ra, 0x10($sp)
/* 31128 80055D28 0C0140DE */  jal       func_80050378
/* 3112C 80055D2C 00452825 */   or       $a1, $v0, $a1
/* 31130 80055D30 8FBF0010 */  lw        $ra, 0x10($sp)
/* 31134 80055D34 03E00008 */  jr        $ra
/* 31138 80055D38 27BD0018 */   addiu    $sp, $sp, 0x18
