.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406A0_DEF540
/* DEF540 802406A0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DEF544 802406A4 AFB10024 */  sw        $s1, 0x24($sp)
/* DEF548 802406A8 0080882D */  daddu     $s1, $a0, $zero
/* DEF54C 802406AC AFBF0028 */  sw        $ra, 0x28($sp)
/* DEF550 802406B0 AFB00020 */  sw        $s0, 0x20($sp)
/* DEF554 802406B4 8E220148 */  lw        $v0, 0x148($s1)
/* DEF558 802406B8 0C00EABB */  jal       get_npc_unsafe
/* DEF55C 802406BC 84440008 */   lh       $a0, 8($v0)
/* DEF560 802406C0 0040802D */  daddu     $s0, $v0, $zero
/* DEF564 802406C4 0200202D */  daddu     $a0, $s0, $zero
/* DEF568 802406C8 C600000C */  lwc1      $f0, 0xc($s0)
/* DEF56C 802406CC 27A60018 */  addiu     $a2, $sp, 0x18
/* DEF570 802406D0 E7A00018 */  swc1      $f0, 0x18($sp)
/* DEF574 802406D4 AFA00010 */  sw        $zero, 0x10($sp)
/* DEF578 802406D8 AFA00014 */  sw        $zero, 0x14($sp)
/* DEF57C 802406DC 8E050018 */  lw        $a1, 0x18($s0)
/* DEF580 802406E0 0C0129E1 */  jal       func_8004A784
/* DEF584 802406E4 0000382D */   daddu    $a3, $zero, $zero
/* DEF588 802406E8 14400005 */  bnez      $v0, .L80240700
/* DEF58C 802406EC 00000000 */   nop
/* DEF590 802406F0 8E050018 */  lw        $a1, 0x18($s0)
/* DEF594 802406F4 8E06000C */  lw        $a2, 0xc($s0)
/* DEF598 802406F8 0C00EA95 */  jal       npc_move_heading
/* DEF59C 802406FC 0200202D */   daddu    $a0, $s0, $zero
.L80240700:
/* DEF5A0 80240700 9602008E */  lhu       $v0, 0x8e($s0)
/* DEF5A4 80240704 2442FFFF */  addiu     $v0, $v0, -1
/* DEF5A8 80240708 A602008E */  sh        $v0, 0x8e($s0)
/* DEF5AC 8024070C 00021400 */  sll       $v0, $v0, 0x10
/* DEF5B0 80240710 14400004 */  bnez      $v0, .L80240724
/* DEF5B4 80240714 2402001E */   addiu    $v0, $zero, 0x1e
/* DEF5B8 80240718 A602008E */  sh        $v0, 0x8e($s0)
/* DEF5BC 8024071C 24020011 */  addiu     $v0, $zero, 0x11
/* DEF5C0 80240720 AE220070 */  sw        $v0, 0x70($s1)
.L80240724:
/* DEF5C4 80240724 8FBF0028 */  lw        $ra, 0x28($sp)
/* DEF5C8 80240728 8FB10024 */  lw        $s1, 0x24($sp)
/* DEF5CC 8024072C 8FB00020 */  lw        $s0, 0x20($sp)
/* DEF5D0 80240730 03E00008 */  jr        $ra
/* DEF5D4 80240734 27BD0030 */   addiu    $sp, $sp, 0x30
