.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021849C_6DC23C
/* 6DC23C 8021849C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6DC240 802184A0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 6DC244 802184A4 AFB20018 */  sw        $s2, 0x18($sp)
/* 6DC248 802184A8 AFB10014 */  sw        $s1, 0x14($sp)
/* 6DC24C 802184AC AFB00010 */  sw        $s0, 0x10($sp)
/* 6DC250 802184B0 8C9000A8 */  lw        $s0, 0xa8($a0)
/* 6DC254 802184B4 0C04417A */  jal       get_entity_by_index
/* 6DC258 802184B8 0200202D */   daddu    $a0, $s0, $zero
/* 6DC25C 802184BC 0040882D */  daddu     $s1, $v0, $zero
/* 6DC260 802184C0 3C128016 */  lui       $s2, %hi(gCollisionStatus)
/* 6DC264 802184C4 2652A550 */  addiu     $s2, $s2, %lo(gCollisionStatus)
/* 6DC268 802184C8 36104000 */  ori       $s0, $s0, 0x4000
/* 6DC26C 802184CC 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* 6DC270 802184D0 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* 6DC274 802184D4 A2200007 */  sb        $zero, 7($s1)
/* 6DC278 802184D8 A6500014 */  sh        $s0, 0x14($s2)
/* 6DC27C 802184DC 8C820000 */  lw        $v0, ($a0)
/* 6DC280 802184E0 3C030100 */  lui       $v1, 0x100
/* 6DC284 802184E4 00431025 */  or        $v0, $v0, $v1
/* 6DC288 802184E8 AC820000 */  sw        $v0, ($a0)
/* 6DC28C 802184EC 24020040 */  addiu     $v0, $zero, 0x40
/* 6DC290 802184F0 A2220006 */  sb        $v0, 6($s1)
/* 6DC294 802184F4 24020012 */  addiu     $v0, $zero, 0x12
/* 6DC298 802184F8 A08200B4 */  sb        $v0, 0xb4($a0)
/* 6DC29C 802184FC 8E220038 */  lw        $v0, 0x38($s1)
/* 6DC2A0 80218500 8C420014 */  lw        $v0, 0x14($v0)
/* 6DC2A4 80218504 0040F809 */  jalr      $v0
/* 6DC2A8 80218508 0220202D */   daddu    $a0, $s1, $zero
/* 6DC2AC 8021850C 2403000A */  addiu     $v1, $zero, 0xa
/* 6DC2B0 80218510 A2230007 */  sb        $v1, 7($s1)
/* 6DC2B4 80218514 8E230000 */  lw        $v1, ($s1)
/* 6DC2B8 80218518 3C040001 */  lui       $a0, 1
/* 6DC2BC 8021851C 00641825 */  or        $v1, $v1, $a0
/* 6DC2C0 80218520 AE230000 */  sw        $v1, ($s1)
/* 6DC2C4 80218524 2403FFFF */  addiu     $v1, $zero, -1
/* 6DC2C8 80218528 A6430014 */  sh        $v1, 0x14($s2)
/* 6DC2CC 8021852C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6DC2D0 80218530 8FB20018 */  lw        $s2, 0x18($sp)
/* 6DC2D4 80218534 8FB10014 */  lw        $s1, 0x14($sp)
/* 6DC2D8 80218538 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DC2DC 8021853C 24020002 */  addiu     $v0, $zero, 2
/* 6DC2E0 80218540 03E00008 */  jr        $ra
/* 6DC2E4 80218544 27BD0020 */   addiu    $sp, $sp, 0x20
/* 6DC2E8 80218548 00000000 */  nop       
/* 6DC2EC 8021854C 00000000 */  nop       
