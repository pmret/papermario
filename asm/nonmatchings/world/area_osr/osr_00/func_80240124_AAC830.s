.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240124_AAC954
/* AAC954 80240124 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AAC958 80240128 AFB00010 */  sw        $s0, 0x10($sp)
/* AAC95C 8024012C 0080802D */  daddu     $s0, $a0, $zero
/* AAC960 80240130 10A00005 */  beqz      $a1, .L80240148
/* AAC964 80240134 AFBF0014 */   sw       $ra, 0x14($sp)
/* AAC968 80240138 AE000070 */  sw        $zero, 0x70($s0)
/* AAC96C 8024013C AE000074 */  sw        $zero, 0x74($s0)
/* AAC970 80240140 AE000078 */  sw        $zero, 0x78($s0)
/* AAC974 80240144 AE00007C */  sw        $zero, 0x7c($s0)
.L80240148:
/* AAC978 80240148 8E020070 */  lw        $v0, 0x70($s0)
/* AAC97C 8024014C 1440000E */  bnez      $v0, .L80240188
/* AAC980 80240150 00000000 */   nop      
/* AAC984 80240154 8E0300A8 */  lw        $v1, 0xa8($s0)
/* AAC988 80240158 8E020088 */  lw        $v0, 0x88($s0)
/* AAC98C 8024015C 00621821 */  addu      $v1, $v1, $v0
/* AAC990 80240160 04610004 */  bgez      $v1, .L80240174
/* AAC994 80240164 AE0300A8 */   sw       $v1, 0xa8($s0)
/* AAC998 80240168 3C020002 */  lui       $v0, 2
/* AAC99C 8024016C 08090061 */  j         .L80240184
/* AAC9A0 80240170 00621021 */   addu     $v0, $v1, $v0
.L80240174:
/* AAC9A4 80240174 3C040002 */  lui       $a0, 2
/* AAC9A8 80240178 0083102A */  slt       $v0, $a0, $v1
/* AAC9AC 8024017C 10400002 */  beqz      $v0, .L80240188
/* AAC9B0 80240180 00641023 */   subu     $v0, $v1, $a0
.L80240184:
/* AAC9B4 80240184 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240188:
/* AAC9B8 80240188 8E020074 */  lw        $v0, 0x74($s0)
/* AAC9BC 8024018C 1440000E */  bnez      $v0, .L802401C8
/* AAC9C0 80240190 00000000 */   nop      
/* AAC9C4 80240194 8E0300AC */  lw        $v1, 0xac($s0)
/* AAC9C8 80240198 8E02008C */  lw        $v0, 0x8c($s0)
/* AAC9CC 8024019C 00621821 */  addu      $v1, $v1, $v0
/* AAC9D0 802401A0 04610004 */  bgez      $v1, .L802401B4
/* AAC9D4 802401A4 AE0300AC */   sw       $v1, 0xac($s0)
/* AAC9D8 802401A8 3C020002 */  lui       $v0, 2
/* AAC9DC 802401AC 08090071 */  j         .L802401C4
/* AAC9E0 802401B0 00621021 */   addu     $v0, $v1, $v0
.L802401B4:
/* AAC9E4 802401B4 3C040002 */  lui       $a0, 2
/* AAC9E8 802401B8 0083102A */  slt       $v0, $a0, $v1
/* AAC9EC 802401BC 10400002 */  beqz      $v0, .L802401C8
/* AAC9F0 802401C0 00641023 */   subu     $v0, $v1, $a0
.L802401C4:
/* AAC9F4 802401C4 AE0200AC */  sw        $v0, 0xac($s0)
.L802401C8:
/* AAC9F8 802401C8 8E020078 */  lw        $v0, 0x78($s0)
/* AAC9FC 802401CC 1440000E */  bnez      $v0, .L80240208
/* AACA00 802401D0 00000000 */   nop      
/* AACA04 802401D4 8E0300B0 */  lw        $v1, 0xb0($s0)
/* AACA08 802401D8 8E020090 */  lw        $v0, 0x90($s0)
/* AACA0C 802401DC 00621821 */  addu      $v1, $v1, $v0
/* AACA10 802401E0 04610004 */  bgez      $v1, .L802401F4
/* AACA14 802401E4 AE0300B0 */   sw       $v1, 0xb0($s0)
/* AACA18 802401E8 3C020002 */  lui       $v0, 2
/* AACA1C 802401EC 08090081 */  j         .L80240204
/* AACA20 802401F0 00621021 */   addu     $v0, $v1, $v0
.L802401F4:
/* AACA24 802401F4 3C040002 */  lui       $a0, 2
/* AACA28 802401F8 0083102A */  slt       $v0, $a0, $v1
/* AACA2C 802401FC 10400002 */  beqz      $v0, .L80240208
/* AACA30 80240200 00641023 */   subu     $v0, $v1, $a0
.L80240204:
/* AACA34 80240204 AE0200B0 */  sw        $v0, 0xb0($s0)
.L80240208:
/* AACA38 80240208 8E02007C */  lw        $v0, 0x7c($s0)
/* AACA3C 8024020C 1440000E */  bnez      $v0, .L80240248
/* AACA40 80240210 00000000 */   nop      
/* AACA44 80240214 8E0300B4 */  lw        $v1, 0xb4($s0)
/* AACA48 80240218 8E020094 */  lw        $v0, 0x94($s0)
/* AACA4C 8024021C 00621821 */  addu      $v1, $v1, $v0
/* AACA50 80240220 04610004 */  bgez      $v1, .L80240234
/* AACA54 80240224 AE0300B4 */   sw       $v1, 0xb4($s0)
/* AACA58 80240228 3C020002 */  lui       $v0, 2
/* AACA5C 8024022C 08090091 */  j         .L80240244
/* AACA60 80240230 00621021 */   addu     $v0, $v1, $v0
.L80240234:
/* AACA64 80240234 3C040002 */  lui       $a0, 2
/* AACA68 80240238 0083102A */  slt       $v0, $a0, $v1
/* AACA6C 8024023C 10400002 */  beqz      $v0, .L80240248
/* AACA70 80240240 00641023 */   subu     $v0, $v1, $a0
.L80240244:
/* AACA74 80240244 AE0200B4 */  sw        $v0, 0xb4($s0)
.L80240248:
/* AACA78 80240248 8E040084 */  lw        $a0, 0x84($s0)
/* AACA7C 8024024C 0C046F07 */  jal       set_main_pan_u
/* AACA80 80240250 8E0500A8 */   lw       $a1, 0xa8($s0)
/* AACA84 80240254 8E040084 */  lw        $a0, 0x84($s0)
/* AACA88 80240258 0C046F0D */  jal       set_main_pan_v
/* AACA8C 8024025C 8E0500AC */   lw       $a1, 0xac($s0)
/* AACA90 80240260 8E040084 */  lw        $a0, 0x84($s0)
/* AACA94 80240264 0C046F13 */  jal       set_aux_pan_u
/* AACA98 80240268 8E0500B0 */   lw       $a1, 0xb0($s0)
/* AACA9C 8024026C 8E040084 */  lw        $a0, 0x84($s0)
/* AACAA0 80240270 0C046F19 */  jal       set_aux_pan_v
/* AACAA4 80240274 8E0500B4 */   lw       $a1, 0xb4($s0)
/* AACAA8 80240278 8E020070 */  lw        $v0, 0x70($s0)
/* AACAAC 8024027C 8E030078 */  lw        $v1, 0x78($s0)
/* AACAB0 80240280 8E040098 */  lw        $a0, 0x98($s0)
/* AACAB4 80240284 24420001 */  addiu     $v0, $v0, 1
/* AACAB8 80240288 AE020070 */  sw        $v0, 0x70($s0)
/* AACABC 8024028C 8E020074 */  lw        $v0, 0x74($s0)
/* AACAC0 80240290 24630001 */  addiu     $v1, $v1, 1
/* AACAC4 80240294 AE030078 */  sw        $v1, 0x78($s0)
/* AACAC8 80240298 8E030070 */  lw        $v1, 0x70($s0)
/* AACACC 8024029C 24420001 */  addiu     $v0, $v0, 1
/* AACAD0 802402A0 AE020074 */  sw        $v0, 0x74($s0)
/* AACAD4 802402A4 8E02007C */  lw        $v0, 0x7c($s0)
/* AACAD8 802402A8 0064182A */  slt       $v1, $v1, $a0
/* AACADC 802402AC 24420001 */  addiu     $v0, $v0, 1
/* AACAE0 802402B0 14600002 */  bnez      $v1, .L802402BC
/* AACAE4 802402B4 AE02007C */   sw       $v0, 0x7c($s0)
/* AACAE8 802402B8 AE000070 */  sw        $zero, 0x70($s0)
.L802402BC:
/* AACAEC 802402BC 8E020074 */  lw        $v0, 0x74($s0)
/* AACAF0 802402C0 8E03009C */  lw        $v1, 0x9c($s0)
/* AACAF4 802402C4 0043102A */  slt       $v0, $v0, $v1
/* AACAF8 802402C8 50400001 */  beql      $v0, $zero, .L802402D0
/* AACAFC 802402CC AE000074 */   sw       $zero, 0x74($s0)
.L802402D0:
/* AACB00 802402D0 8E020078 */  lw        $v0, 0x78($s0)
/* AACB04 802402D4 8E0300A0 */  lw        $v1, 0xa0($s0)
/* AACB08 802402D8 0043102A */  slt       $v0, $v0, $v1
/* AACB0C 802402DC 50400001 */  beql      $v0, $zero, .L802402E4
/* AACB10 802402E0 AE000078 */   sw       $zero, 0x78($s0)
.L802402E4:
/* AACB14 802402E4 8E02007C */  lw        $v0, 0x7c($s0)
/* AACB18 802402E8 8E0300A4 */  lw        $v1, 0xa4($s0)
/* AACB1C 802402EC 0043102A */  slt       $v0, $v0, $v1
/* AACB20 802402F0 50400001 */  beql      $v0, $zero, .L802402F8
/* AACB24 802402F4 AE00007C */   sw       $zero, 0x7c($s0)
.L802402F8:
/* AACB28 802402F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* AACB2C 802402FC 8FB00010 */  lw        $s0, 0x10($sp)
/* AACB30 80240300 0000102D */  daddu     $v0, $zero, $zero
/* AACB34 80240304 03E00008 */  jr        $ra
/* AACB38 80240308 27BD0018 */   addiu    $sp, $sp, 0x18
