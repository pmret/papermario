.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osFlashReadStatus
/* 04A4B8 8006F0B8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 04A4BC 8006F0BC AFBF0014 */  sw    $ra, 0x14($sp)
/* 04A4C0 8006F0C0 AFA40020 */  sw    $a0, 0x20($sp)
/* 04A4C4 8006F0C4 3C04800B */  lui   $a0, 0x800b
/* 04A4C8 8006F0C8 24840C70 */  addiu $a0, $a0, 0xc70
/* 04A4CC 8006F0CC 3C05800B */  lui   $a1, 0x800b
/* 04A4D0 8006F0D0 8CA50C7C */  lw    $a1, 0xc7c($a1)
/* 04A4D4 8006F0D4 3C010001 */  lui   $at, 1
/* 04A4D8 8006F0D8 00A17025 */  or    $t6, $a1, $at
/* 04A4DC 8006F0DC 01C02825 */  or    $a1, $t6, $zero
/* 04A4E0 8006F0E0 3C06D200 */  lui   $a2, 0xd200
/* 04A4E4 8006F0E4 0C018358 */  jal   osEPiWriteIo
/* 04A4E8 8006F0E8 00000000 */   nop   
/* 04A4EC 8006F0EC 3C04800B */  lui   $a0, 0x800b
/* 04A4F0 8006F0F0 24840C70 */  addiu $a0, $a0, 0xc70
/* 04A4F4 8006F0F4 3C05800B */  lui   $a1, 0x800b
/* 04A4F8 8006F0F8 8CA50C7C */  lw    $a1, 0xc7c($a1)
/* 04A4FC 8006F0FC 27A6001C */  addiu $a2, $sp, 0x1c
/* 04A500 8006F100 0C018370 */  jal   osEPiReadIo
/* 04A504 8006F104 00000000 */   nop   
/* 04A508 8006F108 3C04800B */  lui   $a0, 0x800b
/* 04A50C 8006F10C 24840C70 */  addiu $a0, $a0, 0xc70
/* 04A510 8006F110 3C05800B */  lui   $a1, 0x800b
/* 04A514 8006F114 8CA50C7C */  lw    $a1, 0xc7c($a1)
/* 04A518 8006F118 3C010001 */  lui   $at, 1
/* 04A51C 8006F11C 00A17825 */  or    $t7, $a1, $at
/* 04A520 8006F120 01E02825 */  or    $a1, $t7, $zero
/* 04A524 8006F124 3C06D200 */  lui   $a2, 0xd200
/* 04A528 8006F128 0C018358 */  jal   osEPiWriteIo
/* 04A52C 8006F12C 00000000 */   nop   
/* 04A530 8006F130 3C04800B */  lui   $a0, 0x800b
/* 04A534 8006F134 24840C70 */  addiu $a0, $a0, 0xc70
/* 04A538 8006F138 3C05800B */  lui   $a1, 0x800b
/* 04A53C 8006F13C 8CA50C7C */  lw    $a1, 0xc7c($a1)
/* 04A540 8006F140 27A6001C */  addiu $a2, $sp, 0x1c
/* 04A544 8006F144 0C018370 */  jal   osEPiReadIo
/* 04A548 8006F148 00000000 */   nop   
/* 04A54C 8006F14C 8FB8001C */  lw    $t8, 0x1c($sp)
/* 04A550 8006F150 00000000 */  nop   
/* 04A554 8006F154 331900FF */  andi  $t9, $t8, 0xff
/* 04A558 8006F158 8FA80020 */  lw    $t0, 0x20($sp)
/* 04A55C 8006F15C 00000000 */  nop   
/* 04A560 8006F160 A1190000 */  sb    $t9, ($t0)
/* 04A564 8006F164 10000003 */  b     .L8006F174
/* 04A568 8006F168 00000000 */   nop   
/* 04A56C 8006F16C 10000001 */  b     .L8006F174
/* 04A570 8006F170 00000000 */   nop   
.L8006F174:
/* 04A574 8006F174 8FBF0014 */  lw    $ra, 0x14($sp)
/* 04A578 8006F178 27BD0020 */  addiu $sp, $sp, 0x20
/* 04A57C 8006F17C 03E00008 */  jr    $ra
/* 04A580 8006F180 00000000 */   nop   

