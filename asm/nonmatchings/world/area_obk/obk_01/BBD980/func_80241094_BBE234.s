.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241094_BBE234
/* BBE234 80241094 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BBE238 80241098 AFB10014 */  sw        $s1, 0x14($sp)
/* BBE23C 8024109C 0080882D */  daddu     $s1, $a0, $zero
/* BBE240 802410A0 AFBF0018 */  sw        $ra, 0x18($sp)
/* BBE244 802410A4 AFB00010 */  sw        $s0, 0x10($sp)
/* BBE248 802410A8 8E240088 */  lw        $a0, 0x88($s1)
/* BBE24C 802410AC 1480000B */  bnez      $a0, .L802410DC
/* BBE250 802410B0 8E300084 */   lw       $s0, 0x84($s1)
/* BBE254 802410B4 0C00A67F */  jal       rand_int
/* BBE258 802410B8 24040003 */   addiu    $a0, $zero, 3
/* BBE25C 802410BC 00021040 */  sll       $v0, $v0, 1
/* BBE260 802410C0 3C018024 */  lui       $at, %hi(D_80244A54)
/* BBE264 802410C4 00220821 */  addu      $at, $at, $v0
/* BBE268 802410C8 84224A54 */  lh        $v0, %lo(D_80244A54)($at)
/* BBE26C 802410CC 24040032 */  addiu     $a0, $zero, 0x32
/* BBE270 802410D0 0C00A67F */  jal       rand_int
/* BBE274 802410D4 AE220078 */   sw       $v0, 0x78($s1)
/* BBE278 802410D8 2444001E */  addiu     $a0, $v0, 0x1e
.L802410DC:
/* BBE27C 802410DC 8E230078 */  lw        $v1, 0x78($s1)
/* BBE280 802410E0 0203102A */  slt       $v0, $s0, $v1
/* BBE284 802410E4 10400006 */  beqz      $v0, .L80241100
/* BBE288 802410E8 2484FFFF */   addiu    $a0, $a0, -1
/* BBE28C 802410EC 2610000A */  addiu     $s0, $s0, 0xa
/* BBE290 802410F0 0070102A */  slt       $v0, $v1, $s0
/* BBE294 802410F4 5040000A */  beql      $v0, $zero, .L80241120
/* BBE298 802410F8 AE300084 */   sw       $s0, 0x84($s1)
/* BBE29C 802410FC 0060802D */  daddu     $s0, $v1, $zero
.L80241100:
/* BBE2A0 80241100 0070102A */  slt       $v0, $v1, $s0
/* BBE2A4 80241104 50400006 */  beql      $v0, $zero, .L80241120
/* BBE2A8 80241108 AE300084 */   sw       $s0, 0x84($s1)
/* BBE2AC 8024110C 2610FFF6 */  addiu     $s0, $s0, -0xa
/* BBE2B0 80241110 0203102A */  slt       $v0, $s0, $v1
/* BBE2B4 80241114 54400001 */  bnel      $v0, $zero, .L8024111C
/* BBE2B8 80241118 0060802D */   daddu    $s0, $v1, $zero
.L8024111C:
/* BBE2BC 8024111C AE300084 */  sw        $s0, 0x84($s1)
.L80241120:
/* BBE2C0 80241120 AE240088 */  sw        $a0, 0x88($s1)
/* BBE2C4 80241124 8FBF0018 */  lw        $ra, 0x18($sp)
/* BBE2C8 80241128 8FB10014 */  lw        $s1, 0x14($sp)
/* BBE2CC 8024112C 8FB00010 */  lw        $s0, 0x10($sp)
/* BBE2D0 80241130 24020002 */  addiu     $v0, $zero, 2
/* BBE2D4 80241134 03E00008 */  jr        $ra
/* BBE2D8 80241138 27BD0020 */   addiu    $sp, $sp, 0x20
/* BBE2DC 8024113C 00000000 */  nop       
