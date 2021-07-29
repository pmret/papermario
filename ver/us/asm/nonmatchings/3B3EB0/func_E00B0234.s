.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00B0234
/* 3B40E4 E00B0234 27BDFF10 */  addiu     $sp, $sp, -0xf0
/* 3B40E8 E00B0238 0080402D */  daddu     $t0, $a0, $zero
/* 3B40EC E00B023C 3C09DB06 */  lui       $t1, 0xdb06
/* 3B40F0 E00B0240 35290024 */  ori       $t1, $t1, 0x24
/* 3B40F4 E00B0244 27A40020 */  addiu     $a0, $sp, 0x20
/* 3B40F8 E00B0248 AFB000B0 */  sw        $s0, 0xb0($sp)
/* 3B40FC E00B024C 3C100001 */  lui       $s0, 1
/* 3B4100 E00B0250 36101630 */  ori       $s0, $s0, 0x1630
/* 3B4104 E00B0254 AFB100B4 */  sw        $s1, 0xb4($sp)
/* 3B4108 E00B0258 0000882D */  daddu     $s1, $zero, $zero
/* 3B410C E00B025C AFB400C0 */  sw        $s4, 0xc0($sp)
/* 3B4110 E00B0260 27B40060 */  addiu     $s4, $sp, 0x60
/* 3B4114 E00B0264 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* 3B4118 E00B0268 244241F0 */  addiu     $v0, $v0, %lo(gMatrixListPos)
/* 3B411C E00B026C AFB500C4 */  sw        $s5, 0xc4($sp)
/* 3B4120 E00B0270 0040A82D */  daddu     $s5, $v0, $zero
/* 3B4124 E00B0274 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 3B4128 E00B0278 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 3B412C E00B027C AFB200B8 */  sw        $s2, 0xb8($sp)
/* 3B4130 E00B0280 0040902D */  daddu     $s2, $v0, $zero
/* 3B4134 E00B0284 3C02E700 */  lui       $v0, 0xe700
/* 3B4138 E00B0288 AFBF00D4 */  sw        $ra, 0xd4($sp)
/* 3B413C E00B028C AFBE00D0 */  sw        $fp, 0xd0($sp)
/* 3B4140 E00B0290 AFB700CC */  sw        $s7, 0xcc($sp)
/* 3B4144 E00B0294 AFB600C8 */  sw        $s6, 0xc8($sp)
/* 3B4148 E00B0298 AFB300BC */  sw        $s3, 0xbc($sp)
/* 3B414C E00B029C F7B800E8 */  sdc1      $f24, 0xe8($sp)
/* 3B4150 E00B02A0 F7B600E0 */  sdc1      $f22, 0xe0($sp)
/* 3B4154 E00B02A4 F7B400D8 */  sdc1      $f20, 0xd8($sp)
/* 3B4158 E00B02A8 8E460000 */  lw        $a2, ($s2)
/* 3B415C E00B02AC 44800000 */  mtc1      $zero, $f0
/* 3B4160 E00B02B0 8D13000C */  lw        $s3, 0xc($t0)
/* 3B4164 E00B02B4 3C013F80 */  lui       $at, 0x3f80
/* 3B4168 E00B02B8 4481C000 */  mtc1      $at, $f24
/* 3B416C E00B02BC 44050000 */  mfc1      $a1, $f0
/* 3B4170 E00B02C0 8E6A0014 */  lw        $t2, 0x14($s3)
/* 3B4174 E00B02C4 00C0182D */  daddu     $v1, $a2, $zero
/* 3B4178 E00B02C8 AFAA00A0 */  sw        $t2, 0xa0($sp)
/* 3B417C E00B02CC 8E6A0024 */  lw        $t2, 0x24($s3)
/* 3B4180 E00B02D0 4485A000 */  mtc1      $a1, $f20
/* 3B4184 E00B02D4 24C60008 */  addiu     $a2, $a2, 8
/* 3B4188 E00B02D8 AFAA00A4 */  sw        $t2, 0xa4($sp)
/* 3B418C E00B02DC AC620000 */  sw        $v0, ($v1)
/* 3B4190 E00B02E0 AC600004 */  sw        $zero, 4($v1)
/* 3B4194 E00B02E4 ACC90000 */  sw        $t1, ($a2)
/* 3B4198 E00B02E8 8D020010 */  lw        $v0, 0x10($t0)
/* 3B419C E00B02EC 3C088000 */  lui       $t0, 0x8000
/* 3B41A0 E00B02F0 8C42001C */  lw        $v0, 0x1c($v0)
/* 3B41A4 E00B02F4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3B41A8 E00B02F8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3B41AC E00B02FC 00481021 */  addu      $v0, $v0, $t0
/* 3B41B0 E00B0300 ACC20004 */  sw        $v0, 4($a2)
/* 3B41B4 E00B0304 00031080 */  sll       $v0, $v1, 2
/* 3B41B8 E00B0308 00431021 */  addu      $v0, $v0, $v1
/* 3B41BC E00B030C 00021080 */  sll       $v0, $v0, 2
/* 3B41C0 E00B0310 00431023 */  subu      $v0, $v0, $v1
/* 3B41C4 E00B0314 000218C0 */  sll       $v1, $v0, 3
/* 3B41C8 E00B0318 00431021 */  addu      $v0, $v0, $v1
/* 3B41CC E00B031C 000210C0 */  sll       $v0, $v0, 3
/* 3B41D0 E00B0320 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 3B41D4 E00B0324 00220821 */  addu      $at, $at, $v0
/* 3B41D8 E00B0328 C4221DEC */  lwc1      $f2, %lo(gCameras+0x6C)($at)
/* 3B41DC E00B032C C6600028 */  lwc1      $f0, 0x28($s3)
/* 3B41E0 E00B0330 3C1E0001 */  lui       $fp, 1
/* 3B41E4 E00B0334 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3B41E8 E00B0338 C6600004 */  lwc1      $f0, 4($s3)
/* 3B41EC E00B033C 37DE1630 */  ori       $fp, $fp, 0x1630
/* 3B41F0 E00B0340 AE460000 */  sw        $a2, ($s2)
/* 3B41F4 E00B0344 24C60008 */  addiu     $a2, $a2, 8
/* 3B41F8 E00B0348 E7A00014 */  swc1      $f0, 0x14($sp)
/* 3B41FC E00B034C C6600008 */  lwc1      $f0, 8($s3)
/* 3B4200 E00B0350 46001087 */  neg.s     $f2, $f2
/* 3B4204 E00B0354 AE460000 */  sw        $a2, ($s2)
/* 3B4208 E00B0358 44061000 */  mfc1      $a2, $f2
/* 3B420C E00B035C 2416005A */  addiu     $s6, $zero, 0x5a
/* 3B4210 E00B0360 E7A00018 */  swc1      $f0, 0x18($sp)
/* 3B4214 E00B0364 C660000C */  lwc1      $f0, 0xc($s3)
/* 3B4218 E00B0368 00A0382D */  daddu     $a3, $a1, $zero
/* 3B421C E00B036C 0C080180 */  jal       func_E0200600
/* 3B4220 E00B0370 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 3B4224 E00B0374 27A40020 */  addiu     $a0, $sp, 0x20
/* 3B4228 E00B0378 96A50000 */  lhu       $a1, ($s5)
/* 3B422C E00B037C 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 3B4230 E00B0380 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 3B4234 E00B0384 00052980 */  sll       $a1, $a1, 6
/* 3B4238 E00B0388 00B02821 */  addu      $a1, $a1, $s0
/* 3B423C E00B038C 0C080118 */  jal       func_E0200460
/* 3B4240 E00B0390 00452821 */   addu     $a1, $v0, $a1
/* 3B4244 E00B0394 3C06DA38 */  lui       $a2, 0xda38
/* 3B4248 E00B0398 8E440000 */  lw        $a0, ($s2)
/* 3B424C E00B039C 34C60002 */  ori       $a2, $a2, 2
/* 3B4250 E00B03A0 0080282D */  daddu     $a1, $a0, $zero
/* 3B4254 E00B03A4 24840008 */  addiu     $a0, $a0, 8
/* 3B4258 E00B03A8 24820008 */  addiu     $v0, $a0, 8
/* 3B425C E00B03AC 0040B82D */  daddu     $s7, $v0, $zero
/* 3B4260 E00B03B0 96A20000 */  lhu       $v0, ($s5)
/* 3B4264 E00B03B4 24830010 */  addiu     $v1, $a0, 0x10
/* 3B4268 E00B03B8 AFA300A8 */  sw        $v1, 0xa8($sp)
/* 3B426C E00B03BC AE440000 */  sw        $a0, ($s2)
/* 3B4270 E00B03C0 ACA60000 */  sw        $a2, ($a1)
/* 3B4274 E00B03C4 24430001 */  addiu     $v1, $v0, 1
/* 3B4278 E00B03C8 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3B427C E00B03CC 00021180 */  sll       $v0, $v0, 6
/* 3B4280 E00B03D0 A6A30000 */  sh        $v1, ($s5)
/* 3B4284 E00B03D4 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 3B4288 E00B03D8 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 3B428C E00B03DC 00501021 */  addu      $v0, $v0, $s0
/* 3B4290 E00B03E0 00621821 */  addu      $v1, $v1, $v0
/* 3B4294 E00B03E4 3C02DE00 */  lui       $v0, 0xde00
/* 3B4298 E00B03E8 ACA30004 */  sw        $v1, 4($a1)
/* 3B429C E00B03EC AE570000 */  sw        $s7, ($s2)
/* 3B42A0 E00B03F0 AC820000 */  sw        $v0, ($a0)
/* 3B42A4 E00B03F4 3C020900 */  lui       $v0, 0x900
/* 3B42A8 E00B03F8 24420000 */  addiu     $v0, $v0, 0
/* 3B42AC E00B03FC AC820004 */  sw        $v0, 4($a0)
/* 3B42B0 E00B0400 8FAA00A8 */  lw        $t2, 0xa8($sp)
/* 3B42B4 E00B0404 4600C586 */  mov.s     $f22, $f24
/* 3B42B8 E00B0408 AE4A0000 */  sw        $t2, ($s2)
.LE00B040C:
/* 3B42BC E00B040C 27A40020 */  addiu     $a0, $sp, 0x20
/* 3B42C0 E00B0410 44962000 */  mtc1      $s6, $f4
/* 3B42C4 E00B0414 00000000 */  nop
/* 3B42C8 E00B0418 46802120 */  cvt.s.w   $f4, $f4
/* 3B42CC E00B041C 26D60048 */  addiu     $s6, $s6, 0x48
/* 3B42D0 E00B0420 44052000 */  mfc1      $a1, $f4
/* 3B42D4 E00B0424 4406A000 */  mfc1      $a2, $f20
/* 3B42D8 E00B0428 4407A000 */  mfc1      $a3, $f20
/* 3B42DC E00B042C 26310001 */  addiu     $s1, $s1, 1
/* 3B42E0 E00B0430 0C080104 */  jal       func_E0200410
/* 3B42E4 E00B0434 E7B60010 */   swc1     $f22, 0x10($sp)
/* 3B42E8 E00B0438 4405B000 */  mfc1      $a1, $f22
/* 3B42EC E00B043C 4406C000 */  mfc1      $a2, $f24
/* 3B42F0 E00B0440 4407B000 */  mfc1      $a3, $f22
/* 3B42F4 E00B0444 0C080110 */  jal       func_E0200440
/* 3B42F8 E00B0448 0280202D */   daddu    $a0, $s4, $zero
/* 3B42FC E00B044C 0280202D */  daddu     $a0, $s4, $zero
/* 3B4300 E00B0450 27A50020 */  addiu     $a1, $sp, 0x20
/* 3B4304 E00B0454 0C080114 */  jal       func_E0200450
/* 3B4308 E00B0458 00A0302D */   daddu    $a2, $a1, $zero
/* 3B430C E00B045C 4405A000 */  mfc1      $a1, $f20
/* 3B4310 E00B0460 4406A000 */  mfc1      $a2, $f20
/* 3B4314 E00B0464 4407A000 */  mfc1      $a3, $f20
/* 3B4318 E00B0468 3C0141F0 */  lui       $at, 0x41f0
/* 3B431C E00B046C 44810000 */  mtc1      $at, $f0
/* 3B4320 E00B0470 0280202D */  daddu     $a0, $s4, $zero
/* 3B4324 E00B0474 E7B60010 */  swc1      $f22, 0x10($sp)
/* 3B4328 E00B0478 E7B40018 */  swc1      $f20, 0x18($sp)
/* 3B432C E00B047C E7B4001C */  swc1      $f20, 0x1c($sp)
/* 3B4330 E00B0480 0C080180 */  jal       func_E0200600
/* 3B4334 E00B0484 E7A00014 */   swc1     $f0, 0x14($sp)
/* 3B4338 E00B0488 0280202D */  daddu     $a0, $s4, $zero
/* 3B433C E00B048C 27A50020 */  addiu     $a1, $sp, 0x20
/* 3B4340 E00B0490 0C080114 */  jal       func_E0200450
/* 3B4344 E00B0494 00A0302D */   daddu    $a2, $a1, $zero
/* 3B4348 E00B0498 27A40020 */  addiu     $a0, $sp, 0x20
/* 3B434C E00B049C 96A50000 */  lhu       $a1, ($s5)
/* 3B4350 E00B04A0 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 3B4354 E00B04A4 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 3B4358 E00B04A8 00052980 */  sll       $a1, $a1, 6
/* 3B435C E00B04AC 00BE2821 */  addu      $a1, $a1, $fp
/* 3B4360 E00B04B0 0C080118 */  jal       func_E0200460
/* 3B4364 E00B04B4 00452821 */   addu     $a1, $v0, $a1
/* 3B4368 E00B04B8 3C06D838 */  lui       $a2, 0xd838
/* 3B436C E00B04BC 8E440000 */  lw        $a0, ($s2)
/* 3B4370 E00B04C0 34C60002 */  ori       $a2, $a2, 2
/* 3B4374 E00B04C4 0080282D */  daddu     $a1, $a0, $zero
/* 3B4378 E00B04C8 24840008 */  addiu     $a0, $a0, 8
/* 3B437C E00B04CC AE440000 */  sw        $a0, ($s2)
/* 3B4380 E00B04D0 96A20000 */  lhu       $v0, ($s5)
/* 3B4384 E00B04D4 3C03DA38 */  lui       $v1, 0xda38
/* 3B4388 E00B04D8 ACA30000 */  sw        $v1, ($a1)
/* 3B438C E00B04DC 24430001 */  addiu     $v1, $v0, 1
/* 3B4390 E00B04E0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3B4394 E00B04E4 00021180 */  sll       $v0, $v0, 6
/* 3B4398 E00B04E8 A6A30000 */  sh        $v1, ($s5)
/* 3B439C E00B04EC 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 3B43A0 E00B04F0 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 3B43A4 E00B04F4 005E1021 */  addu      $v0, $v0, $fp
/* 3B43A8 E00B04F8 00621821 */  addu      $v1, $v1, $v0
/* 3B43AC E00B04FC 24820008 */  addiu     $v0, $a0, 8
/* 3B43B0 E00B0500 ACA30004 */  sw        $v1, 4($a1)
/* 3B43B4 E00B0504 AE420000 */  sw        $v0, ($s2)
/* 3B43B8 E00B0508 3C02DE00 */  lui       $v0, 0xde00
/* 3B43BC E00B050C AC820000 */  sw        $v0, ($a0)
/* 3B43C0 E00B0510 3C020900 */  lui       $v0, 0x900
/* 3B43C4 E00B0514 244200C8 */  addiu     $v0, $v0, 0xc8
/* 3B43C8 E00B0518 AC820004 */  sw        $v0, 4($a0)
/* 3B43CC E00B051C 24820010 */  addiu     $v0, $a0, 0x10
/* 3B43D0 E00B0520 AE420000 */  sw        $v0, ($s2)
/* 3B43D4 E00B0524 24020040 */  addiu     $v0, $zero, 0x40
/* 3B43D8 E00B0528 AC82000C */  sw        $v0, 0xc($a0)
/* 3B43DC E00B052C 2A220005 */  slti      $v0, $s1, 5
/* 3B43E0 E00B0530 1440FFB6 */  bnez      $v0, .LE00B040C
/* 3B43E4 E00B0534 AC860008 */   sw       $a2, 8($a0)
/* 3B43E8 E00B0538 3C07800A */  lui       $a3, %hi(gMasterGfxPos)
/* 3B43EC E00B053C 24E7A66C */  addiu     $a3, $a3, %lo(gMasterGfxPos)
/* 3B43F0 E00B0540 0000882D */  daddu     $s1, $zero, $zero
/* 3B43F4 E00B0544 8CE40000 */  lw        $a0, ($a3)
/* 3B43F8 E00B0548 3C02DF00 */  lui       $v0, 0xdf00
/* 3B43FC E00B054C 0080182D */  daddu     $v1, $a0, $zero
/* 3B4400 E00B0550 24840008 */  addiu     $a0, $a0, 8
/* 3B4404 E00B0554 ACE40000 */  sw        $a0, ($a3)
/* 3B4408 E00B0558 AC620000 */  sw        $v0, ($v1)
/* 3B440C E00B055C 3C02DE01 */  lui       $v0, 0xde01
/* 3B4410 E00B0560 AC600004 */  sw        $zero, 4($v1)
/* 3B4414 E00B0564 AEE20000 */  sw        $v0, ($s7)
/* 3B4418 E00B0568 24820008 */  addiu     $v0, $a0, 8
/* 3B441C E00B056C AEE40004 */  sw        $a0, 4($s7)
/* 3B4420 E00B0570 ACE20000 */  sw        $v0, ($a3)
/* 3B4424 E00B0574 3C02FA00 */  lui       $v0, 0xfa00
/* 3B4428 E00B0578 AC820000 */  sw        $v0, ($a0)
/* 3B442C E00B057C 9262001B */  lbu       $v0, 0x1b($s3)
/* 3B4430 E00B0580 9265001F */  lbu       $a1, 0x1f($s3)
/* 3B4434 E00B0584 92660023 */  lbu       $a2, 0x23($s3)
/* 3B4438 E00B0588 3C03FB00 */  lui       $v1, 0xfb00
/* 3B443C E00B058C AC830008 */  sw        $v1, 8($a0)
/* 3B4440 E00B0590 2403FF00 */  addiu     $v1, $zero, -0x100
/* 3B4444 E00B0594 AC83000C */  sw        $v1, 0xc($a0)
/* 3B4448 E00B0598 8FAA00A4 */  lw        $t2, 0xa4($sp)
/* 3B444C E00B059C 00021600 */  sll       $v0, $v0, 0x18
/* 3B4450 E00B05A0 00052C00 */  sll       $a1, $a1, 0x10
/* 3B4454 E00B05A4 00451025 */  or        $v0, $v0, $a1
/* 3B4458 E00B05A8 00063200 */  sll       $a2, $a2, 8
/* 3B445C E00B05AC 00461025 */  or        $v0, $v0, $a2
/* 3B4460 E00B05B0 314300FF */  andi      $v1, $t2, 0xff
/* 3B4464 E00B05B4 00431025 */  or        $v0, $v0, $v1
/* 3B4468 E00B05B8 AC820004 */  sw        $v0, 4($a0)
/* 3B446C E00B05BC 8E660030 */  lw        $a2, 0x30($s3)
/* 3B4470 E00B05C0 24840010 */  addiu     $a0, $a0, 0x10
/* 3B4474 E00B05C4 24C20001 */  addiu     $v0, $a2, 1
/* 3B4478 E00B05C8 18400065 */  blez      $v0, .LE00B0760
/* 3B447C E00B05CC ACE40000 */   sw       $a0, ($a3)
/* 3B4480 E00B05D0 8FAA00A0 */  lw        $t2, 0xa0($sp)
/* 3B4484 E00B05D4 000AB8C0 */  sll       $s7, $t2, 3
/* 3B4488 E00B05D8 3C16800A */  lui       $s6, %hi(gDisplayContext)
/* 3B448C E00B05DC 26D6A674 */  addiu     $s6, $s6, %lo(gDisplayContext)
/* 3B4490 E00B05E0 3C158007 */  lui       $s5, %hi(gMatrixListPos)
/* 3B4494 E00B05E4 26B541F0 */  addiu     $s5, $s5, %lo(gMatrixListPos)
/* 3B4498 E00B05E8 3C140001 */  lui       $s4, 1
/* 3B449C E00B05EC 36941630 */  ori       $s4, $s4, 0x1630
/* 3B44A0 E00B05F0 00E0902D */  daddu     $s2, $a3, $zero
.LE00B05F4:
/* 3B44A4 E00B05F4 00111840 */  sll       $v1, $s1, 1
/* 3B44A8 E00B05F8 00711821 */  addu      $v1, $v1, $s1
/* 3B44AC E00B05FC 00031100 */  sll       $v0, $v1, 4
/* 3B44B0 E00B0600 00431023 */  subu      $v0, $v0, $v1
/* 3B44B4 E00B0604 00021080 */  sll       $v0, $v0, 2
/* 3B44B8 E00B0608 24C30001 */  addiu     $v1, $a2, 1
/* 3B44BC E00B060C 14600002 */  bnez      $v1, .LE00B0618
/* 3B44C0 E00B0610 0043001A */   div      $zero, $v0, $v1
/* 3B44C4 E00B0614 0007000D */  break     7
.LE00B0618:
/* 3B44C8 E00B0618 2401FFFF */   addiu    $at, $zero, -1
/* 3B44CC E00B061C 14610004 */  bne       $v1, $at, .LE00B0630
/* 3B44D0 E00B0620 3C018000 */   lui      $at, 0x8000
/* 3B44D4 E00B0624 14410002 */  bne       $v0, $at, .LE00B0630
/* 3B44D8 E00B0628 00000000 */   nop
/* 3B44DC E00B062C 0006000D */  break     6
.LE00B0630:
/* 3B44E0 E00B0630 00001012 */   mflo     $v0
/* 3B44E4 E00B0634 02E21021 */  addu      $v0, $s7, $v0
/* 3B44E8 E00B0638 44826000 */  mtc1      $v0, $f12
/* 3B44EC E00B063C 00000000 */  nop
/* 3B44F0 E00B0640 46806320 */  cvt.s.w   $f12, $f12
/* 3B44F4 E00B0644 0C080144 */  jal       func_E0200510
/* 3B44F8 E00B0648 26300001 */   addiu    $s0, $s1, 1
/* 3B44FC E00B064C 46000021 */  cvt.d.s   $f0, $f0
/* 3B4500 E00B0650 3C01E00B */  lui       $at, %hi(D_E00B07E8)
/* 3B4504 E00B0654 D42207E8 */  ldc1      $f2, %lo(D_E00B07E8)($at)
/* 3B4508 E00B0658 001110C0 */  sll       $v0, $s1, 3
/* 3B450C E00B065C 46220002 */  mul.d     $f0, $f0, $f2
/* 3B4510 E00B0660 00000000 */  nop
/* 3B4514 E00B0664 00511021 */  addu      $v0, $v0, $s1
/* 3B4518 E00B0668 00021080 */  sll       $v0, $v0, 2
/* 3B451C E00B066C 44822000 */  mtc1      $v0, $f4
/* 3B4520 E00B0670 00000000 */  nop
/* 3B4524 E00B0674 46802120 */  cvt.s.w   $f4, $f4
/* 3B4528 E00B0678 4405A000 */  mfc1      $a1, $f20
/* 3B452C E00B067C 4406A000 */  mfc1      $a2, $f20
/* 3B4530 E00B0680 44901000 */  mtc1      $s0, $f2
/* 3B4534 E00B0684 00000000 */  nop
/* 3B4538 E00B0688 468010A0 */  cvt.s.w   $f2, $f2
/* 3B453C E00B068C 460010A1 */  cvt.d.s   $f2, $f2
/* 3B4540 E00B0690 46201080 */  add.d     $f2, $f2, $f0
/* 3B4544 E00B0694 44072000 */  mfc1      $a3, $f4
/* 3B4548 E00B0698 C660002C */  lwc1      $f0, 0x2c($s3)
/* 3B454C E00B069C 462010A0 */  cvt.s.d   $f2, $f2
/* 3B4550 E00B06A0 46001082 */  mul.s     $f2, $f2, $f0
/* 3B4554 E00B06A4 00000000 */  nop
/* 3B4558 E00B06A8 27A40020 */  addiu     $a0, $sp, 0x20
/* 3B455C E00B06AC E7B40014 */  swc1      $f20, 0x14($sp)
/* 3B4560 E00B06B0 E7B40018 */  swc1      $f20, 0x18($sp)
/* 3B4564 E00B06B4 E7B4001C */  swc1      $f20, 0x1c($sp)
/* 3B4568 E00B06B8 0C080180 */  jal       func_E0200600
/* 3B456C E00B06BC E7A20010 */   swc1     $f2, 0x10($sp)
/* 3B4570 E00B06C0 27A40020 */  addiu     $a0, $sp, 0x20
/* 3B4574 E00B06C4 96A50000 */  lhu       $a1, ($s5)
/* 3B4578 E00B06C8 8EC20000 */  lw        $v0, ($s6)
/* 3B457C E00B06CC 00052980 */  sll       $a1, $a1, 6
/* 3B4580 E00B06D0 00B42821 */  addu      $a1, $a1, $s4
/* 3B4584 E00B06D4 0C080118 */  jal       func_E0200460
/* 3B4588 E00B06D8 00452821 */   addu     $a1, $v0, $a1
/* 3B458C E00B06DC 3C07D838 */  lui       $a3, 0xd838
/* 3B4590 E00B06E0 34E70002 */  ori       $a3, $a3, 2
/* 3B4594 E00B06E4 3C02DA38 */  lui       $v0, 0xda38
/* 3B4598 E00B06E8 0200882D */  daddu     $s1, $s0, $zero
/* 3B459C E00B06EC 8E440000 */  lw        $a0, ($s2)
/* 3B45A0 E00B06F0 96A50000 */  lhu       $a1, ($s5)
/* 3B45A4 E00B06F4 0080302D */  daddu     $a2, $a0, $zero
/* 3B45A8 E00B06F8 24840008 */  addiu     $a0, $a0, 8
/* 3B45AC E00B06FC ACC20000 */  sw        $v0, ($a2)
/* 3B45B0 E00B0700 30A2FFFF */  andi      $v0, $a1, 0xffff
/* 3B45B4 E00B0704 00021180 */  sll       $v0, $v0, 6
/* 3B45B8 E00B0708 00541021 */  addu      $v0, $v0, $s4
/* 3B45BC E00B070C 8EC30000 */  lw        $v1, ($s6)
/* 3B45C0 E00B0710 24A50001 */  addiu     $a1, $a1, 1
/* 3B45C4 E00B0714 00621821 */  addu      $v1, $v1, $v0
/* 3B45C8 E00B0718 3C02DE00 */  lui       $v0, 0xde00
/* 3B45CC E00B071C ACC30004 */  sw        $v1, 4($a2)
/* 3B45D0 E00B0720 AC820000 */  sw        $v0, ($a0)
/* 3B45D4 E00B0724 8FAA00A8 */  lw        $t2, 0xa8($sp)
/* 3B45D8 E00B0728 24020040 */  addiu     $v0, $zero, 0x40
/* 3B45DC E00B072C AC870008 */  sw        $a3, 8($a0)
/* 3B45E0 E00B0730 AC82000C */  sw        $v0, 0xc($a0)
/* 3B45E4 E00B0734 AC8A0004 */  sw        $t2, 4($a0)
/* 3B45E8 E00B0738 8E660030 */  lw        $a2, 0x30($s3)
/* 3B45EC E00B073C 24820008 */  addiu     $v0, $a0, 8
/* 3B45F0 E00B0740 AE440000 */  sw        $a0, ($s2)
/* 3B45F4 E00B0744 24840010 */  addiu     $a0, $a0, 0x10
/* 3B45F8 E00B0748 A6A50000 */  sh        $a1, ($s5)
/* 3B45FC E00B074C AE420000 */  sw        $v0, ($s2)
/* 3B4600 E00B0750 24C20001 */  addiu     $v0, $a2, 1
/* 3B4604 E00B0754 0222102A */  slt       $v0, $s1, $v0
/* 3B4608 E00B0758 1440FFA6 */  bnez      $v0, .LE00B05F4
/* 3B460C E00B075C AE440000 */   sw       $a0, ($s2)
.LE00B0760:
/* 3B4610 E00B0760 3C03D838 */  lui       $v1, 0xd838
/* 3B4614 E00B0764 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 3B4618 E00B0768 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 3B461C E00B076C 8C820000 */  lw        $v0, ($a0)
/* 3B4620 E00B0770 34630002 */  ori       $v1, $v1, 2
/* 3B4624 E00B0774 0040282D */  daddu     $a1, $v0, $zero
/* 3B4628 E00B0778 24420008 */  addiu     $v0, $v0, 8
/* 3B462C E00B077C AC820000 */  sw        $v0, ($a0)
/* 3B4630 E00B0780 ACA30000 */  sw        $v1, ($a1)
/* 3B4634 E00B0784 24030040 */  addiu     $v1, $zero, 0x40
/* 3B4638 E00B0788 ACA30004 */  sw        $v1, 4($a1)
/* 3B463C E00B078C 24430008 */  addiu     $v1, $v0, 8
/* 3B4640 E00B0790 AC830000 */  sw        $v1, ($a0)
/* 3B4644 E00B0794 3C03E700 */  lui       $v1, 0xe700
/* 3B4648 E00B0798 AC430000 */  sw        $v1, ($v0)
/* 3B464C E00B079C AC400004 */  sw        $zero, 4($v0)
/* 3B4650 E00B07A0 8FBF00D4 */  lw        $ra, 0xd4($sp)
/* 3B4654 E00B07A4 8FBE00D0 */  lw        $fp, 0xd0($sp)
/* 3B4658 E00B07A8 8FB700CC */  lw        $s7, 0xcc($sp)
/* 3B465C E00B07AC 8FB600C8 */  lw        $s6, 0xc8($sp)
/* 3B4660 E00B07B0 8FB500C4 */  lw        $s5, 0xc4($sp)
/* 3B4664 E00B07B4 8FB400C0 */  lw        $s4, 0xc0($sp)
/* 3B4668 E00B07B8 8FB300BC */  lw        $s3, 0xbc($sp)
/* 3B466C E00B07BC 8FB200B8 */  lw        $s2, 0xb8($sp)
/* 3B4670 E00B07C0 8FB100B4 */  lw        $s1, 0xb4($sp)
/* 3B4674 E00B07C4 8FB000B0 */  lw        $s0, 0xb0($sp)
/* 3B4678 E00B07C8 D7B800E8 */  ldc1      $f24, 0xe8($sp)
/* 3B467C E00B07CC D7B600E0 */  ldc1      $f22, 0xe0($sp)
/* 3B4680 E00B07D0 D7B400D8 */  ldc1      $f20, 0xd8($sp)
/* 3B4684 E00B07D4 03E00008 */  jr        $ra
/* 3B4688 E00B07D8 27BD00F0 */   addiu    $sp, $sp, 0xf0
/* 3B468C E00B07DC 00000000 */  nop
