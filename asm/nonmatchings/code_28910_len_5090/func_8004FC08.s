.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8004FC08
/* 02B008 8004FC08 44852000 */  mtc1  $a1, $f4
/* 02B00C 8004FC0C 00000000 */  nop   
/* 02B010 8004FC10 46802121 */  cvt.d.w $f4, $f4
/* 02B014 8004FC14 04A10006 */  bgez  $a1, .L8004FC30
/* 02B018 8004FC18 9483020A */   lhu   $v1, 0x20a($a0)
/* 02B01C 8004FC1C 3C0141F0 */  lui   $at, 0x41f0
/* 02B020 8004FC20 44810800 */  mtc1  $at, $f1
/* 02B024 8004FC24 44800000 */  mtc1  $zero, $f0
/* 02B028 8004FC28 00000000 */  nop   
/* 02B02C 8004FC2C 46202100 */  add.d $f4, $f4, $f0
.L8004FC30:
/* 02B030 8004FC30 C48200D0 */  lwc1  $f2, 0xd0($a0)
/* 02B034 8004FC34 46202020 */  cvt.s.d $f0, $f4
/* 02B038 8004FC38 46020002 */  mul.s $f0, $f0, $f2
/* 02B03C 8004FC3C 00000000 */  nop   
/* 02B040 8004FC40 3C014F00 */  lui   $at, 0x4f00
/* 02B044 8004FC44 44811000 */  mtc1  $at, $f2
/* 02B048 8004FC48 00000000 */  nop   
/* 02B04C 8004FC4C 4600103E */  c.le.s $f2, $f0
/* 02B050 8004FC50 00000000 */  nop   
/* 02B054 8004FC54 45030005 */  bc1tl .L8004FC6C
/* 02B058 8004FC58 46020001 */   sub.s $f0, $f0, $f2
/* 02B05C 8004FC5C 4600018D */  trunc.w.s $f6, $f0
/* 02B060 8004FC60 44053000 */  mfc1  $a1, $f6
/* 02B064 8004FC64 08013F21 */  j     .L8004FC84
/* 02B068 8004FC68 0065102B */   sltu  $v0, $v1, $a1

.L8004FC6C:
/* 02B06C 8004FC6C 3C028000 */  lui   $v0, 0x8000
/* 02B070 8004FC70 4600018D */  trunc.w.s $f6, $f0
/* 02B074 8004FC74 44053000 */  mfc1  $a1, $f6
/* 02B078 8004FC78 00000000 */  nop   
/* 02B07C 8004FC7C 00A22825 */  or    $a1, $a1, $v0
/* 02B080 8004FC80 0065102B */  sltu  $v0, $v1, $a1
.L8004FC84:
/* 02B084 8004FC84 10400003 */  beqz  $v0, .L8004FC94
/* 02B088 8004FC88 00000000 */   nop   
/* 02B08C 8004FC8C 08013F27 */  j     .L8004FC9C
/* 02B090 8004FC90 0060282D */   daddu $a1, $v1, $zero

.L8004FC94:
/* 02B094 8004FC94 50A00001 */  beql  $a1, $zero, .L8004FC9C
/* 02B098 8004FC98 24050001 */   addiu $a1, $zero, 1
.L8004FC9C:
/* 02B09C 8004FC9C 00051040 */  sll   $v0, $a1, 1
/* 02B0A0 8004FCA0 00451021 */  addu  $v0, $v0, $a1
/* 02B0A4 8004FCA4 000210C0 */  sll   $v0, $v0, 3
/* 02B0A8 8004FCA8 00451021 */  addu  $v0, $v0, $a1
/* 02B0AC 8004FCAC 03E00008 */  jr    $ra
/* 02B0B0 8004FCB0 00021080 */   sll   $v0, $v0, 2

/* 02B0B4 8004FCB4 908200D4 */  lbu   $v0, 0xd4($a0)
/* 02B0B8 8004FCB8 3042007F */  andi  $v0, $v0, 0x7f
/* 02B0BC 8004FCBC 54400001 */  bnel  $v0, $zero, .L8004FCC4
/* 02B0C0 8004FCC0 00021600 */   sll   $v0, $v0, 0x18
.L8004FCC4:
/* 02B0C4 8004FCC4 AC8200C0 */  sw    $v0, 0xc0($a0)
/* 02B0C8 8004FCC8 24020001 */  addiu $v0, $zero, 1
/* 02B0CC 8004FCCC AC8000CC */  sw    $zero, 0xcc($a0)
/* 02B0D0 8004FCD0 AC8000C8 */  sw    $zero, 0xc8($a0)
/* 02B0D4 8004FCD4 AC8000C4 */  sw    $zero, 0xc4($a0)
/* 02B0D8 8004FCD8 A082021A */  sb    $v0, 0x21a($a0)
/* 02B0DC 8004FCDC 03E00008 */  jr    $ra
/* 02B0E0 8004FCE0 A0A20041 */   sb    $v0, 0x41($a1)

/* 02B0E4 8004FCE4 808300D4 */  lb    $v1, 0xd4($a0)
/* 02B0E8 8004FCE8 00031040 */  sll   $v0, $v1, 1
/* 02B0EC 8004FCEC 00431021 */  addu  $v0, $v0, $v1
/* 02B0F0 8004FCF0 000210C0 */  sll   $v0, $v0, 3
/* 02B0F4 8004FCF4 00431021 */  addu  $v0, $v0, $v1
/* 02B0F8 8004FCF8 00021080 */  sll   $v0, $v0, 2
/* 02B0FC 8004FCFC 03E00008 */  jr    $ra
/* 02B100 8004FD00 A482020C */   sh    $v0, 0x20c($a0)

/* 02B104 8004FD04 90830235 */  lbu   $v1, 0x235($a0)
/* 02B108 8004FD08 8C820000 */  lw    $v0, ($a0)
/* 02B10C 8004FD0C 908500D4 */  lbu   $a1, 0xd4($a0)
/* 02B110 8004FD10 00031880 */  sll   $v1, $v1, 2
/* 02B114 8004FD14 00431021 */  addu  $v0, $v0, $v1
/* 02B118 8004FD18 A0450040 */  sb    $a1, 0x40($v0)
/* 02B11C 8004FD1C 90820235 */  lbu   $v0, 0x235($a0)
/* 02B120 8004FD20 8C830000 */  lw    $v1, ($a0)
/* 02B124 8004FD24 00021080 */  sll   $v0, $v0, 2
/* 02B128 8004FD28 00621821 */  addu  $v1, $v1, $v0
/* 02B12C 8004FD2C 24020001 */  addiu $v0, $zero, 1
/* 02B130 8004FD30 03E00008 */  jr    $ra
/* 02B134 8004FD34 A0620041 */   sb    $v0, 0x41($v1)

