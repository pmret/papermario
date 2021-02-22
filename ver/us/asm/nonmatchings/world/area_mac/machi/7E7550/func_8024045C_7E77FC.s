.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024045C_7E77FC
/* 7E77FC 8024045C 2404000B */  addiu     $a0, $zero, 0xb
/* 7E7800 80240460 3C058011 */  lui       $a1, %hi(gPlayerData)
/* 7E7804 80240464 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* 7E7808 80240468 24A30058 */  addiu     $v1, $a1, 0x58
/* 7E780C 8024046C 0080102D */  daddu     $v0, $a0, $zero
/* 7E7810 80240470 A0A20002 */  sb        $v0, 2($a1)
/* 7E7814 80240474 A0A20003 */  sb        $v0, 3($a1)
/* 7E7818 80240478 A0A00000 */  sb        $zero, ($a1)
/* 7E781C 8024047C A0A00001 */  sb        $zero, 1($a1)
/* 7E7820 80240480 A0A0000E */  sb        $zero, 0xe($a1)
.L80240484:
/* 7E7824 80240484 A0600014 */  sb        $zero, 0x14($v1)
/* 7E7828 80240488 2484FFFF */  addiu     $a0, $a0, -1
/* 7E782C 8024048C 0481FFFD */  bgez      $a0, .L80240484
/* 7E7830 80240490 2463FFF8 */   addiu    $v1, $v1, -8
/* 7E7834 80240494 24020001 */  addiu     $v0, $zero, 1
/* 7E7838 80240498 A0A20014 */  sb        $v0, 0x14($a1)
/* 7E783C 8024049C A0A2001C */  sb        $v0, 0x1c($a1)
/* 7E7840 802404A0 A0A2002C */  sb        $v0, 0x2c($a1)
/* 7E7844 802404A4 03E00008 */  jr        $ra
/* 7E7848 802404A8 24020002 */   addiu    $v0, $zero, 2
/* 7E784C 802404AC 00000000 */  nop
