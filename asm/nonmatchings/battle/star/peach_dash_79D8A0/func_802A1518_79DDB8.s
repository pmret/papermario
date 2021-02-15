.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1518_79DDB8
/* 79DDB8 802A1518 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 79DDBC 802A151C 24040030 */  addiu     $a0, $zero, 0x30
/* 79DDC0 802A1520 AFB00010 */  sw        $s0, 0x10($sp)
/* 79DDC4 802A1524 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 79DDC8 802A1528 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 79DDCC 802A152C AFB10014 */  sw        $s1, 0x14($sp)
/* 79DDD0 802A1530 AFBF0018 */  sw        $ra, 0x18($sp)
/* 79DDD4 802A1534 0C03A752 */  jal       is_ability_active
/* 79DDD8 802A1538 0200882D */   daddu    $s1, $s0, $zero
/* 79DDDC 802A153C 10400004 */  beqz      $v0, .L802A1550
/* 79DDE0 802A1540 00000000 */   nop
/* 79DDE4 802A1544 96020290 */  lhu       $v0, 0x290($s0)
/* 79DDE8 802A1548 24420080 */  addiu     $v0, $v0, 0x80
/* 79DDEC 802A154C A6020290 */  sh        $v0, 0x290($s0)
.L802A1550:
/* 79DDF0 802A1550 0C03A752 */  jal       is_ability_active
/* 79DDF4 802A1554 24040031 */   addiu    $a0, $zero, 0x31
/* 79DDF8 802A1558 10400004 */  beqz      $v0, .L802A156C
/* 79DDFC 802A155C 00000000 */   nop
/* 79DE00 802A1560 96020290 */  lhu       $v0, 0x290($s0)
/* 79DE04 802A1564 24420100 */  addiu     $v0, $v0, 0x100
/* 79DE08 802A1568 A6020290 */  sh        $v0, 0x290($s0)
.L802A156C:
/* 79DE0C 802A156C 96220290 */  lhu       $v0, 0x290($s1)
/* 79DE10 802A1570 8223028E */  lb        $v1, 0x28e($s1)
/* 79DE14 802A1574 24420080 */  addiu     $v0, $v0, 0x80
/* 79DE18 802A1578 A6220290 */  sh        $v0, 0x290($s1)
/* 79DE1C 802A157C 00021400 */  sll       $v0, $v0, 0x10
/* 79DE20 802A1580 00021403 */  sra       $v0, $v0, 0x10
/* 79DE24 802A1584 00031A00 */  sll       $v1, $v1, 8
/* 79DE28 802A1588 0043102A */  slt       $v0, $v0, $v1
/* 79DE2C 802A158C 50400001 */  beql      $v0, $zero, .L802A1594
/* 79DE30 802A1590 A6230290 */   sh       $v1, 0x290($s1)
.L802A1594:
/* 79DE34 802A1594 8FBF0018 */  lw        $ra, 0x18($sp)
/* 79DE38 802A1598 8FB10014 */  lw        $s1, 0x14($sp)
/* 79DE3C 802A159C 8FB00010 */  lw        $s0, 0x10($sp)
/* 79DE40 802A15A0 24020002 */  addiu     $v0, $zero, 2
/* 79DE44 802A15A4 03E00008 */  jr        $ra
/* 79DE48 802A15A8 27BD0020 */   addiu    $sp, $sp, 0x20
/* 79DE4C 802A15AC 00000000 */  nop
