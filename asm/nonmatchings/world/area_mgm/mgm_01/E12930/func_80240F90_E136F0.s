.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F90_E136F0
/* E136F0 80240F90 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* E136F4 80240F94 0000202D */  daddu     $a0, $zero, $zero
/* E136F8 80240F98 AFBF002C */  sw        $ra, 0x2c($sp)
/* E136FC 80240F9C AFB40028 */  sw        $s4, 0x28($sp)
/* E13700 80240FA0 AFB30024 */  sw        $s3, 0x24($sp)
/* E13704 80240FA4 AFB20020 */  sw        $s2, 0x20($sp)
/* E13708 80240FA8 AFB1001C */  sw        $s1, 0x1c($sp)
/* E1370C 80240FAC 0C00FB3A */  jal       get_enemy
/* E13710 80240FB0 AFB00018 */   sw       $s0, 0x18($sp)
/* E13714 80240FB4 0000802D */  daddu     $s0, $zero, $zero
/* E13718 80240FB8 3C148024 */  lui       $s4, 0x8024
/* E1371C 80240FBC 26941AC8 */  addiu     $s4, $s4, 0x1ac8
/* E13720 80240FC0 3C138024 */  lui       $s3, 0x8024
/* E13724 80240FC4 26731AD4 */  addiu     $s3, $s3, 0x1ad4
/* E13728 80240FC8 3C128024 */  lui       $s2, 0x8024
/* E1372C 80240FCC 26521AE0 */  addiu     $s2, $s2, 0x1ae0
/* E13730 80240FD0 8C510080 */  lw        $s1, 0x80($v0)
.L80240FD4:
/* E13734 80240FD4 8E220088 */  lw        $v0, 0x88($s1)
/* E13738 80240FD8 0440001B */  bltz      $v0, .L80241048
/* E1373C 80240FDC 02141021 */   addu     $v0, $s0, $s4
/* E13740 80240FE0 02131821 */  addu      $v1, $s0, $s3
/* E13744 80240FE4 02122021 */  addu      $a0, $s0, $s2
/* E13748 80240FE8 80450000 */  lb        $a1, ($v0)
/* E1374C 80240FEC 80620000 */  lb        $v0, ($v1)
/* E13750 80240FF0 80830000 */  lb        $v1, ($a0)
/* E13754 80240FF4 44850000 */  mtc1      $a1, $f0
/* E13758 80240FF8 00000000 */  nop       
/* E1375C 80240FFC 46800020 */  cvt.s.w   $f0, $f0
/* E13760 80241000 2442000D */  addiu     $v0, $v0, 0xd
/* E13764 80241004 44050000 */  mfc1      $a1, $f0
/* E13768 80241008 44820000 */  mtc1      $v0, $f0
/* E1376C 8024100C 00000000 */  nop       
/* E13770 80241010 46800020 */  cvt.s.w   $f0, $f0
/* E13774 80241014 24630005 */  addiu     $v1, $v1, 5
/* E13778 80241018 44060000 */  mfc1      $a2, $f0
/* E1377C 8024101C 44830000 */  mtc1      $v1, $f0
/* E13780 80241020 00000000 */  nop       
/* E13784 80241024 46800020 */  cvt.s.w   $f0, $f0
/* E13788 80241028 44070000 */  mfc1      $a3, $f0
/* E1378C 8024102C 24040001 */  addiu     $a0, $zero, 1
/* E13790 80241030 AFA00010 */  sw        $zero, 0x10($sp)
/* E13794 80241034 0C01BECC */  jal       fx_walk_normal
/* E13798 80241038 AFA00014 */   sw       $zero, 0x14($sp)
/* E1379C 8024103C 8E240088 */  lw        $a0, 0x88($s1)
/* E137A0 80241040 0C0441B4 */  jal       delete_entity
/* E137A4 80241044 00000000 */   nop      
.L80241048:
/* E137A8 80241048 26100001 */  addiu     $s0, $s0, 1
/* E137AC 8024104C 2A02000B */  slti      $v0, $s0, 0xb
/* E137B0 80241050 1440FFE0 */  bnez      $v0, .L80240FD4
/* E137B4 80241054 2631005C */   addiu    $s1, $s1, 0x5c
/* E137B8 80241058 24040283 */  addiu     $a0, $zero, 0x283
/* E137BC 8024105C 24050050 */  addiu     $a1, $zero, 0x50
/* E137C0 80241060 0000302D */  daddu     $a2, $zero, $zero
/* E137C4 80241064 0C0526AE */  jal       _play_sound
/* E137C8 80241068 00C0382D */   daddu    $a3, $a2, $zero
/* E137CC 8024106C 8FBF002C */  lw        $ra, 0x2c($sp)
/* E137D0 80241070 8FB40028 */  lw        $s4, 0x28($sp)
/* E137D4 80241074 8FB30024 */  lw        $s3, 0x24($sp)
/* E137D8 80241078 8FB20020 */  lw        $s2, 0x20($sp)
/* E137DC 8024107C 8FB1001C */  lw        $s1, 0x1c($sp)
/* E137E0 80241080 8FB00018 */  lw        $s0, 0x18($sp)
/* E137E4 80241084 24020002 */  addiu     $v0, $zero, 2
/* E137E8 80241088 03E00008 */  jr        $ra
/* E137EC 8024108C 27BD0030 */   addiu    $sp, $sp, 0x30
