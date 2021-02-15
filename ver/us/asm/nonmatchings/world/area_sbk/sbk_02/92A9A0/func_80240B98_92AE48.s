.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B98_92AE48
/* 92AE48 80240B98 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 92AE4C 80240B9C 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 92AE50 80240BA0 8C6202BC */  lw        $v0, 0x2bc($v1)
/* 92AE54 80240BA4 8C630324 */  lw        $v1, 0x324($v1)
/* 92AE58 80240BA8 00431023 */  subu      $v0, $v0, $v1
/* 92AE5C 80240BAC 3C0391A2 */  lui       $v1, 0x91a2
/* 92AE60 80240BB0 3463B3C5 */  ori       $v1, $v1, 0xb3c5
/* 92AE64 80240BB4 00430019 */  multu     $v0, $v1
/* 92AE68 80240BB8 8C830084 */  lw        $v1, 0x84($a0)
/* 92AE6C 80240BBC 00002810 */  mfhi      $a1
/* 92AE70 80240BC0 000512C2 */  srl       $v0, $a1, 0xb
/* 92AE74 80240BC4 0043102A */  slt       $v0, $v0, $v1
/* 92AE78 80240BC8 AC820084 */  sw        $v0, 0x84($a0)
/* 92AE7C 80240BCC 03E00008 */  jr        $ra
/* 92AE80 80240BD0 24020002 */   addiu    $v0, $zero, 2
