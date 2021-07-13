.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238480_708120
/* 708120 80238480 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 708124 80238484 AFB1001C */  sw        $s1, 0x1c($sp)
/* 708128 80238488 0080882D */  daddu     $s1, $a0, $zero
/* 70812C 8023848C AFBF0020 */  sw        $ra, 0x20($sp)
/* 708130 80238490 AFB00018 */  sw        $s0, 0x18($sp)
/* 708134 80238494 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 708138 80238498 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 70813C 8023849C F7B40028 */  sdc1      $f20, 0x28($sp)
/* 708140 802384A0 8E30000C */  lw        $s0, 0xc($s1)
/* 708144 802384A4 8E050000 */  lw        $a1, ($s0)
/* 708148 802384A8 0C0B210B */  jal       get_float_variable
/* 70814C 802384AC 26100004 */   addiu    $s0, $s0, 4
/* 708150 802384B0 8E050000 */  lw        $a1, ($s0)
/* 708154 802384B4 26100004 */  addiu     $s0, $s0, 4
/* 708158 802384B8 0220202D */  daddu     $a0, $s1, $zero
/* 70815C 802384BC 0C0B210B */  jal       get_float_variable
/* 708160 802384C0 46000606 */   mov.s    $f24, $f0
/* 708164 802384C4 0220202D */  daddu     $a0, $s1, $zero
/* 708168 802384C8 8E050000 */  lw        $a1, ($s0)
/* 70816C 802384CC 0C0B210B */  jal       get_float_variable
/* 708170 802384D0 46000586 */   mov.s    $f22, $f0
/* 708174 802384D4 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 708178 802384D8 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 70817C 802384DC 0040802D */  daddu     $s0, $v0, $zero
/* 708180 802384E0 8E0400A0 */  lw        $a0, 0xa0($s0)
/* 708184 802384E4 10800003 */  beqz      $a0, .L802384F4
/* 708188 802384E8 46000506 */   mov.s    $f20, $f0
/* 70818C 802384EC 0C016914 */  jal       remove_effect
/* 708190 802384F0 00000000 */   nop
.L802384F4:
/* 708194 802384F4 4405C000 */  mfc1      $a1, $f24
/* 708198 802384F8 3C013FC0 */  lui       $at, 0x3fc0
/* 70819C 802384FC 44810000 */  mtc1      $at, $f0
/* 7081A0 80238500 4406B000 */  mfc1      $a2, $f22
/* 7081A4 80238504 4407A000 */  mfc1      $a3, $f20
/* 7081A8 80238508 0000202D */  daddu     $a0, $zero, $zero
/* 7081AC 8023850C AFA00014 */  sw        $zero, 0x14($sp)
/* 7081B0 80238510 0C01C694 */  jal       playFX_5A
/* 7081B4 80238514 E7A00010 */   swc1     $f0, 0x10($sp)
/* 7081B8 80238518 AE0200A0 */  sw        $v0, 0xa0($s0)
/* 7081BC 8023851C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 7081C0 80238520 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7081C4 80238524 8FB00018 */  lw        $s0, 0x18($sp)
/* 7081C8 80238528 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 7081CC 8023852C D7B60030 */  ldc1      $f22, 0x30($sp)
/* 7081D0 80238530 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 7081D4 80238534 24020002 */  addiu     $v0, $zero, 2
/* 7081D8 80238538 03E00008 */  jr        $ra
/* 7081DC 8023853C 27BD0040 */   addiu    $sp, $sp, 0x40
