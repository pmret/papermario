.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241608_B53E38
/* B53E38 80241608 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B53E3C 8024160C AFB10014 */  sw        $s1, 0x14($sp)
/* B53E40 80241610 0080882D */  daddu     $s1, $a0, $zero
/* B53E44 80241614 AFBF0018 */  sw        $ra, 0x18($sp)
/* B53E48 80241618 AFB00010 */  sw        $s0, 0x10($sp)
/* B53E4C 8024161C 8E300148 */  lw        $s0, 0x148($s1)
/* B53E50 80241620 0C00EABB */  jal       get_npc_unsafe
/* B53E54 80241624 86040008 */   lh       $a0, 8($s0)
/* B53E58 80241628 3C054387 */  lui       $a1, 0x4387
/* B53E5C 8024162C 0040202D */  daddu     $a0, $v0, $zero
/* B53E60 80241630 0C00ECD0 */  jal       set_npc_yaw
/* B53E64 80241634 A480008E */   sh       $zero, 0x8e($a0)
/* B53E68 80241638 24020003 */  addiu     $v0, $zero, 3
/* B53E6C 8024163C AE00006C */  sw        $zero, 0x6c($s0)
/* B53E70 80241640 AE220070 */  sw        $v0, 0x70($s1)
/* B53E74 80241644 8FBF0018 */  lw        $ra, 0x18($sp)
/* B53E78 80241648 8FB10014 */  lw        $s1, 0x14($sp)
/* B53E7C 8024164C 8FB00010 */  lw        $s0, 0x10($sp)
/* B53E80 80241650 03E00008 */  jr        $ra
/* B53E84 80241654 27BD0020 */   addiu    $sp, $sp, 0x20
