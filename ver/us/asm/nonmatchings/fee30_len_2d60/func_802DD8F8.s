.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802DD8F8
/* 1009E8 802DD8F8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1009EC 802DD8FC AFB10014 */  sw        $s1, 0x14($sp)
/* 1009F0 802DD900 0080882D */  daddu     $s1, $a0, $zero
/* 1009F4 802DD904 3C048035 */  lui       $a0, %hi(gSpriteHeapPtr)
/* 1009F8 802DD908 2484F800 */  addiu     $a0, $a0, %lo(gSpriteHeapPtr)
/* 1009FC 802DD90C AFBF0018 */  sw        $ra, 0x18($sp)
/* 100A00 802DD910 AFB00010 */  sw        $s0, 0x10($sp)
/* 100A04 802DD914 3C01802E */  lui       $at, %hi(D_802DF524)
/* 100A08 802DD918 AC20F524 */  sw        $zero, %lo(D_802DF524)($at)
/* 100A0C 802DD91C 0C00A40C */  jal       _heap_create
/* 100A10 802DD920 3C050004 */   lui      $a1, 4
/* 100A14 802DD924 0C04E8DF */  jal       func_8013A37C
/* 100A18 802DD928 2410000C */   addiu    $s0, $zero, 0xc
/* 100A1C 802DD92C 3C02802E */  lui       $v0, %hi(D_802DF578)
/* 100A20 802DD930 2442F578 */  addiu     $v0, $v0, %lo(D_802DF578)
.L802DD934:
/* 100A24 802DD934 AC400000 */  sw        $zero, ($v0)
/* 100A28 802DD938 2610FFFF */  addiu     $s0, $s0, -1
/* 100A2C 802DD93C 0601FFFD */  bgez      $s0, .L802DD934
/* 100A30 802DD940 2442FFFC */   addiu    $v0, $v0, -4
/* 100A34 802DD944 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 100A38 802DD948 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 100A3C 802DD94C 3C01802E */  lui       $at, %hi(D_802DF580)
/* 100A40 802DD950 AC20F580 */  sw        $zero, %lo(D_802DF580)($at)
/* 100A44 802DD954 9042007E */  lbu       $v0, 0x7e($v0)
/* 100A48 802DD958 30420001 */  andi      $v0, $v0, 1
/* 100A4C 802DD95C 54400001 */  bnel      $v0, $zero, .L802DD964
/* 100A50 802DD960 24110004 */   addiu    $s1, $zero, 4
.L802DD964:
/* 100A54 802DD964 24100001 */  addiu     $s0, $zero, 1
/* 100A58 802DD968 3C03802E */  lui       $v1, %hi(D_802DF4C4)
/* 100A5C 802DD96C 2463F4C4 */  addiu     $v1, $v1, %lo(D_802DF4C4)
/* 100A60 802DD970 02111004 */  sllv      $v0, $s1, $s0
/* 100A64 802DD974 00511021 */  addu      $v0, $v0, $s1
/* 100A68 802DD978 00021080 */  sll       $v0, $v0, 2
/* 100A6C 802DD97C 00431021 */  addu      $v0, $v0, $v1
/* 100A70 802DD980 8C440000 */  lw        $a0, ($v0)
/* 100A74 802DD984 8C450004 */  lw        $a1, 4($v0)
/* 100A78 802DD988 0C0B7B58 */  jal       func_802DED60
/* 100A7C 802DD98C 8C510008 */   lw       $s1, 8($v0)
/* 100A80 802DD990 02111007 */  srav      $v0, $s1, $s0
.L802DD994:
/* 100A84 802DD994 30420001 */  andi      $v0, $v0, 1
/* 100A88 802DD998 50400004 */  beql      $v0, $zero, .L802DD9AC
/* 100A8C 802DD99C 26100001 */   addiu    $s0, $s0, 1
/* 100A90 802DD9A0 0C0B7627 */  jal       func_802DD89C
/* 100A94 802DD9A4 0200202D */   daddu    $a0, $s0, $zero
/* 100A98 802DD9A8 26100001 */  addiu     $s0, $s0, 1
.L802DD9AC:
/* 100A9C 802DD9AC 2A02000E */  slti      $v0, $s0, 0xe
/* 100AA0 802DD9B0 1440FFF8 */  bnez      $v0, .L802DD994
/* 100AA4 802DD9B4 02111007 */   srav     $v0, $s1, $s0
/* 100AA8 802DD9B8 0000802D */  daddu     $s0, $zero, $zero
/* 100AAC 802DD9BC 2404FFFF */  addiu     $a0, $zero, -1
/* 100AB0 802DD9C0 3C03802E */  lui       $v1, %hi(D_802DF588)
/* 100AB4 802DD9C4 2463F588 */  addiu     $v1, $v1, %lo(D_802DF588)
.L802DD9C8:
/* 100AB8 802DD9C8 AC600000 */  sw        $zero, ($v1)
/* 100ABC 802DD9CC AC640004 */  sw        $a0, 4($v1)
/* 100AC0 802DD9D0 26100001 */  addiu     $s0, $s0, 1
/* 100AC4 802DD9D4 2A020003 */  slti      $v0, $s0, 3
/* 100AC8 802DD9D8 1440FFFB */  bnez      $v0, .L802DD9C8
/* 100ACC 802DD9DC 2463000C */   addiu    $v1, $v1, 0xc
/* 100AD0 802DD9E0 0000802D */  daddu     $s0, $zero, $zero
/* 100AD4 802DD9E4 3C04802E */  lui       $a0, %hi(D_802DF958)
/* 100AD8 802DD9E8 2484F958 */  addiu     $a0, $a0, %lo(D_802DF958)
/* 100ADC 802DD9EC 3C03802E */  lui       $v1, %hi(D_802DF5B0)
/* 100AE0 802DD9F0 2463F5B0 */  addiu     $v1, $v1, %lo(D_802DF5B0)
.L802DD9F4:
/* 100AE4 802DD9F4 AC600000 */  sw        $zero, ($v1)
/* 100AE8 802DD9F8 02041021 */  addu      $v0, $s0, $a0
/* 100AEC 802DD9FC 26100001 */  addiu     $s0, $s0, 1
/* 100AF0 802DDA00 A0400000 */  sb        $zero, ($v0)
/* 100AF4 802DDA04 2A0200EA */  slti      $v0, $s0, 0xea
/* 100AF8 802DDA08 1440FFFA */  bnez      $v0, .L802DD9F4
/* 100AFC 802DDA0C 24630004 */   addiu    $v1, $v1, 4
/* 100B00 802DDA10 0000802D */  daddu     $s0, $zero, $zero
/* 100B04 802DDA14 2404FFFF */  addiu     $a0, $zero, -1
/* 100B08 802DDA18 3C03802E */  lui       $v1, %hi(D_802DFA48)
/* 100B0C 802DDA1C 2463FA48 */  addiu     $v1, $v1, %lo(D_802DFA48)
.L802DDA20:
/* 100B10 802DDA20 AC600000 */  sw        $zero, ($v1)
/* 100B14 802DDA24 AC600004 */  sw        $zero, 4($v1)
/* 100B18 802DDA28 AC600008 */  sw        $zero, 8($v1)
/* 100B1C 802DDA2C AC64000C */  sw        $a0, 0xc($v1)
/* 100B20 802DDA30 AC600010 */  sw        $zero, 0x10($v1)
/* 100B24 802DDA34 26100001 */  addiu     $s0, $s0, 1
/* 100B28 802DDA38 2A020033 */  slti      $v0, $s0, 0x33
/* 100B2C 802DDA3C 1440FFF8 */  bnez      $v0, .L802DDA20
/* 100B30 802DDA40 24630014 */   addiu    $v1, $v1, 0x14
/* 100B34 802DDA44 0C0B6F50 */  jal       func_802DBD40
/* 100B38 802DDA48 00000000 */   nop
/* 100B3C 802DDA4C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 100B40 802DDA50 8FB10014 */  lw        $s1, 0x14($sp)
/* 100B44 802DDA54 8FB00010 */  lw        $s0, 0x10($sp)
/* 100B48 802DDA58 03E00008 */  jr        $ra
/* 100B4C 802DDA5C 27BD0020 */   addiu    $sp, $sp, 0x20
