.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80063868
/* 3EC68 80063868 27BDFF88 */  addiu     $sp, $sp, -0x78
/* 3EC6C 8006386C C7A00088 */  lwc1      $f0, 0x88($sp)
/* 3EC70 80063870 C7A2008C */  lwc1      $f2, 0x8c($sp)
/* 3EC74 80063874 C7A40090 */  lwc1      $f4, 0x90($sp)
/* 3EC78 80063878 C7A60094 */  lwc1      $f6, 0x94($sp)
/* 3EC7C 8006387C C7A80098 */  lwc1      $f8, 0x98($sp)
/* 3EC80 80063880 C7AA009C */  lwc1      $f10, 0x9c($sp)
/* 3EC84 80063884 C7AC00A0 */  lwc1      $f12, 0xa0($sp)
/* 3EC88 80063888 AFB00070 */  sw        $s0, 0x70($sp)
/* 3EC8C 8006388C 00808021 */  addu      $s0, $a0, $zero
/* 3EC90 80063890 27A40030 */  addiu     $a0, $sp, 0x30
/* 3EC94 80063894 AFBF0074 */  sw        $ra, 0x74($sp)
/* 3EC98 80063898 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3EC9C 8006389C E7A20014 */  swc1      $f2, 0x14($sp)
/* 3ECA0 800638A0 E7A40018 */  swc1      $f4, 0x18($sp)
/* 3ECA4 800638A4 E7A6001C */  swc1      $f6, 0x1c($sp)
/* 3ECA8 800638A8 E7A80020 */  swc1      $f8, 0x20($sp)
/* 3ECAC 800638AC E7AA0024 */  swc1      $f10, 0x24($sp)
/* 3ECB0 800638B0 0C018CBC */  jal       func_800632F0
/* 3ECB4 800638B4 E7AC0028 */   swc1     $f12, 0x28($sp)
/* 3ECB8 800638B8 27A40030 */  addiu     $a0, $sp, 0x30
/* 3ECBC 800638BC 0C019D38 */  jal       func_800674E0
/* 3ECC0 800638C0 02002821 */   addu     $a1, $s0, $zero
/* 3ECC4 800638C4 8FBF0074 */  lw        $ra, 0x74($sp)
/* 3ECC8 800638C8 8FB00070 */  lw        $s0, 0x70($sp)
/* 3ECCC 800638CC 03E00008 */  jr        $ra
/* 3ECD0 800638D0 27BD0078 */   addiu    $sp, $sp, 0x78
/* 3ECD4 800638D4 00000000 */  nop
/* 3ECD8 800638D8 00000000 */  nop
/* 3ECDC 800638DC 00000000 */  nop
