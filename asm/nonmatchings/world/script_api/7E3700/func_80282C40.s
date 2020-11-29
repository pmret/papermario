.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80282C40
/* 7E3AC0 80282C40 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 7E3AC4 80282C44 AFB30034 */  sw        $s3, 0x34($sp)
/* 7E3AC8 80282C48 0080982D */  daddu     $s3, $a0, $zero
/* 7E3ACC 80282C4C AFB00028 */  sw        $s0, 0x28($sp)
/* 7E3AD0 80282C50 AFBF0038 */  sw        $ra, 0x38($sp)
/* 7E3AD4 80282C54 AFB20030 */  sw        $s2, 0x30($sp)
/* 7E3AD8 80282C58 AFB1002C */  sw        $s1, 0x2c($sp)
/* 7E3ADC 80282C5C 8E6400B0 */  lw        $a0, 0xb0($s3)
/* 7E3AE0 80282C60 8E7200AC */  lw        $s2, 0xac($s3)
/* 7E3AE4 80282C64 0C04417A */  jal       get_entity_by_index
/* 7E3AE8 80282C68 00A0802D */   daddu    $s0, $a1, $zero
/* 7E3AEC 80282C6C 12000023 */  beqz      $s0, .L80282CFC
/* 7E3AF0 80282C70 0040882D */   daddu    $s1, $v0, $zero
/* 7E3AF4 80282C74 0000202D */  daddu     $a0, $zero, $zero
/* 7E3AF8 80282C78 27A50018 */  addiu     $a1, $sp, 0x18
/* 7E3AFC 80282C7C 27A20024 */  addiu     $v0, $sp, 0x24
/* 7E3B00 80282C80 27A6001C */  addiu     $a2, $sp, 0x1c
/* 7E3B04 80282C84 27A70020 */  addiu     $a3, $sp, 0x20
/* 7E3B08 80282C88 AE600070 */  sw        $zero, 0x70($s3)
/* 7E3B0C 80282C8C C620004C */  lwc1      $f0, 0x4c($s1)
/* 7E3B10 80282C90 3C01420C */  lui       $at, 0x420c
/* 7E3B14 80282C94 44811000 */  mtc1      $at, $f2
/* 7E3B18 80282C98 4600020D */  trunc.w.s $f8, $f0
/* 7E3B1C 80282C9C E6680084 */  swc1      $f8, 0x84($s3)
/* 7E3B20 80282CA0 E7A20024 */  swc1      $f2, 0x24($sp)
/* 7E3B24 80282CA4 C6260048 */  lwc1      $f6, 0x48($s1)
/* 7E3B28 80282CA8 C620004C */  lwc1      $f0, 0x4c($s1)
/* 7E3B2C 80282CAC 3C0140A0 */  lui       $at, 0x40a0
/* 7E3B30 80282CB0 44811000 */  mtc1      $at, $f2
/* 7E3B34 80282CB4 C6240050 */  lwc1      $f4, 0x50($s1)
/* 7E3B38 80282CB8 46020000 */  add.s     $f0, $f0, $f2
/* 7E3B3C 80282CBC E7A60018 */  swc1      $f6, 0x18($sp)
/* 7E3B40 80282CC0 E7A40020 */  swc1      $f4, 0x20($sp)
/* 7E3B44 80282CC4 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 7E3B48 80282CC8 0C0372DF */  jal       func_800DCB7C
/* 7E3B4C 80282CCC AFA20010 */   sw       $v0, 0x10($sp)
/* 7E3B50 80282CD0 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 7E3B54 80282CD4 4600120D */  trunc.w.s $f8, $f2
/* 7E3B58 80282CD8 10400008 */  beqz      $v0, .L80282CFC
/* 7E3B5C 80282CDC E6680074 */   swc1     $f8, 0x74($s3)
/* 7E3B60 80282CE0 3C0140C0 */  lui       $at, 0x40c0
/* 7E3B64 80282CE4 44810000 */  mtc1      $at, $f0
/* 7E3B68 80282CE8 00000000 */  nop       
/* 7E3B6C 80282CEC 4600103E */  c.le.s    $f2, $f0
/* 7E3B70 80282CF0 00000000 */  nop       
/* 7E3B74 80282CF4 45010047 */  bc1t      .L80282E14
/* 7E3B78 80282CF8 24020002 */   addiu    $v0, $zero, 2
.L80282CFC:
/* 7E3B7C 80282CFC 8E420014 */  lw        $v0, 0x14($s2)
/* 7E3B80 80282D00 10400019 */  beqz      $v0, .L80282D68
/* 7E3B84 80282D04 0220202D */   daddu    $a0, $s1, $zero
/* 7E3B88 80282D08 0040F809 */  jalr      $v0
/* 7E3B8C 80282D0C 0260282D */   daddu    $a1, $s3, $zero
/* 7E3B90 80282D10 10400040 */  beqz      $v0, .L80282E14
/* 7E3B94 80282D14 0000102D */   daddu    $v0, $zero, $zero
/* 7E3B98 80282D18 C6460008 */  lwc1      $f6, 8($s2)
/* 7E3B9C 80282D1C 468031A0 */  cvt.s.w   $f6, $f6
/* 7E3BA0 80282D20 C6400010 */  lwc1      $f0, 0x10($s2)
/* 7E3BA4 80282D24 46800020 */  cvt.s.w   $f0, $f0
/* 7E3BA8 80282D28 C6220050 */  lwc1      $f2, 0x50($s1)
/* 7E3BAC 80282D2C 3C0141C8 */  lui       $at, 0x41c8
/* 7E3BB0 80282D30 44812000 */  mtc1      $at, $f4
/* 7E3BB4 80282D34 46001081 */  sub.s     $f2, $f2, $f0
/* 7E3BB8 80282D38 C6200048 */  lwc1      $f0, 0x48($s1)
/* 7E3BBC 80282D3C 92420004 */  lbu       $v0, 4($s2)
/* 7E3BC0 80282D40 46060001 */  sub.s     $f0, $f0, $f6
/* 7E3BC4 80282D44 46041083 */  div.s     $f2, $f2, $f4
/* 7E3BC8 80282D48 4600120D */  trunc.w.s $f8, $f2
/* 7E3BCC 80282D4C 44034000 */  mfc1      $v1, $f8
/* 7E3BD0 80282D50 00000000 */  nop       
/* 7E3BD4 80282D54 00620018 */  mult      $v1, $v0
/* 7E3BD8 80282D58 24020001 */  addiu     $v0, $zero, 1
/* 7E3BDC 80282D5C 8E430000 */  lw        $v1, ($s2)
/* 7E3BE0 80282D60 080A0B7D */  j         .L80282DF4
/* 7E3BE4 80282D64 46040003 */   div.s    $f0, $f0, $f4
.L80282D68:
/* 7E3BE8 80282D68 8E620070 */  lw        $v0, 0x70($s3)
/* 7E3BEC 80282D6C 3C0141C8 */  lui       $at, 0x41c8
/* 7E3BF0 80282D70 44813000 */  mtc1      $at, $f6
/* 7E3BF4 80282D74 00021080 */  sll       $v0, $v0, 2
/* 7E3BF8 80282D78 3C018028 */  lui       $at, %hi(D_80285640)
/* 7E3BFC 80282D7C 00220821 */  addu      $at, $at, $v0
/* 7E3C00 80282D80 C4225640 */  lwc1      $f2, %lo(D_80285640)($at)
/* 7E3C04 80282D84 46061082 */  mul.s     $f2, $f2, $f6
/* 7E3C08 80282D88 00000000 */  nop       
/* 7E3C0C 80282D8C C6600084 */  lwc1      $f0, 0x84($s3)
/* 7E3C10 80282D90 46800020 */  cvt.s.w   $f0, $f0
/* 7E3C14 80282D94 46020001 */  sub.s     $f0, $f0, $f2
/* 7E3C18 80282D98 E620004C */  swc1      $f0, 0x4c($s1)
/* 7E3C1C 80282D9C 8E620070 */  lw        $v0, 0x70($s3)
/* 7E3C20 80282DA0 2403000D */  addiu     $v1, $zero, 0xd
/* 7E3C24 80282DA4 24420001 */  addiu     $v0, $v0, 1
/* 7E3C28 80282DA8 14430019 */  bne       $v0, $v1, .L80282E10
/* 7E3C2C 80282DAC AE620070 */   sw       $v0, 0x70($s3)
/* 7E3C30 80282DB0 C6400010 */  lwc1      $f0, 0x10($s2)
/* 7E3C34 80282DB4 46800020 */  cvt.s.w   $f0, $f0
/* 7E3C38 80282DB8 C6220050 */  lwc1      $f2, 0x50($s1)
/* 7E3C3C 80282DBC C6440008 */  lwc1      $f4, 8($s2)
/* 7E3C40 80282DC0 46802120 */  cvt.s.w   $f4, $f4
/* 7E3C44 80282DC4 46001081 */  sub.s     $f2, $f2, $f0
/* 7E3C48 80282DC8 C6200048 */  lwc1      $f0, 0x48($s1)
/* 7E3C4C 80282DCC 92420004 */  lbu       $v0, 4($s2)
/* 7E3C50 80282DD0 46040001 */  sub.s     $f0, $f0, $f4
/* 7E3C54 80282DD4 46061083 */  div.s     $f2, $f2, $f6
/* 7E3C58 80282DD8 4600120D */  trunc.w.s $f8, $f2
/* 7E3C5C 80282DDC 44034000 */  mfc1      $v1, $f8
/* 7E3C60 80282DE0 00000000 */  nop       
/* 7E3C64 80282DE4 00620018 */  mult      $v1, $v0
/* 7E3C68 80282DE8 24020001 */  addiu     $v0, $zero, 1
/* 7E3C6C 80282DEC 8E430000 */  lw        $v1, ($s2)
/* 7E3C70 80282DF0 46060003 */  div.s     $f0, $f0, $f6
.L80282DF4:
/* 7E3C74 80282DF4 4600020D */  trunc.w.s $f8, $f0
/* 7E3C78 80282DF8 44044000 */  mfc1      $a0, $f8
/* 7E3C7C 80282DFC 00004012 */  mflo      $t0
/* 7E3C80 80282E00 00882021 */  addu      $a0, $a0, $t0
/* 7E3C84 80282E04 00641821 */  addu      $v1, $v1, $a0
/* 7E3C88 80282E08 080A0B85 */  j         .L80282E14
/* 7E3C8C 80282E0C A0600000 */   sb       $zero, ($v1)
.L80282E10:
/* 7E3C90 80282E10 0000102D */  daddu     $v0, $zero, $zero
.L80282E14:
/* 7E3C94 80282E14 8FBF0038 */  lw        $ra, 0x38($sp)
/* 7E3C98 80282E18 8FB30034 */  lw        $s3, 0x34($sp)
/* 7E3C9C 80282E1C 8FB20030 */  lw        $s2, 0x30($sp)
/* 7E3CA0 80282E20 8FB1002C */  lw        $s1, 0x2c($sp)
/* 7E3CA4 80282E24 8FB00028 */  lw        $s0, 0x28($sp)
/* 7E3CA8 80282E28 03E00008 */  jr        $ra
/* 7E3CAC 80282E2C 27BD0040 */   addiu    $sp, $sp, 0x40
