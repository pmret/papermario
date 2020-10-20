.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A5C_CC426C
/* CC426C 80240A5C 27BDFF88 */  addiu     $sp, $sp, -0x78
/* CC4270 80240A60 AFB3004C */  sw        $s3, 0x4c($sp)
/* CC4274 80240A64 0080982D */  daddu     $s3, $a0, $zero
/* CC4278 80240A68 AFBF0054 */  sw        $ra, 0x54($sp)
/* CC427C 80240A6C AFB40050 */  sw        $s4, 0x50($sp)
/* CC4280 80240A70 AFB20048 */  sw        $s2, 0x48($sp)
/* CC4284 80240A74 AFB10044 */  sw        $s1, 0x44($sp)
/* CC4288 80240A78 AFB00040 */  sw        $s0, 0x40($sp)
/* CC428C 80240A7C F7BA0070 */  sdc1      $f26, 0x70($sp)
/* CC4290 80240A80 F7B80068 */  sdc1      $f24, 0x68($sp)
/* CC4294 80240A84 F7B60060 */  sdc1      $f22, 0x60($sp)
/* CC4298 80240A88 F7B40058 */  sdc1      $f20, 0x58($sp)
/* CC429C 80240A8C 8E710148 */  lw        $s1, 0x148($s3)
/* CC42A0 80240A90 00A0902D */  daddu     $s2, $a1, $zero
/* CC42A4 80240A94 86240008 */  lh        $a0, 8($s1)
/* CC42A8 80240A98 0C00EABB */  jal       get_npc_unsafe
/* CC42AC 80240A9C 00C0A02D */   daddu    $s4, $a2, $zero
/* CC42B0 80240AA0 0040802D */  daddu     $s0, $v0, $zero
/* CC42B4 80240AA4 C6200078 */  lwc1      $f0, 0x78($s1)
/* CC42B8 80240AA8 46800020 */  cvt.s.w   $f0, $f0
/* CC42BC 80240AAC 46000021 */  cvt.d.s   $f0, $f0
/* CC42C0 80240AB0 3C014059 */  lui       $at, 0x4059
/* CC42C4 80240AB4 44811800 */  mtc1      $at, $f3
/* CC42C8 80240AB8 44801000 */  mtc1      $zero, $f2
/* CC42CC 80240ABC 8602008E */  lh        $v0, 0x8e($s0)
/* CC42D0 80240AC0 9603008E */  lhu       $v1, 0x8e($s0)
/* CC42D4 80240AC4 46220003 */  div.d     $f0, $f0, $f2
/* CC42D8 80240AC8 46200620 */  cvt.s.d   $f24, $f0
/* CC42DC 80240ACC C6200088 */  lwc1      $f0, 0x88($s1)
/* CC42E0 80240AD0 46800020 */  cvt.s.w   $f0, $f0
/* CC42E4 80240AD4 46000021 */  cvt.d.s   $f0, $f0
/* CC42E8 80240AD8 46220003 */  div.d     $f0, $f0, $f2
/* CC42EC 80240ADC 46200020 */  cvt.s.d   $f0, $f0
/* CC42F0 80240AE0 18400003 */  blez      $v0, .L80240AF0
/* CC42F4 80240AE4 4600C680 */   add.s    $f26, $f24, $f0
/* CC42F8 80240AE8 2462FFFF */  addiu     $v0, $v1, -1
/* CC42FC 80240AEC A602008E */  sh        $v0, 0x8e($s0)
.L80240AF0:
/* CC4300 80240AF0 8E220070 */  lw        $v0, 0x70($s1)
/* CC4304 80240AF4 18400034 */  blez      $v0, .L80240BC8
/* CC4308 80240AF8 00000000 */   nop      
/* CC430C 80240AFC C62C0074 */  lwc1      $f12, 0x74($s1)
/* CC4310 80240B00 46806320 */  cvt.s.w   $f12, $f12
/* CC4314 80240B04 44820000 */  mtc1      $v0, $f0
/* CC4318 80240B08 00000000 */  nop       
/* CC431C 80240B0C 46800020 */  cvt.s.w   $f0, $f0
/* CC4320 80240B10 46000021 */  cvt.d.s   $f0, $f0
/* CC4324 80240B14 46220003 */  div.d     $f0, $f0, $f2
/* CC4328 80240B18 0C00A8BB */  jal       sin_deg
/* CC432C 80240B1C 462005A0 */   cvt.s.d  $f22, $f0
/* CC4330 80240B20 8E020000 */  lw        $v0, ($s0)
/* CC4334 80240B24 30420008 */  andi      $v0, $v0, 8
/* CC4338 80240B28 10400003 */  beqz      $v0, .L80240B38
/* CC433C 80240B2C 46000506 */   mov.s    $f20, $f0
/* CC4340 80240B30 080902DE */  j         .L80240B78
/* CC4344 80240B34 0000102D */   daddu    $v0, $zero, $zero
.L80240B38:
/* CC4348 80240B38 27A50028 */  addiu     $a1, $sp, 0x28
/* CC434C 80240B3C 27A6002C */  addiu     $a2, $sp, 0x2c
/* CC4350 80240B40 C6000038 */  lwc1      $f0, 0x38($s0)
/* CC4354 80240B44 C602003C */  lwc1      $f2, 0x3c($s0)
/* CC4358 80240B48 C6040040 */  lwc1      $f4, 0x40($s0)
/* CC435C 80240B4C 3C01447A */  lui       $at, 0x447a
/* CC4360 80240B50 44813000 */  mtc1      $at, $f6
/* CC4364 80240B54 27A20034 */  addiu     $v0, $sp, 0x34
/* CC4368 80240B58 E7A00028 */  swc1      $f0, 0x28($sp)
/* CC436C 80240B5C E7A2002C */  swc1      $f2, 0x2c($sp)
/* CC4370 80240B60 E7A40030 */  swc1      $f4, 0x30($sp)
/* CC4374 80240B64 E7A60034 */  swc1      $f6, 0x34($sp)
/* CC4378 80240B68 AFA20010 */  sw        $v0, 0x10($sp)
/* CC437C 80240B6C 8E040080 */  lw        $a0, 0x80($s0)
/* CC4380 80240B70 0C0372DF */  jal       func_800DCB7C
/* CC4384 80240B74 27A70030 */   addiu    $a3, $sp, 0x30
.L80240B78:
/* CC4388 80240B78 10400007 */  beqz      $v0, .L80240B98
/* CC438C 80240B7C 00000000 */   nop      
/* CC4390 80240B80 4616A082 */  mul.s     $f2, $f20, $f22
/* CC4394 80240B84 00000000 */  nop       
/* CC4398 80240B88 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* CC439C 80240B8C 46180000 */  add.s     $f0, $f0, $f24
/* CC43A0 80240B90 080902E9 */  j         .L80240BA4
/* CC43A4 80240B94 46020000 */   add.s    $f0, $f0, $f2
.L80240B98:
/* CC43A8 80240B98 4616A002 */  mul.s     $f0, $f20, $f22
/* CC43AC 80240B9C 00000000 */  nop       
/* CC43B0 80240BA0 4600D000 */  add.s     $f0, $f26, $f0
.L80240BA4:
/* CC43B4 80240BA4 E600003C */  swc1      $f0, 0x3c($s0)
/* CC43B8 80240BA8 8E220074 */  lw        $v0, 0x74($s1)
/* CC43BC 80240BAC 2442000A */  addiu     $v0, $v0, 0xa
/* CC43C0 80240BB0 44826000 */  mtc1      $v0, $f12
/* CC43C4 80240BB4 00000000 */  nop       
/* CC43C8 80240BB8 0C00A6C9 */  jal       clamp_angle
/* CC43CC 80240BBC 46806320 */   cvt.s.w  $f12, $f12
/* CC43D0 80240BC0 4600020D */  trunc.w.s $f8, $f0
/* CC43D4 80240BC4 E6280074 */  swc1      $f8, 0x74($s1)
.L80240BC8:
/* CC43D8 80240BC8 8E220090 */  lw        $v0, 0x90($s1)
/* CC43DC 80240BCC 1C400040 */  bgtz      $v0, .L80240CD0
/* CC43E0 80240BD0 2442FFFF */   addiu    $v0, $v0, -1
/* CC43E4 80240BD4 860200A8 */  lh        $v0, 0xa8($s0)
/* CC43E8 80240BD8 C600003C */  lwc1      $f0, 0x3c($s0)
/* CC43EC 80240BDC 44821000 */  mtc1      $v0, $f2
/* CC43F0 80240BE0 00000000 */  nop       
/* CC43F4 80240BE4 468010A0 */  cvt.s.w   $f2, $f2
/* CC43F8 80240BE8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CC43FC 80240BEC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CC4400 80240BF0 46020000 */  add.s     $f0, $f0, $f2
/* CC4404 80240BF4 3C014024 */  lui       $at, 0x4024
/* CC4408 80240BF8 44812800 */  mtc1      $at, $f5
/* CC440C 80240BFC 44802000 */  mtc1      $zero, $f4
/* CC4410 80240C00 C442002C */  lwc1      $f2, 0x2c($v0)
/* CC4414 80240C04 46000021 */  cvt.d.s   $f0, $f0
/* CC4418 80240C08 46240000 */  add.d     $f0, $f0, $f4
/* CC441C 80240C0C 460010A1 */  cvt.d.s   $f2, $f2
/* CC4420 80240C10 4620103C */  c.lt.d    $f2, $f0
/* CC4424 80240C14 00000000 */  nop       
/* CC4428 80240C18 4500002E */  bc1f      .L80240CD4
/* CC442C 80240C1C 0280202D */   daddu    $a0, $s4, $zero
/* CC4430 80240C20 24020001 */  addiu     $v0, $zero, 1
/* CC4434 80240C24 AFA20010 */  sw        $v0, 0x10($sp)
/* CC4438 80240C28 8E460024 */  lw        $a2, 0x24($s2)
/* CC443C 80240C2C 8E470028 */  lw        $a3, 0x28($s2)
/* CC4440 80240C30 0C01242D */  jal       func_800490B4
/* CC4444 80240C34 0220282D */   daddu    $a1, $s1, $zero
/* CC4448 80240C38 10400026 */  beqz      $v0, .L80240CD4
/* CC444C 80240C3C 0000202D */   daddu    $a0, $zero, $zero
/* CC4450 80240C40 0200282D */  daddu     $a1, $s0, $zero
/* CC4454 80240C44 0000302D */  daddu     $a2, $zero, $zero
/* CC4458 80240C48 2412000C */  addiu     $s2, $zero, 0xc
/* CC445C 80240C4C 860300A8 */  lh        $v1, 0xa8($s0)
/* CC4460 80240C50 3C013F80 */  lui       $at, 0x3f80
/* CC4464 80240C54 44810000 */  mtc1      $at, $f0
/* CC4468 80240C58 3C014000 */  lui       $at, 0x4000
/* CC446C 80240C5C 44811000 */  mtc1      $at, $f2
/* CC4470 80240C60 3C01C1A0 */  lui       $at, 0xc1a0
/* CC4474 80240C64 44812000 */  mtc1      $at, $f4
/* CC4478 80240C68 44834000 */  mtc1      $v1, $f8
/* CC447C 80240C6C 00000000 */  nop       
/* CC4480 80240C70 46804220 */  cvt.s.w   $f8, $f8
/* CC4484 80240C74 44074000 */  mfc1      $a3, $f8
/* CC4488 80240C78 27A20038 */  addiu     $v0, $sp, 0x38
/* CC448C 80240C7C AFB2001C */  sw        $s2, 0x1c($sp)
/* CC4490 80240C80 AFA20020 */  sw        $v0, 0x20($sp)
/* CC4494 80240C84 E7A00010 */  swc1      $f0, 0x10($sp)
/* CC4498 80240C88 E7A20014 */  swc1      $f2, 0x14($sp)
/* CC449C 80240C8C 0C01BFA4 */  jal       fx_emote
/* CC44A0 80240C90 E7A40018 */   swc1     $f4, 0x18($sp)
/* CC44A4 80240C94 0200202D */  daddu     $a0, $s0, $zero
/* CC44A8 80240C98 240502F4 */  addiu     $a1, $zero, 0x2f4
/* CC44AC 80240C9C C480003C */  lwc1      $f0, 0x3c($a0)
/* CC44B0 80240CA0 3C060020 */  lui       $a2, 0x20
/* CC44B4 80240CA4 0C012530 */  jal       func_800494C0
/* CC44B8 80240CA8 E4800064 */   swc1     $f0, 0x64($a0)
/* CC44BC 80240CAC 8E220018 */  lw        $v0, 0x18($s1)
/* CC44C0 80240CB0 9442002A */  lhu       $v0, 0x2a($v0)
/* CC44C4 80240CB4 30420001 */  andi      $v0, $v0, 1
/* CC44C8 80240CB8 10400003 */  beqz      $v0, .L80240CC8
/* CC44CC 80240CBC 2402000A */   addiu    $v0, $zero, 0xa
/* CC44D0 80240CC0 0809035C */  j         .L80240D70
/* CC44D4 80240CC4 AE620070 */   sw       $v0, 0x70($s3)
.L80240CC8:
/* CC44D8 80240CC8 0809035C */  j         .L80240D70
/* CC44DC 80240CCC AE720070 */   sw       $s2, 0x70($s3)
.L80240CD0:
/* CC44E0 80240CD0 AE220090 */  sw        $v0, 0x90($s1)
.L80240CD4:
/* CC44E4 80240CD4 8602008C */  lh        $v0, 0x8c($s0)
/* CC44E8 80240CD8 14400025 */  bnez      $v0, .L80240D70
/* CC44EC 80240CDC 00000000 */   nop      
/* CC44F0 80240CE0 8602008E */  lh        $v0, 0x8e($s0)
/* CC44F4 80240CE4 1C400022 */  bgtz      $v0, .L80240D70
/* CC44F8 80240CE8 00000000 */   nop      
/* CC44FC 80240CEC 8E620074 */  lw        $v0, 0x74($s3)
/* CC4500 80240CF0 2442FFFF */  addiu     $v0, $v0, -1
/* CC4504 80240CF4 1840001D */  blez      $v0, .L80240D6C
/* CC4508 80240CF8 AE620074 */   sw       $v0, 0x74($s3)
/* CC450C 80240CFC 8E220018 */  lw        $v0, 0x18($s1)
/* CC4510 80240D00 9442002A */  lhu       $v0, 0x2a($v0)
/* CC4514 80240D04 30420010 */  andi      $v0, $v0, 0x10
/* CC4518 80240D08 14400007 */  bnez      $v0, .L80240D28
/* CC451C 80240D0C 00000000 */   nop      
/* CC4520 80240D10 C600000C */  lwc1      $f0, 0xc($s0)
/* CC4524 80240D14 3C014334 */  lui       $at, 0x4334
/* CC4528 80240D18 44816000 */  mtc1      $at, $f12
/* CC452C 80240D1C 0C00A6C9 */  jal       clamp_angle
/* CC4530 80240D20 460C0300 */   add.s    $f12, $f0, $f12
/* CC4534 80240D24 E600000C */  swc1      $f0, 0xc($s0)
.L80240D28:
/* CC4538 80240D28 0C00A67F */  jal       rand_int
/* CC453C 80240D2C 240403E8 */   addiu    $a0, $zero, 0x3e8
/* CC4540 80240D30 3C032E8B */  lui       $v1, 0x2e8b
/* CC4544 80240D34 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* CC4548 80240D38 00430018 */  mult      $v0, $v1
/* CC454C 80240D3C 00021FC3 */  sra       $v1, $v0, 0x1f
/* CC4550 80240D40 00004010 */  mfhi      $t0
/* CC4554 80240D44 00082043 */  sra       $a0, $t0, 1
/* CC4558 80240D48 00832023 */  subu      $a0, $a0, $v1
/* CC455C 80240D4C 00041840 */  sll       $v1, $a0, 1
/* CC4560 80240D50 00641821 */  addu      $v1, $v1, $a0
/* CC4564 80240D54 00031880 */  sll       $v1, $v1, 2
/* CC4568 80240D58 00641823 */  subu      $v1, $v1, $a0
/* CC456C 80240D5C 00431023 */  subu      $v0, $v0, $v1
/* CC4570 80240D60 24420005 */  addiu     $v0, $v0, 5
/* CC4574 80240D64 0809035C */  j         .L80240D70
/* CC4578 80240D68 A602008E */   sh       $v0, 0x8e($s0)
.L80240D6C:
/* CC457C 80240D6C AE600070 */  sw        $zero, 0x70($s3)
.L80240D70:
/* CC4580 80240D70 8FBF0054 */  lw        $ra, 0x54($sp)
/* CC4584 80240D74 8FB40050 */  lw        $s4, 0x50($sp)
/* CC4588 80240D78 8FB3004C */  lw        $s3, 0x4c($sp)
/* CC458C 80240D7C 8FB20048 */  lw        $s2, 0x48($sp)
/* CC4590 80240D80 8FB10044 */  lw        $s1, 0x44($sp)
/* CC4594 80240D84 8FB00040 */  lw        $s0, 0x40($sp)
/* CC4598 80240D88 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* CC459C 80240D8C D7B80068 */  ldc1      $f24, 0x68($sp)
/* CC45A0 80240D90 D7B60060 */  ldc1      $f22, 0x60($sp)
/* CC45A4 80240D94 D7B40058 */  ldc1      $f20, 0x58($sp)
/* CC45A8 80240D98 03E00008 */  jr        $ra
/* CC45AC 80240D9C 27BD0078 */   addiu    $sp, $sp, 0x78
