.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F70_A4D990
/* A4D990 80240F70 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* A4D994 80240F74 AFB3003C */  sw        $s3, 0x3c($sp)
/* A4D998 80240F78 0080982D */  daddu     $s3, $a0, $zero
/* A4D99C 80240F7C AFBF0044 */  sw        $ra, 0x44($sp)
/* A4D9A0 80240F80 AFB40040 */  sw        $s4, 0x40($sp)
/* A4D9A4 80240F84 AFB20038 */  sw        $s2, 0x38($sp)
/* A4D9A8 80240F88 AFB10034 */  sw        $s1, 0x34($sp)
/* A4D9AC 80240F8C AFB00030 */  sw        $s0, 0x30($sp)
/* A4D9B0 80240F90 8E720148 */  lw        $s2, 0x148($s3)
/* A4D9B4 80240F94 00A0882D */  daddu     $s1, $a1, $zero
/* A4D9B8 80240F98 86440008 */  lh        $a0, 8($s2)
/* A4D9BC 80240F9C 0C00EABB */  jal       get_npc_unsafe
/* A4D9C0 80240FA0 00C0A02D */   daddu    $s4, $a2, $zero
/* A4D9C4 80240FA4 0040802D */  daddu     $s0, $v0, $zero
/* A4D9C8 80240FA8 9602008E */  lhu       $v0, 0x8e($s0)
/* A4D9CC 80240FAC 2442FFFF */  addiu     $v0, $v0, -1
/* A4D9D0 80240FB0 A602008E */  sh        $v0, 0x8e($s0)
/* A4D9D4 80240FB4 00021400 */  sll       $v0, $v0, 0x10
/* A4D9D8 80240FB8 1C400032 */  bgtz      $v0, .L80241084
/* A4D9DC 80240FBC 00000000 */   nop
/* A4D9E0 80240FC0 0260202D */  daddu     $a0, $s3, $zero
/* A4D9E4 80240FC4 8E250024 */  lw        $a1, 0x24($s1)
/* A4D9E8 80240FC8 8E260028 */  lw        $a2, 0x28($s1)
/* A4D9EC 80240FCC 0C090028 */  jal       func_802400A0_A4CAC0
/* A4D9F0 80240FD0 0280382D */   daddu    $a3, $s4, $zero
/* A4D9F4 80240FD4 0040882D */  daddu     $s1, $v0, $zero
/* A4D9F8 80240FD8 24020001 */  addiu     $v0, $zero, 1
/* A4D9FC 80240FDC 1222001D */  beq       $s1, $v0, .L80241054
/* A4DA00 80240FE0 0200282D */   daddu    $a1, $s0, $zero
/* A4DA04 80240FE4 24040002 */  addiu     $a0, $zero, 2
/* A4DA08 80240FE8 0000302D */  daddu     $a2, $zero, $zero
/* A4DA0C 80240FEC 860300A8 */  lh        $v1, 0xa8($s0)
/* A4DA10 80240FF0 3C013F80 */  lui       $at, 0x3f80
/* A4DA14 80240FF4 44810000 */  mtc1      $at, $f0
/* A4DA18 80240FF8 3C014000 */  lui       $at, 0x4000
/* A4DA1C 80240FFC 44811000 */  mtc1      $at, $f2
/* A4DA20 80241000 3C01C1A0 */  lui       $at, 0xc1a0
/* A4DA24 80241004 44812000 */  mtc1      $at, $f4
/* A4DA28 80241008 2402000C */  addiu     $v0, $zero, 0xc
/* A4DA2C 8024100C AFA2001C */  sw        $v0, 0x1c($sp)
/* A4DA30 80241010 44833000 */  mtc1      $v1, $f6
/* A4DA34 80241014 00000000 */  nop
/* A4DA38 80241018 468031A0 */  cvt.s.w   $f6, $f6
/* A4DA3C 8024101C 44073000 */  mfc1      $a3, $f6
/* A4DA40 80241020 27A20028 */  addiu     $v0, $sp, 0x28
/* A4DA44 80241024 AFA20020 */  sw        $v0, 0x20($sp)
/* A4DA48 80241028 E7A00010 */  swc1      $f0, 0x10($sp)
/* A4DA4C 8024102C E7A20014 */  swc1      $f2, 0x14($sp)
/* A4DA50 80241030 0C01BFA4 */  jal       fx_emote
/* A4DA54 80241034 E7A40018 */   swc1     $f4, 0x18($sp)
/* A4DA58 80241038 8E4200CC */  lw        $v0, 0xcc($s2)
/* A4DA5C 8024103C 8C430000 */  lw        $v1, ($v0)
/* A4DA60 80241040 2402000F */  addiu     $v0, $zero, 0xf
/* A4DA64 80241044 A602008E */  sh        $v0, 0x8e($s0)
/* A4DA68 80241048 AE030028 */  sw        $v1, 0x28($s0)
/* A4DA6C 8024104C 08090421 */  j         .L80241084
/* A4DA70 80241050 AE600070 */   sw       $zero, 0x70($s3)
.L80241054:
/* A4DA74 80241054 0200202D */  daddu     $a0, $s0, $zero
/* A4DA78 80241058 240520D5 */  addiu     $a1, $zero, 0x20d5
/* A4DA7C 8024105C 0C012530 */  jal       ai_enemy_play_sound
/* A4DA80 80241060 0000302D */   daddu    $a2, $zero, $zero
/* A4DA84 80241064 86440008 */  lh        $a0, 8($s2)
/* A4DA88 80241068 0C00FB3A */  jal       get_enemy
/* A4DA8C 8024106C 24840001 */   addiu    $a0, $a0, 1
/* A4DA90 80241070 AC51006C */  sw        $s1, 0x6c($v0)
/* A4DA94 80241074 24020014 */  addiu     $v0, $zero, 0x14
/* A4DA98 80241078 A602008E */  sh        $v0, 0x8e($s0)
/* A4DA9C 8024107C 24020018 */  addiu     $v0, $zero, 0x18
/* A4DAA0 80241080 AE620070 */  sw        $v0, 0x70($s3)
.L80241084:
/* A4DAA4 80241084 8FBF0044 */  lw        $ra, 0x44($sp)
/* A4DAA8 80241088 8FB40040 */  lw        $s4, 0x40($sp)
/* A4DAAC 8024108C 8FB3003C */  lw        $s3, 0x3c($sp)
/* A4DAB0 80241090 8FB20038 */  lw        $s2, 0x38($sp)
/* A4DAB4 80241094 8FB10034 */  lw        $s1, 0x34($sp)
/* A4DAB8 80241098 8FB00030 */  lw        $s0, 0x30($sp)
/* A4DABC 8024109C 03E00008 */  jr        $ra
/* A4DAC0 802410A0 27BD0048 */   addiu    $sp, $sp, 0x48
