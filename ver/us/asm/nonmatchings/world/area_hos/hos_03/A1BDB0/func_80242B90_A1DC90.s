.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242B90_A1DC90
/* A1DC90 80242B90 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A1DC94 80242B94 AFB00010 */  sw        $s0, 0x10($sp)
/* A1DC98 80242B98 3C108011 */  lui       $s0, %hi(gPlayerData)
/* A1DC9C 80242B9C 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* A1DCA0 80242BA0 AFBF0018 */  sw        $ra, 0x18($sp)
/* A1DCA4 80242BA4 AFB10014 */  sw        $s1, 0x14($sp)
/* A1DCA8 80242BA8 960302C0 */  lhu       $v1, 0x2c0($s0)
/* A1DCAC 80242BAC 2C6203E7 */  sltiu     $v0, $v1, 0x3e7
/* A1DCB0 80242BB0 10400003 */  beqz      $v0, .L80242BC0
/* A1DCB4 80242BB4 0080882D */   daddu    $s1, $a0, $zero
/* A1DCB8 80242BB8 24620001 */  addiu     $v0, $v1, 1
/* A1DCBC 80242BBC A60202C0 */  sh        $v0, 0x2c0($s0)
.L80242BC0:
/* A1DCC0 80242BC0 3C05F5DE */  lui       $a1, 0xf5de
/* A1DCC4 80242BC4 34A502E0 */  ori       $a1, $a1, 0x2e0
/* A1DCC8 80242BC8 0C0B1EAF */  jal       evt_get_variable
/* A1DCCC 80242BCC 0000202D */   daddu    $a0, $zero, $zero
/* A1DCD0 80242BD0 3C038025 */  lui       $v1, %hi(D_80248080_A23180)
/* A1DCD4 80242BD4 00621821 */  addu      $v1, $v1, $v0
/* A1DCD8 80242BD8 90638080 */  lbu       $v1, %lo(D_80248080_A23180)($v1)
/* A1DCDC 80242BDC 8E220084 */  lw        $v0, 0x84($s1)
/* A1DCE0 80242BE0 54430006 */  bnel      $v0, $v1, .L80242BFC
/* A1DCE4 80242BE4 AE200084 */   sw       $zero, 0x84($s1)
/* A1DCE8 80242BE8 24020001 */  addiu     $v0, $zero, 1
/* A1DCEC 80242BEC AE220084 */  sw        $v0, 0x84($s1)
/* A1DCF0 80242BF0 960202C2 */  lhu       $v0, 0x2c2($s0)
/* A1DCF4 80242BF4 24420001 */  addiu     $v0, $v0, 1
/* A1DCF8 80242BF8 A60202C2 */  sh        $v0, 0x2c2($s0)
.L80242BFC:
/* A1DCFC 80242BFC 8FBF0018 */  lw        $ra, 0x18($sp)
/* A1DD00 80242C00 8FB10014 */  lw        $s1, 0x14($sp)
/* A1DD04 80242C04 8FB00010 */  lw        $s0, 0x10($sp)
/* A1DD08 80242C08 24020002 */  addiu     $v0, $zero, 2
/* A1DD0C 80242C0C 03E00008 */  jr        $ra
/* A1DD10 80242C10 27BD0020 */   addiu    $sp, $sp, 0x20
