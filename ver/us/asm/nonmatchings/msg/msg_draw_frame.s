.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel msg_draw_frame
/* C4258 8012DB58 27BDFEB0 */  addiu     $sp, $sp, -0x150
/* C425C 8012DB5C 0080682D */  daddu     $t5, $a0, $zero
/* C4260 8012DB60 8FAC016C */  lw        $t4, 0x16c($sp)
/* C4264 8012DB64 00A0702D */  daddu     $t6, $a1, $zero
/* C4268 8012DB68 AFB10144 */  sw        $s1, 0x144($sp)
/* C426C 8012DB6C 8FB10170 */  lw        $s1, 0x170($sp)
/* C4270 8012DB70 00C0C82D */  daddu     $t9, $a2, $zero
/* C4274 8012DB74 AFB00140 */  sw        $s0, 0x140($sp)
/* C4278 8012DB78 AFB20148 */  sw        $s2, 0x148($sp)
/* C427C 8012DB7C 8FB20160 */  lw        $s2, 0x160($sp)
/* C4280 8012DB80 2B220010 */  slti      $v0, $t9, 0x10
/* C4284 8012DB84 AFB3014C */  sw        $s3, 0x14c($sp)
/* C4288 8012DB88 8FB30168 */  lw        $s3, 0x168($sp)
/* C428C 8012DB8C 1440034E */  bnez      $v0, .L8012E8C8
/* C4290 8012DB90 00E0802D */   daddu    $s0, $a3, $zero
/* C4294 8012DB94 2A020010 */  slti      $v0, $s0, 0x10
/* C4298 8012DB98 1440034B */  bnez      $v0, .L8012E8C8
/* C429C 8012DB9C 00000000 */   nop
/* C42A0 8012DBA0 12600005 */  beqz      $s3, .L8012DBB8
/* C42A4 8012DBA4 3C03E300 */   lui      $v1, 0xe300
/* C42A8 8012DBA8 15800004 */  bnez      $t4, .L8012DBBC
/* C42AC 8012DBAC 34630A01 */   ori      $v1, $v1, 0xa01
/* C42B0 8012DBB0 12200345 */  beqz      $s1, .L8012E8C8
/* C42B4 8012DBB4 3C03E300 */   lui      $v1, 0xe300
.L8012DBB8:
/* C42B8 8012DBB8 34630A01 */  ori       $v1, $v1, 0xa01
.L8012DBBC:
/* C42BC 8012DBBC 3C04E300 */  lui       $a0, 0xe300
/* C42C0 8012DBC0 34840C00 */  ori       $a0, $a0, 0xc00
/* C42C4 8012DBC4 3C05E300 */  lui       $a1, 0xe300
/* C42C8 8012DBC8 34A50F00 */  ori       $a1, $a1, 0xf00
/* C42CC 8012DBCC 3C06E300 */  lui       $a2, 0xe300
/* C42D0 8012DBD0 34C61001 */  ori       $a2, $a2, 0x1001
/* C42D4 8012DBD4 3C07E300 */  lui       $a3, 0xe300
/* C42D8 8012DBD8 34E71801 */  ori       $a3, $a3, 0x1801
/* C42DC 8012DBDC 3C08E300 */  lui       $t0, 0xe300
/* C42E0 8012DBE0 35081A01 */  ori       $t0, $t0, 0x1a01
/* C42E4 8012DBE4 3C18E300 */  lui       $t8, 0xe300
/* C42E8 8012DBE8 3C0B800A */  lui       $t3, %hi(gMasterGfxPos)
/* C42EC 8012DBEC 256BA66C */  addiu     $t3, $t3, %lo(gMasterGfxPos)
/* C42F0 8012DBF0 37181201 */  ori       $t8, $t8, 0x1201
/* C42F4 8012DBF4 8D690000 */  lw        $t1, ($t3)
/* C42F8 8012DBF8 3C0FE700 */  lui       $t7, 0xe700
/* C42FC 8012DBFC 0120102D */  daddu     $v0, $t1, $zero
/* C4300 8012DC00 25290008 */  addiu     $t1, $t1, 8
/* C4304 8012DC04 AD690000 */  sw        $t1, ($t3)
/* C4308 8012DC08 AC4F0000 */  sw        $t7, ($v0)
/* C430C 8012DC0C AC400004 */  sw        $zero, 4($v0)
/* C4310 8012DC10 25220008 */  addiu     $v0, $t1, 8
/* C4314 8012DC14 AD620000 */  sw        $v0, ($t3)
/* C4318 8012DC18 25220010 */  addiu     $v0, $t1, 0x10
/* C431C 8012DC1C AD230000 */  sw        $v1, ($t1)
/* C4320 8012DC20 AD200004 */  sw        $zero, 4($t1)
/* C4324 8012DC24 AD620000 */  sw        $v0, ($t3)
/* C4328 8012DC28 25220018 */  addiu     $v0, $t1, 0x18
/* C432C 8012DC2C AD240008 */  sw        $a0, 8($t1)
/* C4330 8012DC30 AD20000C */  sw        $zero, 0xc($t1)
/* C4334 8012DC34 AD620000 */  sw        $v0, ($t3)
/* C4338 8012DC38 25220020 */  addiu     $v0, $t1, 0x20
/* C433C 8012DC3C AD250010 */  sw        $a1, 0x10($t1)
/* C4340 8012DC40 AD200014 */  sw        $zero, 0x14($t1)
/* C4344 8012DC44 AD620000 */  sw        $v0, ($t3)
/* C4348 8012DC48 25220028 */  addiu     $v0, $t1, 0x28
/* C434C 8012DC4C AD260018 */  sw        $a2, 0x18($t1)
/* C4350 8012DC50 AD20001C */  sw        $zero, 0x1c($t1)
/* C4354 8012DC54 AD620000 */  sw        $v0, ($t3)
/* C4358 8012DC58 240200C0 */  addiu     $v0, $zero, 0xc0
/* C435C 8012DC5C AD220024 */  sw        $v0, 0x24($t1)
/* C4360 8012DC60 25220030 */  addiu     $v0, $t1, 0x30
/* C4364 8012DC64 AD270020 */  sw        $a3, 0x20($t1)
/* C4368 8012DC68 AD620000 */  sw        $v0, ($t3)
/* C436C 8012DC6C 24020030 */  addiu     $v0, $zero, 0x30
/* C4370 8012DC70 AD280028 */  sw        $t0, 0x28($t1)
/* C4374 8012DC74 25280038 */  addiu     $t0, $t1, 0x38
/* C4378 8012DC78 AD22002C */  sw        $v0, 0x2c($t1)
/* C437C 8012DC7C AD680000 */  sw        $t0, ($t3)
/* C4380 8012DC80 AD380030 */  sw        $t8, 0x30($t1)
/* C4384 8012DC84 12600003 */  beqz      $s3, .L8012DC94
/* C4388 8012DC88 AD200034 */   sw       $zero, 0x34($t1)
/* C438C 8012DC8C 11800168 */  beqz      $t4, .L8012E230
/* C4390 8012DC90 2B220020 */   slti     $v0, $t9, 0x20
.L8012DC94:
/* C4394 8012DC94 24020005 */  addiu     $v0, $zero, 5
/* C4398 8012DC98 12420005 */  beq       $s2, $v0, .L8012DCB0
/* C439C 8012DC9C 24020006 */   addiu    $v0, $zero, 6
/* C43A0 8012DCA0 1242005D */  beq       $s2, $v0, .L8012DE18
/* C43A4 8012DCA4 2B220020 */   slti     $v0, $t9, 0x20
/* C43A8 8012DCA8 0804B88C */  j         .L8012E230
/* C43AC 8012DCAC 00000000 */   nop
.L8012DCB0:
/* C43B0 8012DCB0 3C02802F */  lui       $v0, %hi(D_802EC3F8)
/* C43B4 8012DCB4 9442C3F8 */  lhu       $v0, %lo(D_802EC3F8)($v0)
/* C43B8 8012DCB8 25250040 */  addiu     $a1, $t1, 0x40
/* C43BC 8012DCBC AD650000 */  sw        $a1, ($t3)
/* C43C0 8012DCC0 AD2F0038 */  sw        $t7, 0x38($t1)
/* C43C4 8012DCC4 AD000004 */  sw        $zero, 4($t0)
/* C43C8 8012DCC8 00021AC2 */  srl       $v1, $v0, 0xb
/* C43CC 8012DCCC 000350C0 */  sll       $t2, $v1, 3
/* C43D0 8012DCD0 000218C2 */  srl       $v1, $v0, 3
/* C43D4 8012DCD4 306700F8 */  andi      $a3, $v1, 0xf8
/* C43D8 8012DCD8 00021080 */  sll       $v0, $v0, 2
/* C43DC 8012DCDC 1260000C */  beqz      $s3, .L8012DD10
/* C43E0 8012DCE0 304800F8 */   andi     $t0, $v0, 0xf8
/* C43E4 8012DCE4 298200FF */  slti      $v0, $t4, 0xff
/* C43E8 8012DCE8 10400009 */  beqz      $v0, .L8012DD10
/* C43EC 8012DCEC 3C04E200 */   lui      $a0, 0xe200
/* C43F0 8012DCF0 3484001C */  ori       $a0, $a0, 0x1c
/* C43F4 8012DCF4 3C030050 */  lui       $v1, 0x50
/* C43F8 8012DCF8 34634B40 */  ori       $v1, $v1, 0x4b40
/* C43FC 8012DCFC 25220048 */  addiu     $v0, $t1, 0x48
/* C4400 8012DD00 AD620000 */  sw        $v0, ($t3)
/* C4404 8012DD04 AD240040 */  sw        $a0, 0x40($t1)
/* C4408 8012DD08 0804B750 */  j         .L8012DD40
/* C440C 8012DD0C ACA30004 */   sw       $v1, 4($a1)
.L8012DD10:
/* C4410 8012DD10 3C06E200 */  lui       $a2, 0xe200
/* C4414 8012DD14 34C6001C */  ori       $a2, $a2, 0x1c
/* C4418 8012DD18 3C050F0A */  lui       $a1, 0xf0a
/* C441C 8012DD1C 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* C4420 8012DD20 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* C4424 8012DD24 8C820000 */  lw        $v0, ($a0)
/* C4428 8012DD28 34A54000 */  ori       $a1, $a1, 0x4000
/* C442C 8012DD2C 0040182D */  daddu     $v1, $v0, $zero
/* C4430 8012DD30 24420008 */  addiu     $v0, $v0, 8
/* C4434 8012DD34 AC820000 */  sw        $v0, ($a0)
/* C4438 8012DD38 AC660000 */  sw        $a2, ($v1)
/* C443C 8012DD3C AC650004 */  sw        $a1, 4($v1)
.L8012DD40:
/* C4440 8012DD40 3C04FCFF */  lui       $a0, 0xfcff
/* C4444 8012DD44 3484FFFF */  ori       $a0, $a0, 0xffff
/* C4448 8012DD48 3C03FFFD */  lui       $v1, 0xfffd
/* C444C 8012DD4C 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* C4450 8012DD50 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* C4454 8012DD54 8CC50000 */  lw        $a1, ($a2)
/* C4458 8012DD58 3463F6FB */  ori       $v1, $v1, 0xf6fb
/* C445C 8012DD5C 00A0102D */  daddu     $v0, $a1, $zero
/* C4460 8012DD60 24A50008 */  addiu     $a1, $a1, 8
/* C4464 8012DD64 ACC50000 */  sw        $a1, ($a2)
/* C4468 8012DD68 AC440000 */  sw        $a0, ($v0)
/* C446C 8012DD6C AC430004 */  sw        $v1, 4($v0)
/* C4470 8012DD70 24A20008 */  addiu     $v0, $a1, 8
/* C4474 8012DD74 ACC20000 */  sw        $v0, ($a2)
/* C4478 8012DD78 3C02FA00 */  lui       $v0, 0xfa00
/* C447C 8012DD7C ACA20000 */  sw        $v0, ($a1)
/* C4480 8012DD80 000A1600 */  sll       $v0, $t2, 0x18
/* C4484 8012DD84 00071C00 */  sll       $v1, $a3, 0x10
/* C4488 8012DD88 00431025 */  or        $v0, $v0, $v1
/* C448C 8012DD8C 00081A00 */  sll       $v1, $t0, 8
/* C4490 8012DD90 00431025 */  or        $v0, $v0, $v1
/* C4494 8012DD94 318300FF */  andi      $v1, $t4, 0xff
/* C4498 8012DD98 00431025 */  or        $v0, $v0, $v1
/* C449C 8012DD9C ACA20004 */  sw        $v0, 4($a1)
/* C44A0 8012DDA0 01B91021 */  addu      $v0, $t5, $t9
/* C44A4 8012DDA4 2444FFF8 */  addiu     $a0, $v0, -8
/* C44A8 8012DDA8 18800120 */  blez      $a0, .L8012E22C
/* C44AC 8012DDAC 24A20010 */   addiu    $v0, $a1, 0x10
/* C44B0 8012DDB0 ACC20000 */  sw        $v0, ($a2)
/* C44B4 8012DDB4 01D01021 */  addu      $v0, $t6, $s0
/* C44B8 8012DDB8 2443FFF8 */  addiu     $v1, $v0, -8
/* C44BC 8012DDBC 308203FF */  andi      $v0, $a0, 0x3ff
/* C44C0 8012DDC0 04610002 */  bgez      $v1, .L8012DDCC
/* C44C4 8012DDC4 00022380 */   sll      $a0, $v0, 0xe
/* C44C8 8012DDC8 0000182D */  daddu     $v1, $zero, $zero
.L8012DDCC:
/* C44CC 8012DDCC 306203FF */  andi      $v0, $v1, 0x3ff
/* C44D0 8012DDD0 00021080 */  sll       $v0, $v0, 2
/* C44D4 8012DDD4 3C03F600 */  lui       $v1, 0xf600
/* C44D8 8012DDD8 00431025 */  or        $v0, $v0, $v1
/* C44DC 8012DDDC 00821025 */  or        $v0, $a0, $v0
/* C44E0 8012DDE0 ACA20008 */  sw        $v0, 8($a1)
/* C44E4 8012DDE4 25A20008 */  addiu     $v0, $t5, 8
/* C44E8 8012DDE8 04420001 */  bltzl     $v0, .L8012DDF0
/* C44EC 8012DDEC 0000102D */   daddu    $v0, $zero, $zero
.L8012DDF0:
/* C44F0 8012DDF0 25C30008 */  addiu     $v1, $t6, 8
/* C44F4 8012DDF4 304203FF */  andi      $v0, $v0, 0x3ff
/* C44F8 8012DDF8 04610002 */  bgez      $v1, .L8012DE04
/* C44FC 8012DDFC 00022380 */   sll      $a0, $v0, 0xe
/* C4500 8012DE00 0000182D */  daddu     $v1, $zero, $zero
.L8012DE04:
/* C4504 8012DE04 306203FF */  andi      $v0, $v1, 0x3ff
/* C4508 8012DE08 00021080 */  sll       $v0, $v0, 2
/* C450C 8012DE0C 00821025 */  or        $v0, $a0, $v0
/* C4510 8012DE10 0804B88B */  j         .L8012E22C
/* C4514 8012DE14 ACA2000C */   sw       $v0, 0xc($a1)
.L8012DE18:
/* C4518 8012DE18 3C05E200 */  lui       $a1, 0xe200
/* C451C 8012DE1C 34A5001C */  ori       $a1, $a1, 0x1c
/* C4520 8012DE20 3C030050 */  lui       $v1, 0x50
/* C4524 8012DE24 34634240 */  ori       $v1, $v1, 0x4240
/* C4528 8012DE28 3C06FCFF */  lui       $a2, 0xfcff
/* C452C 8012DE2C 34C6FFFF */  ori       $a2, $a2, 0xffff
/* C4530 8012DE30 3C04FFFC */  lui       $a0, 0xfffc
/* C4534 8012DE34 3484F67B */  ori       $a0, $a0, 0xf67b
/* C4538 8012DE38 0160502D */  daddu     $t2, $t3, $zero
/* C453C 8012DE3C 25270040 */  addiu     $a3, $t1, 0x40
/* C4540 8012DE40 25220048 */  addiu     $v0, $t1, 0x48
/* C4544 8012DE44 AD470000 */  sw        $a3, ($t2)
/* C4548 8012DE48 AD2F0038 */  sw        $t7, 0x38($t1)
/* C454C 8012DE4C AD000004 */  sw        $zero, 4($t0)
/* C4550 8012DE50 AD420000 */  sw        $v0, ($t2)
/* C4554 8012DE54 24023000 */  addiu     $v0, $zero, 0x3000
/* C4558 8012DE58 AD380040 */  sw        $t8, 0x40($t1)
/* C455C 8012DE5C ACE20004 */  sw        $v0, 4($a3)
/* C4560 8012DE60 25220050 */  addiu     $v0, $t1, 0x50
/* C4564 8012DE64 AD420000 */  sw        $v0, ($t2)
/* C4568 8012DE68 25220058 */  addiu     $v0, $t1, 0x58
/* C456C 8012DE6C ACE50008 */  sw        $a1, 8($a3)
/* C4570 8012DE70 ACE3000C */  sw        $v1, 0xc($a3)
/* C4574 8012DE74 AD420000 */  sw        $v0, ($t2)
/* C4578 8012DE78 ACE60010 */  sw        $a2, 0x10($a3)
/* C457C 8012DE7C 12600004 */  beqz      $s3, .L8012DE90
/* C4580 8012DE80 ACE40014 */   sw       $a0, 0x14($a3)
/* C4584 8012DE84 240200FF */  addiu     $v0, $zero, 0xff
/* C4588 8012DE88 55820007 */  bnel      $t4, $v0, .L8012DEA8
/* C458C 8012DE8C 298200D9 */   slti     $v0, $t4, 0xd9
.L8012DE90:
/* C4590 8012DE90 25220060 */  addiu     $v0, $t1, 0x60
/* C4594 8012DE94 AD420000 */  sw        $v0, ($t2)
/* C4598 8012DE98 3C02FA00 */  lui       $v0, 0xfa00
/* C459C 8012DE9C ACE20018 */  sw        $v0, 0x18($a3)
/* C45A0 8012DEA0 0804B7B1 */  j         .L8012DEC4
/* C45A4 8012DEA4 240200D8 */   addiu    $v0, $zero, 0xd8
.L8012DEA8:
/* C45A8 8012DEA8 50400001 */  beql      $v0, $zero, .L8012DEB0
/* C45AC 8012DEAC 240C00D8 */   addiu    $t4, $zero, 0xd8
.L8012DEB0:
/* C45B0 8012DEB0 25220060 */  addiu     $v0, $t1, 0x60
/* C45B4 8012DEB4 AD620000 */  sw        $v0, ($t3)
/* C45B8 8012DEB8 3C02FA00 */  lui       $v0, 0xfa00
/* C45BC 8012DEBC ACE20018 */  sw        $v0, 0x18($a3)
/* C45C0 8012DEC0 318200FF */  andi      $v0, $t4, 0xff
.L8012DEC4:
/* C45C4 8012DEC4 ACE2001C */  sw        $v0, 0x1c($a3)
/* C45C8 8012DEC8 3C040701 */  lui       $a0, 0x701
/* C45CC 8012DECC 34848060 */  ori       $a0, $a0, 0x8060
/* C45D0 8012DED0 3C05073F */  lui       $a1, 0x73f
/* C45D4 8012DED4 34A5F200 */  ori       $a1, $a1, 0xf200
/* C45D8 8012DED8 3C07F580 */  lui       $a3, 0xf580
/* C45DC 8012DEDC 34E70800 */  ori       $a3, $a3, 0x800
/* C45E0 8012DEE0 3C060001 */  lui       $a2, 1
/* C45E4 8012DEE4 34C68060 */  ori       $a2, $a2, 0x8060
/* C45E8 8012DEE8 3C08000F */  lui       $t0, 0xf
/* C45EC 8012DEEC 3C0A800A */  lui       $t2, %hi(gMasterGfxPos)
/* C45F0 8012DEF0 254AA66C */  addiu     $t2, $t2, %lo(gMasterGfxPos)
/* C45F4 8012DEF4 3508C0FC */  ori       $t0, $t0, 0xc0fc
/* C45F8 8012DEF8 8D490000 */  lw        $t1, ($t2)
/* C45FC 8012DEFC 3C02FD90 */  lui       $v0, 0xfd90
/* C4600 8012DF00 0120182D */  daddu     $v1, $t1, $zero
/* C4604 8012DF04 25290008 */  addiu     $t1, $t1, 8
/* C4608 8012DF08 AD490000 */  sw        $t1, ($t2)
/* C460C 8012DF0C AC620000 */  sw        $v0, ($v1)
/* C4610 8012DF10 3C02802F */  lui       $v0, %hi(D_802ECD50)
/* C4614 8012DF14 2442CD50 */  addiu     $v0, $v0, %lo(D_802ECD50)
/* C4618 8012DF18 AC620004 */  sw        $v0, 4($v1)
/* C461C 8012DF1C 25220008 */  addiu     $v0, $t1, 8
/* C4620 8012DF20 AD420000 */  sw        $v0, ($t2)
/* C4624 8012DF24 3C02F590 */  lui       $v0, 0xf590
/* C4628 8012DF28 AD220000 */  sw        $v0, ($t1)
/* C462C 8012DF2C 25220010 */  addiu     $v0, $t1, 0x10
/* C4630 8012DF30 AD240004 */  sw        $a0, 4($t1)
/* C4634 8012DF34 AD420000 */  sw        $v0, ($t2)
/* C4638 8012DF38 3C02E600 */  lui       $v0, 0xe600
/* C463C 8012DF3C AD220008 */  sw        $v0, 8($t1)
/* C4640 8012DF40 25220018 */  addiu     $v0, $t1, 0x18
/* C4644 8012DF44 AD20000C */  sw        $zero, 0xc($t1)
/* C4648 8012DF48 AD420000 */  sw        $v0, ($t2)
/* C464C 8012DF4C 3C02F300 */  lui       $v0, 0xf300
/* C4650 8012DF50 AD220010 */  sw        $v0, 0x10($t1)
/* C4654 8012DF54 25220020 */  addiu     $v0, $t1, 0x20
/* C4658 8012DF58 AD250014 */  sw        $a1, 0x14($t1)
/* C465C 8012DF5C AD420000 */  sw        $v0, ($t2)
/* C4660 8012DF60 3C02E700 */  lui       $v0, 0xe700
/* C4664 8012DF64 AD220018 */  sw        $v0, 0x18($t1)
/* C4668 8012DF68 25220028 */  addiu     $v0, $t1, 0x28
/* C466C 8012DF6C 25230030 */  addiu     $v1, $t1, 0x30
/* C4670 8012DF70 AD20001C */  sw        $zero, 0x1c($t1)
/* C4674 8012DF74 AD420000 */  sw        $v0, ($t2)
/* C4678 8012DF78 3C02F200 */  lui       $v0, 0xf200
/* C467C 8012DF7C AD270020 */  sw        $a3, 0x20($t1)
/* C4680 8012DF80 AD260024 */  sw        $a2, 0x24($t1)
/* C4684 8012DF84 AD430000 */  sw        $v1, ($t2)
/* C4688 8012DF88 AD220028 */  sw        $v0, 0x28($t1)
/* C468C 8012DF8C 24020006 */  addiu     $v0, $zero, 6
/* C4690 8012DF90 1642004C */  bne       $s2, $v0, .L8012E0C4
/* C4694 8012DF94 AD28002C */   sw       $t0, 0x2c($t1)
/* C4698 8012DF98 25220038 */  addiu     $v0, $t1, 0x38
/* C469C 8012DF9C AD420000 */  sw        $v0, ($t2)
/* C46A0 8012DFA0 01B91021 */  addu      $v0, $t5, $t9
/* C46A4 8012DFA4 2442FFFD */  addiu     $v0, $v0, -3
/* C46A8 8012DFA8 00021480 */  sll       $v0, $v0, 0x12
/* C46AC 8012DFAC 00021403 */  sra       $v0, $v0, 0x10
/* C46B0 8012DFB0 18400006 */  blez      $v0, .L8012DFCC
/* C46B4 8012DFB4 0060202D */   daddu    $a0, $v1, $zero
/* C46B8 8012DFB8 30420FFF */  andi      $v0, $v0, 0xfff
/* C46BC 8012DFBC 00021300 */  sll       $v0, $v0, 0xc
/* C46C0 8012DFC0 3C03E400 */  lui       $v1, 0xe400
/* C46C4 8012DFC4 0804B7F4 */  j         .L8012DFD0
/* C46C8 8012DFC8 00431825 */   or       $v1, $v0, $v1
.L8012DFCC:
/* C46CC 8012DFCC 3C03E400 */  lui       $v1, 0xe400
.L8012DFD0:
/* C46D0 8012DFD0 01D01021 */  addu      $v0, $t6, $s0
/* C46D4 8012DFD4 2442FFFD */  addiu     $v0, $v0, -3
/* C46D8 8012DFD8 00021480 */  sll       $v0, $v0, 0x12
/* C46DC 8012DFDC 00021403 */  sra       $v0, $v0, 0x10
/* C46E0 8012DFE0 18400004 */  blez      $v0, .L8012DFF4
/* C46E4 8012DFE4 AC830000 */   sw       $v1, ($a0)
/* C46E8 8012DFE8 30420FFF */  andi      $v0, $v0, 0xfff
/* C46EC 8012DFEC 00621025 */  or        $v0, $v1, $v0
/* C46F0 8012DFF0 AC820000 */  sw        $v0, ($a0)
.L8012DFF4:
/* C46F4 8012DFF4 25A20003 */  addiu     $v0, $t5, 3
/* C46F8 8012DFF8 00021480 */  sll       $v0, $v0, 0x12
/* C46FC 8012DFFC 00021403 */  sra       $v0, $v0, 0x10
/* C4700 8012E000 18400004 */  blez      $v0, .L8012E014
/* C4704 8012E004 24840004 */   addiu    $a0, $a0, 4
/* C4708 8012E008 30420FFF */  andi      $v0, $v0, 0xfff
/* C470C 8012E00C 0804B806 */  j         .L8012E018
/* C4710 8012E010 00021B00 */   sll      $v1, $v0, 0xc
.L8012E014:
/* C4714 8012E014 0000182D */  daddu     $v1, $zero, $zero
.L8012E018:
/* C4718 8012E018 25C20003 */  addiu     $v0, $t6, 3
/* C471C 8012E01C 00021480 */  sll       $v0, $v0, 0x12
/* C4720 8012E020 00021403 */  sra       $v0, $v0, 0x10
/* C4724 8012E024 18400004 */  blez      $v0, .L8012E038
/* C4728 8012E028 AC830000 */   sw       $v1, ($a0)
/* C472C 8012E02C 30420FFF */  andi      $v0, $v0, 0xfff
/* C4730 8012E030 00621025 */  or        $v0, $v1, $v0
/* C4734 8012E034 AC820000 */  sw        $v0, ($a0)
.L8012E038:
/* C4738 8012E038 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* C473C 8012E03C 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* C4740 8012E040 8C620000 */  lw        $v0, ($v1)
/* C4744 8012E044 0040202D */  daddu     $a0, $v0, $zero
/* C4748 8012E048 24420008 */  addiu     $v0, $v0, 8
/* C474C 8012E04C AC620000 */  sw        $v0, ($v1)
/* C4750 8012E050 3C02E100 */  lui       $v0, 0xe100
/* C4754 8012E054 AC820000 */  sw        $v0, ($a0)
/* C4758 8012E058 25A20003 */  addiu     $v0, $t5, 3
/* C475C 8012E05C 00021480 */  sll       $v0, $v0, 0x12
/* C4760 8012E060 00021403 */  sra       $v0, $v0, 0x10
/* C4764 8012E064 04410008 */  bgez      $v0, .L8012E088
/* C4768 8012E068 24840004 */   addiu    $a0, $a0, 4
/* C476C 8012E06C 000218C0 */  sll       $v1, $v0, 3
/* C4770 8012E070 5C600001 */  bgtzl     $v1, .L8012E078
/* C4774 8012E074 0000182D */   daddu    $v1, $zero, $zero
.L8012E078:
/* C4778 8012E078 3C028015 */  lui       $v0, %hi(gMsgBGScrollAmtX)
/* C477C 8012E07C 8C4212D8 */  lw        $v0, %lo(gMsgBGScrollAmtX)($v0)
/* C4780 8012E080 0804B824 */  j         .L8012E090
/* C4784 8012E084 00431023 */   subu     $v0, $v0, $v1
.L8012E088:
/* C4788 8012E088 3C028015 */  lui       $v0, %hi(D_801512DA)
/* C478C 8012E08C 944212DA */  lhu       $v0, %lo(D_801512DA)($v0)
.L8012E090:
/* C4790 8012E090 00022C00 */  sll       $a1, $v0, 0x10
/* C4794 8012E094 25C30003 */  addiu     $v1, $t6, 3
/* C4798 8012E098 00031080 */  sll       $v0, $v1, 2
/* C479C 8012E09C 04410054 */  bgez      $v0, .L8012E1F0
/* C47A0 8012E0A0 00031480 */   sll      $v0, $v1, 0x12
/* C47A4 8012E0A4 00021B43 */  sra       $v1, $v0, 0xd
/* C47A8 8012E0A8 5C600001 */  bgtzl     $v1, .L8012E0B0
/* C47AC 8012E0AC 0000182D */   daddu    $v1, $zero, $zero
.L8012E0B0:
/* C47B0 8012E0B0 3C028015 */  lui       $v0, %hi(gMsgBGScrollAmtY)
/* C47B4 8012E0B4 8C42130C */  lw        $v0, %lo(gMsgBGScrollAmtY)($v0)
/* C47B8 8012E0B8 00431023 */  subu      $v0, $v0, $v1
/* C47BC 8012E0BC 0804B87E */  j         .L8012E1F8
/* C47C0 8012E0C0 3042FFFF */   andi     $v0, $v0, 0xffff
.L8012E0C4:
/* C47C4 8012E0C4 25220038 */  addiu     $v0, $t1, 0x38
/* C47C8 8012E0C8 AD420000 */  sw        $v0, ($t2)
/* C47CC 8012E0CC 01B91021 */  addu      $v0, $t5, $t9
/* C47D0 8012E0D0 2442FFFB */  addiu     $v0, $v0, -5
/* C47D4 8012E0D4 00021480 */  sll       $v0, $v0, 0x12
/* C47D8 8012E0D8 00021403 */  sra       $v0, $v0, 0x10
/* C47DC 8012E0DC 18400006 */  blez      $v0, .L8012E0F8
/* C47E0 8012E0E0 0060202D */   daddu    $a0, $v1, $zero
/* C47E4 8012E0E4 30420FFF */  andi      $v0, $v0, 0xfff
/* C47E8 8012E0E8 00021300 */  sll       $v0, $v0, 0xc
/* C47EC 8012E0EC 3C03E400 */  lui       $v1, 0xe400
/* C47F0 8012E0F0 0804B83F */  j         .L8012E0FC
/* C47F4 8012E0F4 00431825 */   or       $v1, $v0, $v1
.L8012E0F8:
/* C47F8 8012E0F8 3C03E400 */  lui       $v1, 0xe400
.L8012E0FC:
/* C47FC 8012E0FC 01D01021 */  addu      $v0, $t6, $s0
/* C4800 8012E100 2442FFFB */  addiu     $v0, $v0, -5
/* C4804 8012E104 00021480 */  sll       $v0, $v0, 0x12
/* C4808 8012E108 00021403 */  sra       $v0, $v0, 0x10
/* C480C 8012E10C 18400004 */  blez      $v0, .L8012E120
/* C4810 8012E110 AC830000 */   sw       $v1, ($a0)
/* C4814 8012E114 30420FFF */  andi      $v0, $v0, 0xfff
/* C4818 8012E118 00621025 */  or        $v0, $v1, $v0
/* C481C 8012E11C AC820000 */  sw        $v0, ($a0)
.L8012E120:
/* C4820 8012E120 25A20005 */  addiu     $v0, $t5, 5
/* C4824 8012E124 00021480 */  sll       $v0, $v0, 0x12
/* C4828 8012E128 00021403 */  sra       $v0, $v0, 0x10
/* C482C 8012E12C 18400004 */  blez      $v0, .L8012E140
/* C4830 8012E130 24840004 */   addiu    $a0, $a0, 4
/* C4834 8012E134 30420FFF */  andi      $v0, $v0, 0xfff
/* C4838 8012E138 0804B851 */  j         .L8012E144
/* C483C 8012E13C 00021B00 */   sll      $v1, $v0, 0xc
.L8012E140:
/* C4840 8012E140 0000182D */  daddu     $v1, $zero, $zero
.L8012E144:
/* C4844 8012E144 25C20005 */  addiu     $v0, $t6, 5
/* C4848 8012E148 00021480 */  sll       $v0, $v0, 0x12
/* C484C 8012E14C 00021403 */  sra       $v0, $v0, 0x10
/* C4850 8012E150 18400004 */  blez      $v0, .L8012E164
/* C4854 8012E154 AC830000 */   sw       $v1, ($a0)
/* C4858 8012E158 30420FFF */  andi      $v0, $v0, 0xfff
/* C485C 8012E15C 00621025 */  or        $v0, $v1, $v0
/* C4860 8012E160 AC820000 */  sw        $v0, ($a0)
.L8012E164:
/* C4864 8012E164 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* C4868 8012E168 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* C486C 8012E16C 8C620000 */  lw        $v0, ($v1)
/* C4870 8012E170 0040202D */  daddu     $a0, $v0, $zero
/* C4874 8012E174 24420008 */  addiu     $v0, $v0, 8
/* C4878 8012E178 AC620000 */  sw        $v0, ($v1)
/* C487C 8012E17C 3C02E100 */  lui       $v0, 0xe100
/* C4880 8012E180 AC820000 */  sw        $v0, ($a0)
/* C4884 8012E184 25A20005 */  addiu     $v0, $t5, 5
/* C4888 8012E188 00021480 */  sll       $v0, $v0, 0x12
/* C488C 8012E18C 00021403 */  sra       $v0, $v0, 0x10
/* C4890 8012E190 04410008 */  bgez      $v0, .L8012E1B4
/* C4894 8012E194 24840004 */   addiu    $a0, $a0, 4
/* C4898 8012E198 000218C0 */  sll       $v1, $v0, 3
/* C489C 8012E19C 5C600001 */  bgtzl     $v1, .L8012E1A4
/* C48A0 8012E1A0 0000182D */   daddu    $v1, $zero, $zero
.L8012E1A4:
/* C48A4 8012E1A4 3C028015 */  lui       $v0, %hi(gMsgBGScrollAmtX)
/* C48A8 8012E1A8 8C4212D8 */  lw        $v0, %lo(gMsgBGScrollAmtX)($v0)
/* C48AC 8012E1AC 0804B86F */  j         .L8012E1BC
/* C48B0 8012E1B0 00431023 */   subu     $v0, $v0, $v1
.L8012E1B4:
/* C48B4 8012E1B4 3C028015 */  lui       $v0, %hi(D_801512DA)
/* C48B8 8012E1B8 944212DA */  lhu       $v0, %lo(D_801512DA)($v0)
.L8012E1BC:
/* C48BC 8012E1BC 00022C00 */  sll       $a1, $v0, 0x10
/* C48C0 8012E1C0 25C30005 */  addiu     $v1, $t6, 5
/* C48C4 8012E1C4 00031080 */  sll       $v0, $v1, 2
/* C48C8 8012E1C8 04410009 */  bgez      $v0, .L8012E1F0
/* C48CC 8012E1CC 00031480 */   sll      $v0, $v1, 0x12
/* C48D0 8012E1D0 00021B43 */  sra       $v1, $v0, 0xd
/* C48D4 8012E1D4 5C600001 */  bgtzl     $v1, .L8012E1DC
/* C48D8 8012E1D8 0000182D */   daddu    $v1, $zero, $zero
.L8012E1DC:
/* C48DC 8012E1DC 3C028015 */  lui       $v0, %hi(gMsgBGScrollAmtY)
/* C48E0 8012E1E0 8C42130C */  lw        $v0, %lo(gMsgBGScrollAmtY)($v0)
/* C48E4 8012E1E4 00431023 */  subu      $v0, $v0, $v1
/* C48E8 8012E1E8 0804B87E */  j         .L8012E1F8
/* C48EC 8012E1EC 3042FFFF */   andi     $v0, $v0, 0xffff
.L8012E1F0:
/* C48F0 8012E1F0 3C028015 */  lui       $v0, %hi(D_8015130E)
/* C48F4 8012E1F4 9442130E */  lhu       $v0, %lo(D_8015130E)($v0)
.L8012E1F8:
/* C48F8 8012E1F8 00A21025 */  or        $v0, $a1, $v0
/* C48FC 8012E1FC AC820000 */  sw        $v0, ($a0)
/* C4900 8012E200 3C050400 */  lui       $a1, 0x400
/* C4904 8012E204 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* C4908 8012E208 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* C490C 8012E20C 8C620000 */  lw        $v0, ($v1)
/* C4910 8012E210 34A50400 */  ori       $a1, $a1, 0x400
/* C4914 8012E214 0040202D */  daddu     $a0, $v0, $zero
/* C4918 8012E218 24420008 */  addiu     $v0, $v0, 8
/* C491C 8012E21C AC620000 */  sw        $v0, ($v1)
/* C4920 8012E220 3C02F100 */  lui       $v0, 0xf100
/* C4924 8012E224 AC820000 */  sw        $v0, ($a0)
/* C4928 8012E228 AC850004 */  sw        $a1, 4($a0)
.L8012E22C:
/* C492C 8012E22C 2B220020 */  slti      $v0, $t9, 0x20
.L8012E230:
/* C4930 8012E230 14400007 */  bnez      $v0, .L8012E250
/* C4934 8012E234 2722FFEF */   addiu    $v0, $t9, -0x11
/* C4938 8012E238 25A30010 */  addiu     $v1, $t5, 0x10
/* C493C 8012E23C 00031880 */  sll       $v1, $v1, 2
/* C4940 8012E240 000E1080 */  sll       $v0, $t6, 2
/* C4944 8012E244 01B92021 */  addu      $a0, $t5, $t9
/* C4948 8012E248 0804B89B */  j         .L8012E26C
/* C494C 8012E24C 2484FFF0 */   addiu    $a0, $a0, -0x10
.L8012E250:
/* C4950 8012E250 2C420007 */  sltiu     $v0, $v0, 7
/* C4954 8012E254 10400015 */  beqz      $v0, .L8012E2AC
/* C4958 8012E258 25A30008 */   addiu    $v1, $t5, 8
/* C495C 8012E25C 00031880 */  sll       $v1, $v1, 2
/* C4960 8012E260 000E1080 */  sll       $v0, $t6, 2
/* C4964 8012E264 01B92021 */  addu      $a0, $t5, $t9
/* C4968 8012E268 2484FFF8 */  addiu     $a0, $a0, -8
.L8012E26C:
/* C496C 8012E26C 00042080 */  sll       $a0, $a0, 2
/* C4970 8012E270 AFA20064 */  sw        $v0, 0x64($sp)
/* C4974 8012E274 25C20008 */  addiu     $v0, $t6, 8
/* C4978 8012E278 00021080 */  sll       $v0, $v0, 2
/* C497C 8012E27C AFA30060 */  sw        $v1, 0x60($sp)
/* C4980 8012E280 AFA30110 */  sw        $v1, 0x110($sp)
/* C4984 8012E284 01D01821 */  addu      $v1, $t6, $s0
/* C4988 8012E288 AFA2006C */  sw        $v0, 0x6c($sp)
/* C498C 8012E28C 2462FFF8 */  addiu     $v0, $v1, -8
/* C4990 8012E290 00021080 */  sll       $v0, $v0, 2
/* C4994 8012E294 00031880 */  sll       $v1, $v1, 2
/* C4998 8012E298 AFA40068 */  sw        $a0, 0x68($sp)
/* C499C 8012E29C AFA20114 */  sw        $v0, 0x114($sp)
/* C49A0 8012E2A0 AFA40118 */  sw        $a0, 0x118($sp)
/* C49A4 8012E2A4 0804B8AE */  j         .L8012E2B8
/* C49A8 8012E2A8 AFA3011C */   sw       $v1, 0x11c($sp)
.L8012E2AC:
/* C49AC 8012E2AC 24022710 */  addiu     $v0, $zero, 0x2710
/* C49B0 8012E2B0 AFA20060 */  sw        $v0, 0x60($sp)
/* C49B4 8012E2B4 AFA20110 */  sw        $v0, 0x110($sp)
.L8012E2B8:
/* C49B8 8012E2B8 2A020020 */  slti      $v0, $s0, 0x20
/* C49BC 8012E2BC 1440000A */  bnez      $v0, .L8012E2E8
/* C49C0 8012E2C0 2602FFEF */   addiu    $v0, $s0, -0x11
/* C49C4 8012E2C4 000D1080 */  sll       $v0, $t5, 2
/* C49C8 8012E2C8 25C50010 */  addiu     $a1, $t6, 0x10
/* C49CC 8012E2CC 00052880 */  sll       $a1, $a1, 2
/* C49D0 8012E2D0 AFA200B0 */  sw        $v0, 0xb0($sp)
/* C49D4 8012E2D4 25A20008 */  addiu     $v0, $t5, 8
/* C49D8 8012E2D8 00021080 */  sll       $v0, $v0, 2
/* C49DC 8012E2DC 01D02021 */  addu      $a0, $t6, $s0
/* C49E0 8012E2E0 0804B8C4 */  j         .L8012E310
/* C49E4 8012E2E4 2484FFF0 */   addiu    $a0, $a0, -0x10
.L8012E2E8:
/* C49E8 8012E2E8 2C420007 */  sltiu     $v0, $v0, 7
/* C49EC 8012E2EC 10400015 */  beqz      $v0, .L8012E344
/* C49F0 8012E2F0 000D1080 */   sll      $v0, $t5, 2
/* C49F4 8012E2F4 25C50008 */  addiu     $a1, $t6, 8
/* C49F8 8012E2F8 00052880 */  sll       $a1, $a1, 2
/* C49FC 8012E2FC AFA200B0 */  sw        $v0, 0xb0($sp)
/* C4A00 8012E300 25A20008 */  addiu     $v0, $t5, 8
/* C4A04 8012E304 00021080 */  sll       $v0, $v0, 2
/* C4A08 8012E308 01D02021 */  addu      $a0, $t6, $s0
/* C4A0C 8012E30C 2484FFF8 */  addiu     $a0, $a0, -8
.L8012E310:
/* C4A10 8012E310 00042080 */  sll       $a0, $a0, 2
/* C4A14 8012E314 01B91821 */  addu      $v1, $t5, $t9
/* C4A18 8012E318 AFA200B8 */  sw        $v0, 0xb8($sp)
/* C4A1C 8012E31C 2462FFF8 */  addiu     $v0, $v1, -8
/* C4A20 8012E320 00021080 */  sll       $v0, $v0, 2
/* C4A24 8012E324 00031880 */  sll       $v1, $v1, 2
/* C4A28 8012E328 AFA500B4 */  sw        $a1, 0xb4($sp)
/* C4A2C 8012E32C AFA400BC */  sw        $a0, 0xbc($sp)
/* C4A30 8012E330 AFA200C0 */  sw        $v0, 0xc0($sp)
/* C4A34 8012E334 AFA500C4 */  sw        $a1, 0xc4($sp)
/* C4A38 8012E338 AFA300C8 */  sw        $v1, 0xc8($sp)
/* C4A3C 8012E33C 0804B8D4 */  j         .L8012E350
/* C4A40 8012E340 AFA400CC */   sw       $a0, 0xcc($sp)
.L8012E344:
/* C4A44 8012E344 24022710 */  addiu     $v0, $zero, 0x2710
/* C4A48 8012E348 AFA200B0 */  sw        $v0, 0xb0($sp)
/* C4A4C 8012E34C AFA200C0 */  sw        $v0, 0xc0($sp)
.L8012E350:
/* C4A50 8012E350 2B220018 */  slti      $v0, $t9, 0x18
/* C4A54 8012E354 14400022 */  bnez      $v0, .L8012E3E0
/* C4A58 8012E358 24022710 */   addiu    $v0, $zero, 0x2710
/* C4A5C 8012E35C 25A40008 */  addiu     $a0, $t5, 8
/* C4A60 8012E360 00042080 */  sll       $a0, $a0, 2
/* C4A64 8012E364 000E3880 */  sll       $a3, $t6, 2
/* C4A68 8012E368 25A60010 */  addiu     $a2, $t5, 0x10
/* C4A6C 8012E36C 00063080 */  sll       $a2, $a2, 2
/* C4A70 8012E370 25C20008 */  addiu     $v0, $t6, 8
/* C4A74 8012E374 00021080 */  sll       $v0, $v0, 2
/* C4A78 8012E378 01B91821 */  addu      $v1, $t5, $t9
/* C4A7C 8012E37C 2465FFF0 */  addiu     $a1, $v1, -0x10
/* C4A80 8012E380 00052880 */  sll       $a1, $a1, 2
/* C4A84 8012E384 2463FFF8 */  addiu     $v1, $v1, -8
/* C4A88 8012E388 00031880 */  sll       $v1, $v1, 2
/* C4A8C 8012E38C AFA40050 */  sw        $a0, 0x50($sp)
/* C4A90 8012E390 AFA40100 */  sw        $a0, 0x100($sp)
/* C4A94 8012E394 01D02021 */  addu      $a0, $t6, $s0
/* C4A98 8012E398 AFA2005C */  sw        $v0, 0x5c($sp)
/* C4A9C 8012E39C AFA2007C */  sw        $v0, 0x7c($sp)
/* C4AA0 8012E3A0 2482FFF8 */  addiu     $v0, $a0, -8
/* C4AA4 8012E3A4 00021080 */  sll       $v0, $v0, 2
/* C4AA8 8012E3A8 00042080 */  sll       $a0, $a0, 2
/* C4AAC 8012E3AC AFA70054 */  sw        $a3, 0x54($sp)
/* C4AB0 8012E3B0 AFA60058 */  sw        $a2, 0x58($sp)
/* C4AB4 8012E3B4 AFA50070 */  sw        $a1, 0x70($sp)
/* C4AB8 8012E3B8 AFA70074 */  sw        $a3, 0x74($sp)
/* C4ABC 8012E3BC AFA30078 */  sw        $v1, 0x78($sp)
/* C4AC0 8012E3C0 AFA20104 */  sw        $v0, 0x104($sp)
/* C4AC4 8012E3C4 AFA60108 */  sw        $a2, 0x108($sp)
/* C4AC8 8012E3C8 AFA4010C */  sw        $a0, 0x10c($sp)
/* C4ACC 8012E3CC AFA50120 */  sw        $a1, 0x120($sp)
/* C4AD0 8012E3D0 AFA20124 */  sw        $v0, 0x124($sp)
/* C4AD4 8012E3D4 AFA30128 */  sw        $v1, 0x128($sp)
/* C4AD8 8012E3D8 0804B8FC */  j         .L8012E3F0
/* C4ADC 8012E3DC AFA4012C */   sw       $a0, 0x12c($sp)
.L8012E3E0:
/* C4AE0 8012E3E0 AFA20050 */  sw        $v0, 0x50($sp)
/* C4AE4 8012E3E4 AFA20070 */  sw        $v0, 0x70($sp)
/* C4AE8 8012E3E8 AFA20100 */  sw        $v0, 0x100($sp)
/* C4AEC 8012E3EC AFA20120 */  sw        $v0, 0x120($sp)
.L8012E3F0:
/* C4AF0 8012E3F0 2A020018 */  slti      $v0, $s0, 0x18
/* C4AF4 8012E3F4 14400022 */  bnez      $v0, .L8012E480
/* C4AF8 8012E3F8 24022710 */   addiu    $v0, $zero, 0x2710
/* C4AFC 8012E3FC 000D3880 */  sll       $a3, $t5, 2
/* C4B00 8012E400 25C30008 */  addiu     $v1, $t6, 8
/* C4B04 8012E404 00031880 */  sll       $v1, $v1, 2
/* C4B08 8012E408 25A60008 */  addiu     $a2, $t5, 8
/* C4B0C 8012E40C 00063080 */  sll       $a2, $a2, 2
/* C4B10 8012E410 25C20010 */  addiu     $v0, $t6, 0x10
/* C4B14 8012E414 00021080 */  sll       $v0, $v0, 2
/* C4B18 8012E418 01B92021 */  addu      $a0, $t5, $t9
/* C4B1C 8012E41C 2485FFF8 */  addiu     $a1, $a0, -8
/* C4B20 8012E420 00052880 */  sll       $a1, $a1, 2
/* C4B24 8012E424 00042080 */  sll       $a0, $a0, 2
/* C4B28 8012E428 AFA2009C */  sw        $v0, 0x9c($sp)
/* C4B2C 8012E42C AFA200AC */  sw        $v0, 0xac($sp)
/* C4B30 8012E430 01D01021 */  addu      $v0, $t6, $s0
/* C4B34 8012E434 AFA30094 */  sw        $v1, 0x94($sp)
/* C4B38 8012E438 AFA300A4 */  sw        $v1, 0xa4($sp)
/* C4B3C 8012E43C 2443FFF0 */  addiu     $v1, $v0, -0x10
/* C4B40 8012E440 00031880 */  sll       $v1, $v1, 2
/* C4B44 8012E444 2442FFF8 */  addiu     $v0, $v0, -8
/* C4B48 8012E448 00021080 */  sll       $v0, $v0, 2
/* C4B4C 8012E44C AFA70090 */  sw        $a3, 0x90($sp)
/* C4B50 8012E450 AFA60098 */  sw        $a2, 0x98($sp)
/* C4B54 8012E454 AFA500A0 */  sw        $a1, 0xa0($sp)
/* C4B58 8012E458 AFA400A8 */  sw        $a0, 0xa8($sp)
/* C4B5C 8012E45C AFA700D0 */  sw        $a3, 0xd0($sp)
/* C4B60 8012E460 AFA300D4 */  sw        $v1, 0xd4($sp)
/* C4B64 8012E464 AFA600D8 */  sw        $a2, 0xd8($sp)
/* C4B68 8012E468 AFA200DC */  sw        $v0, 0xdc($sp)
/* C4B6C 8012E46C AFA500E0 */  sw        $a1, 0xe0($sp)
/* C4B70 8012E470 AFA300E4 */  sw        $v1, 0xe4($sp)
/* C4B74 8012E474 AFA400E8 */  sw        $a0, 0xe8($sp)
/* C4B78 8012E478 0804B925 */  j         .L8012E494
/* C4B7C 8012E47C AFA200EC */   sw       $v0, 0xec($sp)
.L8012E480:
/* C4B80 8012E480 AFA20090 */  sw        $v0, 0x90($sp)
/* C4B84 8012E484 AFA200A0 */  sw        $v0, 0xa0($sp)
/* C4B88 8012E488 AFA200D0 */  sw        $v0, 0xd0($sp)
/* C4B8C 8012E48C AFA200E0 */  sw        $v0, 0xe0($sp)
/* C4B90 8012E490 000D3880 */  sll       $a3, $t5, 2
.L8012E494:
/* C4B94 8012E494 000E1880 */  sll       $v1, $t6, 2
/* C4B98 8012E498 25A60008 */  addiu     $a2, $t5, 8
/* C4B9C 8012E49C 00063080 */  sll       $a2, $a2, 2
/* C4BA0 8012E4A0 25C20008 */  addiu     $v0, $t6, 8
/* C4BA4 8012E4A4 00021080 */  sll       $v0, $v0, 2
/* C4BA8 8012E4A8 01B92021 */  addu      $a0, $t5, $t9
/* C4BAC 8012E4AC 2485FFF8 */  addiu     $a1, $a0, -8
/* C4BB0 8012E4B0 00052880 */  sll       $a1, $a1, 2
/* C4BB4 8012E4B4 00042080 */  sll       $a0, $a0, 2
/* C4BB8 8012E4B8 AFA30044 */  sw        $v1, 0x44($sp)
/* C4BBC 8012E4BC AFA30084 */  sw        $v1, 0x84($sp)
/* C4BC0 8012E4C0 01D01821 */  addu      $v1, $t6, $s0
/* C4BC4 8012E4C4 AFA2004C */  sw        $v0, 0x4c($sp)
/* C4BC8 8012E4C8 AFA2008C */  sw        $v0, 0x8c($sp)
/* C4BCC 8012E4CC 2462FFF8 */  addiu     $v0, $v1, -8
/* C4BD0 8012E4D0 00021080 */  sll       $v0, $v0, 2
/* C4BD4 8012E4D4 00031880 */  sll       $v1, $v1, 2
/* C4BD8 8012E4D8 AFA200F4 */  sw        $v0, 0xf4($sp)
/* C4BDC 8012E4DC AFA20134 */  sw        $v0, 0x134($sp)
/* C4BE0 8012E4E0 24020005 */  addiu     $v0, $zero, 5
/* C4BE4 8012E4E4 AFA70040 */  sw        $a3, 0x40($sp)
/* C4BE8 8012E4E8 AFA60048 */  sw        $a2, 0x48($sp)
/* C4BEC 8012E4EC AFA50080 */  sw        $a1, 0x80($sp)
/* C4BF0 8012E4F0 AFA40088 */  sw        $a0, 0x88($sp)
/* C4BF4 8012E4F4 AFA700F0 */  sw        $a3, 0xf0($sp)
/* C4BF8 8012E4F8 AFA600F8 */  sw        $a2, 0xf8($sp)
/* C4BFC 8012E4FC AFA300FC */  sw        $v1, 0xfc($sp)
/* C4C00 8012E500 AFA50130 */  sw        $a1, 0x130($sp)
/* C4C04 8012E504 AFA40138 */  sw        $a0, 0x138($sp)
/* C4C08 8012E508 12420006 */  beq       $s2, $v0, .L8012E524
/* C4C0C 8012E50C AFA3013C */   sw       $v1, 0x13c($sp)
/* C4C10 8012E510 24020006 */  addiu     $v0, $zero, 6
/* C4C14 8012E514 16420004 */  bne       $s2, $v0, .L8012E528
/* C4C18 8012E518 0000102D */   daddu    $v0, $zero, $zero
/* C4C1C 8012E51C 0804B94A */  j         .L8012E528
/* C4C20 8012E520 24020001 */   addiu    $v0, $zero, 1
.L8012E524:
/* C4C24 8012E524 0000102D */  daddu     $v0, $zero, $zero
.L8012E528:
/* C4C28 8012E528 0000702D */  daddu     $t6, $zero, $zero
/* C4C2C 8012E52C 3C058009 */  lui       $a1, %hi(D_8008FEE0)
/* C4C30 8012E530 24A5FEE0 */  addiu     $a1, $a1, %lo(D_8008FEE0)
/* C4C34 8012E534 03A0202D */  daddu     $a0, $sp, $zero
/* C4C38 8012E538 00021980 */  sll       $v1, $v0, 6
.L8012E53C:
/* C4C3C 8012E53C 00651021 */  addu      $v0, $v1, $a1
/* C4C40 8012E540 24630004 */  addiu     $v1, $v1, 4
/* C4C44 8012E544 8C420000 */  lw        $v0, ($v0)
/* C4C48 8012E548 25CE0001 */  addiu     $t6, $t6, 1
/* C4C4C 8012E54C AC820000 */  sw        $v0, ($a0)
/* C4C50 8012E550 29C20010 */  slti      $v0, $t6, 0x10
/* C4C54 8012E554 1440FFF9 */  bnez      $v0, .L8012E53C
/* C4C58 8012E558 24840004 */   addiu    $a0, $a0, 4
/* C4C5C 8012E55C 52600001 */  beql      $s3, $zero, .L8012E564
/* C4C60 8012E560 241100FF */   addiu    $s1, $zero, 0xff
.L8012E564:
/* C4C64 8012E564 3C06E200 */  lui       $a2, 0xe200
/* C4C68 8012E568 34C6001C */  ori       $a2, $a2, 0x1c
/* C4C6C 8012E56C 3C040050 */  lui       $a0, 0x50
/* C4C70 8012E570 34844240 */  ori       $a0, $a0, 0x4240
/* C4C74 8012E574 3C07FCFF */  lui       $a3, 0xfcff
/* C4C78 8012E578 34E797FF */  ori       $a3, $a3, 0x97ff
/* C4C7C 8012E57C 3C05FF2C */  lui       $a1, 0xff2c
/* C4C80 8012E580 34A5FE7F */  ori       $a1, $a1, 0xfe7f
/* C4C84 8012E584 3C08E300 */  lui       $t0, 0xe300
/* C4C88 8012E588 35081001 */  ori       $t0, $t0, 0x1001
/* C4C8C 8012E58C 3C0AF500 */  lui       $t2, 0xf500
/* C4C90 8012E590 354A0100 */  ori       $t2, $t2, 0x100
/* C4C94 8012E594 3C0B0703 */  lui       $t3, 0x703
/* C4C98 8012E598 356BC000 */  ori       $t3, $t3, 0xc000
/* C4C9C 8012E59C 0000702D */  daddu     $t6, $zero, $zero
/* C4CA0 8012E5A0 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* C4CA4 8012E5A4 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* C4CA8 8012E5A8 0040602D */  daddu     $t4, $v0, $zero
/* C4CAC 8012E5AC 27AD0040 */  addiu     $t5, $sp, 0x40
/* C4CB0 8012E5B0 03A0782D */  daddu     $t7, $sp, $zero
/* C4CB4 8012E5B4 8D830000 */  lw        $v1, ($t4)
/* C4CB8 8012E5B8 3C09E700 */  lui       $t1, 0xe700
/* C4CBC 8012E5BC 0060102D */  daddu     $v0, $v1, $zero
/* C4CC0 8012E5C0 24630008 */  addiu     $v1, $v1, 8
/* C4CC4 8012E5C4 AD830000 */  sw        $v1, ($t4)
/* C4CC8 8012E5C8 AC490000 */  sw        $t1, ($v0)
/* C4CCC 8012E5CC AC400004 */  sw        $zero, 4($v0)
/* C4CD0 8012E5D0 24620008 */  addiu     $v0, $v1, 8
/* C4CD4 8012E5D4 AD820000 */  sw        $v0, ($t4)
/* C4CD8 8012E5D8 24620010 */  addiu     $v0, $v1, 0x10
/* C4CDC 8012E5DC AC660000 */  sw        $a2, ($v1)
/* C4CE0 8012E5E0 AC640004 */  sw        $a0, 4($v1)
/* C4CE4 8012E5E4 AD820000 */  sw        $v0, ($t4)
/* C4CE8 8012E5E8 24620018 */  addiu     $v0, $v1, 0x18
/* C4CEC 8012E5EC AC670008 */  sw        $a3, 8($v1)
/* C4CF0 8012E5F0 AC65000C */  sw        $a1, 0xc($v1)
/* C4CF4 8012E5F4 AD820000 */  sw        $v0, ($t4)
/* C4CF8 8012E5F8 3C02FA00 */  lui       $v0, 0xfa00
/* C4CFC 8012E5FC AC620010 */  sw        $v0, 0x10($v1)
/* C4D00 8012E600 322200FF */  andi      $v0, $s1, 0xff
/* C4D04 8012E604 AC620014 */  sw        $v0, 0x14($v1)
/* C4D08 8012E608 24620020 */  addiu     $v0, $v1, 0x20
/* C4D0C 8012E60C AD820000 */  sw        $v0, ($t4)
/* C4D10 8012E610 34028000 */  ori       $v0, $zero, 0x8000
/* C4D14 8012E614 AC62001C */  sw        $v0, 0x1c($v1)
/* C4D18 8012E618 24620028 */  addiu     $v0, $v1, 0x28
/* C4D1C 8012E61C AC680018 */  sw        $t0, 0x18($v1)
/* C4D20 8012E620 AD820000 */  sw        $v0, ($t4)
/* C4D24 8012E624 3C02FD10 */  lui       $v0, 0xfd10
/* C4D28 8012E628 AC620020 */  sw        $v0, 0x20($v1)
/* C4D2C 8012E62C 8FA20164 */  lw        $v0, 0x164($sp)
/* C4D30 8012E630 3C04802F */  lui       $a0, %hi(D_802EC3F0)
/* C4D34 8012E634 2484C3F0 */  addiu     $a0, $a0, %lo(D_802EC3F0)
/* C4D38 8012E638 00021140 */  sll       $v0, $v0, 5
/* C4D3C 8012E63C 00441021 */  addu      $v0, $v0, $a0
/* C4D40 8012E640 AC620024 */  sw        $v0, 0x24($v1)
/* C4D44 8012E644 24620030 */  addiu     $v0, $v1, 0x30
/* C4D48 8012E648 AD820000 */  sw        $v0, ($t4)
/* C4D4C 8012E64C 3C02E800 */  lui       $v0, 0xe800
/* C4D50 8012E650 AC620028 */  sw        $v0, 0x28($v1)
/* C4D54 8012E654 24620038 */  addiu     $v0, $v1, 0x38
/* C4D58 8012E658 AC60002C */  sw        $zero, 0x2c($v1)
/* C4D5C 8012E65C AD820000 */  sw        $v0, ($t4)
/* C4D60 8012E660 3C020700 */  lui       $v0, 0x700
/* C4D64 8012E664 AC620034 */  sw        $v0, 0x34($v1)
/* C4D68 8012E668 24620040 */  addiu     $v0, $v1, 0x40
/* C4D6C 8012E66C AC6A0030 */  sw        $t2, 0x30($v1)
/* C4D70 8012E670 AD820000 */  sw        $v0, ($t4)
/* C4D74 8012E674 3C02E600 */  lui       $v0, 0xe600
/* C4D78 8012E678 AC620038 */  sw        $v0, 0x38($v1)
/* C4D7C 8012E67C 24620048 */  addiu     $v0, $v1, 0x48
/* C4D80 8012E680 AC60003C */  sw        $zero, 0x3c($v1)
/* C4D84 8012E684 AD820000 */  sw        $v0, ($t4)
/* C4D88 8012E688 3C02F000 */  lui       $v0, 0xf000
/* C4D8C 8012E68C AC620040 */  sw        $v0, 0x40($v1)
/* C4D90 8012E690 24620050 */  addiu     $v0, $v1, 0x50
/* C4D94 8012E694 AC6B0044 */  sw        $t3, 0x44($v1)
/* C4D98 8012E698 AD820000 */  sw        $v0, ($t4)
/* C4D9C 8012E69C AC690048 */  sw        $t1, 0x48($v1)
/* C4DA0 8012E6A0 AC60004C */  sw        $zero, 0x4c($v1)
.L8012E6A4:
/* C4DA4 8012E6A4 8DE20000 */  lw        $v0, ($t7)
/* C4DA8 8012E6A8 50400074 */  beql      $v0, $zero, .L8012E87C
/* C4DAC 8012E6AC 25AD0010 */   addiu    $t5, $t5, 0x10
/* C4DB0 8012E6B0 8DA20000 */  lw        $v0, ($t5)
/* C4DB4 8012E6B4 28422710 */  slti      $v0, $v0, 0x2710
/* C4DB8 8012E6B8 1040006F */  beqz      $v0, .L8012E878
/* C4DBC 8012E6BC 3C02FD48 */   lui      $v0, 0xfd48
/* C4DC0 8012E6C0 34420003 */  ori       $v0, $v0, 3
/* C4DC4 8012E6C4 3C08F548 */  lui       $t0, 0xf548
/* C4DC8 8012E6C8 35080200 */  ori       $t0, $t0, 0x200
/* C4DCC 8012E6CC 3C070700 */  lui       $a3, 0x700
/* C4DD0 8012E6D0 34E7C030 */  ori       $a3, $a3, 0xc030
/* C4DD4 8012E6D4 3C090700 */  lui       $t1, 0x700
/* C4DD8 8012E6D8 3529E01C */  ori       $t1, $t1, 0xe01c
/* C4DDC 8012E6DC 3C0AF540 */  lui       $t2, 0xf540
/* C4DE0 8012E6E0 354A0200 */  ori       $t2, $t2, 0x200
/* C4DE4 8012E6E4 3C0B0001 */  lui       $t3, 1
/* C4DE8 8012E6E8 8D830000 */  lw        $v1, ($t4)
/* C4DEC 8012E6EC 356BC01C */  ori       $t3, $t3, 0xc01c
/* C4DF0 8012E6F0 0060282D */  daddu     $a1, $v1, $zero
/* C4DF4 8012E6F4 24630008 */  addiu     $v1, $v1, 8
/* C4DF8 8012E6F8 AD830000 */  sw        $v1, ($t4)
/* C4DFC 8012E6FC ACA20000 */  sw        $v0, ($a1)
/* C4E00 8012E700 24620008 */  addiu     $v0, $v1, 8
/* C4E04 8012E704 AD820000 */  sw        $v0, ($t4)
/* C4E08 8012E708 24620010 */  addiu     $v0, $v1, 0x10
/* C4E0C 8012E70C AD820000 */  sw        $v0, ($t4)
/* C4E10 8012E710 24620018 */  addiu     $v0, $v1, 0x18
/* C4E14 8012E714 AD820000 */  sw        $v0, ($t4)
/* C4E18 8012E718 24620020 */  addiu     $v0, $v1, 0x20
/* C4E1C 8012E71C AD820000 */  sw        $v0, ($t4)
/* C4E20 8012E720 24620028 */  addiu     $v0, $v1, 0x28
/* C4E24 8012E724 24660030 */  addiu     $a2, $v1, 0x30
/* C4E28 8012E728 AD820000 */  sw        $v0, ($t4)
/* C4E2C 8012E72C AD860000 */  sw        $a2, ($t4)
/* C4E30 8012E730 8DE40000 */  lw        $a0, ($t7)
/* C4E34 8012E734 24620038 */  addiu     $v0, $v1, 0x38
/* C4E38 8012E738 AD820000 */  sw        $v0, ($t4)
/* C4E3C 8012E73C 3C02E600 */  lui       $v0, 0xe600
/* C4E40 8012E740 ACA40004 */  sw        $a0, 4($a1)
/* C4E44 8012E744 AC620008 */  sw        $v0, 8($v1)
/* C4E48 8012E748 3C02F400 */  lui       $v0, 0xf400
/* C4E4C 8012E74C AC620010 */  sw        $v0, 0x10($v1)
/* C4E50 8012E750 3C02E700 */  lui       $v0, 0xe700
/* C4E54 8012E754 AC620018 */  sw        $v0, 0x18($v1)
/* C4E58 8012E758 3402C030 */  ori       $v0, $zero, 0xc030
/* C4E5C 8012E75C AC620024 */  sw        $v0, 0x24($v1)
/* C4E60 8012E760 3C02F200 */  lui       $v0, 0xf200
/* C4E64 8012E764 AC680000 */  sw        $t0, ($v1)
/* C4E68 8012E768 AC670004 */  sw        $a3, 4($v1)
/* C4E6C 8012E76C AC60000C */  sw        $zero, 0xc($v1)
/* C4E70 8012E770 AC690014 */  sw        $t1, 0x14($v1)
/* C4E74 8012E774 AC60001C */  sw        $zero, 0x1c($v1)
/* C4E78 8012E778 AC6A0020 */  sw        $t2, 0x20($v1)
/* C4E7C 8012E77C AC620028 */  sw        $v0, 0x28($v1)
/* C4E80 8012E780 AC6B002C */  sw        $t3, 0x2c($v1)
/* C4E84 8012E784 85A2000A */  lh        $v0, 0xa($t5)
/* C4E88 8012E788 18400005 */  blez      $v0, .L8012E7A0
/* C4E8C 8012E78C 30420FFF */   andi     $v0, $v0, 0xfff
/* C4E90 8012E790 00021300 */  sll       $v0, $v0, 0xc
/* C4E94 8012E794 3C03E400 */  lui       $v1, 0xe400
/* C4E98 8012E798 0804B9E9 */  j         .L8012E7A4
/* C4E9C 8012E79C 00431825 */   or       $v1, $v0, $v1
.L8012E7A0:
/* C4EA0 8012E7A0 3C03E400 */  lui       $v1, 0xe400
.L8012E7A4:
/* C4EA4 8012E7A4 85A2000E */  lh        $v0, 0xe($t5)
/* C4EA8 8012E7A8 18400002 */  blez      $v0, .L8012E7B4
/* C4EAC 8012E7AC 30420FFF */   andi     $v0, $v0, 0xfff
/* C4EB0 8012E7B0 00621825 */  or        $v1, $v1, $v0
.L8012E7B4:
/* C4EB4 8012E7B4 ACC30000 */  sw        $v1, ($a2)
/* C4EB8 8012E7B8 85A20002 */  lh        $v0, 2($t5)
/* C4EBC 8012E7BC 18400004 */  blez      $v0, .L8012E7D0
/* C4EC0 8012E7C0 24C60004 */   addiu    $a2, $a2, 4
/* C4EC4 8012E7C4 30420FFF */  andi      $v0, $v0, 0xfff
/* C4EC8 8012E7C8 0804B9F5 */  j         .L8012E7D4
/* C4ECC 8012E7CC 00021B00 */   sll      $v1, $v0, 0xc
.L8012E7D0:
/* C4ED0 8012E7D0 0000182D */  daddu     $v1, $zero, $zero
.L8012E7D4:
/* C4ED4 8012E7D4 85A20006 */  lh        $v0, 6($t5)
/* C4ED8 8012E7D8 18400002 */  blez      $v0, .L8012E7E4
/* C4EDC 8012E7DC 30420FFF */   andi     $v0, $v0, 0xfff
/* C4EE0 8012E7E0 00621825 */  or        $v1, $v1, $v0
.L8012E7E4:
/* C4EE4 8012E7E4 8D820000 */  lw        $v0, ($t4)
/* C4EE8 8012E7E8 ACC30000 */  sw        $v1, ($a2)
/* C4EEC 8012E7EC 0040182D */  daddu     $v1, $v0, $zero
/* C4EF0 8012E7F0 24420008 */  addiu     $v0, $v0, 8
/* C4EF4 8012E7F4 AD820000 */  sw        $v0, ($t4)
/* C4EF8 8012E7F8 3C02E100 */  lui       $v0, 0xe100
/* C4EFC 8012E7FC AC620000 */  sw        $v0, ($v1)
/* C4F00 8012E800 85A20002 */  lh        $v0, 2($t5)
/* C4F04 8012E804 04410007 */  bgez      $v0, .L8012E824
/* C4F08 8012E808 24630004 */   addiu    $v1, $v1, 4
/* C4F0C 8012E80C 000210C0 */  sll       $v0, $v0, 3
/* C4F10 8012E810 5C400001 */  bgtzl     $v0, .L8012E818
/* C4F14 8012E814 0000102D */   daddu    $v0, $zero, $zero
.L8012E818:
/* C4F18 8012E818 00021023 */  negu      $v0, $v0
/* C4F1C 8012E81C 0804BA0A */  j         .L8012E828
/* C4F20 8012E820 00022400 */   sll      $a0, $v0, 0x10
.L8012E824:
/* C4F24 8012E824 0000202D */  daddu     $a0, $zero, $zero
.L8012E828:
/* C4F28 8012E828 8DA20004 */  lw        $v0, 4($t5)
/* C4F2C 8012E82C 04410008 */  bgez      $v0, .L8012E850
/* C4F30 8012E830 0080282D */   daddu    $a1, $a0, $zero
/* C4F34 8012E834 85A20006 */  lh        $v0, 6($t5)
/* C4F38 8012E838 000210C0 */  sll       $v0, $v0, 3
/* C4F3C 8012E83C 5C400001 */  bgtzl     $v0, .L8012E844
/* C4F40 8012E840 0000102D */   daddu    $v0, $zero, $zero
.L8012E844:
/* C4F44 8012E844 00021023 */  negu      $v0, $v0
/* C4F48 8012E848 3042FFFF */  andi      $v0, $v0, 0xffff
/* C4F4C 8012E84C 00A22825 */  or        $a1, $a1, $v0
.L8012E850:
/* C4F50 8012E850 3C040400 */  lui       $a0, 0x400
/* C4F54 8012E854 8D820000 */  lw        $v0, ($t4)
/* C4F58 8012E858 34840400 */  ori       $a0, $a0, 0x400
/* C4F5C 8012E85C AC650000 */  sw        $a1, ($v1)
/* C4F60 8012E860 0040182D */  daddu     $v1, $v0, $zero
/* C4F64 8012E864 24420008 */  addiu     $v0, $v0, 8
/* C4F68 8012E868 AD820000 */  sw        $v0, ($t4)
/* C4F6C 8012E86C 3C02F100 */  lui       $v0, 0xf100
/* C4F70 8012E870 AC620000 */  sw        $v0, ($v1)
/* C4F74 8012E874 AC640004 */  sw        $a0, 4($v1)
.L8012E878:
/* C4F78 8012E878 25AD0010 */  addiu     $t5, $t5, 0x10
.L8012E87C:
/* C4F7C 8012E87C 25CE0001 */  addiu     $t6, $t6, 1
/* C4F80 8012E880 29C20010 */  slti      $v0, $t6, 0x10
/* C4F84 8012E884 1440FF87 */  bnez      $v0, .L8012E6A4
/* C4F88 8012E888 25EF0004 */   addiu    $t7, $t7, 4
/* C4F8C 8012E88C 3C06E300 */  lui       $a2, 0xe300
/* C4F90 8012E890 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* C4F94 8012E894 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* C4F98 8012E898 34C61001 */  ori       $a2, $a2, 0x1001
/* C4F9C 8012E89C 8C820000 */  lw        $v0, ($a0)
/* C4FA0 8012E8A0 3C03E700 */  lui       $v1, 0xe700
/* C4FA4 8012E8A4 0040282D */  daddu     $a1, $v0, $zero
/* C4FA8 8012E8A8 24420008 */  addiu     $v0, $v0, 8
/* C4FAC 8012E8AC AC820000 */  sw        $v0, ($a0)
/* C4FB0 8012E8B0 ACA30000 */  sw        $v1, ($a1)
/* C4FB4 8012E8B4 24430008 */  addiu     $v1, $v0, 8
/* C4FB8 8012E8B8 ACA00004 */  sw        $zero, 4($a1)
/* C4FBC 8012E8BC AC830000 */  sw        $v1, ($a0)
/* C4FC0 8012E8C0 AC460000 */  sw        $a2, ($v0)
/* C4FC4 8012E8C4 AC400004 */  sw        $zero, 4($v0)
.L8012E8C8:
/* C4FC8 8012E8C8 8FB3014C */  lw        $s3, 0x14c($sp)
/* C4FCC 8012E8CC 8FB20148 */  lw        $s2, 0x148($sp)
/* C4FD0 8012E8D0 8FB10144 */  lw        $s1, 0x144($sp)
/* C4FD4 8012E8D4 8FB00140 */  lw        $s0, 0x140($sp)
/* C4FD8 8012E8D8 03E00008 */  jr        $ra
/* C4FDC 8012E8DC 27BD0150 */   addiu    $sp, $sp, 0x150
