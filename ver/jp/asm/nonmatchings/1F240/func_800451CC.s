.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800451CC
/* 205CC 800451CC 8C82000C */  lw        $v0, 0xc($a0)
/* 205D0 800451D0 8C830148 */  lw        $v1, 0x148($a0)
/* 205D4 800451D4 8C420000 */  lw        $v0, ($v0)
/* 205D8 800451D8 AC620000 */  sw        $v0, ($v1)
/* 205DC 800451DC 03E00008 */  jr        $ra
/* 205E0 800451E0 24020002 */   addiu    $v0, $zero, 2
