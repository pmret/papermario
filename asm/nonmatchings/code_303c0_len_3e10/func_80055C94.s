.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055C94
/* 31094 80055C94 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 31098 80055C98 240201F4 */  addiu     $v0, $zero, 0x1f4
/* 3109C 80055C9C AFA20014 */  sw        $v0, 0x14($sp)
/* 310A0 80055CA0 24027FFF */  addiu     $v0, $zero, 0x7fff
/* 310A4 80055CA4 AFA40010 */  sw        $a0, 0x10($sp)
/* 310A8 80055CA8 27A40010 */  addiu     $a0, $sp, 0x10
/* 310AC 80055CAC AFBF0030 */  sw        $ra, 0x30($sp)
/* 310B0 80055CB0 0C01383D */  jal       func_8004E0F4
/* 310B4 80055CB4 AFA2001C */   sw       $v0, 0x1c($sp)
/* 310B8 80055CB8 8FBF0030 */  lw        $ra, 0x30($sp)
/* 310BC 80055CBC 03E00008 */  jr        $ra
/* 310C0 80055CC0 27BD0038 */   addiu    $sp, $sp, 0x38
