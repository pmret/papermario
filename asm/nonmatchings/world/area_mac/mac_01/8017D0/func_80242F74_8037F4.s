.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F74_8037F4
/* 8037F4 80242F74 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8037F8 80242F78 3C058024 */  lui       $a1, 0x8024
/* 8037FC 80242F7C 24A52F08 */  addiu     $a1, $a1, 0x2f08
/* 803800 80242F80 AFBF0010 */  sw        $ra, 0x10($sp)
/* 803804 80242F84 0C048C8F */  jal       bind_dynamic_entity_7
/* 803808 80242F88 0000202D */   daddu    $a0, $zero, $zero
/* 80380C 80242F8C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 803810 80242F90 3C018026 */  lui       $at, 0x8026
/* 803814 80242F94 AC222A40 */  sw        $v0, 0x2a40($at)
/* 803818 80242F98 24020002 */  addiu     $v0, $zero, 2
/* 80381C 80242F9C 03E00008 */  jr        $ra
/* 803820 80242FA0 27BD0018 */   addiu    $sp, $sp, 0x18
