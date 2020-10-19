.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408D0_C2F470
/* C2F470 802408D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C2F474 802408D4 AFB10014 */  sw        $s1, 0x14($sp)
/* C2F478 802408D8 0080882D */  daddu     $s1, $a0, $zero
/* C2F47C 802408DC AFBF0018 */  sw        $ra, 0x18($sp)
/* C2F480 802408E0 AFB00010 */  sw        $s0, 0x10($sp)
/* C2F484 802408E4 8E300148 */  lw        $s0, 0x148($s1)
/* C2F488 802408E8 0C00EABB */  jal       get_npc_unsafe
/* C2F48C 802408EC 86040008 */   lh       $a0, 8($s0)
/* C2F490 802408F0 0040202D */  daddu     $a0, $v0, $zero
/* C2F494 802408F4 8482008E */  lh        $v0, 0x8e($a0)
/* C2F498 802408F8 9483008E */  lhu       $v1, 0x8e($a0)
/* C2F49C 802408FC 18400002 */  blez      $v0, .L80240908
/* C2F4A0 80240900 2462FFFF */   addiu    $v0, $v1, -1
/* C2F4A4 80240904 A482008E */  sh        $v0, 0x8e($a0)
.L80240908:
/* C2F4A8 80240908 8482008E */  lh        $v0, 0x8e($a0)
/* C2F4AC 8024090C 24030001 */  addiu     $v1, $zero, 1
/* C2F4B0 80240910 14430005 */  bne       $v0, $v1, .L80240928
/* C2F4B4 80240914 00000000 */   nop      
/* C2F4B8 80240918 8E0200CC */  lw        $v0, 0xcc($s0)
/* C2F4BC 8024091C 8C420030 */  lw        $v0, 0x30($v0)
/* C2F4C0 80240920 08090251 */  j         .L80240944
/* C2F4C4 80240924 AC820028 */   sw       $v0, 0x28($a0)
.L80240928:
/* C2F4C8 80240928 1C400006 */  bgtz      $v0, .L80240944
/* C2F4CC 8024092C 00000000 */   nop      
/* C2F4D0 80240930 8E0200CC */  lw        $v0, 0xcc($s0)
/* C2F4D4 80240934 8C420028 */  lw        $v0, 0x28($v0)
/* C2F4D8 80240938 A480008E */  sh        $zero, 0x8e($a0)
/* C2F4DC 8024093C AC820028 */  sw        $v0, 0x28($a0)
/* C2F4E0 80240940 AE230070 */  sw        $v1, 0x70($s1)
.L80240944:
/* C2F4E4 80240944 8FBF0018 */  lw        $ra, 0x18($sp)
/* C2F4E8 80240948 8FB10014 */  lw        $s1, 0x14($sp)
/* C2F4EC 8024094C 8FB00010 */  lw        $s0, 0x10($sp)
/* C2F4F0 80240950 03E00008 */  jr        $ra
/* C2F4F4 80240954 27BD0020 */   addiu    $sp, $sp, 0x20
