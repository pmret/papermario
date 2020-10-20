.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240568_AF21C8
/* AF21C8 80240568 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF21CC 8024056C AFB00010 */  sw        $s0, 0x10($sp)
/* AF21D0 80240570 AFBF0014 */  sw        $ra, 0x14($sp)
/* AF21D4 80240574 0C039D88 */  jal       get_item_empty_count
/* AF21D8 80240578 0080802D */   daddu    $s0, $a0, $zero
/* AF21DC 8024057C AE020088 */  sw        $v0, 0x88($s0)
/* AF21E0 80240580 8FBF0014 */  lw        $ra, 0x14($sp)
/* AF21E4 80240584 8FB00010 */  lw        $s0, 0x10($sp)
/* AF21E8 80240588 24020002 */  addiu     $v0, $zero, 2
/* AF21EC 8024058C 03E00008 */  jr        $ra
/* AF21F0 80240590 27BD0018 */   addiu    $sp, $sp, 0x18
/* AF21F4 80240594 00000000 */  nop       
/* AF21F8 80240598 00000000 */  nop       
/* AF21FC 8024059C 00000000 */  nop       
