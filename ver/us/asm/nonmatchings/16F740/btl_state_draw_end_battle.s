.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_state_draw_end_battle
/* 173670 80244D90 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 173674 80244D94 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 173678 80244D98 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 17367C 80244D9C 3C04800B */  lui       $a0, %hi(gCameras)
/* 173680 80244DA0 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* 173684 80244DA4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 173688 80244DA8 00031080 */  sll       $v0, $v1, 2
/* 17368C 80244DAC 00431021 */  addu      $v0, $v0, $v1
/* 173690 80244DB0 00021080 */  sll       $v0, $v0, 2
/* 173694 80244DB4 00431023 */  subu      $v0, $v0, $v1
/* 173698 80244DB8 000218C0 */  sll       $v1, $v0, 3
/* 17369C 80244DBC 00431021 */  addu      $v0, $v0, $v1
/* 1736A0 80244DC0 000210C0 */  sll       $v0, $v0, 3
/* 1736A4 80244DC4 00443021 */  addu      $a2, $v0, $a0
/* 1736A8 80244DC8 3C03800B */  lui       $v1, %hi(gCurrentEncounter+0x9)
/* 1736AC 80244DCC 80630F19 */  lb        $v1, %lo(gCurrentEncounter+0x9)($v1)
/* 1736B0 80244DD0 24020001 */  addiu     $v0, $zero, 1
/* 1736B4 80244DD4 1462000E */  bne       $v1, $v0, .L80244E10
/* 1736B8 80244DD8 3C030080 */   lui      $v1, 0x80
/* 1736BC 80244DDC 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1736C0 80244DE0 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1736C4 80244DE4 00431024 */  and       $v0, $v0, $v1
/* 1736C8 80244DE8 14400009 */  bnez      $v0, .L80244E10
/* 1736CC 80244DEC 24040007 */   addiu    $a0, $zero, 7
/* 1736D0 80244DF0 3C018028 */  lui       $at, %hi(D_80280A30)
/* 1736D4 80244DF4 C4200A30 */  lwc1      $f0, %lo(D_80280A30)($at)
/* 1736D8 80244DF8 46800020 */  cvt.s.w   $f0, $f0
/* 1736DC 80244DFC 94C20026 */  lhu       $v0, 0x26($a2)
/* 1736E0 80244E00 44050000 */  mfc1      $a1, $f0
/* 1736E4 80244E04 24420100 */  addiu     $v0, $v0, 0x100
/* 1736E8 80244E08 08091389 */  j         .L80244E24
/* 1736EC 80244E0C A4C20026 */   sh       $v0, 0x26($a2)
.L80244E10:
/* 1736F0 80244E10 3C018028 */  lui       $at, %hi(D_80280A30)
/* 1736F4 80244E14 C4200A30 */  lwc1      $f0, %lo(D_80280A30)($at)
/* 1736F8 80244E18 46800020 */  cvt.s.w   $f0, $f0
/* 1736FC 80244E1C 44050000 */  mfc1      $a1, $f0
/* 173700 80244E20 0000202D */  daddu     $a0, $zero, $zero
.L80244E24:
/* 173704 80244E24 0C04DF62 */  jal       set_screen_overlay_params_front
/* 173708 80244E28 00000000 */   nop
/* 17370C 80244E2C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 173710 80244E30 03E00008 */  jr        $ra
/* 173714 80244E34 27BD0018 */   addiu    $sp, $sp, 0x18
