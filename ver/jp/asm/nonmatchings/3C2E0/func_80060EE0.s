.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80060EE0
/* 3C2E0 80060EE0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3C2E4 80060EE4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 3C2E8 80060EE8 AFB10014 */  sw        $s1, 0x14($sp)
/* 3C2EC 80060EEC 0C01851D */  jal       func_80061474
/* 3C2F0 80060EF0 AFB00010 */   sw       $s0, 0x10($sp)
/* 3C2F4 80060EF4 3C028009 */  lui       $v0, %hi(D_80093D60)
/* 3C2F8 80060EF8 8C423D60 */  lw        $v0, %lo(D_80093D60)($v0)
/* 3C2FC 80060EFC 1040004D */  beqz      $v0, .L80061034
/* 3C300 80060F00 00000000 */   nop
/* 3C304 80060F04 3C02800B */  lui       $v0, %hi(D_800B42EC)
/* 3C308 80060F08 244242EC */  addiu     $v0, $v0, %lo(D_800B42EC)
/* 3C30C 80060F0C 24440010 */  addiu     $a0, $v0, 0x10
/* 3C310 80060F10 3C018009 */  lui       $at, %hi(D_80093D60)
/* 3C314 80060F14 AC203D60 */  sw        $zero, %lo(D_80093D60)($at)
/* 3C318 80060F18 A0400000 */  sb        $zero, ($v0)
/* 3C31C 80060F1C 3C02B000 */  lui       $v0, 0xb000
/* 3C320 80060F20 3C01800B */  lui       $at, %hi(D_800B42F4)
/* 3C324 80060F24 AC2242F4 */  sw        $v0, %lo(D_800B42F4)($at)
/* 3C328 80060F28 3C01800B */  lui       $at, %hi(D_800B42F1)
/* 3C32C 80060F2C A02042F1 */  sb        $zero, %lo(D_800B42F1)($at)
/* 3C330 80060F30 3C01800B */  lui       $at, %hi(D_800B42F8)
/* 3C334 80060F34 AC2042F8 */  sw        $zero, %lo(D_800B42F8)($at)
/* 3C338 80060F38 0C019250 */  jal       func_80064940
/* 3C33C 80060F3C 24050060 */   addiu    $a1, $zero, 0x60
/* 3C340 80060F40 3C02A460 */  lui       $v0, 0xa460
/* 3C344 80060F44 34420010 */  ori       $v0, $v0, 0x10
/* 3C348 80060F48 8C420000 */  lw        $v0, ($v0)
/* 3C34C 80060F4C 30420003 */  andi      $v0, $v0, 3
/* 3C350 80060F50 10400006 */  beqz      $v0, .L80060F6C
/* 3C354 80060F54 3C03A460 */   lui      $v1, 0xa460
/* 3C358 80060F58 34630010 */  ori       $v1, $v1, 0x10
.L80060F5C:
/* 3C35C 80060F5C 8C620000 */  lw        $v0, ($v1)
/* 3C360 80060F60 30420003 */  andi      $v0, $v0, 3
/* 3C364 80060F64 1440FFFD */  bnez      $v0, .L80060F5C
/* 3C368 80060F68 00000000 */   nop
.L80060F6C:
/* 3C36C 80060F6C 3C08A460 */  lui       $t0, 0xa460
/* 3C370 80060F70 35080014 */  ori       $t0, $t0, 0x14
/* 3C374 80060F74 3C07A460 */  lui       $a3, 0xa460
/* 3C378 80060F78 34E7001C */  ori       $a3, $a3, 0x1c
/* 3C37C 80060F7C 3C06A460 */  lui       $a2, 0xa460
/* 3C380 80060F80 34C60020 */  ori       $a2, $a2, 0x20
/* 3C384 80060F84 3C05A460 */  lui       $a1, 0xa460
/* 3C388 80060F88 34A50018 */  ori       $a1, $a1, 0x18
/* 3C38C 80060F8C 8D090000 */  lw        $t1, ($t0)
/* 3C390 80060F90 8CEA0000 */  lw        $t2, ($a3)
/* 3C394 80060F94 8CCB0000 */  lw        $t3, ($a2)
/* 3C398 80060F98 8CAC0000 */  lw        $t4, ($a1)
/* 3C39C 80060F9C 3C11800B */  lui       $s1, %hi(D_800B42F4)
/* 3C3A0 80060FA0 263142F4 */  addiu     $s1, $s1, %lo(D_800B42F4)
/* 3C3A4 80060FA4 8E230000 */  lw        $v1, ($s1)
/* 3C3A8 80060FA8 240400FF */  addiu     $a0, $zero, 0xff
/* 3C3AC 80060FAC 24020003 */  addiu     $v0, $zero, 3
/* 3C3B0 80060FB0 AD040000 */  sw        $a0, ($t0)
/* 3C3B4 80060FB4 ACE00000 */  sw        $zero, ($a3)
/* 3C3B8 80060FB8 ACC20000 */  sw        $v0, ($a2)
/* 3C3BC 80060FBC 3C02A000 */  lui       $v0, 0xa000
/* 3C3C0 80060FC0 ACA40000 */  sw        $a0, ($a1)
/* 3C3C4 80060FC4 00621825 */  or        $v1, $v1, $v0
/* 3C3C8 80060FC8 8C630000 */  lw        $v1, ($v1)
/* 3C3CC 80060FCC AD090000 */  sw        $t1, ($t0)
/* 3C3D0 80060FD0 ACEA0000 */  sw        $t2, ($a3)
/* 3C3D4 80060FD4 ACCB0000 */  sw        $t3, ($a2)
/* 3C3D8 80060FD8 ACAC0000 */  sw        $t4, ($a1)
/* 3C3DC 80060FDC 00031402 */  srl       $v0, $v1, 0x10
/* 3C3E0 80060FE0 3042000F */  andi      $v0, $v0, 0xf
/* 3C3E4 80060FE4 3C01800B */  lui       $at, %hi(D_800B42EE)
/* 3C3E8 80060FE8 A02242EE */  sb        $v0, %lo(D_800B42EE)($at)
/* 3C3EC 80060FEC 00031502 */  srl       $v0, $v1, 0x14
/* 3C3F0 80060FF0 3042000F */  andi      $v0, $v0, 0xf
/* 3C3F4 80060FF4 3C01800B */  lui       $at, %hi(D_800B42ED)
/* 3C3F8 80060FF8 A02342ED */  sb        $v1, %lo(D_800B42ED)($at)
/* 3C3FC 80060FFC 00031A02 */  srl       $v1, $v1, 8
/* 3C400 80061000 3C01800B */  lui       $at, %hi(D_800B42EF)
/* 3C404 80061004 A02242EF */  sb        $v0, %lo(D_800B42EF)($at)
/* 3C408 80061008 3C01800B */  lui       $at, %hi(D_800B42F0)
/* 3C40C 8006100C A02342F0 */  sb        $v1, %lo(D_800B42F0)($at)
/* 3C410 80061010 0C01ACD0 */  jal       func_8006B340
/* 3C414 80061014 2630FFF4 */   addiu    $s0, $s1, -0xc
/* 3C418 80061018 3C038009 */  lui       $v1, %hi(D_80093D4C)
/* 3C41C 8006101C 8C633D4C */  lw        $v1, %lo(D_80093D4C)($v1)
/* 3C420 80061020 00402021 */  addu      $a0, $v0, $zero
/* 3C424 80061024 3C018009 */  lui       $at, %hi(D_80093D4C)
/* 3C428 80061028 AC303D4C */  sw        $s0, %lo(D_80093D4C)($at)
/* 3C42C 8006102C 0C01ACEC */  jal       func_8006B3B0
/* 3C430 80061030 AE23FFF4 */   sw       $v1, -0xc($s1)
.L80061034:
/* 3C434 80061034 0C018538 */  jal       func_800614E0
/* 3C438 80061038 00000000 */   nop
/* 3C43C 8006103C 3C02800B */  lui       $v0, %hi(D_800B42E8)
/* 3C440 80061040 244242E8 */  addiu     $v0, $v0, %lo(D_800B42E8)
/* 3C444 80061044 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3C448 80061048 8FB10014 */  lw        $s1, 0x14($sp)
/* 3C44C 8006104C 8FB00010 */  lw        $s0, 0x10($sp)
/* 3C450 80061050 03E00008 */  jr        $ra
/* 3C454 80061054 27BD0020 */   addiu    $sp, $sp, 0x20
/* 3C458 80061058 00000000 */  nop
/* 3C45C 8006105C 00000000 */  nop
