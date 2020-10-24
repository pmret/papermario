.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413A0_B5F650
/* B5F650 802413A0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B5F654 802413A4 AFBF0020 */  sw        $ra, 0x20($sp)
/* B5F658 802413A8 AFB1001C */  sw        $s1, 0x1c($sp)
/* B5F65C 802413AC AFB00018 */  sw        $s0, 0x18($sp)
/* B5F660 802413B0 8C910148 */  lw        $s1, 0x148($a0)
/* B5F664 802413B4 0C00EABB */  jal       get_npc_unsafe
/* B5F668 802413B8 86240008 */   lh       $a0, 8($s1)
/* B5F66C 802413BC 8E23006C */  lw        $v1, 0x6c($s1)
/* B5F670 802413C0 28630005 */  slti      $v1, $v1, 5
/* B5F674 802413C4 1060001D */  beqz      $v1, .L8024143C
/* B5F678 802413C8 0040802D */   daddu    $s0, $v0, $zero
/* B5F67C 802413CC 0C00A67F */  jal       rand_int
/* B5F680 802413D0 240403E8 */   addiu    $a0, $zero, 0x3e8
/* B5F684 802413D4 2842012D */  slti      $v0, $v0, 0x12d
/* B5F688 802413D8 14400018 */  bnez      $v0, .L8024143C
/* B5F68C 802413DC 24020003 */   addiu    $v0, $zero, 3
/* B5F690 802413E0 860300A8 */  lh        $v1, 0xa8($s0)
/* B5F694 802413E4 C604003C */  lwc1      $f4, 0x3c($s0)
/* B5F698 802413E8 C6000040 */  lwc1      $f0, 0x40($s0)
/* B5F69C 802413EC 3C014014 */  lui       $at, 0x4014
/* B5F6A0 802413F0 44811800 */  mtc1      $at, $f3
/* B5F6A4 802413F4 44801000 */  mtc1      $zero, $f2
/* B5F6A8 802413F8 AFA20010 */  sw        $v0, 0x10($sp)
/* B5F6AC 802413FC 46000021 */  cvt.d.s   $f0, $f0
/* B5F6B0 80241400 46220000 */  add.d     $f0, $f0, $f2
/* B5F6B4 80241404 AFA00014 */  sw        $zero, 0x14($sp)
/* B5F6B8 80241408 44831000 */  mtc1      $v1, $f2
/* B5F6BC 8024140C 00000000 */  nop       
/* B5F6C0 80241410 468010A0 */  cvt.s.w   $f2, $f2
/* B5F6C4 80241414 46022100 */  add.s     $f4, $f4, $f2
/* B5F6C8 80241418 8E050038 */  lw        $a1, 0x38($s0)
/* B5F6CC 8024141C 46200020 */  cvt.s.d   $f0, $f0
/* B5F6D0 80241420 44062000 */  mfc1      $a2, $f4
/* B5F6D4 80241424 44070000 */  mfc1      $a3, $f0
/* B5F6D8 80241428 0C04C6A5 */  jal       make_item_entity_nodelay
/* B5F6DC 8024142C 24040156 */   addiu    $a0, $zero, 0x156
/* B5F6E0 80241430 8E22006C */  lw        $v0, 0x6c($s1)
/* B5F6E4 80241434 24420001 */  addiu     $v0, $v0, 1
/* B5F6E8 80241438 AE22006C */  sw        $v0, 0x6c($s1)
.L8024143C:
/* B5F6EC 8024143C 8FBF0020 */  lw        $ra, 0x20($sp)
/* B5F6F0 80241440 8FB1001C */  lw        $s1, 0x1c($sp)
/* B5F6F4 80241444 8FB00018 */  lw        $s0, 0x18($sp)
/* B5F6F8 80241448 24020002 */  addiu     $v0, $zero, 2
/* B5F6FC 8024144C 03E00008 */  jr        $ra
/* B5F700 80241450 27BD0028 */   addiu    $sp, $sp, 0x28
