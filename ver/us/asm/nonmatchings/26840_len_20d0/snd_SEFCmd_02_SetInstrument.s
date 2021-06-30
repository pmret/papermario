.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_SEFCmd_02_SetInstrument
/* 282C4 8004CEC4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 282C8 8004CEC8 AFB00010 */  sw        $s0, 0x10($sp)
/* 282CC 8004CECC 00A0802D */  daddu     $s0, $a1, $zero
/* 282D0 8004CED0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 282D4 8004CED4 8E020000 */  lw        $v0, ($s0)
/* 282D8 8004CED8 90450000 */  lbu       $a1, ($v0)
/* 282DC 8004CEDC 90460001 */  lbu       $a2, 1($v0)
/* 282E0 8004CEE0 24420002 */  addiu     $v0, $v0, 2
/* 282E4 8004CEE4 AE020000 */  sw        $v0, ($s0)
/* 282E8 8004CEE8 A206009D */  sb        $a2, 0x9d($s0)
/* 282EC 8004CEEC 8C840000 */  lw        $a0, ($a0)
/* 282F0 8004CEF0 0C014EFA */  jal       func_80053BE8
/* 282F4 8004CEF4 26070010 */   addiu    $a3, $s0, 0x10
/* 282F8 8004CEF8 AE02001C */  sw        $v0, 0x1c($s0)
/* 282FC 8004CEFC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 28300 8004CF00 8FB00010 */  lw        $s0, 0x10($sp)
/* 28304 8004CF04 03E00008 */  jr        $ra
/* 28308 8004CF08 27BD0018 */   addiu    $sp, $sp, 0x18
