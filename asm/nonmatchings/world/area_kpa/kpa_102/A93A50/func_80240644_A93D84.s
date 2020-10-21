.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240644_A93D84
/* A93D84 80240644 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* A93D88 80240648 AFB20038 */  sw        $s2, 0x38($sp)
/* A93D8C 8024064C 0080902D */  daddu     $s2, $a0, $zero
/* A93D90 80240650 AFBF003C */  sw        $ra, 0x3c($sp)
/* A93D94 80240654 AFB10034 */  sw        $s1, 0x34($sp)
/* A93D98 80240658 AFB00030 */  sw        $s0, 0x30($sp)
/* A93D9C 8024065C 8E510148 */  lw        $s1, 0x148($s2)
/* A93DA0 80240660 0C00EABB */  jal       get_npc_unsafe
/* A93DA4 80240664 86240008 */   lh       $a0, 8($s1)
/* A93DA8 80240668 0040802D */  daddu     $s0, $v0, $zero
/* A93DAC 8024066C 9602008E */  lhu       $v0, 0x8e($s0)
/* A93DB0 80240670 2442FFFF */  addiu     $v0, $v0, -1
/* A93DB4 80240674 A602008E */  sh        $v0, 0x8e($s0)
/* A93DB8 80240678 00021400 */  sll       $v0, $v0, 0x10
/* A93DBC 8024067C 1C40002B */  bgtz      $v0, .L8024072C
/* A93DC0 80240680 00000000 */   nop      
/* A93DC4 80240684 0C0900C4 */  jal       func_80240310_A93A50
/* A93DC8 80240688 0240202D */   daddu    $a0, $s2, $zero
/* A93DCC 8024068C 0040202D */  daddu     $a0, $v0, $zero
/* A93DD0 80240690 0481001A */  bgez      $a0, .L802406FC
/* A93DD4 80240694 2402000F */   addiu    $v0, $zero, 0xf
/* A93DD8 80240698 24040002 */  addiu     $a0, $zero, 2
/* A93DDC 8024069C 860300A8 */  lh        $v1, 0xa8($s0)
/* A93DE0 802406A0 AFA2001C */  sw        $v0, 0x1c($sp)
/* A93DE4 802406A4 27A20028 */  addiu     $v0, $sp, 0x28
/* A93DE8 802406A8 0200282D */  daddu     $a1, $s0, $zero
/* A93DEC 802406AC 3C013F80 */  lui       $at, 0x3f80
/* A93DF0 802406B0 44810000 */  mtc1      $at, $f0
/* A93DF4 802406B4 3C014000 */  lui       $at, 0x4000
/* A93DF8 802406B8 44811000 */  mtc1      $at, $f2
/* A93DFC 802406BC 3C01C1A0 */  lui       $at, 0xc1a0
/* A93E00 802406C0 44812000 */  mtc1      $at, $f4
/* A93E04 802406C4 44833000 */  mtc1      $v1, $f6
/* A93E08 802406C8 00000000 */  nop       
/* A93E0C 802406CC 468031A0 */  cvt.s.w   $f6, $f6
/* A93E10 802406D0 44073000 */  mfc1      $a3, $f6
/* A93E14 802406D4 0000302D */  daddu     $a2, $zero, $zero
/* A93E18 802406D8 AFA20020 */  sw        $v0, 0x20($sp)
/* A93E1C 802406DC E7A00010 */  swc1      $f0, 0x10($sp)
/* A93E20 802406E0 E7A20014 */  swc1      $f2, 0x14($sp)
/* A93E24 802406E4 0C01BFA4 */  jal       fx_emote
/* A93E28 802406E8 E7A40018 */   swc1     $f4, 0x18($sp)
/* A93E2C 802406EC 8E2200CC */  lw        $v0, 0xcc($s1)
/* A93E30 802406F0 8C420000 */  lw        $v0, ($v0)
/* A93E34 802406F4 080901C7 */  j         .L8024071C
/* A93E38 802406F8 AE020028 */   sw       $v0, 0x28($s0)
.L802406FC:
/* A93E3C 802406FC 8E2200CC */  lw        $v0, 0xcc($s1)
/* A93E40 80240700 8C420024 */  lw        $v0, 0x24($v0)
/* A93E44 80240704 0C00FB3A */  jal       get_enemy
/* A93E48 80240708 AE020028 */   sw       $v0, 0x28($s0)
/* A93E4C 8024070C 86240008 */  lh        $a0, 8($s1)
/* A93E50 80240710 24030001 */  addiu     $v1, $zero, 1
/* A93E54 80240714 AC43006C */  sw        $v1, 0x6c($v0)
/* A93E58 80240718 AC44007C */  sw        $a0, 0x7c($v0)
.L8024071C:
/* A93E5C 8024071C 96220076 */  lhu       $v0, 0x76($s1)
/* A93E60 80240720 A602008E */  sh        $v0, 0x8e($s0)
/* A93E64 80240724 24020021 */  addiu     $v0, $zero, 0x21
/* A93E68 80240728 AE420070 */  sw        $v0, 0x70($s2)
.L8024072C:
/* A93E6C 8024072C 8FBF003C */  lw        $ra, 0x3c($sp)
/* A93E70 80240730 8FB20038 */  lw        $s2, 0x38($sp)
/* A93E74 80240734 8FB10034 */  lw        $s1, 0x34($sp)
/* A93E78 80240738 8FB00030 */  lw        $s0, 0x30($sp)
/* A93E7C 8024073C 03E00008 */  jr        $ra
/* A93E80 80240740 27BD0040 */   addiu    $sp, $sp, 0x40
