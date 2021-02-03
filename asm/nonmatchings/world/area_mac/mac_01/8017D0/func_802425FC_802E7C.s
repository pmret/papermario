.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802425FC_802E7C
/* 802E7C 802425FC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 802E80 80242600 AFB00010 */  sw        $s0, 0x10($sp)
/* 802E84 80242604 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 802E88 80242608 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 802E8C 8024260C AFBF0018 */  sw        $ra, 0x18($sp)
/* 802E90 80242610 AFB10014 */  sw        $s1, 0x14($sp)
/* 802E94 80242614 960302C0 */  lhu       $v1, 0x2c0($s0)
/* 802E98 80242618 2C6203E7 */  sltiu     $v0, $v1, 0x3e7
/* 802E9C 8024261C 10400003 */  beqz      $v0, .L8024262C
/* 802EA0 80242620 0080882D */   daddu    $s1, $a0, $zero
/* 802EA4 80242624 24620001 */  addiu     $v0, $v1, 1
/* 802EA8 80242628 A60202C0 */  sh        $v0, 0x2c0($s0)
.L8024262C:
/* 802EAC 8024262C 3C05F5DE */  lui       $a1, 0xf5de
/* 802EB0 80242630 34A502E0 */  ori       $a1, $a1, 0x2e0
/* 802EB4 80242634 0C0B1EAF */  jal       get_variable
/* 802EB8 80242638 0000202D */   daddu    $a0, $zero, $zero
/* 802EBC 8024263C 3C038025 */  lui       $v1, %hi(D_80248C94_809514)
/* 802EC0 80242640 00621821 */  addu      $v1, $v1, $v0
/* 802EC4 80242644 90638C94 */  lbu       $v1, %lo(D_80248C94_809514)($v1)
/* 802EC8 80242648 8E220084 */  lw        $v0, 0x84($s1)
/* 802ECC 8024264C 54430006 */  bnel      $v0, $v1, .L80242668
/* 802ED0 80242650 AE200084 */   sw       $zero, 0x84($s1)
/* 802ED4 80242654 24020001 */  addiu     $v0, $zero, 1
/* 802ED8 80242658 AE220084 */  sw        $v0, 0x84($s1)
/* 802EDC 8024265C 960202C2 */  lhu       $v0, 0x2c2($s0)
/* 802EE0 80242660 24420001 */  addiu     $v0, $v0, 1
/* 802EE4 80242664 A60202C2 */  sh        $v0, 0x2c2($s0)
.L80242668:
/* 802EE8 80242668 8FBF0018 */  lw        $ra, 0x18($sp)
/* 802EEC 8024266C 8FB10014 */  lw        $s1, 0x14($sp)
/* 802EF0 80242670 8FB00010 */  lw        $s0, 0x10($sp)
/* 802EF4 80242674 24020002 */  addiu     $v0, $zero, 2
/* 802EF8 80242678 03E00008 */  jr        $ra
/* 802EFC 8024267C 27BD0020 */   addiu    $sp, $sp, 0x20
