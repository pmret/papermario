.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80065BEC
/* 40FEC 80065BEC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 40FF0 80065BF0 AFBF0010 */  sw        $ra, 0x10($sp)
.L80065BF4:
/* 40FF4 80065BF4 0C01B1A8 */  jal       func_8006C6A0
/* 40FF8 80065BF8 00000000 */   nop
/* 40FFC 80065BFC 1440FFFD */  bnez      $v0, .L80065BF4
/* 41000 80065C00 00000000 */   nop
/* 41004 80065C04 0C01B1B4 */  jal       func_8006C6D0
/* 41008 80065C08 24040125 */   addiu    $a0, $zero, 0x125
/* 4100C 80065C0C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 41010 80065C10 03E00008 */  jr        $ra
/* 41014 80065C14 27BD0018 */   addiu    $sp, $sp, 0x18
/* 41018 80065C18 00000000 */  nop
/* 4101C 80065C1C 00000000 */  nop
