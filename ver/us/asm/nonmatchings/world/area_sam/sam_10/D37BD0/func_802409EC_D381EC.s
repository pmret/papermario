.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409EC_D381EC
/* D381EC 802409EC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D381F0 802409F0 AFB20038 */  sw        $s2, 0x38($sp)
/* D381F4 802409F4 0080902D */  daddu     $s2, $a0, $zero
/* D381F8 802409F8 AFBF0048 */  sw        $ra, 0x48($sp)
/* D381FC 802409FC AFB50044 */  sw        $s5, 0x44($sp)
/* D38200 80240A00 AFB40040 */  sw        $s4, 0x40($sp)
/* D38204 80240A04 AFB3003C */  sw        $s3, 0x3c($sp)
/* D38208 80240A08 AFB10034 */  sw        $s1, 0x34($sp)
/* D3820C 80240A0C AFB00030 */  sw        $s0, 0x30($sp)
/* D38210 80240A10 8E510148 */  lw        $s1, 0x148($s2)
/* D38214 80240A14 86240008 */  lh        $a0, 8($s1)
/* D38218 80240A18 0C00EABB */  jal       get_npc_unsafe
/* D3821C 80240A1C 00A0802D */   daddu    $s0, $a1, $zero
/* D38220 80240A20 8E43000C */  lw        $v1, 0xc($s2)
/* D38224 80240A24 0240202D */  daddu     $a0, $s2, $zero
/* D38228 80240A28 8C650000 */  lw        $a1, ($v1)
/* D3822C 80240A2C 0C0B1EAF */  jal       get_variable
/* D38230 80240A30 0040A82D */   daddu    $s5, $v0, $zero
/* D38234 80240A34 AFA00010 */  sw        $zero, 0x10($sp)
/* D38238 80240A38 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D3823C 80240A3C 8C630030 */  lw        $v1, 0x30($v1)
/* D38240 80240A40 AFA30014 */  sw        $v1, 0x14($sp)
/* D38244 80240A44 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D38248 80240A48 8C63001C */  lw        $v1, 0x1c($v1)
/* D3824C 80240A4C AFA30018 */  sw        $v1, 0x18($sp)
/* D38250 80240A50 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D38254 80240A54 8C630024 */  lw        $v1, 0x24($v1)
/* D38258 80240A58 AFA3001C */  sw        $v1, 0x1c($sp)
/* D3825C 80240A5C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D38260 80240A60 8C630028 */  lw        $v1, 0x28($v1)
/* D38264 80240A64 27B40010 */  addiu     $s4, $sp, 0x10
/* D38268 80240A68 AFA30020 */  sw        $v1, 0x20($sp)
/* D3826C 80240A6C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* D38270 80240A70 3C014282 */  lui       $at, 0x4282
/* D38274 80240A74 44810000 */  mtc1      $at, $f0
/* D38278 80240A78 8C63002C */  lw        $v1, 0x2c($v1)
/* D3827C 80240A7C 0040982D */  daddu     $s3, $v0, $zero
/* D38280 80240A80 E7A00028 */  swc1      $f0, 0x28($sp)
/* D38284 80240A84 A7A0002C */  sh        $zero, 0x2c($sp)
/* D38288 80240A88 16000005 */  bnez      $s0, .L80240AA0
/* D3828C 80240A8C AFA30024 */   sw       $v1, 0x24($sp)
/* D38290 80240A90 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D38294 80240A94 30420004 */  andi      $v0, $v0, 4
/* D38298 80240A98 10400020 */  beqz      $v0, .L80240B1C
/* D3829C 80240A9C 00000000 */   nop
.L80240AA0:
/* D382A0 80240AA0 2404F7FF */  addiu     $a0, $zero, -0x801
/* D382A4 80240AA4 AE400070 */  sw        $zero, 0x70($s2)
/* D382A8 80240AA8 A6A0008E */  sh        $zero, 0x8e($s5)
/* D382AC 80240AAC 8E2200CC */  lw        $v0, 0xcc($s1)
/* D382B0 80240AB0 8EA30000 */  lw        $v1, ($s5)
/* D382B4 80240AB4 8C420000 */  lw        $v0, ($v0)
/* D382B8 80240AB8 00641824 */  and       $v1, $v1, $a0
/* D382BC 80240ABC AEA30000 */  sw        $v1, ($s5)
/* D382C0 80240AC0 AEA20028 */  sw        $v0, 0x28($s5)
/* D382C4 80240AC4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* D382C8 80240AC8 8C420034 */  lw        $v0, 0x34($v0)
/* D382CC 80240ACC 54400005 */  bnel      $v0, $zero, .L80240AE4
/* D382D0 80240AD0 2402FDFF */   addiu    $v0, $zero, -0x201
/* D382D4 80240AD4 34620200 */  ori       $v0, $v1, 0x200
/* D382D8 80240AD8 2403FFF7 */  addiu     $v1, $zero, -9
/* D382DC 80240ADC 080902BB */  j         .L80240AEC
/* D382E0 80240AE0 00431024 */   and      $v0, $v0, $v1
.L80240AE4:
/* D382E4 80240AE4 00621024 */  and       $v0, $v1, $v0
/* D382E8 80240AE8 34420008 */  ori       $v0, $v0, 8
.L80240AEC:
/* D382EC 80240AEC AEA20000 */  sw        $v0, ($s5)
/* D382F0 80240AF0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D382F4 80240AF4 30420004 */  andi      $v0, $v0, 4
/* D382F8 80240AF8 10400007 */  beqz      $v0, .L80240B18
/* D382FC 80240AFC 24020063 */   addiu    $v0, $zero, 0x63
/* D38300 80240B00 AE420070 */  sw        $v0, 0x70($s2)
/* D38304 80240B04 AE400074 */  sw        $zero, 0x74($s2)
/* D38308 80240B08 8E2200B0 */  lw        $v0, 0xb0($s1)
/* D3830C 80240B0C 2403FFFB */  addiu     $v1, $zero, -5
/* D38310 80240B10 00431024 */  and       $v0, $v0, $v1
/* D38314 80240B14 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240B18:
/* D38318 80240B18 AE20006C */  sw        $zero, 0x6c($s1)
.L80240B1C:
/* D3831C 80240B1C 8E420070 */  lw        $v0, 0x70($s2)
/* D38320 80240B20 2842001E */  slti      $v0, $v0, 0x1e
/* D38324 80240B24 10400009 */  beqz      $v0, .L80240B4C
/* D38328 80240B28 00000000 */   nop
/* D3832C 80240B2C 8E22006C */  lw        $v0, 0x6c($s1)
/* D38330 80240B30 14400006 */  bnez      $v0, .L80240B4C
/* D38334 80240B34 00000000 */   nop
/* D38338 80240B38 0C090176 */  jal       func_802405D8_D37DD8
/* D3833C 80240B3C 0240202D */   daddu    $a0, $s2, $zero
/* D38340 80240B40 10400002 */  beqz      $v0, .L80240B4C
/* D38344 80240B44 2402001E */   addiu    $v0, $zero, 0x1e
/* D38348 80240B48 AE420070 */  sw        $v0, 0x70($s2)
.L80240B4C:
/* D3834C 80240B4C 8E430070 */  lw        $v1, 0x70($s2)
/* D38350 80240B50 2C620064 */  sltiu     $v0, $v1, 0x64
/* D38354 80240B54 10400048 */  beqz      $v0, .L80240C78
/* D38358 80240B58 00031080 */   sll      $v0, $v1, 2
/* D3835C 80240B5C 3C018024 */  lui       $at, %hi(jtbl_80242C38_D3A438)
/* D38360 80240B60 00220821 */  addu      $at, $at, $v0
/* D38364 80240B64 8C222C38 */  lw        $v0, %lo(jtbl_80242C38_D3A438)($at)
/* D38368 80240B68 00400008 */  jr        $v0
/* D3836C 80240B6C 00000000 */   nop
glabel L80240B70_D38370
/* D38370 80240B70 0240202D */  daddu     $a0, $s2, $zero
/* D38374 80240B74 0260282D */  daddu     $a1, $s3, $zero
/* D38378 80240B78 0C012568 */  jal       func_800495A0
/* D3837C 80240B7C 0280302D */   daddu    $a2, $s4, $zero
glabel L80240B80_D38380
/* D38380 80240B80 0240202D */  daddu     $a0, $s2, $zero
/* D38384 80240B84 0260282D */  daddu     $a1, $s3, $zero
/* D38388 80240B88 0C0125AE */  jal       func_800496B8
/* D3838C 80240B8C 0280302D */   daddu    $a2, $s4, $zero
/* D38390 80240B90 0809031E */  j         .L80240C78
/* D38394 80240B94 00000000 */   nop
glabel L80240B98_D38398
/* D38398 80240B98 0240202D */  daddu     $a0, $s2, $zero
/* D3839C 80240B9C 0260282D */  daddu     $a1, $s3, $zero
/* D383A0 80240BA0 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* D383A4 80240BA4 0280302D */   daddu    $a2, $s4, $zero
glabel L80240BA8_D383A8
/* D383A8 80240BA8 0240202D */  daddu     $a0, $s2, $zero
/* D383AC 80240BAC 0260282D */  daddu     $a1, $s3, $zero
/* D383B0 80240BB0 0C012701 */  jal       func_80049C04
/* D383B4 80240BB4 0280302D */   daddu    $a2, $s4, $zero
/* D383B8 80240BB8 0809031E */  j         .L80240C78
/* D383BC 80240BBC 00000000 */   nop
glabel L80240BC0_D383C0
/* D383C0 80240BC0 0240202D */  daddu     $a0, $s2, $zero
/* D383C4 80240BC4 0260282D */  daddu     $a1, $s3, $zero
/* D383C8 80240BC8 0C01278F */  jal       func_80049E3C
/* D383CC 80240BCC 0280302D */   daddu    $a2, $s4, $zero
glabel L80240BD0_D383D0
/* D383D0 80240BD0 0240202D */  daddu     $a0, $s2, $zero
/* D383D4 80240BD4 0260282D */  daddu     $a1, $s3, $zero
/* D383D8 80240BD8 0C0127B3 */  jal       func_80049ECC
/* D383DC 80240BDC 0280302D */   daddu    $a2, $s4, $zero
/* D383E0 80240BE0 0809031E */  j         .L80240C78
/* D383E4 80240BE4 00000000 */   nop
glabel L80240BE8_D383E8
/* D383E8 80240BE8 0240202D */  daddu     $a0, $s2, $zero
/* D383EC 80240BEC 0260282D */  daddu     $a1, $s3, $zero
/* D383F0 80240BF0 0C0127DF */  jal       func_80049F7C
/* D383F4 80240BF4 0280302D */   daddu    $a2, $s4, $zero
glabel L80240BF8_D383F8
/* D383F8 80240BF8 0240202D */  daddu     $a0, $s2, $zero
/* D383FC 80240BFC 0260282D */  daddu     $a1, $s3, $zero
/* D38400 80240C00 0C012849 */  jal       func_8004A124
/* D38404 80240C04 0280302D */   daddu    $a2, $s4, $zero
/* D38408 80240C08 0809031E */  j         .L80240C78
/* D3840C 80240C0C 00000000 */   nop
glabel L80240C10_D38410
/* D38410 80240C10 0240202D */  daddu     $a0, $s2, $zero
/* D38414 80240C14 0260282D */  daddu     $a1, $s3, $zero
/* D38418 80240C18 0C0128FA */  jal       func_8004A3E8
/* D3841C 80240C1C 0280302D */   daddu    $a2, $s4, $zero
/* D38420 80240C20 0809031E */  j         .L80240C78
/* D38424 80240C24 00000000 */   nop
glabel L80240C28_D38428
/* D38428 80240C28 0C0900F4 */  jal       sam_10_UnkNpcAIFunc6
/* D3842C 80240C2C 0240202D */   daddu    $a0, $s2, $zero
glabel L80240C30_D38430
/* D38430 80240C30 0C09010F */  jal       sam_10_UnkNpcAIFunc7
/* D38434 80240C34 0240202D */   daddu    $a0, $s2, $zero
/* D38438 80240C38 8E430070 */  lw        $v1, 0x70($s2)
/* D3843C 80240C3C 24020020 */  addiu     $v0, $zero, 0x20
/* D38440 80240C40 1462000D */  bne       $v1, $v0, .L80240C78
/* D38444 80240C44 00000000 */   nop
glabel L80240C48_D38448
/* D38448 80240C48 0C09012B */  jal       sam_10_UnkNpcAIFunc8
/* D3844C 80240C4C 0240202D */   daddu    $a0, $s2, $zero
/* D38450 80240C50 8E430070 */  lw        $v1, 0x70($s2)
/* D38454 80240C54 24020021 */  addiu     $v0, $zero, 0x21
/* D38458 80240C58 14620007 */  bne       $v1, $v0, .L80240C78
/* D3845C 80240C5C 00000000 */   nop
glabel L80240C60_D38460
/* D38460 80240C60 0C090161 */  jal       sam_10_UnkNpcAIFunc5
/* D38464 80240C64 0240202D */   daddu    $a0, $s2, $zero
/* D38468 80240C68 0809031E */  j         .L80240C78
/* D3846C 80240C6C 00000000 */   nop
glabel L80240C70_D38470
/* D38470 80240C70 0C0129CF */  jal       func_8004A73C
/* D38474 80240C74 0240202D */   daddu    $a0, $s2, $zero
.L80240C78:
glabel L80240C78_D38478
/* D38478 80240C78 8FBF0048 */  lw        $ra, 0x48($sp)
/* D3847C 80240C7C 8FB50044 */  lw        $s5, 0x44($sp)
/* D38480 80240C80 8FB40040 */  lw        $s4, 0x40($sp)
/* D38484 80240C84 8FB3003C */  lw        $s3, 0x3c($sp)
/* D38488 80240C88 8FB20038 */  lw        $s2, 0x38($sp)
/* D3848C 80240C8C 8FB10034 */  lw        $s1, 0x34($sp)
/* D38490 80240C90 8FB00030 */  lw        $s0, 0x30($sp)
/* D38494 80240C94 0000102D */  daddu     $v0, $zero, $zero
/* D38498 80240C98 03E00008 */  jr        $ra
/* D3849C 80240C9C 27BD0050 */   addiu    $sp, $sp, 0x50
