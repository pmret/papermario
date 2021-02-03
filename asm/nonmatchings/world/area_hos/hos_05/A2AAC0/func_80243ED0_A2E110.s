.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243ED0_A2E110
/* A2E110 80243ED0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2E114 80243ED4 24A5FFFF */  addiu     $a1, $a1, -1
/* A2E118 80243ED8 04A1000C */  bgez      $a1, .L80243F0C
/* A2E11C 80243EDC AFBF0010 */   sw       $ra, 0x10($sp)
/* A2E120 80243EE0 3404D6B5 */  ori       $a0, $zero, 0xd6b5
/* A2E124 80243EE4 3C028025 */  lui       $v0, %hi(D_8024AA20_A34C60)
/* A2E128 80243EE8 8C42AA20 */  lw        $v0, %lo(D_8024AA20_A34C60)($v0)
/* A2E12C 80243EEC 240300FF */  addiu     $v1, $zero, 0xff
/* A2E130 80243EF0 8C420008 */  lw        $v0, 8($v0)
.L80243EF4:
/* A2E134 80243EF4 A4440000 */  sh        $a0, ($v0)
/* A2E138 80243EF8 2463FFFF */  addiu     $v1, $v1, -1
/* A2E13C 80243EFC 0461FFFD */  bgez      $v1, .L80243EF4
/* A2E140 80243F00 24420002 */   addiu    $v0, $v0, 2
/* A2E144 80243F04 08090FEE */  j         .L80243FB8
/* A2E148 80243F08 00000000 */   nop
.L80243F0C:
/* A2E14C 80243F0C 14800010 */  bnez      $a0, .L80243F50
/* A2E150 80243F10 00052080 */   sll      $a0, $a1, 2
/* A2E154 80243F14 3C030022 */  lui       $v1, 0x22
/* A2E158 80243F18 246391B0 */  addiu     $v1, $v1, -0x6e50
/* A2E15C 80243F1C 00852021 */  addu      $a0, $a0, $a1
/* A2E160 80243F20 00042080 */  sll       $a0, $a0, 2
/* A2E164 80243F24 00852021 */  addu      $a0, $a0, $a1
/* A2E168 80243F28 000420C0 */  sll       $a0, $a0, 3
/* A2E16C 80243F2C 00852021 */  addu      $a0, $a0, $a1
/* A2E170 80243F30 00042100 */  sll       $a0, $a0, 4
/* A2E174 80243F34 00852021 */  addu      $a0, $a0, $a1
/* A2E178 80243F38 00042100 */  sll       $a0, $a0, 4
/* A2E17C 80243F3C 3C028025 */  lui       $v0, %hi(D_8024AA20_A34C60)
/* A2E180 80243F40 8C42AA20 */  lw        $v0, %lo(D_8024AA20_A34C60)($v0)
/* A2E184 80243F44 8C460004 */  lw        $a2, 4($v0)
/* A2E188 80243F48 08090FE2 */  j         .L80243F88
/* A2E18C 80243F4C 00832021 */   addu     $a0, $a0, $v1
.L80243F50:
/* A2E190 80243F50 3C030022 */  lui       $v1, 0x22
/* A2E194 80243F54 246391B0 */  addiu     $v1, $v1, -0x6e50
/* A2E198 80243F58 00852021 */  addu      $a0, $a0, $a1
/* A2E19C 80243F5C 00042080 */  sll       $a0, $a0, 2
/* A2E1A0 80243F60 00852021 */  addu      $a0, $a0, $a1
/* A2E1A4 80243F64 000420C0 */  sll       $a0, $a0, 3
/* A2E1A8 80243F68 00852021 */  addu      $a0, $a0, $a1
/* A2E1AC 80243F6C 00042100 */  sll       $a0, $a0, 4
/* A2E1B0 80243F70 00852021 */  addu      $a0, $a0, $a1
/* A2E1B4 80243F74 00042100 */  sll       $a0, $a0, 4
/* A2E1B8 80243F78 3C028025 */  lui       $v0, %hi(D_8024AA20_A34C60)
/* A2E1BC 80243F7C 8C42AA20 */  lw        $v0, %lo(D_8024AA20_A34C60)($v0)
/* A2E1C0 80243F80 00832021 */  addu      $a0, $a0, $v1
/* A2E1C4 80243F84 8C46000C */  lw        $a2, 0xc($v0)
.L80243F88:
/* A2E1C8 80243F88 24A20001 */  addiu     $v0, $a1, 1
/* A2E1CC 80243F8C 00022880 */  sll       $a1, $v0, 2
/* A2E1D0 80243F90 00A22821 */  addu      $a1, $a1, $v0
/* A2E1D4 80243F94 00052880 */  sll       $a1, $a1, 2
/* A2E1D8 80243F98 00A22821 */  addu      $a1, $a1, $v0
/* A2E1DC 80243F9C 000528C0 */  sll       $a1, $a1, 3
/* A2E1E0 80243FA0 00A22821 */  addu      $a1, $a1, $v0
/* A2E1E4 80243FA4 00052900 */  sll       $a1, $a1, 4
/* A2E1E8 80243FA8 00A22821 */  addu      $a1, $a1, $v0
/* A2E1EC 80243FAC 00052900 */  sll       $a1, $a1, 4
/* A2E1F0 80243FB0 0C00A5CF */  jal       dma_copy
/* A2E1F4 80243FB4 00A32821 */   addu     $a1, $a1, $v1
.L80243FB8:
/* A2E1F8 80243FB8 8FBF0010 */  lw        $ra, 0x10($sp)
/* A2E1FC 80243FBC 03E00008 */  jr        $ra
/* A2E200 80243FC0 27BD0018 */   addiu    $sp, $sp, 0x18
