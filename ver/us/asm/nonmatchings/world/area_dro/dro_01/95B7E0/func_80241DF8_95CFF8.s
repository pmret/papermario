.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DF8_95CFF8
/* 95CFF8 80241DF8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 95CFFC 80241DFC 10A0000B */  beqz      $a1, .L80241E2C
/* 95D000 80241E00 AFBF0010 */   sw       $ra, 0x10($sp)
/* 95D004 80241E04 3C038025 */  lui       $v1, %hi(D_8024DFE4)
/* 95D008 80241E08 8C63DFE4 */  lw        $v1, %lo(D_8024DFE4)($v1)
/* 95D00C 80241E0C 8C620000 */  lw        $v0, ($v1)
/* 95D010 80241E10 3C048025 */  lui       $a0, %hi(D_8024DFE8)
/* 95D014 80241E14 8C84DFE8 */  lw        $a0, %lo(D_8024DFE8)($a0)
/* 95D018 80241E18 34420010 */  ori       $v0, $v0, 0x10
/* 95D01C 80241E1C AC620000 */  sw        $v0, ($v1)
/* 95D020 80241E20 8C820000 */  lw        $v0, ($a0)
/* 95D024 80241E24 34420010 */  ori       $v0, $v0, 0x10
/* 95D028 80241E28 AC820000 */  sw        $v0, ($a0)
.L80241E2C:
/* 95D02C 80241E2C 3C048025 */  lui       $a0, %hi(D_8024DFE0)
/* 95D030 80241E30 8C84DFE0 */  lw        $a0, %lo(D_8024DFE0)($a0)
/* 95D034 80241E34 8C85000C */  lw        $a1, 0xc($a0)
/* 95D038 80241E38 8CA20018 */  lw        $v0, 0x18($a1)
/* 95D03C 80241E3C 8CA30020 */  lw        $v1, 0x20($a1)
/* 95D040 80241E40 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 95D044 80241E44 ACA20018 */  sw        $v0, 0x18($a1)
/* 95D048 80241E48 8CA20024 */  lw        $v0, 0x24($a1)
/* 95D04C 80241E4C 2463FFF6 */  addiu     $v1, $v1, -0xa
/* 95D050 80241E50 ACA30020 */  sw        $v1, 0x20($a1)
/* 95D054 80241E54 8CA30028 */  lw        $v1, 0x28($a1)
/* 95D058 80241E58 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 95D05C 80241E5C ACA20024 */  sw        $v0, 0x24($a1)
/* 95D060 80241E60 8CA2001C */  lw        $v0, 0x1c($a1)
/* 95D064 80241E64 2463FFF6 */  addiu     $v1, $v1, -0xa
/* 95D068 80241E68 ACA30028 */  sw        $v1, 0x28($a1)
/* 95D06C 80241E6C 8CA30018 */  lw        $v1, 0x18($a1)
/* 95D070 80241E70 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 95D074 80241E74 18600003 */  blez      $v1, .L80241E84
/* 95D078 80241E78 ACA2001C */   sw       $v0, 0x1c($a1)
/* 95D07C 80241E7C 080907A8 */  j         .L80241EA0
/* 95D080 80241E80 0000102D */   daddu    $v0, $zero, $zero
.L80241E84:
/* 95D084 80241E84 0C016914 */  jal       remove_effect
/* 95D088 80241E88 ACA00018 */   sw       $zero, 0x18($a1)
/* 95D08C 80241E8C 3C048025 */  lui       $a0, %hi(D_8024DFC0)
/* 95D090 80241E90 8C84DFC0 */  lw        $a0, %lo(D_8024DFC0)($a0)
/* 95D094 80241E94 0C048D70 */  jal       func_801235C0
/* 95D098 80241E98 00000000 */   nop
/* 95D09C 80241E9C 24020002 */  addiu     $v0, $zero, 2
.L80241EA0:
/* 95D0A0 80241EA0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 95D0A4 80241EA4 03E00008 */  jr        $ra
/* 95D0A8 80241EA8 27BD0018 */   addiu    $sp, $sp, 0x18
