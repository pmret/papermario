.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242124_C70454
/* C70454 80242124 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C70458 80242128 AFB40040 */  sw        $s4, 0x40($sp)
/* C7045C 8024212C 0080A02D */  daddu     $s4, $a0, $zero
/* C70460 80242130 AFBF0048 */  sw        $ra, 0x48($sp)
/* C70464 80242134 AFB50044 */  sw        $s5, 0x44($sp)
/* C70468 80242138 AFB3003C */  sw        $s3, 0x3c($sp)
/* C7046C 8024213C AFB20038 */  sw        $s2, 0x38($sp)
/* C70470 80242140 AFB10034 */  sw        $s1, 0x34($sp)
/* C70474 80242144 AFB00030 */  sw        $s0, 0x30($sp)
/* C70478 80242148 8E920148 */  lw        $s2, 0x148($s4)
/* C7047C 8024214C 86440008 */  lh        $a0, 8($s2)
/* C70480 80242150 8E90000C */  lw        $s0, 0xc($s4)
/* C70484 80242154 0C00EABB */  jal       get_npc_unsafe
/* C70488 80242158 00A0882D */   daddu    $s1, $a1, $zero
/* C7048C 8024215C 0280202D */  daddu     $a0, $s4, $zero
/* C70490 80242160 8E050000 */  lw        $a1, ($s0)
/* C70494 80242164 0C0B1EAF */  jal       get_variable
/* C70498 80242168 0040A82D */   daddu    $s5, $v0, $zero
/* C7049C 8024216C AFA00010 */  sw        $zero, 0x10($sp)
/* C704A0 80242170 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C704A4 80242174 8C630030 */  lw        $v1, 0x30($v1)
/* C704A8 80242178 AFA30014 */  sw        $v1, 0x14($sp)
/* C704AC 8024217C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C704B0 80242180 8C63001C */  lw        $v1, 0x1c($v1)
/* C704B4 80242184 AFA30018 */  sw        $v1, 0x18($sp)
/* C704B8 80242188 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C704BC 8024218C 8C630024 */  lw        $v1, 0x24($v1)
/* C704C0 80242190 AFA3001C */  sw        $v1, 0x1c($sp)
/* C704C4 80242194 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C704C8 80242198 8C630028 */  lw        $v1, 0x28($v1)
/* C704CC 8024219C 27B30010 */  addiu     $s3, $sp, 0x10
/* C704D0 802421A0 AFA30020 */  sw        $v1, 0x20($sp)
/* C704D4 802421A4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C704D8 802421A8 3C0142F0 */  lui       $at, 0x42f0
/* C704DC 802421AC 44810000 */  mtc1      $at, $f0
/* C704E0 802421B0 8C63002C */  lw        $v1, 0x2c($v1)
/* C704E4 802421B4 0040802D */  daddu     $s0, $v0, $zero
/* C704E8 802421B8 E7A00028 */  swc1      $f0, 0x28($sp)
/* C704EC 802421BC A7A0002C */  sh        $zero, 0x2c($sp)
/* C704F0 802421C0 12200007 */  beqz      $s1, .L802421E0
/* C704F4 802421C4 AFA30024 */   sw       $v1, 0x24($sp)
/* C704F8 802421C8 02A0202D */  daddu     $a0, $s5, $zero
/* C704FC 802421CC 0240282D */  daddu     $a1, $s2, $zero
/* C70500 802421D0 0280302D */  daddu     $a2, $s4, $zero
/* C70504 802421D4 0C090682 */  jal       func_80241A08_C6FD38
/* C70508 802421D8 0200382D */   daddu    $a3, $s0, $zero
/* C7050C 802421DC AE800070 */  sw        $zero, 0x70($s4)
.L802421E0:
/* C70510 802421E0 2402FFFE */  addiu     $v0, $zero, -2
/* C70514 802421E4 A2A200AB */  sb        $v0, 0xab($s5)
/* C70518 802421E8 8E4300B0 */  lw        $v1, 0xb0($s2)
/* C7051C 802421EC 30620004 */  andi      $v0, $v1, 4
/* C70520 802421F0 10400007 */  beqz      $v0, .L80242210
/* C70524 802421F4 00000000 */   nop      
/* C70528 802421F8 824200B4 */  lb        $v0, 0xb4($s2)
/* C7052C 802421FC 1440003A */  bnez      $v0, .L802422E8
/* C70530 80242200 0000102D */   daddu    $v0, $zero, $zero
/* C70534 80242204 2402FFFB */  addiu     $v0, $zero, -5
/* C70538 80242208 00621024 */  and       $v0, $v1, $v0
/* C7053C 8024220C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80242210:
/* C70540 80242210 8E830070 */  lw        $v1, 0x70($s4)
/* C70544 80242214 2C620015 */  sltiu     $v0, $v1, 0x15
/* C70548 80242218 10400032 */  beqz      $v0, .L802422E4
/* C7054C 8024221C 00031080 */   sll      $v0, $v1, 2
/* C70550 80242220 3C018024 */  lui       $at, 0x8024
/* C70554 80242224 00220821 */  addu      $at, $at, $v0
/* C70558 80242228 8C2230F0 */  lw        $v0, 0x30f0($at)
/* C7055C 8024222C 00400008 */  jr        $v0
/* C70560 80242230 00000000 */   nop      
/* C70564 80242234 0280202D */  daddu     $a0, $s4, $zero
/* C70568 80242238 0200282D */  daddu     $a1, $s0, $zero
/* C7056C 8024223C 0C090208 */  jal       func_80240820_C6EB50
/* C70570 80242240 0260302D */   daddu    $a2, $s3, $zero
/* C70574 80242244 0280202D */  daddu     $a0, $s4, $zero
/* C70578 80242248 0200282D */  daddu     $a1, $s0, $zero
/* C7057C 8024224C 0C090274 */  jal       func_802409D0_C6ED00
/* C70580 80242250 0260302D */   daddu    $a2, $s3, $zero
/* C70584 80242254 080908BA */  j         .L802422E8
/* C70588 80242258 0000102D */   daddu    $v0, $zero, $zero
/* C7058C 8024225C 0280202D */  daddu     $a0, $s4, $zero
/* C70590 80242260 0200282D */  daddu     $a1, $s0, $zero
/* C70594 80242264 0C0903FE */  jal       UnkNpcAIFunc1
/* C70598 80242268 0260302D */   daddu    $a2, $s3, $zero
/* C7059C 8024226C 0280202D */  daddu     $a0, $s4, $zero
/* C705A0 80242270 0200282D */  daddu     $a1, $s0, $zero
/* C705A4 80242274 0C09042E */  jal       func_802410B8_C6F3E8
/* C705A8 80242278 0260302D */   daddu    $a2, $s3, $zero
/* C705AC 8024227C 080908BA */  j         .L802422E8
/* C705B0 80242280 0000102D */   daddu    $v0, $zero, $zero
/* C705B4 80242284 0280202D */  daddu     $a0, $s4, $zero
/* C705B8 80242288 0200282D */  daddu     $a1, $s0, $zero
/* C705BC 8024228C 0C0904FF */  jal       UnkNpcAIFunc2
/* C705C0 80242290 0260302D */   daddu    $a2, $s3, $zero
/* C705C4 80242294 0280202D */  daddu     $a0, $s4, $zero
/* C705C8 80242298 0200282D */  daddu     $a1, $s0, $zero
/* C705CC 8024229C 0C09051D */  jal       func_80241474_C6F7A4
/* C705D0 802422A0 0260302D */   daddu    $a2, $s3, $zero
/* C705D4 802422A4 080908BA */  j         .L802422E8
/* C705D8 802422A8 0000102D */   daddu    $v0, $zero, $zero
/* C705DC 802422AC 0280202D */  daddu     $a0, $s4, $zero
/* C705E0 802422B0 0200282D */  daddu     $a1, $s0, $zero
/* C705E4 802422B4 0C090746 */  jal       func_80241D18_C70048
/* C705E8 802422B8 0260302D */   daddu    $a2, $s3, $zero
/* C705EC 802422BC 0280202D */  daddu     $a0, $s4, $zero
/* C705F0 802422C0 0200282D */  daddu     $a1, $s0, $zero
/* C705F4 802422C4 0C090792 */  jal       func_80241E48_C70178
/* C705F8 802422C8 0260302D */   daddu    $a2, $s3, $zero
/* C705FC 802422CC 080908BA */  j         .L802422E8
/* C70600 802422D0 0000102D */   daddu    $v0, $zero, $zero
/* C70604 802422D4 0280202D */  daddu     $a0, $s4, $zero
/* C70608 802422D8 0200282D */  daddu     $a1, $s0, $zero
/* C7060C 802422DC 0C090832 */  jal       func_802420C8_C703F8
/* C70610 802422E0 0260302D */   daddu    $a2, $s3, $zero
.L802422E4:
/* C70614 802422E4 0000102D */  daddu     $v0, $zero, $zero
.L802422E8:
/* C70618 802422E8 8FBF0048 */  lw        $ra, 0x48($sp)
/* C7061C 802422EC 8FB50044 */  lw        $s5, 0x44($sp)
/* C70620 802422F0 8FB40040 */  lw        $s4, 0x40($sp)
/* C70624 802422F4 8FB3003C */  lw        $s3, 0x3c($sp)
/* C70628 802422F8 8FB20038 */  lw        $s2, 0x38($sp)
/* C7062C 802422FC 8FB10034 */  lw        $s1, 0x34($sp)
/* C70630 80242300 8FB00030 */  lw        $s0, 0x30($sp)
/* C70634 80242304 03E00008 */  jr        $ra
/* C70638 80242308 27BD0050 */   addiu    $sp, $sp, 0x50
/* C7063C 8024230C 00000000 */  nop       
