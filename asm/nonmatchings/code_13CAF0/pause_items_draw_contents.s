.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_items_draw_contents
/* 13CCB0 80249970 27BDFF58 */  addiu     $sp, $sp, -0xa8
/* 13CCB4 80249974 3C038027 */  lui       $v1, %hi(gItemMenuCurrentPage)
/* 13CCB8 80249978 8C6304C8 */  lw        $v1, %lo(gItemMenuCurrentPage)($v1)
/* 13CCBC 8024997C 240A0001 */  addiu     $t2, $zero, 1
/* 13CCC0 80249980 AFA500AC */  sw        $a1, 0xac($sp)
/* 13CCC4 80249984 AFAA0060 */  sw        $t2, 0x60($sp)
/* 13CCC8 80249988 8FAA00AC */  lw        $t2, 0xac($sp)
/* 13CCCC 8024998C AFA600B0 */  sw        $a2, 0xb0($sp)
/* 13CCD0 80249990 AFA700B4 */  sw        $a3, 0xb4($sp)
/* 13CCD4 80249994 8FA700B0 */  lw        $a3, 0xb0($sp)
/* 13CCD8 80249998 240B000A */  addiu     $t3, $zero, 0xa
/* 13CCDC 8024999C AFAB0064 */  sw        $t3, 0x64($sp)
/* 13CCE0 802499A0 8FAB00B4 */  lw        $t3, 0xb4($sp)
/* 13CCE4 802499A4 AFBF00A4 */  sw        $ra, 0xa4($sp)
/* 13CCE8 802499A8 AFBE00A0 */  sw        $fp, 0xa0($sp)
/* 13CCEC 802499AC AFB7009C */  sw        $s7, 0x9c($sp)
/* 13CCF0 802499B0 AFB60098 */  sw        $s6, 0x98($sp)
/* 13CCF4 802499B4 AFB50094 */  sw        $s5, 0x94($sp)
/* 13CCF8 802499B8 AFB40090 */  sw        $s4, 0x90($sp)
/* 13CCFC 802499BC AFB3008C */  sw        $s3, 0x8c($sp)
/* 13CD00 802499C0 AFB20088 */  sw        $s2, 0x88($sp)
/* 13CD04 802499C4 AFB10084 */  sw        $s1, 0x84($sp)
/* 13CD08 802499C8 AFB00080 */  sw        $s0, 0x80($sp)
/* 13CD0C 802499CC 25460044 */  addiu     $a2, $t2, 0x44
/* 13CD10 802499D0 00031040 */  sll       $v0, $v1, 1
/* 13CD14 802499D4 00431021 */  addu      $v0, $v0, $v1
/* 13CD18 802499D8 00021080 */  sll       $v0, $v0, 2
/* 13CD1C 802499DC 3C088027 */  lui       $t0, %hi(D_802704D2)
/* 13CD20 802499E0 01024021 */  addu      $t0, $t0, $v0
/* 13CD24 802499E4 910804D2 */  lbu       $t0, %lo(D_802704D2)($t0)
/* 13CD28 802499E8 8FAA00B8 */  lw        $t2, 0xb8($sp)
/* 13CD2C 802499EC 2562FFBC */  addiu     $v0, $t3, -0x44
/* 13CD30 802499F0 AFA20014 */  sw        $v0, 0x14($sp)
/* 13CD34 802499F4 240200FF */  addiu     $v0, $zero, 0xff
/* 13CD38 802499F8 AFA00010 */  sw        $zero, 0x10($sp)
/* 13CD3C 802499FC AFA2001C */  sw        $v0, 0x1c($sp)
/* 13CD40 80249A00 AFA00020 */  sw        $zero, 0x20($sp)
/* 13CD44 80249A04 AFA00024 */  sw        $zero, 0x24($sp)
/* 13CD48 80249A08 AFA00028 */  sw        $zero, 0x28($sp)
/* 13CD4C 80249A0C AFA0002C */  sw        $zero, 0x2c($sp)
/* 13CD50 80249A10 AFA00030 */  sw        $zero, 0x30($sp)
/* 13CD54 80249A14 AFA00034 */  sw        $zero, 0x34($sp)
/* 13CD58 80249A18 AFA00038 */  sw        $zero, 0x38($sp)
/* 13CD5C 80249A1C AFA0003C */  sw        $zero, 0x3c($sp)
/* 13CD60 80249A20 AFAA0018 */  sw        $t2, 0x18($sp)
/* 13CD64 80249A24 AFA00040 */  sw        $zero, 0x40($sp)
/* 13CD68 80249A28 3C038027 */  lui       $v1, %hi(gItemMenuSelectedIndex)
/* 13CD6C 80249A2C 8C6305C0 */  lw        $v1, %lo(gItemMenuSelectedIndex)($v1)
/* 13CD70 80249A30 15000002 */  bnez      $t0, .L80249A3C
/* 13CD74 80249A34 0068001A */   div      $zero, $v1, $t0
/* 13CD78 80249A38 0007000D */  break     7
.L80249A3C:
/* 13CD7C 80249A3C 2401FFFF */   addiu    $at, $zero, -1
/* 13CD80 80249A40 15010004 */  bne       $t0, $at, .L80249A54
/* 13CD84 80249A44 3C018000 */   lui      $at, 0x8000
/* 13CD88 80249A48 14610002 */  bne       $v1, $at, .L80249A54
/* 13CD8C 80249A4C 00000000 */   nop      
/* 13CD90 80249A50 0006000D */  break     6
.L80249A54:
/* 13CD94 80249A54 00005012 */   mflo     $t2
/* 13CD98 80249A58 00005810 */  mfhi      $t3
/* 13CD9C 80249A5C 24040004 */  addiu     $a0, $zero, 4
/* 13CDA0 80249A60 3C058027 */  lui       $a1, %hi(D_8026FCF0)
/* 13CDA4 80249A64 24A5FCF0 */  addiu     $a1, $a1, %lo(D_8026FCF0)
/* 13CDA8 80249A68 24020140 */  addiu     $v0, $zero, 0x140
/* 13CDAC 80249A6C AFA20044 */  sw        $v0, 0x44($sp)
/* 13CDB0 80249A70 240200F0 */  addiu     $v0, $zero, 0xf0
/* 13CDB4 80249A74 AFA20048 */  sw        $v0, 0x48($sp)
/* 13CDB8 80249A78 AFA0004C */  sw        $zero, 0x4c($sp)
/* 13CDBC 80249A7C AFAA005C */  sw        $t2, 0x5c($sp)
/* 13CDC0 80249A80 0C03D4B8 */  jal       draw_box
/* 13CDC4 80249A84 AFAB0058 */   sw       $t3, 0x58($sp)
/* 13CDC8 80249A88 3C108027 */  lui       $s0, %hi(gItemMenuPages)
/* 13CDCC 80249A8C 261004D0 */  addiu     $s0, $s0, %lo(gItemMenuPages)
/* 13CDD0 80249A90 8FAB00B0 */  lw        $t3, 0xb0($sp)
/* 13CDD4 80249A94 8FAA00AC */  lw        $t2, 0xac($sp)
/* 13CDD8 80249A98 25660007 */  addiu     $a2, $t3, 7
/* 13CDDC 80249A9C 8FAB00B4 */  lw        $t3, 0xb4($sp)
/* 13CDE0 80249AA0 25440001 */  addiu     $a0, $t2, 1
/* 13CDE4 80249AA4 014B1021 */  addu      $v0, $t2, $t3
/* 13CDE8 80249AA8 8FAA00B0 */  lw        $t2, 0xb0($sp)
/* 13CDEC 80249AAC 8FAB00B8 */  lw        $t3, 0xb8($sp)
/* 13CDF0 80249AB0 2447FFFF */  addiu     $a3, $v0, -1
/* 13CDF4 80249AB4 014B1021 */  addu      $v0, $t2, $t3
/* 13CDF8 80249AB8 1C800002 */  bgtz      $a0, .L80249AC4
/* 13CDFC 80249ABC 2448FFF9 */   addiu    $t0, $v0, -7
/* 13CE00 80249AC0 24040001 */  addiu     $a0, $zero, 1
.L80249AC4:
/* 13CE04 80249AC4 58C00001 */  blezl     $a2, .L80249ACC
/* 13CE08 80249AC8 24060001 */   addiu    $a2, $zero, 1
.L80249ACC:
/* 13CE0C 80249ACC 18E00277 */  blez      $a3, .L8024A4AC
/* 13CE10 80249AD0 00000000 */   nop      
/* 13CE14 80249AD4 19000275 */  blez      $t0, .L8024A4AC
/* 13CE18 80249AD8 2882013F */   slti     $v0, $a0, 0x13f
/* 13CE1C 80249ADC 10400273 */  beqz      $v0, .L8024A4AC
/* 13CE20 80249AE0 28C200EF */   slti     $v0, $a2, 0xef
/* 13CE24 80249AE4 10400271 */  beqz      $v0, .L8024A4AC
/* 13CE28 80249AE8 28E2013F */   slti     $v0, $a3, 0x13f
/* 13CE2C 80249AEC 50400001 */  beql      $v0, $zero, .L80249AF4
/* 13CE30 80249AF0 2407013F */   addiu    $a3, $zero, 0x13f
.L80249AF4:
/* 13CE34 80249AF4 290200EF */  slti      $v0, $t0, 0xef
/* 13CE38 80249AF8 50400001 */  beql      $v0, $zero, .L80249B00
/* 13CE3C 80249AFC 240800EF */   addiu    $t0, $zero, 0xef
.L80249B00:
/* 13CE40 80249B00 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 13CE44 80249B04 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 13CE48 80249B08 44841000 */  mtc1      $a0, $f2
/* 13CE4C 80249B0C 00000000 */  nop       
/* 13CE50 80249B10 468010A0 */  cvt.s.w   $f2, $f2
/* 13CE54 80249B14 44860000 */  mtc1      $a2, $f0
/* 13CE58 80249B18 00000000 */  nop       
/* 13CE5C 80249B1C 46800020 */  cvt.s.w   $f0, $f0
/* 13CE60 80249B20 8FAA00AC */  lw        $t2, 0xac($sp)
/* 13CE64 80249B24 8FAB00B0 */  lw        $t3, 0xb0($sp)
/* 13CE68 80249B28 3C014080 */  lui       $at, 0x4080
/* 13CE6C 80249B2C 44812000 */  mtc1      $at, $f4
/* 13CE70 80249B30 3C04ED00 */  lui       $a0, 0xed00
/* 13CE74 80249B34 AFA00054 */  sw        $zero, 0x54($sp)
/* 13CE78 80249B38 AFA00050 */  sw        $zero, 0x50($sp)
/* 13CE7C 80249B3C 254A0077 */  addiu     $t2, $t2, 0x77
/* 13CE80 80249B40 46041082 */  mul.s     $f2, $f2, $f4
/* 13CE84 80249B44 00000000 */  nop       
/* 13CE88 80249B48 256B0011 */  addiu     $t3, $t3, 0x11
/* 13CE8C 80249B4C AFAA006C */  sw        $t2, 0x6c($sp)
/* 13CE90 80249B50 AFAB0070 */  sw        $t3, 0x70($sp)
/* 13CE94 80249B54 8C620000 */  lw        $v0, ($v1)
/* 13CE98 80249B58 46040002 */  mul.s     $f0, $f0, $f4
/* 13CE9C 80249B5C 00000000 */  nop       
/* 13CEA0 80249B60 0040282D */  daddu     $a1, $v0, $zero
/* 13CEA4 80249B64 24420008 */  addiu     $v0, $v0, 8
/* 13CEA8 80249B68 AC620000 */  sw        $v0, ($v1)
/* 13CEAC 80249B6C 4600118D */  trunc.w.s $f6, $f2
/* 13CEB0 80249B70 44023000 */  mfc1      $v0, $f6
/* 13CEB4 80249B74 00000000 */  nop       
/* 13CEB8 80249B78 30420FFF */  andi      $v0, $v0, 0xfff
/* 13CEBC 80249B7C 00021300 */  sll       $v0, $v0, 0xc
/* 13CEC0 80249B80 4600018D */  trunc.w.s $f6, $f0
/* 13CEC4 80249B84 44033000 */  mfc1      $v1, $f6
/* 13CEC8 80249B88 44871000 */  mtc1      $a3, $f2
/* 13CECC 80249B8C 00000000 */  nop       
/* 13CED0 80249B90 468010A0 */  cvt.s.w   $f2, $f2
/* 13CED4 80249B94 46041082 */  mul.s     $f2, $f2, $f4
/* 13CED8 80249B98 00000000 */  nop       
/* 13CEDC 80249B9C 30630FFF */  andi      $v1, $v1, 0xfff
/* 13CEE0 80249BA0 00641825 */  or        $v1, $v1, $a0
/* 13CEE4 80249BA4 00431025 */  or        $v0, $v0, $v1
/* 13CEE8 80249BA8 44880000 */  mtc1      $t0, $f0
/* 13CEEC 80249BAC 00000000 */  nop       
/* 13CEF0 80249BB0 46800020 */  cvt.s.w   $f0, $f0
/* 13CEF4 80249BB4 46040002 */  mul.s     $f0, $f0, $f4
/* 13CEF8 80249BB8 00000000 */  nop       
/* 13CEFC 80249BBC ACA20000 */  sw        $v0, ($a1)
/* 13CF00 80249BC0 4600118D */  trunc.w.s $f6, $f2
/* 13CF04 80249BC4 44023000 */  mfc1      $v0, $f6
/* 13CF08 80249BC8 00000000 */  nop       
/* 13CF0C 80249BCC 30420FFF */  andi      $v0, $v0, 0xfff
/* 13CF10 80249BD0 00021300 */  sll       $v0, $v0, 0xc
/* 13CF14 80249BD4 4600018D */  trunc.w.s $f6, $f0
/* 13CF18 80249BD8 44033000 */  mfc1      $v1, $f6
/* 13CF1C 80249BDC 00000000 */  nop       
/* 13CF20 80249BE0 30630FFF */  andi      $v1, $v1, 0xfff
/* 13CF24 80249BE4 00431025 */  or        $v0, $v0, $v1
/* 13CF28 80249BE8 ACA20004 */  sw        $v0, 4($a1)
.L80249BEC:
/* 13CF2C 80249BEC 0000F02D */  daddu     $fp, $zero, $zero
/* 13CF30 80249BF0 3C0B8027 */  lui       $t3, %hi(gItemMenuPages)
/* 13CF34 80249BF4 256B04D0 */  addiu     $t3, $t3, %lo(gItemMenuPages)
/* 13CF38 80249BF8 AFAB007C */  sw        $t3, 0x7c($sp)
.L80249BFC:
/* 13CF3C 80249BFC 8FAA007C */  lw        $t2, 0x7c($sp)
/* 13CF40 80249C00 91420000 */  lbu       $v0, ($t2)
/* 13CF44 80249C04 104000E2 */  beqz      $v0, .L80249F90
/* 13CF48 80249C08 00000000 */   nop      
/* 13CF4C 80249C0C 03C0202D */  daddu     $a0, $fp, $zero
/* 13CF50 80249C10 0C09260A */  jal       pause_items_get_pos_y
/* 13CF54 80249C14 0000282D */   daddu    $a1, $zero, $zero
/* 13CF58 80249C18 8FAB007C */  lw        $t3, 0x7c($sp)
/* 13CF5C 80249C1C 8D620008 */  lw        $v0, 8($t3)
/* 13CF60 80249C20 184000D5 */  blez      $v0, .L80249F78
/* 13CF64 80249C24 0000902D */   daddu    $s2, $zero, $zero
/* 13CF68 80249C28 8FAA0054 */  lw        $t2, 0x54($sp)
/* 13CF6C 80249C2C 3C0B8027 */  lui       $t3, %hi(D_802705E8)
/* 13CF70 80249C30 256B05E8 */  addiu     $t3, $t3, %lo(D_802705E8)
/* 13CF74 80249C34 000A1080 */  sll       $v0, $t2, 2
/* 13CF78 80249C38 004B5821 */  addu      $t3, $v0, $t3
/* 13CF7C 80249C3C AFAB0078 */  sw        $t3, 0x78($sp)
.L80249C40:
/* 13CF80 80249C40 8FAA007C */  lw        $t2, 0x7c($sp)
/* 13CF84 80249C44 3C0B8027 */  lui       $t3, %hi(gItemMenuItemIDs)
/* 13CF88 80249C48 256B0400 */  addiu     $t3, $t3, %lo(gItemMenuItemIDs)
/* 13CF8C 80249C4C 8D420004 */  lw        $v0, 4($t2)
/* 13CF90 80249C50 24037FFF */  addiu     $v1, $zero, 0x7fff
/* 13CF94 80249C54 00521021 */  addu      $v0, $v0, $s2
/* 13CF98 80249C58 00021040 */  sll       $v0, $v0, 1
/* 13CF9C 80249C5C 004B1021 */  addu      $v0, $v0, $t3
/* 13CFA0 80249C60 84500000 */  lh        $s0, ($v0)
/* 13CFA4 80249C64 94560000 */  lhu       $s6, ($v0)
/* 13CFA8 80249C68 120300BD */  beq       $s0, $v1, .L80249F60
/* 13CFAC 80249C6C 0000982D */   daddu    $s3, $zero, $zero
/* 13CFB0 80249C70 03C0202D */  daddu     $a0, $fp, $zero
/* 13CFB4 80249C74 0C0925F4 */  jal       pause_items_get_pos_x
/* 13CFB8 80249C78 0240282D */   daddu    $a1, $s2, $zero
/* 13CFBC 80249C7C 03C0202D */  daddu     $a0, $fp, $zero
/* 13CFC0 80249C80 0240282D */  daddu     $a1, $s2, $zero
/* 13CFC4 80249C84 0C09260A */  jal       pause_items_get_pos_y
/* 13CFC8 80249C88 AFA20068 */   sw       $v0, 0x68($sp)
/* 13CFCC 80249C8C 0040B82D */  daddu     $s7, $v0, $zero
/* 13CFD0 80249C90 3A027FFE */  xori      $v0, $s0, 0x7ffe
/* 13CFD4 80249C94 3C038027 */  lui       $v1, %hi(gPauseMenuCurrentTab)
/* 13CFD8 80249C98 806300D4 */  lb        $v1, %lo(gPauseMenuCurrentTab)($v1)
/* 13CFDC 80249C9C 2C420001 */  sltiu     $v0, $v0, 1
/* 13CFE0 80249CA0 AFA20074 */  sw        $v0, 0x74($sp)
/* 13CFE4 80249CA4 24020003 */  addiu     $v0, $zero, 3
/* 13CFE8 80249CA8 14620012 */  bne       $v1, $v0, .L80249CF4
/* 13CFEC 80249CAC 0000A02D */   daddu    $s4, $zero, $zero
/* 13CFF0 80249CB0 3C028027 */  lui       $v0, %hi(gItemMenuLevel)
/* 13CFF4 80249CB4 8C4205E0 */  lw        $v0, %lo(gItemMenuLevel)($v0)
/* 13CFF8 80249CB8 240A0001 */  addiu     $t2, $zero, 1
/* 13CFFC 80249CBC 144A000D */  bne       $v0, $t2, .L80249CF4
/* 13D000 80249CC0 03C0202D */   daddu    $a0, $fp, $zero
/* 13D004 80249CC4 0C092626 */  jal       pause_items_get_column
/* 13D008 80249CC8 0240282D */   daddu    $a1, $s2, $zero
/* 13D00C 80249CCC 8FAB0058 */  lw        $t3, 0x58($sp)
/* 13D010 80249CD0 144B0008 */  bne       $v0, $t3, .L80249CF4
/* 13D014 80249CD4 0000A02D */   daddu    $s4, $zero, $zero
/* 13D018 80249CD8 03C0202D */  daddu     $a0, $fp, $zero
/* 13D01C 80249CDC 0C092638 */  jal       pause_items_get_row
/* 13D020 80249CE0 0240282D */   daddu    $a1, $s2, $zero
/* 13D024 80249CE4 8FAA005C */  lw        $t2, 0x5c($sp)
/* 13D028 80249CE8 004A1026 */  xor       $v0, $v0, $t2
/* 13D02C 80249CEC 2C530001 */  sltiu     $s3, $v0, 1
/* 13D030 80249CF0 0000A02D */  daddu     $s4, $zero, $zero
.L80249CF4:
/* 13D034 80249CF4 12600003 */  beqz      $s3, .L80249D04
/* 13D038 80249CF8 0280A82D */   daddu    $s5, $s4, $zero
/* 13D03C 80249CFC 2414FFFF */  addiu     $s4, $zero, -1
/* 13D040 80249D00 0280A82D */  daddu     $s5, $s4, $zero
.L80249D04:
/* 13D044 80249D04 8FAB0050 */  lw        $t3, 0x50($sp)
/* 13D048 80249D08 15600007 */  bnez      $t3, .L80249D28
/* 13D04C 80249D0C 240A0001 */   addiu    $t2, $zero, 1
/* 13D050 80249D10 240B000A */  addiu     $t3, $zero, 0xa
/* 13D054 80249D14 AFAA0060 */  sw        $t2, 0x60($sp)
/* 13D058 80249D18 12600003 */  beqz      $s3, .L80249D28
/* 13D05C 80249D1C AFAB0064 */   sw       $t3, 0x64($sp)
/* 13D060 80249D20 240A0009 */  addiu     $t2, $zero, 9
/* 13D064 80249D24 AFAA0060 */  sw        $t2, 0x60($sp)
.L80249D28:
/* 13D068 80249D28 0C09264C */  jal       pause_items_is_visible
/* 13D06C 80249D2C 02E0202D */   daddu    $a0, $s7, $zero
/* 13D070 80249D30 1040008B */  beqz      $v0, .L80249F60
/* 13D074 80249D34 00000000 */   nop      
/* 13D078 80249D38 8FAB0050 */  lw        $t3, 0x50($sp)
/* 13D07C 80249D3C 15600035 */  bnez      $t3, .L80249E14
/* 13D080 80249D40 00000000 */   nop      
/* 13D084 80249D44 8FAA0074 */  lw        $t2, 0x74($sp)
/* 13D088 80249D48 11400016 */  beqz      $t2, .L80249DA4
/* 13D08C 80249D4C 00161400 */   sll      $v0, $s6, 0x10
/* 13D090 80249D50 0C093BA0 */  jal       pause_get_menu_string
/* 13D094 80249D54 2404004E */   addiu    $a0, $zero, 0x4e
/* 13D098 80249D58 8FA40068 */  lw        $a0, 0x68($sp)
/* 13D09C 80249D5C 0C09265A */  jal       pause_items_scroll_offset_x
/* 13D0A0 80249D60 0040882D */   daddu    $s1, $v0, $zero
/* 13D0A4 80249D64 8FAB006C */  lw        $t3, 0x6c($sp)
/* 13D0A8 80249D68 02E0202D */  daddu     $a0, $s7, $zero
/* 13D0AC 80249D6C 01628021 */  addu      $s0, $t3, $v0
/* 13D0B0 80249D70 0C092656 */  jal       pause_items_scroll_offset_y
/* 13D0B4 80249D74 02148021 */   addu     $s0, $s0, $s4
/* 13D0B8 80249D78 0220202D */  daddu     $a0, $s1, $zero
/* 13D0BC 80249D7C 0200282D */  daddu     $a1, $s0, $zero
/* 13D0C0 80249D80 240700FF */  addiu     $a3, $zero, 0xff
/* 13D0C4 80249D84 8FAA0070 */  lw        $t2, 0x70($sp)
/* 13D0C8 80249D88 8FAB0064 */  lw        $t3, 0x64($sp)
/* 13D0CC 80249D8C 01421021 */  addu      $v0, $t2, $v0
/* 13D0D0 80249D90 8FAA0060 */  lw        $t2, 0x60($sp)
/* 13D0D4 80249D94 00553021 */  addu      $a2, $v0, $s5
/* 13D0D8 80249D98 AFAB0010 */  sw        $t3, 0x10($sp)
/* 13D0DC 80249D9C 08092783 */  j         .L80249E0C
/* 13D0E0 80249DA0 AFAA0014 */   sw       $t2, 0x14($sp)
.L80249DA4:
/* 13D0E4 80249DA4 000212C3 */  sra       $v0, $v0, 0xb
/* 13D0E8 80249DA8 3C0B8008 */  lui       $t3, %hi(gItemTable)
/* 13D0EC 80249DAC 256B78E0 */  addiu     $t3, $t3, %lo(gItemTable)
/* 13D0F0 80249DB0 004B8821 */  addu      $s1, $v0, $t3
/* 13D0F4 80249DB4 8E220000 */  lw        $v0, ($s1)
/* 13D0F8 80249DB8 10400016 */  beqz      $v0, .L80249E14
/* 13D0FC 80249DBC 00000000 */   nop      
/* 13D100 80249DC0 18400014 */  blez      $v0, .L80249E14
/* 13D104 80249DC4 00000000 */   nop      
/* 13D108 80249DC8 0C09265A */  jal       pause_items_scroll_offset_x
/* 13D10C 80249DCC 8FA40068 */   lw       $a0, 0x68($sp)
/* 13D110 80249DD0 8FAA006C */  lw        $t2, 0x6c($sp)
/* 13D114 80249DD4 02E0202D */  daddu     $a0, $s7, $zero
/* 13D118 80249DD8 01428021 */  addu      $s0, $t2, $v0
/* 13D11C 80249DDC 0C092656 */  jal       pause_items_scroll_offset_y
/* 13D120 80249DE0 02148021 */   addu     $s0, $s0, $s4
/* 13D124 80249DE4 0200282D */  daddu     $a1, $s0, $zero
/* 13D128 80249DE8 8FAB0070 */  lw        $t3, 0x70($sp)
/* 13D12C 80249DEC 8FAA0064 */  lw        $t2, 0x64($sp)
/* 13D130 80249DF0 01621021 */  addu      $v0, $t3, $v0
/* 13D134 80249DF4 8FAB0060 */  lw        $t3, 0x60($sp)
/* 13D138 80249DF8 240700FF */  addiu     $a3, $zero, 0xff
/* 13D13C 80249DFC AFAA0010 */  sw        $t2, 0x10($sp)
/* 13D140 80249E00 AFAB0014 */  sw        $t3, 0x14($sp)
/* 13D144 80249E04 8E240000 */  lw        $a0, ($s1)
/* 13D148 80249E08 00553021 */  addu      $a2, $v0, $s5
.L80249E0C:
/* 13D14C 80249E0C 0C04993B */  jal       draw_string
/* 13D150 80249E10 00000000 */   nop      
.L80249E14:
/* 13D154 80249E14 8FAA0050 */  lw        $t2, 0x50($sp)
/* 13D158 80249E18 240B0001 */  addiu     $t3, $zero, 1
/* 13D15C 80249E1C 154B0050 */  bne       $t2, $t3, .L80249F60
/* 13D160 80249E20 3C052000 */   lui      $a1, 0x2000
/* 13D164 80249E24 8FAA0078 */  lw        $t2, 0x78($sp)
/* 13D168 80249E28 8D510000 */  lw        $s1, ($t2)
/* 13D16C 80249E2C 0C05128B */  jal       clear_icon_flags
/* 13D170 80249E30 0220202D */   daddu    $a0, $s1, $zero
/* 13D174 80249E34 0220202D */  daddu     $a0, $s1, $zero
/* 13D178 80249E38 0C051280 */  jal       set_icon_flags
/* 13D17C 80249E3C 34058000 */   ori      $a1, $zero, 0x8000
/* 13D180 80249E40 8FAB0074 */  lw        $t3, 0x74($sp)
/* 13D184 80249E44 11600005 */  beqz      $t3, .L80249E5C
/* 13D188 80249E48 00000000 */   nop      
/* 13D18C 80249E4C 3C118027 */  lui       $s1, %hi(D_80270634)
/* 13D190 80249E50 8E310634 */  lw        $s1, %lo(D_80270634)($s1)
/* 13D194 80249E54 080927B9 */  j         .L80249EE4
/* 13D198 80249E58 00000000 */   nop      
.L80249E5C:
/* 13D19C 80249E5C 12600010 */  beqz      $s3, .L80249EA0
/* 13D1A0 80249E60 0220202D */   daddu    $a0, $s1, $zero
/* 13D1A4 80249E64 0C051280 */  jal       set_icon_flags
/* 13D1A8 80249E68 3C052000 */   lui      $a1, 0x2000
/* 13D1AC 80249E6C 00161400 */  sll       $v0, $s6, 0x10
/* 13D1B0 80249E70 000212C3 */  sra       $v0, $v0, 0xb
/* 13D1B4 80249E74 3C0A8008 */  lui       $t2, %hi(gItemTable)
/* 13D1B8 80249E78 254A78E0 */  addiu     $t2, $t2, %lo(gItemTable)
/* 13D1BC 80249E7C 004A1021 */  addu      $v0, $v0, $t2
/* 13D1C0 80249E80 84420004 */  lh        $v0, 4($v0)
/* 13D1C4 80249E84 3C0B8009 */  lui       $t3, %hi(D_8008A680)
/* 13D1C8 80249E88 256BA680 */  addiu     $t3, $t3, %lo(D_8008A680)
/* 13D1CC 80249E8C 000210C0 */  sll       $v0, $v0, 3
/* 13D1D0 80249E90 004B1021 */  addu      $v0, $v0, $t3
/* 13D1D4 80249E94 8C420000 */  lw        $v0, ($v0)
/* 13D1D8 80249E98 3C018027 */  lui       $at, %hi(gPauseMenuCurrentDescIconScript)
/* 13D1DC 80249E9C AC2200CC */  sw        $v0, %lo(gPauseMenuCurrentDescIconScript)($at)
.L80249EA0:
/* 13D1E0 80249EA0 00161400 */  sll       $v0, $s6, 0x10
/* 13D1E4 80249EA4 000212C3 */  sra       $v0, $v0, 0xb
/* 13D1E8 80249EA8 3C0A8008 */  lui       $t2, %hi(gItemTable)
/* 13D1EC 80249EAC 254A78E0 */  addiu     $t2, $t2, %lo(gItemTable)
/* 13D1F0 80249EB0 004A1021 */  addu      $v0, $v0, $t2
/* 13D1F4 80249EB4 84420004 */  lh        $v0, 4($v0)
/* 13D1F8 80249EB8 3C0B8009 */  lui       $t3, %hi(D_8008A680)
/* 13D1FC 80249EBC 256BA680 */  addiu     $t3, $t3, %lo(D_8008A680)
/* 13D200 80249EC0 000210C0 */  sll       $v0, $v0, 3
/* 13D204 80249EC4 004B1021 */  addu      $v0, $v0, $t3
/* 13D208 80249EC8 8C450000 */  lw        $a1, ($v0)
/* 13D20C 80249ECC 0C0511FF */  jal       set_menu_icon_script
/* 13D210 80249ED0 0220202D */   daddu    $a0, $s1, $zero
/* 13D214 80249ED4 3C053F2B */  lui       $a1, 0x3f2b
/* 13D218 80249ED8 34A5BA99 */  ori       $a1, $a1, 0xba99
/* 13D21C 80249EDC 0C051308 */  jal       func_80144C20
/* 13D220 80249EE0 0220202D */   daddu    $a0, $s1, $zero
.L80249EE4:
/* 13D224 80249EE4 8FA40068 */  lw        $a0, 0x68($sp)
/* 13D228 80249EE8 0C09265A */  jal       pause_items_scroll_offset_x
/* 13D22C 80249EEC 00000000 */   nop      
/* 13D230 80249EF0 02E0202D */  daddu     $a0, $s7, $zero
/* 13D234 80249EF4 8FAA00AC */  lw        $t2, 0xac($sp)
/* 13D238 80249EF8 24500069 */  addiu     $s0, $v0, 0x69
/* 13D23C 80249EFC 01508021 */  addu      $s0, $t2, $s0
/* 13D240 80249F00 0C092656 */  jal       pause_items_scroll_offset_y
/* 13D244 80249F04 02148021 */   addu     $s0, $s0, $s4
/* 13D248 80249F08 0220202D */  daddu     $a0, $s1, $zero
/* 13D24C 80249F0C 0200282D */  daddu     $a1, $s0, $zero
/* 13D250 80249F10 8FAB00B0 */  lw        $t3, 0xb0($sp)
/* 13D254 80249F14 24420017 */  addiu     $v0, $v0, 0x17
/* 13D258 80249F18 01621021 */  addu      $v0, $t3, $v0
/* 13D25C 80249F1C 0C051261 */  jal       set_icon_render_pos
/* 13D260 80249F20 00553021 */   addu     $a2, $v0, $s5
/* 13D264 80249F24 8FAA0054 */  lw        $t2, 0x54($sp)
/* 13D268 80249F28 15400005 */  bnez      $t2, .L80249F40
/* 13D26C 80249F2C 00000000 */   nop      
/* 13D270 80249F30 0C0511F8 */  jal       draw_icon_2
/* 13D274 80249F34 0220202D */   daddu    $a0, $s1, $zero
/* 13D278 80249F38 080927D2 */  j         .L80249F48
/* 13D27C 80249F3C 00000000 */   nop      
.L80249F40:
/* 13D280 80249F40 0C0511F1 */  jal       draw_icon_1
/* 13D284 80249F44 0220202D */   daddu    $a0, $s1, $zero
.L80249F48:
/* 13D288 80249F48 8FAB0078 */  lw        $t3, 0x78($sp)
/* 13D28C 80249F4C 8FAA0054 */  lw        $t2, 0x54($sp)
/* 13D290 80249F50 256B0004 */  addiu     $t3, $t3, 4
/* 13D294 80249F54 254A0001 */  addiu     $t2, $t2, 1
/* 13D298 80249F58 AFAB0078 */  sw        $t3, 0x78($sp)
/* 13D29C 80249F5C AFAA0054 */  sw        $t2, 0x54($sp)
.L80249F60:
/* 13D2A0 80249F60 8FAB007C */  lw        $t3, 0x7c($sp)
/* 13D2A4 80249F64 8D620008 */  lw        $v0, 8($t3)
/* 13D2A8 80249F68 26520001 */  addiu     $s2, $s2, 1
/* 13D2AC 80249F6C 0242102A */  slt       $v0, $s2, $v0
/* 13D2B0 80249F70 1440FF33 */  bnez      $v0, .L80249C40
/* 13D2B4 80249F74 00000000 */   nop      
.L80249F78:
/* 13D2B8 80249F78 27DE0001 */  addiu     $fp, $fp, 1
/* 13D2BC 80249F7C 8FAA007C */  lw        $t2, 0x7c($sp)
/* 13D2C0 80249F80 2BC20014 */  slti      $v0, $fp, 0x14
/* 13D2C4 80249F84 254A000C */  addiu     $t2, $t2, 0xc
/* 13D2C8 80249F88 1440FF1C */  bnez      $v0, .L80249BFC
/* 13D2CC 80249F8C AFAA007C */   sw       $t2, 0x7c($sp)
.L80249F90:
/* 13D2D0 80249F90 8FAB0050 */  lw        $t3, 0x50($sp)
/* 13D2D4 80249F94 256B0001 */  addiu     $t3, $t3, 1
/* 13D2D8 80249F98 29620003 */  slti      $v0, $t3, 3
/* 13D2DC 80249F9C 1440FF13 */  bnez      $v0, .L80249BEC
/* 13D2E0 80249FA0 AFAB0050 */   sw       $t3, 0x50($sp)
/* 13D2E4 80249FA4 3C09800A */  lui       $t1, %hi(gMasterGfxPos)
/* 13D2E8 80249FA8 2529A66C */  addiu     $t1, $t1, %lo(gMasterGfxPos)
/* 13D2EC 80249FAC 8FAA00AC */  lw        $t2, 0xac($sp)
/* 13D2F0 80249FB0 8FAB00B0 */  lw        $t3, 0xb0($sp)
/* 13D2F4 80249FB4 8D250000 */  lw        $a1, ($t1)
/* 13D2F8 80249FB8 25440001 */  addiu     $a0, $t2, 1
/* 13D2FC 80249FBC 25660001 */  addiu     $a2, $t3, 1
/* 13D300 80249FC0 00A0182D */  daddu     $v1, $a1, $zero
/* 13D304 80249FC4 8FAB00B4 */  lw        $t3, 0xb4($sp)
/* 13D308 80249FC8 24A50008 */  addiu     $a1, $a1, 8
/* 13D30C 80249FCC 014B1021 */  addu      $v0, $t2, $t3
/* 13D310 80249FD0 8FAA00B0 */  lw        $t2, 0xb0($sp)
/* 13D314 80249FD4 8FAB00B8 */  lw        $t3, 0xb8($sp)
/* 13D318 80249FD8 2447FFFF */  addiu     $a3, $v0, -1
/* 13D31C 80249FDC 014B1021 */  addu      $v0, $t2, $t3
/* 13D320 80249FE0 2448FFFF */  addiu     $t0, $v0, -1
/* 13D324 80249FE4 3C02E700 */  lui       $v0, 0xe700
/* 13D328 80249FE8 AD250000 */  sw        $a1, ($t1)
/* 13D32C 80249FEC AC620000 */  sw        $v0, ($v1)
/* 13D330 80249FF0 1C800002 */  bgtz      $a0, .L80249FFC
/* 13D334 80249FF4 AC600004 */   sw       $zero, 4($v1)
/* 13D338 80249FF8 24040001 */  addiu     $a0, $zero, 1
.L80249FFC:
/* 13D33C 80249FFC 58C00001 */  blezl     $a2, .L8024A004
/* 13D340 8024A000 24060001 */   addiu    $a2, $zero, 1
.L8024A004:
/* 13D344 8024A004 18E00129 */  blez      $a3, .L8024A4AC
/* 13D348 8024A008 00000000 */   nop      
/* 13D34C 8024A00C 19000127 */  blez      $t0, .L8024A4AC
/* 13D350 8024A010 2882013F */   slti     $v0, $a0, 0x13f
/* 13D354 8024A014 10400125 */  beqz      $v0, .L8024A4AC
/* 13D358 8024A018 28C200EF */   slti     $v0, $a2, 0xef
/* 13D35C 8024A01C 10400123 */  beqz      $v0, .L8024A4AC
/* 13D360 8024A020 28E2013F */   slti     $v0, $a3, 0x13f
/* 13D364 8024A024 50400001 */  beql      $v0, $zero, .L8024A02C
/* 13D368 8024A028 2407013F */   addiu    $a3, $zero, 0x13f
.L8024A02C:
/* 13D36C 8024A02C 290200EF */  slti      $v0, $t0, 0xef
/* 13D370 8024A030 50400001 */  beql      $v0, $zero, .L8024A038
/* 13D374 8024A034 240800EF */   addiu    $t0, $zero, 0xef
.L8024A038:
/* 13D378 8024A038 3C014080 */  lui       $at, 0x4080
/* 13D37C 8024A03C 44812000 */  mtc1      $at, $f4
/* 13D380 8024A040 44840000 */  mtc1      $a0, $f0
/* 13D384 8024A044 00000000 */  nop       
/* 13D388 8024A048 46800020 */  cvt.s.w   $f0, $f0
/* 13D38C 8024A04C 46040002 */  mul.s     $f0, $f0, $f4
/* 13D390 8024A050 00000000 */  nop       
/* 13D394 8024A054 24A20008 */  addiu     $v0, $a1, 8
/* 13D398 8024A058 44861000 */  mtc1      $a2, $f2
/* 13D39C 8024A05C 00000000 */  nop       
/* 13D3A0 8024A060 468010A0 */  cvt.s.w   $f2, $f2
/* 13D3A4 8024A064 3C04ED00 */  lui       $a0, 0xed00
/* 13D3A8 8024A068 46041082 */  mul.s     $f2, $f2, $f4
/* 13D3AC 8024A06C 00000000 */  nop       
/* 13D3B0 8024A070 AD220000 */  sw        $v0, ($t1)
/* 13D3B4 8024A074 4600018D */  trunc.w.s $f6, $f0
/* 13D3B8 8024A078 44023000 */  mfc1      $v0, $f6
/* 13D3BC 8024A07C 00000000 */  nop       
/* 13D3C0 8024A080 30420FFF */  andi      $v0, $v0, 0xfff
/* 13D3C4 8024A084 00021300 */  sll       $v0, $v0, 0xc
/* 13D3C8 8024A088 4600118D */  trunc.w.s $f6, $f2
/* 13D3CC 8024A08C 44033000 */  mfc1      $v1, $f6
/* 13D3D0 8024A090 44871000 */  mtc1      $a3, $f2
/* 13D3D4 8024A094 00000000 */  nop       
/* 13D3D8 8024A098 468010A0 */  cvt.s.w   $f2, $f2
/* 13D3DC 8024A09C 46041082 */  mul.s     $f2, $f2, $f4
/* 13D3E0 8024A0A0 00000000 */  nop       
/* 13D3E4 8024A0A4 30630FFF */  andi      $v1, $v1, 0xfff
/* 13D3E8 8024A0A8 00641825 */  or        $v1, $v1, $a0
/* 13D3EC 8024A0AC 00431025 */  or        $v0, $v0, $v1
/* 13D3F0 8024A0B0 44880000 */  mtc1      $t0, $f0
/* 13D3F4 8024A0B4 00000000 */  nop       
/* 13D3F8 8024A0B8 46800020 */  cvt.s.w   $f0, $f0
/* 13D3FC 8024A0BC 46040002 */  mul.s     $f0, $f0, $f4
/* 13D400 8024A0C0 00000000 */  nop       
/* 13D404 8024A0C4 ACA20000 */  sw        $v0, ($a1)
/* 13D408 8024A0C8 4600118D */  trunc.w.s $f6, $f2
/* 13D40C 8024A0CC 44023000 */  mfc1      $v0, $f6
/* 13D410 8024A0D0 00000000 */  nop       
/* 13D414 8024A0D4 30420FFF */  andi      $v0, $v0, 0xfff
/* 13D418 8024A0D8 00021300 */  sll       $v0, $v0, 0xc
/* 13D41C 8024A0DC 4600018D */  trunc.w.s $f6, $f0
/* 13D420 8024A0E0 44033000 */  mfc1      $v1, $f6
/* 13D424 8024A0E4 00000000 */  nop       
/* 13D428 8024A0E8 30630FFF */  andi      $v1, $v1, 0xfff
/* 13D42C 8024A0EC 00431025 */  or        $v0, $v0, $v1
/* 13D430 8024A0F0 3C038027 */  lui       $v1, %hi(gPauseMenuCurrentTab)
/* 13D434 8024A0F4 806300D4 */  lb        $v1, %lo(gPauseMenuCurrentTab)($v1)
/* 13D438 8024A0F8 ACA20004 */  sw        $v0, 4($a1)
/* 13D43C 8024A0FC 24020003 */  addiu     $v0, $zero, 3
/* 13D440 8024A100 1462002A */  bne       $v1, $v0, .L8024A1AC
/* 13D444 8024A104 24020001 */   addiu    $v0, $zero, 1
/* 13D448 8024A108 3C038027 */  lui       $v1, %hi(gItemMenuLevel)
/* 13D44C 8024A10C 8C6305E0 */  lw        $v1, %lo(gItemMenuLevel)($v1)
/* 13D450 8024A110 14620026 */  bne       $v1, $v0, .L8024A1AC
/* 13D454 8024A114 00000000 */   nop      
/* 13D458 8024A118 3C118027 */  lui       $s1, %hi(gItemMenuCurrentPage)
/* 13D45C 8024A11C 263104C8 */  addiu     $s1, $s1, %lo(gItemMenuCurrentPage)
/* 13D460 8024A120 8E220000 */  lw        $v0, ($s1)
/* 13D464 8024A124 1840000E */  blez      $v0, .L8024A160
/* 13D468 8024A128 24420001 */   addiu    $v0, $v0, 1
/* 13D46C 8024A12C 3C108027 */  lui       $s0, %hi(D_802705E8)
/* 13D470 8024A130 261005E8 */  addiu     $s0, $s0, %lo(D_802705E8)
/* 13D474 8024A134 8FAB00AC */  lw        $t3, 0xac($sp)
/* 13D478 8024A138 8E040040 */  lw        $a0, 0x40($s0)
/* 13D47C 8024A13C 8FAA00B0 */  lw        $t2, 0xb0($sp)
/* 13D480 8024A140 25650116 */  addiu     $a1, $t3, 0x116
/* 13D484 8024A144 0C051261 */  jal       set_icon_render_pos
/* 13D488 8024A148 2546000E */   addiu    $a2, $t2, 0xe
/* 13D48C 8024A14C 8E040040 */  lw        $a0, 0x40($s0)
/* 13D490 8024A150 0C0511F8 */  jal       draw_icon_2
/* 13D494 8024A154 00000000 */   nop      
/* 13D498 8024A158 8E220000 */  lw        $v0, ($s1)
/* 13D49C 8024A15C 24420001 */  addiu     $v0, $v0, 1
.L8024A160:
/* 13D4A0 8024A160 00021840 */  sll       $v1, $v0, 1
/* 13D4A4 8024A164 00621821 */  addu      $v1, $v1, $v0
/* 13D4A8 8024A168 00031880 */  sll       $v1, $v1, 2
/* 13D4AC 8024A16C 3C028027 */  lui       $v0, %hi(gItemMenuPages)
/* 13D4B0 8024A170 00431021 */  addu      $v0, $v0, $v1
/* 13D4B4 8024A174 904204D0 */  lbu       $v0, %lo(gItemMenuPages)($v0)
/* 13D4B8 8024A178 1040000C */  beqz      $v0, .L8024A1AC
/* 13D4BC 8024A17C 00000000 */   nop      
/* 13D4C0 8024A180 3C108027 */  lui       $s0, %hi(D_802705E8)
/* 13D4C4 8024A184 261005E8 */  addiu     $s0, $s0, %lo(D_802705E8)
/* 13D4C8 8024A188 8FAB00AC */  lw        $t3, 0xac($sp)
/* 13D4CC 8024A18C 8E040044 */  lw        $a0, 0x44($s0)
/* 13D4D0 8024A190 8FAA00B0 */  lw        $t2, 0xb0($sp)
/* 13D4D4 8024A194 25650116 */  addiu     $a1, $t3, 0x116
/* 13D4D8 8024A198 0C051261 */  jal       set_icon_render_pos
/* 13D4DC 8024A19C 25460092 */   addiu    $a2, $t2, 0x92
/* 13D4E0 8024A1A0 8E040044 */  lw        $a0, 0x44($s0)
/* 13D4E4 8024A1A4 0C0511F8 */  jal       draw_icon_2
/* 13D4E8 8024A1A8 00000000 */   nop      
.L8024A1AC:
/* 13D4EC 8024A1AC 3C038027 */  lui       $v1, %hi(gItemMenuCurrentTab)
/* 13D4F0 8024A1B0 8C6305E4 */  lw        $v1, %lo(gItemMenuCurrentTab)($v1)
/* 13D4F4 8024A1B4 8FA600AC */  lw        $a2, 0xac($sp)
/* 13D4F8 8024A1B8 50600001 */  beql      $v1, $zero, .L8024A1C0
/* 13D4FC 8024A1BC 24C60009 */   addiu    $a2, $a2, 9
.L8024A1C0:
/* 13D500 8024A1C0 8FAB00B0 */  lw        $t3, 0xb0($sp)
/* 13D504 8024A1C4 2402005B */  addiu     $v0, $zero, 0x5b
/* 13D508 8024A1C8 AFA20014 */  sw        $v0, 0x14($sp)
/* 13D50C 8024A1CC 24020022 */  addiu     $v0, $zero, 0x22
/* 13D510 8024A1D0 AFA20018 */  sw        $v0, 0x18($sp)
/* 13D514 8024A1D4 240200FF */  addiu     $v0, $zero, 0xff
/* 13D518 8024A1D8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 13D51C 8024A1DC 24020001 */  addiu     $v0, $zero, 1
/* 13D520 8024A1E0 AFA00010 */  sw        $zero, 0x10($sp)
/* 13D524 8024A1E4 14620004 */  bne       $v1, $v0, .L8024A1F8
/* 13D528 8024A1E8 25670007 */   addiu    $a3, $t3, 7
/* 13D52C 8024A1EC 24020080 */  addiu     $v0, $zero, 0x80
/* 13D530 8024A1F0 0809287F */  j         .L8024A1FC
/* 13D534 8024A1F4 AFA20020 */   sw       $v0, 0x20($sp)
.L8024A1F8:
/* 13D538 8024A1F8 AFA00020 */  sw        $zero, 0x20($sp)
.L8024A1FC:
/* 13D53C 8024A1FC 24040004 */  addiu     $a0, $zero, 4
/* 13D540 8024A200 3C058027 */  lui       $a1, %hi(D_8026FCB8)
/* 13D544 8024A204 24A5FCB8 */  addiu     $a1, $a1, %lo(D_8026FCB8)
/* 13D548 8024A208 24020140 */  addiu     $v0, $zero, 0x140
/* 13D54C 8024A20C AFA20044 */  sw        $v0, 0x44($sp)
/* 13D550 8024A210 240200F0 */  addiu     $v0, $zero, 0xf0
/* 13D554 8024A214 AFA00024 */  sw        $zero, 0x24($sp)
/* 13D558 8024A218 AFA00028 */  sw        $zero, 0x28($sp)
/* 13D55C 8024A21C AFA0002C */  sw        $zero, 0x2c($sp)
/* 13D560 8024A220 AFA00030 */  sw        $zero, 0x30($sp)
/* 13D564 8024A224 AFA00034 */  sw        $zero, 0x34($sp)
/* 13D568 8024A228 AFA00038 */  sw        $zero, 0x38($sp)
/* 13D56C 8024A22C AFA0003C */  sw        $zero, 0x3c($sp)
/* 13D570 8024A230 AFA00040 */  sw        $zero, 0x40($sp)
/* 13D574 8024A234 AFA20048 */  sw        $v0, 0x48($sp)
/* 13D578 8024A238 0C03D4B8 */  jal       draw_box
/* 13D57C 8024A23C AFA0004C */   sw       $zero, 0x4c($sp)
/* 13D580 8024A240 0C093BA0 */  jal       pause_get_menu_string
/* 13D584 8024A244 2404004F */   addiu    $a0, $zero, 0x4f
/* 13D588 8024A248 3C118027 */  lui       $s1, %hi(gItemMenuCurrentTab)
/* 13D58C 8024A24C 263105E4 */  addiu     $s1, $s1, %lo(gItemMenuCurrentTab)
/* 13D590 8024A250 8FAA00AC */  lw        $t2, 0xac($sp)
/* 13D594 8024A254 8E230000 */  lw        $v1, ($s1)
/* 13D598 8024A258 14600002 */  bnez      $v1, .L8024A264
/* 13D59C 8024A25C 2545000C */   addiu    $a1, $t2, 0xc
/* 13D5A0 8024A260 25450015 */  addiu     $a1, $t2, 0x15
.L8024A264:
/* 13D5A4 8024A264 240700FF */  addiu     $a3, $zero, 0xff
/* 13D5A8 8024A268 8FAB00B0 */  lw        $t3, 0xb0($sp)
/* 13D5AC 8024A26C 24100001 */  addiu     $s0, $zero, 1
/* 13D5B0 8024A270 14700002 */  bne       $v1, $s0, .L8024A27C
/* 13D5B4 8024A274 25660011 */   addiu    $a2, $t3, 0x11
/* 13D5B8 8024A278 240700BF */  addiu     $a3, $zero, 0xbf
.L8024A27C:
/* 13D5BC 8024A27C 0040202D */  daddu     $a0, $v0, $zero
/* 13D5C0 8024A280 AFA00010 */  sw        $zero, 0x10($sp)
/* 13D5C4 8024A284 0C04993B */  jal       draw_string
/* 13D5C8 8024A288 AFB00014 */   sw       $s0, 0x14($sp)
/* 13D5CC 8024A28C 8E230000 */  lw        $v1, ($s1)
/* 13D5D0 8024A290 8FA600AC */  lw        $a2, 0xac($sp)
/* 13D5D4 8024A294 50700001 */  beql      $v1, $s0, .L8024A29C
/* 13D5D8 8024A298 24C60009 */   addiu    $a2, $a2, 9
.L8024A29C:
/* 13D5DC 8024A29C 8FAA00B0 */  lw        $t2, 0xb0($sp)
/* 13D5E0 8024A2A0 2402005B */  addiu     $v0, $zero, 0x5b
/* 13D5E4 8024A2A4 AFA20014 */  sw        $v0, 0x14($sp)
/* 13D5E8 8024A2A8 24020022 */  addiu     $v0, $zero, 0x22
/* 13D5EC 8024A2AC AFA20018 */  sw        $v0, 0x18($sp)
/* 13D5F0 8024A2B0 240200FF */  addiu     $v0, $zero, 0xff
/* 13D5F4 8024A2B4 AFA00010 */  sw        $zero, 0x10($sp)
/* 13D5F8 8024A2B8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 13D5FC 8024A2BC 14600004 */  bnez      $v1, .L8024A2D0
/* 13D600 8024A2C0 25470027 */   addiu    $a3, $t2, 0x27
/* 13D604 8024A2C4 24020080 */  addiu     $v0, $zero, 0x80
/* 13D608 8024A2C8 080928B5 */  j         .L8024A2D4
/* 13D60C 8024A2CC AFA20020 */   sw       $v0, 0x20($sp)
.L8024A2D0:
/* 13D610 8024A2D0 AFA00020 */  sw        $zero, 0x20($sp)
.L8024A2D4:
/* 13D614 8024A2D4 24040004 */  addiu     $a0, $zero, 4
/* 13D618 8024A2D8 3C058027 */  lui       $a1, %hi(D_8026FCB8)
/* 13D61C 8024A2DC 24A5FCB8 */  addiu     $a1, $a1, %lo(D_8026FCB8)
/* 13D620 8024A2E0 24020140 */  addiu     $v0, $zero, 0x140
/* 13D624 8024A2E4 AFA20044 */  sw        $v0, 0x44($sp)
/* 13D628 8024A2E8 240200F0 */  addiu     $v0, $zero, 0xf0
/* 13D62C 8024A2EC AFA00024 */  sw        $zero, 0x24($sp)
/* 13D630 8024A2F0 AFA00028 */  sw        $zero, 0x28($sp)
/* 13D634 8024A2F4 AFA0002C */  sw        $zero, 0x2c($sp)
/* 13D638 8024A2F8 AFA00030 */  sw        $zero, 0x30($sp)
/* 13D63C 8024A2FC AFA00034 */  sw        $zero, 0x34($sp)
/* 13D640 8024A300 AFA00038 */  sw        $zero, 0x38($sp)
/* 13D644 8024A304 AFA0003C */  sw        $zero, 0x3c($sp)
/* 13D648 8024A308 AFA00040 */  sw        $zero, 0x40($sp)
/* 13D64C 8024A30C AFA20048 */  sw        $v0, 0x48($sp)
/* 13D650 8024A310 0C03D4B8 */  jal       draw_box
/* 13D654 8024A314 AFA0004C */   sw       $zero, 0x4c($sp)
/* 13D658 8024A318 0C093BA0 */  jal       pause_get_menu_string
/* 13D65C 8024A31C 24040050 */   addiu    $a0, $zero, 0x50
/* 13D660 8024A320 3C108027 */  lui       $s0, %hi(gItemMenuCurrentTab)
/* 13D664 8024A324 261005E4 */  addiu     $s0, $s0, %lo(gItemMenuCurrentTab)
/* 13D668 8024A328 24080001 */  addiu     $t0, $zero, 1
/* 13D66C 8024A32C 8FAB00AC */  lw        $t3, 0xac($sp)
/* 13D670 8024A330 8E030000 */  lw        $v1, ($s0)
/* 13D674 8024A334 14680002 */  bne       $v1, $t0, .L8024A340
/* 13D678 8024A338 25650019 */   addiu    $a1, $t3, 0x19
/* 13D67C 8024A33C 25650022 */  addiu     $a1, $t3, 0x22
.L8024A340:
/* 13D680 8024A340 8FAA00B0 */  lw        $t2, 0xb0($sp)
/* 13D684 8024A344 240700FF */  addiu     $a3, $zero, 0xff
/* 13D688 8024A348 14600002 */  bnez      $v1, .L8024A354
/* 13D68C 8024A34C 25460031 */   addiu    $a2, $t2, 0x31
/* 13D690 8024A350 240700BF */  addiu     $a3, $zero, 0xbf
.L8024A354:
/* 13D694 8024A354 0040202D */  daddu     $a0, $v0, $zero
/* 13D698 8024A358 AFA00010 */  sw        $zero, 0x10($sp)
/* 13D69C 8024A35C 0C04993B */  jal       draw_string
/* 13D6A0 8024A360 AFA80014 */   sw       $t0, 0x14($sp)
/* 13D6A4 8024A364 3C038027 */  lui       $v1, %hi(gPauseMenuCurrentTab)
/* 13D6A8 8024A368 806300D4 */  lb        $v1, %lo(gPauseMenuCurrentTab)($v1)
/* 13D6AC 8024A36C 24020003 */  addiu     $v0, $zero, 3
/* 13D6B0 8024A370 1462004E */  bne       $v1, $v0, .L8024A4AC
/* 13D6B4 8024A374 00000000 */   nop      
/* 13D6B8 8024A378 3C028027 */  lui       $v0, %hi(gItemMenuLevel)
/* 13D6BC 8024A37C 8C4205E0 */  lw        $v0, %lo(gItemMenuLevel)($v0)
/* 13D6C0 8024A380 14400008 */  bnez      $v0, .L8024A3A4
/* 13D6C4 8024A384 24040021 */   addiu    $a0, $zero, 0x21
/* 13D6C8 8024A388 8E060000 */  lw        $a2, ($s0)
/* 13D6CC 8024A38C 8FAB00AC */  lw        $t3, 0xac($sp)
/* 13D6D0 8024A390 8FAA00B0 */  lw        $t2, 0xb0($sp)
/* 13D6D4 8024A394 2565000C */  addiu     $a1, $t3, 0xc
/* 13D6D8 8024A398 00063140 */  sll       $a2, $a2, 5
/* 13D6DC 8024A39C 08092929 */  j         .L8024A4A4
/* 13D6E0 8024A3A0 24C6001A */   addiu    $a2, $a2, 0x1a
.L8024A3A4:
/* 13D6E4 8024A3A4 3C118027 */  lui       $s1, %hi(gItemMenuCurrentPage)
/* 13D6E8 8024A3A8 263104C8 */  addiu     $s1, $s1, %lo(gItemMenuCurrentPage)
/* 13D6EC 8024A3AC 8E240000 */  lw        $a0, ($s1)
/* 13D6F0 8024A3B0 3C128027 */  lui       $s2, %hi(gItemMenuPages)
/* 13D6F4 8024A3B4 265204D0 */  addiu     $s2, $s2, %lo(gItemMenuPages)
/* 13D6F8 8024A3B8 00041040 */  sll       $v0, $a0, 1
/* 13D6FC 8024A3BC 00441021 */  addu      $v0, $v0, $a0
/* 13D700 8024A3C0 00021080 */  sll       $v0, $v0, 2
/* 13D704 8024A3C4 00521021 */  addu      $v0, $v0, $s2
/* 13D708 8024A3C8 90430001 */  lbu       $v1, 1($v0)
/* 13D70C 8024A3CC 90420002 */  lbu       $v0, 2($v0)
/* 13D710 8024A3D0 00620018 */  mult      $v1, $v0
/* 13D714 8024A3D4 3C108027 */  lui       $s0, %hi(gItemMenuSelectedIndex)
/* 13D718 8024A3D8 261005C0 */  addiu     $s0, $s0, %lo(gItemMenuSelectedIndex)
/* 13D71C 8024A3DC 8E050000 */  lw        $a1, ($s0)
/* 13D720 8024A3E0 00005012 */  mflo      $t2
/* 13D724 8024A3E4 0C0925F4 */  jal       pause_items_get_pos_x
/* 13D728 8024A3E8 00AA2823 */   subu     $a1, $a1, $t2
/* 13D72C 8024A3EC 8E240000 */  lw        $a0, ($s1)
/* 13D730 8024A3F0 00041840 */  sll       $v1, $a0, 1
/* 13D734 8024A3F4 00641821 */  addu      $v1, $v1, $a0
/* 13D738 8024A3F8 00031880 */  sll       $v1, $v1, 2
/* 13D73C 8024A3FC 00721821 */  addu      $v1, $v1, $s2
/* 13D740 8024A400 90650001 */  lbu       $a1, 1($v1)
/* 13D744 8024A404 90630002 */  lbu       $v1, 2($v1)
/* 13D748 8024A408 00A30018 */  mult      $a1, $v1
/* 13D74C 8024A40C 8E050000 */  lw        $a1, ($s0)
/* 13D750 8024A410 0040802D */  daddu     $s0, $v0, $zero
/* 13D754 8024A414 00005012 */  mflo      $t2
/* 13D758 8024A418 0C09260A */  jal       pause_items_get_pos_y
/* 13D75C 8024A41C 00AA2823 */   subu     $a1, $a1, $t2
/* 13D760 8024A420 0200202D */  daddu     $a0, $s0, $zero
/* 13D764 8024A424 0C09265A */  jal       pause_items_scroll_offset_x
/* 13D768 8024A428 0040802D */   daddu    $s0, $v0, $zero
/* 13D76C 8024A42C 0200202D */  daddu     $a0, $s0, $zero
/* 13D770 8024A430 0C092656 */  jal       pause_items_scroll_offset_y
/* 13D774 8024A434 0040802D */   daddu    $s0, $v0, $zero
/* 13D778 8024A438 0040302D */  daddu     $a2, $v0, $zero
/* 13D77C 8024A43C 04C10003 */  bgez      $a2, .L8024A44C
/* 13D780 8024A440 28C20071 */   slti     $v0, $a2, 0x71
/* 13D784 8024A444 08092915 */  j         .L8024A454
/* 13D788 8024A448 0000302D */   daddu    $a2, $zero, $zero
.L8024A44C:
/* 13D78C 8024A44C 50400001 */  beql      $v0, $zero, .L8024A454
/* 13D790 8024A450 24060070 */   addiu    $a2, $zero, 0x70
.L8024A454:
/* 13D794 8024A454 3C038027 */  lui       $v1, %hi(gItemMenuCurrentScrollPos)
/* 13D798 8024A458 8C6305D4 */  lw        $v1, %lo(gItemMenuCurrentScrollPos)($v1)
/* 13D79C 8024A45C 3C028027 */  lui       $v0, %hi(gItemMenuTargetScrollPos)
/* 13D7A0 8024A460 8C4205D8 */  lw        $v0, %lo(gItemMenuTargetScrollPos)($v0)
/* 13D7A4 8024A464 1062000A */  beq       $v1, $v0, .L8024A490
/* 13D7A8 8024A468 24040021 */   addiu    $a0, $zero, 0x21
/* 13D7AC 8024A46C 26050055 */  addiu     $a1, $s0, 0x55
/* 13D7B0 8024A470 24C60017 */  addiu     $a2, $a2, 0x17
/* 13D7B4 8024A474 8FAB00AC */  lw        $t3, 0xac($sp)
/* 13D7B8 8024A478 8FAA00B0 */  lw        $t2, 0xb0($sp)
/* 13D7BC 8024A47C 01652821 */  addu      $a1, $t3, $a1
/* 13D7C0 8024A480 0C090AEB */  jal       func_80242BAC
/* 13D7C4 8024A484 01463021 */   addu     $a2, $t2, $a2
/* 13D7C8 8024A488 0809292B */  j         .L8024A4AC
/* 13D7CC 8024A48C 00000000 */   nop      
.L8024A490:
/* 13D7D0 8024A490 26050055 */  addiu     $a1, $s0, 0x55
/* 13D7D4 8024A494 24C60017 */  addiu     $a2, $a2, 0x17
/* 13D7D8 8024A498 8FAB00AC */  lw        $t3, 0xac($sp)
/* 13D7DC 8024A49C 8FAA00B0 */  lw        $t2, 0xb0($sp)
/* 13D7E0 8024A4A0 01652821 */  addu      $a1, $t3, $a1
.L8024A4A4:
/* 13D7E4 8024A4A4 0C090B41 */  jal       func_80242D04
/* 13D7E8 8024A4A8 01463021 */   addu     $a2, $t2, $a2
.L8024A4AC:
/* 13D7EC 8024A4AC 8FBF00A4 */  lw        $ra, 0xa4($sp)
/* 13D7F0 8024A4B0 8FBE00A0 */  lw        $fp, 0xa0($sp)
/* 13D7F4 8024A4B4 8FB7009C */  lw        $s7, 0x9c($sp)
/* 13D7F8 8024A4B8 8FB60098 */  lw        $s6, 0x98($sp)
/* 13D7FC 8024A4BC 8FB50094 */  lw        $s5, 0x94($sp)
/* 13D800 8024A4C0 8FB40090 */  lw        $s4, 0x90($sp)
/* 13D804 8024A4C4 8FB3008C */  lw        $s3, 0x8c($sp)
/* 13D808 8024A4C8 8FB20088 */  lw        $s2, 0x88($sp)
/* 13D80C 8024A4CC 8FB10084 */  lw        $s1, 0x84($sp)
/* 13D810 8024A4D0 8FB00080 */  lw        $s0, 0x80($sp)
/* 13D814 8024A4D4 03E00008 */  jr        $ra
/* 13D818 8024A4D8 27BD00A8 */   addiu    $sp, $sp, 0xa8
