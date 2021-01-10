.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80239190_6F2270
/* 6F2270 80239190 3C028024 */  lui       $v0, %hi(D_8023CDA4)
/* 6F2274 80239194 8C42CDA4 */  lw        $v0, %lo(D_8023CDA4)($v0)
/* 6F2278 80239198 54400002 */  bnel      $v0, $zero, .L802391A4
/* 6F227C 8023919C 24020025 */   addiu    $v0, $zero, 0x25
/* 6F2280 802391A0 24020024 */  addiu     $v0, $zero, 0x24
.L802391A4:
/* 6F2284 802391A4 AC820084 */  sw        $v0, 0x84($a0)
/* 6F2288 802391A8 03E00008 */  jr        $ra
/* 6F228C 802391AC 24020002 */   addiu    $v0, $zero, 2
