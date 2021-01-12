.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004309C
/* 1E49C 8004309C 3C03800A */  lui       $v1, %hi(D_8009A5D0)
/* 1E4A0 800430A0 8C63A5D0 */  lw        $v1, %lo(D_8009A5D0)($v1)
/* 1E4A4 800430A4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1E4A8 800430A8 AFB10014 */  sw        $s1, 0x14($sp)
/* 1E4AC 800430AC 3C11800B */  lui       $s1, %hi(gCurrentEncounter)
/* 1E4B0 800430B0 26310F10 */  addiu     $s1, $s1, %lo(gCurrentEncounter)
/* 1E4B4 800430B4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 1E4B8 800430B8 10600006 */  beqz      $v1, .L800430D4
/* 1E4BC 800430BC AFB00010 */   sw       $s0, 0x10($sp)
/* 1E4C0 800430C0 24020001 */  addiu     $v0, $zero, 1
/* 1E4C4 800430C4 1062001B */  beq       $v1, $v0, .L80043134
/* 1E4C8 800430C8 00000000 */   nop
/* 1E4CC 800430CC 08010C70 */  j         .L800431C0
/* 1E4D0 800430D0 00000000 */   nop
.L800430D4:
/* 1E4D4 800430D4 8E30008C */  lw        $s0, 0x8c($s1)
/* 1E4D8 800430D8 8E020038 */  lw        $v0, 0x38($s0)
/* 1E4DC 800430DC 10400007 */  beqz      $v0, .L800430FC
/* 1E4E0 800430E0 0000882D */   daddu    $s1, $zero, $zero
/* 1E4E4 800430E4 8E040050 */  lw        $a0, 0x50($s0)
/* 1E4E8 800430E8 0C0B1059 */  jal       does_script_exist
/* 1E4EC 800430EC 00000000 */   nop
/* 1E4F0 800430F0 50400002 */  beql      $v0, $zero, .L800430FC
/* 1E4F4 800430F4 AE000038 */   sw       $zero, 0x38($s0)
/* 1E4F8 800430F8 24110001 */  addiu     $s1, $zero, 1
.L800430FC:
/* 1E4FC 800430FC 8E020040 */  lw        $v0, 0x40($s0)
/* 1E500 80043100 10400006 */  beqz      $v0, .L8004311C
/* 1E504 80043104 00000000 */   nop
/* 1E508 80043108 0C0B1059 */  jal       does_script_exist
/* 1E50C 8004310C 8E040058 */   lw       $a0, 0x58($s0)
/* 1E510 80043110 50400002 */  beql      $v0, $zero, .L8004311C
/* 1E514 80043114 AE000040 */   sw       $zero, 0x40($s0)
/* 1E518 80043118 24110001 */  addiu     $s1, $zero, 1
.L8004311C:
/* 1E51C 8004311C 16200028 */  bnez      $s1, .L800431C0
/* 1E520 80043120 24020001 */   addiu    $v0, $zero, 1
/* 1E524 80043124 3C01800A */  lui       $at, %hi(D_8009A5D0)
/* 1E528 80043128 AC22A5D0 */  sw        $v0, %lo(D_8009A5D0)($at)
/* 1E52C 8004312C 08010C70 */  j         .L800431C0
/* 1E530 80043130 00000000 */   nop
.L80043134:
/* 1E534 80043134 0C0B1192 */  jal       resume_all_group
/* 1E538 80043138 24040001 */   addiu    $a0, $zero, 1
/* 1E53C 8004313C 8E30008C */  lw        $s0, 0x8c($s1)
/* 1E540 80043140 12000006 */  beqz      $s0, .L8004315C
/* 1E544 80043144 00000000 */   nop
/* 1E548 80043148 8E02003C */  lw        $v0, 0x3c($s0)
/* 1E54C 8004314C 10400003 */  beqz      $v0, .L8004315C
/* 1E550 80043150 00000000 */   nop
/* 1E554 80043154 0C0B1123 */  jal       resume_all_script
/* 1E558 80043158 8E040054 */   lw       $a0, 0x54($s0)
.L8004315C:
/* 1E55C 8004315C 0C038069 */  jal       enable_player_input
/* 1E560 80043160 00000000 */   nop
/* 1E564 80043164 0C03BD80 */  jal       func_800EF600
/* 1E568 80043168 00000000 */   nop
/* 1E56C 8004316C 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 1E570 80043170 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 1E574 80043174 804300B4 */  lb        $v1, 0xb4($v0)
/* 1E578 80043178 2402000C */  addiu     $v0, $zero, 0xc
/* 1E57C 8004317C 14620003 */  bne       $v1, $v0, .L8004318C
/* 1E580 80043180 00000000 */   nop
/* 1E584 80043184 0C039769 */  jal       set_action_state
/* 1E588 80043188 0000202D */   daddu    $a0, $zero, $zero
.L8004318C:
/* 1E58C 8004318C 0C03BCF5 */  jal       func_800EF3D4
/* 1E590 80043190 0000202D */   daddu    $a0, $zero, $zero
/* 1E594 80043194 24040010 */  addiu     $a0, $zero, 0x10
/* 1E598 80043198 0C0B1192 */  jal       resume_all_group
/* 1E59C 8004319C A2200005 */   sb       $zero, 5($s1)
/* 1E5A0 800431A0 24020002 */  addiu     $v0, $zero, 2
/* 1E5A4 800431A4 3C01800A */  lui       $at, %hi(gGameState)
/* 1E5A8 800431A8 AC22A600 */  sw        $v0, %lo(gGameState)($at)
/* 1E5AC 800431AC 24020001 */  addiu     $v0, $zero, 1
/* 1E5B0 800431B0 3C01800A */  lui       $at, %hi(D_8009A678)
/* 1E5B4 800431B4 AC22A678 */  sw        $v0, %lo(D_8009A678)($at)
/* 1E5B8 800431B8 3C01800A */  lui       $at, %hi(D_8009A5D0)
/* 1E5BC 800431BC AC20A5D0 */  sw        $zero, %lo(D_8009A5D0)($at)
.L800431C0:
/* 1E5C0 800431C0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1E5C4 800431C4 8FB10014 */  lw        $s1, 0x14($sp)
/* 1E5C8 800431C8 8FB00010 */  lw        $s0, 0x10($sp)
/* 1E5CC 800431CC 03E00008 */  jr        $ra
/* 1E5D0 800431D0 27BD0020 */   addiu    $sp, $sp, 0x20
