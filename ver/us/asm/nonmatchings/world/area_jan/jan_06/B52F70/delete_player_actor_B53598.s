.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_delete_player_actor_B53598
/* B53598 80240D68 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B5359C 80240D6C AFB40040 */  sw        $s4, 0x40($sp)
/* B535A0 80240D70 0080A02D */  daddu     $s4, $a0, $zero
/* B535A4 80240D74 AFBF0044 */  sw        $ra, 0x44($sp)
/* B535A8 80240D78 AFB3003C */  sw        $s3, 0x3c($sp)
/* B535AC 80240D7C AFB20038 */  sw        $s2, 0x38($sp)
/* B535B0 80240D80 AFB10034 */  sw        $s1, 0x34($sp)
/* B535B4 80240D84 AFB00030 */  sw        $s0, 0x30($sp)
/* B535B8 80240D88 8E920148 */  lw        $s2, 0x148($s4)
/* B535BC 80240D8C 00A0882D */  daddu     $s1, $a1, $zero
/* B535C0 80240D90 86440008 */  lh        $a0, 8($s2)
/* B535C4 80240D94 0C00EABB */  jal       get_npc_unsafe
/* B535C8 80240D98 00C0982D */   daddu    $s3, $a2, $zero
/* B535CC 80240D9C 8E230014 */  lw        $v1, 0x14($s1)
/* B535D0 80240DA0 0460002D */  bltz      $v1, .L80240E58
/* B535D4 80240DA4 0040802D */   daddu    $s0, $v0, $zero
/* B535D8 80240DA8 0260202D */  daddu     $a0, $s3, $zero
/* B535DC 80240DAC AFA00010 */  sw        $zero, 0x10($sp)
/* B535E0 80240DB0 8E260024 */  lw        $a2, 0x24($s1)
/* B535E4 80240DB4 8E270028 */  lw        $a3, 0x28($s1)
/* B535E8 80240DB8 0C01242D */  jal       func_800490B4
/* B535EC 80240DBC 0240282D */   daddu    $a1, $s2, $zero
/* B535F0 80240DC0 10400025 */  beqz      $v0, .L80240E58
/* B535F4 80240DC4 0000202D */   daddu    $a0, $zero, $zero
/* B535F8 80240DC8 0200282D */  daddu     $a1, $s0, $zero
/* B535FC 80240DCC 0000302D */  daddu     $a2, $zero, $zero
/* B53600 80240DD0 860300A8 */  lh        $v1, 0xa8($s0)
/* B53604 80240DD4 3C013F80 */  lui       $at, 0x3f80
/* B53608 80240DD8 44810000 */  mtc1      $at, $f0
/* B5360C 80240DDC 3C014000 */  lui       $at, 0x4000
/* B53610 80240DE0 44811000 */  mtc1      $at, $f2
/* B53614 80240DE4 3C01C1A0 */  lui       $at, 0xc1a0
/* B53618 80240DE8 44812000 */  mtc1      $at, $f4
/* B5361C 80240DEC 2402000F */  addiu     $v0, $zero, 0xf
/* B53620 80240DF0 AFA2001C */  sw        $v0, 0x1c($sp)
/* B53624 80240DF4 44833000 */  mtc1      $v1, $f6
/* B53628 80240DF8 00000000 */  nop
/* B5362C 80240DFC 468031A0 */  cvt.s.w   $f6, $f6
/* B53630 80240E00 44073000 */  mfc1      $a3, $f6
/* B53634 80240E04 27A20028 */  addiu     $v0, $sp, 0x28
/* B53638 80240E08 AFA20020 */  sw        $v0, 0x20($sp)
/* B5363C 80240E0C E7A00010 */  swc1      $f0, 0x10($sp)
/* B53640 80240E10 E7A20014 */  swc1      $f2, 0x14($sp)
/* B53644 80240E14 0C01BFA4 */  jal       fx_emote
/* B53648 80240E18 E7A40018 */   swc1     $f4, 0x18($sp)
/* B5364C 80240E1C 0200202D */  daddu     $a0, $s0, $zero
/* B53650 80240E20 240502F4 */  addiu     $a1, $zero, 0x2f4
/* B53654 80240E24 0C012530 */  jal       ai_enemy_play_sound
/* B53658 80240E28 3C060020 */   lui      $a2, 0x20
/* B5365C 80240E2C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B53660 80240E30 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B53664 80240E34 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B53668 80240E38 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B5366C 80240E3C 8C460028 */  lw        $a2, 0x28($v0)
/* B53670 80240E40 0C00A720 */  jal       atan2
/* B53674 80240E44 8C470030 */   lw       $a3, 0x30($v0)
/* B53678 80240E48 2402000C */  addiu     $v0, $zero, 0xc
/* B5367C 80240E4C E600000C */  swc1      $f0, 0xc($s0)
/* B53680 80240E50 080903BB */  j         .L80240EEC
/* B53684 80240E54 AE820070 */   sw       $v0, 0x70($s4)
.L80240E58:
/* B53688 80240E58 8602008C */  lh        $v0, 0x8c($s0)
/* B5368C 80240E5C 14400023 */  bnez      $v0, .L80240EEC
/* B53690 80240E60 00000000 */   nop
/* B53694 80240E64 9602008E */  lhu       $v0, 0x8e($s0)
/* B53698 80240E68 2442FFFF */  addiu     $v0, $v0, -1
/* B5369C 80240E6C A602008E */  sh        $v0, 0x8e($s0)
/* B536A0 80240E70 00021400 */  sll       $v0, $v0, 0x10
/* B536A4 80240E74 1C40001D */  bgtz      $v0, .L80240EEC
/* B536A8 80240E78 00000000 */   nop
/* B536AC 80240E7C 8E820074 */  lw        $v0, 0x74($s4)
/* B536B0 80240E80 2442FFFF */  addiu     $v0, $v0, -1
/* B536B4 80240E84 18400018 */  blez      $v0, .L80240EE8
/* B536B8 80240E88 AE820074 */   sw       $v0, 0x74($s4)
/* B536BC 80240E8C C600000C */  lwc1      $f0, 0xc($s0)
/* B536C0 80240E90 3C014334 */  lui       $at, 0x4334
/* B536C4 80240E94 44816000 */  mtc1      $at, $f12
/* B536C8 80240E98 0C00A6C9 */  jal       clamp_angle
/* B536CC 80240E9C 460C0300 */   add.s    $f12, $f0, $f12
/* B536D0 80240EA0 240403E8 */  addiu     $a0, $zero, 0x3e8
/* B536D4 80240EA4 0C00A67F */  jal       rand_int
/* B536D8 80240EA8 E600000C */   swc1     $f0, 0xc($s0)
/* B536DC 80240EAC 3C032E8B */  lui       $v1, 0x2e8b
/* B536E0 80240EB0 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* B536E4 80240EB4 00430018 */  mult      $v0, $v1
/* B536E8 80240EB8 00021FC3 */  sra       $v1, $v0, 0x1f
/* B536EC 80240EBC 00004010 */  mfhi      $t0
/* B536F0 80240EC0 00082043 */  sra       $a0, $t0, 1
/* B536F4 80240EC4 00832023 */  subu      $a0, $a0, $v1
/* B536F8 80240EC8 00041840 */  sll       $v1, $a0, 1
/* B536FC 80240ECC 00641821 */  addu      $v1, $v1, $a0
/* B53700 80240ED0 00031880 */  sll       $v1, $v1, 2
/* B53704 80240ED4 00641823 */  subu      $v1, $v1, $a0
/* B53708 80240ED8 00431023 */  subu      $v0, $v0, $v1
/* B5370C 80240EDC 24420005 */  addiu     $v0, $v0, 5
/* B53710 80240EE0 080903BB */  j         .L80240EEC
/* B53714 80240EE4 A602008E */   sh       $v0, 0x8e($s0)
.L80240EE8:
/* B53718 80240EE8 AE800070 */  sw        $zero, 0x70($s4)
.L80240EEC:
/* B5371C 80240EEC 8FBF0044 */  lw        $ra, 0x44($sp)
/* B53720 80240EF0 8FB40040 */  lw        $s4, 0x40($sp)
/* B53724 80240EF4 8FB3003C */  lw        $s3, 0x3c($sp)
/* B53728 80240EF8 8FB20038 */  lw        $s2, 0x38($sp)
/* B5372C 80240EFC 8FB10034 */  lw        $s1, 0x34($sp)
/* B53730 80240F00 8FB00030 */  lw        $s0, 0x30($sp)
/* B53734 80240F04 03E00008 */  jr        $ra
/* B53738 80240F08 27BD0048 */   addiu    $sp, $sp, 0x48
