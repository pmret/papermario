.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B63D4_E28E04
/* E28E04 802B63D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E28E08 802B63D8 AFB00010 */  sw        $s0, 0x10($sp)
/* E28E0C 802B63DC 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E28E10 802B63E0 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E28E14 802B63E4 AFBF0018 */  sw        $ra, 0x18($sp)
/* E28E18 802B63E8 AFB10014 */  sw        $s1, 0x14($sp)
/* E28E1C 802B63EC 8E030000 */  lw        $v1, ($s0)
/* E28E20 802B63F0 0461000F */  bgez      $v1, .L802B6430
/* E28E24 802B63F4 0200882D */   daddu    $s1, $s0, $zero
/* E28E28 802B63F8 3C027FFF */  lui       $v0, 0x7fff
/* E28E2C 802B63FC 3442FFF1 */  ori       $v0, $v0, 0xfff1
/* E28E30 802B6400 3C040001 */  lui       $a0, 1
/* E28E34 802B6404 34840017 */  ori       $a0, $a0, 0x17
/* E28E38 802B6408 00621024 */  and       $v0, $v1, $v0
/* E28E3C 802B640C AE020000 */  sw        $v0, ($s0)
/* E28E40 802B6410 A20000B6 */  sb        $zero, 0xb6($s0)
/* E28E44 802B6414 A60000C0 */  sh        $zero, 0xc0($s0)
/* E28E48 802B6418 A60000C2 */  sh        $zero, 0xc2($s0)
/* E28E4C 802B641C AE000054 */  sw        $zero, 0x54($s0)
/* E28E50 802B6420 0C037FDE */  jal       func_800DFF78
/* E28E54 802B6424 AE00008C */   sw       $zero, 0x8c($s0)
/* E28E58 802B6428 2402001E */  addiu     $v0, $zero, 0x1e
/* E28E5C 802B642C A6020008 */  sh        $v0, 8($s0)
.L802B6430:
/* E28E60 802B6430 86220008 */  lh        $v0, 8($s1)
/* E28E64 802B6434 96230008 */  lhu       $v1, 8($s1)
/* E28E68 802B6438 10400003 */  beqz      $v0, .L802B6448
/* E28E6C 802B643C 2462FFFF */   addiu    $v0, $v1, -1
/* E28E70 802B6440 080AD919 */  j         .L802B6464
/* E28E74 802B6444 A6220008 */   sh       $v0, 8($s1)
.L802B6448:
/* E28E78 802B6448 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* E28E7C 802B644C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* E28E80 802B6450 80420070 */  lb        $v0, 0x70($v0)
/* E28E84 802B6454 14400003 */  bnez      $v0, .L802B6464
/* E28E88 802B6458 00000000 */   nop
/* E28E8C 802B645C 0C039769 */  jal       set_action_state
/* E28E90 802B6460 0000202D */   daddu    $a0, $zero, $zero
.L802B6464:
/* E28E94 802B6464 8FBF0018 */  lw        $ra, 0x18($sp)
/* E28E98 802B6468 8FB10014 */  lw        $s1, 0x14($sp)
/* E28E9C 802B646C 8FB00010 */  lw        $s0, 0x10($sp)
/* E28EA0 802B6470 03E00008 */  jr        $ra
/* E28EA4 802B6474 27BD0020 */   addiu    $sp, $sp, 0x20
