.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218DF8_48DF98
/* 48DF98 80218DF8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 48DF9C 80218DFC AFBF0010 */  sw        $ra, 0x10($sp)
/* 48DFA0 80218E00 8C82000C */  lw        $v0, 0xc($a0)
/* 48DFA4 80218E04 0C0B1EAF */  jal       evt_get_variable
/* 48DFA8 80218E08 8C450004 */   lw       $a1, 4($v0)
/* 48DFAC 80218E0C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 48DFB0 80218E10 24020002 */  addiu     $v0, $zero, 2
/* 48DFB4 80218E14 03E00008 */  jr        $ra
/* 48DFB8 80218E18 27BD0018 */   addiu    $sp, $sp, 0x18
/* 48DFBC 80218E1C 00000000 */  nop
