.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241554_B53D84
/* B53D84 80241554 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B53D88 80241558 AFBF0020 */  sw        $ra, 0x20($sp)
/* B53D8C 8024155C AFB1001C */  sw        $s1, 0x1c($sp)
/* B53D90 80241560 AFB00018 */  sw        $s0, 0x18($sp)
/* B53D94 80241564 8C910148 */  lw        $s1, 0x148($a0)
/* B53D98 80241568 0C00EABB */  jal       get_npc_unsafe
/* B53D9C 8024156C 86240008 */   lh       $a0, 8($s1)
/* B53DA0 80241570 8E23006C */  lw        $v1, 0x6c($s1)
/* B53DA4 80241574 28630005 */  slti      $v1, $v1, 5
/* B53DA8 80241578 1060001D */  beqz      $v1, .L802415F0
/* B53DAC 8024157C 0040802D */   daddu    $s0, $v0, $zero
/* B53DB0 80241580 0C00A67F */  jal       rand_int
/* B53DB4 80241584 240403E8 */   addiu    $a0, $zero, 0x3e8
/* B53DB8 80241588 2842012D */  slti      $v0, $v0, 0x12d
/* B53DBC 8024158C 14400018 */  bnez      $v0, .L802415F0
/* B53DC0 80241590 24020003 */   addiu    $v0, $zero, 3
/* B53DC4 80241594 860300A8 */  lh        $v1, 0xa8($s0)
/* B53DC8 80241598 C604003C */  lwc1      $f4, 0x3c($s0)
/* B53DCC 8024159C C6000040 */  lwc1      $f0, 0x40($s0)
/* B53DD0 802415A0 3C014014 */  lui       $at, 0x4014
/* B53DD4 802415A4 44811800 */  mtc1      $at, $f3
/* B53DD8 802415A8 44801000 */  mtc1      $zero, $f2
/* B53DDC 802415AC AFA20010 */  sw        $v0, 0x10($sp)
/* B53DE0 802415B0 46000021 */  cvt.d.s   $f0, $f0
/* B53DE4 802415B4 46220000 */  add.d     $f0, $f0, $f2
/* B53DE8 802415B8 AFA00014 */  sw        $zero, 0x14($sp)
/* B53DEC 802415BC 44831000 */  mtc1      $v1, $f2
/* B53DF0 802415C0 00000000 */  nop
/* B53DF4 802415C4 468010A0 */  cvt.s.w   $f2, $f2
/* B53DF8 802415C8 46022100 */  add.s     $f4, $f4, $f2
/* B53DFC 802415CC 8E050038 */  lw        $a1, 0x38($s0)
/* B53E00 802415D0 46200020 */  cvt.s.d   $f0, $f0
/* B53E04 802415D4 44062000 */  mfc1      $a2, $f4
/* B53E08 802415D8 44070000 */  mfc1      $a3, $f0
/* B53E0C 802415DC 0C04C6A5 */  jal       make_item_entity_nodelay
/* B53E10 802415E0 24040156 */   addiu    $a0, $zero, 0x156
/* B53E14 802415E4 8E22006C */  lw        $v0, 0x6c($s1)
/* B53E18 802415E8 24420001 */  addiu     $v0, $v0, 1
/* B53E1C 802415EC AE22006C */  sw        $v0, 0x6c($s1)
.L802415F0:
/* B53E20 802415F0 8FBF0020 */  lw        $ra, 0x20($sp)
/* B53E24 802415F4 8FB1001C */  lw        $s1, 0x1c($sp)
/* B53E28 802415F8 8FB00018 */  lw        $s0, 0x18($sp)
/* B53E2C 802415FC 24020002 */  addiu     $v0, $zero, 2
/* B53E30 80241600 03E00008 */  jr        $ra
/* B53E34 80241604 27BD0028 */   addiu    $sp, $sp, 0x28
