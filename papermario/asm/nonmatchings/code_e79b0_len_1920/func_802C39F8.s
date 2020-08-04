.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802C39F8
/* 0E83A8 802C39F8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0E83AC 802C39FC AFB10014 */  sw    $s1, 0x14($sp)
/* 0E83B0 802C3A00 0080882D */  daddu $s1, $a0, $zero
/* 0E83B4 802C3A04 AFB20018 */  sw    $s2, 0x18($sp)
/* 0E83B8 802C3A08 00A0902D */  daddu $s2, $a1, $zero
/* 0E83BC 802C3A0C AFB3001C */  sw    $s3, 0x1c($sp)
/* 0E83C0 802C3A10 00C0982D */  daddu $s3, $a2, $zero
/* 0E83C4 802C3A14 3C04802E */  lui   $a0, 0x802e
/* 0E83C8 802C3A18 8C84A890 */  lw    $a0, -0x5770($a0)
/* 0E83CC 802C3A1C 0000182D */  daddu $v1, $zero, $zero
/* 0E83D0 802C3A20 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0E83D4 802C3A24 AFB40020 */  sw    $s4, 0x20($sp)
/* 0E83D8 802C3A28 AFB00010 */  sw    $s0, 0x10($sp)
.L802C3A2C:
/* 0E83DC 802C3A2C 8C820000 */  lw    $v0, ($a0)
/* 0E83E0 802C3A30 10400006 */  beqz  $v0, .L802C3A4C
/* 0E83E4 802C3A34 28620080 */   slti  $v0, $v1, 0x80
/* 0E83E8 802C3A38 24630001 */  addiu $v1, $v1, 1
/* 0E83EC 802C3A3C 28620080 */  slti  $v0, $v1, 0x80
/* 0E83F0 802C3A40 1440FFFA */  bnez  $v0, .L802C3A2C
/* 0E83F4 802C3A44 24840004 */   addiu $a0, $a0, 4
/* 0E83F8 802C3A48 28620080 */  slti  $v0, $v1, 0x80
.L802C3A4C:
/* 0E83FC 802C3A4C 54400003 */  bnel  $v0, $zero, .L802C3A5C
/* 0E8400 802C3A50 24040168 */   addiu $a0, $zero, 0x168
.L802C3A54:
/* 0E8404 802C3A54 080B0E95 */  j     .L802C3A54
/* 0E8408 802C3A58 00000000 */   nop   

.L802C3A5C:
/* 0E840C 802C3A5C 0C00AB39 */  jal   heap_malloc
/* 0E8410 802C3A60 0060A02D */   daddu $s4, $v1, $zero
/* 0E8414 802C3A64 00142080 */  sll   $a0, $s4, 2
/* 0E8418 802C3A68 3C03802E */  lui   $v1, 0x802e
/* 0E841C 802C3A6C 8C63A890 */  lw    $v1, -0x5770($v1)
/* 0E8420 802C3A70 3C05802E */  lui   $a1, 0x802e
/* 0E8424 802C3A74 24A5A488 */  addiu $a1, $a1, -0x5b78
/* 0E8428 802C3A78 00832021 */  addu  $a0, $a0, $v1
/* 0E842C 802C3A7C 8CA30000 */  lw    $v1, ($a1)
/* 0E8430 802C3A80 0040802D */  daddu $s0, $v0, $zero
/* 0E8434 802C3A84 AC900000 */  sw    $s0, ($a0)
/* 0E8438 802C3A88 24630001 */  addiu $v1, $v1, 1
/* 0E843C 802C3A8C 16000003 */  bnez  $s0, .L802C3A9C
/* 0E8440 802C3A90 ACA30000 */   sw    $v1, ($a1)
.L802C3A94:
/* 0E8444 802C3A94 080B0EA5 */  j     .L802C3A94
/* 0E8448 802C3A98 00000000 */   nop   

