.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415D4_DBE884
/* DBE884 802415D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DBE888 802415D8 AFB10014 */  sw        $s1, 0x14($sp)
/* DBE88C 802415DC 0080882D */  daddu     $s1, $a0, $zero
/* DBE890 802415E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* DBE894 802415E4 AFB00010 */  sw        $s0, 0x10($sp)
/* DBE898 802415E8 8E300148 */  lw        $s0, 0x148($s1)
/* DBE89C 802415EC 0C00EABB */  jal       get_npc_unsafe
/* DBE8A0 802415F0 86040008 */   lh       $a0, 8($s0)
/* DBE8A4 802415F4 0040182D */  daddu     $v1, $v0, $zero
/* DBE8A8 802415F8 9462008E */  lhu       $v0, 0x8e($v1)
/* DBE8AC 802415FC 2442FFFF */  addiu     $v0, $v0, -1
/* DBE8B0 80241600 A462008E */  sh        $v0, 0x8e($v1)
/* DBE8B4 80241604 00021400 */  sll       $v0, $v0, 0x10
/* DBE8B8 80241608 14400005 */  bnez      $v0, .L80241620
/* DBE8BC 8024160C 00000000 */   nop
/* DBE8C0 80241610 8E0200CC */  lw        $v0, 0xcc($s0)
/* DBE8C4 80241614 8C420000 */  lw        $v0, ($v0)
/* DBE8C8 80241618 AC620028 */  sw        $v0, 0x28($v1)
/* DBE8CC 8024161C AE200070 */  sw        $zero, 0x70($s1)
.L80241620:
/* DBE8D0 80241620 8FBF0018 */  lw        $ra, 0x18($sp)
/* DBE8D4 80241624 8FB10014 */  lw        $s1, 0x14($sp)
/* DBE8D8 80241628 8FB00010 */  lw        $s0, 0x10($sp)
/* DBE8DC 8024162C 03E00008 */  jr        $ra
/* DBE8E0 80241630 27BD0020 */   addiu    $sp, $sp, 0x20
