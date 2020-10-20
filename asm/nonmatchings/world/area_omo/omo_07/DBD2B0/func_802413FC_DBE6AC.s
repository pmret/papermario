.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413FC_DBE6AC
/* DBE6AC 802413FC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DBE6B0 80241400 AFB10014 */  sw        $s1, 0x14($sp)
/* DBE6B4 80241404 0080882D */  daddu     $s1, $a0, $zero
/* DBE6B8 80241408 AFBF0018 */  sw        $ra, 0x18($sp)
/* DBE6BC 8024140C AFB00010 */  sw        $s0, 0x10($sp)
/* DBE6C0 80241410 8E300148 */  lw        $s0, 0x148($s1)
/* DBE6C4 80241414 0C00EABB */  jal       get_npc_unsafe
/* DBE6C8 80241418 86040008 */   lh       $a0, 8($s0)
/* DBE6CC 8024141C C4400018 */  lwc1      $f0, 0x18($v0)
/* DBE6D0 80241420 3C018024 */  lui       $at, 0x8024
/* DBE6D4 80241424 D4226F10 */  ldc1      $f2, 0x6f10($at)
/* DBE6D8 80241428 46000021 */  cvt.d.s   $f0, $f0
/* DBE6DC 8024142C 46220002 */  mul.d     $f0, $f0, $f2
/* DBE6E0 80241430 00000000 */  nop       
/* DBE6E4 80241434 46200020 */  cvt.s.d   $f0, $f0
/* DBE6E8 80241438 E4400018 */  swc1      $f0, 0x18($v0)
/* DBE6EC 8024143C 8E0300CC */  lw        $v1, 0xcc($s0)
/* DBE6F0 80241440 8C640030 */  lw        $a0, 0x30($v1)
/* DBE6F4 80241444 24030005 */  addiu     $v1, $zero, 5
/* DBE6F8 80241448 A443008E */  sh        $v1, 0x8e($v0)
/* DBE6FC 8024144C AC440028 */  sw        $a0, 0x28($v0)
/* DBE700 80241450 2402000F */  addiu     $v0, $zero, 0xf
/* DBE704 80241454 AE220070 */  sw        $v0, 0x70($s1)
/* DBE708 80241458 8FBF0018 */  lw        $ra, 0x18($sp)
/* DBE70C 8024145C 8FB10014 */  lw        $s1, 0x14($sp)
/* DBE710 80241460 8FB00010 */  lw        $s0, 0x10($sp)
/* DBE714 80241464 03E00008 */  jr        $ra
/* DBE718 80241468 27BD0020 */   addiu    $sp, $sp, 0x20
