.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411D4_C77EB4
/* C77EB4 802411D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C77EB8 802411D8 AFB10014 */  sw        $s1, 0x14($sp)
/* C77EBC 802411DC 0080882D */  daddu     $s1, $a0, $zero
/* C77EC0 802411E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* C77EC4 802411E4 AFB00010 */  sw        $s0, 0x10($sp)
/* C77EC8 802411E8 8E300148 */  lw        $s0, 0x148($s1)
/* C77ECC 802411EC 0C00EABB */  jal       get_npc_unsafe
/* C77ED0 802411F0 86040008 */   lh       $a0, 8($s0)
/* C77ED4 802411F4 9443008E */  lhu       $v1, 0x8e($v0)
/* C77ED8 802411F8 2463FFFF */  addiu     $v1, $v1, -1
/* C77EDC 802411FC A443008E */  sh        $v1, 0x8e($v0)
/* C77EE0 80241200 00031C00 */  sll       $v1, $v1, 0x10
/* C77EE4 80241204 1C600003 */  bgtz      $v1, .L80241214
/* C77EE8 80241208 2402000C */   addiu    $v0, $zero, 0xc
/* C77EEC 8024120C AE00006C */  sw        $zero, 0x6c($s0)
/* C77EF0 80241210 AE220070 */  sw        $v0, 0x70($s1)
.L80241214:
/* C77EF4 80241214 8FBF0018 */  lw        $ra, 0x18($sp)
/* C77EF8 80241218 8FB10014 */  lw        $s1, 0x14($sp)
/* C77EFC 8024121C 8FB00010 */  lw        $s0, 0x10($sp)
/* C77F00 80241220 03E00008 */  jr        $ra
/* C77F04 80241224 27BD0020 */   addiu    $sp, $sp, 0x20
