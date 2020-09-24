.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8010FE68
/* A6568 8010FE68 3C07FCFF */  lui       $a3, 0xfcff
/* A656C 8010FE6C 34E7B3FF */  ori       $a3, $a3, 0xb3ff
/* A6570 8010FE70 3C06FF2F */  lui       $a2, 0xff2f
/* A6574 8010FE74 3C05800A */  lui       $a1, 0x800a
/* A6578 8010FE78 24A5A66C */  addiu     $a1, $a1, -0x5994
/* A657C 8010FE7C 34C6FFFF */  ori       $a2, $a2, 0xffff
/* A6580 8010FE80 8CA20000 */  lw        $v0, ($a1)
/* A6584 8010FE84 308400FF */  andi      $a0, $a0, 0xff
/* A6588 8010FE88 0040182D */  daddu     $v1, $v0, $zero
/* A658C 8010FE8C 24420008 */  addiu     $v0, $v0, 8
/* A6590 8010FE90 ACA20000 */  sw        $v0, ($a1)
/* A6594 8010FE94 AC670000 */  sw        $a3, ($v1)
/* A6598 8010FE98 AC660004 */  sw        $a2, 4($v1)
/* A659C 8010FE9C 24430008 */  addiu     $v1, $v0, 8
/* A65A0 8010FEA0 ACA30000 */  sw        $v1, ($a1)
/* A65A4 8010FEA4 3C03FA00 */  lui       $v1, 0xfa00
/* A65A8 8010FEA8 AC430000 */  sw        $v1, ($v0)
/* A65AC 8010FEAC 03E00008 */  jr        $ra
/* A65B0 8010FEB0 AC440004 */   sw       $a0, 4($v0)
