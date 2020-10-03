.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006A650
/* 45A50 8006A650 3C05A460 */  lui       $a1, 0xa460
/* 45A54 8006A654 34A50014 */  ori       $a1, $a1, 0x14
/* 45A58 8006A658 3C06A460 */  lui       $a2, 0xa460
/* 45A5C 8006A65C 34C60018 */  ori       $a2, $a2, 0x18
/* 45A60 8006A660 3C07A460 */  lui       $a3, 0xa460
/* 45A64 8006A664 34E7001C */  ori       $a3, $a3, 0x1c
/* 45A68 8006A668 3C08A460 */  lui       $t0, 0xa460
/* 45A6C 8006A66C 35080020 */  ori       $t0, $t0, 0x20
/* 45A70 8006A670 3C09A460 */  lui       $t1, 0xa460
/* 45A74 8006A674 35290024 */  ori       $t1, $t1, 0x24
/* 45A78 8006A678 3C04A460 */  lui       $a0, 0xa460
/* 45A7C 8006A67C 34840028 */  ori       $a0, $a0, 0x28
/* 45A80 8006A680 3C03A460 */  lui       $v1, 0xa460
/* 45A84 8006A684 3463002C */  ori       $v1, $v1, 0x2c
/* 45A88 8006A688 3C02A460 */  lui       $v0, 0xa460
/* 45A8C 8006A68C 34420030 */  ori       $v0, $v0, 0x30
/* 45A90 8006A690 8CA50000 */  lw        $a1, ($a1)
/* 45A94 8006A694 8CC60000 */  lw        $a2, ($a2)
/* 45A98 8006A698 8CE70000 */  lw        $a3, ($a3)
/* 45A9C 8006A69C 8D080000 */  lw        $t0, ($t0)
/* 45AA0 8006A6A0 8D290000 */  lw        $t1, ($t1)
/* 45AA4 8006A6A4 8C840000 */  lw        $a0, ($a0)
/* 45AA8 8006A6A8 8C630000 */  lw        $v1, ($v1)
/* 45AAC 8006A6AC 8C4A0000 */  lw        $t2, ($v0)
/* 45AB0 8006A6B0 24020007 */  addiu     $v0, $zero, 7
/* 45AB4 8006A6B4 3C01800B */  lui       $at, 0x800b
/* 45AB8 8006A6B8 A022451C */  sb        $v0, 0x451c($at)
/* 45ABC 8006A6BC 3C01800B */  lui       $at, 0x800b
/* 45AC0 8006A6C0 A0221B0C */  sb        $v0, 0x1b0c($at)
/* 45AC4 8006A6C4 3C01800B */  lui       $at, 0x800b
/* 45AC8 8006A6C8 A025451D */  sb        $a1, 0x451d($at)
/* 45ACC 8006A6CC 3C01800B */  lui       $at, 0x800b
/* 45AD0 8006A6D0 A0264520 */  sb        $a2, 0x4520($at)
/* 45AD4 8006A6D4 3C01800B */  lui       $at, 0x800b
/* 45AD8 8006A6D8 A027451E */  sb        $a3, 0x451e($at)
/* 45ADC 8006A6DC 3C01800B */  lui       $at, 0x800b
/* 45AE0 8006A6E0 A028451F */  sb        $t0, 0x451f($at)
/* 45AE4 8006A6E4 3C01800B */  lui       $at, 0x800b
/* 45AE8 8006A6E8 A0291B0D */  sb        $t1, 0x1b0d($at)
/* 45AEC 8006A6EC 3C01800B */  lui       $at, 0x800b
/* 45AF0 8006A6F0 A0241B10 */  sb        $a0, 0x1b10($at)
/* 45AF4 8006A6F4 3C01800B */  lui       $at, 0x800b
/* 45AF8 8006A6F8 A0231B0E */  sb        $v1, 0x1b0e($at)
/* 45AFC 8006A6FC 3C01800B */  lui       $at, 0x800b
/* 45B00 8006A700 03E00008 */  jr        $ra
/* 45B04 8006A704 A02A1B0F */   sb       $t2, 0x1b0f($at)
