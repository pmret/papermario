.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006EF48
/* 4A348 8006EF48 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4A34C 8006EF4C AFBF0014 */  sw        $ra, 0x14($sp)
/* 4A350 8006EF50 3C04800B */  lui       $a0, %hi(D_800B0C38)
/* 4A354 8006EF54 24840C38 */  addiu     $a0, $a0, %lo(D_800B0C38)
/* 4A358 8006EF58 3C05800B */  lui       $a1, %hi(D_800B0CC4)
/* 4A35C 8006EF5C 24A50CC4 */  addiu     $a1, $a1, %lo(D_800B0CC4)
/* 4A360 8006EF60 24060001 */  addiu     $a2, $zero, 1
/* 4A364 8006EF64 0C019554 */  jal       func_80065550
/* 4A368 8006EF68 00000000 */   nop
/* 4A36C 8006EF6C 3C0E800B */  lui       $t6, %hi(D_800B0C5C)
/* 4A370 8006EF70 8DCE0C5C */  lw        $t6, %lo(D_800B0C5C)($t6)
/* 4A374 8006EF74 3C01A800 */  lui       $at, 0xa800
/* 4A378 8006EF78 15C10005 */  bne       $t6, $at, .L8006EF90
/* 4A37C 8006EF7C 00000000 */   nop
/* 4A380 8006EF80 3C02800B */  lui       $v0, %hi(D_800B0C50)
/* 4A384 8006EF84 24420C50 */  addiu     $v0, $v0, %lo(D_800B0C50)
/* 4A388 8006EF88 1000003F */  b         .L8006F088
/* 4A38C 8006EF8C 00000000 */   nop
.L8006EF90:
/* 4A390 8006EF90 240F0008 */  addiu     $t7, $zero, 8
/* 4A394 8006EF94 3C01800B */  lui       $at, %hi(D_800B0C54)
/* 4A398 8006EF98 A02F0C54 */  sb        $t7, %lo(D_800B0C54)($at)
/* 4A39C 8006EF9C 3C18A800 */  lui       $t8, 0xa800
/* 4A3A0 8006EFA0 3C01800B */  lui       $at, %hi(D_800B0C5C)
/* 4A3A4 8006EFA4 AC380C5C */  sw        $t8, %lo(D_800B0C5C)($at)
/* 4A3A8 8006EFA8 24190005 */  addiu     $t9, $zero, 5
/* 4A3AC 8006EFAC 3C01800B */  lui       $at, %hi(D_800B0C55)
/* 4A3B0 8006EFB0 A0390C55 */  sb        $t9, %lo(D_800B0C55)($at)
/* 4A3B4 8006EFB4 2408000C */  addiu     $t0, $zero, 0xc
/* 4A3B8 8006EFB8 3C01800B */  lui       $at, %hi(D_800B0C58)
/* 4A3BC 8006EFBC A0280C58 */  sb        $t0, %lo(D_800B0C58)($at)
/* 4A3C0 8006EFC0 2409000F */  addiu     $t1, $zero, 0xf
/* 4A3C4 8006EFC4 3C01800B */  lui       $at, %hi(D_800B0C56)
/* 4A3C8 8006EFC8 A0290C56 */  sb        $t1, %lo(D_800B0C56)($at)
/* 4A3CC 8006EFCC 240A0002 */  addiu     $t2, $zero, 2
/* 4A3D0 8006EFD0 3C01800B */  lui       $at, %hi(D_800B0C57)
/* 4A3D4 8006EFD4 A02A0C57 */  sb        $t2, %lo(D_800B0C57)($at)
/* 4A3D8 8006EFD8 240B0001 */  addiu     $t3, $zero, 1
/* 4A3DC 8006EFDC 3C01800B */  lui       $at, %hi(D_800B0C59)
/* 4A3E0 8006EFE0 A02B0C59 */  sb        $t3, %lo(D_800B0C59)($at)
/* 4A3E4 8006EFE4 3C01800B */  lui       $at, %hi(D_800B0C60)
/* 4A3E8 8006EFE8 AC200C60 */  sw        $zero, %lo(D_800B0C60)($at)
/* 4A3EC 8006EFEC 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A3F0 8006EFF0 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A3F4 8006EFF4 24840014 */  addiu     $a0, $a0, 0x14
/* 4A3F8 8006EFF8 24050060 */  addiu     $a1, $zero, 0x60
/* 4A3FC 8006EFFC 0C019250 */  jal       func_80064940
/* 4A400 8006F000 00000000 */   nop
/* 4A404 8006F004 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A408 8006F008 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A40C 8006F00C 0C0183A4 */  jal       func_80060E90
/* 4A410 8006F010 00000000 */   nop
/* 4A414 8006F014 27A4001C */  addiu     $a0, $sp, 0x1c
/* 4A418 8006F018 27A50018 */  addiu     $a1, $sp, 0x18
/* 4A41C 8006F01C 0C01BC59 */  jal       func_8006F164
/* 4A420 8006F020 00000000 */   nop
/* 4A424 8006F024 8FAC0018 */  lw        $t4, 0x18($sp)
/* 4A428 8006F028 3C0100C2 */  lui       $at, 0xc2
/* 4A42C 8006F02C 3421001E */  ori       $at, $at, 0x1e
/* 4A430 8006F030 11810008 */  beq       $t4, $at, .L8006F054
/* 4A434 8006F034 00000000 */   nop
/* 4A438 8006F038 3C0100C2 */  lui       $at, 0xc2
/* 4A43C 8006F03C 34210001 */  ori       $at, $at, 1
/* 4A440 8006F040 11810004 */  beq       $t4, $at, .L8006F054
/* 4A444 8006F044 00000000 */   nop
/* 4A448 8006F048 3C0100C2 */  lui       $at, 0xc2
/* 4A44C 8006F04C 15810005 */  bne       $t4, $at, .L8006F064
/* 4A450 8006F050 00000000 */   nop
.L8006F054:
/* 4A454 8006F054 3C01800B */  lui       $at, %hi(D_800B0CC8)
/* 4A458 8006F058 AC200CC8 */  sw        $zero, %lo(D_800B0CC8)($at)
/* 4A45C 8006F05C 10000004 */  b         .L8006F070
/* 4A460 8006F060 00000000 */   nop
.L8006F064:
/* 4A464 8006F064 240D0001 */  addiu     $t5, $zero, 1
/* 4A468 8006F068 3C01800B */  lui       $at, %hi(D_800B0CC8)
/* 4A46C 8006F06C AC2D0CC8 */  sw        $t5, %lo(D_800B0CC8)($at)
.L8006F070:
/* 4A470 8006F070 3C02800B */  lui       $v0, %hi(D_800B0C50)
/* 4A474 8006F074 24420C50 */  addiu     $v0, $v0, %lo(D_800B0C50)
/* 4A478 8006F078 10000003 */  b         .L8006F088
/* 4A47C 8006F07C 00000000 */   nop
/* 4A480 8006F080 10000001 */  b         .L8006F088
/* 4A484 8006F084 00000000 */   nop
.L8006F088:
/* 4A488 8006F088 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4A48C 8006F08C 27BD0020 */  addiu     $sp, $sp, 0x20
/* 4A490 8006F090 03E00008 */  jr        $ra
/* 4A494 8006F094 00000000 */   nop
