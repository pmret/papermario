.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024116C_BD49DC
/* BD49DC 8024116C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BD49E0 80241170 AFB10014 */  sw        $s1, 0x14($sp)
/* BD49E4 80241174 0080882D */  daddu     $s1, $a0, $zero
/* BD49E8 80241178 AFBF0018 */  sw        $ra, 0x18($sp)
/* BD49EC 8024117C AFB00010 */  sw        $s0, 0x10($sp)
/* BD49F0 80241180 8E240088 */  lw        $a0, 0x88($s1)
/* BD49F4 80241184 1480000B */  bnez      $a0, .L802411B4
/* BD49F8 80241188 8E300084 */   lw       $s0, 0x84($s1)
/* BD49FC 8024118C 0C00A67F */  jal       rand_int
/* BD4A00 80241190 24040003 */   addiu    $a0, $zero, 3
/* BD4A04 80241194 00021040 */  sll       $v0, $v0, 1
/* BD4A08 80241198 3C018024 */  lui       $at, %hi(D_80244FEC_BD885C)
/* BD4A0C 8024119C 00220821 */  addu      $at, $at, $v0
/* BD4A10 802411A0 84224FEC */  lh        $v0, %lo(D_80244FEC_BD885C)($at)
/* BD4A14 802411A4 24040032 */  addiu     $a0, $zero, 0x32
/* BD4A18 802411A8 0C00A67F */  jal       rand_int
/* BD4A1C 802411AC AE220078 */   sw       $v0, 0x78($s1)
/* BD4A20 802411B0 2444001E */  addiu     $a0, $v0, 0x1e
.L802411B4:
/* BD4A24 802411B4 8E230078 */  lw        $v1, 0x78($s1)
/* BD4A28 802411B8 0203102A */  slt       $v0, $s0, $v1
/* BD4A2C 802411BC 10400006 */  beqz      $v0, .L802411D8
/* BD4A30 802411C0 2484FFFF */   addiu    $a0, $a0, -1
/* BD4A34 802411C4 2610000A */  addiu     $s0, $s0, 0xa
/* BD4A38 802411C8 0070102A */  slt       $v0, $v1, $s0
/* BD4A3C 802411CC 5040000A */  beql      $v0, $zero, .L802411F8
/* BD4A40 802411D0 AE300084 */   sw       $s0, 0x84($s1)
/* BD4A44 802411D4 0060802D */  daddu     $s0, $v1, $zero
.L802411D8:
/* BD4A48 802411D8 0070102A */  slt       $v0, $v1, $s0
/* BD4A4C 802411DC 50400006 */  beql      $v0, $zero, .L802411F8
/* BD4A50 802411E0 AE300084 */   sw       $s0, 0x84($s1)
/* BD4A54 802411E4 2610FFF6 */  addiu     $s0, $s0, -0xa
/* BD4A58 802411E8 0203102A */  slt       $v0, $s0, $v1
/* BD4A5C 802411EC 54400001 */  bnel      $v0, $zero, .L802411F4
/* BD4A60 802411F0 0060802D */   daddu    $s0, $v1, $zero
.L802411F4:
/* BD4A64 802411F4 AE300084 */  sw        $s0, 0x84($s1)
.L802411F8:
/* BD4A68 802411F8 AE240088 */  sw        $a0, 0x88($s1)
/* BD4A6C 802411FC 8FBF0018 */  lw        $ra, 0x18($sp)
/* BD4A70 80241200 8FB10014 */  lw        $s1, 0x14($sp)
/* BD4A74 80241204 8FB00010 */  lw        $s0, 0x10($sp)
/* BD4A78 80241208 24020002 */  addiu     $v0, $zero, 2
/* BD4A7C 8024120C 03E00008 */  jr        $ra
/* BD4A80 80241210 27BD0020 */   addiu    $sp, $sp, 0x20
/* BD4A84 80241214 00000000 */  nop
/* BD4A88 80241218 00000000 */  nop
/* BD4A8C 8024121C 00000000 */  nop
