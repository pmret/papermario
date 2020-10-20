.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242538
/* D223C8 80242538 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D223CC 8024253C AFB00010 */  sw        $s0, 0x10($sp)
/* D223D0 80242540 0080802D */  daddu     $s0, $a0, $zero
/* D223D4 80242544 10A0000A */  beqz      $a1, .L80242570
/* D223D8 80242548 AFBF0014 */   sw       $ra, 0x14($sp)
/* D223DC 8024254C 8E020084 */  lw        $v0, 0x84($s0)
/* D223E0 80242550 54400007 */  bnel      $v0, $zero, .L80242570
/* D223E4 80242554 AE000070 */   sw       $zero, 0x70($s0)
/* D223E8 80242558 960400C2 */  lhu       $a0, 0xc2($s0)
/* D223EC 8024255C 2405FFFF */  addiu     $a1, $zero, -1
/* D223F0 80242560 24060001 */  addiu     $a2, $zero, 1
/* D223F4 80242564 0C046E54 */  jal       func_8011B950
/* D223F8 80242568 00C0382D */   daddu    $a3, $a2, $zero
/* D223FC 8024256C AE000070 */  sw        $zero, 0x70($s0)
.L80242570:
/* D22400 80242570 8E020070 */  lw        $v0, 0x70($s0)
/* D22404 80242574 24420020 */  addiu     $v0, $v0, 0x20
/* D22408 80242578 AE020070 */  sw        $v0, 0x70($s0)
/* D2240C 8024257C 28420100 */  slti      $v0, $v0, 0x100
/* D22410 80242580 14400002 */  bnez      $v0, .L8024258C
/* D22414 80242584 240200FF */   addiu    $v0, $zero, 0xff
/* D22418 80242588 AE020070 */  sw        $v0, 0x70($s0)
.L8024258C:
/* D2241C 8024258C 8E020084 */  lw        $v0, 0x84($s0)
/* D22420 80242590 14400004 */  bnez      $v0, .L802425A4
/* D22424 80242594 240200FF */   addiu    $v0, $zero, 0xff
/* D22428 80242598 8E020070 */  lw        $v0, 0x70($s0)
/* D2242C 8024259C 0809096C */  j         .L802425B0
/* D22430 802425A0 0000202D */   daddu    $a0, $zero, $zero
.L802425A4:
/* D22434 802425A4 8E030070 */  lw        $v1, 0x70($s0)
/* D22438 802425A8 00431023 */  subu      $v0, $v0, $v1
/* D2243C 802425AC 0000202D */  daddu     $a0, $zero, $zero
.L802425B0:
/* D22440 802425B0 0080282D */  daddu     $a1, $a0, $zero
/* D22444 802425B4 0080302D */  daddu     $a2, $a0, $zero
/* D22448 802425B8 0C046F97 */  jal       set_background_color_blend
/* D2244C 802425BC 304700FF */   andi     $a3, $v0, 0xff
/* D22450 802425C0 3C02800B */  lui       $v0, %hi(gCameras)
/* D22454 802425C4 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* D22458 802425C8 A440002C */  sh        $zero, 0x2c($v0)
/* D2245C 802425CC A440002E */  sh        $zero, 0x2e($v0)
/* D22460 802425D0 A4400030 */  sh        $zero, 0x30($v0)
/* D22464 802425D4 8E020070 */  lw        $v0, 0x70($s0)
/* D22468 802425D8 284200FF */  slti      $v0, $v0, 0xff
/* D2246C 802425DC 1440000B */  bnez      $v0, .L8024260C
/* D22470 802425E0 0000102D */   daddu    $v0, $zero, $zero
/* D22474 802425E4 8E030084 */  lw        $v1, 0x84($s0)
/* D22478 802425E8 24020003 */  addiu     $v0, $zero, 3
/* D2247C 802425EC 14620007 */  bne       $v1, $v0, .L8024260C
/* D22480 802425F0 24020002 */   addiu    $v0, $zero, 2
/* D22484 802425F4 960400C2 */  lhu       $a0, 0xc2($s0)
/* D22488 802425F8 2405FFFF */  addiu     $a1, $zero, -1
/* D2248C 802425FC 0000302D */  daddu     $a2, $zero, $zero
/* D22490 80242600 0C046E54 */  jal       func_8011B950
/* D22494 80242604 24070001 */   addiu    $a3, $zero, 1
/* D22498 80242608 24020002 */  addiu     $v0, $zero, 2
.L8024260C:
/* D2249C 8024260C 8FBF0014 */  lw        $ra, 0x14($sp)
/* D224A0 80242610 8FB00010 */  lw        $s0, 0x10($sp)
/* D224A4 80242614 03E00008 */  jr        $ra
/* D224A8 80242618 27BD0018 */   addiu    $sp, $sp, 0x18
/* D224AC 8024261C 00000000 */  nop       
