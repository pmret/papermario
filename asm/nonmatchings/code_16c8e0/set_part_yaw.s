.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_part_yaw
/* 19287C 80263F9C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 192880 80263FA0 AFB00010 */  sw        $s0, 0x10($sp)
/* 192884 80263FA4 00A0802D */  daddu     $s0, $a1, $zero
/* 192888 80263FA8 AFB10014 */  sw        $s1, 0x14($sp)
/* 19288C 80263FAC AFBF0018 */  sw        $ra, 0x18($sp)
/* 192890 80263FB0 0C09A75B */  jal       get_actor
/* 192894 80263FB4 00C0882D */   daddu    $s1, $a2, $zero
/* 192898 80263FB8 0040202D */  daddu     $a0, $v0, $zero
/* 19289C 80263FBC 0C099117 */  jal       get_actor_part
/* 1928A0 80263FC0 0200282D */   daddu    $a1, $s0, $zero
/* 1928A4 80263FC4 44910000 */  mtc1      $s1, $f0
/* 1928A8 80263FC8 00000000 */  nop       
/* 1928AC 80263FCC 46800020 */  cvt.s.w   $f0, $f0
/* 1928B0 80263FD0 E4400064 */  swc1      $f0, 0x64($v0)
/* 1928B4 80263FD4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1928B8 80263FD8 8FB10014 */  lw        $s1, 0x14($sp)
/* 1928BC 80263FDC 8FB00010 */  lw        $s0, 0x10($sp)
/* 1928C0 80263FE0 03E00008 */  jr        $ra
/* 1928C4 80263FE4 27BD0020 */   addiu    $sp, $sp, 0x20
