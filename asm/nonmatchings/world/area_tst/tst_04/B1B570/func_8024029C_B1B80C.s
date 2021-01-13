.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024029C_B1B80C
/* B1B80C 8024029C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B1B810 802402A0 AFB00040 */  sw        $s0, 0x40($sp)
/* B1B814 802402A4 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* B1B818 802402A8 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* B1B81C 802402AC AFBF0048 */  sw        $ra, 0x48($sp)
/* B1B820 802402B0 AFB10044 */  sw        $s1, 0x44($sp)
/* B1B824 802402B4 8E020000 */  lw        $v0, ($s0)
/* B1B828 802402B8 30420001 */  andi      $v0, $v0, 1
/* B1B82C 802402BC 10400023 */  beqz      $v0, .L8024034C
/* B1B830 802402C0 27B10020 */   addiu    $s1, $sp, 0x20
/* B1B834 802402C4 8E0400CC */  lw        $a0, 0xcc($s0)
/* B1B838 802402C8 0C044181 */  jal       get_shadow_by_index
/* B1B83C 802402CC 00000000 */   nop
/* B1B840 802402D0 0C048B77 */  jal       func_80122DDC
/* B1B844 802402D4 84440008 */   lh       $a0, 8($v0)
/* B1B848 802402D8 8C430000 */  lw        $v1, ($v0)
/* B1B84C 802402DC 3C04800A */  lui       $a0, %hi(D_8009A634)
/* B1B850 802402E0 8484A634 */  lh        $a0, %lo(D_8009A634)($a0)
/* B1B854 802402E4 34630200 */  ori       $v1, $v1, 0x200
/* B1B858 802402E8 AC430000 */  sw        $v1, ($v0)
/* B1B85C 802402EC 27A20030 */  addiu     $v0, $sp, 0x30
/* B1B860 802402F0 AFA20010 */  sw        $v0, 0x10($sp)
/* B1B864 802402F4 27A20034 */  addiu     $v0, $sp, 0x34
/* B1B868 802402F8 AFA20014 */  sw        $v0, 0x14($sp)
/* B1B86C 802402FC 27A20038 */  addiu     $v0, $sp, 0x38
/* B1B870 80240300 AFA20018 */  sw        $v0, 0x18($sp)
/* B1B874 80240304 C6000030 */  lwc1      $f0, 0x30($s0)
/* B1B878 80240308 8E050028 */  lw        $a1, 0x28($s0)
/* B1B87C 8024030C 8E06002C */  lw        $a2, 0x2c($s0)
/* B1B880 80240310 46000007 */  neg.s     $f0, $f0
/* B1B884 80240314 44070000 */  mfc1      $a3, $f0
/* B1B888 80240318 0C00B94E */  jal       get_screen_coords
/* B1B88C 8024031C 00000000 */   nop
/* B1B890 80240320 0220202D */  daddu     $a0, $s1, $zero
/* B1B894 80240324 AFB00028 */  sw        $s0, 0x28($sp)
/* B1B898 80240328 820500BE */  lb        $a1, 0xbe($s0)
/* B1B89C 8024032C 8FA30038 */  lw        $v1, 0x38($sp)
/* B1B8A0 80240330 3C028024 */  lui       $v0, %hi(func_80240360_B1B8D0)
/* B1B8A4 80240334 24420360 */  addiu     $v0, $v0, %lo(func_80240360_B1B8D0)
/* B1B8A8 80240338 AFA2002C */  sw        $v0, 0x2c($sp)
/* B1B8AC 8024033C 00031823 */  negu      $v1, $v1
/* B1B8B0 80240340 AFA50020 */  sw        $a1, 0x20($sp)
/* B1B8B4 80240344 0C047644 */  jal       queue_render_task
/* B1B8B8 80240348 AFA30024 */   sw       $v1, 0x24($sp)
.L8024034C:
/* B1B8BC 8024034C 8FBF0048 */  lw        $ra, 0x48($sp)
/* B1B8C0 80240350 8FB10044 */  lw        $s1, 0x44($sp)
/* B1B8C4 80240354 8FB00040 */  lw        $s0, 0x40($sp)
/* B1B8C8 80240358 03E00008 */  jr        $ra
/* B1B8CC 8024035C 27BD0050 */   addiu    $sp, $sp, 0x50
