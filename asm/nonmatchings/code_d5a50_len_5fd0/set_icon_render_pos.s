.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel set_icon_render_pos
/* 0DB084 80144984 2402F7FF */  addiu $v0, $zero, -0x801
/* 0DB088 80144988 00822024 */  and   $a0, $a0, $v0
/* 0DB08C 8014498C 3C028015 */  lui   $v0, 0x8015
/* 0DB090 80144990 8C427960 */  lw    $v0, 0x7960($v0)
/* 0DB094 80144994 00042080 */  sll   $a0, $a0, 2
/* 0DB098 80144998 00822021 */  addu  $a0, $a0, $v0
/* 0DB09C 8014499C 8C820000 */  lw    $v0, ($a0)
/* 0DB0A0 801449A0 A445003C */  sh    $a1, 0x3c($v0)
/* 0DB0A4 801449A4 03E00008 */  jr    $ra
/* 0DB0A8 801449A8 A446003E */   sh    $a2, 0x3e($v0)

