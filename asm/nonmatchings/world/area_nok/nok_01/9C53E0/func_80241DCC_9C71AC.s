.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DCC_9C71AC
/* 9C71AC 80241DCC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C71B0 80241DD0 3C058024 */  lui       $a1, 0x8024
/* 9C71B4 80241DD4 24A51D60 */  addiu     $a1, $a1, 0x1d60
/* 9C71B8 80241DD8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C71BC 80241DDC 0C048C8F */  jal       bind_dynamic_entity_7
/* 9C71C0 80241DE0 0000202D */   daddu    $a0, $zero, $zero
/* 9C71C4 80241DE4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C71C8 80241DE8 3C018025 */  lui       $at, 0x8025
/* 9C71CC 80241DEC AC221C40 */  sw        $v0, 0x1c40($at)
/* 9C71D0 80241DF0 24020002 */  addiu     $v0, $zero, 2
/* 9C71D4 80241DF4 03E00008 */  jr        $ra
/* 9C71D8 80241DF8 27BD0018 */   addiu    $sp, $sp, 0x18
