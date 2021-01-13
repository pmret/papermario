.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240934_BCD994
/* BCD994 80240934 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BCD998 80240938 AFB10014 */  sw        $s1, 0x14($sp)
/* BCD99C 8024093C 0080882D */  daddu     $s1, $a0, $zero
/* BCD9A0 80240940 AFBF0018 */  sw        $ra, 0x18($sp)
/* BCD9A4 80240944 AFB00010 */  sw        $s0, 0x10($sp)
/* BCD9A8 80240948 8E240088 */  lw        $a0, 0x88($s1)
/* BCD9AC 8024094C 1480000B */  bnez      $a0, .L8024097C
/* BCD9B0 80240950 8E300084 */   lw       $s0, 0x84($s1)
/* BCD9B4 80240954 0C00A67F */  jal       rand_int
/* BCD9B8 80240958 24040003 */   addiu    $a0, $zero, 3
/* BCD9BC 8024095C 00021040 */  sll       $v0, $v0, 1
/* BCD9C0 80240960 3C018024 */  lui       $at, %hi(D_8024100C)
/* BCD9C4 80240964 00220821 */  addu      $at, $at, $v0
/* BCD9C8 80240968 8422100C */  lh        $v0, %lo(D_8024100C)($at)
/* BCD9CC 8024096C 24040032 */  addiu     $a0, $zero, 0x32
/* BCD9D0 80240970 0C00A67F */  jal       rand_int
/* BCD9D4 80240974 AE220078 */   sw       $v0, 0x78($s1)
/* BCD9D8 80240978 2444001E */  addiu     $a0, $v0, 0x1e
.L8024097C:
/* BCD9DC 8024097C 8E230078 */  lw        $v1, 0x78($s1)
/* BCD9E0 80240980 0203102A */  slt       $v0, $s0, $v1
/* BCD9E4 80240984 10400006 */  beqz      $v0, .L802409A0
/* BCD9E8 80240988 2484FFFF */   addiu    $a0, $a0, -1
/* BCD9EC 8024098C 2610000A */  addiu     $s0, $s0, 0xa
/* BCD9F0 80240990 0070102A */  slt       $v0, $v1, $s0
/* BCD9F4 80240994 5040000A */  beql      $v0, $zero, .L802409C0
/* BCD9F8 80240998 AE300084 */   sw       $s0, 0x84($s1)
/* BCD9FC 8024099C 0060802D */  daddu     $s0, $v1, $zero
.L802409A0:
/* BCDA00 802409A0 0070102A */  slt       $v0, $v1, $s0
/* BCDA04 802409A4 50400006 */  beql      $v0, $zero, .L802409C0
/* BCDA08 802409A8 AE300084 */   sw       $s0, 0x84($s1)
/* BCDA0C 802409AC 2610FFF6 */  addiu     $s0, $s0, -0xa
/* BCDA10 802409B0 0203102A */  slt       $v0, $s0, $v1
/* BCDA14 802409B4 54400001 */  bnel      $v0, $zero, .L802409BC
/* BCDA18 802409B8 0060802D */   daddu    $s0, $v1, $zero
.L802409BC:
/* BCDA1C 802409BC AE300084 */  sw        $s0, 0x84($s1)
.L802409C0:
/* BCDA20 802409C0 AE240088 */  sw        $a0, 0x88($s1)
/* BCDA24 802409C4 8FBF0018 */  lw        $ra, 0x18($sp)
/* BCDA28 802409C8 8FB10014 */  lw        $s1, 0x14($sp)
/* BCDA2C 802409CC 8FB00010 */  lw        $s0, 0x10($sp)
/* BCDA30 802409D0 24020002 */  addiu     $v0, $zero, 2
/* BCDA34 802409D4 03E00008 */  jr        $ra
/* BCDA38 802409D8 27BD0020 */   addiu    $sp, $sp, 0x20
/* BCDA3C 802409DC 00000000 */  nop
