.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055114
/* 30514 80055114 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 30518 80055118 AFB00010 */  sw        $s0, 0x10($sp)
/* 3051C 8005511C 0080802D */  daddu     $s0, $a0, $zero
/* 30520 80055120 AFB10014 */  sw        $s1, 0x14($sp)
/* 30524 80055124 AFBF0018 */  sw        $ra, 0x18($sp)
/* 30528 80055128 0C014238 */  jal       func_800508E0
/* 3052C 8005512C 00A0882D */   daddu    $s1, $a1, $zero
/* 30530 80055130 14400003 */  bnez      $v0, .L80055140
/* 30534 80055134 0200202D */   daddu    $a0, $s0, $zero
/* 30538 80055138 0C014254 */  jal       func_80050950
/* 3053C 8005513C 0220282D */   daddu    $a1, $s1, $zero
.L80055140:
/* 30540 80055140 8FBF0018 */  lw        $ra, 0x18($sp)
/* 30544 80055144 8FB10014 */  lw        $s1, 0x14($sp)
/* 30548 80055148 8FB00010 */  lw        $s0, 0x10($sp)
/* 3054C 8005514C 03E00008 */  jr        $ra
/* 30550 80055150 27BD0020 */   addiu    $sp, $sp, 0x20
