.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021AE70_626A10
/* 626A10 8021AE70 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 626A14 8021AE74 AFBF0010 */  sw        $ra, 0x10($sp)
/* 626A18 8021AE78 0C051C83 */  jal       func_8014720C
/* 626A1C 8021AE7C 00000000 */   nop
/* 626A20 8021AE80 8FBF0010 */  lw        $ra, 0x10($sp)
/* 626A24 8021AE84 03E00008 */  jr        $ra
/* 626A28 8021AE88 27BD0018 */   addiu    $sp, $sp, 0x18
/* 626A2C 8021AE8C 00000000 */  nop
