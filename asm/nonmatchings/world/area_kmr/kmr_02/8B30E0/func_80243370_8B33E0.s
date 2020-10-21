.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243370_8B33E0
/* 8B33E0 80243370 0000302D */  daddu     $a2, $zero, $zero
/* 8B33E4 80243374 00C0282D */  daddu     $a1, $a2, $zero
/* 8B33E8 80243378 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 8B33EC 8024337C 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
.L80243380:
/* 8B33F0 80243380 84620208 */  lh        $v0, 0x208($v1)
/* 8B33F4 80243384 10400003 */  beqz      $v0, .L80243394
/* 8B33F8 80243388 24A50001 */   addiu    $a1, $a1, 1
/* 8B33FC 8024338C 08090CE8 */  j         .L802433A0
/* 8B3400 80243390 24060001 */   addiu    $a2, $zero, 1
.L80243394:
/* 8B3404 80243394 28A20040 */  slti      $v0, $a1, 0x40
/* 8B3408 80243398 1440FFF9 */  bnez      $v0, .L80243380
/* 8B340C 8024339C 24630002 */   addiu    $v1, $v1, 2
.L802433A0:
/* 8B3410 802433A0 AC860084 */  sw        $a2, 0x84($a0)
/* 8B3414 802433A4 03E00008 */  jr        $ra
/* 8B3418 802433A8 24020002 */   addiu    $v0, $zero, 2
