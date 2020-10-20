.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241EAC
/* 82516C 80241EAC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 825170 80241EB0 AFB00010 */  sw        $s0, 0x10($sp)
/* 825174 80241EB4 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 825178 80241EB8 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 82517C 80241EBC AFBF0018 */  sw        $ra, 0x18($sp)
/* 825180 80241EC0 AFB10014 */  sw        $s1, 0x14($sp)
/* 825184 80241EC4 960302C0 */  lhu       $v1, 0x2c0($s0)
/* 825188 80241EC8 2C6203E7 */  sltiu     $v0, $v1, 0x3e7
/* 82518C 80241ECC 10400003 */  beqz      $v0, .L80241EDC
/* 825190 80241ED0 0080882D */   daddu    $s1, $a0, $zero
/* 825194 80241ED4 24620001 */  addiu     $v0, $v1, 1
/* 825198 80241ED8 A60202C0 */  sh        $v0, 0x2c0($s0)
.L80241EDC:
/* 82519C 80241EDC 3C05F5DE */  lui       $a1, 0xf5de
/* 8251A0 80241EE0 34A502E0 */  ori       $a1, $a1, 0x2e0
/* 8251A4 80241EE4 0C0B1EAF */  jal       get_variable
/* 8251A8 80241EE8 0000202D */   daddu    $a0, $zero, $zero
/* 8251AC 80241EEC 3C038024 */  lui       $v1, 0x8024
/* 8251B0 80241EF0 00621821 */  addu      $v1, $v1, $v0
/* 8251B4 80241EF4 906361B4 */  lbu       $v1, 0x61b4($v1)
/* 8251B8 80241EF8 8E220084 */  lw        $v0, 0x84($s1)
/* 8251BC 80241EFC 54430006 */  bnel      $v0, $v1, .L80241F18
/* 8251C0 80241F00 AE200084 */   sw       $zero, 0x84($s1)
/* 8251C4 80241F04 24020001 */  addiu     $v0, $zero, 1
/* 8251C8 80241F08 AE220084 */  sw        $v0, 0x84($s1)
/* 8251CC 80241F0C 960202C2 */  lhu       $v0, 0x2c2($s0)
/* 8251D0 80241F10 24420001 */  addiu     $v0, $v0, 1
/* 8251D4 80241F14 A60202C2 */  sh        $v0, 0x2c2($s0)
.L80241F18:
/* 8251D8 80241F18 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8251DC 80241F1C 8FB10014 */  lw        $s1, 0x14($sp)
/* 8251E0 80241F20 8FB00010 */  lw        $s0, 0x10($sp)
/* 8251E4 80241F24 24020002 */  addiu     $v0, $zero, 2
/* 8251E8 80241F28 03E00008 */  jr        $ra
/* 8251EC 80241F2C 27BD0020 */   addiu    $sp, $sp, 0x20
