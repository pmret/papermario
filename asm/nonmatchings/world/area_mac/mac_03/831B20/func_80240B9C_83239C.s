.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B9C_83239C
/* 83239C 80240B9C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8323A0 80240BA0 AFB00010 */  sw        $s0, 0x10($sp)
/* 8323A4 80240BA4 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 8323A8 80240BA8 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 8323AC 80240BAC AFBF0018 */  sw        $ra, 0x18($sp)
/* 8323B0 80240BB0 AFB10014 */  sw        $s1, 0x14($sp)
/* 8323B4 80240BB4 960302C0 */  lhu       $v1, 0x2c0($s0)
/* 8323B8 80240BB8 2C6203E7 */  sltiu     $v0, $v1, 0x3e7
/* 8323BC 80240BBC 10400003 */  beqz      $v0, .L80240BCC
/* 8323C0 80240BC0 0080882D */   daddu    $s1, $a0, $zero
/* 8323C4 80240BC4 24620001 */  addiu     $v0, $v1, 1
/* 8323C8 80240BC8 A60202C0 */  sh        $v0, 0x2c0($s0)
.L80240BCC:
/* 8323CC 80240BCC 3C05F5DE */  lui       $a1, 0xf5de
/* 8323D0 80240BD0 34A502E0 */  ori       $a1, $a1, 0x2e0
/* 8323D4 80240BD4 0C0B1EAF */  jal       get_variable
/* 8323D8 80240BD8 0000202D */   daddu    $a0, $zero, $zero
/* 8323DC 80240BDC 3C038024 */  lui       $v1, %hi(D_802466A8_837EA8)
/* 8323E0 80240BE0 00621821 */  addu      $v1, $v1, $v0
/* 8323E4 80240BE4 906366A8 */  lbu       $v1, %lo(D_802466A8_837EA8)($v1)
/* 8323E8 80240BE8 8E220084 */  lw        $v0, 0x84($s1)
/* 8323EC 80240BEC 54430006 */  bnel      $v0, $v1, .L80240C08
/* 8323F0 80240BF0 AE200084 */   sw       $zero, 0x84($s1)
/* 8323F4 80240BF4 24020001 */  addiu     $v0, $zero, 1
/* 8323F8 80240BF8 AE220084 */  sw        $v0, 0x84($s1)
/* 8323FC 80240BFC 960202C2 */  lhu       $v0, 0x2c2($s0)
/* 832400 80240C00 24420001 */  addiu     $v0, $v0, 1
/* 832404 80240C04 A60202C2 */  sh        $v0, 0x2c2($s0)
.L80240C08:
/* 832408 80240C08 8FBF0018 */  lw        $ra, 0x18($sp)
/* 83240C 80240C0C 8FB10014 */  lw        $s1, 0x14($sp)
/* 832410 80240C10 8FB00010 */  lw        $s0, 0x10($sp)
/* 832414 80240C14 24020002 */  addiu     $v0, $zero, 2
/* 832418 80240C18 03E00008 */  jr        $ra
/* 83241C 80240C1C 27BD0020 */   addiu    $sp, $sp, 0x20
