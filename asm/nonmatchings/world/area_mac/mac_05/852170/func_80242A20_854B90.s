.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A20_854B90
/* 854B90 80242A20 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 854B94 80242A24 AFB00010 */  sw        $s0, 0x10($sp)
/* 854B98 80242A28 0080802D */  daddu     $s0, $a0, $zero
/* 854B9C 80242A2C AFBF0014 */  sw        $ra, 0x14($sp)
/* 854BA0 80242A30 0C00EABB */  jal       get_npc_unsafe
/* 854BA4 80242A34 8E04008C */   lw       $a0, 0x8c($s0)
/* 854BA8 80242A38 0040282D */  daddu     $a1, $v0, $zero
/* 854BAC 80242A3C 8E040094 */  lw        $a0, 0x94($s0)
/* 854BB0 80242A40 8CA30028 */  lw        $v1, 0x28($a1)
/* 854BB4 80242A44 ACA40028 */  sw        $a0, 0x28($a1)
/* 854BB8 80242A48 8FBF0014 */  lw        $ra, 0x14($sp)
/* 854BBC 80242A4C 8FB00010 */  lw        $s0, 0x10($sp)
/* 854BC0 80242A50 24020002 */  addiu     $v0, $zero, 2
/* 854BC4 80242A54 3C018025 */  lui       $at, 0x8025
/* 854BC8 80242A58 AC232D38 */  sw        $v1, 0x2d38($at)
/* 854BCC 80242A5C 03E00008 */  jr        $ra
/* 854BD0 80242A60 27BD0018 */   addiu    $sp, $sp, 0x18
