.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802C39F8
/* E83A8 802C39F8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E83AC 802C39FC AFB10014 */  sw        $s1, 0x14($sp)
/* E83B0 802C3A00 0080882D */  daddu     $s1, $a0, $zero
/* E83B4 802C3A04 AFB20018 */  sw        $s2, 0x18($sp)
/* E83B8 802C3A08 00A0902D */  daddu     $s2, $a1, $zero
/* E83BC 802C3A0C AFB3001C */  sw        $s3, 0x1c($sp)
/* E83C0 802C3A10 00C0982D */  daddu     $s3, $a2, $zero
/* E83C4 802C3A14 3C04802E */  lui       $a0, %hi(gCurrentScriptListPtr)
/* E83C8 802C3A18 8C84A890 */  lw        $a0, %lo(gCurrentScriptListPtr)($a0)
/* E83CC 802C3A1C 0000182D */  daddu     $v1, $zero, $zero
/* E83D0 802C3A20 AFBF0024 */  sw        $ra, 0x24($sp)
/* E83D4 802C3A24 AFB40020 */  sw        $s4, 0x20($sp)
/* E83D8 802C3A28 AFB00010 */  sw        $s0, 0x10($sp)
.L802C3A2C:
/* E83DC 802C3A2C 8C820000 */  lw        $v0, ($a0)
/* E83E0 802C3A30 10400006 */  beqz      $v0, .L802C3A4C
/* E83E4 802C3A34 28620080 */   slti     $v0, $v1, 0x80
/* E83E8 802C3A38 24630001 */  addiu     $v1, $v1, 1
/* E83EC 802C3A3C 28620080 */  slti      $v0, $v1, 0x80
/* E83F0 802C3A40 1440FFFA */  bnez      $v0, .L802C3A2C
/* E83F4 802C3A44 24840004 */   addiu    $a0, $a0, 4
/* E83F8 802C3A48 28620080 */  slti      $v0, $v1, 0x80
.L802C3A4C:
/* E83FC 802C3A4C 54400003 */  bnel      $v0, $zero, .L802C3A5C
/* E8400 802C3A50 24040168 */   addiu    $a0, $zero, 0x168
.L802C3A54:
/* E8404 802C3A54 080B0E95 */  j         .L802C3A54
/* E8408 802C3A58 00000000 */   nop      
.L802C3A5C:
/* E840C 802C3A5C 0C00AB39 */  jal       heap_malloc
/* E8410 802C3A60 0060A02D */   daddu    $s4, $v1, $zero
/* E8414 802C3A64 00142080 */  sll       $a0, $s4, 2
/* E8418 802C3A68 3C03802E */  lui       $v1, %hi(gCurrentScriptListPtr)
/* E841C 802C3A6C 8C63A890 */  lw        $v1, %lo(gCurrentScriptListPtr)($v1)
/* E8420 802C3A70 3C05802E */  lui       $a1, %hi(gNumScripts)
/* E8424 802C3A74 24A5A488 */  addiu     $a1, $a1, %lo(gNumScripts)
/* E8428 802C3A78 00832021 */  addu      $a0, $a0, $v1
/* E842C 802C3A7C 8CA30000 */  lw        $v1, ($a1)
/* E8430 802C3A80 0040802D */  daddu     $s0, $v0, $zero
/* E8434 802C3A84 AC900000 */  sw        $s0, ($a0)
/* E8438 802C3A88 24630001 */  addiu     $v1, $v1, 1
/* E843C 802C3A8C 16000003 */  bnez      $s0, .L802C3A9C
/* E8440 802C3A90 ACA30000 */   sw       $v1, ($a1)
.L802C3A94:
/* E8444 802C3A94 080B0EA5 */  j         .L802C3A94
/* E8448 802C3A98 00000000 */   nop      
.L802C3A9C:
/* E844C 802C3A9C 36620001 */  ori       $v0, $s3, 1
/* E8450 802C3AA0 A2020000 */  sb        $v0, ($s0)
/* E8454 802C3AA4 AE120008 */  sw        $s2, 8($s0)
/* E8458 802C3AA8 AE12015C */  sw        $s2, 0x15c($s0)
/* E845C 802C3AAC AE120164 */  sw        $s2, 0x164($s0)
/* E8460 802C3AB0 A2000002 */  sb        $zero, 2($s0)
/* E8464 802C3AB4 AE000060 */  sw        $zero, 0x60($s0)
/* E8468 802C3AB8 AE000064 */  sw        $zero, 0x64($s0)
/* E846C 802C3ABC AE11006C */  sw        $s1, 0x6c($s0)
/* E8470 802C3AC0 AE000068 */  sw        $zero, 0x68($s0)
/* E8474 802C3AC4 92220003 */  lbu       $v0, 3($s1)
/* E8478 802C3AC8 3C04802E */  lui       $a0, 0x802e
/* E847C 802C3ACC 24849CA0 */  addiu     $a0, $a0, -0x6360
/* E8480 802C3AD0 A2020003 */  sb        $v0, 3($s0)
/* E8484 802C3AD4 8C820000 */  lw        $v0, ($a0)
/* E8488 802C3AD8 AE020144 */  sw        $v0, 0x144($s0)
/* E848C 802C3ADC 8E230148 */  lw        $v1, 0x148($s1)
/* E8490 802C3AE0 24420001 */  addiu     $v0, $v0, 1
/* E8494 802C3AE4 AC820000 */  sw        $v0, ($a0)
/* E8498 802C3AE8 AE030148 */  sw        $v1, 0x148($s0)
/* E849C 802C3AEC 8E23014C */  lw        $v1, 0x14c($s1)
/* E84A0 802C3AF0 2402FFFF */  addiu     $v0, $zero, -1
/* E84A4 802C3AF4 A2020006 */  sb        $v0, 6($s0)
/* E84A8 802C3AF8 A2020007 */  sb        $v0, 7($s0)
/* E84AC 802C3AFC AE03014C */  sw        $v1, 0x14c($s0)
/* E84B0 802C3B00 92220004 */  lbu       $v0, 4($s1)
/* E84B4 802C3B04 0220282D */  daddu     $a1, $s1, $zero
/* E84B8 802C3B08 AE000160 */  sw        $zero, 0x160($s0)
/* E84BC 802C3B0C A2020004 */  sb        $v0, 4($s0)
/* E84C0 802C3B10 8E22013C */  lw        $v0, 0x13c($s1)
/* E84C4 802C3B14 3C01802E */  lui       $at, 0x802e
/* E84C8 802C3B18 C4209CA8 */  lwc1      $f0, -0x6358($at)
/* E84CC 802C3B1C 0200202D */  daddu     $a0, $s0, $zero
/* E84D0 802C3B20 AE02013C */  sw        $v0, 0x13c($s0)
/* E84D4 802C3B24 8E220140 */  lw        $v0, 0x140($s1)
/* E84D8 802C3B28 0000182D */  daddu     $v1, $zero, $zero
/* E84DC 802C3B2C E6000150 */  swc1      $f0, 0x150($s0)
/* E84E0 802C3B30 AE000154 */  sw        $zero, 0x154($s0)
/* E84E4 802C3B34 AE000158 */  sw        $zero, 0x158($s0)
/* E84E8 802C3B38 AE020140 */  sw        $v0, 0x140($s0)
.L802C3B3C:
/* E84EC 802C3B3C 8CA20084 */  lw        $v0, 0x84($a1)
/* E84F0 802C3B40 24A50004 */  addiu     $a1, $a1, 4
/* E84F4 802C3B44 24630001 */  addiu     $v1, $v1, 1
/* E84F8 802C3B48 AC820084 */  sw        $v0, 0x84($a0)
/* E84FC 802C3B4C 28620010 */  slti      $v0, $v1, 0x10
/* E8500 802C3B50 1440FFFA */  bnez      $v0, .L802C3B3C
/* E8504 802C3B54 24840004 */   addiu    $a0, $a0, 4
/* E8508 802C3B58 0000182D */  daddu     $v1, $zero, $zero
/* E850C 802C3B5C 0220202D */  daddu     $a0, $s1, $zero
/* E8510 802C3B60 0200282D */  daddu     $a1, $s0, $zero
.L802C3B64:
/* E8514 802C3B64 8C8200C4 */  lw        $v0, 0xc4($a0)
/* E8518 802C3B68 24840004 */  addiu     $a0, $a0, 4
/* E851C 802C3B6C 24630001 */  addiu     $v1, $v1, 1
/* E8520 802C3B70 ACA200C4 */  sw        $v0, 0xc4($a1)
/* E8524 802C3B74 28620003 */  slti      $v0, $v1, 3
/* E8528 802C3B78 1440FFFA */  bnez      $v0, .L802C3B64
/* E852C 802C3B7C 24A50004 */   addiu    $a1, $a1, 4
/* E8530 802C3B80 0C0B0C52 */  jal       find_script_labels
/* E8534 802C3B84 0200202D */   daddu    $a0, $s0, $zero
/* E8538 802C3B88 3C02802E */  lui       $v0, %hi(D_802D9CA4)
/* E853C 802C3B8C 8C429CA4 */  lw        $v0, %lo(D_802D9CA4)($v0)
/* E8540 802C3B90 1040000E */  beqz      $v0, .L802C3BCC
/* E8544 802C3B94 00000000 */   nop      
/* E8548 802C3B98 3C05802E */  lui       $a1, %hi(gScriptListCount)
/* E854C 802C3B9C 24A5AC98 */  addiu     $a1, $a1, %lo(gScriptListCount)
/* E8550 802C3BA0 8CA20000 */  lw        $v0, ($a1)
/* E8554 802C3BA4 00022080 */  sll       $a0, $v0, 2
/* E8558 802C3BA8 3C01802E */  lui       $at, 0x802e
/* E855C 802C3BAC 00240821 */  addu      $at, $at, $a0
/* E8560 802C3BB0 AC34A898 */  sw        $s4, -0x5768($at)
/* E8564 802C3BB4 8E030144 */  lw        $v1, 0x144($s0)
/* E8568 802C3BB8 24420001 */  addiu     $v0, $v0, 1
/* E856C 802C3BBC ACA20000 */  sw        $v0, ($a1)
/* E8570 802C3BC0 3C01802E */  lui       $at, %hi(gScriptIndexList)
/* E8574 802C3BC4 00240821 */  addu      $at, $at, $a0
/* E8578 802C3BC8 AC23AA98 */  sw        $v1, %lo(gScriptIndexList)($at)
.L802C3BCC:
/* E857C 802C3BCC 3C03802E */  lui       $v1, 0x802e
/* E8580 802C3BD0 24639CA0 */  addiu     $v1, $v1, -0x6360
/* E8584 802C3BD4 8C620000 */  lw        $v0, ($v1)
/* E8588 802C3BD8 14400002 */  bnez      $v0, .L802C3BE4
/* E858C 802C3BDC 24020001 */   addiu    $v0, $zero, 1
/* E8590 802C3BE0 AC620000 */  sw        $v0, ($v1)
.L802C3BE4:
/* E8594 802C3BE4 0C0B0CE4 */  jal       func_802C3390
/* E8598 802C3BE8 0200202D */   daddu    $a0, $s0, $zero
/* E859C 802C3BEC 0200102D */  daddu     $v0, $s0, $zero
/* E85A0 802C3BF0 8FBF0024 */  lw        $ra, 0x24($sp)
/* E85A4 802C3BF4 8FB40020 */  lw        $s4, 0x20($sp)
/* E85A8 802C3BF8 8FB3001C */  lw        $s3, 0x1c($sp)
/* E85AC 802C3BFC 8FB20018 */  lw        $s2, 0x18($sp)
/* E85B0 802C3C00 8FB10014 */  lw        $s1, 0x14($sp)
/* E85B4 802C3C04 8FB00010 */  lw        $s0, 0x10($sp)
/* E85B8 802C3C08 03E00008 */  jr        $ra
/* E85BC 802C3C0C 27BD0028 */   addiu    $sp, $sp, 0x28
