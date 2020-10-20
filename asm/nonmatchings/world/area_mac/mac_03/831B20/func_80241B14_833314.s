.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B14_833314
/* 833314 80241B14 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 833318 80241B18 AFB00010 */  sw        $s0, 0x10($sp)
/* 83331C 80241B1C 0080802D */  daddu     $s0, $a0, $zero
/* 833320 80241B20 AFBF0014 */  sw        $ra, 0x14($sp)
/* 833324 80241B24 0C00EABB */  jal       get_npc_unsafe
/* 833328 80241B28 8E04008C */   lw       $a0, 0x8c($s0)
/* 83332C 80241B2C 0040282D */  daddu     $a1, $v0, $zero
/* 833330 80241B30 8E040094 */  lw        $a0, 0x94($s0)
/* 833334 80241B34 8CA30028 */  lw        $v1, 0x28($a1)
/* 833338 80241B38 ACA40028 */  sw        $a0, 0x28($a1)
/* 83333C 80241B3C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 833340 80241B40 8FB00010 */  lw        $s0, 0x10($sp)
/* 833344 80241B44 24020002 */  addiu     $v0, $zero, 2
/* 833348 80241B48 3C018025 */  lui       $at, 0x8025
/* 83334C 80241B4C AC2315C4 */  sw        $v1, 0x15c4($at)
/* 833350 80241B50 03E00008 */  jr        $ra
/* 833354 80241B54 27BD0018 */   addiu    $sp, $sp, 0x18
