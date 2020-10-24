.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024150C_CB024C
/* CB024C 8024150C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CB0250 80241510 AFB40040 */  sw        $s4, 0x40($sp)
/* CB0254 80241514 0080A02D */  daddu     $s4, $a0, $zero
/* CB0258 80241518 AFBF0048 */  sw        $ra, 0x48($sp)
/* CB025C 8024151C AFB50044 */  sw        $s5, 0x44($sp)
/* CB0260 80241520 AFB3003C */  sw        $s3, 0x3c($sp)
/* CB0264 80241524 AFB20038 */  sw        $s2, 0x38($sp)
/* CB0268 80241528 AFB10034 */  sw        $s1, 0x34($sp)
/* CB026C 8024152C AFB00030 */  sw        $s0, 0x30($sp)
/* CB0270 80241530 8E910148 */  lw        $s1, 0x148($s4)
/* CB0274 80241534 86240008 */  lh        $a0, 8($s1)
/* CB0278 80241538 0C00EABB */  jal       get_npc_unsafe
/* CB027C 8024153C 00A0802D */   daddu    $s0, $a1, $zero
/* CB0280 80241540 8E83000C */  lw        $v1, 0xc($s4)
/* CB0284 80241544 0280202D */  daddu     $a0, $s4, $zero
/* CB0288 80241548 8C650000 */  lw        $a1, ($v1)
/* CB028C 8024154C 0C0B1EAF */  jal       get_variable
/* CB0290 80241550 0040A82D */   daddu    $s5, $v0, $zero
/* CB0294 80241554 AFA00010 */  sw        $zero, 0x10($sp)
/* CB0298 80241558 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CB029C 8024155C 8C630030 */  lw        $v1, 0x30($v1)
/* CB02A0 80241560 AFA30014 */  sw        $v1, 0x14($sp)
/* CB02A4 80241564 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CB02A8 80241568 8C63001C */  lw        $v1, 0x1c($v1)
/* CB02AC 8024156C AFA30018 */  sw        $v1, 0x18($sp)
/* CB02B0 80241570 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CB02B4 80241574 8C630024 */  lw        $v1, 0x24($v1)
/* CB02B8 80241578 AFA3001C */  sw        $v1, 0x1c($sp)
/* CB02BC 8024157C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CB02C0 80241580 8C630028 */  lw        $v1, 0x28($v1)
/* CB02C4 80241584 27B30010 */  addiu     $s3, $sp, 0x10
/* CB02C8 80241588 AFA30020 */  sw        $v1, 0x20($sp)
/* CB02CC 8024158C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CB02D0 80241590 3C0142C8 */  lui       $at, 0x42c8
/* CB02D4 80241594 44810000 */  mtc1      $at, $f0
/* CB02D8 80241598 8C63002C */  lw        $v1, 0x2c($v1)
/* CB02DC 8024159C 0040902D */  daddu     $s2, $v0, $zero
/* CB02E0 802415A0 E7A00028 */  swc1      $f0, 0x28($sp)
/* CB02E4 802415A4 A7A0002C */  sh        $zero, 0x2c($sp)
/* CB02E8 802415A8 16000005 */  bnez      $s0, .L802415C0
/* CB02EC 802415AC AFA30024 */   sw       $v1, 0x24($sp)
/* CB02F0 802415B0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* CB02F4 802415B4 30420004 */  andi      $v0, $v0, 4
/* CB02F8 802415B8 1040001F */  beqz      $v0, .L80241638
/* CB02FC 802415BC 00000000 */   nop      
.L802415C0:
/* CB0300 802415C0 2404F7FF */  addiu     $a0, $zero, -0x801
/* CB0304 802415C4 AE800070 */  sw        $zero, 0x70($s4)
/* CB0308 802415C8 A6A0008E */  sh        $zero, 0x8e($s5)
/* CB030C 802415CC 8E2200CC */  lw        $v0, 0xcc($s1)
/* CB0310 802415D0 8EA30000 */  lw        $v1, ($s5)
/* CB0314 802415D4 8C420000 */  lw        $v0, ($v0)
/* CB0318 802415D8 00641824 */  and       $v1, $v1, $a0
/* CB031C 802415DC AEA30000 */  sw        $v1, ($s5)
/* CB0320 802415E0 AEA20028 */  sw        $v0, 0x28($s5)
/* CB0324 802415E4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CB0328 802415E8 8C420034 */  lw        $v0, 0x34($v0)
/* CB032C 802415EC 54400005 */  bnel      $v0, $zero, .L80241604
/* CB0330 802415F0 2402FDFF */   addiu    $v0, $zero, -0x201
/* CB0334 802415F4 34620200 */  ori       $v0, $v1, 0x200
/* CB0338 802415F8 2403FFF7 */  addiu     $v1, $zero, -9
/* CB033C 802415FC 08090583 */  j         .L8024160C
/* CB0340 80241600 00431024 */   and      $v0, $v0, $v1
.L80241604:
/* CB0344 80241604 00621024 */  and       $v0, $v1, $v0
/* CB0348 80241608 34420008 */  ori       $v0, $v0, 8
.L8024160C:
/* CB034C 8024160C AEA20000 */  sw        $v0, ($s5)
/* CB0350 80241610 8E2200B0 */  lw        $v0, 0xb0($s1)
/* CB0354 80241614 30420004 */  andi      $v0, $v0, 4
/* CB0358 80241618 10400007 */  beqz      $v0, .L80241638
/* CB035C 8024161C 24020063 */   addiu    $v0, $zero, 0x63
/* CB0360 80241620 AE820070 */  sw        $v0, 0x70($s4)
/* CB0364 80241624 AE800074 */  sw        $zero, 0x74($s4)
/* CB0368 80241628 8E2200B0 */  lw        $v0, 0xb0($s1)
/* CB036C 8024162C 2403FFFB */  addiu     $v1, $zero, -5
/* CB0370 80241630 00431024 */  and       $v0, $v0, $v1
/* CB0374 80241634 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80241638:
/* CB0378 80241638 8E830070 */  lw        $v1, 0x70($s4)
/* CB037C 8024163C 2C620064 */  sltiu     $v0, $v1, 0x64
/* CB0380 80241640 10400036 */  beqz      $v0, .L8024171C
/* CB0384 80241644 00031080 */   sll      $v0, $v1, 2
/* CB0388 80241648 3C018024 */  lui       $at, 0x8024
/* CB038C 8024164C 00220821 */  addu      $at, $at, $v0
/* CB0390 80241650 8C226130 */  lw        $v0, 0x6130($at)
/* CB0394 80241654 00400008 */  jr        $v0
/* CB0398 80241658 00000000 */   nop      
/* CB039C 8024165C 0280202D */  daddu     $a0, $s4, $zero
/* CB03A0 80241660 0240282D */  daddu     $a1, $s2, $zero
/* CB03A4 80241664 0C012568 */  jal       func_800495A0
/* CB03A8 80241668 0260302D */   daddu    $a2, $s3, $zero
/* CB03AC 8024166C 0280202D */  daddu     $a0, $s4, $zero
/* CB03B0 80241670 0240282D */  daddu     $a1, $s2, $zero
/* CB03B4 80241674 0C0125AE */  jal       func_800496B8
/* CB03B8 80241678 0260302D */   daddu    $a2, $s3, $zero
/* CB03BC 8024167C 080905C7 */  j         .L8024171C
/* CB03C0 80241680 00000000 */   nop      
/* CB03C4 80241684 0280202D */  daddu     $a0, $s4, $zero
/* CB03C8 80241688 0240282D */  daddu     $a1, $s2, $zero
/* CB03CC 8024168C 0C0126D1 */  jal       func_80049B44
/* CB03D0 80241690 0260302D */   daddu    $a2, $s3, $zero
/* CB03D4 80241694 0280202D */  daddu     $a0, $s4, $zero
/* CB03D8 80241698 0240282D */  daddu     $a1, $s2, $zero
/* CB03DC 8024169C 0C012701 */  jal       func_80049C04
/* CB03E0 802416A0 0260302D */   daddu    $a2, $s3, $zero
/* CB03E4 802416A4 080905C7 */  j         .L8024171C
/* CB03E8 802416A8 00000000 */   nop      
/* CB03EC 802416AC 0280202D */  daddu     $a0, $s4, $zero
/* CB03F0 802416B0 0240282D */  daddu     $a1, $s2, $zero
/* CB03F4 802416B4 0C01278F */  jal       func_80049E3C
/* CB03F8 802416B8 0260302D */   daddu    $a2, $s3, $zero
/* CB03FC 802416BC 0280202D */  daddu     $a0, $s4, $zero
/* CB0400 802416C0 0240282D */  daddu     $a1, $s2, $zero
/* CB0404 802416C4 0C0127B3 */  jal       func_80049ECC
/* CB0408 802416C8 0260302D */   daddu    $a2, $s3, $zero
/* CB040C 802416CC 080905C7 */  j         .L8024171C
/* CB0410 802416D0 00000000 */   nop      
/* CB0414 802416D4 0280202D */  daddu     $a0, $s4, $zero
/* CB0418 802416D8 0240282D */  daddu     $a1, $s2, $zero
/* CB041C 802416DC 0C090360 */  jal       func_80240D80_CAFAC0
/* CB0420 802416E0 0260302D */   daddu    $a2, $s3, $zero
/* CB0424 802416E4 0280202D */  daddu     $a0, $s4, $zero
/* CB0428 802416E8 0240282D */  daddu     $a1, $s2, $zero
/* CB042C 802416EC 0C0904D9 */  jal       func_80241364_CB00A4
/* CB0430 802416F0 0260302D */   daddu    $a2, $s3, $zero
/* CB0434 802416F4 080905C7 */  j         .L8024171C
/* CB0438 802416F8 00000000 */   nop      
/* CB043C 802416FC 0280202D */  daddu     $a0, $s4, $zero
/* CB0440 80241700 0240282D */  daddu     $a1, $s2, $zero
/* CB0444 80241704 0C090532 */  jal       func_802414C8_CB0208
/* CB0448 80241708 0260302D */   daddu    $a2, $s3, $zero
/* CB044C 8024170C 080905C7 */  j         .L8024171C
/* CB0450 80241710 00000000 */   nop      
/* CB0454 80241714 0C0129CF */  jal       func_8004A73C
/* CB0458 80241718 0280202D */   daddu    $a0, $s4, $zero
.L8024171C:
/* CB045C 8024171C 8FBF0048 */  lw        $ra, 0x48($sp)
/* CB0460 80241720 8FB50044 */  lw        $s5, 0x44($sp)
/* CB0464 80241724 8FB40040 */  lw        $s4, 0x40($sp)
/* CB0468 80241728 8FB3003C */  lw        $s3, 0x3c($sp)
/* CB046C 8024172C 8FB20038 */  lw        $s2, 0x38($sp)
/* CB0470 80241730 8FB10034 */  lw        $s1, 0x34($sp)
/* CB0474 80241734 8FB00030 */  lw        $s0, 0x30($sp)
/* CB0478 80241738 0000102D */  daddu     $v0, $zero, $zero
/* CB047C 8024173C 03E00008 */  jr        $ra
/* CB0480 80241740 27BD0050 */   addiu    $sp, $sp, 0x50
