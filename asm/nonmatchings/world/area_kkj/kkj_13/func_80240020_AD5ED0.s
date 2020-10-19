.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240020_AD5EF0
/* AD5EF0 80240020 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AD5EF4 80240024 AFB00010 */  sw        $s0, 0x10($sp)
/* AD5EF8 80240028 0080802D */  daddu     $s0, $a0, $zero
/* AD5EFC 8024002C AFBF0014 */  sw        $ra, 0x14($sp)
/* AD5F00 80240030 8E0300A8 */  lw        $v1, 0xa8($s0)
/* AD5F04 80240034 8E020088 */  lw        $v0, 0x88($s0)
/* AD5F08 80240038 00621821 */  addu      $v1, $v1, $v0
/* AD5F0C 8024003C 04610004 */  bgez      $v1, .L80240050
/* AD5F10 80240040 AE0300A8 */   sw       $v1, 0xa8($s0)
/* AD5F14 80240044 3C020002 */  lui       $v0, 2
/* AD5F18 80240048 08090018 */  j         .L80240060
/* AD5F1C 8024004C 00621021 */   addu     $v0, $v1, $v0
.L80240050:
/* AD5F20 80240050 3C040002 */  lui       $a0, 2
/* AD5F24 80240054 0083102A */  slt       $v0, $a0, $v1
/* AD5F28 80240058 10400002 */  beqz      $v0, .L80240064
/* AD5F2C 8024005C 00641023 */   subu     $v0, $v1, $a0
.L80240060:
/* AD5F30 80240060 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240064:
/* AD5F34 80240064 8E0300AC */  lw        $v1, 0xac($s0)
/* AD5F38 80240068 8E02008C */  lw        $v0, 0x8c($s0)
/* AD5F3C 8024006C 00621821 */  addu      $v1, $v1, $v0
/* AD5F40 80240070 04610004 */  bgez      $v1, .L80240084
/* AD5F44 80240074 AE0300AC */   sw       $v1, 0xac($s0)
/* AD5F48 80240078 3C020002 */  lui       $v0, 2
/* AD5F4C 8024007C 08090025 */  j         .L80240094
/* AD5F50 80240080 00621021 */   addu     $v0, $v1, $v0
.L80240084:
/* AD5F54 80240084 3C040002 */  lui       $a0, 2
/* AD5F58 80240088 0083102A */  slt       $v0, $a0, $v1
/* AD5F5C 8024008C 10400002 */  beqz      $v0, .L80240098
/* AD5F60 80240090 00641023 */   subu     $v0, $v1, $a0
.L80240094:
/* AD5F64 80240094 AE0200AC */  sw        $v0, 0xac($s0)
.L80240098:
/* AD5F68 80240098 8E0300B0 */  lw        $v1, 0xb0($s0)
/* AD5F6C 8024009C 8E020090 */  lw        $v0, 0x90($s0)
/* AD5F70 802400A0 00621821 */  addu      $v1, $v1, $v0
/* AD5F74 802400A4 04610004 */  bgez      $v1, .L802400B8
/* AD5F78 802400A8 AE0300B0 */   sw       $v1, 0xb0($s0)
/* AD5F7C 802400AC 3C020002 */  lui       $v0, 2
/* AD5F80 802400B0 08090032 */  j         .L802400C8
/* AD5F84 802400B4 00621021 */   addu     $v0, $v1, $v0
.L802400B8:
/* AD5F88 802400B8 3C040002 */  lui       $a0, 2
/* AD5F8C 802400BC 0083102A */  slt       $v0, $a0, $v1
/* AD5F90 802400C0 10400002 */  beqz      $v0, .L802400CC
/* AD5F94 802400C4 00641023 */   subu     $v0, $v1, $a0
.L802400C8:
/* AD5F98 802400C8 AE0200B0 */  sw        $v0, 0xb0($s0)
.L802400CC:
/* AD5F9C 802400CC 8E0300B4 */  lw        $v1, 0xb4($s0)
/* AD5FA0 802400D0 8E020094 */  lw        $v0, 0x94($s0)
/* AD5FA4 802400D4 00621821 */  addu      $v1, $v1, $v0
/* AD5FA8 802400D8 04610004 */  bgez      $v1, .L802400EC
/* AD5FAC 802400DC AE0300B4 */   sw       $v1, 0xb4($s0)
/* AD5FB0 802400E0 3C020002 */  lui       $v0, 2
/* AD5FB4 802400E4 0809003F */  j         .L802400FC
/* AD5FB8 802400E8 00621021 */   addu     $v0, $v1, $v0
.L802400EC:
/* AD5FBC 802400EC 3C040002 */  lui       $a0, 2
/* AD5FC0 802400F0 0083102A */  slt       $v0, $a0, $v1
/* AD5FC4 802400F4 10400002 */  beqz      $v0, .L80240100
/* AD5FC8 802400F8 00641023 */   subu     $v0, $v1, $a0
.L802400FC:
/* AD5FCC 802400FC AE0200B4 */  sw        $v0, 0xb4($s0)
.L80240100:
/* AD5FD0 80240100 8E040084 */  lw        $a0, 0x84($s0)
/* AD5FD4 80240104 0C046F07 */  jal       set_main_pan_u
/* AD5FD8 80240108 8E0500A8 */   lw       $a1, 0xa8($s0)
/* AD5FDC 8024010C 8E040084 */  lw        $a0, 0x84($s0)
/* AD5FE0 80240110 0C046F0D */  jal       set_main_pan_v
/* AD5FE4 80240114 8E0500AC */   lw       $a1, 0xac($s0)
/* AD5FE8 80240118 8E040084 */  lw        $a0, 0x84($s0)
/* AD5FEC 8024011C 0C046F13 */  jal       set_aux_pan_u
/* AD5FF0 80240120 8E0500B0 */   lw       $a1, 0xb0($s0)
/* AD5FF4 80240124 8E040084 */  lw        $a0, 0x84($s0)
/* AD5FF8 80240128 0C046F19 */  jal       set_aux_pan_v
/* AD5FFC 8024012C 8E0500B4 */   lw       $a1, 0xb4($s0)
/* AD6000 80240130 8FBF0014 */  lw        $ra, 0x14($sp)
/* AD6004 80240134 8FB00010 */  lw        $s0, 0x10($sp)
/* AD6008 80240138 0000102D */  daddu     $v0, $zero, $zero
/* AD600C 8024013C 03E00008 */  jr        $ra
/* AD6010 80240140 27BD0018 */   addiu    $sp, $sp, 0x18
