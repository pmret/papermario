.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_menu_icon
/* 0DAFD4 801448D4 2402F7FF */  addiu $v0, $zero, -0x801
/* 0DAFD8 801448D8 00822024 */  and   $a0, $a0, $v0
/* 0DAFDC 801448DC 3C028015 */  lui   $v0, 0x8015
/* 0DAFE0 801448E0 8C427960 */  lw    $v0, 0x7960($v0)
/* 0DAFE4 801448E4 00042080 */  sll   $a0, $a0, 2
/* 0DAFE8 801448E8 00822021 */  addu  $a0, $a0, $v0
/* 0DAFEC 801448EC 03E00008 */  jr    $ra
/* 0DAFF0 801448F0 8C820000 */   lw    $v0, ($a0)

