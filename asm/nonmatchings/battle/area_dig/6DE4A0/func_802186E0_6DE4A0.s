.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802186E0_6DE4A0
/* 6DE4A0 802186E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6DE4A4 802186E4 3C04800E */  lui       $a0, %hi(gBattleStatus)
/* 6DE4A8 802186E8 2484C070 */  addiu     $a0, $a0, %lo(gBattleStatus)
/* 6DE4AC 802186EC AFBF0014 */  sw        $ra, 0x14($sp)
/* 6DE4B0 802186F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 6DE4B4 802186F4 A0800178 */  sb        $zero, 0x178($a0)
/* 6DE4B8 802186F8 3C03800B */  lui       $v1, %hi(gCurrentEncounter+0x6)
/* 6DE4BC 802186FC 90630F16 */  lbu       $v1, %lo(gCurrentEncounter+0x6)($v1)
/* 6DE4C0 80218700 8C9000D8 */  lw        $s0, 0xd8($a0)
/* 6DE4C4 80218704 24020020 */  addiu     $v0, $zero, 0x20
/* 6DE4C8 80218708 A482017C */  sh        $v0, 0x17c($a0)
/* 6DE4CC 8021870C 3C028009 */  lui       $v0, %hi(D_8008F2E4)
/* 6DE4D0 80218710 8C42F2E4 */  lw        $v0, %lo(D_8008F2E4)($v0)
/* 6DE4D4 80218714 00031E00 */  sll       $v1, $v1, 0x18
/* 6DE4D8 80218718 00031E03 */  sra       $v1, $v1, 0x18
/* 6DE4DC 8021871C A483017A */  sh        $v1, 0x17a($a0)
/* 6DE4E0 80218720 AC820184 */  sw        $v0, 0x184($a0)
/* 6DE4E4 80218724 0C098C0B */  jal       player_create_target_list
/* 6DE4E8 80218728 0200202D */   daddu    $a0, $s0, $zero
/* 6DE4EC 8021872C 8203040E */  lb        $v1, 0x40e($s0)
/* 6DE4F0 80218730 24020001 */  addiu     $v0, $zero, 1
/* 6DE4F4 80218734 A2020425 */  sb        $v0, 0x425($s0)
/* 6DE4F8 80218738 00031080 */  sll       $v0, $v1, 2
/* 6DE4FC 8021873C 00431021 */  addu      $v0, $v0, $v1
/* 6DE500 80218740 00021080 */  sll       $v0, $v0, 2
/* 6DE504 80218744 2442022C */  addiu     $v0, $v0, 0x22c
/* 6DE508 80218748 02021021 */  addu      $v0, $s0, $v0
/* 6DE50C 8021874C 94430000 */  lhu       $v1, ($v0)
/* 6DE510 80218750 A6030428 */  sh        $v1, 0x428($s0)
/* 6DE514 80218754 90420003 */  lbu       $v0, 3($v0)
/* 6DE518 80218758 A2020426 */  sb        $v0, 0x426($s0)
/* 6DE51C 8021875C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6DE520 80218760 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DE524 80218764 24020002 */  addiu     $v0, $zero, 2
/* 6DE528 80218768 03E00008 */  jr        $ra
/* 6DE52C 8021876C 27BD0018 */   addiu    $sp, $sp, 0x18
