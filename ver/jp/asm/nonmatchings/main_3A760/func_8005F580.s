.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F580
/* 3A980 8005F580 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3A984 8005F584 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3A988 8005F588 8C82000C */  lw        $v0, 0xc($a0)
/* 3A98C 8005F58C 8C430000 */  lw        $v1, ($v0)
/* 3A990 8005F590 8C450004 */  lw        $a1, 4($v0)
/* 3A994 8005F594 8C460008 */  lw        $a2, 8($v0)
/* 3A998 8005F598 0C01A41C */  jal       func_80069070
/* 3A99C 8005F59C 8C640000 */   lw       $a0, ($v1)
/* 3A9A0 8005F5A0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3A9A4 8005F5A4 03E00008 */  jr        $ra
/* 3A9A8 8005F5A8 27BD0018 */   addiu    $sp, $sp, 0x18
