.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80067940
/* 42D40 80067940 27BDFF20 */  addiu     $sp, $sp, -0xe0
/* 42D44 80067944 00801021 */  addu      $v0, $a0, $zero
/* 42D48 80067948 AFB100D4 */  sw        $s1, 0xd4($sp)
/* 42D4C 8006794C 00A08821 */  addu      $s1, $a1, $zero
/* 42D50 80067950 AFB200D8 */  sw        $s2, 0xd8($sp)
/* 42D54 80067954 00C09021 */  addu      $s2, $a2, $zero
/* 42D58 80067958 27A40010 */  addiu     $a0, $sp, 0x10
/* 42D5C 8006795C 00402821 */  addu      $a1, $v0, $zero
/* 42D60 80067960 AFBF00DC */  sw        $ra, 0xdc($sp)
/* 42D64 80067964 0C019D58 */  jal       func_80067560
/* 42D68 80067968 AFB000D0 */   sw       $s0, 0xd0($sp)
/* 42D6C 8006796C 27B00050 */  addiu     $s0, $sp, 0x50
/* 42D70 80067970 02002021 */  addu      $a0, $s0, $zero
/* 42D74 80067974 0C019D58 */  jal       func_80067560
/* 42D78 80067978 02202821 */   addu     $a1, $s1, $zero
/* 42D7C 8006797C 27A40010 */  addiu     $a0, $sp, 0x10
/* 42D80 80067980 02002821 */  addu      $a1, $s0, $zero
/* 42D84 80067984 27B00090 */  addiu     $s0, $sp, 0x90
/* 42D88 80067988 0C019D78 */  jal       func_800675E0
/* 42D8C 8006798C 02003021 */   addu     $a2, $s0, $zero
/* 42D90 80067990 02002021 */  addu      $a0, $s0, $zero
/* 42D94 80067994 0C019D38 */  jal       func_800674E0
/* 42D98 80067998 02402821 */   addu     $a1, $s2, $zero
/* 42D9C 8006799C 8FBF00DC */  lw        $ra, 0xdc($sp)
/* 42DA0 800679A0 8FB200D8 */  lw        $s2, 0xd8($sp)
/* 42DA4 800679A4 8FB100D4 */  lw        $s1, 0xd4($sp)
/* 42DA8 800679A8 8FB000D0 */  lw        $s0, 0xd0($sp)
/* 42DAC 800679AC 03E00008 */  jr        $ra
/* 42DB0 800679B0 27BD00E0 */   addiu    $sp, $sp, 0xe0
/* 42DB4 800679B4 00000000 */  nop
/* 42DB8 800679B8 00000000 */  nop
/* 42DBC 800679BC 00000000 */  nop
