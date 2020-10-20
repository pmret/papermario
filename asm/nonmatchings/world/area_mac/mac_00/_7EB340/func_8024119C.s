.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024119C
/* 7EBEAC 8024119C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7EBEB0 802411A0 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EBEB4 802411A4 0080882D */  daddu     $s1, $a0, $zero
/* 7EBEB8 802411A8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7EBEBC 802411AC AFB00010 */  sw        $s0, 0x10($sp)
/* 7EBEC0 802411B0 8E30000C */  lw        $s0, 0xc($s1)
/* 7EBEC4 802411B4 8E050000 */  lw        $a1, ($s0)
/* 7EBEC8 802411B8 0C0B1EAF */  jal       get_variable
/* 7EBECC 802411BC 26100004 */   addiu    $s0, $s0, 4
/* 7EBED0 802411C0 0220202D */  daddu     $a0, $s1, $zero
/* 7EBED4 802411C4 8E050000 */  lw        $a1, ($s0)
/* 7EBED8 802411C8 0C0B210B */  jal       get_float_variable
/* 7EBEDC 802411CC 0040802D */   daddu    $s0, $v0, $zero
/* 7EBEE0 802411D0 24020002 */  addiu     $v0, $zero, 2
/* 7EBEE4 802411D4 00501804 */  sllv      $v1, $s0, $v0
/* 7EBEE8 802411D8 00701821 */  addu      $v1, $v1, $s0
/* 7EBEEC 802411DC 00431804 */  sllv      $v1, $v1, $v0
/* 7EBEF0 802411E0 00701823 */  subu      $v1, $v1, $s0
/* 7EBEF4 802411E4 000320C0 */  sll       $a0, $v1, 3
/* 7EBEF8 802411E8 00641821 */  addu      $v1, $v1, $a0
/* 7EBEFC 802411EC 000318C0 */  sll       $v1, $v1, 3
/* 7EBF00 802411F0 3C01800B */  lui       $at, 0x800b
/* 7EBF04 802411F4 00230821 */  addu      $at, $at, $v1
/* 7EBF08 802411F8 E4201D98 */  swc1      $f0, 0x1d98($at)
/* 7EBF0C 802411FC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7EBF10 80241200 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EBF14 80241204 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EBF18 80241208 03E00008 */  jr        $ra
/* 7EBF1C 8024120C 27BD0020 */   addiu    $sp, $sp, 0x20
