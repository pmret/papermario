.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407F0_B4B260
/* B4B260 802407F0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B4B264 802407F4 AFBF0020 */  sw        $ra, 0x20($sp)
/* B4B268 802407F8 AFB1001C */  sw        $s1, 0x1c($sp)
/* B4B26C 802407FC AFB00018 */  sw        $s0, 0x18($sp)
/* B4B270 80240800 8C910148 */  lw        $s1, 0x148($a0)
/* B4B274 80240804 0C00EABB */  jal       get_npc_unsafe
/* B4B278 80240808 86240008 */   lh       $a0, 8($s1)
/* B4B27C 8024080C 8E23006C */  lw        $v1, 0x6c($s1)
/* B4B280 80240810 28630005 */  slti      $v1, $v1, 5
/* B4B284 80240814 1060001D */  beqz      $v1, .L8024088C
/* B4B288 80240818 0040802D */   daddu    $s0, $v0, $zero
/* B4B28C 8024081C 0C00A67F */  jal       rand_int
/* B4B290 80240820 240403E8 */   addiu    $a0, $zero, 0x3e8
/* B4B294 80240824 2842012D */  slti      $v0, $v0, 0x12d
/* B4B298 80240828 14400018 */  bnez      $v0, .L8024088C
/* B4B29C 8024082C 24020003 */   addiu    $v0, $zero, 3
/* B4B2A0 80240830 860300A8 */  lh        $v1, 0xa8($s0)
/* B4B2A4 80240834 C604003C */  lwc1      $f4, 0x3c($s0)
/* B4B2A8 80240838 C6000040 */  lwc1      $f0, 0x40($s0)
/* B4B2AC 8024083C 3C014014 */  lui       $at, 0x4014
/* B4B2B0 80240840 44811800 */  mtc1      $at, $f3
/* B4B2B4 80240844 44801000 */  mtc1      $zero, $f2
/* B4B2B8 80240848 AFA20010 */  sw        $v0, 0x10($sp)
/* B4B2BC 8024084C 46000021 */  cvt.d.s   $f0, $f0
/* B4B2C0 80240850 46220000 */  add.d     $f0, $f0, $f2
/* B4B2C4 80240854 AFA00014 */  sw        $zero, 0x14($sp)
/* B4B2C8 80240858 44831000 */  mtc1      $v1, $f2
/* B4B2CC 8024085C 00000000 */  nop       
/* B4B2D0 80240860 468010A0 */  cvt.s.w   $f2, $f2
/* B4B2D4 80240864 46022100 */  add.s     $f4, $f4, $f2
/* B4B2D8 80240868 8E050038 */  lw        $a1, 0x38($s0)
/* B4B2DC 8024086C 46200020 */  cvt.s.d   $f0, $f0
/* B4B2E0 80240870 44062000 */  mfc1      $a2, $f4
/* B4B2E4 80240874 44070000 */  mfc1      $a3, $f0
/* B4B2E8 80240878 0C04C6A5 */  jal       make_item_entity_nodelay
/* B4B2EC 8024087C 24040156 */   addiu    $a0, $zero, 0x156
/* B4B2F0 80240880 8E22006C */  lw        $v0, 0x6c($s1)
/* B4B2F4 80240884 24420001 */  addiu     $v0, $v0, 1
/* B4B2F8 80240888 AE22006C */  sw        $v0, 0x6c($s1)
.L8024088C:
/* B4B2FC 8024088C 8FBF0020 */  lw        $ra, 0x20($sp)
/* B4B300 80240890 8FB1001C */  lw        $s1, 0x1c($sp)
/* B4B304 80240894 8FB00018 */  lw        $s0, 0x18($sp)
/* B4B308 80240898 24020002 */  addiu     $v0, $zero, 2
/* B4B30C 8024089C 03E00008 */  jr        $ra
/* B4B310 802408A0 27BD0028 */   addiu    $sp, $sp, 0x28
