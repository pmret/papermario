.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80147CC8
/* 0DE3C8 80147CC8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0DE3CC 80147CCC 0080582D */  daddu $t3, $a0, $zero
/* 0DE3D0 80147CD0 3C0A8016 */  lui   $t2, 0x8016
/* 0DE3D4 80147CD4 254A9D50 */  addiu $t2, $t2, -0x62b0
/* 0DE3D8 80147CD8 8FA90030 */  lw    $t1, 0x30($sp)
/* 0DE3DC 80147CDC 000B1140 */  sll   $v0, $t3, 5
/* 0DE3E0 80147CE0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0DE3E4 80147CE4 004A8021 */  addu  $s0, $v0, $t2
/* 0DE3E8 80147CE8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0DE3EC 80147CEC 8FB10034 */  lw    $s1, 0x34($sp)
/* 0DE3F0 80147CF0 8FA40038 */  lw    $a0, 0x38($sp)
/* 0DE3F4 80147CF4 8FA8003C */  lw    $t0, 0x3c($sp)
/* 0DE3F8 80147CF8 8FA30040 */  lw    $v1, 0x40($sp)
/* 0DE3FC 80147CFC 24020005 */  addiu $v0, $zero, 5
/* 0DE400 80147D00 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0DE404 80147D04 A2020000 */  sb    $v0, ($s0)
/* 0DE408 80147D08 A605000C */  sh    $a1, 0xc($s0)
/* 0DE40C 80147D0C A606000E */  sh    $a2, 0xe($s0)
/* 0DE410 80147D10 A6070010 */  sh    $a3, 0x10($s0)
/* 0DE414 80147D14 AE000004 */  sw    $zero, 4($s0)
/* 0DE418 80147D18 0220282D */  daddu $a1, $s1, $zero
/* 0DE41C 80147D1C A2030003 */  sb    $v1, 3($s0)
/* 0DE420 80147D20 00031E00 */  sll   $v1, $v1, 0x18
/* 0DE424 80147D24 00031E03 */  sra   $v1, $v1, 0x18
/* 0DE428 80147D28 A6090012 */  sh    $t1, 0x12($s0)
/* 0DE42C 80147D2C AE040014 */  sw    $a0, 0x14($s0)
/* 0DE430 80147D30 04600006 */  bltz  $v1, .L80147D4C
/* 0DE434 80147D34 AE080018 */   sw    $t0, 0x18($s0)
/* 0DE438 80147D38 00031940 */  sll   $v1, $v1, 5
/* 0DE43C 80147D3C 006A1821 */  addu  $v1, $v1, $t2
/* 0DE440 80147D40 90620000 */  lbu   $v0, ($v1)
/* 0DE444 80147D44 34420010 */  ori   $v0, $v0, 0x10
/* 0DE448 80147D48 A0620000 */  sb    $v0, ($v1)
.L80147D4C:
/* 0DE44C 80147D4C 0160202D */  daddu $a0, $t3, $zero
/* 0DE450 80147D50 0C051F5C */  jal   func_80147D70
/* 0DE454 80147D54 30A500FF */   andi  $a1, $a1, 0xff
/* 0DE458 80147D58 A2110002 */  sb    $s1, 2($s0)
/* 0DE45C 80147D5C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0DE460 80147D60 8FB10014 */  lw    $s1, 0x14($sp)
/* 0DE464 80147D64 8FB00010 */  lw    $s0, 0x10($sp)
/* 0DE468 80147D68 03E00008 */  jr    $ra
/* 0DE46C 80147D6C 27BD0020 */   addiu $sp, $sp, 0x20

