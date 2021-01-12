.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401CC_EC9ECC
/* EC9ECC 802401CC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* EC9ED0 802401D0 AFB5002C */  sw        $s5, 0x2c($sp)
/* EC9ED4 802401D4 0080A82D */  daddu     $s5, $a0, $zero
/* EC9ED8 802401D8 AFBE0038 */  sw        $fp, 0x38($sp)
/* EC9EDC 802401DC 3C1E8011 */  lui       $fp, %hi(D_80117840)
/* EC9EE0 802401E0 27DE7840 */  addiu     $fp, $fp, %lo(D_80117840)
/* EC9EE4 802401E4 AFBF003C */  sw        $ra, 0x3c($sp)
/* EC9EE8 802401E8 AFB70034 */  sw        $s7, 0x34($sp)
/* EC9EEC 802401EC AFB60030 */  sw        $s6, 0x30($sp)
/* EC9EF0 802401F0 AFB40028 */  sw        $s4, 0x28($sp)
/* EC9EF4 802401F4 AFB30024 */  sw        $s3, 0x24($sp)
/* EC9EF8 802401F8 AFB20020 */  sw        $s2, 0x20($sp)
/* EC9EFC 802401FC AFB1001C */  sw        $s1, 0x1c($sp)
/* EC9F00 80240200 10A0004F */  beqz      $a1, .L80240340
/* EC9F04 80240204 AFB00018 */   sw       $s0, 0x18($sp)
/* EC9F08 80240208 0C00AFF5 */  jal       func_8002BFD4
/* EC9F0C 8024020C 24040330 */   addiu    $a0, $zero, 0x330
/* EC9F10 80240210 0040982D */  daddu     $s3, $v0, $zero
/* EC9F14 80240214 0000B02D */  daddu     $s6, $zero, $zero
/* EC9F18 80240218 02C0902D */  daddu     $s2, $s6, $zero
/* EC9F1C 8024021C 3C148024 */  lui       $s4, %hi(func_80241FE8_D3C5B8)
/* EC9F20 80240220 26941FE8 */  addiu     $s4, $s4, %lo(func_80241FE8_D3C5B8)
/* EC9F24 80240224 0260882D */  daddu     $s1, $s3, $zero
/* EC9F28 80240228 8EA200B4 */  lw        $v0, 0xb4($s5)
/* EC9F2C 8024022C 3C038024 */  lui       $v1, %hi(D_80241FE0)
/* EC9F30 80240230 24631FE0 */  addiu     $v1, $v1, %lo(D_80241FE0)
/* EC9F34 80240234 AEB30078 */  sw        $s3, 0x78($s5)
/* EC9F38 80240238 00021027 */  nor       $v0, $zero, $v0
/* EC9F3C 8024023C 0002BFC2 */  srl       $s7, $v0, 0x1f
/* EC9F40 80240240 00171080 */  sll       $v0, $s7, 2
/* EC9F44 80240244 00431021 */  addu      $v0, $v0, $v1
/* EC9F48 80240248 AFA20010 */  sw        $v0, 0x10($sp)
.L8024024C:
/* EC9F4C 8024024C 86900000 */  lh        $s0, ($s4)
/* EC9F50 80240250 001010C0 */  sll       $v0, $s0, 3
/* EC9F54 80240254 03C21021 */  addu      $v0, $fp, $v0
/* EC9F58 80240258 90420014 */  lbu       $v0, 0x14($v0)
/* EC9F5C 8024025C 5040002E */  beql      $v0, $zero, .L80240318
/* EC9F60 80240260 26520001 */   addiu    $s2, $s2, 1
/* EC9F64 80240264 00101100 */  sll       $v0, $s0, 4
/* EC9F68 80240268 3C068009 */  lui       $a2, %hi(D_80094900)
/* EC9F6C 8024026C 24C64900 */  addiu     $a2, $a2, %lo(D_80094900)
/* EC9F70 80240270 00461021 */  addu      $v0, $v0, $a2
/* EC9F74 80240274 0200202D */  daddu     $a0, $s0, $zero
/* EC9F78 80240278 AE300108 */  sw        $s0, 0x108($s1)
/* EC9F7C 8024027C 8C420000 */  lw        $v0, ($v0)
/* EC9F80 80240280 02E0282D */  daddu     $a1, $s7, $zero
/* EC9F84 80240284 0C090035 */  jal       func_802400D4_EC9DD4
/* EC9F88 80240288 AE220084 */   sw       $v0, 0x84($s1)
/* EC9F8C 8024028C 0040202D */  daddu     $a0, $v0, $zero
/* EC9F90 80240290 04800011 */  bltz      $a0, .L802402D8
/* EC9F94 80240294 00101080 */   sll      $v0, $s0, 2
/* EC9F98 80240298 3C068010 */  lui       $a2, %hi(D_80100060)
/* EC9F9C 8024029C 24C60060 */  addiu     $a2, $a2, %lo(D_80100060)
/* EC9FA0 802402A0 00461021 */  addu      $v0, $v0, $a2
/* EC9FA4 802402A4 8C430000 */  lw        $v1, ($v0)
/* EC9FA8 802402A8 24020001 */  addiu     $v0, $zero, 1
/* EC9FAC 802402AC AE22018C */  sw        $v0, 0x18c($s1)
/* EC9FB0 802402B0 00041080 */  sll       $v0, $a0, 2
/* EC9FB4 802402B4 3C068024 */  lui       $a2, %hi(func_80241FF8_C41DA8)
/* EC9FB8 802402B8 24C61FF8 */  addiu     $a2, $a2, %lo(func_80241FF8_C41DA8)
/* EC9FBC 802402BC AE230000 */  sw        $v1, ($s1)
/* EC9FC0 802402C0 001218C0 */  sll       $v1, $s2, 3
/* EC9FC4 802402C4 00431021 */  addu      $v0, $v0, $v1
/* EC9FC8 802402C8 00461021 */  addu      $v0, $v0, $a2
/* EC9FCC 802402CC 8C420000 */  lw        $v0, ($v0)
/* EC9FD0 802402D0 080900BF */  j         .L802402FC
/* EC9FD4 802402D4 AE220294 */   sw       $v0, 0x294($s1)
.L802402D8:
/* EC9FD8 802402D8 3C068010 */  lui       $a2, %hi(D_801000A0)
/* EC9FDC 802402DC 24C600A0 */  addiu     $a2, $a2, %lo(D_801000A0)
/* EC9FE0 802402E0 00461021 */  addu      $v0, $v0, $a2
/* EC9FE4 802402E4 8C420000 */  lw        $v0, ($v0)
/* EC9FE8 802402E8 AE20018C */  sw        $zero, 0x18c($s1)
/* EC9FEC 802402EC AE220000 */  sw        $v0, ($s1)
/* EC9FF0 802402F0 8FA60010 */  lw        $a2, 0x10($sp)
/* EC9FF4 802402F4 8CC20000 */  lw        $v0, ($a2)
/* EC9FF8 802402F8 AE220294 */  sw        $v0, 0x294($s1)
.L802402FC:
/* EC9FFC 802402FC 001010C0 */  sll       $v0, $s0, 3
/* ECA000 80240300 03C21021 */  addu      $v0, $fp, $v0
/* ECA004 80240304 80420015 */  lb        $v0, 0x15($v0)
/* ECA008 80240308 26D60001 */  addiu     $s6, $s6, 1
/* ECA00C 8024030C AE220210 */  sw        $v0, 0x210($s1)
/* ECA010 80240310 26310004 */  addiu     $s1, $s1, 4
/* ECA014 80240314 26520001 */  addiu     $s2, $s2, 1
.L80240318:
/* ECA018 80240318 2A420008 */  slti      $v0, $s2, 8
/* ECA01C 8024031C 1440FFCB */  bnez      $v0, .L8024024C
/* ECA020 80240320 26940002 */   addiu    $s4, $s4, 2
/* ECA024 80240324 0260202D */  daddu     $a0, $s3, $zero
/* ECA028 80240328 24020004 */  addiu     $v0, $zero, 4
/* ECA02C 8024032C AC820318 */  sw        $v0, 0x318($a0)
/* ECA030 80240330 AC960324 */  sw        $s6, 0x324($a0)
/* ECA034 80240334 0C03F343 */  jal       func_800FCD0C
/* ECA038 80240338 AC800328 */   sw       $zero, 0x328($a0)
/* ECA03C 8024033C AEA00070 */  sw        $zero, 0x70($s5)
.L80240340:
/* ECA040 80240340 8EA20070 */  lw        $v0, 0x70($s5)
/* ECA044 80240344 8EB30078 */  lw        $s3, 0x78($s5)
/* ECA048 80240348 14400008 */  bnez      $v0, .L8024036C
/* ECA04C 8024034C 24420001 */   addiu    $v0, $v0, 1
/* ECA050 80240350 8662032C */  lh        $v0, 0x32c($s3)
/* ECA054 80240354 10400009 */  beqz      $v0, .L8024037C
/* ECA058 80240358 AEA20074 */   sw       $v0, 0x74($s5)
/* ECA05C 8024035C 0C03E498 */  jal       func_800F9260
/* ECA060 80240360 00000000 */   nop
/* ECA064 80240364 8EA20070 */  lw        $v0, 0x70($s5)
/* ECA068 80240368 24420001 */  addiu     $v0, $v0, 1
.L8024036C:
/* ECA06C 8024036C AEA20070 */  sw        $v0, 0x70($s5)
/* ECA070 80240370 2842000F */  slti      $v0, $v0, 0xf
/* ECA074 80240374 10400003 */  beqz      $v0, .L80240384
/* ECA078 80240378 00000000 */   nop
.L8024037C:
/* ECA07C 8024037C 080900FB */  j         .L802403EC
/* ECA080 80240380 0000102D */   daddu    $v0, $zero, $zero
.L80240384:
/* ECA084 80240384 0C03E4FA */  jal       func_800F93E8
/* ECA088 80240388 00000000 */   nop
/* ECA08C 8024038C 8EA30074 */  lw        $v1, 0x74($s5)
/* ECA090 80240390 240200FF */  addiu     $v0, $zero, 0xff
/* ECA094 80240394 10620010 */  beq       $v1, $v0, .L802403D8
/* ECA098 80240398 2462FFFF */   addiu    $v0, $v1, -1
/* ECA09C 8024039C 00021080 */  sll       $v0, $v0, 2
/* ECA0A0 802403A0 02621021 */  addu      $v0, $s3, $v0
/* ECA0A4 802403A4 8C420108 */  lw        $v0, 0x108($v0)
/* ECA0A8 802403A8 00021100 */  sll       $v0, $v0, 4
/* ECA0AC 802403AC 3C038009 */  lui       $v1, %hi(D_80094900)
/* ECA0B0 802403B0 00621821 */  addu      $v1, $v1, $v0
/* ECA0B4 802403B4 8C634900 */  lw        $v1, %lo(D_80094900)($v1)
/* ECA0B8 802403B8 8EA20074 */  lw        $v0, 0x74($s5)
/* ECA0BC 802403BC 2442FFFF */  addiu     $v0, $v0, -1
/* ECA0C0 802403C0 00021080 */  sll       $v0, $v0, 2
/* ECA0C4 802403C4 02621021 */  addu      $v0, $s3, $v0
/* ECA0C8 802403C8 AEA30084 */  sw        $v1, 0x84($s5)
/* ECA0CC 802403CC 8C420108 */  lw        $v0, 0x108($v0)
/* ECA0D0 802403D0 080900F8 */  j         .L802403E0
/* ECA0D4 802403D4 AEA20088 */   sw       $v0, 0x88($s5)
.L802403D8:
/* ECA0D8 802403D8 2402FFFF */  addiu     $v0, $zero, -1
/* ECA0DC 802403DC AEA20084 */  sw        $v0, 0x84($s5)
.L802403E0:
/* ECA0E0 802403E0 0C00B007 */  jal       func_8002C01C
/* ECA0E4 802403E4 8EA40078 */   lw       $a0, 0x78($s5)
/* ECA0E8 802403E8 24020002 */  addiu     $v0, $zero, 2
.L802403EC:
/* ECA0EC 802403EC 8FBF003C */  lw        $ra, 0x3c($sp)
/* ECA0F0 802403F0 8FBE0038 */  lw        $fp, 0x38($sp)
/* ECA0F4 802403F4 8FB70034 */  lw        $s7, 0x34($sp)
/* ECA0F8 802403F8 8FB60030 */  lw        $s6, 0x30($sp)
/* ECA0FC 802403FC 8FB5002C */  lw        $s5, 0x2c($sp)
/* ECA100 80240400 8FB40028 */  lw        $s4, 0x28($sp)
/* ECA104 80240404 8FB30024 */  lw        $s3, 0x24($sp)
/* ECA108 80240408 8FB20020 */  lw        $s2, 0x20($sp)
/* ECA10C 8024040C 8FB1001C */  lw        $s1, 0x1c($sp)
/* ECA110 80240410 8FB00018 */  lw        $s0, 0x18($sp)
/* ECA114 80240414 03E00008 */  jr        $ra
/* ECA118 80240418 27BD0040 */   addiu    $sp, $sp, 0x40
