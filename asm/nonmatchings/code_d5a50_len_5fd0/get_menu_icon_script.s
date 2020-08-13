.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel get_menu_icon_script
/* 0DAFB0 801448B0 2402F7FF */  addiu $v0, $zero, -0x801
/* 0DAFB4 801448B4 00822024 */  and   $a0, $a0, $v0
/* 0DAFB8 801448B8 3C028015 */  lui   $v0, 0x8015
/* 0DAFBC 801448BC 8C427960 */  lw    $v0, 0x7960($v0)
/* 0DAFC0 801448C0 00042080 */  sll   $a0, $a0, 2
/* 0DAFC4 801448C4 00822021 */  addu  $a0, $a0, $v0
/* 0DAFC8 801448C8 8C820000 */  lw    $v0, ($a0)
/* 0DAFCC 801448CC 03E00008 */  jr    $ra
/* 0DAFD0 801448D0 8C420008 */   lw    $v0, 8($v0)

