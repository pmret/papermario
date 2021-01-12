.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00848E4
/* 3892B4 E00848E4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3892B8 E00848E8 3C02E008 */  lui       $v0, %hi(func_E0084928)
/* 3892BC E00848EC 24424928 */  addiu     $v0, $v0, %lo(func_E0084928)
/* 3892C0 E00848F0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3892C4 E00848F4 24020028 */  addiu     $v0, $zero, 0x28
/* 3892C8 E00848F8 AFA40018 */  sw        $a0, 0x18($sp)
/* 3892CC E00848FC 27A40010 */  addiu     $a0, $sp, 0x10
/* 3892D0 E0084900 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3892D4 E0084904 AFA00014 */  sw        $zero, 0x14($sp)
/* 3892D8 E0084908 0C080120 */  jal       func_E0200480
/* 3892DC E008490C AFA20010 */   sw       $v0, 0x10($sp)
/* 3892E0 E0084910 8C430000 */  lw        $v1, ($v0)
/* 3892E4 E0084914 34630002 */  ori       $v1, $v1, 2
/* 3892E8 E0084918 AC430000 */  sw        $v1, ($v0)
/* 3892EC E008491C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3892F0 E0084920 03E00008 */  jr        $ra
/* 3892F4 E0084924 27BD0028 */   addiu    $sp, $sp, 0x28
