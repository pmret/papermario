.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218FA0_649DB0
/* 649DB0 80218FA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 649DB4 80218FA4 AFB10014 */  sw        $s1, 0x14($sp)
/* 649DB8 80218FA8 0080882D */  daddu     $s1, $a0, $zero
/* 649DBC 80218FAC AFBF0018 */  sw        $ra, 0x18($sp)
/* 649DC0 80218FB0 AFB00010 */  sw        $s0, 0x10($sp)
/* 649DC4 80218FB4 8E30000C */  lw        $s0, 0xc($s1)
/* 649DC8 80218FB8 8E050000 */  lw        $a1, ($s0)
/* 649DCC 80218FBC 0C0B1EAF */  jal       get_variable
/* 649DD0 80218FC0 26100004 */   addiu    $s0, $s0, 4
/* 649DD4 80218FC4 0220202D */  daddu     $a0, $s1, $zero
/* 649DD8 80218FC8 8E050000 */  lw        $a1, ($s0)
/* 649DDC 80218FCC 0C0B1EAF */  jal       get_variable
/* 649DE0 80218FD0 0040802D */   daddu    $s0, $v0, $zero
/* 649DE4 80218FD4 0200202D */  daddu     $a0, $s0, $zero
/* 649DE8 80218FD8 0C00A3C2 */  jal       start_rumble
/* 649DEC 80218FDC 0040282D */   daddu    $a1, $v0, $zero
/* 649DF0 80218FE0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 649DF4 80218FE4 8FB10014 */  lw        $s1, 0x14($sp)
/* 649DF8 80218FE8 8FB00010 */  lw        $s0, 0x10($sp)
/* 649DFC 80218FEC 24020002 */  addiu     $v0, $zero, 2
/* 649E00 80218FF0 03E00008 */  jr        $ra
/* 649E04 80218FF4 27BD0020 */   addiu    $sp, $sp, 0x20
