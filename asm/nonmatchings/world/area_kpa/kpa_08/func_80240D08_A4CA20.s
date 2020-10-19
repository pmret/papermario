.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D08_A4D728
/* A4D728 80240D08 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A4D72C 80240D0C AFB00010 */  sw        $s0, 0x10($sp)
/* A4D730 80240D10 0080802D */  daddu     $s0, $a0, $zero
/* A4D734 80240D14 AFBF0014 */  sw        $ra, 0x14($sp)
/* A4D738 80240D18 8E020148 */  lw        $v0, 0x148($s0)
/* A4D73C 80240D1C 0C00EABB */  jal       get_npc_unsafe
/* A4D740 80240D20 84440008 */   lh       $a0, 8($v0)
/* A4D744 80240D24 24030028 */  addiu     $v1, $zero, 0x28
/* A4D748 80240D28 A443008E */  sh        $v1, 0x8e($v0)
/* A4D74C 80240D2C 24020015 */  addiu     $v0, $zero, 0x15
/* A4D750 80240D30 AE020070 */  sw        $v0, 0x70($s0)
/* A4D754 80240D34 8FBF0014 */  lw        $ra, 0x14($sp)
/* A4D758 80240D38 8FB00010 */  lw        $s0, 0x10($sp)
/* A4D75C 80240D3C 03E00008 */  jr        $ra
/* A4D760 80240D40 27BD0018 */   addiu    $sp, $sp, 0x18
