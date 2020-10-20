.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A7C_BD42EC
/* BD42EC 80240A7C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BD42F0 80240A80 AFBF0010 */  sw        $ra, 0x10($sp)
/* BD42F4 80240A84 0C00EABB */  jal       get_npc_unsafe
/* BD42F8 80240A88 24040001 */   addiu    $a0, $zero, 1
/* BD42FC 80240A8C 24040002 */  addiu     $a0, $zero, 2
/* BD4300 80240A90 0C00EABB */  jal       get_npc_unsafe
/* BD4304 80240A94 A44000A2 */   sh       $zero, 0xa2($v0)
/* BD4308 80240A98 24040003 */  addiu     $a0, $zero, 3
/* BD430C 80240A9C 0C00EABB */  jal       get_npc_unsafe
/* BD4310 80240AA0 A44000A2 */   sh       $zero, 0xa2($v0)
/* BD4314 80240AA4 24040004 */  addiu     $a0, $zero, 4
/* BD4318 80240AA8 0C00EABB */  jal       get_npc_unsafe
/* BD431C 80240AAC A44000A2 */   sh       $zero, 0xa2($v0)
/* BD4320 80240AB0 24040005 */  addiu     $a0, $zero, 5
/* BD4324 80240AB4 0C00EABB */  jal       get_npc_unsafe
/* BD4328 80240AB8 A44000A2 */   sh       $zero, 0xa2($v0)
/* BD432C 80240ABC 24040006 */  addiu     $a0, $zero, 6
/* BD4330 80240AC0 0C00EABB */  jal       get_npc_unsafe
/* BD4334 80240AC4 A44000A2 */   sh       $zero, 0xa2($v0)
/* BD4338 80240AC8 24040007 */  addiu     $a0, $zero, 7
/* BD433C 80240ACC 0C00EABB */  jal       get_npc_unsafe
/* BD4340 80240AD0 A44000A2 */   sh       $zero, 0xa2($v0)
/* BD4344 80240AD4 24040008 */  addiu     $a0, $zero, 8
/* BD4348 80240AD8 0C00EABB */  jal       get_npc_unsafe
/* BD434C 80240ADC A44000A2 */   sh       $zero, 0xa2($v0)
/* BD4350 80240AE0 A44000A2 */  sh        $zero, 0xa2($v0)
/* BD4354 80240AE4 8FBF0010 */  lw        $ra, 0x10($sp)
/* BD4358 80240AE8 03E00008 */  jr        $ra
/* BD435C 80240AEC 27BD0018 */   addiu    $sp, $sp, 0x18
