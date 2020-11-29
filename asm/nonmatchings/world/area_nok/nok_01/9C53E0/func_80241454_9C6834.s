.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241454_9C6834
/* 9C6834 80241454 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9C6838 80241458 AFB00010 */  sw        $s0, 0x10($sp)
/* 9C683C 8024145C 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 9C6840 80241460 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 9C6844 80241464 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9C6848 80241468 AFB10014 */  sw        $s1, 0x14($sp)
/* 9C684C 8024146C 960302C0 */  lhu       $v1, 0x2c0($s0)
/* 9C6850 80241470 2C6203E7 */  sltiu     $v0, $v1, 0x3e7
/* 9C6854 80241474 10400003 */  beqz      $v0, .L80241484
/* 9C6858 80241478 0080882D */   daddu    $s1, $a0, $zero
/* 9C685C 8024147C 24620001 */  addiu     $v0, $v1, 1
/* 9C6860 80241480 A60202C0 */  sh        $v0, 0x2c0($s0)
.L80241484:
/* 9C6864 80241484 3C05F5DE */  lui       $a1, 0xf5de
/* 9C6868 80241488 34A502E0 */  ori       $a1, $a1, 0x2e0
/* 9C686C 8024148C 0C0B1EAF */  jal       get_variable
/* 9C6870 80241490 0000202D */   daddu    $a0, $zero, $zero
/* 9C6874 80241494 3C038024 */  lui       $v1, %hi(D_80245FA8)
/* 9C6878 80241498 00621821 */  addu      $v1, $v1, $v0
/* 9C687C 8024149C 90635FA8 */  lbu       $v1, %lo(D_80245FA8)($v1)
/* 9C6880 802414A0 8E220084 */  lw        $v0, 0x84($s1)
/* 9C6884 802414A4 54430006 */  bnel      $v0, $v1, .L802414C0
/* 9C6888 802414A8 AE200084 */   sw       $zero, 0x84($s1)
/* 9C688C 802414AC 24020001 */  addiu     $v0, $zero, 1
/* 9C6890 802414B0 AE220084 */  sw        $v0, 0x84($s1)
/* 9C6894 802414B4 960202C2 */  lhu       $v0, 0x2c2($s0)
/* 9C6898 802414B8 24420001 */  addiu     $v0, $v0, 1
/* 9C689C 802414BC A60202C2 */  sh        $v0, 0x2c2($s0)
.L802414C0:
/* 9C68A0 802414C0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9C68A4 802414C4 8FB10014 */  lw        $s1, 0x14($sp)
/* 9C68A8 802414C8 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C68AC 802414CC 24020002 */  addiu     $v0, $zero, 2
/* 9C68B0 802414D0 03E00008 */  jr        $ra
/* 9C68B4 802414D4 27BD0020 */   addiu    $sp, $sp, 0x20
