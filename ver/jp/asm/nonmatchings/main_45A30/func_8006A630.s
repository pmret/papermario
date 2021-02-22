.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006A630
/* 45A30 8006A630 3C05A460 */  lui       $a1, 0xa460
/* 45A34 8006A634 34A50014 */  ori       $a1, $a1, 0x14
/* 45A38 8006A638 3C06A460 */  lui       $a2, 0xa460
/* 45A3C 8006A63C 34C60018 */  ori       $a2, $a2, 0x18
/* 45A40 8006A640 3C07A460 */  lui       $a3, 0xa460
/* 45A44 8006A644 34E7001C */  ori       $a3, $a3, 0x1c
/* 45A48 8006A648 3C08A460 */  lui       $t0, 0xa460
/* 45A4C 8006A64C 35080020 */  ori       $t0, $t0, 0x20
/* 45A50 8006A650 3C09A460 */  lui       $t1, 0xa460
/* 45A54 8006A654 35290024 */  ori       $t1, $t1, 0x24
/* 45A58 8006A658 3C04A460 */  lui       $a0, 0xa460
/* 45A5C 8006A65C 34840028 */  ori       $a0, $a0, 0x28
/* 45A60 8006A660 3C03A460 */  lui       $v1, 0xa460
/* 45A64 8006A664 3463002C */  ori       $v1, $v1, 0x2c
/* 45A68 8006A668 3C02A460 */  lui       $v0, 0xa460
/* 45A6C 8006A66C 34420030 */  ori       $v0, $v0, 0x30
/* 45A70 8006A670 8CA50000 */  lw        $a1, ($a1)
/* 45A74 8006A674 8CC60000 */  lw        $a2, ($a2)
/* 45A78 8006A678 8CE70000 */  lw        $a3, ($a3)
/* 45A7C 8006A67C 8D080000 */  lw        $t0, ($t0)
/* 45A80 8006A680 8D290000 */  lw        $t1, ($t1)
/* 45A84 8006A684 8C840000 */  lw        $a0, ($a0)
/* 45A88 8006A688 8C630000 */  lw        $v1, ($v1)
/* 45A8C 8006A68C 8C4A0000 */  lw        $t2, ($v0)
/* 45A90 8006A690 24020007 */  addiu     $v0, $zero, 7
/* 45A94 8006A694 3C01800B */  lui       $at, %hi(D_800B44FC)
/* 45A98 8006A698 A02244FC */  sb        $v0, %lo(D_800B44FC)($at)
/* 45A9C 8006A69C 3C01800B */  lui       $at, %hi(D_800B1AEC)
/* 45AA0 8006A6A0 A0221AEC */  sb        $v0, %lo(D_800B1AEC)($at)
/* 45AA4 8006A6A4 3C01800B */  lui       $at, %hi(D_800B44FD)
/* 45AA8 8006A6A8 A02544FD */  sb        $a1, %lo(D_800B44FD)($at)
/* 45AAC 8006A6AC 3C01800B */  lui       $at, %hi(D_800B4500)
/* 45AB0 8006A6B0 A0264500 */  sb        $a2, %lo(D_800B4500)($at)
/* 45AB4 8006A6B4 3C01800B */  lui       $at, %hi(D_800B44FE)
/* 45AB8 8006A6B8 A02744FE */  sb        $a3, %lo(D_800B44FE)($at)
/* 45ABC 8006A6BC 3C01800B */  lui       $at, %hi(D_800B44FF)
/* 45AC0 8006A6C0 A02844FF */  sb        $t0, %lo(D_800B44FF)($at)
/* 45AC4 8006A6C4 3C01800B */  lui       $at, %hi(D_800B1AED)
/* 45AC8 8006A6C8 A0291AED */  sb        $t1, %lo(D_800B1AED)($at)
/* 45ACC 8006A6CC 3C01800B */  lui       $at, %hi(D_800B1AF0)
/* 45AD0 8006A6D0 A0241AF0 */  sb        $a0, %lo(D_800B1AF0)($at)
/* 45AD4 8006A6D4 3C01800B */  lui       $at, %hi(D_800B1AEE)
/* 45AD8 8006A6D8 A0231AEE */  sb        $v1, %lo(D_800B1AEE)($at)
/* 45ADC 8006A6DC 3C01800B */  lui       $at, %hi(D_800B1AEF)
/* 45AE0 8006A6E0 03E00008 */  jr        $ra
/* 45AE4 8006A6E4 A02A1AEF */   sb       $t2, %lo(D_800B1AEF)($at)
