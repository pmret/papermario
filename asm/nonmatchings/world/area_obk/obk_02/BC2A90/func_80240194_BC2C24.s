.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240194_BC2C24
/* BC2C24 80240194 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BC2C28 80240198 AFB10014 */  sw        $s1, 0x14($sp)
/* BC2C2C 8024019C 0080882D */  daddu     $s1, $a0, $zero
/* BC2C30 802401A0 AFBF0018 */  sw        $ra, 0x18($sp)
/* BC2C34 802401A4 AFB00010 */  sw        $s0, 0x10($sp)
/* BC2C38 802401A8 8E240088 */  lw        $a0, 0x88($s1)
/* BC2C3C 802401AC 1480000B */  bnez      $a0, .L802401DC
/* BC2C40 802401B0 8E300084 */   lw       $s0, 0x84($s1)
/* BC2C44 802401B4 0C00A67F */  jal       rand_int
/* BC2C48 802401B8 24040003 */   addiu    $a0, $zero, 3
/* BC2C4C 802401BC 00021040 */  sll       $v0, $v0, 1
/* BC2C50 802401C0 3C018024 */  lui       $at, %hi(D_80240CBC)
/* BC2C54 802401C4 00220821 */  addu      $at, $at, $v0
/* BC2C58 802401C8 84220CBC */  lh        $v0, %lo(D_80240CBC)($at)
/* BC2C5C 802401CC 24040032 */  addiu     $a0, $zero, 0x32
/* BC2C60 802401D0 0C00A67F */  jal       rand_int
/* BC2C64 802401D4 AE220078 */   sw       $v0, 0x78($s1)
/* BC2C68 802401D8 2444001E */  addiu     $a0, $v0, 0x1e
.L802401DC:
/* BC2C6C 802401DC 8E230078 */  lw        $v1, 0x78($s1)
/* BC2C70 802401E0 0203102A */  slt       $v0, $s0, $v1
/* BC2C74 802401E4 10400006 */  beqz      $v0, .L80240200
/* BC2C78 802401E8 2484FFFF */   addiu    $a0, $a0, -1
/* BC2C7C 802401EC 2610000A */  addiu     $s0, $s0, 0xa
/* BC2C80 802401F0 0070102A */  slt       $v0, $v1, $s0
/* BC2C84 802401F4 5040000A */  beql      $v0, $zero, .L80240220
/* BC2C88 802401F8 AE300084 */   sw       $s0, 0x84($s1)
/* BC2C8C 802401FC 0060802D */  daddu     $s0, $v1, $zero
.L80240200:
/* BC2C90 80240200 0070102A */  slt       $v0, $v1, $s0
/* BC2C94 80240204 50400006 */  beql      $v0, $zero, .L80240220
/* BC2C98 80240208 AE300084 */   sw       $s0, 0x84($s1)
/* BC2C9C 8024020C 2610FFF6 */  addiu     $s0, $s0, -0xa
/* BC2CA0 80240210 0203102A */  slt       $v0, $s0, $v1
/* BC2CA4 80240214 54400001 */  bnel      $v0, $zero, .L8024021C
/* BC2CA8 80240218 0060802D */   daddu    $s0, $v1, $zero
.L8024021C:
/* BC2CAC 8024021C AE300084 */  sw        $s0, 0x84($s1)
.L80240220:
/* BC2CB0 80240220 AE240088 */  sw        $a0, 0x88($s1)
/* BC2CB4 80240224 8FBF0018 */  lw        $ra, 0x18($sp)
/* BC2CB8 80240228 8FB10014 */  lw        $s1, 0x14($sp)
/* BC2CBC 8024022C 8FB00010 */  lw        $s0, 0x10($sp)
/* BC2CC0 80240230 24020002 */  addiu     $v0, $zero, 2
/* BC2CC4 80240234 03E00008 */  jr        $ra
/* BC2CC8 80240238 27BD0020 */   addiu    $sp, $sp, 0x20
/* BC2CCC 8024023C 00000000 */  nop
