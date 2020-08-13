.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80047CA4
/* 0230A4 80047CA4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0230A8 80047CA8 00041040 */  sll   $v0, $a0, 1
/* 0230AC 80047CAC 00441021 */  addu  $v0, $v0, $a0
/* 0230B0 80047CB0 00021080 */  sll   $v0, $v0, 2
/* 0230B4 80047CB4 00441023 */  subu  $v0, $v0, $a0
/* 0230B8 80047CB8 3C03800A */  lui   $v1, 0x800a
/* 0230BC 80047CBC 8C630F44 */  lw    $v1, 0xf44($v1)
/* 0230C0 80047CC0 00021100 */  sll   $v0, $v0, 4
/* 0230C4 80047CC4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0230C8 80047CC8 00621821 */  addu  $v1, $v1, $v0
/* 0230CC 80047CCC 80620078 */  lb    $v0, 0x78($v1)
/* 0230D0 80047CD0 10400008 */  beqz  $v0, .L80047CF4
/* 0230D4 80047CD4 24020001 */   addiu $v0, $zero, 1
/* 0230D8 80047CD8 8C64007C */  lw    $a0, 0x7c($v1)
/* 0230DC 80047CDC 3C058010 */  lui   $a1, 0x8010
/* 0230E0 80047CE0 24A5717C */  addiu $a1, $a1, 0x717c
/* 0230E4 80047CE4 A0600078 */  sb    $zero, 0x78($v1)
/* 0230E8 80047CE8 A0620079 */  sb    $v0, 0x79($v1)
/* 0230EC 80047CEC 0C0511FF */  jal   set_menu_icon_script
/* 0230F0 80047CF0 AC640080 */   sw    $a0, 0x80($v1)
.L80047CF4:
/* 0230F4 80047CF4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0230F8 80047CF8 03E00008 */  jr    $ra
/* 0230FC 80047CFC 27BD0018 */   addiu $sp, $sp, 0x18

