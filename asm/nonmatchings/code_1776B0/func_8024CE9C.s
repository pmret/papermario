.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024CE9C
/* 17B77C 8024CE9C 24020008 */  addiu     $v0, $zero, 8
/* 17B780 8024CEA0 3C01802A */  lui       $at, %hi(D_8029F284)
/* 17B784 8024CEA4 A422F284 */  sh        $v0, %lo(D_8029F284)($at)
/* 17B788 8024CEA8 3C02800B */  lui       $v0, %hi(D_800B22D8)
/* 17B78C 8024CEAC 244222D8 */  addiu     $v0, $v0, %lo(D_800B22D8)
/* 17B790 8024CEB0 8443001C */  lh        $v1, 0x1c($v0)
/* 17B794 8024CEB4 8444001E */  lh        $a0, 0x1e($v0)
/* 17B798 8024CEB8 A4400024 */  sh        $zero, 0x24($v0)
/* 17B79C 8024CEBC A4400026 */  sh        $zero, 0x26($v0)
/* 17B7A0 8024CEC0 84420022 */  lh        $v0, 0x22($v0)
/* 17B7A4 8024CEC4 44801000 */  mtc1      $zero, $f2
/* 17B7A8 8024CEC8 3C01802A */  lui       $at, %hi(D_8029F286)
/* 17B7AC 8024CECC A420F286 */  sh        $zero, %lo(D_8029F286)($at)
/* 17B7B0 8024CED0 3C01802A */  lui       $at, %hi(D_8029F282)
/* 17B7B4 8024CED4 A420F282 */  sh        $zero, %lo(D_8029F282)($at)
/* 17B7B8 8024CED8 3C018028 */  lui       $at, %hi(D_80280CE0)
/* 17B7BC 8024CEDC A0200CE0 */  sb        $zero, %lo(D_80280CE0)($at)
/* 17B7C0 8024CEE0 44830000 */  mtc1      $v1, $f0
/* 17B7C4 8024CEE4 00000000 */  nop       
/* 17B7C8 8024CEE8 46800020 */  cvt.s.w   $f0, $f0
/* 17B7CC 8024CEEC 3C01802A */  lui       $at, %hi(D_8029F288)
/* 17B7D0 8024CEF0 E420F288 */  swc1      $f0, %lo(D_8029F288)($at)
/* 17B7D4 8024CEF4 44840000 */  mtc1      $a0, $f0
/* 17B7D8 8024CEF8 00000000 */  nop       
/* 17B7DC 8024CEFC 46800020 */  cvt.s.w   $f0, $f0
/* 17B7E0 8024CF00 3C01802A */  lui       $at, %hi(D_8029F28C)
/* 17B7E4 8024CF04 E420F28C */  swc1      $f0, %lo(D_8029F28C)($at)
/* 17B7E8 8024CF08 44820000 */  mtc1      $v0, $f0
/* 17B7EC 8024CF0C 00000000 */  nop       
/* 17B7F0 8024CF10 46800020 */  cvt.s.w   $f0, $f0
/* 17B7F4 8024CF14 3C01802A */  lui       $at, %hi(D_8029F294)
/* 17B7F8 8024CF18 E420F294 */  swc1      $f0, %lo(D_8029F294)($at)
/* 17B7FC 8024CF1C 3C01802A */  lui       $at, %hi(D_8029F290)
/* 17B800 8024CF20 E422F290 */  swc1      $f2, %lo(D_8029F290)($at)
/* 17B804 8024CF24 3C01802A */  lui       $at, %hi(D_8029F298)
/* 17B808 8024CF28 E422F298 */  swc1      $f2, %lo(D_8029F298)($at)
/* 17B80C 8024CF2C 03E00008 */  jr        $ra
/* 17B810 8024CF30 24020002 */   addiu    $v0, $zero, 2
