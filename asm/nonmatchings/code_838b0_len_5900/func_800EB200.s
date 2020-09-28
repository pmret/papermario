.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EB200
/* 846B0 800EB200 3C058011 */  lui       $a1, %hi(gPlayerStatus)
/* 846B4 800EB204 24A5EFC8 */  addiu     $a1, $a1, %lo(gPlayerStatus)
/* 846B8 800EB208 3C038011 */  lui       $v1, 0x8011
/* 846BC 800EB20C 8C63CFD8 */  lw        $v1, -0x3028($v1)
/* 846C0 800EB210 3C068011 */  lui       $a2, %hi(D_8010EBB0)
/* 846C4 800EB214 24C6EBB0 */  addiu     $a2, $a2, %lo(D_8010EBB0)
/* 846C8 800EB218 1064000D */  beq       $v1, $a0, .L800EB250
/* 846CC 800EB21C 24020001 */   addiu    $v0, $zero, 1
/* 846D0 800EB220 3C018011 */  lui       $at, 0x8011
/* 846D4 800EB224 AC22CFE0 */  sw        $v0, -0x3020($at)
/* 846D8 800EB228 3C018011 */  lui       $at, 0x8011
/* 846DC 800EB22C AC24CFE4 */  sw        $a0, -0x301c($at)
/* 846E0 800EB230 A0C00000 */  sb        $zero, ($a2)
/* 846E4 800EB234 10600008 */  beqz      $v1, .L800EB258
/* 846E8 800EB238 A0C00001 */   sb       $zero, 1($a2)
/* 846EC 800EB23C 10800009 */  beqz      $a0, .L800EB264
/* 846F0 800EB240 24020004 */   addiu    $v0, $zero, 4
/* 846F4 800EB244 24020002 */  addiu     $v0, $zero, 2
/* 846F8 800EB248 3C018011 */  lui       $at, 0x8011
/* 846FC 800EB24C AC22CFE8 */  sw        $v0, -0x3018($at)
.L800EB250:
/* 84700 800EB250 03E00008 */  jr        $ra
/* 84704 800EB254 00000000 */   nop      
.L800EB258:
/* 84708 800EB258 14800006 */  bnez      $a0, .L800EB274
/* 8470C 800EB25C 24020006 */   addiu    $v0, $zero, 6
/* 84710 800EB260 24020004 */  addiu     $v0, $zero, 4
.L800EB264:
/* 84714 800EB264 3C018011 */  lui       $at, 0x8011
/* 84718 800EB268 AC22CFE8 */  sw        $v0, -0x3018($at)
/* 8471C 800EB26C 03E00008 */  jr        $ra
/* 84720 800EB270 00000000 */   nop      
.L800EB274:
/* 84724 800EB274 C4A00028 */  lwc1      $f0, 0x28($a1)
/* 84728 800EB278 C4A2002C */  lwc1      $f2, 0x2c($a1)
/* 8472C 800EB27C C4A40030 */  lwc1      $f4, 0x30($a1)
/* 84730 800EB280 3C018011 */  lui       $at, 0x8011
/* 84734 800EB284 AC22CFE8 */  sw        $v0, -0x3018($at)
/* 84738 800EB288 3C018010 */  lui       $at, 0x8010
/* 8473C 800EB28C E420833C */  swc1      $f0, -0x7cc4($at)
/* 84740 800EB290 3C018010 */  lui       $at, 0x8010
/* 84744 800EB294 E4228340 */  swc1      $f2, -0x7cc0($at)
/* 84748 800EB298 3C018010 */  lui       $at, 0x8010
/* 8474C 800EB29C 03E00008 */  jr        $ra
/* 84750 800EB2A0 E4248344 */   swc1     $f4, -0x7cbc($at)
