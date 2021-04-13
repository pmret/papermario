.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055A3C
/* 30E3C 80055A3C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 30E40 80055A40 AFB1001C */  sw        $s1, 0x1c($sp)
/* 30E44 80055A44 00A0882D */  daddu     $s1, $a1, $zero
/* 30E48 80055A48 27A50010 */  addiu     $a1, $sp, 0x10
/* 30E4C 80055A4C 27A60014 */  addiu     $a2, $sp, 0x14
/* 30E50 80055A50 AFBF0020 */  sw        $ra, 0x20($sp)
/* 30E54 80055A54 0C015666 */  jal       func_80055998
/* 30E58 80055A58 AFB00018 */   sw       $s0, 0x18($sp)
/* 30E5C 80055A5C 0040802D */  daddu     $s0, $v0, $zero
/* 30E60 80055A60 16000005 */  bnez      $s0, .L80055A78
/* 30E64 80055A64 0200102D */   daddu    $v0, $s0, $zero
/* 30E68 80055A68 8FA40014 */  lw        $a0, 0x14($sp)
/* 30E6C 80055A6C 0C014132 */  jal       func_800504C8
/* 30E70 80055A70 0220282D */   daddu    $a1, $s1, $zero
/* 30E74 80055A74 0200102D */  daddu     $v0, $s0, $zero
.L80055A78:
/* 30E78 80055A78 8FBF0020 */  lw        $ra, 0x20($sp)
/* 30E7C 80055A7C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 30E80 80055A80 8FB00018 */  lw        $s0, 0x18($sp)
/* 30E84 80055A84 03E00008 */  jr        $ra
/* 30E88 80055A88 27BD0028 */   addiu    $sp, $sp, 0x28
