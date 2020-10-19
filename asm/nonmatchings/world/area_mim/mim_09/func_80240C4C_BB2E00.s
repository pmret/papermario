.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C4C_BB3A4C
/* BB3A4C 80240C4C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BB3A50 80240C50 AFB00010 */  sw        $s0, 0x10($sp)
/* BB3A54 80240C54 0080802D */  daddu     $s0, $a0, $zero
/* BB3A58 80240C58 AFBF0014 */  sw        $ra, 0x14($sp)
/* BB3A5C 80240C5C 8E020148 */  lw        $v0, 0x148($s0)
/* BB3A60 80240C60 0C00EABB */  jal       get_npc_unsafe
/* BB3A64 80240C64 84440008 */   lh       $a0, 8($v0)
/* BB3A68 80240C68 9443008E */  lhu       $v1, 0x8e($v0)
/* BB3A6C 80240C6C 2463FFFF */  addiu     $v1, $v1, -1
/* BB3A70 80240C70 A443008E */  sh        $v1, 0x8e($v0)
/* BB3A74 80240C74 00031C00 */  sll       $v1, $v1, 0x10
/* BB3A78 80240C78 58600001 */  blezl     $v1, .L80240C80
/* BB3A7C 80240C7C AE000070 */   sw       $zero, 0x70($s0)
.L80240C80:
/* BB3A80 80240C80 8FBF0014 */  lw        $ra, 0x14($sp)
/* BB3A84 80240C84 8FB00010 */  lw        $s0, 0x10($sp)
/* BB3A88 80240C88 03E00008 */  jr        $ra
/* BB3A8C 80240C8C 27BD0018 */   addiu    $sp, $sp, 0x18
