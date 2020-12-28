.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218644_6DE404
/* 6DE404 80218644 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6DE408 80218648 3C04800E */  lui       $a0, %hi(gBattleStatus)
/* 6DE40C 8021864C 2484C070 */  addiu     $a0, $a0, %lo(gBattleStatus)
/* 6DE410 80218650 24020001 */  addiu     $v0, $zero, 1
/* 6DE414 80218654 AFBF0014 */  sw        $ra, 0x14($sp)
/* 6DE418 80218658 AFB00010 */  sw        $s0, 0x10($sp)
/* 6DE41C 8021865C A0820178 */  sb        $v0, 0x178($a0)
/* 6DE420 80218660 3C03800B */  lui       $v1, %hi(gCurrentEncounter+0x6)
/* 6DE424 80218664 90630F16 */  lbu       $v1, %lo(gCurrentEncounter+0x6)($v1)
/* 6DE428 80218668 8C9000D8 */  lw        $s0, 0xd8($a0)
/* 6DE42C 8021866C 24020003 */  addiu     $v0, $zero, 3
/* 6DE430 80218670 A482017C */  sh        $v0, 0x17c($a0)
/* 6DE434 80218674 3C028009 */  lui       $v0, %hi(D_8008F0A0)
/* 6DE438 80218678 8C42F0A0 */  lw        $v0, %lo(D_8008F0A0)($v0)
/* 6DE43C 8021867C 00031E00 */  sll       $v1, $v1, 0x18
/* 6DE440 80218680 00031E03 */  sra       $v1, $v1, 0x18
/* 6DE444 80218684 A483017A */  sh        $v1, 0x17a($a0)
/* 6DE448 80218688 AC820184 */  sw        $v0, 0x184($a0)
/* 6DE44C 8021868C 0C098C0B */  jal       player_create_target_list
/* 6DE450 80218690 0200202D */   daddu    $a0, $s0, $zero
/* 6DE454 80218694 8203040D */  lb        $v1, 0x40d($s0)
/* 6DE458 80218698 A2000425 */  sb        $zero, 0x425($s0)
/* 6DE45C 8021869C 00031080 */  sll       $v0, $v1, 2
/* 6DE460 802186A0 00431021 */  addu      $v0, $v0, $v1
/* 6DE464 802186A4 00021080 */  sll       $v0, $v0, 2
/* 6DE468 802186A8 2442022C */  addiu     $v0, $v0, 0x22c
/* 6DE46C 802186AC 02021021 */  addu      $v0, $s0, $v0
/* 6DE470 802186B0 94430000 */  lhu       $v1, ($v0)
/* 6DE474 802186B4 A6030428 */  sh        $v1, 0x428($s0)
/* 6DE478 802186B8 90420003 */  lbu       $v0, 3($v0)
/* 6DE47C 802186BC A2020426 */  sb        $v0, 0x426($s0)
/* 6DE480 802186C0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6DE484 802186C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DE488 802186C8 24020002 */  addiu     $v0, $zero, 2
/* 6DE48C 802186CC 03E00008 */  jr        $ra
/* 6DE490 802186D0 27BD0018 */   addiu    $sp, $sp, 0x18
/* 6DE494 802186D4 00000000 */  nop       
/* 6DE498 802186D8 00000000 */  nop       
/* 6DE49C 802186DC 00000000 */  nop       
