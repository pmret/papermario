.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002C194
/* 7594 8002C194 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7598 8002C198 AFB10014 */  sw        $s1, 0x14($sp)
/* 759C 8002C19C 0080882D */  daddu     $s1, $a0, $zero
/* 75A0 8002C1A0 AFB00010 */  sw        $s0, 0x10($sp)
/* 75A4 8002C1A4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 75A8 8002C1A8 0C019291 */  jal       func_80064A44
/* 75AC 8002C1AC 00C0802D */   daddu    $s0, $a2, $zero
/* 75B0 8002C1B0 02301021 */  addu      $v0, $s1, $s0
/* 75B4 8002C1B4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 75B8 8002C1B8 8FB10014 */  lw        $s1, 0x14($sp)
/* 75BC 8002C1BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 75C0 8002C1C0 03E00008 */  jr        $ra
/* 75C4 8002C1C4 27BD0020 */   addiu    $sp, $sp, 0x20
