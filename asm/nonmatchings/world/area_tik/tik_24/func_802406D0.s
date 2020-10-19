.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406D0
/* 8A6150 802406D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8A6154 802406D4 AFB20018 */  sw        $s2, 0x18($sp)
/* 8A6158 802406D8 0080902D */  daddu     $s2, $a0, $zero
/* 8A615C 802406DC AFBF001C */  sw        $ra, 0x1c($sp)
/* 8A6160 802406E0 AFB10014 */  sw        $s1, 0x14($sp)
/* 8A6164 802406E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 8A6168 802406E8 8E510148 */  lw        $s1, 0x148($s2)
/* 8A616C 802406EC 0C00EABB */  jal       get_npc_unsafe
/* 8A6170 802406F0 86240008 */   lh       $a0, 8($s1)
/* 8A6174 802406F4 0040802D */  daddu     $s0, $v0, $zero
/* 8A6178 802406F8 8E2300CC */  lw        $v1, 0xcc($s1)
/* 8A617C 802406FC C60C0038 */  lwc1      $f12, 0x38($s0)
/* 8A6180 80240700 8C630020 */  lw        $v1, 0x20($v1)
/* 8A6184 80240704 AE030028 */  sw        $v1, 0x28($s0)
/* 8A6188 80240708 96220076 */  lhu       $v0, 0x76($s1)
/* 8A618C 8024070C A602008E */  sh        $v0, 0x8e($s0)
/* 8A6190 80240710 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 8A6194 80240714 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 8A6198 80240718 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 8A619C 8024071C 8C460028 */  lw        $a2, 0x28($v0)
/* 8A61A0 80240720 0C00A720 */  jal       atan2
/* 8A61A4 80240724 8C470030 */   lw       $a3, 0x30($v0)
/* 8A61A8 80240728 2402000D */  addiu     $v0, $zero, 0xd
/* 8A61AC 8024072C E600000C */  swc1      $f0, 0xc($s0)
/* 8A61B0 80240730 AE420070 */  sw        $v0, 0x70($s2)
/* 8A61B4 80240734 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8A61B8 80240738 8FB20018 */  lw        $s2, 0x18($sp)
/* 8A61BC 8024073C 8FB10014 */  lw        $s1, 0x14($sp)
/* 8A61C0 80240740 8FB00010 */  lw        $s0, 0x10($sp)
/* 8A61C4 80240744 03E00008 */  jr        $ra
/* 8A61C8 80240748 27BD0020 */   addiu    $sp, $sp, 0x20
