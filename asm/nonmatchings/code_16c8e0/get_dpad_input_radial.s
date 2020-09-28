.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_dpad_input_radial
/* 16C8E0 8023E000 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 16C8E4 8023E004 AFB00010 */  sw        $s0, 0x10($sp)
/* 16C8E8 8023E008 0080802D */  daddu     $s0, $a0, $zero
/* 16C8EC 8023E00C AFB10014 */  sw        $s1, 0x14($sp)
/* 16C8F0 8023E010 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 16C8F4 8023E014 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 16C8F8 8023E018 AFBF0018 */  sw        $ra, 0x18($sp)
/* 16C8FC 8023E01C F7BC0040 */  sdc1      $f28, 0x40($sp)
/* 16C900 8023E020 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* 16C904 8023E024 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 16C908 8023E028 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 16C90C 8023E02C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 16C910 8023E030 C456021C */  lwc1      $f22, 0x21c($v0)
/* 16C914 8023E034 4680B5A0 */  cvt.s.w   $f22, $f22
/* 16C918 8023E038 C4400220 */  lwc1      $f0, 0x220($v0)
/* 16C91C 8023E03C 46800020 */  cvt.s.w   $f0, $f0
/* 16C920 8023E040 94430212 */  lhu       $v1, 0x212($v0)
/* 16C924 8023E044 3C014270 */  lui       $at, 0x4270
/* 16C928 8023E048 4481D000 */  mtc1      $at, $f26
/* 16C92C 8023E04C 30620F00 */  andi      $v0, $v1, 0xf00
/* 16C930 8023E050 1040000F */  beqz      $v0, .L8023E090
/* 16C934 8023E054 00A0882D */   daddu    $s1, $a1, $zero
/* 16C938 8023E058 4480B000 */  mtc1      $zero, $f22
/* 16C93C 8023E05C 30620800 */  andi      $v0, $v1, 0x800
/* 16C940 8023E060 10400002 */  beqz      $v0, .L8023E06C
/* 16C944 8023E064 4600B006 */   mov.s    $f0, $f22
/* 16C948 8023E068 4600D006 */  mov.s     $f0, $f26
.L8023E06C:
/* 16C94C 8023E06C 30620400 */  andi      $v0, $v1, 0x400
/* 16C950 8023E070 54400001 */  bnel      $v0, $zero, .L8023E078
/* 16C954 8023E074 4600D007 */   neg.s    $f0, $f26
.L8023E078:
/* 16C958 8023E078 30620200 */  andi      $v0, $v1, 0x200
/* 16C95C 8023E07C 54400001 */  bnel      $v0, $zero, .L8023E084
/* 16C960 8023E080 4600D587 */   neg.s    $f22, $f26
.L8023E084:
/* 16C964 8023E084 30620100 */  andi      $v0, $v1, 0x100
/* 16C968 8023E088 54400001 */  bnel      $v0, $zero, .L8023E090
/* 16C96C 8023E08C 4600D586 */   mov.s    $f22, $f26
.L8023E090:
/* 16C970 8023E090 4406B000 */  mfc1      $a2, $f22
/* 16C974 8023E094 4480C000 */  mtc1      $zero, $f24
/* 16C978 8023E098 46000707 */  neg.s     $f28, $f0
/* 16C97C 8023E09C 4407E000 */  mfc1      $a3, $f28
/* 16C980 8023E0A0 4600C306 */  mov.s     $f12, $f24
/* 16C984 8023E0A4 0C00A7B5 */  jal       dist2D
/* 16C988 8023E0A8 4600C386 */   mov.s    $f14, $f24
/* 16C98C 8023E0AC 46000506 */  mov.s     $f20, $f0
/* 16C990 8023E0B0 4614D03E */  c.le.s    $f26, $f20
/* 16C994 8023E0B4 00000000 */  nop       
/* 16C998 8023E0B8 45030001 */  bc1tl     .L8023E0C0
/* 16C99C 8023E0BC 4600D506 */   mov.s    $f20, $f26
.L8023E0C0:
/* 16C9A0 8023E0C0 4600C306 */  mov.s     $f12, $f24
/* 16C9A4 8023E0C4 4406B000 */  mfc1      $a2, $f22
/* 16C9A8 8023E0C8 4407E000 */  mfc1      $a3, $f28
/* 16C9AC 8023E0CC 0C00A720 */  jal       atan2
/* 16C9B0 8023E0D0 46006386 */   mov.s    $f14, $f12
/* 16C9B4 8023E0D4 E6000000 */  swc1      $f0, ($s0)
/* 16C9B8 8023E0D8 E6340000 */  swc1      $f20, ($s1)
/* 16C9BC 8023E0DC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 16C9C0 8023E0E0 8FB10014 */  lw        $s1, 0x14($sp)
/* 16C9C4 8023E0E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 16C9C8 8023E0E8 D7BC0040 */  ldc1      $f28, 0x40($sp)
/* 16C9CC 8023E0EC D7BA0038 */  ldc1      $f26, 0x38($sp)
/* 16C9D0 8023E0F0 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 16C9D4 8023E0F4 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 16C9D8 8023E0F8 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 16C9DC 8023E0FC 03E00008 */  jr        $ra
/* 16C9E0 8023E100 27BD0048 */   addiu    $sp, $sp, 0x48
