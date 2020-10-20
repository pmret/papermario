.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024153C
/* DBE7EC 8024153C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DBE7F0 80241540 AFB10024 */  sw        $s1, 0x24($sp)
/* DBE7F4 80241544 0080882D */  daddu     $s1, $a0, $zero
/* DBE7F8 80241548 AFBF0028 */  sw        $ra, 0x28($sp)
/* DBE7FC 8024154C AFB00020 */  sw        $s0, 0x20($sp)
/* DBE800 80241550 8E220148 */  lw        $v0, 0x148($s1)
/* DBE804 80241554 0C00EABB */  jal       get_npc_unsafe
/* DBE808 80241558 84440008 */   lh       $a0, 8($v0)
/* DBE80C 8024155C 0040802D */  daddu     $s0, $v0, $zero
/* DBE810 80241560 0200202D */  daddu     $a0, $s0, $zero
/* DBE814 80241564 C600000C */  lwc1      $f0, 0xc($s0)
/* DBE818 80241568 27A60018 */  addiu     $a2, $sp, 0x18
/* DBE81C 8024156C E7A00018 */  swc1      $f0, 0x18($sp)
/* DBE820 80241570 AFA00010 */  sw        $zero, 0x10($sp)
/* DBE824 80241574 AFA00014 */  sw        $zero, 0x14($sp)
/* DBE828 80241578 8E050018 */  lw        $a1, 0x18($s0)
/* DBE82C 8024157C 0C0129E1 */  jal       func_8004A784
/* DBE830 80241580 0000382D */   daddu    $a3, $zero, $zero
/* DBE834 80241584 14400005 */  bnez      $v0, .L8024159C
/* DBE838 80241588 00000000 */   nop      
/* DBE83C 8024158C 8E050018 */  lw        $a1, 0x18($s0)
/* DBE840 80241590 8E06000C */  lw        $a2, 0xc($s0)
/* DBE844 80241594 0C00EA95 */  jal       npc_move_heading
/* DBE848 80241598 0200202D */   daddu    $a0, $s0, $zero
.L8024159C:
/* DBE84C 8024159C 9602008E */  lhu       $v0, 0x8e($s0)
/* DBE850 802415A0 2442FFFF */  addiu     $v0, $v0, -1
/* DBE854 802415A4 A602008E */  sh        $v0, 0x8e($s0)
/* DBE858 802415A8 00021400 */  sll       $v0, $v0, 0x10
/* DBE85C 802415AC 14400004 */  bnez      $v0, .L802415C0
/* DBE860 802415B0 2402001E */   addiu    $v0, $zero, 0x1e
/* DBE864 802415B4 A602008E */  sh        $v0, 0x8e($s0)
/* DBE868 802415B8 24020011 */  addiu     $v0, $zero, 0x11
/* DBE86C 802415BC AE220070 */  sw        $v0, 0x70($s1)
.L802415C0:
/* DBE870 802415C0 8FBF0028 */  lw        $ra, 0x28($sp)
/* DBE874 802415C4 8FB10024 */  lw        $s1, 0x24($sp)
/* DBE878 802415C8 8FB00020 */  lw        $s0, 0x20($sp)
/* DBE87C 802415CC 03E00008 */  jr        $ra
/* DBE880 802415D0 27BD0030 */   addiu    $sp, $sp, 0x30
