.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E3898
/* 105118 802E3898 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10511C 802E389C AFB00010 */  sw        $s0, 0x10($sp)
/* 105120 802E38A0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 105124 802E38A4 0C0B8DB9 */  jal       entity_init_Hammer23Block_normal
/* 105128 802E38A8 0080802D */   daddu    $s0, $a0, $zero
/* 10512C 802E38AC 8E030040 */  lw        $v1, 0x40($s0)
/* 105130 802E38B0 2402000A */  addiu     $v0, $zero, 0xa
/* 105134 802E38B4 A4620004 */  sh        $v0, 4($v1)
/* 105138 802E38B8 2402007B */  addiu     $v0, $zero, 0x7b
/* 10513C 802E38BC A4620006 */  sh        $v0, 6($v1)
/* 105140 802E38C0 3402FFFF */  ori       $v0, $zero, 0xffff
/* 105144 802E38C4 A462000A */  sh        $v0, 0xa($v1)
/* 105148 802E38C8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 10514C 802E38CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 105150 802E38D0 03E00008 */  jr        $ra
/* 105154 802E38D4 27BD0018 */   addiu    $sp, $sp, 0x18