.L802C3A9C:
/* 0E844C 802C3A9C 36620001 */  ori   $v0, $s3, 1
/* 0E8450 802C3AA0 A2020000 */  sb    $v0, ($s0)
/* 0E8454 802C3AA4 AE120008 */  sw    $s2, 8($s0)
/* 0E8458 802C3AA8 AE12015C */  sw    $s2, 0x15c($s0)
/* 0E845C 802C3AAC AE120164 */  sw    $s2, 0x164($s0)
/* 0E8460 802C3AB0 A2000002 */  sb    $zero, 2($s0)
/* 0E8464 802C3AB4 AE000060 */  sw    $zero, 0x60($s0)
/* 0E8468 802C3AB8 AE000064 */  sw    $zero, 0x64($s0)
/* 0E846C 802C3ABC AE11006C */  sw    $s1, 0x6c($s0)
/* 0E8470 802C3AC0 AE000068 */  sw    $zero, 0x68($s0)
/* 0E8474 802C3AC4 92220003 */  lbu   $v0, 3($s1)
/* 0E8478 802C3AC8 3C04802E */  lui   $a0, 0x802e
/* 0E847C 802C3ACC 24849CA0 */  addiu $a0, $a0, -0x6360
/* 0E8480 802C3AD0 A2020003 */  sb    $v0, 3($s0)
/* 0E8484 802C3AD4 8C820000 */  lw    $v0, ($a0)
/* 0E8488 802C3AD8 AE020144 */  sw    $v0, 0x144($s0)
/* 0E848C 802C3ADC 8E230148 */  lw    $v1, 0x148($s1)
/* 0E8490 802C3AE0 24420001 */  addiu $v0, $v0, 1
/* 0E8494 802C3AE4 AC820000 */  sw    $v0, ($a0)
/* 0E8498 802C3AE8 AE030148 */  sw    $v1, 0x148($s0)
/* 0E849C 802C3AEC 8E23014C */  lw    $v1, 0x14c($s1)
/* 0E84A0 802C3AF0 2402FFFF */  addiu $v0, $zero, -1
/* 0E84A4 802C3AF4 A2020006 */  sb    $v0, 6($s0)
/* 0E84A8 802C3AF8 A2020007 */  sb    $v0, 7($s0)
/* 0E84AC 802C3AFC AE03014C */  sw    $v1, 0x14c($s0)
/* 0E84B0 802C3B00 92220004 */  lbu   $v0, 4($s1)
/* 0E84B4 802C3B04 0220282D */  daddu $a1, $s1, $zero
/* 0E84B8 802C3B08 AE000160 */  sw    $zero, 0x160($s0)
/* 0E84BC 802C3B0C A2020004 */  sb    $v0, 4($s0)
/* 0E84C0 802C3B10 8E22013C */  lw    $v0, 0x13c($s1)
/* 0E84C4 802C3B14 3C01802E */  lui   $at, 0x802e
/* 0E84C8 802C3B18 C4209CA8 */  lwc1  $f0, -0x6358($at)
/* 0E84CC 802C3B1C 0200202D */  daddu $a0, $s0, $zero
/* 0E84D0 802C3B20 AE02013C */  sw    $v0, 0x13c($s0)
/* 0E84D4 802C3B24 8E220140 */  lw    $v0, 0x140($s1)
/* 0E84D8 802C3B28 0000182D */  daddu $v1, $zero, $zero
/* 0E84DC 802C3B2C E6000150 */  swc1  $f0, 0x150($s0)
/* 0E84E0 802C3B30 AE000154 */  sw    $zero, 0x154($s0)
/* 0E84E4 802C3B34 AE000158 */  sw    $zero, 0x158($s0)
/* 0E84E8 802C3B38 AE020140 */  sw    $v0, 0x140($s0)
.L802C3B3C:
/* 0E84EC 802C3B3C 8CA20084 */  lw    $v0, 0x84($a1)
/* 0E84F0 802C3B40 24A50004 */  addiu $a1, $a1, 4
/* 0E84F4 802C3B44 24630001 */  addiu $v1, $v1, 1
/* 0E84F8 802C3B48 AC820084 */  sw    $v0, 0x84($a0)
/* 0E84FC 802C3B4C 28620010 */  slti  $v0, $v1, 0x10
/* 0E8500 802C3B50 1440FFFA */  bnez  $v0, .L802C3B3C
/* 0E8504 802C3B54 24840004 */   addiu $a0, $a0, 4
/* 0E8508 802C3B58 0000182D */  daddu $v1, $zero, $zero
/* 0E850C 802C3B5C 0220202D */  daddu $a0, $s1, $zero
/* 0E8510 802C3B60 0200282D */  daddu $a1, $s0, $zero
.L802C3B64:
/* 0E8514 802C3B64 8C8200C4 */  lw    $v0, 0xc4($a0)
/* 0E8518 802C3B68 24840004 */  addiu $a0, $a0, 4
/* 0E851C 802C3B6C 24630001 */  addiu $v1, $v1, 1
/* 0E8520 802C3B70 ACA200C4 */  sw    $v0, 0xc4($a1)
/* 0E8524 802C3B74 28620003 */  slti  $v0, $v1, 3
/* 0E8528 802C3B78 1440FFFA */  bnez  $v0, .L802C3B64
/* 0E852C 802C3B7C 24A50004 */   addiu $a1, $a1, 4
/* 0E8530 802C3B80 0C0B0C52 */  jal   find_script_labels
/* 0E8534 802C3B84 0200202D */   daddu $a0, $s0, $zero
/* 0E8538 802C3B88 3C02802E */  lui   $v0, 0x802e
/* 0E853C 802C3B8C 8C429CA4 */  lw    $v0, -0x635c($v0)
/* 0E8540 802C3B90 1040000E */  beqz  $v0, .L802C3BCC
/* 0E8544 802C3B94 00000000 */   nop   
/* 0E8548 802C3B98 3C05802E */  lui   $a1, 0x802e
/* 0E854C 802C3B9C 24A5AC98 */  addiu $a1, $a1, -0x5368
/* 0E8550 802C3BA0 8CA20000 */  lw    $v0, ($a1)
/* 0E8554 802C3BA4 00022080 */  sll   $a0, $v0, 2
/* 0E8558 802C3BA8 3C01802E */  lui   $at, 0x802e
/* 0E855C 802C3BAC 00240821 */  addu  $at, $at, $a0
/* 0E8560 802C3BB0 AC34A898 */  sw    $s4, -0x5768($at)
/* 0E8564 802C3BB4 8E030144 */  lw    $v1, 0x144($s0)
/* 0E8568 802C3BB8 24420001 */  addiu $v0, $v0, 1
/* 0E856C 802C3BBC ACA20000 */  sw    $v0, ($a1)
/* 0E8570 802C3BC0 3C01802E */  lui   $at, 0x802e
/* 0E8574 802C3BC4 00240821 */  addu  $at, $at, $a0
/* 0E8578 802C3BC8 AC23AA98 */  sw    $v1, -0x5568($at)
.L802C3BCC:
/* 0E857C 802C3BCC 3C03802E */  lui   $v1, 0x802e
/* 0E8580 802C3BD0 24639CA0 */  addiu $v1, $v1, -0x6360
/* 0E8584 802C3BD4 8C620000 */  lw    $v0, ($v1)
/* 0E8588 802C3BD8 14400002 */  bnez  $v0, .L802C3BE4
/* 0E858C 802C3BDC 24020001 */   addiu $v0, $zero, 1
/* 0E8590 802C3BE0 AC620000 */  sw    $v0, ($v1)
.L802C3BE4:
/* 0E8594 802C3BE4 0C0B0CE4 */  jal   func_802C3390
/* 0E8598 802C3BE8 0200202D */   daddu $a0, $s0, $zero
/* 0E859C 802C3BEC 0200102D */  daddu $v0, $s0, $zero
/* 0E85A0 802C3BF0 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0E85A4 802C3BF4 8FB40020 */  lw    $s4, 0x20($sp)
/* 0E85A8 802C3BF8 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0E85AC 802C3BFC 8FB20018 */  lw    $s2, 0x18($sp)
/* 0E85B0 802C3C00 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E85B4 802C3C04 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E85B8 802C3C08 03E00008 */  jr    $ra
/* 0E85BC 802C3C0C 27BD0028 */   addiu $sp, $sp, 0x28

