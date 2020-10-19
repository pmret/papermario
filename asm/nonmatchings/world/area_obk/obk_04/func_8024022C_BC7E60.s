.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024022C_BC808C
/* BC808C 8024022C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BC8090 80240230 AFBF0010 */  sw        $ra, 0x10($sp)
/* BC8094 80240234 0C00EABB */  jal       get_npc_unsafe
/* BC8098 80240238 24040001 */   addiu    $a0, $zero, 1
/* BC809C 8024023C 24040002 */  addiu     $a0, $zero, 2
/* BC80A0 80240240 0C00EABB */  jal       get_npc_unsafe
/* BC80A4 80240244 A44000A2 */   sh       $zero, 0xa2($v0)
/* BC80A8 80240248 24040003 */  addiu     $a0, $zero, 3
/* BC80AC 8024024C 0C00EABB */  jal       get_npc_unsafe
/* BC80B0 80240250 A44000A2 */   sh       $zero, 0xa2($v0)
/* BC80B4 80240254 24040004 */  addiu     $a0, $zero, 4
/* BC80B8 80240258 0C00EABB */  jal       get_npc_unsafe
/* BC80BC 8024025C A44000A2 */   sh       $zero, 0xa2($v0)
/* BC80C0 80240260 24040005 */  addiu     $a0, $zero, 5
/* BC80C4 80240264 0C00EABB */  jal       get_npc_unsafe
/* BC80C8 80240268 A44000A2 */   sh       $zero, 0xa2($v0)
/* BC80CC 8024026C 24040006 */  addiu     $a0, $zero, 6
/* BC80D0 80240270 0C00EABB */  jal       get_npc_unsafe
/* BC80D4 80240274 A44000A2 */   sh       $zero, 0xa2($v0)
/* BC80D8 80240278 24040007 */  addiu     $a0, $zero, 7
/* BC80DC 8024027C 0C00EABB */  jal       get_npc_unsafe
/* BC80E0 80240280 A44000A2 */   sh       $zero, 0xa2($v0)
/* BC80E4 80240284 24040008 */  addiu     $a0, $zero, 8
/* BC80E8 80240288 0C00EABB */  jal       get_npc_unsafe
/* BC80EC 8024028C A44000A2 */   sh       $zero, 0xa2($v0)
/* BC80F0 80240290 A44000A2 */  sh        $zero, 0xa2($v0)
/* BC80F4 80240294 8FBF0010 */  lw        $ra, 0x10($sp)
/* BC80F8 80240298 03E00008 */  jr        $ra
/* BC80FC 8024029C 27BD0018 */   addiu    $sp, $sp, 0x18
