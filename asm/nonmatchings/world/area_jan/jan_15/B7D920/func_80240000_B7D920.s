.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_B7D920
/* B7D920 80240000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B7D924 80240004 AFBF0020 */  sw        $ra, 0x20($sp)
/* B7D928 80240008 AFB1001C */  sw        $s1, 0x1c($sp)
/* B7D92C 8024000C AFB00018 */  sw        $s0, 0x18($sp)
/* B7D930 80240010 8C910148 */  lw        $s1, 0x148($a0)
/* B7D934 80240014 0C00EABB */  jal       get_npc_unsafe
/* B7D938 80240018 86240008 */   lh       $a0, 8($s1)
/* B7D93C 8024001C 8E23006C */  lw        $v1, 0x6c($s1)
/* B7D940 80240020 28630005 */  slti      $v1, $v1, 5
/* B7D944 80240024 1060001D */  beqz      $v1, .L8024009C
/* B7D948 80240028 0040802D */   daddu    $s0, $v0, $zero
/* B7D94C 8024002C 0C00A67F */  jal       rand_int
/* B7D950 80240030 240403E8 */   addiu    $a0, $zero, 0x3e8
/* B7D954 80240034 2842012D */  slti      $v0, $v0, 0x12d
/* B7D958 80240038 14400018 */  bnez      $v0, .L8024009C
/* B7D95C 8024003C 24020003 */   addiu    $v0, $zero, 3
/* B7D960 80240040 860300A8 */  lh        $v1, 0xa8($s0)
/* B7D964 80240044 C604003C */  lwc1      $f4, 0x3c($s0)
/* B7D968 80240048 C6000040 */  lwc1      $f0, 0x40($s0)
/* B7D96C 8024004C 3C014014 */  lui       $at, 0x4014
/* B7D970 80240050 44811800 */  mtc1      $at, $f3
/* B7D974 80240054 44801000 */  mtc1      $zero, $f2
/* B7D978 80240058 AFA20010 */  sw        $v0, 0x10($sp)
/* B7D97C 8024005C 46000021 */  cvt.d.s   $f0, $f0
/* B7D980 80240060 46220000 */  add.d     $f0, $f0, $f2
/* B7D984 80240064 AFA00014 */  sw        $zero, 0x14($sp)
/* B7D988 80240068 44831000 */  mtc1      $v1, $f2
/* B7D98C 8024006C 00000000 */  nop
/* B7D990 80240070 468010A0 */  cvt.s.w   $f2, $f2
/* B7D994 80240074 46022100 */  add.s     $f4, $f4, $f2
/* B7D998 80240078 8E050038 */  lw        $a1, 0x38($s0)
/* B7D99C 8024007C 46200020 */  cvt.s.d   $f0, $f0
/* B7D9A0 80240080 44062000 */  mfc1      $a2, $f4
/* B7D9A4 80240084 44070000 */  mfc1      $a3, $f0
/* B7D9A8 80240088 0C04C6A5 */  jal       make_item_entity_nodelay
/* B7D9AC 8024008C 24040156 */   addiu    $a0, $zero, 0x156
/* B7D9B0 80240090 8E22006C */  lw        $v0, 0x6c($s1)
/* B7D9B4 80240094 24420001 */  addiu     $v0, $v0, 1
/* B7D9B8 80240098 AE22006C */  sw        $v0, 0x6c($s1)
.L8024009C:
/* B7D9BC 8024009C 8FBF0020 */  lw        $ra, 0x20($sp)
/* B7D9C0 802400A0 8FB1001C */  lw        $s1, 0x1c($sp)
/* B7D9C4 802400A4 8FB00018 */  lw        $s0, 0x18($sp)
/* B7D9C8 802400A8 24020002 */  addiu     $v0, $zero, 2
/* B7D9CC 802400AC 03E00008 */  jr        $ra
/* B7D9D0 802400B0 27BD0028 */   addiu    $sp, $sp, 0x28
/* B7D9D4 802400B4 00000000 */  nop
/* B7D9D8 802400B8 00000000 */  nop
/* B7D9DC 802400BC 00000000 */  nop
