.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_D1FE90
/* D1FE90 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D1FE94 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* D1FE98 80240008 0080802D */  daddu     $s0, $a0, $zero
/* D1FE9C 8024000C AFBF0014 */  sw        $ra, 0x14($sp)
/* D1FEA0 80240010 8E0300A8 */  lw        $v1, 0xa8($s0)
/* D1FEA4 80240014 8E020088 */  lw        $v0, 0x88($s0)
/* D1FEA8 80240018 00621821 */  addu      $v1, $v1, $v0
/* D1FEAC 8024001C 04610004 */  bgez      $v1, .L80240030
/* D1FEB0 80240020 AE0300A8 */   sw       $v1, 0xa8($s0)
/* D1FEB4 80240024 3C020002 */  lui       $v0, 2
/* D1FEB8 80240028 08090010 */  j         .L80240040
/* D1FEBC 8024002C 00621021 */   addu     $v0, $v1, $v0
.L80240030:
/* D1FEC0 80240030 3C040002 */  lui       $a0, 2
/* D1FEC4 80240034 0083102A */  slt       $v0, $a0, $v1
/* D1FEC8 80240038 10400002 */  beqz      $v0, .L80240044
/* D1FECC 8024003C 00641023 */   subu     $v0, $v1, $a0
.L80240040:
/* D1FED0 80240040 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240044:
/* D1FED4 80240044 8E0300AC */  lw        $v1, 0xac($s0)
/* D1FED8 80240048 8E02008C */  lw        $v0, 0x8c($s0)
/* D1FEDC 8024004C 00621821 */  addu      $v1, $v1, $v0
/* D1FEE0 80240050 04610004 */  bgez      $v1, .L80240064
/* D1FEE4 80240054 AE0300AC */   sw       $v1, 0xac($s0)
/* D1FEE8 80240058 3C020002 */  lui       $v0, 2
/* D1FEEC 8024005C 0809001D */  j         .L80240074
/* D1FEF0 80240060 00621021 */   addu     $v0, $v1, $v0
.L80240064:
/* D1FEF4 80240064 3C040002 */  lui       $a0, 2
/* D1FEF8 80240068 0083102A */  slt       $v0, $a0, $v1
/* D1FEFC 8024006C 10400002 */  beqz      $v0, .L80240078
/* D1FF00 80240070 00641023 */   subu     $v0, $v1, $a0
.L80240074:
/* D1FF04 80240074 AE0200AC */  sw        $v0, 0xac($s0)
.L80240078:
/* D1FF08 80240078 8E0300B0 */  lw        $v1, 0xb0($s0)
/* D1FF0C 8024007C 8E020090 */  lw        $v0, 0x90($s0)
/* D1FF10 80240080 00621821 */  addu      $v1, $v1, $v0
/* D1FF14 80240084 04610004 */  bgez      $v1, .L80240098
/* D1FF18 80240088 AE0300B0 */   sw       $v1, 0xb0($s0)
/* D1FF1C 8024008C 3C020002 */  lui       $v0, 2
/* D1FF20 80240090 0809002A */  j         .L802400A8
/* D1FF24 80240094 00621021 */   addu     $v0, $v1, $v0
.L80240098:
/* D1FF28 80240098 3C040002 */  lui       $a0, 2
/* D1FF2C 8024009C 0083102A */  slt       $v0, $a0, $v1
/* D1FF30 802400A0 10400002 */  beqz      $v0, .L802400AC
/* D1FF34 802400A4 00641023 */   subu     $v0, $v1, $a0
.L802400A8:
/* D1FF38 802400A8 AE0200B0 */  sw        $v0, 0xb0($s0)
.L802400AC:
/* D1FF3C 802400AC 8E0300B4 */  lw        $v1, 0xb4($s0)
/* D1FF40 802400B0 8E020094 */  lw        $v0, 0x94($s0)
/* D1FF44 802400B4 00621821 */  addu      $v1, $v1, $v0
/* D1FF48 802400B8 04610004 */  bgez      $v1, .L802400CC
/* D1FF4C 802400BC AE0300B4 */   sw       $v1, 0xb4($s0)
/* D1FF50 802400C0 3C020002 */  lui       $v0, 2
/* D1FF54 802400C4 08090037 */  j         .L802400DC
/* D1FF58 802400C8 00621021 */   addu     $v0, $v1, $v0
.L802400CC:
/* D1FF5C 802400CC 3C040002 */  lui       $a0, 2
/* D1FF60 802400D0 0083102A */  slt       $v0, $a0, $v1
/* D1FF64 802400D4 10400002 */  beqz      $v0, .L802400E0
/* D1FF68 802400D8 00641023 */   subu     $v0, $v1, $a0
.L802400DC:
/* D1FF6C 802400DC AE0200B4 */  sw        $v0, 0xb4($s0)
.L802400E0:
/* D1FF70 802400E0 8E040084 */  lw        $a0, 0x84($s0)
/* D1FF74 802400E4 0C046F07 */  jal       set_main_pan_u
/* D1FF78 802400E8 8E0500A8 */   lw       $a1, 0xa8($s0)
/* D1FF7C 802400EC 8E040084 */  lw        $a0, 0x84($s0)
/* D1FF80 802400F0 0C046F0D */  jal       set_main_pan_v
/* D1FF84 802400F4 8E0500AC */   lw       $a1, 0xac($s0)
/* D1FF88 802400F8 8E040084 */  lw        $a0, 0x84($s0)
/* D1FF8C 802400FC 0C046F13 */  jal       set_aux_pan_u
/* D1FF90 80240100 8E0500B0 */   lw       $a1, 0xb0($s0)
/* D1FF94 80240104 8E040084 */  lw        $a0, 0x84($s0)
/* D1FF98 80240108 0C046F19 */  jal       set_aux_pan_v
/* D1FF9C 8024010C 8E0500B4 */   lw       $a1, 0xb4($s0)
/* D1FFA0 80240110 8FBF0014 */  lw        $ra, 0x14($sp)
/* D1FFA4 80240114 8FB00010 */  lw        $s0, 0x10($sp)
/* D1FFA8 80240118 0000102D */  daddu     $v0, $zero, $zero
/* D1FFAC 8024011C 03E00008 */  jr        $ra
/* D1FFB0 80240120 27BD0018 */   addiu    $sp, $sp, 0x18
