.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_8EB360
/* 8EB360 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8EB364 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* 8EB368 80240008 0080802D */  daddu     $s0, $a0, $zero
/* 8EB36C 8024000C AFBF0014 */  sw        $ra, 0x14($sp)
/* 8EB370 80240010 0C00FB5A */  jal       get_enemy_safe
/* 8EB374 80240014 0000202D */   daddu    $a0, $zero, $zero
/* 8EB378 80240018 AE020084 */  sw        $v0, 0x84($s0)
/* 8EB37C 8024001C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8EB380 80240020 8FB00010 */  lw        $s0, 0x10($sp)
/* 8EB384 80240024 24020002 */  addiu     $v0, $zero, 2
/* 8EB388 80240028 03E00008 */  jr        $ra
/* 8EB38C 8024002C 27BD0018 */   addiu    $sp, $sp, 0x18
