.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243380_8554F0
/* 8554F0 80243380 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 8554F4 80243384 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 8554F8 80243388 8C6202BC */  lw        $v0, 0x2bc($v1)
/* 8554FC 8024338C 8C630324 */  lw        $v1, 0x324($v1)
/* 855500 80243390 00431023 */  subu      $v0, $v0, $v1
/* 855504 80243394 3C0391A2 */  lui       $v1, 0x91a2
/* 855508 80243398 3463B3C5 */  ori       $v1, $v1, 0xb3c5
/* 85550C 8024339C 00430019 */  multu     $v0, $v1
/* 855510 802433A0 8C830084 */  lw        $v1, 0x84($a0)
/* 855514 802433A4 00002810 */  mfhi      $a1
/* 855518 802433A8 000512C2 */  srl       $v0, $a1, 0xb
/* 85551C 802433AC 0043102A */  slt       $v0, $v0, $v1
/* 855520 802433B0 AC820084 */  sw        $v0, 0x84($a0)
/* 855524 802433B4 03E00008 */  jr        $ra
/* 855528 802433B8 24020002 */   addiu    $v0, $zero, 2
