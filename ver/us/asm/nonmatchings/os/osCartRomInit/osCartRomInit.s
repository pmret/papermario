.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osCartRomInit
/* 3C310 80060F10 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3C314 80060F14 AFBF0018 */  sw        $ra, 0x18($sp)
/* 3C318 80060F18 AFB10014 */  sw        $s1, 0x14($sp)
/* 3C31C 80060F1C 0C018529 */  jal       __osPiGetAccess
/* 3C320 80060F20 AFB00010 */   sw       $s0, 0x10($sp)
/* 3C324 80060F24 3C028009 */  lui       $v0, %hi(D_80093D80)
/* 3C328 80060F28 8C423D80 */  lw        $v0, %lo(D_80093D80)($v0)
/* 3C32C 80060F2C 1040004D */  beqz      $v0, .L80061064
/* 3C330 80060F30 00000000 */   nop
/* 3C334 80060F34 3C02800B */  lui       $v0, %hi(D_800B430C)
/* 3C338 80060F38 2442430C */  addiu     $v0, $v0, %lo(D_800B430C)
/* 3C33C 80060F3C 24440010 */  addiu     $a0, $v0, 0x10
/* 3C340 80060F40 3C018009 */  lui       $at, %hi(D_80093D80)
/* 3C344 80060F44 AC203D80 */  sw        $zero, %lo(D_80093D80)($at)
/* 3C348 80060F48 A0400000 */  sb        $zero, ($v0)
/* 3C34C 80060F4C 3C02B000 */  lui       $v0, 0xb000
/* 3C350 80060F50 3C01800B */  lui       $at, %hi(D_800B4314)
/* 3C354 80060F54 AC224314 */  sw        $v0, %lo(D_800B4314)($at)
/* 3C358 80060F58 3C01800B */  lui       $at, %hi(D_800B4311)
/* 3C35C 80060F5C A0204311 */  sb        $zero, %lo(D_800B4311)($at)
/* 3C360 80060F60 3C01800B */  lui       $at, %hi(D_800B4318)
/* 3C364 80060F64 AC204318 */  sw        $zero, %lo(D_800B4318)($at)
/* 3C368 80060F68 0C01925C */  jal       bzero
/* 3C36C 80060F6C 24050060 */   addiu    $a1, $zero, 0x60
/* 3C370 80060F70 3C02A460 */  lui       $v0, 0xa460
/* 3C374 80060F74 34420010 */  ori       $v0, $v0, 0x10
/* 3C378 80060F78 8C420000 */  lw        $v0, ($v0)
/* 3C37C 80060F7C 30420003 */  andi      $v0, $v0, 3
/* 3C380 80060F80 10400006 */  beqz      $v0, .L80060F9C
/* 3C384 80060F84 3C03A460 */   lui      $v1, 0xa460
/* 3C388 80060F88 34630010 */  ori       $v1, $v1, 0x10
.L80060F8C:
/* 3C38C 80060F8C 8C620000 */  lw        $v0, ($v1)
/* 3C390 80060F90 30420003 */  andi      $v0, $v0, 3
/* 3C394 80060F94 1440FFFD */  bnez      $v0, .L80060F8C
/* 3C398 80060F98 00000000 */   nop
.L80060F9C:
/* 3C39C 80060F9C 3C08A460 */  lui       $t0, 0xa460
/* 3C3A0 80060FA0 35080014 */  ori       $t0, $t0, 0x14
/* 3C3A4 80060FA4 3C07A460 */  lui       $a3, 0xa460
/* 3C3A8 80060FA8 34E7001C */  ori       $a3, $a3, 0x1c
/* 3C3AC 80060FAC 3C06A460 */  lui       $a2, 0xa460
/* 3C3B0 80060FB0 34C60020 */  ori       $a2, $a2, 0x20
/* 3C3B4 80060FB4 3C05A460 */  lui       $a1, 0xa460
/* 3C3B8 80060FB8 34A50018 */  ori       $a1, $a1, 0x18
/* 3C3BC 80060FBC 8D090000 */  lw        $t1, ($t0)
/* 3C3C0 80060FC0 8CEA0000 */  lw        $t2, ($a3)
/* 3C3C4 80060FC4 8CCB0000 */  lw        $t3, ($a2)
/* 3C3C8 80060FC8 8CAC0000 */  lw        $t4, ($a1)
/* 3C3CC 80060FCC 3C11800B */  lui       $s1, %hi(D_800B4314)
/* 3C3D0 80060FD0 26314314 */  addiu     $s1, $s1, %lo(D_800B4314)
/* 3C3D4 80060FD4 8E230000 */  lw        $v1, ($s1)
/* 3C3D8 80060FD8 240400FF */  addiu     $a0, $zero, 0xff
/* 3C3DC 80060FDC 24020003 */  addiu     $v0, $zero, 3
/* 3C3E0 80060FE0 AD040000 */  sw        $a0, ($t0)
/* 3C3E4 80060FE4 ACE00000 */  sw        $zero, ($a3)
/* 3C3E8 80060FE8 ACC20000 */  sw        $v0, ($a2)
/* 3C3EC 80060FEC 3C02A000 */  lui       $v0, 0xa000
/* 3C3F0 80060FF0 ACA40000 */  sw        $a0, ($a1)
/* 3C3F4 80060FF4 00621825 */  or        $v1, $v1, $v0
/* 3C3F8 80060FF8 8C630000 */  lw        $v1, ($v1)
/* 3C3FC 80060FFC AD090000 */  sw        $t1, ($t0)
/* 3C400 80061000 ACEA0000 */  sw        $t2, ($a3)
/* 3C404 80061004 ACCB0000 */  sw        $t3, ($a2)
/* 3C408 80061008 ACAC0000 */  sw        $t4, ($a1)
/* 3C40C 8006100C 00031402 */  srl       $v0, $v1, 0x10
/* 3C410 80061010 3042000F */  andi      $v0, $v0, 0xf
/* 3C414 80061014 3C01800B */  lui       $at, %hi(D_800B430E)
/* 3C418 80061018 A022430E */  sb        $v0, %lo(D_800B430E)($at)
/* 3C41C 8006101C 00031502 */  srl       $v0, $v1, 0x14
/* 3C420 80061020 3042000F */  andi      $v0, $v0, 0xf
/* 3C424 80061024 3C01800B */  lui       $at, %hi(D_800B430D)
/* 3C428 80061028 A023430D */  sb        $v1, %lo(D_800B430D)($at)
/* 3C42C 8006102C 00031A02 */  srl       $v1, $v1, 8
/* 3C430 80061030 3C01800B */  lui       $at, %hi(D_800B430F)
/* 3C434 80061034 A022430F */  sb        $v0, %lo(D_800B430F)($at)
/* 3C438 80061038 3C01800B */  lui       $at, %hi(D_800B4310)
/* 3C43C 8006103C A0234310 */  sb        $v1, %lo(D_800B4310)($at)
/* 3C440 80061040 0C01ACD8 */  jal       __osDisableInt
/* 3C444 80061044 2630FFF4 */   addiu    $s0, $s1, -0xc
/* 3C448 80061048 3C038009 */  lui       $v1, %hi(__osPiTable)
/* 3C44C 8006104C 8C633D6C */  lw        $v1, %lo(__osPiTable)($v1)
/* 3C450 80061050 00402021 */  addu      $a0, $v0, $zero
/* 3C454 80061054 3C018009 */  lui       $at, %hi(__osPiTable)
/* 3C458 80061058 AC303D6C */  sw        $s0, %lo(__osPiTable)($at)
/* 3C45C 8006105C 0C01ACF4 */  jal       __osRestoreInt
/* 3C460 80061060 AE23FFF4 */   sw       $v1, -0xc($s1)
.L80061064:
/* 3C464 80061064 0C018544 */  jal       __osPiRelAccess
/* 3C468 80061068 00000000 */   nop
/* 3C46C 8006106C 3C02800B */  lui       $v0, %hi(D_800B4308)
/* 3C470 80061070 24424308 */  addiu     $v0, $v0, %lo(D_800B4308)
/* 3C474 80061074 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3C478 80061078 8FB10014 */  lw        $s1, 0x14($sp)
/* 3C47C 8006107C 8FB00010 */  lw        $s0, 0x10($sp)
/* 3C480 80061080 03E00008 */  jr        $ra
/* 3C484 80061084 27BD0020 */   addiu    $sp, $sp, 0x20
/* 3C488 80061088 00000000 */  nop
/* 3C48C 8006108C 00000000 */  nop
