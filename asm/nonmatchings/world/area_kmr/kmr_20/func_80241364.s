.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241364
/* 8ED184 80241364 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8ED188 80241368 AFB10014 */  sw        $s1, 0x14($sp)
/* 8ED18C 8024136C 0080882D */  daddu     $s1, $a0, $zero
/* 8ED190 80241370 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8ED194 80241374 AFB00010 */  sw        $s0, 0x10($sp)
/* 8ED198 80241378 8E30000C */  lw        $s0, 0xc($s1)
/* 8ED19C 8024137C 8E050000 */  lw        $a1, ($s0)
/* 8ED1A0 80241380 0C0B1EAF */  jal       get_variable
/* 8ED1A4 80241384 26100004 */   addiu    $s0, $s0, 4
/* 8ED1A8 80241388 0220202D */  daddu     $a0, $s1, $zero
/* 8ED1AC 8024138C 8E050000 */  lw        $a1, ($s0)
/* 8ED1B0 80241390 0C0B1EAF */  jal       get_variable
/* 8ED1B4 80241394 0040802D */   daddu    $s0, $v0, $zero
/* 8ED1B8 80241398 44820000 */  mtc1      $v0, $f0
/* 8ED1BC 8024139C 00000000 */  nop       
/* 8ED1C0 802413A0 46800020 */  cvt.s.w   $f0, $f0
/* 8ED1C4 802413A4 24020002 */  addiu     $v0, $zero, 2
/* 8ED1C8 802413A8 00501804 */  sllv      $v1, $s0, $v0
/* 8ED1CC 802413AC 00701821 */  addu      $v1, $v1, $s0
/* 8ED1D0 802413B0 00431804 */  sllv      $v1, $v1, $v0
/* 8ED1D4 802413B4 00701823 */  subu      $v1, $v1, $s0
/* 8ED1D8 802413B8 000320C0 */  sll       $a0, $v1, 3
/* 8ED1DC 802413BC 00641821 */  addu      $v1, $v1, $a0
/* 8ED1E0 802413C0 000318C0 */  sll       $v1, $v1, 3
/* 8ED1E4 802413C4 3C01800B */  lui       $at, 0x800b
/* 8ED1E8 802413C8 00230821 */  addu      $at, $at, $v1
/* 8ED1EC 802413CC E4201D98 */  swc1      $f0, 0x1d98($at)
/* 8ED1F0 802413D0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8ED1F4 802413D4 8FB10014 */  lw        $s1, 0x14($sp)
/* 8ED1F8 802413D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 8ED1FC 802413DC 03E00008 */  jr        $ra
/* 8ED200 802413E0 27BD0020 */   addiu    $sp, $sp, 0x20
