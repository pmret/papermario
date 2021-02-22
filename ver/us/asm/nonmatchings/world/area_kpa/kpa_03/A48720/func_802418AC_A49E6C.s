.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418AC_A49E6C
/* A49E6C 802418AC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A49E70 802418B0 AFB10014 */  sw        $s1, 0x14($sp)
/* A49E74 802418B4 0080882D */  daddu     $s1, $a0, $zero
/* A49E78 802418B8 AFBF0018 */  sw        $ra, 0x18($sp)
/* A49E7C 802418BC AFB00010 */  sw        $s0, 0x10($sp)
/* A49E80 802418C0 8E300148 */  lw        $s0, 0x148($s1)
/* A49E84 802418C4 0C00EABB */  jal       get_npc_unsafe
/* A49E88 802418C8 86040008 */   lh       $a0, 8($s0)
/* A49E8C 802418CC 0040202D */  daddu     $a0, $v0, $zero
/* A49E90 802418D0 9482008E */  lhu       $v0, 0x8e($a0)
/* A49E94 802418D4 2442FFFF */  addiu     $v0, $v0, -1
/* A49E98 802418D8 A482008E */  sh        $v0, 0x8e($a0)
/* A49E9C 802418DC 00021400 */  sll       $v0, $v0, 0x10
/* A49EA0 802418E0 1C400008 */  bgtz      $v0, .L80241904
/* A49EA4 802418E4 00000000 */   nop
/* A49EA8 802418E8 8E0200CC */  lw        $v0, 0xcc($s0)
/* A49EAC 802418EC 8C430024 */  lw        $v1, 0x24($v0)
/* A49EB0 802418F0 24020009 */  addiu     $v0, $zero, 9
/* A49EB4 802418F4 A482008E */  sh        $v0, 0x8e($a0)
/* A49EB8 802418F8 24020017 */  addiu     $v0, $zero, 0x17
/* A49EBC 802418FC AC830028 */  sw        $v1, 0x28($a0)
/* A49EC0 80241900 AE220070 */  sw        $v0, 0x70($s1)
.L80241904:
/* A49EC4 80241904 8FBF0018 */  lw        $ra, 0x18($sp)
/* A49EC8 80241908 8FB10014 */  lw        $s1, 0x14($sp)
/* A49ECC 8024190C 8FB00010 */  lw        $s0, 0x10($sp)
/* A49ED0 80241910 03E00008 */  jr        $ra
/* A49ED4 80241914 27BD0020 */   addiu    $sp, $sp, 0x20
