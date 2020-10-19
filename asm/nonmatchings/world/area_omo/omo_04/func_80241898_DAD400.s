.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241898_DAEC98
/* DAEC98 80241898 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DAEC9C 8024189C AFB10014 */  sw        $s1, 0x14($sp)
/* DAECA0 802418A0 0080882D */  daddu     $s1, $a0, $zero
/* DAECA4 802418A4 AFBF0018 */  sw        $ra, 0x18($sp)
/* DAECA8 802418A8 AFB00010 */  sw        $s0, 0x10($sp)
/* DAECAC 802418AC 8E300148 */  lw        $s0, 0x148($s1)
/* DAECB0 802418B0 0C00EABB */  jal       get_npc_unsafe
/* DAECB4 802418B4 86040008 */   lh       $a0, 8($s0)
/* DAECB8 802418B8 C4400018 */  lwc1      $f0, 0x18($v0)
/* DAECBC 802418BC 3C018024 */  lui       $at, 0x8024
/* DAECC0 802418C0 D4224D08 */  ldc1      $f2, 0x4d08($at)
/* DAECC4 802418C4 46000021 */  cvt.d.s   $f0, $f0
/* DAECC8 802418C8 46220002 */  mul.d     $f0, $f0, $f2
/* DAECCC 802418CC 00000000 */  nop       
/* DAECD0 802418D0 46200020 */  cvt.s.d   $f0, $f0
/* DAECD4 802418D4 E4400018 */  swc1      $f0, 0x18($v0)
/* DAECD8 802418D8 8E0300CC */  lw        $v1, 0xcc($s0)
/* DAECDC 802418DC 8C640030 */  lw        $a0, 0x30($v1)
/* DAECE0 802418E0 24030005 */  addiu     $v1, $zero, 5
/* DAECE4 802418E4 A443008E */  sh        $v1, 0x8e($v0)
/* DAECE8 802418E8 AC440028 */  sw        $a0, 0x28($v0)
/* DAECEC 802418EC 2402000F */  addiu     $v0, $zero, 0xf
/* DAECF0 802418F0 AE220070 */  sw        $v0, 0x70($s1)
/* DAECF4 802418F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* DAECF8 802418F8 8FB10014 */  lw        $s1, 0x14($sp)
/* DAECFC 802418FC 8FB00010 */  lw        $s0, 0x10($sp)
/* DAED00 80241900 03E00008 */  jr        $ra
/* DAED04 80241904 27BD0020 */   addiu    $sp, $sp, 0x20
