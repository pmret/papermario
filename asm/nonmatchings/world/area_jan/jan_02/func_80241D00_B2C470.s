.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D00_B2E170
/* B2E170 80241D00 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B2E174 80241D04 AFB00010 */  sw        $s0, 0x10($sp)
/* B2E178 80241D08 3C108011 */  lui       $s0, %hi(gPlayerData)
/* B2E17C 80241D0C 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* B2E180 80241D10 AFBF0018 */  sw        $ra, 0x18($sp)
/* B2E184 80241D14 AFB10014 */  sw        $s1, 0x14($sp)
/* B2E188 80241D18 960302C0 */  lhu       $v1, 0x2c0($s0)
/* B2E18C 80241D1C 2C6203E7 */  sltiu     $v0, $v1, 0x3e7
/* B2E190 80241D20 10400003 */  beqz      $v0, .L80241D30
/* B2E194 80241D24 0080882D */   daddu    $s1, $a0, $zero
/* B2E198 80241D28 24620001 */  addiu     $v0, $v1, 1
/* B2E19C 80241D2C A60202C0 */  sh        $v0, 0x2c0($s0)
.L80241D30:
/* B2E1A0 80241D30 3C05F5DE */  lui       $a1, 0xf5de
/* B2E1A4 80241D34 34A502E0 */  ori       $a1, $a1, 0x2e0
/* B2E1A8 80241D38 0C0B1EAF */  jal       get_variable
/* B2E1AC 80241D3C 0000202D */   daddu    $a0, $zero, $zero
/* B2E1B0 80241D40 3C038024 */  lui       $v1, 0x8024
/* B2E1B4 80241D44 00621821 */  addu      $v1, $v1, $v0
/* B2E1B8 80241D48 90633248 */  lbu       $v1, 0x3248($v1)
/* B2E1BC 80241D4C 8E220084 */  lw        $v0, 0x84($s1)
/* B2E1C0 80241D50 54430006 */  bnel      $v0, $v1, .L80241D6C
/* B2E1C4 80241D54 AE200084 */   sw       $zero, 0x84($s1)
/* B2E1C8 80241D58 24020001 */  addiu     $v0, $zero, 1
/* B2E1CC 80241D5C AE220084 */  sw        $v0, 0x84($s1)
/* B2E1D0 80241D60 960202C2 */  lhu       $v0, 0x2c2($s0)
/* B2E1D4 80241D64 24420001 */  addiu     $v0, $v0, 1
/* B2E1D8 80241D68 A60202C2 */  sh        $v0, 0x2c2($s0)
.L80241D6C:
/* B2E1DC 80241D6C 8FBF0018 */  lw        $ra, 0x18($sp)
/* B2E1E0 80241D70 8FB10014 */  lw        $s1, 0x14($sp)
/* B2E1E4 80241D74 8FB00010 */  lw        $s0, 0x10($sp)
/* B2E1E8 80241D78 24020002 */  addiu     $v0, $zero, 2
/* B2E1EC 80241D7C 03E00008 */  jr        $ra
/* B2E1F0 80241D80 27BD0020 */   addiu    $sp, $sp, 0x20
