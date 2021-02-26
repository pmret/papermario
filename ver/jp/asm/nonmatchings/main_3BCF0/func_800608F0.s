.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800608F0
/* 3BCF0 800608F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3BCF4 800608F4 24040103 */  addiu     $a0, $zero, 0x103
/* 3BCF8 800608F8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3BCFC 800608FC 0C0180B2 */  jal       func_800602C8
/* 3BD00 80060900 0000282D */   daddu    $a1, $zero, $zero
/* 3BD04 80060904 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3BD08 80060908 03E00008 */  jr        $ra
/* 3BD0C 8006090C 27BD0018 */   addiu    $sp, $sp, 0x18
