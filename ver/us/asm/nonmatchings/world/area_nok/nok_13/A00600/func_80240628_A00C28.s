.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240628_A00C28
/* A00C28 80240628 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* A00C2C 8024062C AFB40040 */  sw        $s4, 0x40($sp)
/* A00C30 80240630 0080A02D */  daddu     $s4, $a0, $zero
/* A00C34 80240634 AFBF0044 */  sw        $ra, 0x44($sp)
/* A00C38 80240638 AFB3003C */  sw        $s3, 0x3c($sp)
/* A00C3C 8024063C AFB20038 */  sw        $s2, 0x38($sp)
/* A00C40 80240640 AFB10034 */  sw        $s1, 0x34($sp)
/* A00C44 80240644 AFB00030 */  sw        $s0, 0x30($sp)
/* A00C48 80240648 8E920148 */  lw        $s2, 0x148($s4)
/* A00C4C 8024064C 00A0882D */  daddu     $s1, $a1, $zero
/* A00C50 80240650 86440008 */  lh        $a0, 8($s2)
/* A00C54 80240654 0C00EABB */  jal       get_npc_unsafe
/* A00C58 80240658 00C0982D */   daddu    $s3, $a2, $zero
/* A00C5C 8024065C 8E230014 */  lw        $v1, 0x14($s1)
/* A00C60 80240660 0460002D */  bltz      $v1, .L80240718
/* A00C64 80240664 0040802D */   daddu    $s0, $v0, $zero
/* A00C68 80240668 0260202D */  daddu     $a0, $s3, $zero
/* A00C6C 8024066C AFA00010 */  sw        $zero, 0x10($sp)
/* A00C70 80240670 8E260024 */  lw        $a2, 0x24($s1)
/* A00C74 80240674 8E270028 */  lw        $a3, 0x28($s1)
/* A00C78 80240678 0C01242D */  jal       func_800490B4
/* A00C7C 8024067C 0240282D */   daddu    $a1, $s2, $zero
/* A00C80 80240680 10400025 */  beqz      $v0, .L80240718
/* A00C84 80240684 0000202D */   daddu    $a0, $zero, $zero
/* A00C88 80240688 0200282D */  daddu     $a1, $s0, $zero
/* A00C8C 8024068C 0000302D */  daddu     $a2, $zero, $zero
/* A00C90 80240690 860300A8 */  lh        $v1, 0xa8($s0)
/* A00C94 80240694 3C013F80 */  lui       $at, 0x3f80
/* A00C98 80240698 44810000 */  mtc1      $at, $f0
/* A00C9C 8024069C 3C014000 */  lui       $at, 0x4000
/* A00CA0 802406A0 44811000 */  mtc1      $at, $f2
/* A00CA4 802406A4 3C01C1A0 */  lui       $at, 0xc1a0
/* A00CA8 802406A8 44812000 */  mtc1      $at, $f4
/* A00CAC 802406AC 2402000F */  addiu     $v0, $zero, 0xf
/* A00CB0 802406B0 AFA2001C */  sw        $v0, 0x1c($sp)
/* A00CB4 802406B4 44833000 */  mtc1      $v1, $f6
/* A00CB8 802406B8 00000000 */  nop
/* A00CBC 802406BC 468031A0 */  cvt.s.w   $f6, $f6
/* A00CC0 802406C0 44073000 */  mfc1      $a3, $f6
/* A00CC4 802406C4 27A20028 */  addiu     $v0, $sp, 0x28
/* A00CC8 802406C8 AFA20020 */  sw        $v0, 0x20($sp)
/* A00CCC 802406CC E7A00010 */  swc1      $f0, 0x10($sp)
/* A00CD0 802406D0 E7A20014 */  swc1      $f2, 0x14($sp)
/* A00CD4 802406D4 0C01BFA4 */  jal       fx_emote
/* A00CD8 802406D8 E7A40018 */   swc1     $f4, 0x18($sp)
/* A00CDC 802406DC 0200202D */  daddu     $a0, $s0, $zero
/* A00CE0 802406E0 240502F4 */  addiu     $a1, $zero, 0x2f4
/* A00CE4 802406E4 0C012530 */  jal       ai_enemy_play_sound
/* A00CE8 802406E8 3C060020 */   lui      $a2, 0x20
/* A00CEC 802406EC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A00CF0 802406F0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A00CF4 802406F4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A00CF8 802406F8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A00CFC 802406FC 8C460028 */  lw        $a2, 0x28($v0)
/* A00D00 80240700 0C00A720 */  jal       atan2
/* A00D04 80240704 8C470030 */   lw       $a3, 0x30($v0)
/* A00D08 80240708 2402000C */  addiu     $v0, $zero, 0xc
/* A00D0C 8024070C E600000C */  swc1      $f0, 0xc($s0)
/* A00D10 80240710 080901EB */  j         .L802407AC
/* A00D14 80240714 AE820070 */   sw       $v0, 0x70($s4)
.L80240718:
/* A00D18 80240718 8602008C */  lh        $v0, 0x8c($s0)
/* A00D1C 8024071C 14400023 */  bnez      $v0, .L802407AC
/* A00D20 80240720 00000000 */   nop
/* A00D24 80240724 9602008E */  lhu       $v0, 0x8e($s0)
/* A00D28 80240728 2442FFFF */  addiu     $v0, $v0, -1
/* A00D2C 8024072C A602008E */  sh        $v0, 0x8e($s0)
/* A00D30 80240730 00021400 */  sll       $v0, $v0, 0x10
/* A00D34 80240734 1C40001D */  bgtz      $v0, .L802407AC
/* A00D38 80240738 00000000 */   nop
/* A00D3C 8024073C 8E820074 */  lw        $v0, 0x74($s4)
/* A00D40 80240740 2442FFFF */  addiu     $v0, $v0, -1
/* A00D44 80240744 18400018 */  blez      $v0, .L802407A8
/* A00D48 80240748 AE820074 */   sw       $v0, 0x74($s4)
/* A00D4C 8024074C C600000C */  lwc1      $f0, 0xc($s0)
/* A00D50 80240750 3C014334 */  lui       $at, 0x4334
/* A00D54 80240754 44816000 */  mtc1      $at, $f12
/* A00D58 80240758 0C00A6C9 */  jal       clamp_angle
/* A00D5C 8024075C 460C0300 */   add.s    $f12, $f0, $f12
/* A00D60 80240760 240403E8 */  addiu     $a0, $zero, 0x3e8
/* A00D64 80240764 0C00A67F */  jal       rand_int
/* A00D68 80240768 E600000C */   swc1     $f0, 0xc($s0)
/* A00D6C 8024076C 3C032E8B */  lui       $v1, 0x2e8b
/* A00D70 80240770 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* A00D74 80240774 00430018 */  mult      $v0, $v1
/* A00D78 80240778 00021FC3 */  sra       $v1, $v0, 0x1f
/* A00D7C 8024077C 00004010 */  mfhi      $t0
/* A00D80 80240780 00082043 */  sra       $a0, $t0, 1
/* A00D84 80240784 00832023 */  subu      $a0, $a0, $v1
/* A00D88 80240788 00041840 */  sll       $v1, $a0, 1
/* A00D8C 8024078C 00641821 */  addu      $v1, $v1, $a0
/* A00D90 80240790 00031880 */  sll       $v1, $v1, 2
/* A00D94 80240794 00641823 */  subu      $v1, $v1, $a0
/* A00D98 80240798 00431023 */  subu      $v0, $v0, $v1
/* A00D9C 8024079C 24420005 */  addiu     $v0, $v0, 5
/* A00DA0 802407A0 080901EB */  j         .L802407AC
/* A00DA4 802407A4 A602008E */   sh       $v0, 0x8e($s0)
.L802407A8:
/* A00DA8 802407A8 AE800070 */  sw        $zero, 0x70($s4)
.L802407AC:
/* A00DAC 802407AC 8FBF0044 */  lw        $ra, 0x44($sp)
/* A00DB0 802407B0 8FB40040 */  lw        $s4, 0x40($sp)
/* A00DB4 802407B4 8FB3003C */  lw        $s3, 0x3c($sp)
/* A00DB8 802407B8 8FB20038 */  lw        $s2, 0x38($sp)
/* A00DBC 802407BC 8FB10034 */  lw        $s1, 0x34($sp)
/* A00DC0 802407C0 8FB00030 */  lw        $s0, 0x30($sp)
/* A00DC4 802407C4 03E00008 */  jr        $ra
/* A00DC8 802407C8 27BD0048 */   addiu    $sp, $sp, 0x48
