.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osViSetEvent
/* 421B0 80066DB0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 421B4 80066DB4 AFB00010 */  sw        $s0, 0x10($sp)
/* 421B8 80066DB8 00808021 */  addu      $s0, $a0, $zero
/* 421BC 80066DBC AFB10014 */  sw        $s1, 0x14($sp)
/* 421C0 80066DC0 00A08821 */  addu      $s1, $a1, $zero
/* 421C4 80066DC4 AFB20018 */  sw        $s2, 0x18($sp)
/* 421C8 80066DC8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 421CC 80066DCC 0C01ACD8 */  jal       osDisableInt
/* 421D0 80066DD0 00C09021 */   addu     $s2, $a2, $zero
/* 421D4 80066DD4 3C038009 */  lui       $v1, %hi(D_800959D4)
/* 421D8 80066DD8 8C6359D4 */  lw        $v1, %lo(D_800959D4)($v1)
/* 421DC 80066DDC 00402021 */  addu      $a0, $v0, $zero
/* 421E0 80066DE0 AC700010 */  sw        $s0, 0x10($v1)
/* 421E4 80066DE4 AC710014 */  sw        $s1, 0x14($v1)
/* 421E8 80066DE8 0C01ACF4 */  jal       osRestoreInt
/* 421EC 80066DEC A4720002 */   sh       $s2, 2($v1)
/* 421F0 80066DF0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 421F4 80066DF4 8FB20018 */  lw        $s2, 0x18($sp)
/* 421F8 80066DF8 8FB10014 */  lw        $s1, 0x14($sp)
/* 421FC 80066DFC 8FB00010 */  lw        $s0, 0x10($sp)
/* 42200 80066E00 03E00008 */  jr        $ra
/* 42204 80066E04 27BD0020 */   addiu    $sp, $sp, 0x20
/* 42208 80066E08 00000000 */  nop
/* 4220C 80066E0C 00000000 */  nop
