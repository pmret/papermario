.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C1C_B9881C
/* B9881C 80240C1C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B98820 80240C20 AFB00010 */  sw        $s0, 0x10($sp)
/* B98824 80240C24 0080802D */  daddu     $s0, $a0, $zero
/* B98828 80240C28 AFBF0014 */  sw        $ra, 0x14($sp)
/* B9882C 80240C2C 8E020148 */  lw        $v0, 0x148($s0)
/* B98830 80240C30 0C00EABB */  jal       get_npc_unsafe
/* B98834 80240C34 84440008 */   lh       $a0, 8($v0)
/* B98838 80240C38 9443008E */  lhu       $v1, 0x8e($v0)
/* B9883C 80240C3C 2463FFFF */  addiu     $v1, $v1, -1
/* B98840 80240C40 A443008E */  sh        $v1, 0x8e($v0)
/* B98844 80240C44 00031C00 */  sll       $v1, $v1, 0x10
/* B98848 80240C48 58600001 */  blezl     $v1, .L80240C50
/* B9884C 80240C4C AE000070 */   sw       $zero, 0x70($s0)
.L80240C50:
/* B98850 80240C50 8FBF0014 */  lw        $ra, 0x14($sp)
/* B98854 80240C54 8FB00010 */  lw        $s0, 0x10($sp)
/* B98858 80240C58 03E00008 */  jr        $ra
/* B9885C 80240C5C 27BD0018 */   addiu    $sp, $sp, 0x18
