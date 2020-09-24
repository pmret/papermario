.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800561A4
/* 315A4 800561A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 315A8 800561A8 0080282D */  daddu     $a1, $a0, $zero
/* 315AC 800561AC AFBF0010 */  sw        $ra, 0x10($sp)
/* 315B0 800561B0 0C015338 */  jal       func_80054CE0
/* 315B4 800561B4 24040001 */   addiu    $a0, $zero, 1
/* 315B8 800561B8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 315BC 800561BC 03E00008 */  jr        $ra
/* 315C0 800561C0 27BD0018 */   addiu    $sp, $sp, 0x18
