.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80282338
/* 7E31B8 80282338 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7E31BC 8028233C AFBF0014 */  sw        $ra, 0x14($sp)
/* 7E31C0 80282340 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E31C4 80282344 8C82000C */  lw        $v0, 0xc($a0)
/* 7E31C8 80282348 8C450000 */  lw        $a1, ($v0)
/* 7E31CC 8028234C 0C0B1EAF */  jal       get_variable
/* 7E31D0 80282350 8C900074 */   lw       $s0, 0x74($a0)
/* 7E31D4 80282354 AE020000 */  sw        $v0, ($s0)
/* 7E31D8 80282358 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7E31DC 8028235C 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E31E0 80282360 24020002 */  addiu     $v0, $zero, 2
/* 7E31E4 80282364 03E00008 */  jr        $ra
/* 7E31E8 80282368 27BD0018 */   addiu    $sp, $sp, 0x18
