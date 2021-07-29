.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_merlee_on_start_turn
/* 16F740 80240E60 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 16F744 80240E64 AFB40020 */  sw        $s4, 0x20($sp)
/* 16F748 80240E68 3C14800E */  lui       $s4, %hi(gBattleStatus)
/* 16F74C 80240E6C 2694C070 */  addiu     $s4, $s4, %lo(gBattleStatus)
/* 16F750 80240E70 AFB3001C */  sw        $s3, 0x1c($sp)
/* 16F754 80240E74 3C13800B */  lui       $s3, %hi(gCurrentEncounter)
/* 16F758 80240E78 26730F10 */  addiu     $s3, $s3, %lo(gCurrentEncounter)
/* 16F75C 80240E7C AFB00010 */  sw        $s0, 0x10($sp)
/* 16F760 80240E80 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 16F764 80240E84 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 16F768 80240E88 AFBF0024 */  sw        $ra, 0x24($sp)
/* 16F76C 80240E8C AFB20018 */  sw        $s2, 0x18($sp)
/* 16F770 80240E90 AFB10014 */  sw        $s1, 0x14($sp)
/* 16F774 80240E94 8E820004 */  lw        $v0, 4($s4)
/* 16F778 80240E98 30420040 */  andi      $v0, $v0, 0x40
/* 16F77C 80240E9C 14400047 */  bnez      $v0, .L80240FBC
/* 16F780 80240EA0 24110003 */   addiu    $s1, $zero, 3
/* 16F784 80240EA4 8282008A */  lb        $v0, 0x8a($s4)
/* 16F788 80240EA8 10510044 */  beq       $v0, $s1, .L80240FBC
/* 16F78C 80240EAC 24120004 */   addiu    $s2, $zero, 4
/* 16F790 80240EB0 10520042 */  beq       $v0, $s2, .L80240FBC
/* 16F794 80240EB4 00000000 */   nop
/* 16F798 80240EB8 8202028A */  lb        $v0, 0x28a($s0)
/* 16F79C 80240EBC 1840003F */  blez      $v0, .L80240FBC
/* 16F7A0 80240EC0 00000000 */   nop
/* 16F7A4 80240EC4 8602028C */  lh        $v0, 0x28c($s0)
/* 16F7A8 80240EC8 1C400030 */  bgtz      $v0, .L80240F8C
/* 16F7AC 80240ECC 00000000 */   nop
/* 16F7B0 80240ED0 0C00A67F */  jal       rand_int
/* 16F7B4 80240ED4 24040064 */   addiu    $a0, $zero, 0x64
/* 16F7B8 80240ED8 8E63008C */  lw        $v1, 0x8c($s3)
/* 16F7BC 80240EDC 10600018 */  beqz      $v1, .L80240F40
/* 16F7C0 80240EE0 0040202D */   daddu    $a0, $v0, $zero
/* 16F7C4 80240EE4 8C620000 */  lw        $v0, ($v1)
/* 16F7C8 80240EE8 3C030004 */  lui       $v1, 4
/* 16F7CC 80240EEC 00431024 */  and       $v0, $v0, $v1
/* 16F7D0 80240EF0 10400008 */  beqz      $v0, .L80240F14
/* 16F7D4 80240EF4 2882002E */   slti     $v0, $a0, 0x2e
/* 16F7D8 80240EF8 14400014 */  bnez      $v0, .L80240F4C
/* 16F7DC 80240EFC 24020001 */   addiu    $v0, $zero, 1
/* 16F7E0 80240F00 2882005B */  slti      $v0, $a0, 0x5b
/* 16F7E4 80240F04 14400016 */  bnez      $v0, .L80240F60
/* 16F7E8 80240F08 24020002 */   addiu    $v0, $zero, 2
/* 16F7EC 80240F0C 080903DE */  j         .L80240F78
/* 16F7F0 80240F10 A2110289 */   sb       $s1, 0x289($s0)
.L80240F14:
/* 16F7F4 80240F14 2882001F */  slti      $v0, $a0, 0x1f
/* 16F7F8 80240F18 1440000C */  bnez      $v0, .L80240F4C
/* 16F7FC 80240F1C 24020001 */   addiu    $v0, $zero, 1
/* 16F800 80240F20 2882003D */  slti      $v0, $a0, 0x3d
/* 16F804 80240F24 1440000E */  bnez      $v0, .L80240F60
/* 16F808 80240F28 24020002 */   addiu    $v0, $zero, 2
/* 16F80C 80240F2C 28820051 */  slti      $v0, $a0, 0x51
/* 16F810 80240F30 54400011 */  bnel      $v0, $zero, .L80240F78
/* 16F814 80240F34 A2110289 */   sb       $s1, 0x289($s0)
/* 16F818 80240F38 080903DE */  j         .L80240F78
/* 16F81C 80240F3C A2120289 */   sb       $s2, 0x289($s0)
.L80240F40:
/* 16F820 80240F40 2882001F */  slti      $v0, $a0, 0x1f
/* 16F824 80240F44 10400003 */  beqz      $v0, .L80240F54
/* 16F828 80240F48 24020001 */   addiu    $v0, $zero, 1
.L80240F4C:
/* 16F82C 80240F4C 080903DE */  j         .L80240F78
/* 16F830 80240F50 A2020289 */   sb       $v0, 0x289($s0)
.L80240F54:
/* 16F834 80240F54 2882003D */  slti      $v0, $a0, 0x3d
/* 16F838 80240F58 10400003 */  beqz      $v0, .L80240F68
/* 16F83C 80240F5C 24020002 */   addiu    $v0, $zero, 2
.L80240F60:
/* 16F840 80240F60 080903DE */  j         .L80240F78
/* 16F844 80240F64 A2020289 */   sb       $v0, 0x289($s0)
.L80240F68:
/* 16F848 80240F68 28820051 */  slti      $v0, $a0, 0x51
/* 16F84C 80240F6C 50400002 */  beql      $v0, $zero, .L80240F78
/* 16F850 80240F70 A2120289 */   sb       $s2, 0x289($s0)
/* 16F854 80240F74 A2110289 */  sb        $s1, 0x289($s0)
.L80240F78:
/* 16F858 80240F78 0C00A67F */  jal       rand_int
/* 16F85C 80240F7C 2404000A */   addiu    $a0, $zero, 0xa
/* 16F860 80240F80 24440006 */  addiu     $a0, $v0, 6
/* 16F864 80240F84 A604028C */  sh        $a0, 0x28c($s0)
/* 16F868 80240F88 8602028C */  lh        $v0, 0x28c($s0)
.L80240F8C:
/* 16F86C 80240F8C 9603028C */  lhu       $v1, 0x28c($s0)
/* 16F870 80240F90 28420002 */  slti      $v0, $v0, 2
/* 16F874 80240F94 14400003 */  bnez      $v0, .L80240FA4
/* 16F878 80240F98 2462FFFF */   addiu    $v0, $v1, -1
/* 16F87C 80240F9C 080903EF */  j         .L80240FBC
/* 16F880 80240FA0 A602028C */   sh       $v0, 0x28c($s0)
.L80240FA4:
/* 16F884 80240FA4 92030289 */  lbu       $v1, 0x289($s0)
/* 16F888 80240FA8 9202028A */  lbu       $v0, 0x28a($s0)
/* 16F88C 80240FAC A600028C */  sh        $zero, 0x28c($s0)
/* 16F890 80240FB0 2442FFFF */  addiu     $v0, $v0, -1
/* 16F894 80240FB4 A283008A */  sb        $v1, 0x8a($s4)
/* 16F898 80240FB8 A202028A */  sb        $v0, 0x28a($s0)
.L80240FBC:
/* 16F89C 80240FBC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 16F8A0 80240FC0 8FB40020 */  lw        $s4, 0x20($sp)
/* 16F8A4 80240FC4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 16F8A8 80240FC8 8FB20018 */  lw        $s2, 0x18($sp)
/* 16F8AC 80240FCC 8FB10014 */  lw        $s1, 0x14($sp)
/* 16F8B0 80240FD0 8FB00010 */  lw        $s0, 0x10($sp)
/* 16F8B4 80240FD4 03E00008 */  jr        $ra
/* 16F8B8 80240FD8 27BD0028 */   addiu    $sp, $sp, 0x28
