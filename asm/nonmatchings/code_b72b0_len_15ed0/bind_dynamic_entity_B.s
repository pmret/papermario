.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel bind_dynamic_entity_B
/* B9A20 80123320 3C038015 */  lui       $v1, %hi(gCurrentDynamicEntityListPtr)
/* B9A24 80123324 8C634420 */  lw        $v1, %lo(gCurrentDynamicEntityListPtr)($v1)
/* B9A28 80123328 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B9A2C 8012332C AFB10014 */  sw        $s1, 0x14($sp)
/* B9A30 80123330 0080882D */  daddu     $s1, $a0, $zero
/* B9A34 80123334 AFB20018 */  sw        $s2, 0x18($sp)
/* B9A38 80123338 00A0902D */  daddu     $s2, $a1, $zero
/* B9A3C 8012333C AFB00010 */  sw        $s0, 0x10($sp)
/* B9A40 80123340 0000802D */  daddu     $s0, $zero, $zero
/* B9A44 80123344 AFBF001C */  sw        $ra, 0x1c($sp)
.L80123348:
/* B9A48 80123348 8C620000 */  lw        $v0, ($v1)
/* B9A4C 8012334C 10400006 */  beqz      $v0, .L80123368
/* B9A50 80123350 2A020010 */   slti     $v0, $s0, 0x10
/* B9A54 80123354 26100001 */  addiu     $s0, $s0, 1
/* B9A58 80123358 2A020010 */  slti      $v0, $s0, 0x10
/* B9A5C 8012335C 1440FFFA */  bnez      $v0, .L80123348
/* B9A60 80123360 24630004 */   addiu    $v1, $v1, 4
/* B9A64 80123364 2A020010 */  slti      $v0, $s0, 0x10
.L80123368:
/* B9A68 80123368 14400003 */  bnez      $v0, .L80123378
/* B9A6C 8012336C 00000000 */   nop
.L80123370:
/* B9A70 80123370 08048CDC */  j         .L80123370
/* B9A74 80123374 00000000 */   nop
.L80123378:
/* B9A78 80123378 0C00AB39 */  jal       heap_malloc
/* B9A7C 8012337C 2404000C */   addiu    $a0, $zero, 0xc
/* B9A80 80123380 3C048015 */  lui       $a0, %hi(gCurrentDynamicEntityListPtr)
/* B9A84 80123384 8C844420 */  lw        $a0, %lo(gCurrentDynamicEntityListPtr)($a0)
/* B9A88 80123388 00101880 */  sll       $v1, $s0, 2
/* B9A8C 8012338C 00641821 */  addu      $v1, $v1, $a0
/* B9A90 80123390 0040202D */  daddu     $a0, $v0, $zero
/* B9A94 80123394 14800003 */  bnez      $a0, .L801233A4
/* B9A98 80123398 AC640000 */   sw       $a0, ($v1)
.L8012339C:
/* B9A9C 8012339C 08048CE7 */  j         .L8012339C
/* B9AA0 801233A0 00000000 */   nop
.L801233A4:
/* B9AA4 801233A4 2402000B */  addiu     $v0, $zero, 0xb
/* B9AA8 801233A8 AC820000 */  sw        $v0, ($a0)
/* B9AAC 801233AC 16200004 */  bnez      $s1, .L801233C0
/* B9AB0 801233B0 AC910004 */   sw       $s1, 4($a0)
/* B9AB4 801233B4 3C028012 */  lui       $v0, %hi(stub_dynamic_entity_delegate)
/* B9AB8 801233B8 244230B0 */  addiu     $v0, $v0, %lo(stub_dynamic_entity_delegate)
/* B9ABC 801233BC AC820004 */  sw        $v0, 4($a0)
.L801233C0:
/* B9AC0 801233C0 16400004 */  bnez      $s2, .L801233D4
/* B9AC4 801233C4 AC920008 */   sw       $s2, 8($a0)
/* B9AC8 801233C8 3C028012 */  lui       $v0, %hi(stub_dynamic_entity_delegate)
/* B9ACC 801233CC 244230B0 */  addiu     $v0, $v0, %lo(stub_dynamic_entity_delegate)
/* B9AD0 801233D0 AC820008 */  sw        $v0, 8($a0)
.L801233D4:
/* B9AD4 801233D4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B9AD8 801233D8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B9ADC 801233DC 80420070 */  lb        $v0, 0x70($v0)
/* B9AE0 801233E0 54400001 */  bnel      $v0, $zero, .L801233E8
/* B9AE4 801233E4 36100800 */   ori      $s0, $s0, 0x800
.L801233E8:
/* B9AE8 801233E8 0200102D */  daddu     $v0, $s0, $zero
/* B9AEC 801233EC 8FBF001C */  lw        $ra, 0x1c($sp)
/* B9AF0 801233F0 8FB20018 */  lw        $s2, 0x18($sp)
/* B9AF4 801233F4 8FB10014 */  lw        $s1, 0x14($sp)
/* B9AF8 801233F8 8FB00010 */  lw        $s0, 0x10($sp)
/* B9AFC 801233FC 03E00008 */  jr        $ra
/* B9B00 80123400 27BD0020 */   addiu    $sp, $sp, 0x20
