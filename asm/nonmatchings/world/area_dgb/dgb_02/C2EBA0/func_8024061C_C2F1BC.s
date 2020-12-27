.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024061C_C2F1BC
/* C2F1BC 8024061C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C2F1C0 80240620 AFB20038 */  sw        $s2, 0x38($sp)
/* C2F1C4 80240624 0080902D */  daddu     $s2, $a0, $zero
/* C2F1C8 80240628 AFBF0048 */  sw        $ra, 0x48($sp)
/* C2F1CC 8024062C AFB50044 */  sw        $s5, 0x44($sp)
/* C2F1D0 80240630 AFB40040 */  sw        $s4, 0x40($sp)
/* C2F1D4 80240634 AFB3003C */  sw        $s3, 0x3c($sp)
/* C2F1D8 80240638 AFB10034 */  sw        $s1, 0x34($sp)
/* C2F1DC 8024063C AFB00030 */  sw        $s0, 0x30($sp)
/* C2F1E0 80240640 8E510148 */  lw        $s1, 0x148($s2)
/* C2F1E4 80240644 86240008 */  lh        $a0, 8($s1)
/* C2F1E8 80240648 0C00EABB */  jal       get_npc_unsafe
/* C2F1EC 8024064C 00A0802D */   daddu    $s0, $a1, $zero
/* C2F1F0 80240650 8E43000C */  lw        $v1, 0xc($s2)
/* C2F1F4 80240654 0240202D */  daddu     $a0, $s2, $zero
/* C2F1F8 80240658 8C650000 */  lw        $a1, ($v1)
/* C2F1FC 8024065C 0C0B1EAF */  jal       get_variable
/* C2F200 80240660 0040A82D */   daddu    $s5, $v0, $zero
/* C2F204 80240664 AFA00010 */  sw        $zero, 0x10($sp)
/* C2F208 80240668 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C2F20C 8024066C 8C630030 */  lw        $v1, 0x30($v1)
/* C2F210 80240670 AFA30014 */  sw        $v1, 0x14($sp)
/* C2F214 80240674 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C2F218 80240678 8C63001C */  lw        $v1, 0x1c($v1)
/* C2F21C 8024067C AFA30018 */  sw        $v1, 0x18($sp)
/* C2F220 80240680 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C2F224 80240684 8C630024 */  lw        $v1, 0x24($v1)
/* C2F228 80240688 AFA3001C */  sw        $v1, 0x1c($sp)
/* C2F22C 8024068C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C2F230 80240690 8C630028 */  lw        $v1, 0x28($v1)
/* C2F234 80240694 27B40010 */  addiu     $s4, $sp, 0x10
/* C2F238 80240698 AFA30020 */  sw        $v1, 0x20($sp)
/* C2F23C 8024069C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C2F240 802406A0 3C014282 */  lui       $at, 0x4282
/* C2F244 802406A4 44810000 */  mtc1      $at, $f0
/* C2F248 802406A8 8C63002C */  lw        $v1, 0x2c($v1)
/* C2F24C 802406AC 0040982D */  daddu     $s3, $v0, $zero
/* C2F250 802406B0 E7A00028 */  swc1      $f0, 0x28($sp)
/* C2F254 802406B4 A7A0002C */  sh        $zero, 0x2c($sp)
/* C2F258 802406B8 16000005 */  bnez      $s0, .L802406D0
/* C2F25C 802406BC AFA30024 */   sw       $v1, 0x24($sp)
/* C2F260 802406C0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C2F264 802406C4 30420004 */  andi      $v0, $v0, 4
/* C2F268 802406C8 10400020 */  beqz      $v0, .L8024074C
/* C2F26C 802406CC 00000000 */   nop
.L802406D0:
/* C2F270 802406D0 2404F7FF */  addiu     $a0, $zero, -0x801
/* C2F274 802406D4 AE400070 */  sw        $zero, 0x70($s2)
/* C2F278 802406D8 A6A0008E */  sh        $zero, 0x8e($s5)
/* C2F27C 802406DC 8E2200CC */  lw        $v0, 0xcc($s1)
/* C2F280 802406E0 8EA30000 */  lw        $v1, ($s5)
/* C2F284 802406E4 8C420000 */  lw        $v0, ($v0)
/* C2F288 802406E8 00641824 */  and       $v1, $v1, $a0
/* C2F28C 802406EC AEA30000 */  sw        $v1, ($s5)
/* C2F290 802406F0 AEA20028 */  sw        $v0, 0x28($s5)
/* C2F294 802406F4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C2F298 802406F8 8C420034 */  lw        $v0, 0x34($v0)
/* C2F29C 802406FC 54400005 */  bnel      $v0, $zero, .L80240714
/* C2F2A0 80240700 2402FDFF */   addiu    $v0, $zero, -0x201
/* C2F2A4 80240704 34620200 */  ori       $v0, $v1, 0x200
/* C2F2A8 80240708 2403FFF7 */  addiu     $v1, $zero, -9
/* C2F2AC 8024070C 080901C7 */  j         .L8024071C
/* C2F2B0 80240710 00431024 */   and      $v0, $v0, $v1
.L80240714:
/* C2F2B4 80240714 00621024 */  and       $v0, $v1, $v0
/* C2F2B8 80240718 34420008 */  ori       $v0, $v0, 8
.L8024071C:
/* C2F2BC 8024071C AEA20000 */  sw        $v0, ($s5)
/* C2F2C0 80240720 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C2F2C4 80240724 30420004 */  andi      $v0, $v0, 4
/* C2F2C8 80240728 10400007 */  beqz      $v0, .L80240748
/* C2F2CC 8024072C 24020063 */   addiu    $v0, $zero, 0x63
/* C2F2D0 80240730 AE420070 */  sw        $v0, 0x70($s2)
/* C2F2D4 80240734 AE400074 */  sw        $zero, 0x74($s2)
/* C2F2D8 80240738 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C2F2DC 8024073C 2403FFFB */  addiu     $v1, $zero, -5
/* C2F2E0 80240740 00431024 */  and       $v0, $v0, $v1
/* C2F2E4 80240744 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240748:
/* C2F2E8 80240748 AE20006C */  sw        $zero, 0x6c($s1)
.L8024074C:
/* C2F2EC 8024074C 8E420070 */  lw        $v0, 0x70($s2)
/* C2F2F0 80240750 2842001E */  slti      $v0, $v0, 0x1e
/* C2F2F4 80240754 10400009 */  beqz      $v0, .L8024077C
/* C2F2F8 80240758 00000000 */   nop
/* C2F2FC 8024075C 8E22006C */  lw        $v0, 0x6c($s1)
/* C2F300 80240760 14400006 */  bnez      $v0, .L8024077C
/* C2F304 80240764 00000000 */   nop
/* C2F308 80240768 0C090082 */  jal       func_80240208_C2EDA8
/* C2F30C 8024076C 0240202D */   daddu    $a0, $s2, $zero
/* C2F310 80240770 10400002 */  beqz      $v0, .L8024077C
/* C2F314 80240774 2402001E */   addiu    $v0, $zero, 0x1e
/* C2F318 80240778 AE420070 */  sw        $v0, 0x70($s2)
.L8024077C:
/* C2F31C 8024077C 8E430070 */  lw        $v1, 0x70($s2)
/* C2F320 80240780 2C620064 */  sltiu     $v0, $v1, 0x64
/* C2F324 80240784 10400048 */  beqz      $v0, .L802408A8
/* C2F328 80240788 00031080 */   sll      $v0, $v1, 2
/* C2F32C 8024078C 3C018024 */  lui       $at, %hi(D_80242618)
/* C2F330 80240790 00220821 */  addu      $at, $at, $v0
/* C2F334 80240794 8C222618 */  lw        $v0, %lo(D_80242618)($at)
/* C2F338 80240798 00400008 */  jr        $v0
/* C2F33C 8024079C 00000000 */   nop
/* C2F340 802407A0 0240202D */  daddu     $a0, $s2, $zero
/* C2F344 802407A4 0260282D */  daddu     $a1, $s3, $zero
/* C2F348 802407A8 0C012568 */  jal       func_800495A0
/* C2F34C 802407AC 0280302D */   daddu    $a2, $s4, $zero
/* C2F350 802407B0 0240202D */  daddu     $a0, $s2, $zero
/* C2F354 802407B4 0260282D */  daddu     $a1, $s3, $zero
/* C2F358 802407B8 0C0125AE */  jal       func_800496B8
/* C2F35C 802407BC 0280302D */   daddu    $a2, $s4, $zero
/* C2F360 802407C0 0809022A */  j         .L802408A8
/* C2F364 802407C4 00000000 */   nop
/* C2F368 802407C8 0240202D */  daddu     $a0, $s2, $zero
/* C2F36C 802407CC 0260282D */  daddu     $a1, $s3, $zero
/* C2F370 802407D0 0C0126D1 */  jal       func_80049B44
/* C2F374 802407D4 0280302D */   daddu    $a2, $s4, $zero
/* C2F378 802407D8 0240202D */  daddu     $a0, $s2, $zero
/* C2F37C 802407DC 0260282D */  daddu     $a1, $s3, $zero
/* C2F380 802407E0 0C012701 */  jal       func_80049C04
/* C2F384 802407E4 0280302D */   daddu    $a2, $s4, $zero
/* C2F388 802407E8 0809022A */  j         .L802408A8
/* C2F38C 802407EC 00000000 */   nop
/* C2F390 802407F0 0240202D */  daddu     $a0, $s2, $zero
/* C2F394 802407F4 0260282D */  daddu     $a1, $s3, $zero
/* C2F398 802407F8 0C01278F */  jal       func_80049E3C
/* C2F39C 802407FC 0280302D */   daddu    $a2, $s4, $zero
/* C2F3A0 80240800 0240202D */  daddu     $a0, $s2, $zero
/* C2F3A4 80240804 0260282D */  daddu     $a1, $s3, $zero
/* C2F3A8 80240808 0C0127B3 */  jal       func_80049ECC
/* C2F3AC 8024080C 0280302D */   daddu    $a2, $s4, $zero
/* C2F3B0 80240810 0809022A */  j         .L802408A8
/* C2F3B4 80240814 00000000 */   nop
/* C2F3B8 80240818 0240202D */  daddu     $a0, $s2, $zero
/* C2F3BC 8024081C 0260282D */  daddu     $a1, $s3, $zero
/* C2F3C0 80240820 0C0127DF */  jal       func_80049F7C
/* C2F3C4 80240824 0280302D */   daddu    $a2, $s4, $zero
/* C2F3C8 80240828 0240202D */  daddu     $a0, $s2, $zero
/* C2F3CC 8024082C 0260282D */  daddu     $a1, $s3, $zero
/* C2F3D0 80240830 0C012849 */  jal       func_8004A124
/* C2F3D4 80240834 0280302D */   daddu    $a2, $s4, $zero
/* C2F3D8 80240838 0809022A */  j         .L802408A8
/* C2F3DC 8024083C 00000000 */   nop
/* C2F3E0 80240840 0240202D */  daddu     $a0, $s2, $zero
/* C2F3E4 80240844 0260282D */  daddu     $a1, $s3, $zero
/* C2F3E8 80240848 0C0128FA */  jal       func_8004A3E8
/* C2F3EC 8024084C 0280302D */   daddu    $a2, $s4, $zero
/* C2F3F0 80240850 0809022A */  j         .L802408A8
/* C2F3F4 80240854 00000000 */   nop
/* C2F3F8 80240858 0C090000 */  jal       UnkNpcAIFunc6
/* C2F3FC 8024085C 0240202D */   daddu    $a0, $s2, $zero
/* C2F400 80240860 0C09001B */  jal       UnkNpcAIFunc7
/* C2F404 80240864 0240202D */   daddu    $a0, $s2, $zero
/* C2F408 80240868 8E430070 */  lw        $v1, 0x70($s2)
/* C2F40C 8024086C 24020020 */  addiu     $v0, $zero, 0x20
/* C2F410 80240870 1462000D */  bne       $v1, $v0, .L802408A8
/* C2F414 80240874 00000000 */   nop
/* C2F418 80240878 0C090037 */  jal       dgb_02_UnkNpcAIFunc8
/* C2F41C 8024087C 0240202D */   daddu    $a0, $s2, $zero
/* C2F420 80240880 8E430070 */  lw        $v1, 0x70($s2)
/* C2F424 80240884 24020021 */  addiu     $v0, $zero, 0x21
/* C2F428 80240888 14620007 */  bne       $v1, $v0, .L802408A8
/* C2F42C 8024088C 00000000 */   nop
/* C2F430 80240890 0C09006D */  jal       UnkNpcAIFunc5
/* C2F434 80240894 0240202D */   daddu    $a0, $s2, $zero
/* C2F438 80240898 0809022A */  j         .L802408A8
/* C2F43C 8024089C 00000000 */   nop
/* C2F440 802408A0 0C0129CF */  jal       func_8004A73C
/* C2F444 802408A4 0240202D */   daddu    $a0, $s2, $zero
.L802408A8:
/* C2F448 802408A8 8FBF0048 */  lw        $ra, 0x48($sp)
/* C2F44C 802408AC 8FB50044 */  lw        $s5, 0x44($sp)
/* C2F450 802408B0 8FB40040 */  lw        $s4, 0x40($sp)
/* C2F454 802408B4 8FB3003C */  lw        $s3, 0x3c($sp)
/* C2F458 802408B8 8FB20038 */  lw        $s2, 0x38($sp)
/* C2F45C 802408BC 8FB10034 */  lw        $s1, 0x34($sp)
/* C2F460 802408C0 8FB00030 */  lw        $s0, 0x30($sp)
/* C2F464 802408C4 0000102D */  daddu     $v0, $zero, $zero
/* C2F468 802408C8 03E00008 */  jr        $ra
/* C2F46C 802408CC 27BD0050 */   addiu    $sp, $sp, 0x50
