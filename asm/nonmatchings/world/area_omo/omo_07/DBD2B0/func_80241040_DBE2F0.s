.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241040_DBE2F0
/* DBE2F0 80241040 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DBE2F4 80241044 AFB10014 */  sw        $s1, 0x14($sp)
/* DBE2F8 80241048 0080882D */  daddu     $s1, $a0, $zero
/* DBE2FC 8024104C AFBF001C */  sw        $ra, 0x1c($sp)
/* DBE300 80241050 AFB20018 */  sw        $s2, 0x18($sp)
/* DBE304 80241054 AFB00010 */  sw        $s0, 0x10($sp)
/* DBE308 80241058 8E300148 */  lw        $s0, 0x148($s1)
/* DBE30C 8024105C 86040008 */  lh        $a0, 8($s0)
/* DBE310 80241060 0C00EABB */  jal       get_npc_unsafe
/* DBE314 80241064 00A0902D */   daddu    $s2, $a1, $zero
/* DBE318 80241068 8E0300D0 */  lw        $v1, 0xd0($s0)
/* DBE31C 8024106C 8E240078 */  lw        $a0, 0x78($s1)
/* DBE320 80241070 8C630000 */  lw        $v1, ($v1)
/* DBE324 80241074 0083182A */  slt       $v1, $a0, $v1
/* DBE328 80241078 10600013 */  beqz      $v1, .L802410C8
/* DBE32C 8024107C 0040302D */   daddu    $a2, $v0, $zero
/* DBE330 80241080 00041040 */  sll       $v0, $a0, 1
/* DBE334 80241084 00441021 */  addu      $v0, $v0, $a0
/* DBE338 80241088 00022880 */  sll       $a1, $v0, 2
.L8024108C:
/* DBE33C 8024108C 8E0300D0 */  lw        $v1, 0xd0($s0)
/* DBE340 80241090 C4C2003C */  lwc1      $f2, 0x3c($a2)
/* DBE344 80241094 00A31021 */  addu      $v0, $a1, $v1
/* DBE348 80241098 C4400008 */  lwc1      $f0, 8($v0)
/* DBE34C 8024109C 46800020 */  cvt.s.w   $f0, $f0
/* DBE350 802410A0 4602003E */  c.le.s    $f0, $f2
/* DBE354 802410A4 00000000 */  nop
/* DBE358 802410A8 45020003 */  bc1fl     .L802410B8
/* DBE35C 802410AC 24840001 */   addiu    $a0, $a0, 1
/* DBE360 802410B0 08090432 */  j         .L802410C8
/* DBE364 802410B4 AE240078 */   sw       $a0, 0x78($s1)
.L802410B8:
/* DBE368 802410B8 8C620000 */  lw        $v0, ($v1)
/* DBE36C 802410BC 0082102A */  slt       $v0, $a0, $v0
/* DBE370 802410C0 1440FFF2 */  bnez      $v0, .L8024108C
/* DBE374 802410C4 24A5000C */   addiu    $a1, $a1, 0xc
.L802410C8:
/* DBE378 802410C8 C6400000 */  lwc1      $f0, ($s2)
/* DBE37C 802410CC E4C00018 */  swc1      $f0, 0x18($a2)
/* DBE380 802410D0 8E0200CC */  lw        $v0, 0xcc($s0)
/* DBE384 802410D4 8C420004 */  lw        $v0, 4($v0)
/* DBE388 802410D8 ACC20028 */  sw        $v0, 0x28($a2)
/* DBE38C 802410DC 24020001 */  addiu     $v0, $zero, 1
/* DBE390 802410E0 AE200074 */  sw        $zero, 0x74($s1)
/* DBE394 802410E4 AE220070 */  sw        $v0, 0x70($s1)
/* DBE398 802410E8 8FBF001C */  lw        $ra, 0x1c($sp)
/* DBE39C 802410EC 8FB20018 */  lw        $s2, 0x18($sp)
/* DBE3A0 802410F0 8FB10014 */  lw        $s1, 0x14($sp)
/* DBE3A4 802410F4 8FB00010 */  lw        $s0, 0x10($sp)
/* DBE3A8 802410F8 03E00008 */  jr        $ra
/* DBE3AC 802410FC 27BD0020 */   addiu    $sp, $sp, 0x20
