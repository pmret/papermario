.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnkNpcAIFunc7
/* C73A28 802425A8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C73A2C 802425AC AFB10014 */  sw        $s1, 0x14($sp)
/* C73A30 802425B0 0080882D */  daddu     $s1, $a0, $zero
/* C73A34 802425B4 AFBF0018 */  sw        $ra, 0x18($sp)
/* C73A38 802425B8 AFB00010 */  sw        $s0, 0x10($sp)
/* C73A3C 802425BC 8E300148 */  lw        $s0, 0x148($s1)
/* C73A40 802425C0 0C00EABB */  jal       get_npc_unsafe
/* C73A44 802425C4 86040008 */   lh       $a0, 8($s0)
/* C73A48 802425C8 0040202D */  daddu     $a0, $v0, $zero
/* C73A4C 802425CC 9482008E */  lhu       $v0, 0x8e($a0)
/* C73A50 802425D0 2442FFFF */  addiu     $v0, $v0, -1
/* C73A54 802425D4 A482008E */  sh        $v0, 0x8e($a0)
/* C73A58 802425D8 00021400 */  sll       $v0, $v0, 0x10
/* C73A5C 802425DC 1C400009 */  bgtz      $v0, .L80242604
/* C73A60 802425E0 24020003 */   addiu    $v0, $zero, 3
/* C73A64 802425E4 96030076 */  lhu       $v1, 0x76($s0)
/* C73A68 802425E8 AE02006C */  sw        $v0, 0x6c($s0)
/* C73A6C 802425EC A483008E */  sh        $v1, 0x8e($a0)
/* C73A70 802425F0 8E0200CC */  lw        $v0, 0xcc($s0)
/* C73A74 802425F4 8C420024 */  lw        $v0, 0x24($v0)
/* C73A78 802425F8 AC820028 */  sw        $v0, 0x28($a0)
/* C73A7C 802425FC 24020020 */  addiu     $v0, $zero, 0x20
/* C73A80 80242600 AE220070 */  sw        $v0, 0x70($s1)
.L80242604:
/* C73A84 80242604 8FBF0018 */  lw        $ra, 0x18($sp)
/* C73A88 80242608 8FB10014 */  lw        $s1, 0x14($sp)
/* C73A8C 8024260C 8FB00010 */  lw        $s0, 0x10($sp)
/* C73A90 80242610 03E00008 */  jr        $ra
/* C73A94 80242614 27BD0020 */   addiu    $sp, $sp, 0x20
