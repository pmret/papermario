.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osFlashInit
/* 4A368 8006EF68 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4A36C 8006EF6C AFBF0014 */  sw        $ra, 0x14($sp)
/* 4A370 8006EF70 3C04800B */  lui       $a0, %hi(D_800B0C58)
/* 4A374 8006EF74 24840C58 */  addiu     $a0, $a0, %lo(D_800B0C58)
/* 4A378 8006EF78 3C05800B */  lui       $a1, %hi(D_800B0CE4)
/* 4A37C 8006EF7C 24A50CE4 */  addiu     $a1, $a1, %lo(D_800B0CE4)
/* 4A380 8006EF80 24060001 */  addiu     $a2, $zero, 1
/* 4A384 8006EF84 0C019560 */  jal       osCreateMesgQueue
/* 4A388 8006EF88 00000000 */   nop      
/* 4A38C 8006EF8C 3C0E800B */  lui       $t6, %hi(D_800B0C7C)
/* 4A390 8006EF90 8DCE0C7C */  lw        $t6, %lo(D_800B0C7C)($t6)
/* 4A394 8006EF94 3C01A800 */  lui       $at, 0xa800
/* 4A398 8006EF98 15C10005 */  bne       $t6, $at, .L8006EFB0
/* 4A39C 8006EF9C 00000000 */   nop      
/* 4A3A0 8006EFA0 3C02800B */  lui       $v0, %hi(D_800B0C70)
/* 4A3A4 8006EFA4 24420C70 */  addiu     $v0, $v0, %lo(D_800B0C70)
/* 4A3A8 8006EFA8 1000003F */  b         .L8006F0A8
/* 4A3AC 8006EFAC 00000000 */   nop      
.L8006EFB0:
/* 4A3B0 8006EFB0 240F0008 */  addiu     $t7, $zero, 8
/* 4A3B4 8006EFB4 3C01800B */  lui       $at, %hi(D_800B0C74)
/* 4A3B8 8006EFB8 A02F0C74 */  sb        $t7, %lo(D_800B0C74)($at)
/* 4A3BC 8006EFBC 3C18A800 */  lui       $t8, 0xa800
/* 4A3C0 8006EFC0 3C01800B */  lui       $at, %hi(D_800B0C7C)
/* 4A3C4 8006EFC4 AC380C7C */  sw        $t8, %lo(D_800B0C7C)($at)
/* 4A3C8 8006EFC8 24190005 */  addiu     $t9, $zero, 5
/* 4A3CC 8006EFCC 3C01800B */  lui       $at, %hi(D_800B0C75)
/* 4A3D0 8006EFD0 A0390C75 */  sb        $t9, %lo(D_800B0C75)($at)
/* 4A3D4 8006EFD4 2408000C */  addiu     $t0, $zero, 0xc
/* 4A3D8 8006EFD8 3C01800B */  lui       $at, %hi(D_800B0C78)
/* 4A3DC 8006EFDC A0280C78 */  sb        $t0, %lo(D_800B0C78)($at)
/* 4A3E0 8006EFE0 2409000F */  addiu     $t1, $zero, 0xf
/* 4A3E4 8006EFE4 3C01800B */  lui       $at, %hi(D_800B0C76)
/* 4A3E8 8006EFE8 A0290C76 */  sb        $t1, %lo(D_800B0C76)($at)
/* 4A3EC 8006EFEC 240A0002 */  addiu     $t2, $zero, 2
/* 4A3F0 8006EFF0 3C01800B */  lui       $at, %hi(D_800B0C77)
/* 4A3F4 8006EFF4 A02A0C77 */  sb        $t2, %lo(D_800B0C77)($at)
/* 4A3F8 8006EFF8 240B0001 */  addiu     $t3, $zero, 1
/* 4A3FC 8006EFFC 3C01800B */  lui       $at, %hi(D_800B0C79)
/* 4A400 8006F000 A02B0C79 */  sb        $t3, %lo(D_800B0C79)($at)
/* 4A404 8006F004 3C01800B */  lui       $at, %hi(D_800B0C80)
/* 4A408 8006F008 AC200C80 */  sw        $zero, %lo(D_800B0C80)($at)
/* 4A40C 8006F00C 3C04800B */  lui       $a0, %hi(D_800B0C70)
/* 4A410 8006F010 24840C70 */  addiu     $a0, $a0, %lo(D_800B0C70)
/* 4A414 8006F014 24840014 */  addiu     $a0, $a0, 0x14
/* 4A418 8006F018 24050060 */  addiu     $a1, $zero, 0x60
/* 4A41C 8006F01C 0C01925C */  jal       bzero
/* 4A420 8006F020 00000000 */   nop      
/* 4A424 8006F024 3C04800B */  lui       $a0, %hi(D_800B0C70)
/* 4A428 8006F028 24840C70 */  addiu     $a0, $a0, %lo(D_800B0C70)
/* 4A42C 8006F02C 0C0183B0 */  jal       osEPiLinkHandle
/* 4A430 8006F030 00000000 */   nop      
/* 4A434 8006F034 27A4001C */  addiu     $a0, $sp, 0x1c
/* 4A438 8006F038 27A50018 */  addiu     $a1, $sp, 0x18
/* 4A43C 8006F03C 0C01BC61 */  jal       osFlashReadId
/* 4A440 8006F040 00000000 */   nop      
/* 4A444 8006F044 8FAC0018 */  lw        $t4, 0x18($sp)
/* 4A448 8006F048 3C0100C2 */  lui       $at, 0xc2
/* 4A44C 8006F04C 3421001E */  ori       $at, $at, 0x1e
/* 4A450 8006F050 11810008 */  beq       $t4, $at, .L8006F074
/* 4A454 8006F054 00000000 */   nop      
/* 4A458 8006F058 3C0100C2 */  lui       $at, 0xc2
/* 4A45C 8006F05C 34210001 */  ori       $at, $at, 1
/* 4A460 8006F060 11810004 */  beq       $t4, $at, .L8006F074
/* 4A464 8006F064 00000000 */   nop      
/* 4A468 8006F068 3C0100C2 */  lui       $at, 0xc2
/* 4A46C 8006F06C 15810005 */  bne       $t4, $at, .L8006F084
/* 4A470 8006F070 00000000 */   nop      
.L8006F074:
/* 4A474 8006F074 3C01800B */  lui       $at, %hi(D_800B0CE8)
/* 4A478 8006F078 AC200CE8 */  sw        $zero, %lo(D_800B0CE8)($at)
/* 4A47C 8006F07C 10000004 */  b         .L8006F090
/* 4A480 8006F080 00000000 */   nop      
.L8006F084:
/* 4A484 8006F084 240D0001 */  addiu     $t5, $zero, 1
/* 4A488 8006F088 3C01800B */  lui       $at, %hi(D_800B0CE8)
/* 4A48C 8006F08C AC2D0CE8 */  sw        $t5, %lo(D_800B0CE8)($at)
.L8006F090:
/* 4A490 8006F090 3C02800B */  lui       $v0, %hi(D_800B0C70)
/* 4A494 8006F094 24420C70 */  addiu     $v0, $v0, %lo(D_800B0C70)
/* 4A498 8006F098 10000003 */  b         .L8006F0A8
/* 4A49C 8006F09C 00000000 */   nop      
/* 4A4A0 8006F0A0 10000001 */  b         .L8006F0A8
/* 4A4A4 8006F0A4 00000000 */   nop      
.L8006F0A8:
/* 4A4A8 8006F0A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4A4AC 8006F0AC 27BD0020 */  addiu     $sp, $sp, 0x20
/* 4A4B0 8006F0B0 03E00008 */  jr        $ra
/* 4A4B4 8006F0B4 00000000 */   nop      
