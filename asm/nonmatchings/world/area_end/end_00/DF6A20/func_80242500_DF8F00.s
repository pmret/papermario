.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242500_DF8F00
/* DF8F00 80242500 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DF8F04 80242504 AFB00010 */  sw        $s0, 0x10($sp)
/* DF8F08 80242508 3C108025 */  lui       $s0, %hi(D_8024E960)
/* DF8F0C 8024250C 2610E960 */  addiu     $s0, $s0, %lo(D_8024E960)
/* DF8F10 80242510 3C058024 */  lui       $a1, %hi(D_802421D8)
/* DF8F14 80242514 24A521D8 */  addiu     $a1, $a1, %lo(D_802421D8)
/* DF8F18 80242518 AFBF0014 */  sw        $ra, 0x14($sp)
/* DF8F1C 8024251C 3C018025 */  lui       $at, %hi(D_8024F7E4)
/* DF8F20 80242520 AC30F7E4 */  sw        $s0, %lo(D_8024F7E4)($at)
/* DF8F24 80242524 0C048C8F */  jal       bind_dynamic_entity_7
/* DF8F28 80242528 0000202D */   daddu    $a0, $zero, $zero
/* DF8F2C 8024252C 2404001F */  addiu     $a0, $zero, 0x1f
/* DF8F30 80242530 26030E0C */  addiu     $v1, $s0, 0xe0c
/* DF8F34 80242534 AE020000 */  sw        $v0, ($s0)
.L80242538:
/* DF8F38 80242538 A4600074 */  sh        $zero, 0x74($v1)
/* DF8F3C 8024253C 2484FFFF */  addiu     $a0, $a0, -1
/* DF8F40 80242540 0481FFFD */  bgez      $a0, .L80242538
/* DF8F44 80242544 2463FF8C */   addiu    $v1, $v1, -0x74
/* DF8F48 80242548 8FBF0014 */  lw        $ra, 0x14($sp)
/* DF8F4C 8024254C 8FB00010 */  lw        $s0, 0x10($sp)
/* DF8F50 80242550 03E00008 */  jr        $ra
/* DF8F54 80242554 27BD0018 */   addiu    $sp, $sp, 0x18
