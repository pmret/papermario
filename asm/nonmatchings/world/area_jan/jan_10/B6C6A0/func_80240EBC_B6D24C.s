.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EBC_B6D24C
/* B6D24C 80240EBC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B6D250 80240EC0 AFB00010 */  sw        $s0, 0x10($sp)
/* B6D254 80240EC4 0080802D */  daddu     $s0, $a0, $zero
/* B6D258 80240EC8 AFBF0014 */  sw        $ra, 0x14($sp)
/* B6D25C 80240ECC 8E020148 */  lw        $v0, 0x148($s0)
/* B6D260 80240ED0 0C00EABB */  jal       get_npc_unsafe
/* B6D264 80240ED4 84440008 */   lh       $a0, 8($v0)
/* B6D268 80240ED8 9443008E */  lhu       $v1, 0x8e($v0)
/* B6D26C 80240EDC 2463FFFF */  addiu     $v1, $v1, -1
/* B6D270 80240EE0 A443008E */  sh        $v1, 0x8e($v0)
/* B6D274 80240EE4 00031C00 */  sll       $v1, $v1, 0x10
/* B6D278 80240EE8 58600001 */  blezl     $v1, .L80240EF0
/* B6D27C 80240EEC AE000070 */   sw       $zero, 0x70($s0)
.L80240EF0:
/* B6D280 80240EF0 8FBF0014 */  lw        $ra, 0x14($sp)
/* B6D284 80240EF4 8FB00010 */  lw        $s0, 0x10($sp)
/* B6D288 80240EF8 03E00008 */  jr        $ra
/* B6D28C 80240EFC 27BD0018 */   addiu    $sp, $sp, 0x18
