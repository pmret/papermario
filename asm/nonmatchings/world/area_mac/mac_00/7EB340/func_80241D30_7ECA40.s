.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D30_7ECA40
/* 7ECA40 80241D30 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7ECA44 80241D34 AFB00010 */  sw        $s0, 0x10($sp)
/* 7ECA48 80241D38 0080802D */  daddu     $s0, $a0, $zero
/* 7ECA4C 80241D3C AFBF0014 */  sw        $ra, 0x14($sp)
/* 7ECA50 80241D40 0C00EABB */  jal       get_npc_unsafe
/* 7ECA54 80241D44 8E04008C */   lw       $a0, 0x8c($s0)
/* 7ECA58 80241D48 0040282D */  daddu     $a1, $v0, $zero
/* 7ECA5C 80241D4C 8E040094 */  lw        $a0, 0x94($s0)
/* 7ECA60 80241D50 8CA30028 */  lw        $v1, 0x28($a1)
/* 7ECA64 80241D54 ACA40028 */  sw        $a0, 0x28($a1)
/* 7ECA68 80241D58 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7ECA6C 80241D5C 8FB00010 */  lw        $s0, 0x10($sp)
/* 7ECA70 80241D60 24020002 */  addiu     $v0, $zero, 2
/* 7ECA74 80241D64 3C018025 */  lui       $at, 0x8025
/* 7ECA78 80241D68 AC235ED8 */  sw        $v1, 0x5ed8($at)
/* 7ECA7C 80241D6C 03E00008 */  jr        $ra
/* 7ECA80 80241D70 27BD0018 */   addiu    $sp, $sp, 0x18
