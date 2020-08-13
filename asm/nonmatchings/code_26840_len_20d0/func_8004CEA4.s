.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8004CEA4
/* 0282A4 8004CEA4 8CA20000 */  lw    $v0, ($a1)
/* 0282A8 8004CEA8 90430000 */  lbu   $v1, ($v0)
/* 0282AC 8004CEAC 24420001 */  addiu $v0, $v0, 1
/* 0282B0 8004CEB0 ACA20000 */  sw    $v0, ($a1)
/* 0282B4 8004CEB4 24020001 */  addiu $v0, $zero, 1
/* 0282B8 8004CEB8 A0A20056 */  sb    $v0, 0x56($a1)
/* 0282BC 8004CEBC 03E00008 */  jr    $ra
/* 0282C0 8004CEC0 A0A3009B */   sb    $v1, 0x9b($a1)

