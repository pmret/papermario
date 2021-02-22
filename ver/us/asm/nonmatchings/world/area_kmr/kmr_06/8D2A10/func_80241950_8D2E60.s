.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241950_8D2E60
/* 8D2E60 80241950 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 8D2E64 80241954 AFB10014 */  sw        $s1, 0x14($sp)
/* 8D2E68 80241958 0080882D */  daddu     $s1, $a0, $zero
/* 8D2E6C 8024195C AFBF0018 */  sw        $ra, 0x18($sp)
/* 8D2E70 80241960 AFB00010 */  sw        $s0, 0x10($sp)
/* 8D2E74 80241964 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 8D2E78 80241968 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 8D2E7C 8024196C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 8D2E80 80241970 8E30000C */  lw        $s0, 0xc($s1)
/* 8D2E84 80241974 8E050000 */  lw        $a1, ($s0)
/* 8D2E88 80241978 0C0B210B */  jal       get_float_variable
/* 8D2E8C 8024197C 26100004 */   addiu    $s0, $s0, 4
/* 8D2E90 80241980 8E050000 */  lw        $a1, ($s0)
/* 8D2E94 80241984 26100004 */  addiu     $s0, $s0, 4
/* 8D2E98 80241988 0220202D */  daddu     $a0, $s1, $zero
/* 8D2E9C 8024198C 0C0B210B */  jal       get_float_variable
/* 8D2EA0 80241990 46000606 */   mov.s    $f24, $f0
/* 8D2EA4 80241994 0220202D */  daddu     $a0, $s1, $zero
/* 8D2EA8 80241998 8E050000 */  lw        $a1, ($s0)
/* 8D2EAC 8024199C 0C0B210B */  jal       get_float_variable
/* 8D2EB0 802419A0 46000586 */   mov.s    $f22, $f0
/* 8D2EB4 802419A4 0220202D */  daddu     $a0, $s1, $zero
/* 8D2EB8 802419A8 3C05FD05 */  lui       $a1, 0xfd05
/* 8D2EBC 802419AC 34A50F8A */  ori       $a1, $a1, 0xf8a
/* 8D2EC0 802419B0 0C0B1EAF */  jal       get_variable
/* 8D2EC4 802419B4 46000506 */   mov.s    $f20, $f0
/* 8D2EC8 802419B8 0040182D */  daddu     $v1, $v0, $zero
/* 8D2ECC 802419BC E4780008 */  swc1      $f24, 8($v1)
/* 8D2ED0 802419C0 E476000C */  swc1      $f22, 0xc($v1)
/* 8D2ED4 802419C4 E4740010 */  swc1      $f20, 0x10($v1)
/* 8D2ED8 802419C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8D2EDC 802419CC 8FB10014 */  lw        $s1, 0x14($sp)
/* 8D2EE0 802419D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 8D2EE4 802419D4 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 8D2EE8 802419D8 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 8D2EEC 802419DC D7B40020 */  ldc1      $f20, 0x20($sp)
/* 8D2EF0 802419E0 24020002 */  addiu     $v0, $zero, 2
/* 8D2EF4 802419E4 03E00008 */  jr        $ra
/* 8D2EF8 802419E8 27BD0038 */   addiu    $sp, $sp, 0x38
