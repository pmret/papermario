.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241604
/* BAEF44 80241604 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BAEF48 80241608 AFB10014 */  sw        $s1, 0x14($sp)
/* BAEF4C 8024160C 0080882D */  daddu     $s1, $a0, $zero
/* BAEF50 80241610 AFBF0018 */  sw        $ra, 0x18($sp)
/* BAEF54 80241614 AFB00010 */  sw        $s0, 0x10($sp)
/* BAEF58 80241618 8E300148 */  lw        $s0, 0x148($s1)
/* BAEF5C 8024161C 0C00EABB */  jal       get_npc_unsafe
/* BAEF60 80241620 86040008 */   lh       $a0, 8($s0)
/* BAEF64 80241624 0040202D */  daddu     $a0, $v0, $zero
/* BAEF68 80241628 9482008E */  lhu       $v0, 0x8e($a0)
/* BAEF6C 8024162C 2442FFFF */  addiu     $v0, $v0, -1
/* BAEF70 80241630 A482008E */  sh        $v0, 0x8e($a0)
/* BAEF74 80241634 00021400 */  sll       $v0, $v0, 0x10
/* BAEF78 80241638 1C400009 */  bgtz      $v0, .L80241660
/* BAEF7C 8024163C 24020003 */   addiu    $v0, $zero, 3
/* BAEF80 80241640 96030076 */  lhu       $v1, 0x76($s0)
/* BAEF84 80241644 AE02006C */  sw        $v0, 0x6c($s0)
/* BAEF88 80241648 A483008E */  sh        $v1, 0x8e($a0)
/* BAEF8C 8024164C 8E0200CC */  lw        $v0, 0xcc($s0)
/* BAEF90 80241650 8C420024 */  lw        $v0, 0x24($v0)
/* BAEF94 80241654 AC820028 */  sw        $v0, 0x28($a0)
/* BAEF98 80241658 24020020 */  addiu     $v0, $zero, 0x20
/* BAEF9C 8024165C AE220070 */  sw        $v0, 0x70($s1)
.L80241660:
/* BAEFA0 80241660 8FBF0018 */  lw        $ra, 0x18($sp)
/* BAEFA4 80241664 8FB10014 */  lw        $s1, 0x14($sp)
/* BAEFA8 80241668 8FB00010 */  lw        $s0, 0x10($sp)
/* BAEFAC 8024166C 03E00008 */  jr        $ra
/* BAEFB0 80241670 27BD0020 */   addiu    $sp, $sp, 0x20
