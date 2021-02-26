.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80043F24
/* 1F324 80043F24 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1F328 80043F28 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1F32C 80043F2C 8C82000C */  lw        $v0, 0xc($a0)
/* 1F330 80043F30 0C0B1EAF */  jal       func_802C7ABC
/* 1F334 80043F34 8C450000 */   lw       $a1, ($v0)
/* 1F338 80043F38 0C01CB7D */  jal       func_80072DF4
/* 1F33C 80043F3C 0040202D */   daddu    $a0, $v0, $zero
/* 1F340 80043F40 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1F344 80043F44 24020002 */  addiu     $v0, $zero, 2
/* 1F348 80043F48 03E00008 */  jr        $ra
/* 1F34C 80043F4C 27BD0018 */   addiu    $sp, $sp, 0x18
