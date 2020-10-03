.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E46BC
/* 105F3C 802E46BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 105F40 802E46C0 AFB00010 */  sw        $s0, 0x10($sp)
/* 105F44 802E46C4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 105F48 802E46C8 0C0B8DB9 */  jal       entity_init_Hammer23Block_normal
/* 105F4C 802E46CC 0080802D */   daddu    $s0, $a0, $zero
/* 105F50 802E46D0 86040014 */  lh        $a0, 0x14($s0)
/* 105F54 802E46D4 3C02802E */  lui       $v0, 0x802e
/* 105F58 802E46D8 2442455C */  addiu     $v0, $v0, 0x455c
/* 105F5C 802E46DC 0C047FF8 */  jal       func_8011FFE0
/* 105F60 802E46E0 AE02003C */   sw       $v0, 0x3c($s0)
/* 105F64 802E46E4 24030011 */  addiu     $v1, $zero, 0x11
/* 105F68 802E46E8 A0430004 */  sb        $v1, 4($v0)
/* 105F6C 802E46EC 8C430000 */  lw        $v1, ($v0)
/* 105F70 802E46F0 3C040001 */  lui       $a0, 1
/* 105F74 802E46F4 00641825 */  or        $v1, $v1, $a0
/* 105F78 802E46F8 AC430000 */  sw        $v1, ($v0)
/* 105F7C 802E46FC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 105F80 802E4700 8FB00010 */  lw        $s0, 0x10($sp)
/* 105F84 802E4704 03E00008 */  jr        $ra
/* 105F88 802E4708 27BD0018 */   addiu    $sp, $sp, 0x18
/* 105F8C 802E470C 00000000 */  nop       
