.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C90_EF42A0
/* EF42A0 80241C90 27BDFF98 */  addiu     $sp, $sp, -0x68
/* EF42A4 80241C94 AFB40050 */  sw        $s4, 0x50($sp)
/* EF42A8 80241C98 0080A02D */  daddu     $s4, $a0, $zero
/* EF42AC 80241C9C AFBF005C */  sw        $ra, 0x5c($sp)
/* EF42B0 80241CA0 AFB60058 */  sw        $s6, 0x58($sp)
/* EF42B4 80241CA4 AFB50054 */  sw        $s5, 0x54($sp)
/* EF42B8 80241CA8 AFB3004C */  sw        $s3, 0x4c($sp)
/* EF42BC 80241CAC AFB20048 */  sw        $s2, 0x48($sp)
/* EF42C0 80241CB0 AFB10044 */  sw        $s1, 0x44($sp)
/* EF42C4 80241CB4 AFB00040 */  sw        $s0, 0x40($sp)
/* EF42C8 80241CB8 F7B40060 */  sdc1      $f20, 0x60($sp)
/* EF42CC 80241CBC 8E930148 */  lw        $s3, 0x148($s4)
/* EF42D0 80241CC0 86640008 */  lh        $a0, 8($s3)
/* EF42D4 80241CC4 8E90000C */  lw        $s0, 0xc($s4)
/* EF42D8 80241CC8 0C00F92F */  jal       dead_get_npc_unsafe
/* EF42DC 80241CCC 00A0882D */   daddu    $s1, $a1, $zero
/* EF42E0 80241CD0 0280202D */  daddu     $a0, $s4, $zero
/* EF42E4 80241CD4 8E050000 */  lw        $a1, ($s0)
/* EF42E8 80241CD8 0C0B53A3 */  jal       dead_evt_get_variable
/* EF42EC 80241CDC 0040902D */   daddu    $s2, $v0, $zero
/* EF42F0 80241CE0 AFA00020 */  sw        $zero, 0x20($sp)
/* EF42F4 80241CE4 8E6300D0 */  lw        $v1, 0xd0($s3)
/* EF42F8 80241CE8 8C630030 */  lw        $v1, 0x30($v1)
/* EF42FC 80241CEC AFA30024 */  sw        $v1, 0x24($sp)
/* EF4300 80241CF0 8E6300D0 */  lw        $v1, 0xd0($s3)
/* EF4304 80241CF4 8C63001C */  lw        $v1, 0x1c($v1)
/* EF4308 80241CF8 AFA30028 */  sw        $v1, 0x28($sp)
/* EF430C 80241CFC 8E6300D0 */  lw        $v1, 0xd0($s3)
/* EF4310 80241D00 8C630024 */  lw        $v1, 0x24($v1)
/* EF4314 80241D04 AFA3002C */  sw        $v1, 0x2c($sp)
/* EF4318 80241D08 8E6300D0 */  lw        $v1, 0xd0($s3)
/* EF431C 80241D0C 8C630028 */  lw        $v1, 0x28($v1)
/* EF4320 80241D10 AFA30030 */  sw        $v1, 0x30($sp)
/* EF4324 80241D14 8E6300D0 */  lw        $v1, 0xd0($s3)
/* EF4328 80241D18 3C0142F0 */  lui       $at, 0x42f0
/* EF432C 80241D1C 44810000 */  mtc1      $at, $f0
/* EF4330 80241D20 8C63002C */  lw        $v1, 0x2c($v1)
/* EF4334 80241D24 E7A00038 */  swc1      $f0, 0x38($sp)
/* EF4338 80241D28 A7A0003C */  sh        $zero, 0x3c($sp)
/* EF433C 80241D2C AFA30034 */  sw        $v1, 0x34($sp)
/* EF4340 80241D30 C6400038 */  lwc1      $f0, 0x38($s2)
/* EF4344 80241D34 E6600108 */  swc1      $f0, 0x108($s3)
/* EF4348 80241D38 C640003C */  lwc1      $f0, 0x3c($s2)
/* EF434C 80241D3C 27B50020 */  addiu     $s5, $sp, 0x20
/* EF4350 80241D40 E660010C */  swc1      $f0, 0x10c($s3)
/* EF4354 80241D44 3C0138D1 */  lui       $at, 0x38d1
/* EF4358 80241D48 3421B717 */  ori       $at, $at, 0xb717
/* EF435C 80241D4C 44810000 */  mtc1      $at, $f0
/* EF4360 80241D50 C6420040 */  lwc1      $f2, 0x40($s2)
/* EF4364 80241D54 0040B02D */  daddu     $s6, $v0, $zero
/* EF4368 80241D58 E6600114 */  swc1      $f0, 0x114($s3)
/* EF436C 80241D5C E6600118 */  swc1      $f0, 0x118($s3)
/* EF4370 80241D60 12200007 */  beqz      $s1, .L80241D80
/* EF4374 80241D64 E6620110 */   swc1     $f2, 0x110($s3)
/* EF4378 80241D68 0240202D */  daddu     $a0, $s2, $zero
/* EF437C 80241D6C 0260282D */  daddu     $a1, $s3, $zero
/* EF4380 80241D70 0280302D */  daddu     $a2, $s4, $zero
/* EF4384 80241D74 0C090496 */  jal       EF2680_UnkFunc5
/* EF4388 80241D78 02C0382D */   daddu    $a3, $s6, $zero
/* EF438C 80241D7C AE800070 */  sw        $zero, 0x70($s4)
.L80241D80:
/* EF4390 80241D80 2402FFFD */  addiu     $v0, $zero, -3
/* EF4394 80241D84 A24200AB */  sb        $v0, 0xab($s2)
/* EF4398 80241D88 8E6300B0 */  lw        $v1, 0xb0($s3)
/* EF439C 80241D8C 30620004 */  andi      $v0, $v1, 4
/* EF43A0 80241D90 10400007 */  beqz      $v0, .L80241DB0
/* EF43A4 80241D94 00000000 */   nop
/* EF43A8 80241D98 826200B4 */  lb        $v0, 0xb4($s3)
/* EF43AC 80241D9C 144000F4 */  bnez      $v0, .L80242170
/* EF43B0 80241DA0 0000102D */   daddu    $v0, $zero, $zero
/* EF43B4 80241DA4 2402FFFB */  addiu     $v0, $zero, -5
/* EF43B8 80241DA8 00621024 */  and       $v0, $v1, $v0
/* EF43BC 80241DAC AE6200B0 */  sw        $v0, 0xb0($s3)
.L80241DB0:
/* EF43C0 80241DB0 8E830070 */  lw        $v1, 0x70($s4)
/* EF43C4 80241DB4 24020001 */  addiu     $v0, $zero, 1
/* EF43C8 80241DB8 10620011 */  beq       $v1, $v0, .L80241E00
/* EF43CC 80241DBC 28620002 */   slti     $v0, $v1, 2
/* EF43D0 80241DC0 10400005 */  beqz      $v0, .L80241DD8
/* EF43D4 80241DC4 24020002 */   addiu    $v0, $zero, 2
/* EF43D8 80241DC8 10600009 */  beqz      $v1, .L80241DF0
/* EF43DC 80241DCC 2402000C */   addiu    $v0, $zero, 0xc
/* EF43E0 80241DD0 08090790 */  j         .L80241E40
/* EF43E4 80241DD4 00000000 */   nop
.L80241DD8:
/* EF43E8 80241DD8 1062000F */  beq       $v1, $v0, .L80241E18
/* EF43EC 80241DDC 24020003 */   addiu    $v0, $zero, 3
/* EF43F0 80241DE0 10620012 */  beq       $v1, $v0, .L80241E2C
/* EF43F4 80241DE4 0280202D */   daddu    $a0, $s4, $zero
/* EF43F8 80241DE8 0809078E */  j         .L80241E38
/* EF43FC 80241DEC 00000000 */   nop
.L80241DF0:
/* EF4400 80241DF0 0280202D */  daddu     $a0, $s4, $zero
/* EF4404 80241DF4 02C0282D */  daddu     $a1, $s6, $zero
/* EF4408 80241DF8 0C09001C */  jal       EF2680_UnkNpcAIFunc23
/* EF440C 80241DFC 02A0302D */   daddu    $a2, $s5, $zero
.L80241E00:
/* EF4410 80241E00 0280202D */  daddu     $a0, $s4, $zero
/* EF4414 80241E04 02C0282D */  daddu     $a1, $s6, $zero
/* EF4418 80241E08 0C090577 */  jal       func_802415DC_EF3BEC
/* EF441C 80241E0C 02A0302D */   daddu    $a2, $s5, $zero
/* EF4420 80241E10 0809078E */  j         .L80241E38
/* EF4424 80241E14 00000000 */   nop
.L80241E18:
/* EF4428 80241E18 0280202D */  daddu     $a0, $s4, $zero
/* EF442C 80241E1C 02C0282D */  daddu     $a1, $s6, $zero
/* EF4430 80241E20 0C090212 */  jal       EF2680_DeadUnkNpcAIFunc1
/* EF4434 80241E24 02A0302D */   daddu    $a2, $s5, $zero
/* EF4438 80241E28 0280202D */  daddu     $a0, $s4, $zero
.L80241E2C:
/* EF443C 80241E2C 02C0282D */  daddu     $a1, $s6, $zero
/* EF4440 80241E30 0C090690 */  jal       func_80241A40_EF4050
/* EF4444 80241E34 02A0302D */   daddu    $a2, $s5, $zero
.L80241E38:
/* EF4448 80241E38 8E830070 */  lw        $v1, 0x70($s4)
/* EF444C 80241E3C 2402000C */  addiu     $v0, $zero, 0xc
.L80241E40:
/* EF4450 80241E40 1462001A */  bne       $v1, $v0, .L80241EAC
/* EF4454 80241E44 00000000 */   nop
/* EF4458 80241E48 C64C0038 */  lwc1      $f12, 0x38($s2)
/* EF445C 80241E4C 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EF4460 80241E50 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EF4464 80241E54 C64E0040 */  lwc1      $f14, 0x40($s2)
/* EF4468 80241E58 8C460028 */  lw        $a2, 0x28($v0)
/* EF446C 80241E5C 0C00ABDC */  jal       fio_validate_header_checksums
/* EF4470 80241E60 8C470030 */   lw       $a3, 0x30($v0)
/* EF4474 80241E64 0C090565 */  jal       func_80241594_EF3BA4
/* EF4478 80241E68 E640000C */   swc1     $f0, 0xc($s2)
/* EF447C 80241E6C 0440000F */  bltz      $v0, .L80241EAC
/* EF4480 80241E70 AE62007C */   sw       $v0, 0x7c($s3)
/* EF4484 80241E74 0C010ABD */  jal       dead_get_enemy
/* EF4488 80241E78 0040202D */   daddu    $a0, $v0, $zero
/* EF448C 80241E7C 3C030049 */  lui       $v1, 0x49
/* EF4490 80241E80 0040202D */  daddu     $a0, $v0, $zero
/* EF4494 80241E84 24020001 */  addiu     $v0, $zero, 1
/* EF4498 80241E88 AC820094 */  sw        $v0, 0x94($a0)
/* EF449C 80241E8C 86620008 */  lh        $v0, 8($s3)
/* EF44A0 80241E90 34630014 */  ori       $v1, $v1, 0x14
/* EF44A4 80241E94 AC820098 */  sw        $v0, 0x98($a0)
/* EF44A8 80241E98 2402000F */  addiu     $v0, $zero, 0xf
/* EF44AC 80241E9C A642008E */  sh        $v0, 0x8e($s2)
/* EF44B0 80241EA0 2402001E */  addiu     $v0, $zero, 0x1e
/* EF44B4 80241EA4 AE430028 */  sw        $v1, 0x28($s2)
/* EF44B8 80241EA8 AE820070 */  sw        $v0, 0x70($s4)
.L80241EAC:
/* EF44BC 80241EAC 8E830070 */  lw        $v1, 0x70($s4)
/* EF44C0 80241EB0 2402000D */  addiu     $v0, $zero, 0xd
/* EF44C4 80241EB4 10620010 */  beq       $v1, $v0, .L80241EF8
/* EF44C8 80241EB8 2862000E */   slti     $v0, $v1, 0xe
/* EF44CC 80241EBC 10400005 */  beqz      $v0, .L80241ED4
/* EF44D0 80241EC0 2402000C */   addiu    $v0, $zero, 0xc
/* EF44D4 80241EC4 10620008 */  beq       $v1, $v0, .L80241EE8
/* EF44D8 80241EC8 2410001F */   addiu    $s0, $zero, 0x1f
/* EF44DC 80241ECC 080907C9 */  j         .L80241F24
/* EF44E0 80241ED0 00000000 */   nop
.L80241ED4:
/* EF44E4 80241ED4 2402000E */  addiu     $v0, $zero, 0xe
/* EF44E8 80241ED8 1062000D */  beq       $v1, $v0, .L80241F10
/* EF44EC 80241EDC 0280202D */   daddu    $a0, $s4, $zero
/* EF44F0 80241EE0 080907C7 */  j         .L80241F1C
/* EF44F4 80241EE4 00000000 */   nop
.L80241EE8:
/* EF44F8 80241EE8 0280202D */  daddu     $a0, $s4, $zero
/* EF44FC 80241EEC 02C0282D */  daddu     $a1, $s6, $zero
/* EF4500 80241EF0 0C09034C */  jal       EF2680_DeadUnkNpcAIFunc14
/* EF4504 80241EF4 02A0302D */   daddu    $a2, $s5, $zero
.L80241EF8:
/* EF4508 80241EF8 0280202D */  daddu     $a0, $s4, $zero
/* EF450C 80241EFC 02C0282D */  daddu     $a1, $s6, $zero
/* EF4510 80241F00 0C090399 */  jal       EF2680_UnkNpcAIFunc3
/* EF4514 80241F04 02A0302D */   daddu    $a2, $s5, $zero
/* EF4518 80241F08 080907C7 */  j         .L80241F1C
/* EF451C 80241F0C 00000000 */   nop
.L80241F10:
/* EF4520 80241F10 02C0282D */  daddu     $a1, $s6, $zero
/* EF4524 80241F14 0C0903B2 */  jal       EF2680_UnkFunc6
/* EF4528 80241F18 02A0302D */   daddu    $a2, $s5, $zero
.L80241F1C:
/* EF452C 80241F1C 8E830070 */  lw        $v1, 0x70($s4)
/* EF4530 80241F20 2410001F */  addiu     $s0, $zero, 0x1f
.L80241F24:
/* EF4534 80241F24 1070001B */  beq       $v1, $s0, .L80241F94
/* EF4538 80241F28 28620020 */   slti     $v0, $v1, 0x20
/* EF453C 80241F2C 10400005 */  beqz      $v0, .L80241F44
/* EF4540 80241F30 2402001E */   addiu    $v0, $zero, 0x1e
/* EF4544 80241F34 1062000A */  beq       $v1, $v0, .L80241F60
/* EF4548 80241F38 00000000 */   nop
/* EF454C 80241F3C 08090804 */  j         .L80242010
/* EF4550 80241F40 00000000 */   nop
.L80241F44:
/* EF4554 80241F44 24020020 */  addiu     $v0, $zero, 0x20
/* EF4558 80241F48 10620022 */  beq       $v1, $v0, .L80241FD4
/* EF455C 80241F4C 24020021 */   addiu    $v0, $zero, 0x21
/* EF4560 80241F50 10620029 */  beq       $v1, $v0, .L80241FF8
/* EF4564 80241F54 00000000 */   nop
/* EF4568 80241F58 08090804 */  j         .L80242010
/* EF456C 80241F5C 00000000 */   nop
.L80241F60:
/* EF4570 80241F60 9642008E */  lhu       $v0, 0x8e($s2)
/* EF4574 80241F64 2442FFFF */  addiu     $v0, $v0, -1
/* EF4578 80241F68 A642008E */  sh        $v0, 0x8e($s2)
/* EF457C 80241F6C 00021400 */  sll       $v0, $v0, 0x10
/* EF4580 80241F70 1C400027 */  bgtz      $v0, .L80242010
/* EF4584 80241F74 00000000 */   nop
/* EF4588 80241F78 0C010ABD */  jal       dead_get_enemy
/* EF458C 80241F7C 8E64007C */   lw       $a0, 0x7c($s3)
/* EF4590 80241F80 24030002 */  addiu     $v1, $zero, 2
/* EF4594 80241F84 AC430094 */  sw        $v1, 0x94($v0)
/* EF4598 80241F88 24020005 */  addiu     $v0, $zero, 5
/* EF459C 80241F8C A642008E */  sh        $v0, 0x8e($s2)
/* EF45A0 80241F90 AE900070 */  sw        $s0, 0x70($s4)
.L80241F94:
/* EF45A4 80241F94 9642008E */  lhu       $v0, 0x8e($s2)
/* EF45A8 80241F98 2442FFFF */  addiu     $v0, $v0, -1
/* EF45AC 80241F9C A642008E */  sh        $v0, 0x8e($s2)
/* EF45B0 80241FA0 00021400 */  sll       $v0, $v0, 0x10
/* EF45B4 80241FA4 1C40001A */  bgtz      $v0, .L80242010
/* EF45B8 80241FA8 3C020049 */   lui      $v0, 0x49
/* EF45BC 80241FAC 34420015 */  ori       $v0, $v0, 0x15
/* EF45C0 80241FB0 AE420028 */  sw        $v0, 0x28($s2)
/* EF45C4 80241FB4 0C010ABD */  jal       dead_get_enemy
/* EF45C8 80241FB8 8E64007C */   lw       $a0, 0x7c($s3)
/* EF45CC 80241FBC 24030003 */  addiu     $v1, $zero, 3
/* EF45D0 80241FC0 AC430094 */  sw        $v1, 0x94($v0)
/* EF45D4 80241FC4 2402000A */  addiu     $v0, $zero, 0xa
/* EF45D8 80241FC8 A642008E */  sh        $v0, 0x8e($s2)
/* EF45DC 80241FCC 24020020 */  addiu     $v0, $zero, 0x20
/* EF45E0 80241FD0 AE820070 */  sw        $v0, 0x70($s4)
.L80241FD4:
/* EF45E4 80241FD4 9642008E */  lhu       $v0, 0x8e($s2)
/* EF45E8 80241FD8 2442FFFF */  addiu     $v0, $v0, -1
/* EF45EC 80241FDC A642008E */  sh        $v0, 0x8e($s2)
/* EF45F0 80241FE0 00021400 */  sll       $v0, $v0, 0x10
/* EF45F4 80241FE4 1C40000A */  bgtz      $v0, .L80242010
/* EF45F8 80241FE8 24020003 */   addiu    $v0, $zero, 3
/* EF45FC 80241FEC A642008E */  sh        $v0, 0x8e($s2)
/* EF4600 80241FF0 24020021 */  addiu     $v0, $zero, 0x21
/* EF4604 80241FF4 AE820070 */  sw        $v0, 0x70($s4)
.L80241FF8:
/* EF4608 80241FF8 9642008E */  lhu       $v0, 0x8e($s2)
/* EF460C 80241FFC 2442FFFF */  addiu     $v0, $v0, -1
/* EF4610 80242000 A642008E */  sh        $v0, 0x8e($s2)
/* EF4614 80242004 00021400 */  sll       $v0, $v0, 0x10
/* EF4618 80242008 58400001 */  blezl     $v0, .L80242010
/* EF461C 8024200C AE800070 */   sw       $zero, 0x70($s4)
.L80242010:
/* EF4620 80242010 8E820070 */  lw        $v0, 0x70($s4)
/* EF4624 80242014 2442FFE2 */  addiu     $v0, $v0, -0x1e
/* EF4628 80242018 2C420002 */  sltiu     $v0, $v0, 2
/* EF462C 8024201C 10400054 */  beqz      $v0, .L80242170
/* EF4630 80242020 0000102D */   daddu    $v0, $zero, $zero
/* EF4634 80242024 3C108010 */  lui       $s0, %hi(dead_gPlayerStatusPtr)
/* EF4638 80242028 2610FC90 */  addiu     $s0, $s0, %lo(dead_gPlayerStatusPtr)
/* EF463C 8024202C C64C0038 */  lwc1      $f12, 0x38($s2)
/* EF4640 80242030 8E020000 */  lw        $v0, ($s0)
/* EF4644 80242034 C64E0040 */  lwc1      $f14, 0x40($s2)
/* EF4648 80242038 8C460028 */  lw        $a2, 0x28($v0)
/* EF464C 8024203C 0C00ABDC */  jal       fio_validate_header_checksums
/* EF4650 80242040 8C470030 */   lw       $a3, 0x30($v0)
/* EF4654 80242044 8E460038 */  lw        $a2, 0x38($s2)
/* EF4658 80242048 8E470040 */  lw        $a3, 0x40($s2)
/* EF465C 8024204C 8E020000 */  lw        $v0, ($s0)
/* EF4660 80242050 E640000C */  swc1      $f0, 0xc($s2)
/* EF4664 80242054 C44C0028 */  lwc1      $f12, 0x28($v0)
/* EF4668 80242058 0C00AC71 */  jal       dead_dist2D
/* EF466C 8024205C C44E0030 */   lwc1     $f14, 0x30($v0)
/* EF4670 80242060 C6A20008 */  lwc1      $f2, 8($s5)
/* EF4674 80242064 468010A0 */  cvt.s.w   $f2, $f2
/* EF4678 80242068 44051000 */  mfc1      $a1, $f2
/* EF467C 8024206C C6A2000C */  lwc1      $f2, 0xc($s5)
/* EF4680 80242070 468010A0 */  cvt.s.w   $f2, $f2
/* EF4684 80242074 44061000 */  mfc1      $a2, $f2
/* EF4688 80242078 C6420040 */  lwc1      $f2, 0x40($s2)
/* EF468C 8024207C E7A20010 */  swc1      $f2, 0x10($sp)
/* EF4690 80242080 C6A20010 */  lwc1      $f2, 0x10($s5)
/* EF4694 80242084 468010A0 */  cvt.s.w   $f2, $f2
/* EF4698 80242088 E7A20014 */  swc1      $f2, 0x14($sp)
/* EF469C 8024208C C6A20014 */  lwc1      $f2, 0x14($s5)
/* EF46A0 80242090 468010A0 */  cvt.s.w   $f2, $f2
/* EF46A4 80242094 E7A20018 */  swc1      $f2, 0x18($sp)
/* EF46A8 80242098 8EA40004 */  lw        $a0, 4($s5)
/* EF46AC 8024209C 8E470038 */  lw        $a3, 0x38($s2)
/* EF46B0 802420A0 0C013431 */  jal       dead_is_point_within_region
/* EF46B4 802420A4 46000506 */   mov.s    $f20, $f0
/* EF46B8 802420A8 14400031 */  bnez      $v0, .L80242170
/* EF46BC 802420AC 0000102D */   daddu    $v0, $zero, $zero
/* EF46C0 802420B0 3C01403E */  lui       $at, 0x403e
/* EF46C4 802420B4 44810800 */  mtc1      $at, $f1
/* EF46C8 802420B8 44800000 */  mtc1      $zero, $f0
/* EF46CC 802420BC 4600A0A1 */  cvt.d.s   $f2, $f20
/* EF46D0 802420C0 4622003C */  c.lt.d    $f0, $f2
/* EF46D4 802420C4 00000000 */  nop
/* EF46D8 802420C8 45000029 */  bc1f      .L80242170
/* EF46DC 802420CC 00000000 */   nop
/* EF46E0 802420D0 8642008C */  lh        $v0, 0x8c($s2)
/* EF46E4 802420D4 54400026 */  bnel      $v0, $zero, .L80242170
/* EF46E8 802420D8 0000102D */   daddu    $v0, $zero, $zero
/* EF46EC 802420DC 3C014034 */  lui       $at, 0x4034
/* EF46F0 802420E0 44810800 */  mtc1      $at, $f1
/* EF46F4 802420E4 44800000 */  mtc1      $zero, $f0
/* EF46F8 802420E8 00000000 */  nop
/* EF46FC 802420EC 46201001 */  sub.d     $f0, $f2, $f0
/* EF4700 802420F0 44801000 */  mtc1      $zero, $f2
/* EF4704 802420F4 44801800 */  mtc1      $zero, $f3
/* EF4708 802420F8 46200120 */  cvt.s.d   $f4, $f0
/* EF470C 802420FC 46002021 */  cvt.d.s   $f0, $f4
/* EF4710 80242100 4622003C */  c.lt.d    $f0, $f2
/* EF4714 80242104 00000000 */  nop
/* EF4718 80242108 45000002 */  bc1f      .L80242114
/* EF471C 8024210C 00000000 */   nop
/* EF4720 80242110 44802000 */  mtc1      $zero, $f4
.L80242114:
/* EF4724 80242114 3C014069 */  lui       $at, 0x4069
/* EF4728 80242118 44811800 */  mtc1      $at, $f3
/* EF472C 8024211C 44801000 */  mtc1      $zero, $f2
/* EF4730 80242120 46002021 */  cvt.d.s   $f0, $f4
/* EF4734 80242124 4620103C */  c.lt.d    $f2, $f0
/* EF4738 80242128 00000000 */  nop
/* EF473C 8024212C 45000003 */  bc1f      .L8024213C
/* EF4740 80242130 240200C8 */   addiu    $v0, $zero, 0xc8
/* EF4744 80242134 3C014348 */  lui       $at, 0x4348
/* EF4748 80242138 44812000 */  mtc1      $at, $f4
.L8024213C:
/* EF474C 8024213C AFA20010 */  sw        $v0, 0x10($sp)
/* EF4750 80242140 8EC50000 */  lw        $a1, ($s6)
/* EF4754 80242144 8EC60018 */  lw        $a2, 0x18($s6)
/* EF4758 80242148 4600218D */  trunc.w.s $f6, $f4
/* EF475C 8024214C 44073000 */  mfc1      $a3, $f6
/* EF4760 80242150 0C00ADA9 */  jal       dead_update_lerp
/* EF4764 80242154 0000202D */   daddu    $a0, $zero, $zero
/* EF4768 80242158 44050000 */  mfc1      $a1, $f0
/* EF476C 8024215C 8E46000C */  lw        $a2, 0xc($s2)
/* EF4770 80242160 0240202D */  daddu     $a0, $s2, $zero
/* EF4774 80242164 0C00F909 */  jal       dead_npc_move_heading
/* EF4778 80242168 AC850018 */   sw       $a1, 0x18($a0)
/* EF477C 8024216C 0000102D */  daddu     $v0, $zero, $zero
.L80242170:
/* EF4780 80242170 8FBF005C */  lw        $ra, 0x5c($sp)
/* EF4784 80242174 8FB60058 */  lw        $s6, 0x58($sp)
/* EF4788 80242178 8FB50054 */  lw        $s5, 0x54($sp)
/* EF478C 8024217C 8FB40050 */  lw        $s4, 0x50($sp)
/* EF4790 80242180 8FB3004C */  lw        $s3, 0x4c($sp)
/* EF4794 80242184 8FB20048 */  lw        $s2, 0x48($sp)
/* EF4798 80242188 8FB10044 */  lw        $s1, 0x44($sp)
/* EF479C 8024218C 8FB00040 */  lw        $s0, 0x40($sp)
/* EF47A0 80242190 D7B40060 */  ldc1      $f20, 0x60($sp)
/* EF47A4 80242194 03E00008 */  jr        $ra
/* EF47A8 80242198 27BD0068 */   addiu    $sp, $sp, 0x68
