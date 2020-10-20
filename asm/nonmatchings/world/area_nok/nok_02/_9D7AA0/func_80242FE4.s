.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242FE4
/* 9DA004 80242FE4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9DA008 80242FE8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9DA00C 80242FEC 8C82000C */  lw        $v0, 0xc($a0)
/* 9DA010 80242FF0 0C0B1EAF */  jal       get_variable
/* 9DA014 80242FF4 8C450000 */   lw       $a1, ($v0)
/* 9DA018 80242FF8 0C03AC5A */  jal       func_800EB168
/* 9DA01C 80242FFC 0040202D */   daddu    $a0, $v0, $zero
/* 9DA020 80243000 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9DA024 80243004 24020002 */  addiu     $v0, $zero, 2
/* 9DA028 80243008 03E00008 */  jr        $ra
/* 9DA02C 8024300C 27BD0018 */   addiu    $sp, $sp, 0x18
