.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A0C_853B7C
/* 853B7C 80241A0C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 853B80 80241A10 AFB00010 */  sw        $s0, 0x10($sp)
/* 853B84 80241A14 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 853B88 80241A18 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 853B8C 80241A1C AFBF0018 */  sw        $ra, 0x18($sp)
/* 853B90 80241A20 AFB10014 */  sw        $s1, 0x14($sp)
/* 853B94 80241A24 960302C0 */  lhu       $v1, 0x2c0($s0)
/* 853B98 80241A28 2C6203E7 */  sltiu     $v0, $v1, 0x3e7
/* 853B9C 80241A2C 10400003 */  beqz      $v0, .L80241A3C
/* 853BA0 80241A30 0080882D */   daddu    $s1, $a0, $zero
/* 853BA4 80241A34 24620001 */  addiu     $v0, $v1, 1
/* 853BA8 80241A38 A60202C0 */  sh        $v0, 0x2c0($s0)
.L80241A3C:
/* 853BAC 80241A3C 3C05F5DE */  lui       $a1, 0xf5de
/* 853BB0 80241A40 34A502E0 */  ori       $a1, $a1, 0x2e0
/* 853BB4 80241A44 0C0B1EAF */  jal       evt_get_variable
/* 853BB8 80241A48 0000202D */   daddu    $a0, $zero, $zero
/* 853BBC 80241A4C 3C038024 */  lui       $v1, %hi(D_80245114_857284)
/* 853BC0 80241A50 00621821 */  addu      $v1, $v1, $v0
/* 853BC4 80241A54 90635114 */  lbu       $v1, %lo(D_80245114_857284)($v1)
/* 853BC8 80241A58 8E220084 */  lw        $v0, 0x84($s1)
/* 853BCC 80241A5C 54430006 */  bnel      $v0, $v1, .L80241A78
/* 853BD0 80241A60 AE200084 */   sw       $zero, 0x84($s1)
/* 853BD4 80241A64 24020001 */  addiu     $v0, $zero, 1
/* 853BD8 80241A68 AE220084 */  sw        $v0, 0x84($s1)
/* 853BDC 80241A6C 960202C2 */  lhu       $v0, 0x2c2($s0)
/* 853BE0 80241A70 24420001 */  addiu     $v0, $v0, 1
/* 853BE4 80241A74 A60202C2 */  sh        $v0, 0x2c2($s0)
.L80241A78:
/* 853BE8 80241A78 8FBF0018 */  lw        $ra, 0x18($sp)
/* 853BEC 80241A7C 8FB10014 */  lw        $s1, 0x14($sp)
/* 853BF0 80241A80 8FB00010 */  lw        $s0, 0x10($sp)
/* 853BF4 80241A84 24020002 */  addiu     $v0, $zero, 2
/* 853BF8 80241A88 03E00008 */  jr        $ra
/* 853BFC 80241A8C 27BD0020 */   addiu    $sp, $sp, 0x20
