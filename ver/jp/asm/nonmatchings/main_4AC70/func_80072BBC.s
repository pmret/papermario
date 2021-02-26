.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072BBC
/* 4DFBC 80072BBC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4DFC0 80072BC0 3C02800E */  lui       $v0, %hi(D_800DC4CA)
/* 4DFC4 80072BC4 9042C4CA */  lbu       $v0, %lo(D_800DC4CA)($v0)
/* 4DFC8 80072BC8 3C038009 */  lui       $v1, %hi(D_80095A10)
/* 4DFCC 80072BCC 24635A10 */  addiu     $v1, $v1, %lo(D_80095A10)
/* 4DFD0 80072BD0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4DFD4 80072BD4 AFB10014 */  sw        $s1, 0x14($sp)
/* 4DFD8 80072BD8 AFB00010 */  sw        $s0, 0x10($sp)
/* 4DFDC 80072BDC 00021140 */  sll       $v0, $v0, 5
/* 4DFE0 80072BE0 00438821 */  addu      $s1, $v0, $v1
/* 4DFE4 80072BE4 8E240004 */  lw        $a0, 4($s1)
/* 4DFE8 80072BE8 8E250008 */  lw        $a1, 8($s1)
/* 4DFEC 80072BEC 8E26000C */  lw        $a2, 0xc($s1)
/* 4DFF0 80072BF0 3C10800E */  lui       $s0, %hi(D_800DC4CB)
/* 4DFF4 80072BF4 9210C4CB */  lbu       $s0, %lo(D_800DC4CB)($s0)
/* 4DFF8 80072BF8 0C00A5BF */  jal       func_800296FC
/* 4DFFC 80072BFC 00000000 */   nop
/* 4E000 80072C00 00101880 */  sll       $v1, $s0, 2
/* 4E004 80072C04 00701821 */  addu      $v1, $v1, $s0
/* 4E008 80072C08 00031880 */  sll       $v1, $v1, 2
/* 4E00C 80072C0C 8E220010 */  lw        $v0, 0x10($s1)
/* 4E010 80072C10 3C04800E */  lui       $a0, %hi(D_800DC4CC)
/* 4E014 80072C14 8C84C4CC */  lw        $a0, %lo(D_800DC4CC)($a0)
/* 4E018 80072C18 00431021 */  addu      $v0, $v0, $v1
/* 4E01C 80072C1C 3C01800E */  lui       $at, %hi(D_800DC4DC)
/* 4E020 80072C20 AC22C4DC */  sw        $v0, %lo(D_800DC4DC)($at)
/* 4E024 80072C24 04810005 */  bgez      $a0, .L80072C3C
/* 4E028 80072C28 000418C0 */   sll      $v1, $a0, 3
/* 4E02C 80072C2C 3C01800E */  lui       $at, %hi(D_800DC044)
/* 4E030 80072C30 AC20C044 */  sw        $zero, %lo(D_800DC044)($at)
/* 4E034 80072C34 0801CB13 */  j         .L80072C4C
/* 4E038 80072C38 00000000 */   nop
.L80072C3C:
/* 4E03C 80072C3C 8E220014 */  lw        $v0, 0x14($s1)
/* 4E040 80072C40 00431021 */  addu      $v0, $v0, $v1
/* 4E044 80072C44 3C01800E */  lui       $at, %hi(D_800DC044)
/* 4E048 80072C48 AC22C044 */  sw        $v0, %lo(D_800DC044)($at)
.L80072C4C:
/* 4E04C 80072C4C 0C090464 */  jal       func_80241190
/* 4E050 80072C50 24040001 */   addiu    $a0, $zero, 1
/* 4E054 80072C54 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4E058 80072C58 8FB10014 */  lw        $s1, 0x14($sp)
/* 4E05C 80072C5C 8FB00010 */  lw        $s0, 0x10($sp)
/* 4E060 80072C60 3C01800E */  lui       $at, %hi(D_800DC4B0)
/* 4E064 80072C64 AC20C4B0 */  sw        $zero, %lo(D_800DC4B0)($at)
/* 4E068 80072C68 03E00008 */  jr        $ra
/* 4E06C 80072C6C 27BD0020 */   addiu    $sp, $sp, 0x20
