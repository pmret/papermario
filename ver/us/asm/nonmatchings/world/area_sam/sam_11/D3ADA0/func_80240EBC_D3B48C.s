.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EBC_D3B48C
/* D3B48C 80240EBC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D3B490 80240EC0 AFB00010 */  sw        $s0, 0x10($sp)
/* D3B494 80240EC4 3C108011 */  lui       $s0, %hi(gPlayerData)
/* D3B498 80240EC8 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* D3B49C 80240ECC AFBF0018 */  sw        $ra, 0x18($sp)
/* D3B4A0 80240ED0 AFB10014 */  sw        $s1, 0x14($sp)
/* D3B4A4 80240ED4 960302C0 */  lhu       $v1, 0x2c0($s0)
/* D3B4A8 80240ED8 2C6203E7 */  sltiu     $v0, $v1, 0x3e7
/* D3B4AC 80240EDC 10400003 */  beqz      $v0, .L80240EEC
/* D3B4B0 80240EE0 0080882D */   daddu    $s1, $a0, $zero
/* D3B4B4 80240EE4 24620001 */  addiu     $v0, $v1, 1
/* D3B4B8 80240EE8 A60202C0 */  sh        $v0, 0x2c0($s0)
.L80240EEC:
/* D3B4BC 80240EEC 3C05F5DE */  lui       $a1, 0xf5de
/* D3B4C0 80240EF0 34A502E0 */  ori       $a1, $a1, 0x2e0
/* D3B4C4 80240EF4 0C0B1EAF */  jal       evt_get_variable
/* D3B4C8 80240EF8 0000202D */   daddu    $a0, $zero, $zero
/* D3B4CC 80240EFC 3C038024 */  lui       $v1, %hi(D_80244FDC_D3F5AC)
/* D3B4D0 80240F00 00621821 */  addu      $v1, $v1, $v0
/* D3B4D4 80240F04 90634FDC */  lbu       $v1, %lo(D_80244FDC_D3F5AC)($v1)
/* D3B4D8 80240F08 8E220084 */  lw        $v0, 0x84($s1)
/* D3B4DC 80240F0C 54430006 */  bnel      $v0, $v1, .L80240F28
/* D3B4E0 80240F10 AE200084 */   sw       $zero, 0x84($s1)
/* D3B4E4 80240F14 24020001 */  addiu     $v0, $zero, 1
/* D3B4E8 80240F18 AE220084 */  sw        $v0, 0x84($s1)
/* D3B4EC 80240F1C 960202C2 */  lhu       $v0, 0x2c2($s0)
/* D3B4F0 80240F20 24420001 */  addiu     $v0, $v0, 1
/* D3B4F4 80240F24 A60202C2 */  sh        $v0, 0x2c2($s0)
.L80240F28:
/* D3B4F8 80240F28 8FBF0018 */  lw        $ra, 0x18($sp)
/* D3B4FC 80240F2C 8FB10014 */  lw        $s1, 0x14($sp)
/* D3B500 80240F30 8FB00010 */  lw        $s0, 0x10($sp)
/* D3B504 80240F34 24020002 */  addiu     $v0, $zero, 2
/* D3B508 80240F38 03E00008 */  jr        $ra
/* D3B50C 80240F3C 27BD0020 */   addiu    $sp, $sp, 0x20
