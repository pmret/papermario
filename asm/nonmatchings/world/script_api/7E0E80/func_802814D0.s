.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802814D0
/* 7E2350 802814D0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7E2354 802814D4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7E2358 802814D8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7E235C 802814DC AFBF0018 */  sw        $ra, 0x18($sp)
/* 7E2360 802814E0 8C420144 */  lw        $v0, 0x144($v0)
/* 7E2364 802814E4 24A50008 */  addiu     $a1, $a1, 8
/* 7E2368 802814E8 8C440008 */  lw        $a0, 8($v0)
/* 7E236C 802814EC 8C430018 */  lw        $v1, 0x18($v0)
/* 7E2370 802814F0 2402000A */  addiu     $v0, $zero, 0xa
/* 7E2374 802814F4 AFA20010 */  sw        $v0, 0x10($sp)
/* 7E2378 802814F8 AFA00014 */  sw        $zero, 0x14($sp)
/* 7E237C 802814FC 00041040 */  sll       $v0, $a0, 1
/* 7E2380 80281500 00441021 */  addu      $v0, $v0, $a0
/* 7E2384 80281504 00021080 */  sll       $v0, $v0, 2
/* 7E2388 80281508 00621821 */  addu      $v1, $v1, $v0
/* 7E238C 8028150C 8C640008 */  lw        $a0, 8($v1)
/* 7E2390 80281510 0C04993B */  jal       draw_msg
/* 7E2394 80281514 240700FF */   addiu    $a3, $zero, 0xff
/* 7E2398 80281518 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7E239C 8028151C 03E00008 */  jr        $ra
/* 7E23A0 80281520 27BD0020 */   addiu    $sp, $sp, 0x20
