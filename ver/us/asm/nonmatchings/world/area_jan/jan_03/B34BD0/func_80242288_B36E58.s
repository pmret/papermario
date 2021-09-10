.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242288_B36E58
/* B36E58 80242288 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B36E5C 8024228C AFB00010 */  sw        $s0, 0x10($sp)
/* B36E60 80242290 3C108011 */  lui       $s0, %hi(gPlayerData)
/* B36E64 80242294 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* B36E68 80242298 AFBF0018 */  sw        $ra, 0x18($sp)
/* B36E6C 8024229C AFB10014 */  sw        $s1, 0x14($sp)
/* B36E70 802422A0 960302C0 */  lhu       $v1, 0x2c0($s0)
/* B36E74 802422A4 2C6203E7 */  sltiu     $v0, $v1, 0x3e7
/* B36E78 802422A8 10400003 */  beqz      $v0, .L802422B8
/* B36E7C 802422AC 0080882D */   daddu    $s1, $a0, $zero
/* B36E80 802422B0 24620001 */  addiu     $v0, $v1, 1
/* B36E84 802422B4 A60202C0 */  sh        $v0, 0x2c0($s0)
.L802422B8:
/* B36E88 802422B8 3C05F5DE */  lui       $a1, 0xf5de
/* B36E8C 802422BC 34A502E0 */  ori       $a1, $a1, 0x2e0
/* B36E90 802422C0 0C0B1EAF */  jal       evt_get_variable
/* B36E94 802422C4 0000202D */   daddu    $a0, $zero, $zero
/* B36E98 802422C8 3C038024 */  lui       $v1, %hi(D_802477C8_B3C398)
/* B36E9C 802422CC 00621821 */  addu      $v1, $v1, $v0
/* B36EA0 802422D0 906377C8 */  lbu       $v1, %lo(D_802477C8_B3C398)($v1)
/* B36EA4 802422D4 8E220084 */  lw        $v0, 0x84($s1)
/* B36EA8 802422D8 54430006 */  bnel      $v0, $v1, .L802422F4
/* B36EAC 802422DC AE200084 */   sw       $zero, 0x84($s1)
/* B36EB0 802422E0 24020001 */  addiu     $v0, $zero, 1
/* B36EB4 802422E4 AE220084 */  sw        $v0, 0x84($s1)
/* B36EB8 802422E8 960202C2 */  lhu       $v0, 0x2c2($s0)
/* B36EBC 802422EC 24420001 */  addiu     $v0, $v0, 1
/* B36EC0 802422F0 A60202C2 */  sh        $v0, 0x2c2($s0)
.L802422F4:
/* B36EC4 802422F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* B36EC8 802422F8 8FB10014 */  lw        $s1, 0x14($sp)
/* B36ECC 802422FC 8FB00010 */  lw        $s0, 0x10($sp)
/* B36ED0 80242300 24020002 */  addiu     $v0, $zero, 2
/* B36ED4 80242304 03E00008 */  jr        $ra
/* B36ED8 80242308 27BD0020 */   addiu    $sp, $sp, 0x20
