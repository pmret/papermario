.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B94_BE4344
/* BE4344 80240B94 27BDFF98 */  addiu     $sp, $sp, -0x68
/* BE4348 80240B98 AFB40058 */  sw        $s4, 0x58($sp)
/* BE434C 80240B9C 0080A02D */  daddu     $s4, $a0, $zero
/* BE4350 80240BA0 AFBF0060 */  sw        $ra, 0x60($sp)
/* BE4354 80240BA4 AFB5005C */  sw        $s5, 0x5c($sp)
/* BE4358 80240BA8 AFB30054 */  sw        $s3, 0x54($sp)
/* BE435C 80240BAC AFB20050 */  sw        $s2, 0x50($sp)
/* BE4360 80240BB0 AFB1004C */  sw        $s1, 0x4c($sp)
/* BE4364 80240BB4 AFB00048 */  sw        $s0, 0x48($sp)
/* BE4368 80240BB8 8E910148 */  lw        $s1, 0x148($s4)
/* BE436C 80240BBC 86240008 */  lh        $a0, 8($s1)
/* BE4370 80240BC0 0C00EABB */  jal       get_npc_unsafe
/* BE4374 80240BC4 00A0802D */   daddu    $s0, $a1, $zero
/* BE4378 80240BC8 8E83000C */  lw        $v1, 0xc($s4)
/* BE437C 80240BCC 0280202D */  daddu     $a0, $s4, $zero
/* BE4380 80240BD0 8C650000 */  lw        $a1, ($v1)
/* BE4384 80240BD4 0C0B1EAF */  jal       get_variable
/* BE4388 80240BD8 0040902D */   daddu    $s2, $v0, $zero
/* BE438C 80240BDC AFA00018 */  sw        $zero, 0x18($sp)
/* BE4390 80240BE0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BE4394 80240BE4 8C630094 */  lw        $v1, 0x94($v1)
/* BE4398 80240BE8 AFA3001C */  sw        $v1, 0x1c($sp)
/* BE439C 80240BEC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BE43A0 80240BF0 8C630080 */  lw        $v1, 0x80($v1)
/* BE43A4 80240BF4 AFA30020 */  sw        $v1, 0x20($sp)
/* BE43A8 80240BF8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BE43AC 80240BFC 8C630088 */  lw        $v1, 0x88($v1)
/* BE43B0 80240C00 AFA30024 */  sw        $v1, 0x24($sp)
/* BE43B4 80240C04 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BE43B8 80240C08 8C63008C */  lw        $v1, 0x8c($v1)
/* BE43BC 80240C0C 27B50018 */  addiu     $s5, $sp, 0x18
/* BE43C0 80240C10 AFA30028 */  sw        $v1, 0x28($sp)
/* BE43C4 80240C14 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BE43C8 80240C18 3C014282 */  lui       $at, 0x4282
/* BE43CC 80240C1C 44810000 */  mtc1      $at, $f0
/* BE43D0 80240C20 8C630090 */  lw        $v1, 0x90($v1)
/* BE43D4 80240C24 0040982D */  daddu     $s3, $v0, $zero
/* BE43D8 80240C28 E7A00030 */  swc1      $f0, 0x30($sp)
/* BE43DC 80240C2C A7A00034 */  sh        $zero, 0x34($sp)
/* BE43E0 80240C30 16000005 */  bnez      $s0, .L80240C48
/* BE43E4 80240C34 AFA3002C */   sw       $v1, 0x2c($sp)
/* BE43E8 80240C38 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BE43EC 80240C3C 30420004 */  andi      $v0, $v0, 4
/* BE43F0 80240C40 10400044 */  beqz      $v0, .L80240D54
/* BE43F4 80240C44 00000000 */   nop      
.L80240C48:
/* BE43F8 80240C48 2404F7FF */  addiu     $a0, $zero, -0x801
/* BE43FC 80240C4C AE800070 */  sw        $zero, 0x70($s4)
/* BE4400 80240C50 A640008E */  sh        $zero, 0x8e($s2)
/* BE4404 80240C54 8E2200CC */  lw        $v0, 0xcc($s1)
/* BE4408 80240C58 8E430000 */  lw        $v1, ($s2)
/* BE440C 80240C5C 8C420000 */  lw        $v0, ($v0)
/* BE4410 80240C60 00641824 */  and       $v1, $v1, $a0
/* BE4414 80240C64 AE430000 */  sw        $v1, ($s2)
/* BE4418 80240C68 AE420028 */  sw        $v0, 0x28($s2)
/* BE441C 80240C6C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BE4420 80240C70 8C420098 */  lw        $v0, 0x98($v0)
/* BE4424 80240C74 54400005 */  bnel      $v0, $zero, .L80240C8C
/* BE4428 80240C78 2402FDFF */   addiu    $v0, $zero, -0x201
/* BE442C 80240C7C 34620200 */  ori       $v0, $v1, 0x200
/* BE4430 80240C80 2403FFF7 */  addiu     $v1, $zero, -9
/* BE4434 80240C84 08090325 */  j         .L80240C94
/* BE4438 80240C88 00431024 */   and      $v0, $v0, $v1
.L80240C8C:
/* BE443C 80240C8C 00621024 */  and       $v0, $v1, $v0
/* BE4440 80240C90 34420008 */  ori       $v0, $v0, 8
.L80240C94:
/* BE4444 80240C94 AE420000 */  sw        $v0, ($s2)
/* BE4448 80240C98 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BE444C 80240C9C 30420004 */  andi      $v0, $v0, 4
/* BE4450 80240CA0 10400008 */  beqz      $v0, .L80240CC4
/* BE4454 80240CA4 24020063 */   addiu    $v0, $zero, 0x63
/* BE4458 80240CA8 AE820070 */  sw        $v0, 0x70($s4)
/* BE445C 80240CAC AE800074 */  sw        $zero, 0x74($s4)
/* BE4460 80240CB0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BE4464 80240CB4 2403FFFB */  addiu     $v1, $zero, -5
/* BE4468 80240CB8 00431024 */  and       $v0, $v0, $v1
/* BE446C 80240CBC 0809033C */  j         .L80240CF0
/* BE4470 80240CC0 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240CC4:
/* BE4474 80240CC4 8E220000 */  lw        $v0, ($s1)
/* BE4478 80240CC8 3C034000 */  lui       $v1, 0x4000
/* BE447C 80240CCC 00431024 */  and       $v0, $v0, $v1
/* BE4480 80240CD0 10400007 */  beqz      $v0, .L80240CF0
/* BE4484 80240CD4 3C03BFFF */   lui      $v1, 0xbfff
/* BE4488 80240CD8 2402000C */  addiu     $v0, $zero, 0xc
/* BE448C 80240CDC AE820070 */  sw        $v0, 0x70($s4)
/* BE4490 80240CE0 8E220000 */  lw        $v0, ($s1)
/* BE4494 80240CE4 3463FFFF */  ori       $v1, $v1, 0xffff
/* BE4498 80240CE8 00431024 */  and       $v0, $v0, $v1
/* BE449C 80240CEC AE220000 */  sw        $v0, ($s1)
.L80240CF0:
/* BE44A0 80240CF0 27A50038 */  addiu     $a1, $sp, 0x38
/* BE44A4 80240CF4 27A6003C */  addiu     $a2, $sp, 0x3c
/* BE44A8 80240CF8 C6400038 */  lwc1      $f0, 0x38($s2)
/* BE44AC 80240CFC 864200A8 */  lh        $v0, 0xa8($s2)
/* BE44B0 80240D00 3C0142C8 */  lui       $at, 0x42c8
/* BE44B4 80240D04 44812000 */  mtc1      $at, $f4
/* BE44B8 80240D08 44823000 */  mtc1      $v0, $f6
/* BE44BC 80240D0C 00000000 */  nop       
/* BE44C0 80240D10 468031A0 */  cvt.s.w   $f6, $f6
/* BE44C4 80240D14 27A20044 */  addiu     $v0, $sp, 0x44
/* BE44C8 80240D18 E7A00038 */  swc1      $f0, 0x38($sp)
/* BE44CC 80240D1C C640003C */  lwc1      $f0, 0x3c($s2)
/* BE44D0 80240D20 C6420040 */  lwc1      $f2, 0x40($s2)
/* BE44D4 80240D24 46060000 */  add.s     $f0, $f0, $f6
/* BE44D8 80240D28 E7A40044 */  swc1      $f4, 0x44($sp)
/* BE44DC 80240D2C E7A20040 */  swc1      $f2, 0x40($sp)
/* BE44E0 80240D30 E7A0003C */  swc1      $f0, 0x3c($sp)
/* BE44E4 80240D34 AFA20010 */  sw        $v0, 0x10($sp)
/* BE44E8 80240D38 8E440080 */  lw        $a0, 0x80($s2)
/* BE44EC 80240D3C 0C0372DF */  jal       func_800DCB7C
/* BE44F0 80240D40 27A70040 */   addiu    $a3, $sp, 0x40
/* BE44F4 80240D44 10400003 */  beqz      $v0, .L80240D54
/* BE44F8 80240D48 00000000 */   nop      
/* BE44FC 80240D4C C7A0003C */  lwc1      $f0, 0x3c($sp)
/* BE4500 80240D50 E640003C */  swc1      $f0, 0x3c($s2)
.L80240D54:
/* BE4504 80240D54 8E830070 */  lw        $v1, 0x70($s4)
/* BE4508 80240D58 2C620064 */  sltiu     $v0, $v1, 0x64
/* BE450C 80240D5C 10400042 */  beqz      $v0, .L80240E68
/* BE4510 80240D60 00031080 */   sll      $v0, $v1, 2
/* BE4514 80240D64 3C018024 */  lui       $at, %hi(D_80244140)
/* BE4518 80240D68 00220821 */  addu      $at, $at, $v0
/* BE451C 80240D6C 8C224140 */  lw        $v0, %lo(D_80244140)($at)
/* BE4520 80240D70 00400008 */  jr        $v0
/* BE4524 80240D74 00000000 */   nop      
/* BE4528 80240D78 0280202D */  daddu     $a0, $s4, $zero
/* BE452C 80240D7C 0260282D */  daddu     $a1, $s3, $zero
/* BE4530 80240D80 0C090000 */  jal       func_80240000_BE37B0
/* BE4534 80240D84 02A0302D */   daddu    $a2, $s5, $zero
/* BE4538 80240D88 0280202D */  daddu     $a0, $s4, $zero
/* BE453C 80240D8C 0260282D */  daddu     $a1, $s3, $zero
/* BE4540 80240D90 0C090056 */  jal       func_80240158_BE3908
/* BE4544 80240D94 02A0302D */   daddu    $a2, $s5, $zero
/* BE4548 80240D98 0809039A */  j         .L80240E68
/* BE454C 80240D9C 00000000 */   nop      
/* BE4550 80240DA0 0280202D */  daddu     $a0, $s4, $zero
/* BE4554 80240DA4 0260282D */  daddu     $a1, $s3, $zero
/* BE4558 80240DA8 0C090100 */  jal       arn_04_UnkNpcAIFunc1
/* BE455C 80240DAC 02A0302D */   daddu    $a2, $s5, $zero
/* BE4560 80240DB0 0280202D */  daddu     $a0, $s4, $zero
/* BE4564 80240DB4 0260282D */  daddu     $a1, $s3, $zero
/* BE4568 80240DB8 0C090130 */  jal       func_802404C0_BE3C70
/* BE456C 80240DBC 02A0302D */   daddu    $a2, $s5, $zero
/* BE4570 80240DC0 0809039A */  j         .L80240E68
/* BE4574 80240DC4 00000000 */   nop      
/* BE4578 80240DC8 0280202D */  daddu     $a0, $s4, $zero
/* BE457C 80240DCC 0260282D */  daddu     $a1, $s3, $zero
/* BE4580 80240DD0 0C09019F */  jal       func_8024067C_BE3E2C
/* BE4584 80240DD4 02A0302D */   daddu    $a2, $s5, $zero
/* BE4588 80240DD8 0809039A */  j         .L80240E68
/* BE458C 80240DDC 00000000 */   nop      
/* BE4590 80240DE0 0280202D */  daddu     $a0, $s4, $zero
/* BE4594 80240DE4 0260282D */  daddu     $a1, $s3, $zero
/* BE4598 80240DE8 0C0901CC */  jal       arn_04_NpcJumpFunc2
/* BE459C 80240DEC 02A0302D */   daddu    $a2, $s5, $zero
/* BE45A0 80240DF0 0280202D */  daddu     $a0, $s4, $zero
/* BE45A4 80240DF4 0260282D */  daddu     $a1, $s3, $zero
/* BE45A8 80240DF8 0C0901E9 */  jal       arn_04_NpcJumpFunc
/* BE45AC 80240DFC 02A0302D */   daddu    $a2, $s5, $zero
/* BE45B0 80240E00 0809039A */  j         .L80240E68
/* BE45B4 80240E04 00000000 */   nop      
/* BE45B8 80240E08 0280202D */  daddu     $a0, $s4, $zero
/* BE45BC 80240E0C 0260282D */  daddu     $a1, $s3, $zero
/* BE45C0 80240E10 0C090207 */  jal       func_8024081C_BE3FCC
/* BE45C4 80240E14 02A0302D */   daddu    $a2, $s5, $zero
/* BE45C8 80240E18 0280202D */  daddu     $a0, $s4, $zero
/* BE45CC 80240E1C 0260282D */  daddu     $a1, $s3, $zero
/* BE45D0 80240E20 0C090253 */  jal       func_8024094C_BE40FC
/* BE45D4 80240E24 02A0302D */   daddu    $a2, $s5, $zero
/* BE45D8 80240E28 0809039A */  j         .L80240E68
/* BE45DC 80240E2C 00000000 */   nop      
/* BE45E0 80240E30 0280202D */  daddu     $a0, $s4, $zero
/* BE45E4 80240E34 0260282D */  daddu     $a1, $s3, $zero
/* BE45E8 80240E38 0C09029B */  jal       arn_04_UnkNpcDurationFlagFunc
/* BE45EC 80240E3C 02A0302D */   daddu    $a2, $s5, $zero
/* BE45F0 80240E40 0809039A */  j         .L80240E68
/* BE45F4 80240E44 00000000 */   nop      
/* BE45F8 80240E48 0280202D */  daddu     $a0, $s4, $zero
/* BE45FC 80240E4C 0260282D */  daddu     $a1, $s3, $zero
/* BE4600 80240E50 0C0902B5 */  jal       func_80240AD4_BE4284
/* BE4604 80240E54 02A0302D */   daddu    $a2, $s5, $zero
/* BE4608 80240E58 0809039A */  j         .L80240E68
/* BE460C 80240E5C 00000000 */   nop      
/* BE4610 80240E60 0C0129CF */  jal       func_8004A73C
/* BE4614 80240E64 0280202D */   daddu    $a0, $s4, $zero
.L80240E68:
/* BE4618 80240E68 8FBF0060 */  lw        $ra, 0x60($sp)
/* BE461C 80240E6C 8FB5005C */  lw        $s5, 0x5c($sp)
/* BE4620 80240E70 8FB40058 */  lw        $s4, 0x58($sp)
/* BE4624 80240E74 8FB30054 */  lw        $s3, 0x54($sp)
/* BE4628 80240E78 8FB20050 */  lw        $s2, 0x50($sp)
/* BE462C 80240E7C 8FB1004C */  lw        $s1, 0x4c($sp)
/* BE4630 80240E80 8FB00048 */  lw        $s0, 0x48($sp)
/* BE4634 80240E84 0000102D */  daddu     $v0, $zero, $zero
/* BE4638 80240E88 03E00008 */  jr        $ra
/* BE463C 80240E8C 27BD0068 */   addiu    $sp, $sp, 0x68
