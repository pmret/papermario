.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D1C_7EBA2C
/* 7EBA2C 80240D1C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7EBA30 80240D20 AFB00010 */  sw        $s0, 0x10($sp)
/* 7EBA34 80240D24 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 7EBA38 80240D28 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 7EBA3C 80240D2C AFBF0018 */  sw        $ra, 0x18($sp)
/* 7EBA40 80240D30 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EBA44 80240D34 960302C0 */  lhu       $v1, 0x2c0($s0)
/* 7EBA48 80240D38 2C6203E7 */  sltiu     $v0, $v1, 0x3e7
/* 7EBA4C 80240D3C 10400003 */  beqz      $v0, .L80240D4C
/* 7EBA50 80240D40 0080882D */   daddu    $s1, $a0, $zero
/* 7EBA54 80240D44 24620001 */  addiu     $v0, $v1, 1
/* 7EBA58 80240D48 A60202C0 */  sh        $v0, 0x2c0($s0)
.L80240D4C:
/* 7EBA5C 80240D4C 3C05F5DE */  lui       $a1, 0xf5de
/* 7EBA60 80240D50 34A502E0 */  ori       $a1, $a1, 0x2e0
/* 7EBA64 80240D54 0C0B1EAF */  jal       get_variable
/* 7EBA68 80240D58 0000202D */   daddu    $a0, $zero, $zero
/* 7EBA6C 80240D5C 3C038024 */  lui       $v1, %hi(D_80245E24)
/* 7EBA70 80240D60 00621821 */  addu      $v1, $v1, $v0
/* 7EBA74 80240D64 90635E24 */  lbu       $v1, %lo(D_80245E24)($v1)
/* 7EBA78 80240D68 8E220084 */  lw        $v0, 0x84($s1)
/* 7EBA7C 80240D6C 54430006 */  bnel      $v0, $v1, .L80240D88
/* 7EBA80 80240D70 AE200084 */   sw       $zero, 0x84($s1)
/* 7EBA84 80240D74 24020001 */  addiu     $v0, $zero, 1
/* 7EBA88 80240D78 AE220084 */  sw        $v0, 0x84($s1)
/* 7EBA8C 80240D7C 960202C2 */  lhu       $v0, 0x2c2($s0)
/* 7EBA90 80240D80 24420001 */  addiu     $v0, $v0, 1
/* 7EBA94 80240D84 A60202C2 */  sh        $v0, 0x2c2($s0)
.L80240D88:
/* 7EBA98 80240D88 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7EBA9C 80240D8C 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EBAA0 80240D90 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EBAA4 80240D94 24020002 */  addiu     $v0, $zero, 2
/* 7EBAA8 80240D98 03E00008 */  jr        $ra
/* 7EBAAC 80240D9C 27BD0020 */   addiu    $sp, $sp, 0x20
