.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802DBE78
/* FEF68 802DBE78 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* FEF6C 802DBE7C AFB10014 */  sw        $s1, 0x14($sp)
/* FEF70 802DBE80 00A0882D */  daddu     $s1, $a1, $zero
/* FEF74 802DBE84 AFB20018 */  sw        $s2, 0x18($sp)
/* FEF78 802DBE88 00C0902D */  daddu     $s2, $a2, $zero
/* FEF7C 802DBE8C 02320018 */  mult      $s1, $s2
/* FEF80 802DBE90 0080402D */  daddu     $t0, $a0, $zero
/* FEF84 802DBE94 AFBF001C */  sw        $ra, 0x1c($sp)
/* FEF88 802DBE98 00001012 */  mflo      $v0
/* FEF8C 802DBE9C 00021FC2 */  srl       $v1, $v0, 0x1f
/* FEF90 802DBEA0 00431021 */  addu      $v0, $v0, $v1
/* FEF94 802DBEA4 00021043 */  sra       $v0, $v0, 1
/* FEF98 802DBEA8 28420801 */  slti      $v0, $v0, 0x801
/* FEF9C 802DBEAC 1040003D */  beqz      $v0, .L802DBFA4
/* FEFA0 802DBEB0 AFB00010 */   sw       $s0, 0x10($sp)
/* FEFA4 802DBEB4 00111600 */  sll       $v0, $s1, 0x18
/* FEFA8 802DBEB8 00121C00 */  sll       $v1, $s2, 0x10
/* FEFAC 802DBEBC 00432821 */  addu      $a1, $v0, $v1
/* FEFB0 802DBEC0 8D040000 */  lw        $a0, ($t0)
/* FEFB4 802DBEC4 2402FFFF */  addiu     $v0, $zero, -1
/* FEFB8 802DBEC8 1082000C */  beq       $a0, $v0, .L802DBEFC
/* FEFBC 802DBECC 00041080 */   sll      $v0, $a0, 2
/* FEFC0 802DBED0 3C01802E */  lui       $at, 0x802e
/* FEFC4 802DBED4 00220821 */  addu      $at, $at, $v0
/* FEFC8 802DBED8 8C22FE48 */  lw        $v0, -0x1b8($at)
/* FEFCC 802DBEDC 3C03FFFF */  lui       $v1, 0xffff
/* FEFD0 802DBEE0 00431024 */  and       $v0, $v0, $v1
/* FEFD4 802DBEE4 54A20006 */  bnel      $a1, $v0, .L802DBF00
/* FEFD8 802DBEE8 0000202D */   daddu    $a0, $zero, $zero
/* FEFDC 802DBEEC 0C0B6F63 */  jal       func_802DBD8C
/* FEFE0 802DBEF0 00000000 */   nop      
/* FEFE4 802DBEF4 080B6FEA */  j         .L802DBFA8
/* FEFE8 802DBEF8 00000000 */   nop      
.L802DBEFC:
/* FEFEC 802DBEFC 0000202D */  daddu     $a0, $zero, $zero
.L802DBF00:
/* FEFF0 802DBF00 3C06FFFF */  lui       $a2, 0xffff
/* FEFF4 802DBF04 3C03802E */  lui       $v1, 0x802e
/* FEFF8 802DBF08 2463FE48 */  addiu     $v1, $v1, -0x1b8
.L802DBF0C:
/* FEFFC 802DBF0C 8C620000 */  lw        $v0, ($v1)
/* FF000 802DBF10 00461024 */  and       $v0, $v0, $a2
/* FF004 802DBF14 10A2001F */  beq       $a1, $v0, .L802DBF94
/* FF008 802DBF18 00000000 */   nop      
/* FF00C 802DBF1C 24840001 */  addiu     $a0, $a0, 1
/* FF010 802DBF20 28820016 */  slti      $v0, $a0, 0x16
/* FF014 802DBF24 1440FFF9 */  bnez      $v0, .L802DBF0C
/* FF018 802DBF28 24630004 */   addiu    $v1, $v1, 4
/* FF01C 802DBF2C 0000202D */  daddu     $a0, $zero, $zero
/* FF020 802DBF30 2406FFFF */  addiu     $a2, $zero, -1
/* FF024 802DBF34 3C07802E */  lui       $a3, 0x802e
/* FF028 802DBF38 24E7FE48 */  addiu     $a3, $a3, -0x1b8
/* FF02C 802DBF3C 00E0182D */  daddu     $v1, $a3, $zero
.L802DBF40:
/* FF030 802DBF40 8C620000 */  lw        $v0, ($v1)
/* FF034 802DBF44 10460006 */  beq       $v0, $a2, .L802DBF60
/* FF038 802DBF48 24020016 */   addiu    $v0, $zero, 0x16
/* FF03C 802DBF4C 24840001 */  addiu     $a0, $a0, 1
/* FF040 802DBF50 28820016 */  slti      $v0, $a0, 0x16
/* FF044 802DBF54 1440FFFA */  bnez      $v0, .L802DBF40
/* FF048 802DBF58 24630004 */   addiu    $v1, $v1, 4
/* FF04C 802DBF5C 24020016 */  addiu     $v0, $zero, 0x16
.L802DBF60:
/* FF050 802DBF60 10820010 */  beq       $a0, $v0, .L802DBFA4
/* FF054 802DBF64 00041080 */   sll      $v0, $a0, 2
/* FF058 802DBF68 00471021 */  addu      $v0, $v0, $a3
/* FF05C 802DBF6C AD040000 */  sw        $a0, ($t0)
/* FF060 802DBF70 0C0B6F63 */  jal       func_802DBD8C
/* FF064 802DBF74 AC450000 */   sw       $a1, ($v0)
/* FF068 802DBF78 0040802D */  daddu     $s0, $v0, $zero
/* FF06C 802DBF7C 0200202D */  daddu     $a0, $s0, $zero
/* FF070 802DBF80 0220282D */  daddu     $a1, $s1, $zero
/* FF074 802DBF84 0C0B6F6F */  jal       func_802DBDBC
/* FF078 802DBF88 0240302D */   daddu    $a2, $s2, $zero
/* FF07C 802DBF8C 080B6FEA */  j         .L802DBFA8
/* FF080 802DBF90 0200102D */   daddu    $v0, $s0, $zero
.L802DBF94:
/* FF084 802DBF94 0C0B6F63 */  jal       func_802DBD8C
/* FF088 802DBF98 AD040000 */   sw       $a0, ($t0)
/* FF08C 802DBF9C 080B6FEA */  j         .L802DBFA8
/* FF090 802DBFA0 00000000 */   nop      
.L802DBFA4:
/* FF094 802DBFA4 0000102D */  daddu     $v0, $zero, $zero
.L802DBFA8:
/* FF098 802DBFA8 8FBF001C */  lw        $ra, 0x1c($sp)
/* FF09C 802DBFAC 8FB20018 */  lw        $s2, 0x18($sp)
/* FF0A0 802DBFB0 8FB10014 */  lw        $s1, 0x14($sp)
/* FF0A4 802DBFB4 8FB00010 */  lw        $s0, 0x10($sp)
/* FF0A8 802DBFB8 03E00008 */  jr        $ra
/* FF0AC 802DBFBC 27BD0020 */   addiu    $sp, $sp, 0x20
