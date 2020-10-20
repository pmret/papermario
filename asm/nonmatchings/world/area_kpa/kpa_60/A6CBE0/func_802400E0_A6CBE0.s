.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400E0_A6CBE0
/* A6CBE0 802400E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A6CBE4 802400E4 AFB00010 */  sw        $s0, 0x10($sp)
/* A6CBE8 802400E8 0080802D */  daddu     $s0, $a0, $zero
/* A6CBEC 802400EC AFBF0014 */  sw        $ra, 0x14($sp)
/* A6CBF0 802400F0 8E0300A8 */  lw        $v1, 0xa8($s0)
/* A6CBF4 802400F4 8E020088 */  lw        $v0, 0x88($s0)
/* A6CBF8 802400F8 00621821 */  addu      $v1, $v1, $v0
/* A6CBFC 802400FC 04610004 */  bgez      $v1, .L80240110
/* A6CC00 80240100 AE0300A8 */   sw       $v1, 0xa8($s0)
/* A6CC04 80240104 3C020002 */  lui       $v0, 2
/* A6CC08 80240108 08090048 */  j         .L80240120
/* A6CC0C 8024010C 00621021 */   addu     $v0, $v1, $v0
.L80240110:
/* A6CC10 80240110 3C040002 */  lui       $a0, 2
/* A6CC14 80240114 0083102A */  slt       $v0, $a0, $v1
/* A6CC18 80240118 10400002 */  beqz      $v0, .L80240124
/* A6CC1C 8024011C 00641023 */   subu     $v0, $v1, $a0
.L80240120:
/* A6CC20 80240120 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240124:
/* A6CC24 80240124 8E0300AC */  lw        $v1, 0xac($s0)
/* A6CC28 80240128 8E02008C */  lw        $v0, 0x8c($s0)
/* A6CC2C 8024012C 00621821 */  addu      $v1, $v1, $v0
/* A6CC30 80240130 04610004 */  bgez      $v1, .L80240144
/* A6CC34 80240134 AE0300AC */   sw       $v1, 0xac($s0)
/* A6CC38 80240138 3C020002 */  lui       $v0, 2
/* A6CC3C 8024013C 08090055 */  j         .L80240154
/* A6CC40 80240140 00621021 */   addu     $v0, $v1, $v0
.L80240144:
/* A6CC44 80240144 3C040002 */  lui       $a0, 2
/* A6CC48 80240148 0083102A */  slt       $v0, $a0, $v1
/* A6CC4C 8024014C 10400002 */  beqz      $v0, .L80240158
/* A6CC50 80240150 00641023 */   subu     $v0, $v1, $a0
.L80240154:
/* A6CC54 80240154 AE0200AC */  sw        $v0, 0xac($s0)
.L80240158:
/* A6CC58 80240158 8E0300B0 */  lw        $v1, 0xb0($s0)
/* A6CC5C 8024015C 8E020090 */  lw        $v0, 0x90($s0)
/* A6CC60 80240160 00621821 */  addu      $v1, $v1, $v0
/* A6CC64 80240164 04610004 */  bgez      $v1, .L80240178
/* A6CC68 80240168 AE0300B0 */   sw       $v1, 0xb0($s0)
/* A6CC6C 8024016C 3C020002 */  lui       $v0, 2
/* A6CC70 80240170 08090062 */  j         .L80240188
/* A6CC74 80240174 00621021 */   addu     $v0, $v1, $v0
.L80240178:
/* A6CC78 80240178 3C040002 */  lui       $a0, 2
/* A6CC7C 8024017C 0083102A */  slt       $v0, $a0, $v1
/* A6CC80 80240180 10400002 */  beqz      $v0, .L8024018C
/* A6CC84 80240184 00641023 */   subu     $v0, $v1, $a0
.L80240188:
/* A6CC88 80240188 AE0200B0 */  sw        $v0, 0xb0($s0)
.L8024018C:
/* A6CC8C 8024018C 8E0300B4 */  lw        $v1, 0xb4($s0)
/* A6CC90 80240190 8E020094 */  lw        $v0, 0x94($s0)
/* A6CC94 80240194 00621821 */  addu      $v1, $v1, $v0
/* A6CC98 80240198 04610004 */  bgez      $v1, .L802401AC
/* A6CC9C 8024019C AE0300B4 */   sw       $v1, 0xb4($s0)
/* A6CCA0 802401A0 3C020002 */  lui       $v0, 2
/* A6CCA4 802401A4 0809006F */  j         .L802401BC
/* A6CCA8 802401A8 00621021 */   addu     $v0, $v1, $v0
.L802401AC:
/* A6CCAC 802401AC 3C040002 */  lui       $a0, 2
/* A6CCB0 802401B0 0083102A */  slt       $v0, $a0, $v1
/* A6CCB4 802401B4 10400002 */  beqz      $v0, .L802401C0
/* A6CCB8 802401B8 00641023 */   subu     $v0, $v1, $a0
.L802401BC:
/* A6CCBC 802401BC AE0200B4 */  sw        $v0, 0xb4($s0)
.L802401C0:
/* A6CCC0 802401C0 8E040084 */  lw        $a0, 0x84($s0)
/* A6CCC4 802401C4 0C046F07 */  jal       set_main_pan_u
/* A6CCC8 802401C8 8E0500A8 */   lw       $a1, 0xa8($s0)
/* A6CCCC 802401CC 8E040084 */  lw        $a0, 0x84($s0)
/* A6CCD0 802401D0 0C046F0D */  jal       set_main_pan_v
/* A6CCD4 802401D4 8E0500AC */   lw       $a1, 0xac($s0)
/* A6CCD8 802401D8 8E040084 */  lw        $a0, 0x84($s0)
/* A6CCDC 802401DC 0C046F13 */  jal       set_aux_pan_u
/* A6CCE0 802401E0 8E0500B0 */   lw       $a1, 0xb0($s0)
/* A6CCE4 802401E4 8E040084 */  lw        $a0, 0x84($s0)
/* A6CCE8 802401E8 0C046F19 */  jal       set_aux_pan_v
/* A6CCEC 802401EC 8E0500B4 */   lw       $a1, 0xb4($s0)
/* A6CCF0 802401F0 8FBF0014 */  lw        $ra, 0x14($sp)
/* A6CCF4 802401F4 8FB00010 */  lw        $s0, 0x10($sp)
/* A6CCF8 802401F8 0000102D */  daddu     $v0, $zero, $zero
/* A6CCFC 802401FC 03E00008 */  jr        $ra
/* A6CD00 80240200 27BD0018 */   addiu    $sp, $sp, 0x18
