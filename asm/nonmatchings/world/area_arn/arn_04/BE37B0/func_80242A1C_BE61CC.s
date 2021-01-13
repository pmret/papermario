.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A1C_BE61CC
/* BE61CC 80242A1C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BE61D0 80242A20 AFB30024 */  sw        $s3, 0x24($sp)
/* BE61D4 80242A24 0080982D */  daddu     $s3, $a0, $zero
/* BE61D8 80242A28 AFBF002C */  sw        $ra, 0x2c($sp)
/* BE61DC 80242A2C AFB40028 */  sw        $s4, 0x28($sp)
/* BE61E0 80242A30 AFB20020 */  sw        $s2, 0x20($sp)
/* BE61E4 80242A34 AFB1001C */  sw        $s1, 0x1c($sp)
/* BE61E8 80242A38 AFB00018 */  sw        $s0, 0x18($sp)
/* BE61EC 80242A3C 8E710148 */  lw        $s1, 0x148($s3)
/* BE61F0 80242A40 86240008 */  lh        $a0, 8($s1)
/* BE61F4 80242A44 0C00EABB */  jal       get_npc_unsafe
/* BE61F8 80242A48 00A0A02D */   daddu    $s4, $a1, $zero
/* BE61FC 80242A4C 0040802D */  daddu     $s0, $v0, $zero
/* BE6200 80242A50 3C12800F */  lui       $s2, %hi(gPlayerStatusPtr)
/* BE6204 80242A54 26527B30 */  addiu     $s2, $s2, %lo(gPlayerStatusPtr)
/* BE6208 80242A58 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BE620C 80242A5C 8E420000 */  lw        $v0, ($s2)
/* BE6210 80242A60 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BE6214 80242A64 8C460028 */  lw        $a2, 0x28($v0)
/* BE6218 80242A68 0C00A720 */  jal       atan2
/* BE621C 80242A6C 8C470030 */   lw       $a3, 0x30($v0)
/* BE6220 80242A70 3C025555 */  lui       $v0, 0x5555
/* BE6224 80242A74 9603008E */  lhu       $v1, 0x8e($s0)
/* BE6228 80242A78 34425556 */  ori       $v0, $v0, 0x5556
/* BE622C 80242A7C 00031C00 */  sll       $v1, $v1, 0x10
/* BE6230 80242A80 00032403 */  sra       $a0, $v1, 0x10
/* BE6234 80242A84 00820018 */  mult      $a0, $v0
/* BE6238 80242A88 00031FC3 */  sra       $v1, $v1, 0x1f
/* BE623C 80242A8C 00004010 */  mfhi      $t0
/* BE6240 80242A90 01031823 */  subu      $v1, $t0, $v1
/* BE6244 80242A94 00031040 */  sll       $v0, $v1, 1
/* BE6248 80242A98 00431021 */  addu      $v0, $v0, $v1
/* BE624C 80242A9C 00822023 */  subu      $a0, $a0, $v0
/* BE6250 80242AA0 00042400 */  sll       $a0, $a0, 0x10
/* BE6254 80242AA4 1480000C */  bnez      $a0, .L80242AD8
/* BE6258 80242AA8 E600000C */   swc1     $f0, 0xc($s0)
/* BE625C 80242AAC C6020040 */  lwc1      $f2, 0x40($s0)
/* BE6260 80242AB0 3C014000 */  lui       $at, 0x4000
/* BE6264 80242AB4 44810000 */  mtc1      $at, $f0
/* BE6268 80242AB8 AFA00010 */  sw        $zero, 0x10($sp)
/* BE626C 80242ABC AFA00014 */  sw        $zero, 0x14($sp)
/* BE6270 80242AC0 46001080 */  add.s     $f2, $f2, $f0
/* BE6274 80242AC4 8E06003C */  lw        $a2, 0x3c($s0)
/* BE6278 80242AC8 8E050038 */  lw        $a1, 0x38($s0)
/* BE627C 80242ACC 44071000 */  mfc1      $a3, $f2
/* BE6280 80242AD0 0C01BECC */  jal       fx_walk_normal
/* BE6284 80242AD4 24040002 */   addiu    $a0, $zero, 2
.L80242AD8:
/* BE6288 80242AD8 9602008E */  lhu       $v0, 0x8e($s0)
/* BE628C 80242ADC 2442FFFF */  addiu     $v0, $v0, -1
/* BE6290 80242AE0 A602008E */  sh        $v0, 0x8e($s0)
/* BE6294 80242AE4 00021400 */  sll       $v0, $v0, 0x10
/* BE6298 80242AE8 1C40002C */  bgtz      $v0, .L80242B9C
/* BE629C 80242AEC 00000000 */   nop
/* BE62A0 80242AF0 C6000038 */  lwc1      $f0, 0x38($s0)
/* BE62A4 80242AF4 4600010D */  trunc.w.s $f4, $f0
/* BE62A8 80242AF8 44022000 */  mfc1      $v0, $f4
/* BE62AC 80242AFC 00000000 */  nop
/* BE62B0 80242B00 A6220010 */  sh        $v0, 0x10($s1)
/* BE62B4 80242B04 C600003C */  lwc1      $f0, 0x3c($s0)
/* BE62B8 80242B08 4600010D */  trunc.w.s $f4, $f0
/* BE62BC 80242B0C 44022000 */  mfc1      $v0, $f4
/* BE62C0 80242B10 00000000 */  nop
/* BE62C4 80242B14 A6220012 */  sh        $v0, 0x12($s1)
/* BE62C8 80242B18 C6000040 */  lwc1      $f0, 0x40($s0)
/* BE62CC 80242B1C 24020001 */  addiu     $v0, $zero, 1
/* BE62D0 80242B20 A2220007 */  sb        $v0, 7($s1)
/* BE62D4 80242B24 4600010D */  trunc.w.s $f4, $f0
/* BE62D8 80242B28 44022000 */  mfc1      $v0, $f4
/* BE62DC 80242B2C 00000000 */  nop
/* BE62E0 80242B30 A6220014 */  sh        $v0, 0x14($s1)
/* BE62E4 80242B34 C6800018 */  lwc1      $f0, 0x18($s4)
/* BE62E8 80242B38 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BE62EC 80242B3C C60E0040 */  lwc1      $f14, 0x40($s0)
/* BE62F0 80242B40 8E420000 */  lw        $v0, ($s2)
/* BE62F4 80242B44 E6000018 */  swc1      $f0, 0x18($s0)
/* BE62F8 80242B48 8C460028 */  lw        $a2, 0x28($v0)
/* BE62FC 80242B4C 0C00A7B5 */  jal       dist2D
/* BE6300 80242B50 8C470030 */   lw       $a3, 0x30($v0)
/* BE6304 80242B54 C6020018 */  lwc1      $f2, 0x18($s0)
/* BE6308 80242B58 46020003 */  div.s     $f0, $f0, $f2
/* BE630C 80242B5C 3C018024 */  lui       $at, %hi(D_80244340)
/* BE6310 80242B60 D4224340 */  ldc1      $f2, %lo(D_80244340)($at)
/* BE6314 80242B64 46000021 */  cvt.d.s   $f0, $f0
/* BE6318 80242B68 46220000 */  add.d     $f0, $f0, $f2
/* BE631C 80242B6C 4620010D */  trunc.w.d $f4, $f0
/* BE6320 80242B70 44022000 */  mfc1      $v0, $f4
/* BE6324 80242B74 00000000 */  nop
/* BE6328 80242B78 A602008E */  sh        $v0, 0x8e($s0)
/* BE632C 80242B7C 00021400 */  sll       $v0, $v0, 0x10
/* BE6330 80242B80 00021403 */  sra       $v0, $v0, 0x10
/* BE6334 80242B84 2842000F */  slti      $v0, $v0, 0xf
/* BE6338 80242B88 10400002 */  beqz      $v0, .L80242B94
/* BE633C 80242B8C 2402000F */   addiu    $v0, $zero, 0xf
/* BE6340 80242B90 A602008E */  sh        $v0, 0x8e($s0)
.L80242B94:
/* BE6344 80242B94 24020016 */  addiu     $v0, $zero, 0x16
/* BE6348 80242B98 AE620070 */  sw        $v0, 0x70($s3)
.L80242B9C:
/* BE634C 80242B9C 8FBF002C */  lw        $ra, 0x2c($sp)
/* BE6350 80242BA0 8FB40028 */  lw        $s4, 0x28($sp)
/* BE6354 80242BA4 8FB30024 */  lw        $s3, 0x24($sp)
/* BE6358 80242BA8 8FB20020 */  lw        $s2, 0x20($sp)
/* BE635C 80242BAC 8FB1001C */  lw        $s1, 0x1c($sp)
/* BE6360 80242BB0 8FB00018 */  lw        $s0, 0x18($sp)
/* BE6364 80242BB4 03E00008 */  jr        $ra
/* BE6368 80242BB8 27BD0030 */   addiu    $sp, $sp, 0x30
