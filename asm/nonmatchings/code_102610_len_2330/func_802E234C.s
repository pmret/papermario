.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802E234C
/* 103BCC 802E234C 3C058011 */  lui   $a1, 0x8011
/* 103BD0 802E2350 24A5EFC8 */  addiu $a1, $a1, -0x1038
/* 103BD4 802E2354 3C060100 */  lui   $a2, 0x100
/* 103BD8 802E2358 8C830040 */  lw    $v1, 0x40($a0)
/* 103BDC 802E235C 8CA20004 */  lw    $v0, 4($a1)
/* 103BE0 802E2360 3C013F80 */  lui   $at, 0x3f80
/* 103BE4 802E2364 44810000 */  mtc1  $at, $f0
/* 103BE8 802E2368 00461025 */  or    $v0, $v0, $a2
/* 103BEC 802E236C ACA20004 */  sw    $v0, 4($a1)
/* 103BF0 802E2370 E4600014 */  swc1  $f0, 0x14($v1)
/* 103BF4 802E2374 E4600018 */  swc1  $f0, 0x18($v1)
/* 103BF8 802E2378 03E00008 */  jr    $ra
/* 103BFC 802E237C E460001C */   swc1  $f0, 0x1c($v1)

/* 103C00 802E2380 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 103C04 802E2384 AFB00010 */  sw    $s0, 0x10($sp)
/* 103C08 802E2388 0080802D */  daddu $s0, $a0, $zero
/* 103C0C 802E238C AFBF0018 */  sw    $ra, 0x18($sp)
/* 103C10 802E2390 AFB10014 */  sw    $s1, 0x14($sp)
/* 103C14 802E2394 0C0B88D3 */  jal   func_802E234C
/* 103C18 802E2398 8E110040 */   lw    $s1, 0x40($s0)
/* 103C1C 802E239C 3C038016 */  lui   $v1, 0x8016
/* 103C20 802E23A0 8C63C7D0 */  lw    $v1, -0x3830($v1)
/* 103C24 802E23A4 24020002 */  addiu $v0, $zero, 2
/* 103C28 802E23A8 14620005 */  bne   $v1, $v0, .L802E23C0
/* 103C2C 802E23AC 24020001 */   addiu $v0, $zero, 1
/* 103C30 802E23B0 3C01802F */  lui   $at, 0x802f
/* 103C34 802E23B4 AC30B3A0 */  sw    $s0, -0x4c60($at)
/* 103C38 802E23B8 080B88FD */  j     .L802E23F4
/* 103C3C 802E23BC 00000000 */   nop   

.L802E23C0:
/* 103C40 802E23C0 1462000A */  bne   $v1, $v0, .L802E23EC
/* 103C44 802E23C4 00000000 */   nop   
/* 103C48 802E23C8 3C02802F */  lui   $v0, 0x802f
/* 103C4C 802E23CC 8C42B3A0 */  lw    $v0, -0x4c60($v0)
/* 103C50 802E23D0 10400008 */  beqz  $v0, .L802E23F4
/* 103C54 802E23D4 00000000 */   nop   
/* 103C58 802E23D8 AE220028 */  sw    $v0, 0x28($s1)
/* 103C5C 802E23DC 8E020000 */  lw    $v0, ($s0)
/* 103C60 802E23E0 34420001 */  ori   $v0, $v0, 1
/* 103C64 802E23E4 080B88FD */  j     .L802E23F4
/* 103C68 802E23E8 AE020000 */   sw    $v0, ($s0)

.L802E23EC:
/* 103C6C 802E23EC 3C01802F */  lui   $at, 0x802f
/* 103C70 802E23F0 AC20B3A0 */  sw    $zero, -0x4c60($at)
.L802E23F4:
/* 103C74 802E23F4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 103C78 802E23F8 8FB10014 */  lw    $s1, 0x14($sp)
/* 103C7C 802E23FC 8FB00010 */  lw    $s0, 0x10($sp)
/* 103C80 802E2400 03E00008 */  jr    $ra
/* 103C84 802E2404 27BD0020 */   addiu $sp, $sp, 0x20

/* 103C88 802E2408 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 103C8C 802E240C AFB00010 */  sw    $s0, 0x10($sp)
/* 103C90 802E2410 AFBF0014 */  sw    $ra, 0x14($sp)
/* 103C94 802E2414 0C0B88D3 */  jal   func_802E234C
/* 103C98 802E2418 0080802D */   daddu $s0, $a0, $zero
/* 103C9C 802E241C 3C014040 */  lui   $at, 0x4040
/* 103CA0 802E2420 44810000 */  mtc1  $at, $f0
/* 103CA4 802E2424 8E020040 */  lw    $v0, 0x40($s0)
/* 103CA8 802E2428 E6000054 */  swc1  $f0, 0x54($s0)
/* 103CAC 802E242C E6000058 */  swc1  $f0, 0x58($s0)
/* 103CB0 802E2430 E600005C */  swc1  $f0, 0x5c($s0)
/* 103CB4 802E2434 E4400014 */  swc1  $f0, 0x14($v0)
/* 103CB8 802E2438 E4400018 */  swc1  $f0, 0x18($v0)
/* 103CBC 802E243C E440001C */  swc1  $f0, 0x1c($v0)
/* 103CC0 802E2440 8FBF0014 */  lw    $ra, 0x14($sp)
/* 103CC4 802E2444 8FB00010 */  lw    $s0, 0x10($sp)
/* 103CC8 802E2448 03E00008 */  jr    $ra
/* 103CCC 802E244C 27BD0018 */   addiu $sp, $sp, 0x18

/* 103CD0 802E2450 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 103CD4 802E2454 AFBF0010 */  sw    $ra, 0x10($sp)
/* 103CD8 802E2458 0C0B8D94 */  jal   func_802E3650
/* 103CDC 802E245C 00000000 */   nop   
/* 103CE0 802E2460 8FBF0010 */  lw    $ra, 0x10($sp)
/* 103CE4 802E2464 03E00008 */  jr    $ra
/* 103CE8 802E2468 27BD0018 */   addiu $sp, $sp, 0x18

