.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242250
/* 7ECF60 80242250 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 7ECF64 80242254 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 7ECF68 80242258 8C6202BC */  lw        $v0, 0x2bc($v1)
/* 7ECF6C 8024225C 8C630324 */  lw        $v1, 0x324($v1)
/* 7ECF70 80242260 00431023 */  subu      $v0, $v0, $v1
/* 7ECF74 80242264 3C0391A2 */  lui       $v1, 0x91a2
/* 7ECF78 80242268 3463B3C5 */  ori       $v1, $v1, 0xb3c5
/* 7ECF7C 8024226C 00430019 */  multu     $v0, $v1
/* 7ECF80 80242270 8C830084 */  lw        $v1, 0x84($a0)
/* 7ECF84 80242274 00002810 */  mfhi      $a1
/* 7ECF88 80242278 000512C2 */  srl       $v0, $a1, 0xb
/* 7ECF8C 8024227C 0043102A */  slt       $v0, $v0, $v1
/* 7ECF90 80242280 AC820084 */  sw        $v0, 0x84($a0)
/* 7ECF94 80242284 03E00008 */  jr        $ra
/* 7ECF98 80242288 24020002 */   addiu    $v0, $zero, 2
