.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetCamLookAtObjVector
/* 01A798 8003F398 3C038007 */  lui   $v1, 0x8007
/* 01A79C 8003F39C 8C637410 */  lw    $v1, 0x7410($v1)
/* 01A7A0 8003F3A0 3C05800B */  lui   $a1, 0x800b
/* 01A7A4 8003F3A4 24A51D80 */  addiu $a1, $a1, 0x1d80
/* 01A7A8 8003F3A8 00031080 */  sll   $v0, $v1, 2
/* 01A7AC 8003F3AC 00431021 */  addu  $v0, $v0, $v1
/* 01A7B0 8003F3B0 00021080 */  sll   $v0, $v0, 2
/* 01A7B4 8003F3B4 00431023 */  subu  $v0, $v0, $v1
/* 01A7B8 8003F3B8 000218C0 */  sll   $v1, $v0, 3
/* 01A7BC 8003F3BC 00431021 */  addu  $v0, $v0, $v1
/* 01A7C0 8003F3C0 000210C0 */  sll   $v0, $v0, 3
/* 01A7C4 8003F3C4 00451021 */  addu  $v0, $v0, $a1
/* 01A7C8 8003F3C8 C4400048 */  lwc1  $f0, 0x48($v0)
/* 01A7CC 8003F3CC 4600008D */  trunc.w.s $f2, $f0
/* 01A7D0 8003F3D0 E4820084 */  swc1  $f2, 0x84($a0)
/* 01A7D4 8003F3D4 C440004C */  lwc1  $f0, 0x4c($v0)
/* 01A7D8 8003F3D8 4600008D */  trunc.w.s $f2, $f0
/* 01A7DC 8003F3DC E4820088 */  swc1  $f2, 0x88($a0)
/* 01A7E0 8003F3E0 C4400050 */  lwc1  $f0, 0x50($v0)
/* 01A7E4 8003F3E4 4600008D */  trunc.w.s $f2, $f0
/* 01A7E8 8003F3E8 E482008C */  swc1  $f2, 0x8c($a0)
/* 01A7EC 8003F3EC 03E00008 */  jr    $ra
/* 01A7F0 8003F3F0 24020002 */   addiu $v0, $zero, 2

