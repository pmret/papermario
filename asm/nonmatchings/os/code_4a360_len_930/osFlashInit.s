.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osFlashInit
/* 04A368 8006EF68 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 04A36C 8006EF6C AFBF0014 */  sw    $ra, 0x14($sp)
/* 04A370 8006EF70 3C04800B */  lui   $a0, 0x800b
/* 04A374 8006EF74 24840C58 */  addiu $a0, $a0, 0xc58
/* 04A378 8006EF78 3C05800B */  lui   $a1, 0x800b
/* 04A37C 8006EF7C 24A50CE4 */  addiu $a1, $a1, 0xce4
/* 04A380 8006EF80 24060001 */  addiu $a2, $zero, 1
/* 04A384 8006EF84 0C019560 */  jal   osCreateMesgQueue
/* 04A388 8006EF88 00000000 */   nop   
/* 04A38C 8006EF8C 3C0E800B */  lui   $t6, 0x800b
/* 04A390 8006EF90 8DCE0C7C */  lw    $t6, 0xc7c($t6)
/* 04A394 8006EF94 3C01A800 */  lui   $at, 0xa800
/* 04A398 8006EF98 15C10005 */  bne   $t6, $at, .L8006EFB0
/* 04A39C 8006EF9C 00000000 */   nop   
/* 04A3A0 8006EFA0 3C02800B */  lui   $v0, 0x800b
/* 04A3A4 8006EFA4 24420C70 */  addiu $v0, $v0, 0xc70
/* 04A3A8 8006EFA8 1000003F */  b     .L8006F0A8
/* 04A3AC 8006EFAC 00000000 */   nop   
.L8006EFB0:
/* 04A3B0 8006EFB0 240F0008 */  addiu $t7, $zero, 8
/* 04A3B4 8006EFB4 3C01800B */  lui   $at, 0x800b
/* 04A3B8 8006EFB8 A02F0C74 */  sb    $t7, 0xc74($at)
/* 04A3BC 8006EFBC 3C18A800 */  lui   $t8, 0xa800
/* 04A3C0 8006EFC0 3C01800B */  lui   $at, 0x800b
/* 04A3C4 8006EFC4 AC380C7C */  sw    $t8, 0xc7c($at)
/* 04A3C8 8006EFC8 24190005 */  addiu $t9, $zero, 5
/* 04A3CC 8006EFCC 3C01800B */  lui   $at, 0x800b
/* 04A3D0 8006EFD0 A0390C75 */  sb    $t9, 0xc75($at)
/* 04A3D4 8006EFD4 2408000C */  addiu $t0, $zero, 0xc
/* 04A3D8 8006EFD8 3C01800B */  lui   $at, 0x800b
/* 04A3DC 8006EFDC A0280C78 */  sb    $t0, 0xc78($at)
/* 04A3E0 8006EFE0 2409000F */  addiu $t1, $zero, 0xf
/* 04A3E4 8006EFE4 3C01800B */  lui   $at, 0x800b
/* 04A3E8 8006EFE8 A0290C76 */  sb    $t1, 0xc76($at)
/* 04A3EC 8006EFEC 240A0002 */  addiu $t2, $zero, 2
/* 04A3F0 8006EFF0 3C01800B */  lui   $at, 0x800b
/* 04A3F4 8006EFF4 A02A0C77 */  sb    $t2, 0xc77($at)
/* 04A3F8 8006EFF8 240B0001 */  addiu $t3, $zero, 1
/* 04A3FC 8006EFFC 3C01800B */  lui   $at, 0x800b
/* 04A400 8006F000 A02B0C79 */  sb    $t3, 0xc79($at)
/* 04A404 8006F004 3C01800B */  lui   $at, 0x800b
/* 04A408 8006F008 AC200C80 */  sw    $zero, 0xc80($at)
/* 04A40C 8006F00C 3C04800B */  lui   $a0, 0x800b
/* 04A410 8006F010 24840C70 */  addiu $a0, $a0, 0xc70
/* 04A414 8006F014 24840014 */  addiu $a0, $a0, 0x14
/* 04A418 8006F018 24050060 */  addiu $a1, $zero, 0x60
/* 04A41C 8006F01C 0C01925C */  jal   bzero
/* 04A420 8006F020 00000000 */   nop   
/* 04A424 8006F024 3C04800B */  lui   $a0, 0x800b
/* 04A428 8006F028 24840C70 */  addiu $a0, $a0, 0xc70
/* 04A42C 8006F02C 0C0183B0 */  jal   osEPiLinkHandle
/* 04A430 8006F030 00000000 */   nop   
/* 04A434 8006F034 27A4001C */  addiu $a0, $sp, 0x1c
/* 04A438 8006F038 27A50018 */  addiu $a1, $sp, 0x18
/* 04A43C 8006F03C 0C01BC61 */  jal   osFlashReadId
/* 04A440 8006F040 00000000 */   nop   
/* 04A444 8006F044 8FAC0018 */  lw    $t4, 0x18($sp)
/* 04A448 8006F048 3C0100C2 */  lui   $at, 0xc2
/* 04A44C 8006F04C 3421001E */  ori   $at, $at, 0x1e
/* 04A450 8006F050 11810008 */  beq   $t4, $at, .L8006F074
/* 04A454 8006F054 00000000 */   nop   
/* 04A458 8006F058 3C0100C2 */  lui   $at, 0xc2
/* 04A45C 8006F05C 34210001 */  ori   $at, $at, 1
/* 04A460 8006F060 11810004 */  beq   $t4, $at, .L8006F074
/* 04A464 8006F064 00000000 */   nop   
/* 04A468 8006F068 3C0100C2 */  lui   $at, 0xc2
/* 04A46C 8006F06C 15810005 */  bne   $t4, $at, .L8006F084
/* 04A470 8006F070 00000000 */   nop   
.L8006F074:
/* 04A474 8006F074 3C01800B */  lui   $at, 0x800b
/* 04A478 8006F078 AC200CE8 */  sw    $zero, 0xce8($at)
/* 04A47C 8006F07C 10000004 */  b     .L8006F090
/* 04A480 8006F080 00000000 */   nop   
.L8006F084:
/* 04A484 8006F084 240D0001 */  addiu $t5, $zero, 1
/* 04A488 8006F088 3C01800B */  lui   $at, 0x800b
/* 04A48C 8006F08C AC2D0CE8 */  sw    $t5, 0xce8($at)
.L8006F090:
/* 04A490 8006F090 3C02800B */  lui   $v0, 0x800b
/* 04A494 8006F094 24420C70 */  addiu $v0, $v0, 0xc70
/* 04A498 8006F098 10000003 */  b     .L8006F0A8
/* 04A49C 8006F09C 00000000 */   nop   
/* 04A4A0 8006F0A0 10000001 */  b     .L8006F0A8
/* 04A4A4 8006F0A4 00000000 */   nop   
.L8006F0A8:
/* 04A4A8 8006F0A8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 04A4AC 8006F0AC 27BD0020 */  addiu $sp, $sp, 0x20
/* 04A4B0 8006F0B0 03E00008 */  jr    $ra
/* 04A4B4 8006F0B4 00000000 */   nop   

