.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel PlayerPowerBounceEnemy
/* 1A2D80 802744A0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1A2D84 802744A4 AFB20018 */  sw        $s2, 0x18($sp)
/* 1A2D88 802744A8 0080902D */  daddu     $s2, $a0, $zero
/* 1A2D8C 802744AC AFBF0020 */  sw        $ra, 0x20($sp)
/* 1A2D90 802744B0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1A2D94 802744B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 1A2D98 802744B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 1A2D9C 802744BC 8E50000C */  lw        $s0, 0xc($s2)
/* 1A2DA0 802744C0 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 1A2DA4 802744C4 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 1A2DA8 802744C8 8E130000 */  lw        $s3, ($s0)
/* 1A2DAC 802744CC 26100004 */  addiu     $s0, $s0, 4
/* 1A2DB0 802744D0 8E020000 */  lw        $v0, ($s0)
/* 1A2DB4 802744D4 26100004 */  addiu     $s0, $s0, 4
/* 1A2DB8 802744D8 AE220188 */  sw        $v0, 0x188($s1)
/* 1A2DBC 802744DC 8E020000 */  lw        $v0, ($s0)
/* 1A2DC0 802744E0 26100004 */  addiu     $s0, $s0, 4
/* 1A2DC4 802744E4 AE22018C */  sw        $v0, 0x18c($s1)
/* 1A2DC8 802744E8 8E020000 */  lw        $v0, ($s0)
/* 1A2DCC 802744EC 26100004 */  addiu     $s0, $s0, 4
/* 1A2DD0 802744F0 AE220190 */  sw        $v0, 0x190($s1)
/* 1A2DD4 802744F4 8E050000 */  lw        $a1, ($s0)
/* 1A2DD8 802744F8 0C0B1EAF */  jal       get_variable
/* 1A2DDC 802744FC 26100004 */   addiu    $s0, $s0, 4
/* 1A2DE0 80274500 A622017E */  sh        $v0, 0x17e($s1)
/* 1A2DE4 80274504 8E050000 */  lw        $a1, ($s0)
/* 1A2DE8 80274508 26100004 */  addiu     $s0, $s0, 4
/* 1A2DEC 8027450C 0C0B1EAF */  jal       get_variable
/* 1A2DF0 80274510 0240202D */   daddu    $a0, $s2, $zero
/* 1A2DF4 80274514 A2220198 */  sb        $v0, 0x198($s1)
/* 1A2DF8 80274518 8E100000 */  lw        $s0, ($s0)
/* 1A2DFC 8027451C 24020030 */  addiu     $v0, $zero, 0x30
/* 1A2E00 80274520 32030030 */  andi      $v1, $s0, 0x30
/* 1A2E04 80274524 54620004 */  bnel      $v1, $v0, .L80274538
/* 1A2E08 80274528 32020010 */   andi     $v0, $s0, 0x10
/* 1A2E0C 8027452C 8E220000 */  lw        $v0, ($s1)
/* 1A2E10 80274530 0809D15E */  j         .L80274578
/* 1A2E14 80274534 34420030 */   ori      $v0, $v0, 0x30
.L80274538:
/* 1A2E18 80274538 10400004 */  beqz      $v0, .L8027454C
/* 1A2E1C 8027453C 2403FFDF */   addiu    $v1, $zero, -0x21
/* 1A2E20 80274540 8E220000 */  lw        $v0, ($s1)
/* 1A2E24 80274544 0809D15D */  j         .L80274574
/* 1A2E28 80274548 34420010 */   ori      $v0, $v0, 0x10
.L8027454C:
/* 1A2E2C 8027454C 32020020 */  andi      $v0, $s0, 0x20
/* 1A2E30 80274550 10400005 */  beqz      $v0, .L80274568
/* 1A2E34 80274554 2403FFEF */   addiu    $v1, $zero, -0x11
/* 1A2E38 80274558 8E220000 */  lw        $v0, ($s1)
/* 1A2E3C 8027455C 00431024 */  and       $v0, $v0, $v1
/* 1A2E40 80274560 0809D15E */  j         .L80274578
/* 1A2E44 80274564 34420020 */   ori      $v0, $v0, 0x20
.L80274568:
/* 1A2E48 80274568 8E220000 */  lw        $v0, ($s1)
/* 1A2E4C 8027456C 00431024 */  and       $v0, $v0, $v1
/* 1A2E50 80274570 2403FFDF */  addiu     $v1, $zero, -0x21
.L80274574:
/* 1A2E54 80274574 00431024 */  and       $v0, $v0, $v1
.L80274578:
/* 1A2E58 80274578 AE220000 */  sw        $v0, ($s1)
/* 1A2E5C 8027457C 32020040 */  andi      $v0, $s0, 0x40
/* 1A2E60 80274580 10400007 */  beqz      $v0, .L802745A0
/* 1A2E64 80274584 2404FFBF */   addiu    $a0, $zero, -0x41
/* 1A2E68 80274588 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1A2E6C 8027458C 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1A2E70 80274590 8C620000 */  lw        $v0, ($v1)
/* 1A2E74 80274594 34420040 */  ori       $v0, $v0, 0x40
/* 1A2E78 80274598 0809D16D */  j         .L802745B4
/* 1A2E7C 8027459C AC620000 */   sw       $v0, ($v1)
.L802745A0:
/* 1A2E80 802745A0 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1A2E84 802745A4 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1A2E88 802745A8 8C430000 */  lw        $v1, ($v0)
/* 1A2E8C 802745AC 00641824 */  and       $v1, $v1, $a0
/* 1A2E90 802745B0 AC430000 */  sw        $v1, ($v0)
.L802745B4:
/* 1A2E94 802745B4 32020200 */  andi      $v0, $s0, 0x200
/* 1A2E98 802745B8 10400007 */  beqz      $v0, .L802745D8
/* 1A2E9C 802745BC 2404FDFF */   addiu    $a0, $zero, -0x201
/* 1A2EA0 802745C0 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1A2EA4 802745C4 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1A2EA8 802745C8 8C620000 */  lw        $v0, ($v1)
/* 1A2EAC 802745CC 34420200 */  ori       $v0, $v0, 0x200
/* 1A2EB0 802745D0 0809D17B */  j         .L802745EC
/* 1A2EB4 802745D4 AC620000 */   sw       $v0, ($v1)
.L802745D8:
/* 1A2EB8 802745D8 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1A2EBC 802745DC 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1A2EC0 802745E0 8C430000 */  lw        $v1, ($v0)
/* 1A2EC4 802745E4 00641824 */  and       $v1, $v1, $a0
/* 1A2EC8 802745E8 AC430000 */  sw        $v1, ($v0)
.L802745EC:
/* 1A2ECC 802745EC 32020080 */  andi      $v0, $s0, 0x80
/* 1A2ED0 802745F0 10400007 */  beqz      $v0, .L80274610
/* 1A2ED4 802745F4 2404FF7F */   addiu    $a0, $zero, -0x81
/* 1A2ED8 802745F8 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1A2EDC 802745FC 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1A2EE0 80274600 8C620000 */  lw        $v0, ($v1)
/* 1A2EE4 80274604 34420080 */  ori       $v0, $v0, 0x80
/* 1A2EE8 80274608 0809D189 */  j         .L80274624
/* 1A2EEC 8027460C AC620000 */   sw       $v0, ($v1)
.L80274610:
/* 1A2EF0 80274610 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1A2EF4 80274614 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1A2EF8 80274618 8C430000 */  lw        $v1, ($v0)
/* 1A2EFC 8027461C 00641824 */  and       $v1, $v1, $a0
/* 1A2F00 80274620 AC430000 */  sw        $v1, ($v0)
.L80274624:
/* 1A2F04 80274624 32020800 */  andi      $v0, $s0, 0x800
/* 1A2F08 80274628 10400007 */  beqz      $v0, .L80274648
/* 1A2F0C 8027462C 2404F7FF */   addiu    $a0, $zero, -0x801
/* 1A2F10 80274630 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1A2F14 80274634 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1A2F18 80274638 8C620000 */  lw        $v0, ($v1)
/* 1A2F1C 8027463C 34420800 */  ori       $v0, $v0, 0x800
/* 1A2F20 80274640 0809D197 */  j         .L8027465C
/* 1A2F24 80274644 AC620000 */   sw       $v0, ($v1)
.L80274648:
/* 1A2F28 80274648 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1A2F2C 8027464C 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1A2F30 80274650 8C430000 */  lw        $v1, ($v0)
/* 1A2F34 80274654 00641824 */  and       $v1, $v1, $a0
/* 1A2F38 80274658 AC430000 */  sw        $v1, ($v0)
.L8027465C:
/* 1A2F3C 8027465C 0C09A75B */  jal       get_actor
/* 1A2F40 80274660 8E440148 */   lw       $a0, 0x148($s2)
/* 1A2F44 80274664 94430428 */  lhu       $v1, 0x428($v0)
/* 1A2F48 80274668 A62301A0 */  sh        $v1, 0x1a0($s1)
/* 1A2F4C 8027466C 92230193 */  lbu       $v1, 0x193($s1)
/* 1A2F50 80274670 90420426 */  lbu       $v0, 0x426($v0)
/* 1A2F54 80274674 A2230194 */  sb        $v1, 0x194($s1)
/* 1A2F58 80274678 306300FF */  andi      $v1, $v1, 0xff
/* 1A2F5C 8027467C A22201A2 */  sb        $v0, 0x1a2($s1)
/* 1A2F60 80274680 240200FF */  addiu     $v0, $zero, 0xff
/* 1A2F64 80274684 50620001 */  beql      $v1, $v0, .L8027468C
/* 1A2F68 80274688 A2200194 */   sb       $zero, 0x194($s1)
.L8027468C:
/* 1A2F6C 8027468C 8E220190 */  lw        $v0, 0x190($s1)
/* 1A2F70 80274690 30420F00 */  andi      $v0, $v0, 0xf00
/* 1A2F74 80274694 00021203 */  sra       $v0, $v0, 8
/* 1A2F78 80274698 0C09C651 */  jal       calc_player_damage_enemy
/* 1A2F7C 8027469C A2220195 */   sb       $v0, 0x195($s1)
/* 1A2F80 802746A0 0440000B */  bltz      $v0, .L802746D0
/* 1A2F84 802746A4 0240202D */   daddu    $a0, $s2, $zero
/* 1A2F88 802746A8 0260282D */  daddu     $a1, $s3, $zero
/* 1A2F8C 802746AC 0C0B2026 */  jal       set_variable
/* 1A2F90 802746B0 0040302D */   daddu    $a2, $v0, $zero
/* 1A2F94 802746B4 0C0B1069 */  jal       does_script_exist_by_ref
/* 1A2F98 802746B8 0240202D */   daddu    $a0, $s2, $zero
/* 1A2F9C 802746BC 0040182D */  daddu     $v1, $v0, $zero
/* 1A2FA0 802746C0 10600004 */  beqz      $v1, .L802746D4
/* 1A2FA4 802746C4 240200FF */   addiu    $v0, $zero, 0xff
/* 1A2FA8 802746C8 0809D1B5 */  j         .L802746D4
/* 1A2FAC 802746CC 24020002 */   addiu    $v0, $zero, 2
.L802746D0:
/* 1A2FB0 802746D0 240200FF */  addiu     $v0, $zero, 0xff
.L802746D4:
/* 1A2FB4 802746D4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1A2FB8 802746D8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1A2FBC 802746DC 8FB20018 */  lw        $s2, 0x18($sp)
/* 1A2FC0 802746E0 8FB10014 */  lw        $s1, 0x14($sp)
/* 1A2FC4 802746E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 1A2FC8 802746E8 03E00008 */  jr        $ra
/* 1A2FCC 802746EC 27BD0028 */   addiu    $sp, $sp, 0x28
