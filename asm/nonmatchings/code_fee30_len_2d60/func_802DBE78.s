.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802DBE78
/* 0FEF68 802DBE78 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FEF6C 802DBE7C AFB10014 */  sw    $s1, 0x14($sp)
/* 0FEF70 802DBE80 00A0882D */  daddu $s1, $a1, $zero
/* 0FEF74 802DBE84 AFB20018 */  sw    $s2, 0x18($sp)
/* 0FEF78 802DBE88 00C0902D */  daddu $s2, $a2, $zero
/* 0FEF7C 802DBE8C 02320018 */  mult  $s1, $s2
/* 0FEF80 802DBE90 0080402D */  daddu $t0, $a0, $zero
/* 0FEF84 802DBE94 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0FEF88 802DBE98 00001012 */  mflo  $v0
/* 0FEF8C 802DBE9C 00021FC2 */  srl   $v1, $v0, 0x1f
/* 0FEF90 802DBEA0 00431021 */  addu  $v0, $v0, $v1
/* 0FEF94 802DBEA4 00021043 */  sra   $v0, $v0, 1
/* 0FEF98 802DBEA8 28420801 */  slti  $v0, $v0, 0x801
/* 0FEF9C 802DBEAC 1040003D */  beqz  $v0, .L802DBFA4
/* 0FEFA0 802DBEB0 AFB00010 */   sw    $s0, 0x10($sp)
/* 0FEFA4 802DBEB4 00111600 */  sll   $v0, $s1, 0x18
/* 0FEFA8 802DBEB8 00121C00 */  sll   $v1, $s2, 0x10
/* 0FEFAC 802DBEBC 00432821 */  addu  $a1, $v0, $v1
/* 0FEFB0 802DBEC0 8D040000 */  lw    $a0, ($t0)
/* 0FEFB4 802DBEC4 2402FFFF */  addiu $v0, $zero, -1
/* 0FEFB8 802DBEC8 1082000C */  beq   $a0, $v0, .L802DBEFC
/* 0FEFBC 802DBECC 00041080 */   sll   $v0, $a0, 2
/* 0FEFC0 802DBED0 3C01802E */  lui   $at, 0x802e
/* 0FEFC4 802DBED4 00220821 */  addu  $at, $at, $v0
/* 0FEFC8 802DBED8 8C22FE48 */  lw    $v0, -0x1b8($at)
/* 0FEFCC 802DBEDC 3C03FFFF */  lui   $v1, 0xffff
/* 0FEFD0 802DBEE0 00431024 */  and   $v0, $v0, $v1
/* 0FEFD4 802DBEE4 54A20006 */  bnel  $a1, $v0, .L802DBF00
/* 0FEFD8 802DBEE8 0000202D */   daddu $a0, $zero, $zero
/* 0FEFDC 802DBEEC 0C0B6F63 */  jal   func_802DBD8C
/* 0FEFE0 802DBEF0 00000000 */   nop   
/* 0FEFE4 802DBEF4 080B6FEA */  j     .L802DBFA8
/* 0FEFE8 802DBEF8 00000000 */   nop   

.L802DBEFC:
/* 0FEFEC 802DBEFC 0000202D */  daddu $a0, $zero, $zero
.L802DBF00:
/* 0FEFF0 802DBF00 3C06FFFF */  lui   $a2, 0xffff
/* 0FEFF4 802DBF04 3C03802E */  lui   $v1, 0x802e
/* 0FEFF8 802DBF08 2463FE48 */  addiu $v1, $v1, -0x1b8
.L802DBF0C:
/* 0FEFFC 802DBF0C 8C620000 */  lw    $v0, ($v1)
/* 0FF000 802DBF10 00461024 */  and   $v0, $v0, $a2
/* 0FF004 802DBF14 10A2001F */  beq   $a1, $v0, .L802DBF94
/* 0FF008 802DBF18 00000000 */   nop   
/* 0FF00C 802DBF1C 24840001 */  addiu $a0, $a0, 1
/* 0FF010 802DBF20 28820016 */  slti  $v0, $a0, 0x16
/* 0FF014 802DBF24 1440FFF9 */  bnez  $v0, .L802DBF0C
/* 0FF018 802DBF28 24630004 */   addiu $v1, $v1, 4
/* 0FF01C 802DBF2C 0000202D */  daddu $a0, $zero, $zero
/* 0FF020 802DBF30 2406FFFF */  addiu $a2, $zero, -1
/* 0FF024 802DBF34 3C07802E */  lui   $a3, 0x802e
/* 0FF028 802DBF38 24E7FE48 */  addiu $a3, $a3, -0x1b8
/* 0FF02C 802DBF3C 00E0182D */  daddu $v1, $a3, $zero
.L802DBF40:
/* 0FF030 802DBF40 8C620000 */  lw    $v0, ($v1)
/* 0FF034 802DBF44 10460006 */  beq   $v0, $a2, .L802DBF60
/* 0FF038 802DBF48 24020016 */   addiu $v0, $zero, 0x16
/* 0FF03C 802DBF4C 24840001 */  addiu $a0, $a0, 1
/* 0FF040 802DBF50 28820016 */  slti  $v0, $a0, 0x16
/* 0FF044 802DBF54 1440FFFA */  bnez  $v0, .L802DBF40
/* 0FF048 802DBF58 24630004 */   addiu $v1, $v1, 4
/* 0FF04C 802DBF5C 24020016 */  addiu $v0, $zero, 0x16
.L802DBF60:
/* 0FF050 802DBF60 10820010 */  beq   $a0, $v0, .L802DBFA4
/* 0FF054 802DBF64 00041080 */   sll   $v0, $a0, 2
/* 0FF058 802DBF68 00471021 */  addu  $v0, $v0, $a3
/* 0FF05C 802DBF6C AD040000 */  sw    $a0, ($t0)
/* 0FF060 802DBF70 0C0B6F63 */  jal   func_802DBD8C
/* 0FF064 802DBF74 AC450000 */   sw    $a1, ($v0)
/* 0FF068 802DBF78 0040802D */  daddu $s0, $v0, $zero
/* 0FF06C 802DBF7C 0200202D */  daddu $a0, $s0, $zero
/* 0FF070 802DBF80 0220282D */  daddu $a1, $s1, $zero
/* 0FF074 802DBF84 0C0B6F6F */  jal   func_802DBDBC
/* 0FF078 802DBF88 0240302D */   daddu $a2, $s2, $zero
/* 0FF07C 802DBF8C 080B6FEA */  j     .L802DBFA8
/* 0FF080 802DBF90 0200102D */   daddu $v0, $s0, $zero

.L802DBF94:
/* 0FF084 802DBF94 0C0B6F63 */  jal   func_802DBD8C
/* 0FF088 802DBF98 AD040000 */   sw    $a0, ($t0)
/* 0FF08C 802DBF9C 080B6FEA */  j     .L802DBFA8
/* 0FF090 802DBFA0 00000000 */   nop   

.L802DBFA4:
/* 0FF094 802DBFA4 0000102D */  daddu $v0, $zero, $zero
.L802DBFA8:
/* 0FF098 802DBFA8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0FF09C 802DBFAC 8FB20018 */  lw    $s2, 0x18($sp)
/* 0FF0A0 802DBFB0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FF0A4 802DBFB4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FF0A8 802DBFB8 03E00008 */  jr    $ra
/* 0FF0AC 802DBFBC 27BD0020 */   addiu $sp, $sp, 0x20

