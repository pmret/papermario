.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mac_00_UnkFunc16
/* 7EDD54 80243044 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7EDD58 80243048 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EDD5C 8024304C 0080882D */  daddu     $s1, $a0, $zero
/* 7EDD60 80243050 AFBF001C */  sw        $ra, 0x1c($sp)
/* 7EDD64 80243054 AFB20018 */  sw        $s2, 0x18($sp)
/* 7EDD68 80243058 AFB00010 */  sw        $s0, 0x10($sp)
/* 7EDD6C 8024305C 8E300148 */  lw        $s0, 0x148($s1)
/* 7EDD70 80243060 86040008 */  lh        $a0, 8($s0)
/* 7EDD74 80243064 0C00EABB */  jal       get_npc_unsafe
/* 7EDD78 80243068 00A0902D */   daddu    $s2, $a1, $zero
/* 7EDD7C 8024306C 8E0300D0 */  lw        $v1, 0xd0($s0)
/* 7EDD80 80243070 8E240078 */  lw        $a0, 0x78($s1)
/* 7EDD84 80243074 8C630000 */  lw        $v1, ($v1)
/* 7EDD88 80243078 0083182A */  slt       $v1, $a0, $v1
/* 7EDD8C 8024307C 10600013 */  beqz      $v1, .L802430CC
/* 7EDD90 80243080 0040302D */   daddu    $a2, $v0, $zero
/* 7EDD94 80243084 00041040 */  sll       $v0, $a0, 1
/* 7EDD98 80243088 00441021 */  addu      $v0, $v0, $a0
/* 7EDD9C 8024308C 00022880 */  sll       $a1, $v0, 2
.L80243090:
/* 7EDDA0 80243090 8E0300D0 */  lw        $v1, 0xd0($s0)
/* 7EDDA4 80243094 C4C2003C */  lwc1      $f2, 0x3c($a2)
/* 7EDDA8 80243098 00A31021 */  addu      $v0, $a1, $v1
/* 7EDDAC 8024309C C4400008 */  lwc1      $f0, 8($v0)
/* 7EDDB0 802430A0 46800020 */  cvt.s.w   $f0, $f0
/* 7EDDB4 802430A4 4602003E */  c.le.s    $f0, $f2
/* 7EDDB8 802430A8 00000000 */  nop
/* 7EDDBC 802430AC 45020003 */  bc1fl     .L802430BC
/* 7EDDC0 802430B0 24840001 */   addiu    $a0, $a0, 1
/* 7EDDC4 802430B4 08090C33 */  j         .L802430CC
/* 7EDDC8 802430B8 AE240078 */   sw       $a0, 0x78($s1)
.L802430BC:
/* 7EDDCC 802430BC 8C620000 */  lw        $v0, ($v1)
/* 7EDDD0 802430C0 0082102A */  slt       $v0, $a0, $v0
/* 7EDDD4 802430C4 1440FFF2 */  bnez      $v0, .L80243090
/* 7EDDD8 802430C8 24A5000C */   addiu    $a1, $a1, 0xc
.L802430CC:
/* 7EDDDC 802430CC C6400000 */  lwc1      $f0, ($s2)
/* 7EDDE0 802430D0 E4C00018 */  swc1      $f0, 0x18($a2)
/* 7EDDE4 802430D4 8E0200CC */  lw        $v0, 0xcc($s0)
/* 7EDDE8 802430D8 8C420004 */  lw        $v0, 4($v0)
/* 7EDDEC 802430DC ACC20028 */  sw        $v0, 0x28($a2)
/* 7EDDF0 802430E0 24020001 */  addiu     $v0, $zero, 1
/* 7EDDF4 802430E4 AE200074 */  sw        $zero, 0x74($s1)
/* 7EDDF8 802430E8 AE220070 */  sw        $v0, 0x70($s1)
/* 7EDDFC 802430EC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 7EDE00 802430F0 8FB20018 */  lw        $s2, 0x18($sp)
/* 7EDE04 802430F4 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EDE08 802430F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EDE0C 802430FC 03E00008 */  jr        $ra
/* 7EDE10 80243100 27BD0020 */   addiu    $sp, $sp, 0x20
