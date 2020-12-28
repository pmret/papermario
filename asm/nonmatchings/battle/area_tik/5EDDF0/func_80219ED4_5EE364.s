.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219ED4_5EE364
/* 5EE364 80219ED4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 5EE368 80219ED8 AFB00010 */  sw        $s0, 0x10($sp)
/* 5EE36C 80219EDC 0080802D */  daddu     $s0, $a0, $zero
/* 5EE370 80219EE0 10A00005 */  beqz      $a1, .L80219EF8
/* 5EE374 80219EE4 AFBF0014 */   sw       $ra, 0x14($sp)
/* 5EE378 80219EE8 AE000070 */  sw        $zero, 0x70($s0)
/* 5EE37C 80219EEC AE000074 */  sw        $zero, 0x74($s0)
/* 5EE380 80219EF0 AE000078 */  sw        $zero, 0x78($s0)
/* 5EE384 80219EF4 AE00007C */  sw        $zero, 0x7c($s0)
.L80219EF8:
/* 5EE388 80219EF8 8E020070 */  lw        $v0, 0x70($s0)
/* 5EE38C 80219EFC 1440000E */  bnez      $v0, .L80219F38
/* 5EE390 80219F00 00000000 */   nop      
/* 5EE394 80219F04 8E0300A8 */  lw        $v1, 0xa8($s0)
/* 5EE398 80219F08 8E020088 */  lw        $v0, 0x88($s0)
/* 5EE39C 80219F0C 00621821 */  addu      $v1, $v1, $v0
/* 5EE3A0 80219F10 04610004 */  bgez      $v1, .L80219F24
/* 5EE3A4 80219F14 AE0300A8 */   sw       $v1, 0xa8($s0)
/* 5EE3A8 80219F18 3C020002 */  lui       $v0, 2
/* 5EE3AC 80219F1C 080867CD */  j         .L80219F34
/* 5EE3B0 80219F20 00621021 */   addu     $v0, $v1, $v0
.L80219F24:
/* 5EE3B4 80219F24 3C040002 */  lui       $a0, 2
/* 5EE3B8 80219F28 0083102A */  slt       $v0, $a0, $v1
/* 5EE3BC 80219F2C 10400002 */  beqz      $v0, .L80219F38
/* 5EE3C0 80219F30 00641023 */   subu     $v0, $v1, $a0
.L80219F34:
/* 5EE3C4 80219F34 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80219F38:
/* 5EE3C8 80219F38 8E020074 */  lw        $v0, 0x74($s0)
/* 5EE3CC 80219F3C 1440000E */  bnez      $v0, .L80219F78
/* 5EE3D0 80219F40 00000000 */   nop      
/* 5EE3D4 80219F44 8E0300AC */  lw        $v1, 0xac($s0)
/* 5EE3D8 80219F48 8E02008C */  lw        $v0, 0x8c($s0)
/* 5EE3DC 80219F4C 00621821 */  addu      $v1, $v1, $v0
/* 5EE3E0 80219F50 04610004 */  bgez      $v1, .L80219F64
/* 5EE3E4 80219F54 AE0300AC */   sw       $v1, 0xac($s0)
/* 5EE3E8 80219F58 3C020002 */  lui       $v0, 2
/* 5EE3EC 80219F5C 080867DD */  j         .L80219F74
/* 5EE3F0 80219F60 00621021 */   addu     $v0, $v1, $v0
.L80219F64:
/* 5EE3F4 80219F64 3C040002 */  lui       $a0, 2
/* 5EE3F8 80219F68 0083102A */  slt       $v0, $a0, $v1
/* 5EE3FC 80219F6C 10400002 */  beqz      $v0, .L80219F78
/* 5EE400 80219F70 00641023 */   subu     $v0, $v1, $a0
.L80219F74:
/* 5EE404 80219F74 AE0200AC */  sw        $v0, 0xac($s0)
.L80219F78:
/* 5EE408 80219F78 8E020078 */  lw        $v0, 0x78($s0)
/* 5EE40C 80219F7C 1440000E */  bnez      $v0, .L80219FB8
/* 5EE410 80219F80 00000000 */   nop      
/* 5EE414 80219F84 8E0300B0 */  lw        $v1, 0xb0($s0)
/* 5EE418 80219F88 8E020090 */  lw        $v0, 0x90($s0)
/* 5EE41C 80219F8C 00621821 */  addu      $v1, $v1, $v0
/* 5EE420 80219F90 04610004 */  bgez      $v1, .L80219FA4
/* 5EE424 80219F94 AE0300B0 */   sw       $v1, 0xb0($s0)
/* 5EE428 80219F98 3C020002 */  lui       $v0, 2
/* 5EE42C 80219F9C 080867ED */  j         .L80219FB4
/* 5EE430 80219FA0 00621021 */   addu     $v0, $v1, $v0
.L80219FA4:
/* 5EE434 80219FA4 3C040002 */  lui       $a0, 2
/* 5EE438 80219FA8 0083102A */  slt       $v0, $a0, $v1
/* 5EE43C 80219FAC 10400002 */  beqz      $v0, .L80219FB8
/* 5EE440 80219FB0 00641023 */   subu     $v0, $v1, $a0
.L80219FB4:
/* 5EE444 80219FB4 AE0200B0 */  sw        $v0, 0xb0($s0)
.L80219FB8:
/* 5EE448 80219FB8 8E02007C */  lw        $v0, 0x7c($s0)
/* 5EE44C 80219FBC 1440000E */  bnez      $v0, .L80219FF8
/* 5EE450 80219FC0 00000000 */   nop      
/* 5EE454 80219FC4 8E0300B4 */  lw        $v1, 0xb4($s0)
/* 5EE458 80219FC8 8E020094 */  lw        $v0, 0x94($s0)
/* 5EE45C 80219FCC 00621821 */  addu      $v1, $v1, $v0
/* 5EE460 80219FD0 04610004 */  bgez      $v1, .L80219FE4
/* 5EE464 80219FD4 AE0300B4 */   sw       $v1, 0xb4($s0)
/* 5EE468 80219FD8 3C020002 */  lui       $v0, 2
/* 5EE46C 80219FDC 080867FD */  j         .L80219FF4
/* 5EE470 80219FE0 00621021 */   addu     $v0, $v1, $v0
.L80219FE4:
/* 5EE474 80219FE4 3C040002 */  lui       $a0, 2
/* 5EE478 80219FE8 0083102A */  slt       $v0, $a0, $v1
/* 5EE47C 80219FEC 10400002 */  beqz      $v0, .L80219FF8
/* 5EE480 80219FF0 00641023 */   subu     $v0, $v1, $a0
.L80219FF4:
/* 5EE484 80219FF4 AE0200B4 */  sw        $v0, 0xb4($s0)
.L80219FF8:
/* 5EE488 80219FF8 8E040084 */  lw        $a0, 0x84($s0)
/* 5EE48C 80219FFC 0C046F07 */  jal       set_main_pan_u
/* 5EE490 8021A000 8E0500A8 */   lw       $a1, 0xa8($s0)
/* 5EE494 8021A004 8E040084 */  lw        $a0, 0x84($s0)
/* 5EE498 8021A008 0C046F0D */  jal       set_main_pan_v
/* 5EE49C 8021A00C 8E0500AC */   lw       $a1, 0xac($s0)
/* 5EE4A0 8021A010 8E040084 */  lw        $a0, 0x84($s0)
/* 5EE4A4 8021A014 0C046F13 */  jal       set_aux_pan_u
/* 5EE4A8 8021A018 8E0500B0 */   lw       $a1, 0xb0($s0)
/* 5EE4AC 8021A01C 8E040084 */  lw        $a0, 0x84($s0)
/* 5EE4B0 8021A020 0C046F19 */  jal       set_aux_pan_v
/* 5EE4B4 8021A024 8E0500B4 */   lw       $a1, 0xb4($s0)
/* 5EE4B8 8021A028 8E020070 */  lw        $v0, 0x70($s0)
/* 5EE4BC 8021A02C 8E030078 */  lw        $v1, 0x78($s0)
/* 5EE4C0 8021A030 8E040098 */  lw        $a0, 0x98($s0)
/* 5EE4C4 8021A034 24420001 */  addiu     $v0, $v0, 1
/* 5EE4C8 8021A038 AE020070 */  sw        $v0, 0x70($s0)
/* 5EE4CC 8021A03C 8E020074 */  lw        $v0, 0x74($s0)
/* 5EE4D0 8021A040 24630001 */  addiu     $v1, $v1, 1
/* 5EE4D4 8021A044 AE030078 */  sw        $v1, 0x78($s0)
/* 5EE4D8 8021A048 8E030070 */  lw        $v1, 0x70($s0)
/* 5EE4DC 8021A04C 24420001 */  addiu     $v0, $v0, 1
/* 5EE4E0 8021A050 AE020074 */  sw        $v0, 0x74($s0)
/* 5EE4E4 8021A054 8E02007C */  lw        $v0, 0x7c($s0)
/* 5EE4E8 8021A058 0064182A */  slt       $v1, $v1, $a0
/* 5EE4EC 8021A05C 24420001 */  addiu     $v0, $v0, 1
/* 5EE4F0 8021A060 14600002 */  bnez      $v1, .L8021A06C
/* 5EE4F4 8021A064 AE02007C */   sw       $v0, 0x7c($s0)
/* 5EE4F8 8021A068 AE000070 */  sw        $zero, 0x70($s0)
.L8021A06C:
/* 5EE4FC 8021A06C 8E020074 */  lw        $v0, 0x74($s0)
/* 5EE500 8021A070 8E03009C */  lw        $v1, 0x9c($s0)
/* 5EE504 8021A074 0043102A */  slt       $v0, $v0, $v1
/* 5EE508 8021A078 50400001 */  beql      $v0, $zero, .L8021A080
/* 5EE50C 8021A07C AE000074 */   sw       $zero, 0x74($s0)
.L8021A080:
/* 5EE510 8021A080 8E020078 */  lw        $v0, 0x78($s0)
/* 5EE514 8021A084 8E0300A0 */  lw        $v1, 0xa0($s0)
/* 5EE518 8021A088 0043102A */  slt       $v0, $v0, $v1
/* 5EE51C 8021A08C 50400001 */  beql      $v0, $zero, .L8021A094
/* 5EE520 8021A090 AE000078 */   sw       $zero, 0x78($s0)
.L8021A094:
/* 5EE524 8021A094 8E02007C */  lw        $v0, 0x7c($s0)
/* 5EE528 8021A098 8E0300A4 */  lw        $v1, 0xa4($s0)
/* 5EE52C 8021A09C 0043102A */  slt       $v0, $v0, $v1
/* 5EE530 8021A0A0 50400001 */  beql      $v0, $zero, .L8021A0A8
/* 5EE534 8021A0A4 AE00007C */   sw       $zero, 0x7c($s0)
.L8021A0A8:
/* 5EE538 8021A0A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 5EE53C 8021A0AC 8FB00010 */  lw        $s0, 0x10($sp)
/* 5EE540 8021A0B0 0000102D */  daddu     $v0, $zero, $zero
/* 5EE544 8021A0B4 03E00008 */  jr        $ra
/* 5EE548 8021A0B8 27BD0018 */   addiu    $sp, $sp, 0x18
/* 5EE54C 8021A0BC 00000000 */  nop       
