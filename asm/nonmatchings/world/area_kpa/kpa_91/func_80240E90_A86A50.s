.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E90_A878E0
/* A878E0 80240E90 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A878E4 80240E94 AFB20018 */  sw        $s2, 0x18($sp)
/* A878E8 80240E98 0080902D */  daddu     $s2, $a0, $zero
/* A878EC 80240E9C AFBF001C */  sw        $ra, 0x1c($sp)
/* A878F0 80240EA0 AFB10014 */  sw        $s1, 0x14($sp)
/* A878F4 80240EA4 AFB00010 */  sw        $s0, 0x10($sp)
/* A878F8 80240EA8 8E510148 */  lw        $s1, 0x148($s2)
/* A878FC 80240EAC 0C00EABB */  jal       get_npc_unsafe
/* A87900 80240EB0 86240008 */   lh       $a0, 8($s1)
/* A87904 80240EB4 0040802D */  daddu     $s0, $v0, $zero
/* A87908 80240EB8 8E2300CC */  lw        $v1, 0xcc($s1)
/* A8790C 80240EBC C60C0038 */  lwc1      $f12, 0x38($s0)
/* A87910 80240EC0 8C630020 */  lw        $v1, 0x20($v1)
/* A87914 80240EC4 AE030028 */  sw        $v1, 0x28($s0)
/* A87918 80240EC8 96220076 */  lhu       $v0, 0x76($s1)
/* A8791C 80240ECC A602008E */  sh        $v0, 0x8e($s0)
/* A87920 80240ED0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A87924 80240ED4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A87928 80240ED8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A8792C 80240EDC 8C460028 */  lw        $a2, 0x28($v0)
/* A87930 80240EE0 0C00A720 */  jal       atan2
/* A87934 80240EE4 8C470030 */   lw       $a3, 0x30($v0)
/* A87938 80240EE8 2402000D */  addiu     $v0, $zero, 0xd
/* A8793C 80240EEC E600000C */  swc1      $f0, 0xc($s0)
/* A87940 80240EF0 AE420070 */  sw        $v0, 0x70($s2)
/* A87944 80240EF4 8FBF001C */  lw        $ra, 0x1c($sp)
/* A87948 80240EF8 8FB20018 */  lw        $s2, 0x18($sp)
/* A8794C 80240EFC 8FB10014 */  lw        $s1, 0x14($sp)
/* A87950 80240F00 8FB00010 */  lw        $s0, 0x10($sp)
/* A87954 80240F04 03E00008 */  jr        $ra
/* A87958 80240F08 27BD0020 */   addiu    $sp, $sp, 0x20
