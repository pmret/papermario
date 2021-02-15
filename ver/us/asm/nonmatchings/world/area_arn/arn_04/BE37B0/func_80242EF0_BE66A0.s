.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242EF0_BE66A0
/* BE66A0 80242EF0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BE66A4 80242EF4 AFB10014 */  sw        $s1, 0x14($sp)
/* BE66A8 80242EF8 0080882D */  daddu     $s1, $a0, $zero
/* BE66AC 80242EFC AFBF0018 */  sw        $ra, 0x18($sp)
/* BE66B0 80242F00 AFB00010 */  sw        $s0, 0x10($sp)
/* BE66B4 80242F04 8E300148 */  lw        $s0, 0x148($s1)
/* BE66B8 80242F08 0C00EABB */  jal       get_npc_unsafe
/* BE66BC 80242F0C 86040008 */   lh       $a0, 8($s0)
/* BE66C0 80242F10 0040202D */  daddu     $a0, $v0, $zero
/* BE66C4 80242F14 8482008E */  lh        $v0, 0x8e($a0)
/* BE66C8 80242F18 9483008E */  lhu       $v1, 0x8e($a0)
/* BE66CC 80242F1C 18400002 */  blez      $v0, .L80242F28
/* BE66D0 80242F20 2462FFFF */   addiu    $v0, $v1, -1
/* BE66D4 80242F24 A482008E */  sh        $v0, 0x8e($a0)
.L80242F28:
/* BE66D8 80242F28 8482008C */  lh        $v0, 0x8c($a0)
/* BE66DC 80242F2C 1440000A */  bnez      $v0, .L80242F58
/* BE66E0 80242F30 00000000 */   nop
/* BE66E4 80242F34 8482008E */  lh        $v0, 0x8e($a0)
/* BE66E8 80242F38 1C400007 */  bgtz      $v0, .L80242F58
/* BE66EC 80242F3C 24020008 */   addiu    $v0, $zero, 8
/* BE66F0 80242F40 A482008E */  sh        $v0, 0x8e($a0)
/* BE66F4 80242F44 8E0200CC */  lw        $v0, 0xcc($s0)
/* BE66F8 80242F48 8C42002C */  lw        $v0, 0x2c($v0)
/* BE66FC 80242F4C AC820028 */  sw        $v0, 0x28($a0)
/* BE6700 80242F50 24020033 */  addiu     $v0, $zero, 0x33
/* BE6704 80242F54 AE220070 */  sw        $v0, 0x70($s1)
.L80242F58:
/* BE6708 80242F58 8FBF0018 */  lw        $ra, 0x18($sp)
/* BE670C 80242F5C 8FB10014 */  lw        $s1, 0x14($sp)
/* BE6710 80242F60 8FB00010 */  lw        $s0, 0x10($sp)
/* BE6714 80242F64 03E00008 */  jr        $ra
/* BE6718 80242F68 27BD0020 */   addiu    $sp, $sp, 0x20
