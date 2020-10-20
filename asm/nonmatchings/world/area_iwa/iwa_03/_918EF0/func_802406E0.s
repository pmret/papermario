.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406E0
/* 919290 802406E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 919294 802406E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 919298 802406E8 0080882D */  daddu     $s1, $a0, $zero
/* 91929C 802406EC AFBF0018 */  sw        $ra, 0x18($sp)
/* 9192A0 802406F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 9192A4 802406F4 8E220148 */  lw        $v0, 0x148($s1)
/* 9192A8 802406F8 0C00EABB */  jal       get_npc_unsafe
/* 9192AC 802406FC 84440008 */   lh       $a0, 8($v0)
/* 9192B0 80240700 0040802D */  daddu     $s0, $v0, $zero
/* 9192B4 80240704 9602008E */  lhu       $v0, 0x8e($s0)
/* 9192B8 80240708 2442FFFF */  addiu     $v0, $v0, -1
/* 9192BC 8024070C A602008E */  sh        $v0, 0x8e($s0)
/* 9192C0 80240710 00021400 */  sll       $v0, $v0, 0x10
/* 9192C4 80240714 1C40000F */  bgtz      $v0, .L80240754
/* 9192C8 80240718 00000000 */   nop      
/* 9192CC 8024071C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9192D0 80240720 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9192D4 80240724 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9192D8 80240728 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9192DC 8024072C 8C460028 */  lw        $a2, 0x28($v0)
/* 9192E0 80240730 0C00A720 */  jal       atan2
/* 9192E4 80240734 8C470030 */   lw       $a3, 0x30($v0)
/* 9192E8 80240738 2402001A */  addiu     $v0, $zero, 0x1a
/* 9192EC 8024073C A60200A8 */  sh        $v0, 0xa8($s0)
/* 9192F0 80240740 24020018 */  addiu     $v0, $zero, 0x18
/* 9192F4 80240744 A60200A6 */  sh        $v0, 0xa6($s0)
/* 9192F8 80240748 24020004 */  addiu     $v0, $zero, 4
/* 9192FC 8024074C E600000C */  swc1      $f0, 0xc($s0)
/* 919300 80240750 AE220070 */  sw        $v0, 0x70($s1)
.L80240754:
/* 919304 80240754 8FBF0018 */  lw        $ra, 0x18($sp)
/* 919308 80240758 8FB10014 */  lw        $s1, 0x14($sp)
/* 91930C 8024075C 8FB00010 */  lw        $s0, 0x10($sp)
/* 919310 80240760 03E00008 */  jr        $ra
/* 919314 80240764 27BD0020 */   addiu    $sp, $sp, 0x20
