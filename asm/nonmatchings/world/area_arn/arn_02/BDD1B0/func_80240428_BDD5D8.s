.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240428_BDD5D8
/* BDD5D8 80240428 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BDD5DC 8024042C AFB10014 */  sw        $s1, 0x14($sp)
/* BDD5E0 80240430 0080882D */  daddu     $s1, $a0, $zero
/* BDD5E4 80240434 AFBF001C */  sw        $ra, 0x1c($sp)
/* BDD5E8 80240438 AFB20018 */  sw        $s2, 0x18($sp)
/* BDD5EC 8024043C AFB00010 */  sw        $s0, 0x10($sp)
/* BDD5F0 80240440 8E320148 */  lw        $s2, 0x148($s1)
/* BDD5F4 80240444 0C00EABB */  jal       get_npc_unsafe
/* BDD5F8 80240448 86440008 */   lh       $a0, 8($s2)
/* BDD5FC 8024044C 240400B4 */  addiu     $a0, $zero, 0xb4
/* BDD600 80240450 0C00A67F */  jal       rand_int
/* BDD604 80240454 0040802D */   daddu    $s0, $v0, $zero
/* BDD608 80240458 C60C000C */  lwc1      $f12, 0xc($s0)
/* BDD60C 8024045C 44820000 */  mtc1      $v0, $f0
/* BDD610 80240460 00000000 */  nop
/* BDD614 80240464 46800020 */  cvt.s.w   $f0, $f0
/* BDD618 80240468 46006300 */  add.s     $f12, $f12, $f0
/* BDD61C 8024046C 3C0142B4 */  lui       $at, 0x42b4
/* BDD620 80240470 44810000 */  mtc1      $at, $f0
/* BDD624 80240474 0C00A6C9 */  jal       clamp_angle
/* BDD628 80240478 46006301 */   sub.s    $f12, $f12, $f0
/* BDD62C 8024047C E600000C */  swc1      $f0, 0xc($s0)
/* BDD630 80240480 8E4200CC */  lw        $v0, 0xcc($s2)
/* BDD634 80240484 8C420000 */  lw        $v0, ($v0)
/* BDD638 80240488 240403E8 */  addiu     $a0, $zero, 0x3e8
/* BDD63C 8024048C 0C00A67F */  jal       rand_int
/* BDD640 80240490 AE020028 */   sw       $v0, 0x28($s0)
/* BDD644 80240494 00021FC2 */  srl       $v1, $v0, 0x1f
/* BDD648 80240498 00431821 */  addu      $v1, $v0, $v1
/* BDD64C 8024049C 00031843 */  sra       $v1, $v1, 1
/* BDD650 802404A0 00031840 */  sll       $v1, $v1, 1
/* BDD654 802404A4 00431023 */  subu      $v0, $v0, $v1
/* BDD658 802404A8 24420002 */  addiu     $v0, $v0, 2
/* BDD65C 802404AC AE220074 */  sw        $v0, 0x74($s1)
/* BDD660 802404B0 24020005 */  addiu     $v0, $zero, 5
/* BDD664 802404B4 AE220070 */  sw        $v0, 0x70($s1)
/* BDD668 802404B8 8FBF001C */  lw        $ra, 0x1c($sp)
/* BDD66C 802404BC 8FB20018 */  lw        $s2, 0x18($sp)
/* BDD670 802404C0 8FB10014 */  lw        $s1, 0x14($sp)
/* BDD674 802404C4 8FB00010 */  lw        $s0, 0x10($sp)
/* BDD678 802404C8 03E00008 */  jr        $ra
/* BDD67C 802404CC 27BD0020 */   addiu    $sp, $sp, 0x20
