.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AE4_B5A354
/* B5A354 80240AE4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B5A358 80240AE8 AFB20038 */  sw        $s2, 0x38($sp)
/* B5A35C 80240AEC 0080902D */  daddu     $s2, $a0, $zero
/* B5A360 80240AF0 AFBF0048 */  sw        $ra, 0x48($sp)
/* B5A364 80240AF4 AFB50044 */  sw        $s5, 0x44($sp)
/* B5A368 80240AF8 AFB40040 */  sw        $s4, 0x40($sp)
/* B5A36C 80240AFC AFB3003C */  sw        $s3, 0x3c($sp)
/* B5A370 80240B00 AFB10034 */  sw        $s1, 0x34($sp)
/* B5A374 80240B04 AFB00030 */  sw        $s0, 0x30($sp)
/* B5A378 80240B08 8E510148 */  lw        $s1, 0x148($s2)
/* B5A37C 80240B0C 86240008 */  lh        $a0, 8($s1)
/* B5A380 80240B10 0C00EABB */  jal       get_npc_unsafe
/* B5A384 80240B14 00A0802D */   daddu    $s0, $a1, $zero
/* B5A388 80240B18 8E43000C */  lw        $v1, 0xc($s2)
/* B5A38C 80240B1C 0240202D */  daddu     $a0, $s2, $zero
/* B5A390 80240B20 8C650000 */  lw        $a1, ($v1)
/* B5A394 80240B24 0C0B1EAF */  jal       get_variable
/* B5A398 80240B28 0040A82D */   daddu    $s5, $v0, $zero
/* B5A39C 80240B2C AFA00010 */  sw        $zero, 0x10($sp)
/* B5A3A0 80240B30 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B5A3A4 80240B34 8C630030 */  lw        $v1, 0x30($v1)
/* B5A3A8 80240B38 AFA30014 */  sw        $v1, 0x14($sp)
/* B5A3AC 80240B3C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B5A3B0 80240B40 8C63001C */  lw        $v1, 0x1c($v1)
/* B5A3B4 80240B44 AFA30018 */  sw        $v1, 0x18($sp)
/* B5A3B8 80240B48 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B5A3BC 80240B4C 8C630024 */  lw        $v1, 0x24($v1)
/* B5A3C0 80240B50 AFA3001C */  sw        $v1, 0x1c($sp)
/* B5A3C4 80240B54 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B5A3C8 80240B58 8C630028 */  lw        $v1, 0x28($v1)
/* B5A3CC 80240B5C 27B40010 */  addiu     $s4, $sp, 0x10
/* B5A3D0 80240B60 AFA30020 */  sw        $v1, 0x20($sp)
/* B5A3D4 80240B64 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B5A3D8 80240B68 3C014282 */  lui       $at, 0x4282
/* B5A3DC 80240B6C 44810000 */  mtc1      $at, $f0
/* B5A3E0 80240B70 8C63002C */  lw        $v1, 0x2c($v1)
/* B5A3E4 80240B74 0040982D */  daddu     $s3, $v0, $zero
/* B5A3E8 80240B78 E7A00028 */  swc1      $f0, 0x28($sp)
/* B5A3EC 80240B7C A7A0002C */  sh        $zero, 0x2c($sp)
/* B5A3F0 80240B80 16000005 */  bnez      $s0, .L80240B98
/* B5A3F4 80240B84 AFA30024 */   sw       $v1, 0x24($sp)
/* B5A3F8 80240B88 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B5A3FC 80240B8C 30420004 */  andi      $v0, $v0, 4
/* B5A400 80240B90 10400020 */  beqz      $v0, .L80240C14
/* B5A404 80240B94 00000000 */   nop      
.L80240B98:
/* B5A408 80240B98 2404F7FF */  addiu     $a0, $zero, -0x801
/* B5A40C 80240B9C AE400070 */  sw        $zero, 0x70($s2)
/* B5A410 80240BA0 A6A0008E */  sh        $zero, 0x8e($s5)
/* B5A414 80240BA4 8E2200CC */  lw        $v0, 0xcc($s1)
/* B5A418 80240BA8 8EA30000 */  lw        $v1, ($s5)
/* B5A41C 80240BAC 8C420000 */  lw        $v0, ($v0)
/* B5A420 80240BB0 00641824 */  and       $v1, $v1, $a0
/* B5A424 80240BB4 AEA30000 */  sw        $v1, ($s5)
/* B5A428 80240BB8 AEA20028 */  sw        $v0, 0x28($s5)
/* B5A42C 80240BBC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* B5A430 80240BC0 8C420034 */  lw        $v0, 0x34($v0)
/* B5A434 80240BC4 54400005 */  bnel      $v0, $zero, .L80240BDC
/* B5A438 80240BC8 2402FDFF */   addiu    $v0, $zero, -0x201
/* B5A43C 80240BCC 34620200 */  ori       $v0, $v1, 0x200
/* B5A440 80240BD0 2403FFF7 */  addiu     $v1, $zero, -9
/* B5A444 80240BD4 080902F9 */  j         .L80240BE4
/* B5A448 80240BD8 00431024 */   and      $v0, $v0, $v1
.L80240BDC:
/* B5A44C 80240BDC 00621024 */  and       $v0, $v1, $v0
/* B5A450 80240BE0 34420008 */  ori       $v0, $v0, 8
.L80240BE4:
/* B5A454 80240BE4 AEA20000 */  sw        $v0, ($s5)
/* B5A458 80240BE8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B5A45C 80240BEC 30420004 */  andi      $v0, $v0, 4
/* B5A460 80240BF0 10400007 */  beqz      $v0, .L80240C10
/* B5A464 80240BF4 24020063 */   addiu    $v0, $zero, 0x63
/* B5A468 80240BF8 AE420070 */  sw        $v0, 0x70($s2)
/* B5A46C 80240BFC AE400074 */  sw        $zero, 0x74($s2)
/* B5A470 80240C00 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B5A474 80240C04 2403FFFB */  addiu     $v1, $zero, -5
/* B5A478 80240C08 00431024 */  and       $v0, $v0, $v1
/* B5A47C 80240C0C AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240C10:
/* B5A480 80240C10 AE20006C */  sw        $zero, 0x6c($s1)
.L80240C14:
/* B5A484 80240C14 8E420070 */  lw        $v0, 0x70($s2)
/* B5A488 80240C18 2842001E */  slti      $v0, $v0, 0x1e
/* B5A48C 80240C1C 10400009 */  beqz      $v0, .L80240C44
/* B5A490 80240C20 00000000 */   nop      
/* B5A494 80240C24 8E22006C */  lw        $v0, 0x6c($s1)
/* B5A498 80240C28 14400006 */  bnez      $v0, .L80240C44
/* B5A49C 80240C2C 00000000 */   nop      
/* B5A4A0 80240C30 0C090107 */  jal       func_8024041C_B59C8C
/* B5A4A4 80240C34 0240202D */   daddu    $a0, $s2, $zero
/* B5A4A8 80240C38 10400002 */  beqz      $v0, .L80240C44
/* B5A4AC 80240C3C 2402001E */   addiu    $v0, $zero, 0x1e
/* B5A4B0 80240C40 AE420070 */  sw        $v0, 0x70($s2)
.L80240C44:
/* B5A4B4 80240C44 8E430070 */  lw        $v1, 0x70($s2)
/* B5A4B8 80240C48 2C620064 */  sltiu     $v0, $v1, 0x64
/* B5A4BC 80240C4C 10400048 */  beqz      $v0, .L80240D70
/* B5A4C0 80240C50 00031080 */   sll      $v0, $v1, 2
/* B5A4C4 80240C54 3C018024 */  lui       $at, 0x8024
/* B5A4C8 80240C58 00220821 */  addu      $at, $at, $v0
/* B5A4CC 80240C5C 8C2248B0 */  lw        $v0, 0x48b0($at)
/* B5A4D0 80240C60 00400008 */  jr        $v0
/* B5A4D4 80240C64 00000000 */   nop      
/* B5A4D8 80240C68 0240202D */  daddu     $a0, $s2, $zero
/* B5A4DC 80240C6C 0260282D */  daddu     $a1, $s3, $zero
/* B5A4E0 80240C70 0C012568 */  jal       func_800495A0
/* B5A4E4 80240C74 0280302D */   daddu    $a2, $s4, $zero
/* B5A4E8 80240C78 0240202D */  daddu     $a0, $s2, $zero
/* B5A4EC 80240C7C 0260282D */  daddu     $a1, $s3, $zero
/* B5A4F0 80240C80 0C0125AE */  jal       func_800496B8
/* B5A4F4 80240C84 0280302D */   daddu    $a2, $s4, $zero
/* B5A4F8 80240C88 0809035C */  j         .L80240D70
/* B5A4FC 80240C8C 00000000 */   nop      
/* B5A500 80240C90 0240202D */  daddu     $a0, $s2, $zero
/* B5A504 80240C94 0260282D */  daddu     $a1, $s3, $zero
/* B5A508 80240C98 0C090000 */  jal       UnkNpcAIFunc4
/* B5A50C 80240C9C 0280302D */   daddu    $a2, $s4, $zero
/* B5A510 80240CA0 0240202D */  daddu     $a0, $s2, $zero
/* B5A514 80240CA4 0260282D */  daddu     $a1, $s3, $zero
/* B5A518 80240CA8 0C090014 */  jal       func_80240050_B598C0
/* B5A51C 80240CAC 0280302D */   daddu    $a2, $s4, $zero
/* B5A520 80240CB0 0809035C */  j         .L80240D70
/* B5A524 80240CB4 00000000 */   nop      
/* B5A528 80240CB8 0240202D */  daddu     $a0, $s2, $zero
/* B5A52C 80240CBC 0260282D */  daddu     $a1, $s3, $zero
/* B5A530 80240CC0 0C01278F */  jal       func_80049E3C
/* B5A534 80240CC4 0280302D */   daddu    $a2, $s4, $zero
/* B5A538 80240CC8 0240202D */  daddu     $a0, $s2, $zero
/* B5A53C 80240CCC 0260282D */  daddu     $a1, $s3, $zero
/* B5A540 80240CD0 0C0127B3 */  jal       func_80049ECC
/* B5A544 80240CD4 0280302D */   daddu    $a2, $s4, $zero
/* B5A548 80240CD8 0809035C */  j         .L80240D70
/* B5A54C 80240CDC 00000000 */   nop      
/* B5A550 80240CE0 0240202D */  daddu     $a0, $s2, $zero
/* B5A554 80240CE4 0260282D */  daddu     $a1, $s3, $zero
/* B5A558 80240CE8 0C0127DF */  jal       func_80049F7C
/* B5A55C 80240CEC 0280302D */   daddu    $a2, $s4, $zero
/* B5A560 80240CF0 0240202D */  daddu     $a0, $s2, $zero
/* B5A564 80240CF4 0260282D */  daddu     $a1, $s3, $zero
/* B5A568 80240CF8 0C012849 */  jal       func_8004A124
/* B5A56C 80240CFC 0280302D */   daddu    $a2, $s4, $zero
/* B5A570 80240D00 0809035C */  j         .L80240D70
/* B5A574 80240D04 00000000 */   nop      
/* B5A578 80240D08 0240202D */  daddu     $a0, $s2, $zero
/* B5A57C 80240D0C 0260282D */  daddu     $a1, $s3, $zero
/* B5A580 80240D10 0C0128FA */  jal       func_8004A3E8
/* B5A584 80240D14 0280302D */   daddu    $a2, $s4, $zero
/* B5A588 80240D18 0809035C */  j         .L80240D70
/* B5A58C 80240D1C 00000000 */   nop      
/* B5A590 80240D20 0C090085 */  jal       func_80240214_B59A84
/* B5A594 80240D24 0240202D */   daddu    $a0, $s2, $zero
/* B5A598 80240D28 0C0900A0 */  jal       func_80240280_B59AF0
/* B5A59C 80240D2C 0240202D */   daddu    $a0, $s2, $zero
/* B5A5A0 80240D30 8E430070 */  lw        $v1, 0x70($s2)
/* B5A5A4 80240D34 24020020 */  addiu     $v0, $zero, 0x20
/* B5A5A8 80240D38 1462000D */  bne       $v1, $v0, .L80240D70
/* B5A5AC 80240D3C 00000000 */   nop      
/* B5A5B0 80240D40 0C0900BC */  jal       func_802402F0_B59B60
/* B5A5B4 80240D44 0240202D */   daddu    $a0, $s2, $zero
/* B5A5B8 80240D48 8E430070 */  lw        $v1, 0x70($s2)
/* B5A5BC 80240D4C 24020021 */  addiu     $v0, $zero, 0x21
/* B5A5C0 80240D50 14620007 */  bne       $v1, $v0, .L80240D70
/* B5A5C4 80240D54 00000000 */   nop      
/* B5A5C8 80240D58 0C0900F2 */  jal       func_802403C8_B59C38
/* B5A5CC 80240D5C 0240202D */   daddu    $a0, $s2, $zero
/* B5A5D0 80240D60 0809035C */  j         .L80240D70
/* B5A5D4 80240D64 00000000 */   nop      
/* B5A5D8 80240D68 0C0129CF */  jal       func_8004A73C
/* B5A5DC 80240D6C 0240202D */   daddu    $a0, $s2, $zero
.L80240D70:
/* B5A5E0 80240D70 8FBF0048 */  lw        $ra, 0x48($sp)
/* B5A5E4 80240D74 8FB50044 */  lw        $s5, 0x44($sp)
/* B5A5E8 80240D78 8FB40040 */  lw        $s4, 0x40($sp)
/* B5A5EC 80240D7C 8FB3003C */  lw        $s3, 0x3c($sp)
/* B5A5F0 80240D80 8FB20038 */  lw        $s2, 0x38($sp)
/* B5A5F4 80240D84 8FB10034 */  lw        $s1, 0x34($sp)
/* B5A5F8 80240D88 8FB00030 */  lw        $s0, 0x30($sp)
/* B5A5FC 80240D8C 0000102D */  daddu     $v0, $zero, $zero
/* B5A600 80240D90 03E00008 */  jr        $ra
/* B5A604 80240D94 27BD0050 */   addiu    $sp, $sp, 0x50
/* B5A608 80240D98 00000000 */  nop       
/* B5A60C 80240D9C 00000000 */  nop       
