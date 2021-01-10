.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6000_E27510
/* E27510 802B6000 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* E27514 802B6004 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* E27518 802B6008 8C6200D0 */  lw        $v0, 0xd0($v1)
/* E2751C 802B600C C4400010 */  lwc1      $f0, 0x10($v0)
/* E27520 802B6010 E4600070 */  swc1      $f0, 0x70($v1)
/* E27524 802B6014 C4400014 */  lwc1      $f0, 0x14($v0)
/* E27528 802B6018 E4600074 */  swc1      $f0, 0x74($v1)
/* E2752C 802B601C C4400018 */  lwc1      $f0, 0x18($v0)
/* E27530 802B6020 E4600078 */  swc1      $f0, 0x78($v1)
/* E27534 802B6024 C440001C */  lwc1      $f0, 0x1c($v0)
/* E27538 802B6028 E460007C */  swc1      $f0, 0x7c($v1)
/* E2753C 802B602C C4400000 */  lwc1      $f0, ($v0)
/* E27540 802B6030 E46000A0 */  swc1      $f0, 0xa0($v1)
/* E27544 802B6034 C4400004 */  lwc1      $f0, 4($v0)
/* E27548 802B6038 C4420008 */  lwc1      $f2, 8($v0)
/* E2754C 802B603C C444000C */  lwc1      $f4, 0xc($v0)
/* E27550 802B6040 3C01802B */  lui       $at, %hi(D_802B6784)
/* E27554 802B6044 E4206784 */  swc1      $f0, %lo(D_802B6784)($at)
/* E27558 802B6048 3C01802B */  lui       $at, %hi(D_802B678C)
/* E2755C 802B604C E422678C */  swc1      $f2, %lo(D_802B678C)($at)
/* E27560 802B6050 3C01802B */  lui       $at, %hi(D_802B6788)
/* E27564 802B6054 E4246788 */  swc1      $f4, %lo(D_802B6788)($at)
/* E27568 802B6058 03E00008 */  jr        $ra
/* E2756C 802B605C 00000000 */   nop      
