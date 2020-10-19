.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024301C
/* A2D25C 8024301C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A2D260 80243020 AFB00018 */  sw        $s0, 0x18($sp)
/* A2D264 80243024 00A0802D */  daddu     $s0, $a1, $zero
/* A2D268 80243028 AFBF0020 */  sw        $ra, 0x20($sp)
/* A2D26C 8024302C AFB1001C */  sw        $s1, 0x1c($sp)
/* A2D270 80243030 F7B40028 */  sdc1      $f20, 0x28($sp)
/* A2D274 80243034 0C0B36B0 */  jal       resolve_npc
/* A2D278 80243038 24050009 */   addiu    $a1, $zero, 9
/* A2D27C 8024303C 12000007 */  beqz      $s0, .L8024305C
/* A2D280 80243040 0040882D */   daddu    $s1, $v0, $zero
/* A2D284 80243044 C6200038 */  lwc1      $f0, 0x38($s1)
/* A2D288 80243048 C6220040 */  lwc1      $f2, 0x40($s1)
/* A2D28C 8024304C 3C018025 */  lui       $at, 0x8025
/* A2D290 80243050 E420F2F4 */  swc1      $f0, -0xd0c($at)
/* A2D294 80243054 3C018025 */  lui       $at, 0x8025
/* A2D298 80243058 E422F2F8 */  swc1      $f2, -0xd08($at)
.L8024305C:
/* A2D29C 8024305C 24040003 */  addiu     $a0, $zero, 3
/* A2D2A0 80243060 3C108025 */  lui       $s0, 0x8025
/* A2D2A4 80243064 2610A9CC */  addiu     $s0, $s0, -0x5634
/* A2D2A8 80243068 C6000000 */  lwc1      $f0, ($s0)
/* A2D2AC 8024306C 46800020 */  cvt.s.w   $f0, $f0
/* A2D2B0 80243070 3C058025 */  lui       $a1, 0x8025
/* A2D2B4 80243074 8CA5F2F4 */  lw        $a1, -0xd0c($a1)
/* A2D2B8 80243078 3C06C2BE */  lui       $a2, 0xc2be
/* A2D2BC 8024307C 44070000 */  mfc1      $a3, $f0
/* A2D2C0 80243080 3C014220 */  lui       $at, 0x4220
/* A2D2C4 80243084 4481A000 */  mtc1      $at, $f20
/* A2D2C8 80243088 26220038 */  addiu     $v0, $s1, 0x38
/* A2D2CC 8024308C AFA20014 */  sw        $v0, 0x14($sp)
/* A2D2D0 80243090 0C090439 */  jal       func_802410E4
/* A2D2D4 80243094 E7B40010 */   swc1     $f20, 0x10($sp)
/* A2D2D8 80243098 C6000000 */  lwc1      $f0, ($s0)
/* A2D2DC 8024309C 46800020 */  cvt.s.w   $f0, $f0
/* A2D2E0 802430A0 24040003 */  addiu     $a0, $zero, 3
/* A2D2E4 802430A4 3C058025 */  lui       $a1, 0x8025
/* A2D2E8 802430A8 8CA5F2F8 */  lw        $a1, -0xd08($a1)
/* A2D2EC 802430AC 3C0641A0 */  lui       $a2, 0x41a0
/* A2D2F0 802430B0 44070000 */  mfc1      $a3, $f0
/* A2D2F4 802430B4 26220040 */  addiu     $v0, $s1, 0x40
/* A2D2F8 802430B8 E7B40010 */  swc1      $f20, 0x10($sp)
/* A2D2FC 802430BC 0C090439 */  jal       func_802410E4
/* A2D300 802430C0 AFA20014 */   sw       $v0, 0x14($sp)
/* A2D304 802430C4 8E030000 */  lw        $v1, ($s0)
/* A2D308 802430C8 C6200038 */  lwc1      $f0, 0x38($s1)
/* A2D30C 802430CC C6220040 */  lwc1      $f2, 0x40($s1)
/* A2D310 802430D0 24630001 */  addiu     $v1, $v1, 1
/* A2D314 802430D4 28620029 */  slti      $v0, $v1, 0x29
/* A2D318 802430D8 E620006C */  swc1      $f0, 0x6c($s1)
/* A2D31C 802430DC E6220074 */  swc1      $f2, 0x74($s1)
/* A2D320 802430E0 AE030000 */  sw        $v1, ($s0)
/* A2D324 802430E4 8FBF0020 */  lw        $ra, 0x20($sp)
/* A2D328 802430E8 8FB1001C */  lw        $s1, 0x1c($sp)
/* A2D32C 802430EC 8FB00018 */  lw        $s0, 0x18($sp)
/* A2D330 802430F0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* A2D334 802430F4 38420001 */  xori      $v0, $v0, 1
/* A2D338 802430F8 03E00008 */  jr        $ra
/* A2D33C 802430FC 27BD0030 */   addiu    $sp, $sp, 0x30
