.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel spr_make_quad_for_size
/* FEEAC 802DBDBC 0080382D */  daddu     $a3, $a0, $zero
/* FEEB0 802DBDC0 00A0402D */  daddu     $t0, $a1, $zero
/* FEEB4 802DBDC4 00E0182D */  daddu     $v1, $a3, $zero
/* FEEB8 802DBDC8 3C02802E */  lui       $v0, %hi(spr_defaultQuad)
/* FEEBC 802DBDCC 2442F390 */  addiu     $v0, $v0, %lo(spr_defaultQuad)
/* FEEC0 802DBDD0 24440040 */  addiu     $a0, $v0, 0x40
.L802DBDD4:
/* FEEC4 802DBDD4 8C490000 */  lw        $t1, ($v0)
/* FEEC8 802DBDD8 8C4A0004 */  lw        $t2, 4($v0)
/* FEECC 802DBDDC 8C4B0008 */  lw        $t3, 8($v0)
/* FEED0 802DBDE0 8C4C000C */  lw        $t4, 0xc($v0)
/* FEED4 802DBDE4 AC690000 */  sw        $t1, ($v1)
/* FEED8 802DBDE8 AC6A0004 */  sw        $t2, 4($v1)
/* FEEDC 802DBDEC AC6B0008 */  sw        $t3, 8($v1)
/* FEEE0 802DBDF0 AC6C000C */  sw        $t4, 0xc($v1)
/* FEEE4 802DBDF4 24420010 */  addiu     $v0, $v0, 0x10
/* FEEE8 802DBDF8 1444FFF6 */  bne       $v0, $a0, .L802DBDD4
/* FEEEC 802DBDFC 24630010 */   addiu    $v1, $v1, 0x10
/* FEEF0 802DBE00 00082023 */  negu      $a0, $t0
/* FEEF4 802DBE04 000417C2 */  srl       $v0, $a0, 0x1f
/* FEEF8 802DBE08 00822021 */  addu      $a0, $a0, $v0
/* FEEFC 802DBE0C 00042043 */  sra       $a0, $a0, 1
/* FEF00 802DBE10 24052000 */  addiu     $a1, $zero, 0x2000
/* FEF04 802DBE14 A4E40000 */  sh        $a0, ($a3)
/* FEF08 802DBE18 A4E60002 */  sh        $a2, 2($a3)
/* FEF0C 802DBE1C A4E50008 */  sh        $a1, 8($a3)
/* FEF10 802DBE20 A4E5000A */  sh        $a1, 0xa($a3)
/* FEF14 802DBE24 24E70010 */  addiu     $a3, $a3, 0x10
/* FEF18 802DBE28 00081FC2 */  srl       $v1, $t0, 0x1f
/* FEF1C 802DBE2C 01031821 */  addu      $v1, $t0, $v1
/* FEF20 802DBE30 00031843 */  sra       $v1, $v1, 1
/* FEF24 802DBE34 25020100 */  addiu     $v0, $t0, 0x100
/* FEF28 802DBE38 00021140 */  sll       $v0, $v0, 5
/* FEF2C 802DBE3C A4E30000 */  sh        $v1, ($a3)
/* FEF30 802DBE40 A4E60002 */  sh        $a2, 2($a3)
/* FEF34 802DBE44 A4E20008 */  sh        $v0, 8($a3)
/* FEF38 802DBE48 A4E5000A */  sh        $a1, 0xa($a3)
/* FEF3C 802DBE4C 24E70010 */  addiu     $a3, $a3, 0x10
/* FEF40 802DBE50 A4E20008 */  sh        $v0, 8($a3)
/* FEF44 802DBE54 24C20100 */  addiu     $v0, $a2, 0x100
/* FEF48 802DBE58 00021140 */  sll       $v0, $v0, 5
/* FEF4C 802DBE5C A4E30000 */  sh        $v1, ($a3)
/* FEF50 802DBE60 A4E2000A */  sh        $v0, 0xa($a3)
/* FEF54 802DBE64 24E70010 */  addiu     $a3, $a3, 0x10
/* FEF58 802DBE68 A4E40000 */  sh        $a0, ($a3)
/* FEF5C 802DBE6C A4E50008 */  sh        $a1, 8($a3)
/* FEF60 802DBE70 03E00008 */  jr        $ra
/* FEF64 802DBE74 A4E2000A */   sh       $v0, 0xa($a3)
