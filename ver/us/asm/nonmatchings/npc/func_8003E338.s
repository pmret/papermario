.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003E338
/* 19738 8003E338 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1973C 8003E33C AFBF0010 */  sw        $ra, 0x10($sp)
/* 19740 8003E340 24050017 */  addiu     $a1, $zero, 0x17
/* 19744 8003E344 3C06800B */  lui       $a2, %hi(gCurrentEncounter)
/* 19748 8003E348 24C60F10 */  addiu     $a2, $a2, %lo(gCurrentEncounter)
/* 1974C 8003E34C 24C2005C */  addiu     $v0, $a2, 0x5c
.L8003E350:
/* 19750 8003E350 AC400028 */  sw        $zero, 0x28($v0)
/* 19754 8003E354 24A5FFFF */  addiu     $a1, $a1, -1
/* 19758 8003E358 04A1FFFD */  bgez      $a1, .L8003E350
/* 1975C 8003E35C 2442FFFC */   addiu    $v0, $v0, -4
/* 19760 8003E360 0000282D */  daddu     $a1, $zero, $zero
/* 19764 8003E364 00A0382D */  daddu     $a3, $a1, $zero
/* 19768 8003E368 ACC00000 */  sw        $zero, ($a2)
/* 1976C 8003E36C A0C0001C */  sb        $zero, 0x1c($a2)
/* 19770 8003E370 A0C00004 */  sb        $zero, 4($a2)
/* 19774 8003E374 A0C00005 */  sb        $zero, 5($a2)
/* 19778 8003E378 A0C0000A */  sb        $zero, 0xa($a2)
/* 1977C 8003E37C ACC00024 */  sw        $zero, 0x24($a2)
/* 19780 8003E380 A0C00008 */  sb        $zero, 8($a2)
/* 19784 8003E384 A0C00013 */  sb        $zero, 0x13($a2)
.L8003E388:
/* 19788 8003E388 0000202D */  daddu     $a0, $zero, $zero
/* 1978C 8003E38C 00E0182D */  daddu     $v1, $a3, $zero
.L8003E390:
/* 19790 8003E390 00C31021 */  addu      $v0, $a2, $v1
/* 19794 8003E394 AC4000B0 */  sw        $zero, 0xb0($v0)
/* 19798 8003E398 24840001 */  addiu     $a0, $a0, 1
/* 1979C 8003E39C 2882000C */  slti      $v0, $a0, 0xc
/* 197A0 8003E3A0 1440FFFB */  bnez      $v0, .L8003E390
/* 197A4 8003E3A4 24630004 */   addiu    $v1, $v1, 4
/* 197A8 8003E3A8 24A50001 */  addiu     $a1, $a1, 1
/* 197AC 8003E3AC 28A2003C */  slti      $v0, $a1, 0x3c
/* 197B0 8003E3B0 1440FFF5 */  bnez      $v0, .L8003E388
/* 197B4 8003E3B4 24E70030 */   addiu    $a3, $a3, 0x30
/* 197B8 8003E3B8 2403FFFF */  addiu     $v1, $zero, -1
/* 197BC 8003E3BC 24050001 */  addiu     $a1, $zero, 1
/* 197C0 8003E3C0 24C20002 */  addiu     $v0, $a2, 2
.L8003E3C4:
/* 197C4 8003E3C4 A4430BF0 */  sh        $v1, 0xbf0($v0)
/* 197C8 8003E3C8 24A5FFFF */  addiu     $a1, $a1, -1
/* 197CC 8003E3CC 04A1FFFD */  bgez      $a1, .L8003E3C4
/* 197D0 8003E3D0 2442FFFE */   addiu    $v0, $v0, -2
/* 197D4 8003E3D4 0C0116B0 */  jal       func_80045AC0
/* 197D8 8003E3D8 00000000 */   nop
/* 197DC 8003E3DC 3C058004 */  lui       $a1, %hi(npc_dyn_entity_draw_no_op)
/* 197E0 8003E3E0 24A5E670 */  addiu     $a1, $a1, %lo(npc_dyn_entity_draw_no_op)
/* 197E4 8003E3E4 3C01800A */  lui       $at, %hi(gGameState)
/* 197E8 8003E3E8 AC20A600 */  sw        $zero, %lo(gGameState)($at)
/* 197EC 8003E3EC 0C048C56 */  jal       bind_dynamic_entity_3
/* 197F0 8003E3F0 0000202D */   daddu    $a0, $zero, $zero
/* 197F4 8003E3F4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197F8 8003E3F8 03E00008 */  jr        $ra
/* 197FC 8003E3FC 27BD0018 */   addiu    $sp, $sp, 0x18
