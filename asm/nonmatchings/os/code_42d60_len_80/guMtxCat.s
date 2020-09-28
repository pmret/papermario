.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel guMtxCat
/* 42D60 80067960 27BDFF20 */  addiu     $sp, $sp, -0xe0
/* 42D64 80067964 00801021 */  addu      $v0, $a0, $zero
/* 42D68 80067968 AFB100D4 */  sw        $s1, 0xd4($sp)
/* 42D6C 8006796C 00A08821 */  addu      $s1, $a1, $zero
/* 42D70 80067970 AFB200D8 */  sw        $s2, 0xd8($sp)
/* 42D74 80067974 00C09021 */  addu      $s2, $a2, $zero
/* 42D78 80067978 27A40010 */  addiu     $a0, $sp, 0x10
/* 42D7C 8006797C 00402821 */  addu      $a1, $v0, $zero
/* 42D80 80067980 AFBF00DC */  sw        $ra, 0xdc($sp)
/* 42D84 80067984 0C019D60 */  jal       guMtxL2F
/* 42D88 80067988 AFB000D0 */   sw       $s0, 0xd0($sp)
/* 42D8C 8006798C 27B00050 */  addiu     $s0, $sp, 0x50
/* 42D90 80067990 02002021 */  addu      $a0, $s0, $zero
/* 42D94 80067994 0C019D60 */  jal       guMtxL2F
/* 42D98 80067998 02202821 */   addu     $a1, $s1, $zero
/* 42D9C 8006799C 27A40010 */  addiu     $a0, $sp, 0x10
/* 42DA0 800679A0 02002821 */  addu      $a1, $s0, $zero
/* 42DA4 800679A4 27B00090 */  addiu     $s0, $sp, 0x90
/* 42DA8 800679A8 0C019D80 */  jal       guMtxCatF
/* 42DAC 800679AC 02003021 */   addu     $a2, $s0, $zero
/* 42DB0 800679B0 02002021 */  addu      $a0, $s0, $zero
/* 42DB4 800679B4 0C019D40 */  jal       guMtxF2L
/* 42DB8 800679B8 02402821 */   addu     $a1, $s2, $zero
/* 42DBC 800679BC 8FBF00DC */  lw        $ra, 0xdc($sp)
/* 42DC0 800679C0 8FB200D8 */  lw        $s2, 0xd8($sp)
/* 42DC4 800679C4 8FB100D4 */  lw        $s1, 0xd4($sp)
/* 42DC8 800679C8 8FB000D0 */  lw        $s0, 0xd0($sp)
/* 42DCC 800679CC 03E00008 */  jr        $ra
/* 42DD0 800679D0 27BD00E0 */   addiu    $sp, $sp, 0xe0
/* 42DD4 800679D4 00000000 */  nop       
/* 42DD8 800679D8 00000000 */  nop       
/* 42DDC 800679DC 00000000 */  nop       
