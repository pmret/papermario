.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409E8_BD4258
/* BD4258 802409E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BD425C 802409EC AFBF0010 */  sw        $ra, 0x10($sp)
/* BD4260 802409F0 0C00EABB */  jal       get_npc_unsafe
/* BD4264 802409F4 24040001 */   addiu    $a0, $zero, 1
/* BD4268 802409F8 0C090248 */  jal       func_80240920_BD4190
/* BD426C 802409FC 0040202D */   daddu    $a0, $v0, $zero
/* BD4270 80240A00 0C00EABB */  jal       get_npc_unsafe
/* BD4274 80240A04 24040002 */   addiu    $a0, $zero, 2
/* BD4278 80240A08 0C090248 */  jal       func_80240920_BD4190
/* BD427C 80240A0C 0040202D */   daddu    $a0, $v0, $zero
/* BD4280 80240A10 0C00EABB */  jal       get_npc_unsafe
/* BD4284 80240A14 24040003 */   addiu    $a0, $zero, 3
/* BD4288 80240A18 0C090248 */  jal       func_80240920_BD4190
/* BD428C 80240A1C 0040202D */   daddu    $a0, $v0, $zero
/* BD4290 80240A20 0C00EABB */  jal       get_npc_unsafe
/* BD4294 80240A24 24040004 */   addiu    $a0, $zero, 4
/* BD4298 80240A28 0C090248 */  jal       func_80240920_BD4190
/* BD429C 80240A2C 0040202D */   daddu    $a0, $v0, $zero
/* BD42A0 80240A30 0C00EABB */  jal       get_npc_unsafe
/* BD42A4 80240A34 24040005 */   addiu    $a0, $zero, 5
/* BD42A8 80240A38 0C090248 */  jal       func_80240920_BD4190
/* BD42AC 80240A3C 0040202D */   daddu    $a0, $v0, $zero
/* BD42B0 80240A40 0C00EABB */  jal       get_npc_unsafe
/* BD42B4 80240A44 24040006 */   addiu    $a0, $zero, 6
/* BD42B8 80240A48 0C090248 */  jal       func_80240920_BD4190
/* BD42BC 80240A4C 0040202D */   daddu    $a0, $v0, $zero
/* BD42C0 80240A50 0C00EABB */  jal       get_npc_unsafe
/* BD42C4 80240A54 24040007 */   addiu    $a0, $zero, 7
/* BD42C8 80240A58 0C090248 */  jal       func_80240920_BD4190
/* BD42CC 80240A5C 0040202D */   daddu    $a0, $v0, $zero
/* BD42D0 80240A60 0C00EABB */  jal       get_npc_unsafe
/* BD42D4 80240A64 24040008 */   addiu    $a0, $zero, 8
/* BD42D8 80240A68 0C090248 */  jal       func_80240920_BD4190
/* BD42DC 80240A6C 0040202D */   daddu    $a0, $v0, $zero
/* BD42E0 80240A70 8FBF0010 */  lw        $ra, 0x10($sp)
/* BD42E4 80240A74 03E00008 */  jr        $ra
/* BD42E8 80240A78 27BD0018 */   addiu    $sp, $sp, 0x18
