.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CB8_A64D48
/* A64D48 80240CB8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A64D4C 80240CBC AFB00010 */  sw        $s0, 0x10($sp)
/* A64D50 80240CC0 0080802D */  daddu     $s0, $a0, $zero
/* A64D54 80240CC4 AFBF0014 */  sw        $ra, 0x14($sp)
/* A64D58 80240CC8 8E020148 */  lw        $v0, 0x148($s0)
/* A64D5C 80240CCC 0C00EABB */  jal       get_npc_unsafe
/* A64D60 80240CD0 84440008 */   lh       $a0, 8($v0)
/* A64D64 80240CD4 24030028 */  addiu     $v1, $zero, 0x28
/* A64D68 80240CD8 A443008E */  sh        $v1, 0x8e($v0)
/* A64D6C 80240CDC 24020015 */  addiu     $v0, $zero, 0x15
/* A64D70 80240CE0 AE020070 */  sw        $v0, 0x70($s0)
/* A64D74 80240CE4 8FBF0014 */  lw        $ra, 0x14($sp)
/* A64D78 80240CE8 8FB00010 */  lw        $s0, 0x10($sp)
/* A64D7C 80240CEC 03E00008 */  jr        $ra
/* A64D80 80240CF0 27BD0018 */   addiu    $sp, $sp, 0x18
