.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414C4_844094
/* 844094 802414C4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 844098 802414C8 3C058024 */  lui       $a1, 0x8024
/* 84409C 802414CC 24A51458 */  addiu     $a1, $a1, 0x1458
/* 8440A0 802414D0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8440A4 802414D4 0C048C8F */  jal       bind_dynamic_entity_7
/* 8440A8 802414D8 0000202D */   daddu    $a0, $zero, $zero
/* 8440AC 802414DC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8440B0 802414E0 3C018025 */  lui       $at, 0x8025
/* 8440B4 802414E4 AC22F5A0 */  sw        $v0, -0xa60($at)
/* 8440B8 802414E8 24020002 */  addiu     $v0, $zero, 2
/* 8440BC 802414EC 03E00008 */  jr        $ra
/* 8440C0 802414F0 27BD0018 */   addiu    $sp, $sp, 0x18
