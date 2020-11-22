.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B1C_B93F5C
/* B93F5C 80240B1C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B93F60 80240B20 AFB20038 */  sw        $s2, 0x38($sp)
/* B93F64 80240B24 0080902D */  daddu     $s2, $a0, $zero
/* B93F68 80240B28 AFBF0048 */  sw        $ra, 0x48($sp)
/* B93F6C 80240B2C AFB50044 */  sw        $s5, 0x44($sp)
/* B93F70 80240B30 AFB40040 */  sw        $s4, 0x40($sp)
/* B93F74 80240B34 AFB3003C */  sw        $s3, 0x3c($sp)
/* B93F78 80240B38 AFB10034 */  sw        $s1, 0x34($sp)
/* B93F7C 80240B3C AFB00030 */  sw        $s0, 0x30($sp)
/* B93F80 80240B40 8E510148 */  lw        $s1, 0x148($s2)
/* B93F84 80240B44 86240008 */  lh        $a0, 8($s1)
/* B93F88 80240B48 0C00EABB */  jal       get_npc_unsafe
/* B93F8C 80240B4C 00A0802D */   daddu    $s0, $a1, $zero
/* B93F90 80240B50 8E43000C */  lw        $v1, 0xc($s2)
/* B93F94 80240B54 0240202D */  daddu     $a0, $s2, $zero
/* B93F98 80240B58 8C650000 */  lw        $a1, ($v1)
/* B93F9C 80240B5C 0C0B1EAF */  jal       get_variable
/* B93FA0 80240B60 0040A82D */   daddu    $s5, $v0, $zero
/* B93FA4 80240B64 AFA00010 */  sw        $zero, 0x10($sp)
/* B93FA8 80240B68 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B93FAC 80240B6C 8C630030 */  lw        $v1, 0x30($v1)
/* B93FB0 80240B70 AFA30014 */  sw        $v1, 0x14($sp)
/* B93FB4 80240B74 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B93FB8 80240B78 8C63001C */  lw        $v1, 0x1c($v1)
/* B93FBC 80240B7C AFA30018 */  sw        $v1, 0x18($sp)
/* B93FC0 80240B80 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B93FC4 80240B84 8C630024 */  lw        $v1, 0x24($v1)
/* B93FC8 80240B88 AFA3001C */  sw        $v1, 0x1c($sp)
/* B93FCC 80240B8C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B93FD0 80240B90 8C630028 */  lw        $v1, 0x28($v1)
/* B93FD4 80240B94 27B40010 */  addiu     $s4, $sp, 0x10
/* B93FD8 80240B98 AFA30020 */  sw        $v1, 0x20($sp)
/* B93FDC 80240B9C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* B93FE0 80240BA0 3C014282 */  lui       $at, 0x4282
/* B93FE4 80240BA4 44810000 */  mtc1      $at, $f0
/* B93FE8 80240BA8 8C63002C */  lw        $v1, 0x2c($v1)
/* B93FEC 80240BAC 0040982D */  daddu     $s3, $v0, $zero
/* B93FF0 80240BB0 E7A00028 */  swc1      $f0, 0x28($sp)
/* B93FF4 80240BB4 A7A0002C */  sh        $zero, 0x2c($sp)
/* B93FF8 80240BB8 16000005 */  bnez      $s0, .L80240BD0
/* B93FFC 80240BBC AFA30024 */   sw       $v1, 0x24($sp)
/* B94000 80240BC0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B94004 80240BC4 30420004 */  andi      $v0, $v0, 4
/* B94008 80240BC8 10400020 */  beqz      $v0, .L80240C4C
/* B9400C 80240BCC 00000000 */   nop      
.L80240BD0:
/* B94010 80240BD0 2404F7FF */  addiu     $a0, $zero, -0x801
/* B94014 80240BD4 AE400070 */  sw        $zero, 0x70($s2)
/* B94018 80240BD8 A6A0008E */  sh        $zero, 0x8e($s5)
/* B9401C 80240BDC 8E2200CC */  lw        $v0, 0xcc($s1)
/* B94020 80240BE0 8EA30000 */  lw        $v1, ($s5)
/* B94024 80240BE4 8C420000 */  lw        $v0, ($v0)
/* B94028 80240BE8 00641824 */  and       $v1, $v1, $a0
/* B9402C 80240BEC AEA30000 */  sw        $v1, ($s5)
/* B94030 80240BF0 AEA20028 */  sw        $v0, 0x28($s5)
/* B94034 80240BF4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* B94038 80240BF8 8C420034 */  lw        $v0, 0x34($v0)
/* B9403C 80240BFC 54400005 */  bnel      $v0, $zero, .L80240C14
/* B94040 80240C00 2402FDFF */   addiu    $v0, $zero, -0x201
/* B94044 80240C04 34620200 */  ori       $v0, $v1, 0x200
/* B94048 80240C08 2403FFF7 */  addiu     $v1, $zero, -9
/* B9404C 80240C0C 08090307 */  j         .L80240C1C
/* B94050 80240C10 00431024 */   and      $v0, $v0, $v1
.L80240C14:
/* B94054 80240C14 00621024 */  and       $v0, $v1, $v0
/* B94058 80240C18 34420008 */  ori       $v0, $v0, 8
.L80240C1C:
/* B9405C 80240C1C AEA20000 */  sw        $v0, ($s5)
/* B94060 80240C20 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B94064 80240C24 30420004 */  andi      $v0, $v0, 4
/* B94068 80240C28 10400007 */  beqz      $v0, .L80240C48
/* B9406C 80240C2C 24020063 */   addiu    $v0, $zero, 0x63
/* B94070 80240C30 AE420070 */  sw        $v0, 0x70($s2)
/* B94074 80240C34 AE400074 */  sw        $zero, 0x74($s2)
/* B94078 80240C38 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B9407C 80240C3C 2403FFFB */  addiu     $v1, $zero, -5
/* B94080 80240C40 00431024 */  and       $v0, $v0, $v1
/* B94084 80240C44 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240C48:
/* B94088 80240C48 AE20006C */  sw        $zero, 0x6c($s1)
.L80240C4C:
/* B9408C 80240C4C 8E420070 */  lw        $v0, 0x70($s2)
/* B94090 80240C50 2842001E */  slti      $v0, $v0, 0x1e
/* B94094 80240C54 10400009 */  beqz      $v0, .L80240C7C
/* B94098 80240C58 00000000 */   nop      
/* B9409C 80240C5C 8E22006C */  lw        $v0, 0x6c($s1)
/* B940A0 80240C60 14400006 */  bnez      $v0, .L80240C7C
/* B940A4 80240C64 00000000 */   nop      
/* B940A8 80240C68 0C0901C2 */  jal       func_80240708_B93B48
/* B940AC 80240C6C 0240202D */   daddu    $a0, $s2, $zero
/* B940B0 80240C70 10400002 */  beqz      $v0, .L80240C7C
/* B940B4 80240C74 2402001E */   addiu    $v0, $zero, 0x1e
/* B940B8 80240C78 AE420070 */  sw        $v0, 0x70($s2)
.L80240C7C:
/* B940BC 80240C7C 8E430070 */  lw        $v1, 0x70($s2)
/* B940C0 80240C80 2C620064 */  sltiu     $v0, $v1, 0x64
/* B940C4 80240C84 10400048 */  beqz      $v0, .L80240DA8
/* B940C8 80240C88 00031080 */   sll      $v0, $v1, 2
/* B940CC 80240C8C 3C018024 */  lui       $at, 0x8024
/* B940D0 80240C90 00220821 */  addu      $at, $at, $v0
/* B940D4 80240C94 8C2245F8 */  lw        $v0, 0x45f8($at)
/* B940D8 80240C98 00400008 */  jr        $v0
/* B940DC 80240C9C 00000000 */   nop      
/* B940E0 80240CA0 0240202D */  daddu     $a0, $s2, $zero
/* B940E4 80240CA4 0260282D */  daddu     $a1, $s3, $zero
/* B940E8 80240CA8 0C012568 */  jal       func_800495A0
/* B940EC 80240CAC 0280302D */   daddu    $a2, $s4, $zero
/* B940F0 80240CB0 0240202D */  daddu     $a0, $s2, $zero
/* B940F4 80240CB4 0260282D */  daddu     $a1, $s3, $zero
/* B940F8 80240CB8 0C0125AE */  jal       func_800496B8
/* B940FC 80240CBC 0280302D */   daddu    $a2, $s4, $zero
/* B94100 80240CC0 0809036A */  j         .L80240DA8
/* B94104 80240CC4 00000000 */   nop      
/* B94108 80240CC8 0240202D */  daddu     $a0, $s2, $zero
/* B9410C 80240CCC 0260282D */  daddu     $a1, $s3, $zero
/* B94110 80240CD0 0C0126D1 */  jal       func_80049B44
/* B94114 80240CD4 0280302D */   daddu    $a2, $s4, $zero
/* B94118 80240CD8 0240202D */  daddu     $a0, $s2, $zero
/* B9411C 80240CDC 0260282D */  daddu     $a1, $s3, $zero
/* B94120 80240CE0 0C012701 */  jal       func_80049C04
/* B94124 80240CE4 0280302D */   daddu    $a2, $s4, $zero
/* B94128 80240CE8 0809036A */  j         .L80240DA8
/* B9412C 80240CEC 00000000 */   nop      
/* B94130 80240CF0 0240202D */  daddu     $a0, $s2, $zero
/* B94134 80240CF4 0260282D */  daddu     $a1, $s3, $zero
/* B94138 80240CF8 0C01278F */  jal       func_80049E3C
/* B9413C 80240CFC 0280302D */   daddu    $a2, $s4, $zero
/* B94140 80240D00 0240202D */  daddu     $a0, $s2, $zero
/* B94144 80240D04 0260282D */  daddu     $a1, $s3, $zero
/* B94148 80240D08 0C0127B3 */  jal       func_80049ECC
/* B9414C 80240D0C 0280302D */   daddu    $a2, $s4, $zero
/* B94150 80240D10 0809036A */  j         .L80240DA8
/* B94154 80240D14 00000000 */   nop      
/* B94158 80240D18 0240202D */  daddu     $a0, $s2, $zero
/* B9415C 80240D1C 0260282D */  daddu     $a1, $s3, $zero
/* B94160 80240D20 0C0127DF */  jal       func_80049F7C
/* B94164 80240D24 0280302D */   daddu    $a2, $s4, $zero
/* B94168 80240D28 0240202D */  daddu     $a0, $s2, $zero
/* B9416C 80240D2C 0260282D */  daddu     $a1, $s3, $zero
/* B94170 80240D30 0C012849 */  jal       func_8004A124
/* B94174 80240D34 0280302D */   daddu    $a2, $s4, $zero
/* B94178 80240D38 0809036A */  j         .L80240DA8
/* B9417C 80240D3C 00000000 */   nop      
/* B94180 80240D40 0240202D */  daddu     $a0, $s2, $zero
/* B94184 80240D44 0260282D */  daddu     $a1, $s3, $zero
/* B94188 80240D48 0C0128FA */  jal       func_8004A3E8
/* B9418C 80240D4C 0280302D */   daddu    $a2, $s4, $zero
/* B94190 80240D50 0809036A */  j         .L80240DA8
/* B94194 80240D54 00000000 */   nop      
/* B94198 80240D58 0C090140 */  jal       UnkNpcAIFunc6
/* B9419C 80240D5C 0240202D */   daddu    $a0, $s2, $zero
/* B941A0 80240D60 0C09015B */  jal       UnkNpcAIFunc7
/* B941A4 80240D64 0240202D */   daddu    $a0, $s2, $zero
/* B941A8 80240D68 8E430070 */  lw        $v1, 0x70($s2)
/* B941AC 80240D6C 24020020 */  addiu     $v0, $zero, 0x20
/* B941B0 80240D70 1462000D */  bne       $v1, $v0, .L80240DA8
/* B941B4 80240D74 00000000 */   nop      
/* B941B8 80240D78 0C090177 */  jal       func_802405DC_B93A1C
/* B941BC 80240D7C 0240202D */   daddu    $a0, $s2, $zero
/* B941C0 80240D80 8E430070 */  lw        $v1, 0x70($s2)
/* B941C4 80240D84 24020021 */  addiu     $v0, $zero, 0x21
/* B941C8 80240D88 14620007 */  bne       $v1, $v0, .L80240DA8
/* B941CC 80240D8C 00000000 */   nop      
/* B941D0 80240D90 0C0901AD */  jal       UnkNpcAIFunc5
/* B941D4 80240D94 0240202D */   daddu    $a0, $s2, $zero
/* B941D8 80240D98 0809036A */  j         .L80240DA8
/* B941DC 80240D9C 00000000 */   nop      
/* B941E0 80240DA0 0C0129CF */  jal       func_8004A73C
/* B941E4 80240DA4 0240202D */   daddu    $a0, $s2, $zero
.L80240DA8:
/* B941E8 80240DA8 8FBF0048 */  lw        $ra, 0x48($sp)
/* B941EC 80240DAC 8FB50044 */  lw        $s5, 0x44($sp)
/* B941F0 80240DB0 8FB40040 */  lw        $s4, 0x40($sp)
/* B941F4 80240DB4 8FB3003C */  lw        $s3, 0x3c($sp)
/* B941F8 80240DB8 8FB20038 */  lw        $s2, 0x38($sp)
/* B941FC 80240DBC 8FB10034 */  lw        $s1, 0x34($sp)
/* B94200 80240DC0 8FB00030 */  lw        $s0, 0x30($sp)
/* B94204 80240DC4 0000102D */  daddu     $v0, $zero, $zero
/* B94208 80240DC8 03E00008 */  jr        $ra
/* B9420C 80240DCC 27BD0050 */   addiu    $sp, $sp, 0x50
