.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel init_hud_element_list
/* D7A00 80141300 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* D7A04 80141304 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* D7A08 80141308 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D7A0C 8014130C AFBF0014 */  sw        $ra, 0x14($sp)
/* D7A10 80141310 AFB00010 */  sw        $s0, 0x10($sp)
/* D7A14 80141314 80420070 */  lb        $v0, 0x70($v0)
/* D7A18 80141318 1440001B */  bnez      $v0, .L80141388
/* D7A1C 8014131C 00000000 */   nop
/* D7A20 80141320 3C108016 */  lui       $s0, %hi(D_80158570)
/* D7A24 80141324 26108570 */  addiu     $s0, $s0, %lo(D_80158570)
/* D7A28 80141328 8E040000 */  lw        $a0, ($s0)
/* D7A2C 8014132C 10800004 */  beqz      $a0, .L80141340
/* D7A30 80141330 00000000 */   nop
/* D7A34 80141334 0C00AB1E */  jal       general_heap_free
/* D7A38 80141338 00000000 */   nop
/* D7A3C 8014133C AE000000 */  sw        $zero, ($s0)
.L80141340:
/* D7A40 80141340 3C038015 */  lui       $v1, %hi(D_80157964)
/* D7A44 80141344 8C637964 */  lw        $v1, %lo(D_80157964)($v1)
/* D7A48 80141348 3C028015 */  lui       $v0, %hi(D_80156F60)
/* D7A4C 8014134C 24426F60 */  addiu     $v0, $v0, %lo(D_80156F60)
/* D7A50 80141350 3C018015 */  lui       $at, %hi(gHudElementList)
/* D7A54 80141354 AC227960 */  sw        $v0, %lo(gHudElementList)($at)
/* D7A58 80141358 3C028015 */  lui       $v0, %hi(D_80157968)
/* D7A5C 8014135C 24427968 */  addiu     $v0, $v0, %lo(D_80157968)
/* D7A60 80141360 3C018015 */  lui       $at, %hi(D_8015133C)
/* D7A64 80141364 AC22133C */  sw        $v0, %lo(D_8015133C)($at)
/* D7A68 80141368 3C028015 */  lui       $v0, %hi(D_80157970)
/* D7A6C 8014136C 24427970 */  addiu     $v0, $v0, %lo(D_80157970)
/* D7A70 80141370 3C018015 */  lui       $at, %hi(D_801512C8)
/* D7A74 80141374 AC2212C8 */  sw        $v0, %lo(D_801512C8)($at)
/* D7A78 80141378 3C028015 */  lui       $v0, %hi(D_80157F70)
/* D7A7C 8014137C 24427F70 */  addiu     $v0, $v0, %lo(D_80157F70)
/* D7A80 80141380 080504F2 */  j         .L801413C8
/* D7A84 80141384 00000000 */   nop
.L80141388:
/* D7A88 80141388 3C038016 */  lui       $v1, %hi(D_80158570)
/* D7A8C 8014138C 8C638570 */  lw        $v1, %lo(D_80158570)($v1)
/* D7A90 80141390 3C028015 */  lui       $v0, %hi(D_80157460)
/* D7A94 80141394 24427460 */  addiu     $v0, $v0, %lo(D_80157460)
/* D7A98 80141398 3C018015 */  lui       $at, %hi(gHudElementList)
/* D7A9C 8014139C AC227960 */  sw        $v0, %lo(gHudElementList)($at)
/* D7AA0 801413A0 3C028016 */  lui       $v0, %hi(D_80158574)
/* D7AA4 801413A4 24428574 */  addiu     $v0, $v0, %lo(D_80158574)
/* D7AA8 801413A8 3C018015 */  lui       $at, %hi(D_8015133C)
/* D7AAC 801413AC AC22133C */  sw        $v0, %lo(D_8015133C)($at)
/* D7AB0 801413B0 3C028016 */  lui       $v0, %hi(D_80158580)
/* D7AB4 801413B4 24428580 */  addiu     $v0, $v0, %lo(D_80158580)
/* D7AB8 801413B8 3C018015 */  lui       $at, %hi(D_801512C8)
/* D7ABC 801413BC AC2212C8 */  sw        $v0, %lo(D_801512C8)($at)
/* D7AC0 801413C0 3C028016 */  lui       $v0, %hi(D_80158B80)
/* D7AC4 801413C4 24428B80 */  addiu     $v0, $v0, %lo(D_80158B80)
.L801413C8:
/* D7AC8 801413C8 3C018015 */  lui       $at, %hi(D_801512D0)
/* D7ACC 801413CC AC2212D0 */  sw        $v0, %lo(D_801512D0)($at)
/* D7AD0 801413D0 3C018015 */  lui       $at, %hi(D_80151314)
/* D7AD4 801413D4 AC231314 */  sw        $v1, %lo(D_80151314)($at)
/* D7AD8 801413D8 8FBF0014 */  lw        $ra, 0x14($sp)
/* D7ADC 801413DC 8FB00010 */  lw        $s0, 0x10($sp)
/* D7AE0 801413E0 3C018015 */  lui       $at, %hi(D_801512B4)
/* D7AE4 801413E4 AC2012B4 */  sw        $zero, %lo(D_801512B4)($at)
/* D7AE8 801413E8 3C018016 */  lui       $at, %hi(D_80159180)
/* D7AEC 801413EC AC209180 */  sw        $zero, %lo(D_80159180)($at)
/* D7AF0 801413F0 03E00008 */  jr        $ra
/* D7AF4 801413F4 27BD0018 */   addiu    $sp, $sp, 0x18
