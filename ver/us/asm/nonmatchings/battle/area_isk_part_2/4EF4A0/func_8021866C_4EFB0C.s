.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021866C_4EFB0C
/* 4EFB0C 8021866C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4EFB10 80218670 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4EFB14 80218674 8C82000C */  lw        $v0, 0xc($a0)
/* 4EFB18 80218678 0C0B1EAF */  jal       evt_get_variable
/* 4EFB1C 8021867C 8C450004 */   lw       $a1, 4($v0)
/* 4EFB20 80218680 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4EFB24 80218684 24020002 */  addiu     $v0, $zero, 2
/* 4EFB28 80218688 03E00008 */  jr        $ra
/* 4EFB2C 8021868C 27BD0018 */   addiu    $sp, $sp, 0x18
