.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240074
/* 90B2B4 80240074 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 90B2B8 80240078 3C048024 */  lui       $a0, 0x8024
/* 90B2BC 8024007C 24840480 */  addiu     $a0, $a0, 0x480
/* 90B2C0 80240080 AFB00018 */  sw        $s0, 0x18($sp)
/* 90B2C4 80240084 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 90B2C8 80240088 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 90B2CC 8024008C 27A50010 */  addiu     $a1, $sp, 0x10
/* 90B2D0 80240090 AFBF0028 */  sw        $ra, 0x28($sp)
/* 90B2D4 80240094 AFB30024 */  sw        $s3, 0x24($sp)
/* 90B2D8 80240098 AFB20020 */  sw        $s2, 0x20($sp)
/* 90B2DC 8024009C AFB1001C */  sw        $s1, 0x1c($sp)
/* 90B2E0 802400A0 8E020000 */  lw        $v0, ($s0)
/* 90B2E4 802400A4 94510086 */  lhu       $s1, 0x86($v0)
/* 90B2E8 802400A8 9452008C */  lhu       $s2, 0x8c($v0)
/* 90B2EC 802400AC 9453008E */  lhu       $s3, 0x8e($v0)
/* 90B2F0 802400B0 0C016AFE */  jal       get_map_IDs_by_name
/* 90B2F4 802400B4 27A60012 */   addiu    $a2, $sp, 0x12
/* 90B2F8 802400B8 8E030000 */  lw        $v1, ($s0)
/* 90B2FC 802400BC 97A20010 */  lhu       $v0, 0x10($sp)
/* 90B300 802400C0 97A50012 */  lhu       $a1, 0x12($sp)
/* 90B304 802400C4 90640166 */  lbu       $a0, 0x166($v1)
/* 90B308 802400C8 A4620086 */  sh        $v0, 0x86($v1)
/* 90B30C 802400CC 24020004 */  addiu     $v0, $zero, 4
/* 90B310 802400D0 A465008C */  sh        $a1, 0x8c($v1)
/* 90B314 802400D4 0C00ACDD */  jal       fio_save_game
/* 90B318 802400D8 A462008E */   sh       $v0, 0x8e($v1)
/* 90B31C 802400DC 8E030000 */  lw        $v1, ($s0)
/* 90B320 802400E0 A4710086 */  sh        $s1, 0x86($v1)
/* 90B324 802400E4 A472008C */  sh        $s2, 0x8c($v1)
/* 90B328 802400E8 A473008E */  sh        $s3, 0x8e($v1)
/* 90B32C 802400EC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 90B330 802400F0 8FB30024 */  lw        $s3, 0x24($sp)
/* 90B334 802400F4 8FB20020 */  lw        $s2, 0x20($sp)
/* 90B338 802400F8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 90B33C 802400FC 8FB00018 */  lw        $s0, 0x18($sp)
/* 90B340 80240100 24020002 */  addiu     $v0, $zero, 2
/* 90B344 80240104 03E00008 */  jr        $ra
/* 90B348 80240108 27BD0030 */   addiu    $sp, $sp, 0x30
/* 90B34C 8024010C 00000000 */  nop       
