.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80246650_EA6F50
.word L80242534_EA2E34, L80242540_EA2E40, L80242540_EA2E40, L80242540_EA2E40, L80242540_EA2E40, L80242540_EA2E40, L80242540_EA2E40, L80242540_EA2E40, L80242534_EA2E34, L80242540_EA2E40, L80242534_EA2E34, L80242540_EA2E40, L80242534_EA2E34, L80242540_EA2E40, L80242534_EA2E34, L80242540_EA2E40, L80242540_EA2E40, L80242540_EA2E40, L80242534_EA2E34, L80242540_EA2E40, L80242534_EA2E34, 0, 0, 0

.section .text

glabel func_802420FC_EA29FC
/* EA29FC 802420FC 27BDFF90 */  addiu     $sp, $sp, -0x70
/* EA2A00 80242100 AFB3005C */  sw        $s3, 0x5c($sp)
/* EA2A04 80242104 0080982D */  daddu     $s3, $a0, $zero
/* EA2A08 80242108 AFBF0068 */  sw        $ra, 0x68($sp)
/* EA2A0C 8024210C AFB50064 */  sw        $s5, 0x64($sp)
/* EA2A10 80242110 AFB40060 */  sw        $s4, 0x60($sp)
/* EA2A14 80242114 AFB20058 */  sw        $s2, 0x58($sp)
/* EA2A18 80242118 AFB10054 */  sw        $s1, 0x54($sp)
/* EA2A1C 8024211C AFB00050 */  sw        $s0, 0x50($sp)
/* EA2A20 80242120 8E710148 */  lw        $s1, 0x148($s3)
/* EA2A24 80242124 86240008 */  lh        $a0, 8($s1)
/* EA2A28 80242128 0C00F92F */  jal       func_8003E4BC
/* EA2A2C 8024212C 00A0802D */   daddu    $s0, $a1, $zero
/* EA2A30 80242130 8E63000C */  lw        $v1, 0xc($s3)
/* EA2A34 80242134 0260202D */  daddu     $a0, $s3, $zero
/* EA2A38 80242138 8C650000 */  lw        $a1, ($v1)
/* EA2A3C 8024213C 0C0B53A3 */  jal       func_802D4E8C
/* EA2A40 80242140 0040902D */   daddu    $s2, $v0, $zero
/* EA2A44 80242144 AFA00028 */  sw        $zero, 0x28($sp)
/* EA2A48 80242148 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EA2A4C 8024214C 8C630030 */  lw        $v1, 0x30($v1)
/* EA2A50 80242150 AFA3002C */  sw        $v1, 0x2c($sp)
/* EA2A54 80242154 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EA2A58 80242158 8C63001C */  lw        $v1, 0x1c($v1)
/* EA2A5C 8024215C AFA30030 */  sw        $v1, 0x30($sp)
/* EA2A60 80242160 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EA2A64 80242164 8C630024 */  lw        $v1, 0x24($v1)
/* EA2A68 80242168 AFA30034 */  sw        $v1, 0x34($sp)
/* EA2A6C 8024216C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EA2A70 80242170 8C630028 */  lw        $v1, 0x28($v1)
/* EA2A74 80242174 AFA30038 */  sw        $v1, 0x38($sp)
/* EA2A78 80242178 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EA2A7C 8024217C 3C0142C8 */  lui       $at, 0x42c8
/* EA2A80 80242180 44810000 */  mtc1      $at, $f0
/* EA2A84 80242184 8C63002C */  lw        $v1, 0x2c($v1)
/* EA2A88 80242188 E7A00040 */  swc1      $f0, 0x40($sp)
/* EA2A8C 8024218C A7A00044 */  sh        $zero, 0x44($sp)
/* EA2A90 80242190 AFA3003C */  sw        $v1, 0x3c($sp)
/* EA2A94 80242194 C6400038 */  lwc1      $f0, 0x38($s2)
/* EA2A98 80242198 E6200108 */  swc1      $f0, 0x108($s1)
/* EA2A9C 8024219C C640003C */  lwc1      $f0, 0x3c($s2)
/* EA2AA0 802421A0 27B50028 */  addiu     $s5, $sp, 0x28
/* EA2AA4 802421A4 E620010C */  swc1      $f0, 0x10c($s1)
/* EA2AA8 802421A8 3C013C23 */  lui       $at, 0x3c23
/* EA2AAC 802421AC 3421D70A */  ori       $at, $at, 0xd70a
/* EA2AB0 802421B0 44810000 */  mtc1      $at, $f0
/* EA2AB4 802421B4 C6420040 */  lwc1      $f2, 0x40($s2)
/* EA2AB8 802421B8 0040A02D */  daddu     $s4, $v0, $zero
/* EA2ABC 802421BC E6200114 */  swc1      $f0, 0x114($s1)
/* EA2AC0 802421C0 E6200118 */  swc1      $f0, 0x118($s1)
/* EA2AC4 802421C4 12000009 */  beqz      $s0, .L802421EC
/* EA2AC8 802421C8 E6220110 */   swc1     $f2, 0x110($s1)
/* EA2ACC 802421CC 864300A8 */  lh        $v1, 0xa8($s2)
/* EA2AD0 802421D0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* EA2AD4 802421D4 AE20008C */  sw        $zero, 0x8c($s1)
/* EA2AD8 802421D8 A22000B5 */  sb        $zero, 0xb5($s1)
/* EA2ADC 802421DC 34420008 */  ori       $v0, $v0, 8
/* EA2AE0 802421E0 AE230084 */  sw        $v1, 0x84($s1)
/* EA2AE4 802421E4 0809087F */  j         .L802421FC
/* EA2AE8 802421E8 AE2200B0 */   sw       $v0, 0xb0($s1)
.L802421EC:
/* EA2AEC 802421EC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* EA2AF0 802421F0 30420004 */  andi      $v0, $v0, 4
/* EA2AF4 802421F4 10400047 */  beqz      $v0, .L80242314
/* EA2AF8 802421F8 00000000 */   nop
.L802421FC:
/* EA2AFC 802421FC AE600070 */  sw        $zero, 0x70($s3)
/* EA2B00 80242200 A640008E */  sh        $zero, 0x8e($s2)
/* EA2B04 80242204 8E2300CC */  lw        $v1, 0xcc($s1)
/* EA2B08 80242208 2404F7FF */  addiu     $a0, $zero, -0x801
/* EA2B0C 8024220C A2200007 */  sb        $zero, 7($s1)
/* EA2B10 80242210 8E420000 */  lw        $v0, ($s2)
/* EA2B14 80242214 8C630000 */  lw        $v1, ($v1)
/* EA2B18 80242218 00441024 */  and       $v0, $v0, $a0
/* EA2B1C 8024221C AE420000 */  sw        $v0, ($s2)
/* EA2B20 80242220 AE430028 */  sw        $v1, 0x28($s2)
/* EA2B24 80242224 96220086 */  lhu       $v0, 0x86($s1)
/* EA2B28 80242228 A64200A8 */  sh        $v0, 0xa8($s2)
/* EA2B2C 8024222C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EA2B30 80242230 AE200090 */  sw        $zero, 0x90($s1)
/* EA2B34 80242234 8C420034 */  lw        $v0, 0x34($v0)
/* EA2B38 80242238 14400006 */  bnez      $v0, .L80242254
/* EA2B3C 8024223C 2403FDFF */   addiu    $v1, $zero, -0x201
/* EA2B40 80242240 8E420000 */  lw        $v0, ($s2)
/* EA2B44 80242244 2403FFF7 */  addiu     $v1, $zero, -9
/* EA2B48 80242248 34420200 */  ori       $v0, $v0, 0x200
/* EA2B4C 8024224C 08090898 */  j         .L80242260
/* EA2B50 80242250 00431024 */   and      $v0, $v0, $v1
.L80242254:
/* EA2B54 80242254 8E420000 */  lw        $v0, ($s2)
/* EA2B58 80242258 00431024 */  and       $v0, $v0, $v1
/* EA2B5C 8024225C 34420008 */  ori       $v0, $v0, 8
.L80242260:
/* EA2B60 80242260 AE420000 */  sw        $v0, ($s2)
/* EA2B64 80242264 8E2200B0 */  lw        $v0, 0xb0($s1)
/* EA2B68 80242268 30420004 */  andi      $v0, $v0, 4
/* EA2B6C 8024226C 1040001E */  beqz      $v0, .L802422E8
/* EA2B70 80242270 24040002 */   addiu    $a0, $zero, 2
/* EA2B74 80242274 0240282D */  daddu     $a1, $s2, $zero
/* EA2B78 80242278 0000302D */  daddu     $a2, $zero, $zero
/* EA2B7C 8024227C 24020063 */  addiu     $v0, $zero, 0x63
/* EA2B80 80242280 AE620070 */  sw        $v0, 0x70($s3)
/* EA2B84 80242284 AE600074 */  sw        $zero, 0x74($s3)
/* EA2B88 80242288 864300A8 */  lh        $v1, 0xa8($s2)
/* EA2B8C 8024228C 3C013F80 */  lui       $at, 0x3f80
/* EA2B90 80242290 44810000 */  mtc1      $at, $f0
/* EA2B94 80242294 3C014000 */  lui       $at, 0x4000
/* EA2B98 80242298 44811000 */  mtc1      $at, $f2
/* EA2B9C 8024229C 3C01C1A0 */  lui       $at, 0xc1a0
/* EA2BA0 802422A0 44812000 */  mtc1      $at, $f4
/* EA2BA4 802422A4 24020028 */  addiu     $v0, $zero, 0x28
/* EA2BA8 802422A8 AFA2001C */  sw        $v0, 0x1c($sp)
/* EA2BAC 802422AC 44833000 */  mtc1      $v1, $f6
/* EA2BB0 802422B0 00000000 */  nop
/* EA2BB4 802422B4 468031A0 */  cvt.s.w   $f6, $f6
/* EA2BB8 802422B8 44073000 */  mfc1      $a3, $f6
/* EA2BBC 802422BC 27A20048 */  addiu     $v0, $sp, 0x48
/* EA2BC0 802422C0 AFA20020 */  sw        $v0, 0x20($sp)
/* EA2BC4 802422C4 E7A00010 */  swc1      $f0, 0x10($sp)
/* EA2BC8 802422C8 E7A20014 */  swc1      $f2, 0x14($sp)
/* EA2BCC 802422CC 0C01D444 */  jal       func_80075110
/* EA2BD0 802422D0 E7A40018 */   swc1     $f4, 0x18($sp)
/* EA2BD4 802422D4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* EA2BD8 802422D8 2403FFFB */  addiu     $v1, $zero, -5
/* EA2BDC 802422DC 00431024 */  and       $v0, $v0, $v1
/* EA2BE0 802422E0 080908C5 */  j         .L80242314
/* EA2BE4 802422E4 AE2200B0 */   sw       $v0, 0xb0($s1)
.L802422E8:
/* EA2BE8 802422E8 8E220000 */  lw        $v0, ($s1)
/* EA2BEC 802422EC 3C034000 */  lui       $v1, 0x4000
/* EA2BF0 802422F0 00431024 */  and       $v0, $v0, $v1
/* EA2BF4 802422F4 10400007 */  beqz      $v0, .L80242314
/* EA2BF8 802422F8 3C03BFFF */   lui      $v1, 0xbfff
/* EA2BFC 802422FC 2402000C */  addiu     $v0, $zero, 0xc
/* EA2C00 80242300 AE620070 */  sw        $v0, 0x70($s3)
/* EA2C04 80242304 8E220000 */  lw        $v0, ($s1)
/* EA2C08 80242308 3463FFFF */  ori       $v1, $v1, 0xffff
/* EA2C0C 8024230C 00431024 */  and       $v0, $v0, $v1
/* EA2C10 80242310 AE220000 */  sw        $v0, ($s1)
.L80242314:
/* EA2C14 80242314 8E220090 */  lw        $v0, 0x90($s1)
/* EA2C18 80242318 1840000C */  blez      $v0, .L8024234C
/* EA2C1C 8024231C 2442FFFF */   addiu    $v0, $v0, -1
/* EA2C20 80242320 14400087 */  bnez      $v0, L80242540_EA2E40
/* EA2C24 80242324 AE220090 */   sw       $v0, 0x90($s1)
/* EA2C28 80242328 3C03FFAA */  lui       $v1, 0xffaa
/* EA2C2C 8024232C 8E420028 */  lw        $v0, 0x28($s2)
/* EA2C30 80242330 3463FFD2 */  ori       $v1, $v1, 0xffd2
/* EA2C34 80242334 00431021 */  addu      $v0, $v0, $v1
/* EA2C38 80242338 2C420002 */  sltiu     $v0, $v0, 2
/* EA2C3C 8024233C 10400003 */  beqz      $v0, .L8024234C
/* EA2C40 80242340 3C020055 */   lui      $v0, 0x55
/* EA2C44 80242344 3442000C */  ori       $v0, $v0, 0xc
/* EA2C48 80242348 AE420028 */  sw        $v0, 0x28($s2)
.L8024234C:
/* EA2C4C 8024234C 8E630070 */  lw        $v1, 0x70($s3)
/* EA2C50 80242350 2402000C */  addiu     $v0, $zero, 0xc
/* EA2C54 80242354 10620048 */  beq       $v1, $v0, .L80242478
/* EA2C58 80242358 2862000D */   slti     $v0, $v1, 0xd
/* EA2C5C 8024235C 1040000F */  beqz      $v0, .L8024239C
/* EA2C60 80242360 24100001 */   addiu    $s0, $zero, 1
/* EA2C64 80242364 1070001E */  beq       $v1, $s0, .L802423E0
/* EA2C68 80242368 28620002 */   slti     $v0, $v1, 2
/* EA2C6C 8024236C 10400005 */  beqz      $v0, .L80242384
/* EA2C70 80242370 24020002 */   addiu    $v0, $zero, 2
/* EA2C74 80242374 10600015 */  beqz      $v1, .L802423CC
/* EA2C78 80242378 0260202D */   daddu    $a0, $s3, $zero
/* EA2C7C 8024237C 08090935 */  j         .L802424D4
/* EA2C80 80242380 00000000 */   nop
.L80242384:
/* EA2C84 80242384 1062001C */  beq       $v1, $v0, .L802423F8
/* EA2C88 80242388 24020003 */   addiu    $v0, $zero, 3
/* EA2C8C 8024238C 10620035 */  beq       $v1, $v0, .L80242464
/* EA2C90 80242390 0260202D */   daddu    $a0, $s3, $zero
/* EA2C94 80242394 08090935 */  j         .L802424D4
/* EA2C98 80242398 00000000 */   nop
.L8024239C:
/* EA2C9C 8024239C 2402000E */  addiu     $v0, $zero, 0xe
/* EA2CA0 802423A0 1062003F */  beq       $v1, $v0, .L802424A0
/* EA2CA4 802423A4 0062102A */   slt      $v0, $v1, $v0
/* EA2CA8 802423A8 14400038 */  bnez      $v0, .L8024248C
/* EA2CAC 802423AC 0260202D */   daddu    $a0, $s3, $zero
/* EA2CB0 802423B0 2402000F */  addiu     $v0, $zero, 0xf
/* EA2CB4 802423B4 10620040 */  beq       $v1, $v0, .L802424B8
/* EA2CB8 802423B8 24020063 */   addiu    $v0, $zero, 0x63
/* EA2CBC 802423BC 10620043 */  beq       $v1, $v0, .L802424CC
/* EA2CC0 802423C0 00000000 */   nop
/* EA2CC4 802423C4 08090935 */  j         .L802424D4
/* EA2CC8 802423C8 00000000 */   nop
.L802423CC:
/* EA2CCC 802423CC 0280282D */  daddu     $a1, $s4, $zero
/* EA2CD0 802423D0 0C013670 */  jal       func_8004D9C0
/* EA2CD4 802423D4 02A0302D */   daddu    $a2, $s5, $zero
/* EA2CD8 802423D8 96220086 */  lhu       $v0, 0x86($s1)
/* EA2CDC 802423DC A64200A8 */  sh        $v0, 0xa8($s2)
.L802423E0:
/* EA2CE0 802423E0 0260202D */  daddu     $a0, $s3, $zero
/* EA2CE4 802423E4 0280282D */  daddu     $a1, $s4, $zero
/* EA2CE8 802423E8 0C0136B6 */  jal       func_8004DAD8
/* EA2CEC 802423EC 02A0302D */   daddu    $a2, $s5, $zero
/* EA2CF0 802423F0 08090935 */  j         .L802424D4
/* EA2CF4 802423F4 00000000 */   nop
.L802423F8:
/* EA2CF8 802423F8 0260202D */  daddu     $a0, $s3, $zero
/* EA2CFC 802423FC 0280282D */  daddu     $a1, $s4, $zero
/* EA2D00 80242400 0C0137D9 */  jal       func_8004DF64
/* EA2D04 80242404 02A0302D */   daddu    $a2, $s5, $zero
/* EA2D08 80242408 8E230088 */  lw        $v1, 0x88($s1)
/* EA2D0C 8024240C 24020006 */  addiu     $v0, $zero, 6
/* EA2D10 80242410 14620014 */  bne       $v1, $v0, .L80242464
/* EA2D14 80242414 0260202D */   daddu    $a0, $s3, $zero
/* EA2D18 80242418 0C00AB3B */  jal       func_8002ACEC
/* EA2D1C 8024241C 24040064 */   addiu    $a0, $zero, 0x64
/* EA2D20 80242420 28420021 */  slti      $v0, $v0, 0x21
/* EA2D24 80242424 5040000F */  beql      $v0, $zero, .L80242464
/* EA2D28 80242428 0260202D */   daddu    $a0, $s3, $zero
/* EA2D2C 8024242C 8E22008C */  lw        $v0, 0x8c($s1)
/* EA2D30 80242430 10400005 */  beqz      $v0, .L80242448
/* EA2D34 80242434 3C020055 */   lui      $v0, 0x55
/* EA2D38 80242438 3442002F */  ori       $v0, $v0, 0x2f
/* EA2D3C 8024243C AE20008C */  sw        $zero, 0x8c($s1)
/* EA2D40 80242440 08090915 */  j         .L80242454
/* EA2D44 80242444 A22000B5 */   sb       $zero, 0xb5($s1)
.L80242448:
/* EA2D48 80242448 3442002E */  ori       $v0, $v0, 0x2e
/* EA2D4C 8024244C AE30008C */  sw        $s0, 0x8c($s1)
/* EA2D50 80242450 A23000B5 */  sb        $s0, 0xb5($s1)
.L80242454:
/* EA2D54 80242454 AE420028 */  sw        $v0, 0x28($s2)
/* EA2D58 80242458 24020007 */  addiu     $v0, $zero, 7
/* EA2D5C 8024245C 08090950 */  j         L80242540_EA2E40
/* EA2D60 80242460 AE220090 */   sw       $v0, 0x90($s1)
.L80242464:
/* EA2D64 80242464 0280282D */  daddu     $a1, $s4, $zero
/* EA2D68 80242468 0C013809 */  jal       func_8004E024
/* EA2D6C 8024246C 02A0302D */   daddu    $a2, $s5, $zero
/* EA2D70 80242470 08090935 */  j         .L802424D4
/* EA2D74 80242474 00000000 */   nop
.L80242478:
/* EA2D78 80242478 0260202D */  daddu     $a0, $s3, $zero
/* EA2D7C 8024247C 0280282D */  daddu     $a1, $s4, $zero
/* EA2D80 80242480 0C09075A */  jal       func_80241D68_EA2668
/* EA2D84 80242484 02A0302D */   daddu    $a2, $s5, $zero
/* EA2D88 80242488 0260202D */  daddu     $a0, $s3, $zero
.L8024248C:
/* EA2D8C 8024248C 0280282D */  daddu     $a1, $s4, $zero
/* EA2D90 80242490 0C090779 */  jal       func_80241DE4_EA26E4
/* EA2D94 80242494 02A0302D */   daddu    $a2, $s5, $zero
/* EA2D98 80242498 08090935 */  j         .L802424D4
/* EA2D9C 8024249C 00000000 */   nop
.L802424A0:
/* EA2DA0 802424A0 0260202D */  daddu     $a0, $s3, $zero
/* EA2DA4 802424A4 0280282D */  daddu     $a1, $s4, $zero
/* EA2DA8 802424A8 0C0907C6 */  jal       func_80241F18_EA2818
/* EA2DAC 802424AC 02A0302D */   daddu    $a2, $s5, $zero
/* EA2DB0 802424B0 08090935 */  j         .L802424D4
/* EA2DB4 802424B4 00000000 */   nop
.L802424B8:
/* EA2DB8 802424B8 0280282D */  daddu     $a1, $s4, $zero
/* EA2DBC 802424BC 0C09081F */  jal       func_8024207C_EA297C
/* EA2DC0 802424C0 02A0302D */   daddu    $a2, $s5, $zero
/* EA2DC4 802424C4 08090935 */  j         .L802424D4
/* EA2DC8 802424C8 00000000 */   nop
.L802424CC:
/* EA2DCC 802424CC 0C013AE3 */  jal       func_8004EB8C
/* EA2DD0 802424D0 0260202D */   daddu    $a0, $s3, $zero
.L802424D4:
/* EA2DD4 802424D4 8E230088 */  lw        $v1, 0x88($s1)
/* EA2DD8 802424D8 24020006 */  addiu     $v0, $zero, 6
/* EA2DDC 802424DC 14620019 */  bne       $v1, $v0, .L80242544
/* EA2DE0 802424E0 0000102D */   daddu    $v0, $zero, $zero
/* EA2DE4 802424E4 8E22008C */  lw        $v0, 0x8c($s1)
/* EA2DE8 802424E8 10400003 */  beqz      $v0, .L802424F8
/* EA2DEC 802424EC 24020001 */   addiu    $v0, $zero, 1
/* EA2DF0 802424F0 0809093F */  j         .L802424FC
/* EA2DF4 802424F4 A22200B5 */   sb       $v0, 0xb5($s1)
.L802424F8:
/* EA2DF8 802424F8 A22000B5 */  sb        $zero, 0xb5($s1)
.L802424FC:
/* EA2DFC 802424FC 8E22008C */  lw        $v0, 0x8c($s1)
/* EA2E00 80242500 1040000F */  beqz      $v0, L80242540_EA2E40
/* EA2E04 80242504 3C03FFAA */   lui      $v1, 0xffaa
/* EA2E08 80242508 8E420028 */  lw        $v0, 0x28($s2)
/* EA2E0C 8024250C 3463FFFC */  ori       $v1, $v1, 0xfffc
/* EA2E10 80242510 00431821 */  addu      $v1, $v0, $v1
/* EA2E14 80242514 2C620015 */  sltiu     $v0, $v1, 0x15
/* EA2E18 80242518 10400009 */  beqz      $v0, L80242540_EA2E40
/* EA2E1C 8024251C 00031080 */   sll      $v0, $v1, 2
/* EA2E20 80242520 3C018024 */  lui       $at, %hi(jtbl_80246650_EA6F50)
/* EA2E24 80242524 00220821 */  addu      $at, $at, $v0
/* EA2E28 80242528 8C226650 */  lw        $v0, %lo(jtbl_80246650_EA6F50)($at)
/* EA2E2C 8024252C 00400008 */  jr        $v0
/* EA2E30 80242530 00000000 */   nop
glabel L80242534_EA2E34
/* EA2E34 80242534 8E420028 */  lw        $v0, 0x28($s2)
/* EA2E38 80242538 24420001 */  addiu     $v0, $v0, 1
/* EA2E3C 8024253C AE420028 */  sw        $v0, 0x28($s2)
glabel L80242540_EA2E40
/* EA2E40 80242540 0000102D */  daddu     $v0, $zero, $zero
.L80242544:
/* EA2E44 80242544 8FBF0068 */  lw        $ra, 0x68($sp)
/* EA2E48 80242548 8FB50064 */  lw        $s5, 0x64($sp)
/* EA2E4C 8024254C 8FB40060 */  lw        $s4, 0x60($sp)
/* EA2E50 80242550 8FB3005C */  lw        $s3, 0x5c($sp)
/* EA2E54 80242554 8FB20058 */  lw        $s2, 0x58($sp)
/* EA2E58 80242558 8FB10054 */  lw        $s1, 0x54($sp)
/* EA2E5C 8024255C 8FB00050 */  lw        $s0, 0x50($sp)
/* EA2E60 80242560 03E00008 */  jr        $ra
/* EA2E64 80242564 27BD0070 */   addiu    $sp, $sp, 0x70
