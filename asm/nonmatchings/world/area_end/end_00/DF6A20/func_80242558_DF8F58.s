.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242558_DF8F58
/* DF8F58 80242558 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DF8F5C 8024255C AFBF0010 */  sw        $ra, 0x10($sp)
/* DF8F60 80242560 0C090940 */  jal       func_80242500_DF8F00
/* DF8F64 80242564 00000000 */   nop      
/* DF8F68 80242568 0C048DCD */  jal       load_font
/* DF8F6C 8024256C 24040001 */   addiu    $a0, $zero, 1
/* DF8F70 80242570 8FBF0010 */  lw        $ra, 0x10($sp)
/* DF8F74 80242574 24020002 */  addiu     $v0, $zero, 2
/* DF8F78 80242578 03E00008 */  jr        $ra
/* DF8F7C 8024257C 27BD0018 */   addiu    $sp, $sp, 0x18
