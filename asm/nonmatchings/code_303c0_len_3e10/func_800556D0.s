.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800556D0
/* 30AD0 800556D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 30AD4 800556D4 AFB10014 */  sw        $s1, 0x14($sp)
/* 30AD8 800556D8 0080882D */  daddu     $s1, $a0, $zero
/* 30ADC 800556DC AFBF0018 */  sw        $ra, 0x18($sp)
/* 30AE0 800556E0 0C01430C */  jal       func_80050C30
/* 30AE4 800556E4 AFB00010 */   sw       $s0, 0x10($sp)
/* 30AE8 800556E8 0040802D */  daddu     $s0, $v0, $zero
/* 30AEC 800556EC 16000005 */  bnez      $s0, .L80055704
/* 30AF0 800556F0 0200102D */   daddu    $v0, $s0, $zero
/* 30AF4 800556F4 0220202D */  daddu     $a0, $s1, $zero
/* 30AF8 800556F8 0C014319 */  jal       func_80050C64
/* 30AFC 800556FC 24050001 */   addiu    $a1, $zero, 1
/* 30B00 80055700 0200102D */  daddu     $v0, $s0, $zero
.L80055704:
/* 30B04 80055704 8FBF0018 */  lw        $ra, 0x18($sp)
/* 30B08 80055708 8FB10014 */  lw        $s1, 0x14($sp)
/* 30B0C 8005570C 8FB00010 */  lw        $s0, 0x10($sp)
/* 30B10 80055710 03E00008 */  jr        $ra
/* 30B14 80055714 27BD0020 */   addiu    $sp, $sp, 0x20
