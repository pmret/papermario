.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80061DA0
/* 3D1A0 80061DA0 27BDFFF0 */  addiu     $sp, $sp, -0x10
/* 3D1A4 80061DA4 00802821 */  addu      $a1, $a0, $zero
/* 3D1A8 80061DA8 2406000E */  addiu     $a2, $zero, 0xe
/* 3D1AC 80061DAC 3C02800B */  lui       $v0, %hi(D_800B0EE8)
/* 3D1B0 80061DB0 24420EE8 */  addiu     $v0, $v0, %lo(D_800B0EE8)
.L80061DB4:
/* 3D1B4 80061DB4 AC400000 */  sw        $zero, ($v0)
/* 3D1B8 80061DB8 24C6FFFF */  addiu     $a2, $a2, -1
/* 3D1BC 80061DBC 04C1FFFD */  bgez      $a2, .L80061DB4
/* 3D1C0 80061DC0 2442FFFC */   addiu    $v0, $v0, -4
/* 3D1C4 80061DC4 3C03800B */  lui       $v1, %hi(D_800B0EEC)
/* 3D1C8 80061DC8 24630EEC */  addiu     $v1, $v1, %lo(D_800B0EEC)
/* 3D1CC 80061DCC 2467FFC4 */  addiu     $a3, $v1, -0x3c
/* 3D1D0 80061DD0 3C04800A */  lui       $a0, %hi(D_8009A5E6)
/* 3D1D4 80061DD4 9084A5E6 */  lbu       $a0, %lo(D_8009A5E6)($a0)
/* 3D1D8 80061DD8 00003021 */  addu      $a2, $zero, $zero
/* 3D1DC 80061DDC 24020001 */  addiu     $v0, $zero, 1
/* 3D1E0 80061DE0 AC620000 */  sw        $v0, ($v1)
/* 3D1E4 80061DE4 240300FF */  addiu     $v1, $zero, 0xff
/* 3D1E8 80061DE8 24020001 */  addiu     $v0, $zero, 1
/* 3D1EC 80061DEC A3A20001 */  sb        $v0, 1($sp)
/* 3D1F0 80061DF0 24020003 */  addiu     $v0, $zero, 3
/* 3D1F4 80061DF4 A3A30000 */  sb        $v1, ($sp)
/* 3D1F8 80061DF8 A3A20002 */  sb        $v0, 2($sp)
/* 3D1FC 80061DFC A3A50003 */  sb        $a1, 3($sp)
/* 3D200 80061E00 A3A30004 */  sb        $v1, 4($sp)
/* 3D204 80061E04 A3A30005 */  sb        $v1, 5($sp)
/* 3D208 80061E08 A3A30006 */  sb        $v1, 6($sp)
/* 3D20C 80061E0C 1880000F */  blez      $a0, .L80061E4C
/* 3D210 80061E10 A3A30007 */   sb       $v1, 7($sp)
.L80061E14:
/* 3D214 80061E14 8BA20000 */  lwl       $v0, ($sp)
/* 3D218 80061E18 9BA20003 */  lwr       $v0, 3($sp)
/* 3D21C 80061E1C 8BA30004 */  lwl       $v1, 4($sp)
/* 3D220 80061E20 9BA30007 */  lwr       $v1, 7($sp)
/* 3D224 80061E24 A8E20000 */  swl       $v0, ($a3)
/* 3D228 80061E28 B8E20003 */  swr       $v0, 3($a3)
/* 3D22C 80061E2C A8E30004 */  swl       $v1, 4($a3)
/* 3D230 80061E30 B8E30007 */  swr       $v1, 7($a3)
/* 3D234 80061E34 3C02800A */  lui       $v0, %hi(D_8009A5E6)
/* 3D238 80061E38 9042A5E6 */  lbu       $v0, %lo(D_8009A5E6)($v0)
/* 3D23C 80061E3C 24C60001 */  addiu     $a2, $a2, 1
/* 3D240 80061E40 00C2102A */  slt       $v0, $a2, $v0
/* 3D244 80061E44 1440FFF3 */  bnez      $v0, .L80061E14
/* 3D248 80061E48 24E70008 */   addiu    $a3, $a3, 8
.L80061E4C:
/* 3D24C 80061E4C 240200FE */  addiu     $v0, $zero, 0xfe
/* 3D250 80061E50 A0E20000 */  sb        $v0, ($a3)
/* 3D254 80061E54 03E00008 */  jr        $ra
/* 3D258 80061E58 27BD0010 */   addiu    $sp, $sp, 0x10
/* 3D25C 80061E5C 00000000 */  nop
