.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413D0_BCFFC0
/* BCFFC0 802413D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BCFFC4 802413D4 AFBF0014 */  sw        $ra, 0x14($sp)
/* BCFFC8 802413D8 0C090150 */  jal       func_80240540_BCF130
/* BCFFCC 802413DC AFB00010 */   sw       $s0, 0x10($sp)
/* BCFFD0 802413E0 0040802D */  daddu     $s0, $v0, $zero
/* BCFFD4 802413E4 2402FFFF */  addiu     $v0, $zero, -1
/* BCFFD8 802413E8 3C05800A */  lui       $a1, %hi(gOverrideFlags)
/* BCFFDC 802413EC 24A5A650 */  addiu     $a1, $a1, %lo(gOverrideFlags)
/* BCFFE0 802413F0 2403FFEF */  addiu     $v1, $zero, -0x11
/* BCFFE4 802413F4 AE020030 */  sw        $v0, 0x30($s0)
/* BCFFE8 802413F8 8CA20000 */  lw        $v0, ($a1)
/* BCFFEC 802413FC 8E04003C */  lw        $a0, 0x3c($s0)
/* BCFFF0 80241400 00431024 */  and       $v0, $v0, $v1
/* BCFFF4 80241404 0C05123D */  jal       free_icon
/* BCFFF8 80241408 ACA20000 */   sw       $v0, ($a1)
/* BCFFFC 8024140C 8E040040 */  lw        $a0, 0x40($s0)
/* BD0000 80241410 0C05123D */  jal       free_icon
/* BD0004 80241414 00000000 */   nop
/* BD0008 80241418 0C05123D */  jal       free_icon
/* BD000C 8024141C 8E040044 */   lw       $a0, 0x44($s0)
/* BD0010 80241420 0C048D70 */  jal       free_dynamic_entity
/* BD0014 80241424 8E04002C */   lw       $a0, 0x2c($s0)
/* BD0018 80241428 8FBF0014 */  lw        $ra, 0x14($sp)
/* BD001C 8024142C 8FB00010 */  lw        $s0, 0x10($sp)
/* BD0020 80241430 24020002 */  addiu     $v0, $zero, 2
/* BD0024 80241434 03E00008 */  jr        $ra
/* BD0028 80241438 27BD0018 */   addiu    $sp, $sp, 0x18