/* 0E85C0 802C3C10 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E85C4 802C3C14 AFB10014 */  sw    $s1, 0x14($sp)
/* 0E85C8 802C3C18 0080882D */  daddu $s1, $a0, $zero
/* 0E85CC 802C3C1C AFBF0018 */  sw    $ra, 0x18($sp)
/* 0E85D0 802C3C20 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E85D4 802C3C24 92220000 */  lbu   $v0, ($s1)
/* 0E85D8 802C3C28 3C013F80 */  lui   $at, 0x3f80
/* 0E85DC 802C3C2C 44810000 */  mtc1  $at, $f0
/* 0E85E0 802C3C30 8E240060 */  lw    $a0, 0x60($s1)
/* 0E85E4 802C3C34 AE250008 */  sw    $a1, 8($s1)
/* 0E85E8 802C3C38 AE25015C */  sw    $a1, 0x15c($s1)
/* 0E85EC 802C3C3C AE250164 */  sw    $a1, 0x164($s1)
/* 0E85F0 802C3C40 A2200002 */  sb    $zero, 2($s1)
/* 0E85F4 802C3C44 AE200154 */  sw    $zero, 0x154($s1)
/* 0E85F8 802C3C48 00461025 */  or    $v0, $v0, $a2
/* 0E85FC 802C3C4C A2220000 */  sb    $v0, ($s1)
/* 0E8600 802C3C50 10800004 */  beqz  $a0, .L802C3C64
/* 0E8604 802C3C54 E6200150 */   swc1  $f0, 0x150($s1)
/* 0E8608 802C3C58 0C00AB4B */  jal   heap_free
/* 0E860C 802C3C5C 00000000 */   nop   
/* 0E8610 802C3C60 AE200060 */  sw    $zero, 0x60($s1)
.L802C3C64:
/* 0E8614 802C3C64 8E240068 */  lw    $a0, 0x68($s1)
/* 0E8618 802C3C68 10800003 */  beqz  $a0, .L802C3C78
/* 0E861C 802C3C6C 0000802D */   daddu $s0, $zero, $zero
/* 0E8620 802C3C70 0C0B0FCF */  jal   kill_script
/* 0E8624 802C3C74 00000000 */   nop   
.L802C3C78:
/* 0E8628 802C3C78 3C03802E */  lui   $v1, 0x802e
/* 0E862C 802C3C7C 8C63A890 */  lw    $v1, -0x5770($v1)
/* 0E8630 802C3C80 00101080 */  sll   $v0, $s0, 2
/* 0E8634 802C3C84 00431021 */  addu  $v0, $v0, $v1
/* 0E8638 802C3C88 8C440000 */  lw    $a0, ($v0)
/* 0E863C 802C3C8C 10800006 */  beqz  $a0, .L802C3CA8
/* 0E8640 802C3C90 26100001 */   addiu $s0, $s0, 1
/* 0E8644 802C3C94 8C82006C */  lw    $v0, 0x6c($a0)
/* 0E8648 802C3C98 14510003 */  bne   $v0, $s1, .L802C3CA8
/* 0E864C 802C3C9C 00000000 */   nop   
/* 0E8650 802C3CA0 0C0B0FCF */  jal   kill_script
/* 0E8654 802C3CA4 00000000 */   nop   
.L802C3CA8:
/* 0E8658 802C3CA8 2A020080 */  slti  $v0, $s0, 0x80
/* 0E865C 802C3CAC 1440FFF2 */  bnez  $v0, .L802C3C78
/* 0E8660 802C3CB0 2402FFFF */   addiu $v0, $zero, -1
/* 0E8664 802C3CB4 A2220006 */  sb    $v0, 6($s1)
/* 0E8668 802C3CB8 A2220007 */  sb    $v0, 7($s1)
/* 0E866C 802C3CBC 3C01802E */  lui   $at, 0x802e
/* 0E8670 802C3CC0 C4209CA8 */  lwc1  $f0, -0x6358($at)
/* 0E8674 802C3CC4 0220202D */  daddu $a0, $s1, $zero
/* 0E8678 802C3CC8 AE200064 */  sw    $zero, 0x64($s1)
/* 0E867C 802C3CCC AE20006C */  sw    $zero, 0x6c($s1)
/* 0E8680 802C3CD0 AE200068 */  sw    $zero, 0x68($s1)
/* 0E8684 802C3CD4 AE200154 */  sw    $zero, 0x154($s1)
/* 0E8688 802C3CD8 AE200158 */  sw    $zero, 0x158($s1)
/* 0E868C 802C3CDC 0C0B0C52 */  jal   find_script_labels
/* 0E8690 802C3CE0 E6200150 */   swc1  $f0, 0x150($s1)
/* 0E8694 802C3CE4 0C0B0CE4 */  jal   func_802C3390
/* 0E8698 802C3CE8 0220202D */   daddu $a0, $s1, $zero
/* 0E869C 802C3CEC 0220102D */  daddu $v0, $s1, $zero
/* 0E86A0 802C3CF0 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E86A4 802C3CF4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E86A8 802C3CF8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E86AC 802C3CFC 03E00008 */  jr    $ra
/* 0E86B0 802C3D00 27BD0020 */   addiu $sp, $sp, 0x20

