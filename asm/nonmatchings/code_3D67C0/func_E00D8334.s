.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00D8334
/* 3D6AF4 E00D8334 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 3D6AF8 E00D8338 00A0C02D */  daddu     $t8, $a1, $zero
/* 3D6AFC E00D833C 3C03FFFF */  lui       $v1, 0xffff
/* 3D6B00 E00D8340 AFBF0030 */  sw        $ra, 0x30($sp)
/* 3D6B04 E00D8344 AFB7002C */  sw        $s7, 0x2c($sp)
/* 3D6B08 E00D8348 AFB60028 */  sw        $s6, 0x28($sp)
/* 3D6B0C E00D834C AFB50024 */  sw        $s5, 0x24($sp)
/* 3D6B10 E00D8350 AFB40020 */  sw        $s4, 0x20($sp)
/* 3D6B14 E00D8354 AFB3001C */  sw        $s3, 0x1c($sp)
/* 3D6B18 E00D8358 AFB20018 */  sw        $s2, 0x18($sp)
/* 3D6B1C E00D835C AFB10014 */  sw        $s1, 0x14($sp)
/* 3D6B20 E00D8360 AFB00010 */  sw        $s0, 0x10($sp)
/* 3D6B24 E00D8364 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3D6B28 E00D8368 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3D6B2C E00D836C AFA70054 */  sw        $a3, 0x54($sp)
/* 3D6B30 E00D8370 90820034 */  lbu       $v0, 0x34($a0)
/* 3D6B34 E00D8374 3C01437F */  lui       $at, 0x437f
/* 3D6B38 E00D8378 44811000 */  mtc1      $at, $f2
/* 3D6B3C E00D837C 44820000 */  mtc1      $v0, $f0
/* 3D6B40 E00D8380 00000000 */  nop       
/* 3D6B44 E00D8384 46800020 */  cvt.s.w   $f0, $f0
/* 3D6B48 E00D8388 90820035 */  lbu       $v0, 0x35($a0)
/* 3D6B4C E00D838C 46020103 */  div.s     $f4, $f0, $f2
/* 3D6B50 E00D8390 44820000 */  mtc1      $v0, $f0
/* 3D6B54 E00D8394 00000000 */  nop       
/* 3D6B58 E00D8398 46800020 */  cvt.s.w   $f0, $f0
/* 3D6B5C E00D839C 8C820034 */  lw        $v0, 0x34($a0)
/* 3D6B60 E00D83A0 00431024 */  and       $v0, $v0, $v1
/* 3D6B64 E00D83A4 10400095 */  beqz      $v0, .LE00D85FC
/* 3D6B68 E00D83A8 46020583 */   div.s    $f22, $f0, $f2
/* 3D6B6C E00D83AC 3C09E300 */  lui       $t1, 0xe300
/* 3D6B70 E00D83B0 35290A01 */  ori       $t1, $t1, 0xa01
/* 3D6B74 E00D83B4 3C0AE300 */  lui       $t2, 0xe300
/* 3D6B78 E00D83B8 354A0C00 */  ori       $t2, $t2, 0xc00
/* 3D6B7C E00D83BC 3C0BE300 */  lui       $t3, 0xe300
/* 3D6B80 E00D83C0 356B0D01 */  ori       $t3, $t3, 0xd01
/* 3D6B84 E00D83C4 3C0CE300 */  lui       $t4, 0xe300
/* 3D6B88 E00D83C8 358C0F00 */  ori       $t4, $t4, 0xf00
/* 3D6B8C E00D83CC 3C0DE300 */  lui       $t5, 0xe300
/* 3D6B90 E00D83D0 35AD1001 */  ori       $t5, $t5, 0x1001
/* 3D6B94 E00D83D4 3C0EE300 */  lui       $t6, 0xe300
/* 3D6B98 E00D83D8 35CE1201 */  ori       $t6, $t6, 0x1201
/* 3D6B9C E00D83DC 3C0FE300 */  lui       $t7, 0xe300
/* 3D6BA0 E00D83E0 35EF1402 */  ori       $t7, $t7, 0x1402
/* 3D6BA4 E00D83E4 3C15E200 */  lui       $s5, 0xe200
/* 3D6BA8 E00D83E8 36B5001C */  ori       $s5, $s5, 0x1c
/* 3D6BAC E00D83EC 3C100050 */  lui       $s0, 0x50
/* 3D6BB0 E00D83F0 36104340 */  ori       $s0, $s0, 0x4340
/* 3D6BB4 E00D83F4 3C16FCFF */  lui       $s6, 0xfcff
/* 3D6BB8 E00D83F8 36D6FFFF */  ori       $s6, $s6, 0xffff
/* 3D6BBC E00D83FC 3C11FFFD */  lui       $s1, 0xfffd
/* 3D6BC0 E00D8400 3631F6FB */  ori       $s1, $s1, 0xf6fb
/* 3D6BC4 E00D8404 3C171830 */  lui       $s7, 0x1830
/* 3D6BC8 E00D8408 36F760FF */  ori       $s7, $s7, 0x60ff
/* 3D6BCC E00D840C 27140004 */  addiu     $s4, $t8, 4
/* 3D6BD0 E00D8410 0280202D */  daddu     $a0, $s4, $zero
/* 3D6BD4 E00D8414 24D30004 */  addiu     $s3, $a2, 4
/* 3D6BD8 E00D8418 0260282D */  daddu     $a1, $s3, $zero
/* 3D6BDC E00D841C 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* 3D6BE0 E00D8420 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* 3D6BE4 E00D8424 3C02E700 */  lui       $v0, 0xe700
/* 3D6BE8 E00D8428 44940000 */  mtc1      $s4, $f0
/* 3D6BEC E00D842C 00000000 */  nop       
/* 3D6BF0 E00D8430 46800020 */  cvt.s.w   $f0, $f0
/* 3D6BF4 E00D8434 8FB20058 */  lw        $s2, 0x58($sp)
/* 3D6BF8 E00D8438 8D030000 */  lw        $v1, ($t0)
/* 3D6BFC E00D843C 00D29021 */  addu      $s2, $a2, $s2
/* 3D6C00 E00D8440 2652FFFC */  addiu     $s2, $s2, -4
/* 3D6C04 E00D8444 0240382D */  daddu     $a3, $s2, $zero
/* 3D6C08 E00D8448 0060302D */  daddu     $a2, $v1, $zero
/* 3D6C0C E00D844C 24630008 */  addiu     $v1, $v1, 8
/* 3D6C10 E00D8450 AD030000 */  sw        $v1, ($t0)
/* 3D6C14 E00D8454 ACC20000 */  sw        $v0, ($a2)
/* 3D6C18 E00D8458 24620008 */  addiu     $v0, $v1, 8
/* 3D6C1C E00D845C ACC00004 */  sw        $zero, 4($a2)
/* 3D6C20 E00D8460 AD020000 */  sw        $v0, ($t0)
/* 3D6C24 E00D8464 3C02D700 */  lui       $v0, 0xd700
/* 3D6C28 E00D8468 AC620000 */  sw        $v0, ($v1)
/* 3D6C2C E00D846C 2402FFFF */  addiu     $v0, $zero, -1
/* 3D6C30 E00D8470 AC620004 */  sw        $v0, 4($v1)
/* 3D6C34 E00D8474 24620010 */  addiu     $v0, $v1, 0x10
/* 3D6C38 E00D8478 AD020000 */  sw        $v0, ($t0)
/* 3D6C3C E00D847C 24620018 */  addiu     $v0, $v1, 0x18
/* 3D6C40 E00D8480 AC690008 */  sw        $t1, 8($v1)
/* 3D6C44 E00D8484 AC60000C */  sw        $zero, 0xc($v1)
/* 3D6C48 E00D8488 AD020000 */  sw        $v0, ($t0)
/* 3D6C4C E00D848C 24620020 */  addiu     $v0, $v1, 0x20
/* 3D6C50 E00D8490 AC6A0010 */  sw        $t2, 0x10($v1)
/* 3D6C54 E00D8494 AC600014 */  sw        $zero, 0x14($v1)
/* 3D6C58 E00D8498 AD020000 */  sw        $v0, ($t0)
/* 3D6C5C E00D849C 24620028 */  addiu     $v0, $v1, 0x28
/* 3D6C60 E00D84A0 AC6B0018 */  sw        $t3, 0x18($v1)
/* 3D6C64 E00D84A4 AC60001C */  sw        $zero, 0x1c($v1)
/* 3D6C68 E00D84A8 AD020000 */  sw        $v0, ($t0)
/* 3D6C6C E00D84AC 24620030 */  addiu     $v0, $v1, 0x30
/* 3D6C70 E00D84B0 AC6C0020 */  sw        $t4, 0x20($v1)
/* 3D6C74 E00D84B4 AC600024 */  sw        $zero, 0x24($v1)
/* 3D6C78 E00D84B8 AD020000 */  sw        $v0, ($t0)
/* 3D6C7C E00D84BC 24620038 */  addiu     $v0, $v1, 0x38
/* 3D6C80 E00D84C0 AC6D0028 */  sw        $t5, 0x28($v1)
/* 3D6C84 E00D84C4 AC60002C */  sw        $zero, 0x2c($v1)
/* 3D6C88 E00D84C8 AD020000 */  sw        $v0, ($t0)
/* 3D6C8C E00D84CC 24023000 */  addiu     $v0, $zero, 0x3000
/* 3D6C90 E00D84D0 AC620034 */  sw        $v0, 0x34($v1)
/* 3D6C94 E00D84D4 24620040 */  addiu     $v0, $v1, 0x40
/* 3D6C98 E00D84D8 AC6E0030 */  sw        $t6, 0x30($v1)
/* 3D6C9C E00D84DC AD020000 */  sw        $v0, ($t0)
/* 3D6CA0 E00D84E0 24020C00 */  addiu     $v0, $zero, 0xc00
/* 3D6CA4 E00D84E4 AC62003C */  sw        $v0, 0x3c($v1)
/* 3D6CA8 E00D84E8 24620048 */  addiu     $v0, $v1, 0x48
/* 3D6CAC E00D84EC AC6F0038 */  sw        $t7, 0x38($v1)
/* 3D6CB0 E00D84F0 AD020000 */  sw        $v0, ($t0)
/* 3D6CB4 E00D84F4 24620050 */  addiu     $v0, $v1, 0x50
/* 3D6CB8 E00D84F8 AC750040 */  sw        $s5, 0x40($v1)
/* 3D6CBC E00D84FC AC700044 */  sw        $s0, 0x44($v1)
/* 3D6CC0 E00D8500 AD020000 */  sw        $v0, ($t0)
/* 3D6CC4 E00D8504 AC760048 */  sw        $s6, 0x48($v1)
/* 3D6CC8 E00D8508 AC71004C */  sw        $s1, 0x4c($v1)
/* 3D6CCC E00D850C 8FB90054 */  lw        $t9, 0x54($sp)
/* 3D6CD0 E00D8510 02538023 */  subu      $s0, $s2, $s3
/* 3D6CD4 E00D8514 03198821 */  addu      $s1, $t8, $t9
/* 3D6CD8 E00D8518 2631FFFC */  addiu     $s1, $s1, -4
/* 3D6CDC E00D851C 02341023 */  subu      $v0, $s1, $s4
/* 3D6CE0 E00D8520 000237C2 */  srl       $a2, $v0, 0x1f
/* 3D6CE4 E00D8524 00461021 */  addu      $v0, $v0, $a2
/* 3D6CE8 E00D8528 00021043 */  sra       $v0, $v0, 1
/* 3D6CEC E00D852C 4482A000 */  mtc1      $v0, $f20
/* 3D6CF0 E00D8530 00000000 */  nop       
/* 3D6CF4 E00D8534 4680A520 */  cvt.s.w   $f20, $f20
/* 3D6CF8 E00D8538 24620058 */  addiu     $v0, $v1, 0x58
/* 3D6CFC E00D853C 4604A502 */  mul.s     $f20, $f20, $f4
/* 3D6D00 E00D8540 00000000 */  nop       
/* 3D6D04 E00D8544 AD020000 */  sw        $v0, ($t0)
/* 3D6D08 E00D8548 3C02FA00 */  lui       $v0, 0xfa00
/* 3D6D0C E00D854C AC620050 */  sw        $v0, 0x50($v1)
/* 3D6D10 E00D8550 001017C2 */  srl       $v0, $s0, 0x1f
/* 3D6D14 E00D8554 02028021 */  addu      $s0, $s0, $v0
/* 3D6D18 E00D8558 46140000 */  add.s     $f0, $f0, $f20
/* 3D6D1C E00D855C 00108043 */  sra       $s0, $s0, 1
/* 3D6D20 E00D8560 4600018D */  trunc.w.s $f6, $f0
/* 3D6D24 E00D8564 44063000 */  mfc1      $a2, $f6
/* 3D6D28 E00D8568 0C0360A2 */  jal       func_E00D8288
/* 3D6D2C E00D856C AC770054 */   sw       $s7, 0x54($v1)
/* 3D6D30 E00D8570 0260282D */  daddu     $a1, $s3, $zero
/* 3D6D34 E00D8574 44910000 */  mtc1      $s1, $f0
/* 3D6D38 E00D8578 00000000 */  nop       
/* 3D6D3C E00D857C 46800020 */  cvt.s.w   $f0, $f0
/* 3D6D40 E00D8580 46140001 */  sub.s     $f0, $f0, $f20
/* 3D6D44 E00D8584 0220302D */  daddu     $a2, $s1, $zero
/* 3D6D48 E00D8588 4600018D */  trunc.w.s $f6, $f0
/* 3D6D4C E00D858C 44043000 */  mfc1      $a0, $f6
/* 3D6D50 E00D8590 0C0360A2 */  jal       func_E00D8288
/* 3D6D54 E00D8594 0240382D */   daddu    $a3, $s2, $zero
/* 3D6D58 E00D8598 4490A000 */  mtc1      $s0, $f20
/* 3D6D5C E00D859C 00000000 */  nop       
/* 3D6D60 E00D85A0 4680A520 */  cvt.s.w   $f20, $f20
/* 3D6D64 E00D85A4 4616A502 */  mul.s     $f20, $f20, $f22
/* 3D6D68 E00D85A8 00000000 */  nop       
/* 3D6D6C E00D85AC 0280202D */  daddu     $a0, $s4, $zero
/* 3D6D70 E00D85B0 44930000 */  mtc1      $s3, $f0
/* 3D6D74 E00D85B4 00000000 */  nop       
/* 3D6D78 E00D85B8 46800020 */  cvt.s.w   $f0, $f0
/* 3D6D7C E00D85BC 46140000 */  add.s     $f0, $f0, $f20
/* 3D6D80 E00D85C0 0260282D */  daddu     $a1, $s3, $zero
/* 3D6D84 E00D85C4 4600018D */  trunc.w.s $f6, $f0
/* 3D6D88 E00D85C8 44073000 */  mfc1      $a3, $f6
/* 3D6D8C E00D85CC 0C0360A2 */  jal       func_E00D8288
/* 3D6D90 E00D85D0 0220302D */   daddu    $a2, $s1, $zero
/* 3D6D94 E00D85D4 0280202D */  daddu     $a0, $s4, $zero
/* 3D6D98 E00D85D8 44920000 */  mtc1      $s2, $f0
/* 3D6D9C E00D85DC 00000000 */  nop       
/* 3D6DA0 E00D85E0 46800020 */  cvt.s.w   $f0, $f0
/* 3D6DA4 E00D85E4 46140001 */  sub.s     $f0, $f0, $f20
/* 3D6DA8 E00D85E8 0220302D */  daddu     $a2, $s1, $zero
/* 3D6DAC E00D85EC 4600018D */  trunc.w.s $f6, $f0
/* 3D6DB0 E00D85F0 44053000 */  mfc1      $a1, $f6
/* 3D6DB4 E00D85F4 0C0360A2 */  jal       func_E00D8288
/* 3D6DB8 E00D85F8 0240382D */   daddu    $a3, $s2, $zero
.LE00D85FC:
/* 3D6DBC E00D85FC 8FBF0030 */  lw        $ra, 0x30($sp)
/* 3D6DC0 E00D8600 8FB7002C */  lw        $s7, 0x2c($sp)
/* 3D6DC4 E00D8604 8FB60028 */  lw        $s6, 0x28($sp)
/* 3D6DC8 E00D8608 8FB50024 */  lw        $s5, 0x24($sp)
/* 3D6DCC E00D860C 8FB40020 */  lw        $s4, 0x20($sp)
/* 3D6DD0 E00D8610 8FB3001C */  lw        $s3, 0x1c($sp)
/* 3D6DD4 E00D8614 8FB20018 */  lw        $s2, 0x18($sp)
/* 3D6DD8 E00D8618 8FB10014 */  lw        $s1, 0x14($sp)
/* 3D6DDC E00D861C 8FB00010 */  lw        $s0, 0x10($sp)
/* 3D6DE0 E00D8620 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3D6DE4 E00D8624 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3D6DE8 E00D8628 03E00008 */  jr        $ra
/* 3D6DEC E00D862C 27BD0048 */   addiu    $sp, $sp, 0x48
