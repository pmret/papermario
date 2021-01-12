.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00AC2A4
/* 3AF0C4 E00AC2A4 27BDFF30 */  addiu     $sp, $sp, -0xd0
/* 3AF0C8 E00AC2A8 0080482D */  daddu     $t1, $a0, $zero
/* 3AF0CC E00AC2AC AFBF00C4 */  sw        $ra, 0xc4($sp)
/* 3AF0D0 E00AC2B0 AFBE00C0 */  sw        $fp, 0xc0($sp)
/* 3AF0D4 E00AC2B4 AFB700BC */  sw        $s7, 0xbc($sp)
/* 3AF0D8 E00AC2B8 AFB600B8 */  sw        $s6, 0xb8($sp)
/* 3AF0DC E00AC2BC AFB500B4 */  sw        $s5, 0xb4($sp)
/* 3AF0E0 E00AC2C0 AFB400B0 */  sw        $s4, 0xb0($sp)
/* 3AF0E4 E00AC2C4 AFB300AC */  sw        $s3, 0xac($sp)
/* 3AF0E8 E00AC2C8 AFB200A8 */  sw        $s2, 0xa8($sp)
/* 3AF0EC E00AC2CC AFB100A4 */  sw        $s1, 0xa4($sp)
/* 3AF0F0 E00AC2D0 AFB000A0 */  sw        $s0, 0xa0($sp)
/* 3AF0F4 E00AC2D4 F7B400C8 */  sdc1      $f20, 0xc8($sp)
/* 3AF0F8 E00AC2D8 8D34000C */  lw        $s4, 0xc($t1)
/* 3AF0FC E00AC2DC 44801000 */  mtc1      $zero, $f2
/* 3AF100 E00AC2E0 C6800028 */  lwc1      $f0, 0x28($s4)
/* 3AF104 E00AC2E4 8E9E001C */  lw        $fp, 0x1c($s4)
/* 3AF108 E00AC2E8 8E970020 */  lw        $s7, 0x20($s4)
/* 3AF10C E00AC2EC 46020032 */  c.eq.s    $f0, $f2
/* 3AF110 E00AC2F0 00000000 */  nop       
/* 3AF114 E00AC2F4 4501011F */  bc1t      .LE00AC774
/* 3AF118 E00AC2F8 00000000 */   nop      
/* 3AF11C E00AC2FC C680002C */  lwc1      $f0, 0x2c($s4)
/* 3AF120 E00AC300 46020032 */  c.eq.s    $f0, $f2
/* 3AF124 E00AC304 00000000 */  nop       
/* 3AF128 E00AC308 4501011A */  bc1t      .LE00AC774
/* 3AF12C E00AC30C 3C08DB06 */   lui      $t0, 0xdb06
/* 3AF130 E00AC310 35080024 */  ori       $t0, $t0, 0x24
/* 3AF134 E00AC314 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 3AF138 E00AC318 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 3AF13C E00AC31C 3C02E700 */  lui       $v0, 0xe700
/* 3AF140 E00AC320 8E660000 */  lw        $a2, ($s3)
/* 3AF144 E00AC324 44051000 */  mfc1      $a1, $f2
/* 3AF148 E00AC328 00C0182D */  daddu     $v1, $a2, $zero
/* 3AF14C E00AC32C 24C60008 */  addiu     $a2, $a2, 8
/* 3AF150 E00AC330 AC620000 */  sw        $v0, ($v1)
/* 3AF154 E00AC334 AC600004 */  sw        $zero, 4($v1)
/* 3AF158 E00AC338 ACC80000 */  sw        $t0, ($a2)
/* 3AF15C E00AC33C 8D220010 */  lw        $v0, 0x10($t1)
/* 3AF160 E00AC340 3C088000 */  lui       $t0, 0x8000
/* 3AF164 E00AC344 8C42001C */  lw        $v0, 0x1c($v0)
/* 3AF168 E00AC348 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3AF16C E00AC34C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3AF170 E00AC350 00481021 */  addu      $v0, $v0, $t0
/* 3AF174 E00AC354 ACC20004 */  sw        $v0, 4($a2)
/* 3AF178 E00AC358 00031080 */  sll       $v0, $v1, 2
/* 3AF17C E00AC35C 00431021 */  addu      $v0, $v0, $v1
/* 3AF180 E00AC360 00021080 */  sll       $v0, $v0, 2
/* 3AF184 E00AC364 00431023 */  subu      $v0, $v0, $v1
/* 3AF188 E00AC368 000218C0 */  sll       $v1, $v0, 3
/* 3AF18C E00AC36C 00431021 */  addu      $v0, $v0, $v1
/* 3AF190 E00AC370 000210C0 */  sll       $v0, $v0, 3
/* 3AF194 E00AC374 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 3AF198 E00AC378 00220821 */  addu      $at, $at, $v0
/* 3AF19C E00AC37C C4221DEC */  lwc1      $f2, %lo(D_800B1DEC)($at)
/* 3AF1A0 E00AC380 C6800010 */  lwc1      $f0, 0x10($s4)
/* 3AF1A4 E00AC384 27A40020 */  addiu     $a0, $sp, 0x20
/* 3AF1A8 E00AC388 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3AF1AC E00AC38C C6800004 */  lwc1      $f0, 4($s4)
/* 3AF1B0 E00AC390 3C120001 */  lui       $s2, 1
/* 3AF1B4 E00AC394 AE660000 */  sw        $a2, ($s3)
/* 3AF1B8 E00AC398 24C60008 */  addiu     $a2, $a2, 8
/* 3AF1BC E00AC39C E7A00014 */  swc1      $f0, 0x14($sp)
/* 3AF1C0 E00AC3A0 C6800008 */  lwc1      $f0, 8($s4)
/* 3AF1C4 E00AC3A4 46001087 */  neg.s     $f2, $f2
/* 3AF1C8 E00AC3A8 AE660000 */  sw        $a2, ($s3)
/* 3AF1CC E00AC3AC 44061000 */  mfc1      $a2, $f2
/* 3AF1D0 E00AC3B0 36521630 */  ori       $s2, $s2, 0x1630
/* 3AF1D4 E00AC3B4 E7A00018 */  swc1      $f0, 0x18($sp)
/* 3AF1D8 E00AC3B8 C680000C */  lwc1      $f0, 0xc($s4)
/* 3AF1DC E00AC3BC 00A0382D */  daddu     $a3, $a1, $zero
/* 3AF1E0 E00AC3C0 0C080180 */  jal       func_E0200600
/* 3AF1E4 E00AC3C4 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 3AF1E8 E00AC3C8 27A40020 */  addiu     $a0, $sp, 0x20
/* 3AF1EC E00AC3CC 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 3AF1F0 E00AC3D0 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 3AF1F4 E00AC3D4 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 3AF1F8 E00AC3D8 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 3AF1FC E00AC3DC 96050000 */  lhu       $a1, ($s0)
/* 3AF200 E00AC3E0 8E220000 */  lw        $v0, ($s1)
/* 3AF204 E00AC3E4 00052980 */  sll       $a1, $a1, 6
/* 3AF208 E00AC3E8 00B22821 */  addu      $a1, $a1, $s2
/* 3AF20C E00AC3EC 0C080118 */  jal       func_E0200460
/* 3AF210 E00AC3F0 00452821 */   addu     $a1, $v0, $a1
/* 3AF214 E00AC3F4 8E670000 */  lw        $a3, ($s3)
/* 3AF218 E00AC3F8 00E0202D */  daddu     $a0, $a3, $zero
/* 3AF21C E00AC3FC 24E70008 */  addiu     $a3, $a3, 8
/* 3AF220 E00AC400 AE670000 */  sw        $a3, ($s3)
/* 3AF224 E00AC404 96020000 */  lhu       $v0, ($s0)
/* 3AF228 E00AC408 3C03DA38 */  lui       $v1, 0xda38
/* 3AF22C E00AC40C AC830000 */  sw        $v1, ($a0)
/* 3AF230 E00AC410 24430001 */  addiu     $v1, $v0, 1
/* 3AF234 E00AC414 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3AF238 E00AC418 00021180 */  sll       $v0, $v0, 6
/* 3AF23C E00AC41C A6030000 */  sh        $v1, ($s0)
/* 3AF240 E00AC420 8E230000 */  lw        $v1, ($s1)
/* 3AF244 E00AC424 00521021 */  addu      $v0, $v0, $s2
/* 3AF248 E00AC428 00621821 */  addu      $v1, $v1, $v0
/* 3AF24C E00AC42C AC830004 */  sw        $v1, 4($a0)
/* 3AF250 E00AC430 8E830024 */  lw        $v1, 0x24($s4)
/* 3AF254 E00AC434 240200FF */  addiu     $v0, $zero, 0xff
/* 3AF258 E00AC438 54620011 */  bnel      $v1, $v0, .LE00AC480
/* 3AF25C E00AC43C 3C05E200 */   lui      $a1, 0xe200
/* 3AF260 E00AC440 3C04E200 */  lui       $a0, 0xe200
/* 3AF264 E00AC444 3484001C */  ori       $a0, $a0, 0x1c
/* 3AF268 E00AC448 3C030055 */  lui       $v1, 0x55
/* 3AF26C E00AC44C 34631208 */  ori       $v1, $v1, 0x1208
/* 3AF270 E00AC450 3C05FC12 */  lui       $a1, 0xfc12
/* 3AF274 E00AC454 34A57E24 */  ori       $a1, $a1, 0x7e24
/* 3AF278 E00AC458 24E20008 */  addiu     $v0, $a3, 8
/* 3AF27C E00AC45C AE620000 */  sw        $v0, ($s3)
/* 3AF280 E00AC460 24E20010 */  addiu     $v0, $a3, 0x10
/* 3AF284 E00AC464 ACE40000 */  sw        $a0, ($a3)
/* 3AF288 E00AC468 ACE30004 */  sw        $v1, 4($a3)
/* 3AF28C E00AC46C AE620000 */  sw        $v0, ($s3)
/* 3AF290 E00AC470 2402F3F9 */  addiu     $v0, $zero, -0xc07
/* 3AF294 E00AC474 ACE50008 */  sw        $a1, 8($a3)
/* 3AF298 E00AC478 0802B12F */  j         .LE00AC4BC
/* 3AF29C E00AC47C ACE2000C */   sw       $v0, 0xc($a3)
.LE00AC480:
/* 3AF2A0 E00AC480 34A5001C */  ori       $a1, $a1, 0x1c
/* 3AF2A4 E00AC484 3C030050 */  lui       $v1, 0x50
/* 3AF2A8 E00AC488 34634340 */  ori       $v1, $v1, 0x4340
/* 3AF2AC E00AC48C 3C06FC12 */  lui       $a2, 0xfc12
/* 3AF2B0 E00AC490 34C63224 */  ori       $a2, $a2, 0x3224
/* 3AF2B4 E00AC494 3C04FF67 */  lui       $a0, 0xff67
/* 3AF2B8 E00AC498 3484FFFF */  ori       $a0, $a0, 0xffff
/* 3AF2BC E00AC49C 24E20008 */  addiu     $v0, $a3, 8
/* 3AF2C0 E00AC4A0 AE620000 */  sw        $v0, ($s3)
/* 3AF2C4 E00AC4A4 24E20010 */  addiu     $v0, $a3, 0x10
/* 3AF2C8 E00AC4A8 ACE50000 */  sw        $a1, ($a3)
/* 3AF2CC E00AC4AC ACE30004 */  sw        $v1, 4($a3)
/* 3AF2D0 E00AC4B0 AE620000 */  sw        $v0, ($s3)
/* 3AF2D4 E00AC4B4 ACE60008 */  sw        $a2, 8($a3)
/* 3AF2D8 E00AC4B8 ACE4000C */  sw        $a0, 0xc($a3)
.LE00AC4BC:
/* 3AF2DC E00AC4BC 27A40020 */  addiu     $a0, $sp, 0x20
/* 3AF2E0 E00AC4C0 3C120001 */  lui       $s2, 1
/* 3AF2E4 E00AC4C4 4480A000 */  mtc1      $zero, $f20
/* 3AF2E8 E00AC4C8 8E860040 */  lw        $a2, 0x40($s4)
/* 3AF2EC E00AC4CC 4405A000 */  mfc1      $a1, $f20
/* 3AF2F0 E00AC4D0 4407A000 */  mfc1      $a3, $f20
/* 3AF2F4 E00AC4D4 0C080108 */  jal       func_E0200420
/* 3AF2F8 E00AC4D8 36521630 */   ori      $s2, $s2, 0x1630
/* 3AF2FC E00AC4DC 27B00060 */  addiu     $s0, $sp, 0x60
/* 3AF300 E00AC4E0 8E850028 */  lw        $a1, 0x28($s4)
/* 3AF304 E00AC4E4 8E86002C */  lw        $a2, 0x2c($s4)
/* 3AF308 E00AC4E8 3C073F80 */  lui       $a3, 0x3f80
/* 3AF30C E00AC4EC 0C080110 */  jal       func_E0200440
/* 3AF310 E00AC4F0 0200202D */   daddu    $a0, $s0, $zero
/* 3AF314 E00AC4F4 0200202D */  daddu     $a0, $s0, $zero
/* 3AF318 E00AC4F8 27A50020 */  addiu     $a1, $sp, 0x20
/* 3AF31C E00AC4FC 0C080114 */  jal       func_E0200450
/* 3AF320 E00AC500 00A0302D */   daddu    $a2, $a1, $zero
/* 3AF324 E00AC504 27A40020 */  addiu     $a0, $sp, 0x20
/* 3AF328 E00AC508 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 3AF32C E00AC50C 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 3AF330 E00AC510 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 3AF334 E00AC514 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 3AF338 E00AC518 96050000 */  lhu       $a1, ($s0)
/* 3AF33C E00AC51C 8E220000 */  lw        $v0, ($s1)
/* 3AF340 E00AC520 00052980 */  sll       $a1, $a1, 6
/* 3AF344 E00AC524 00B22821 */  addu      $a1, $a1, $s2
/* 3AF348 E00AC528 0C080118 */  jal       func_E0200460
/* 3AF34C E00AC52C 00452821 */   addu     $a1, $v0, $a1
/* 3AF350 E00AC530 3C09D838 */  lui       $t1, 0xd838
/* 3AF354 E00AC534 35290002 */  ori       $t1, $t1, 2
/* 3AF358 E00AC538 27A40020 */  addiu     $a0, $sp, 0x20
/* 3AF35C E00AC53C 3C15800A */  lui       $s5, %hi(gMasterGfxPos)
/* 3AF360 E00AC540 26B5A66C */  addiu     $s5, $s5, %lo(gMasterGfxPos)
/* 3AF364 E00AC544 3C13DA38 */  lui       $s3, 0xda38
/* 3AF368 E00AC548 3C16DE00 */  lui       $s6, 0xde00
/* 3AF36C E00AC54C 8EA80000 */  lw        $t0, ($s5)
/* 3AF370 E00AC550 4405A000 */  mfc1      $a1, $f20
/* 3AF374 E00AC554 0100302D */  daddu     $a2, $t0, $zero
/* 3AF378 E00AC558 25080008 */  addiu     $t0, $t0, 8
/* 3AF37C E00AC55C AEA80000 */  sw        $t0, ($s5)
/* 3AF380 E00AC560 96020000 */  lhu       $v0, ($s0)
/* 3AF384 E00AC564 00A0382D */  daddu     $a3, $a1, $zero
/* 3AF388 E00AC568 ACD30000 */  sw        $s3, ($a2)
/* 3AF38C E00AC56C 24430001 */  addiu     $v1, $v0, 1
/* 3AF390 E00AC570 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3AF394 E00AC574 00021180 */  sll       $v0, $v0, 6
/* 3AF398 E00AC578 A6030000 */  sh        $v1, ($s0)
/* 3AF39C E00AC57C 8E230000 */  lw        $v1, ($s1)
/* 3AF3A0 E00AC580 00521021 */  addu      $v0, $v0, $s2
/* 3AF3A4 E00AC584 00621821 */  addu      $v1, $v1, $v0
/* 3AF3A8 E00AC588 25020008 */  addiu     $v0, $t0, 8
/* 3AF3AC E00AC58C ACC30004 */  sw        $v1, 4($a2)
/* 3AF3B0 E00AC590 AEA20000 */  sw        $v0, ($s5)
/* 3AF3B4 E00AC594 25020010 */  addiu     $v0, $t0, 0x10
/* 3AF3B8 E00AC598 001E3080 */  sll       $a2, $fp, 2
/* 3AF3BC E00AC59C AD160000 */  sw        $s6, ($t0)
/* 3AF3C0 E00AC5A0 AEA20000 */  sw        $v0, ($s5)
/* 3AF3C4 E00AC5A4 3C03E00B */  lui       $v1, %hi(D_E00AC7B0)
/* 3AF3C8 E00AC5A8 00661821 */  addu      $v1, $v1, $a2
/* 3AF3CC E00AC5AC 8C63C7B0 */  lw        $v1, %lo(D_E00AC7B0)($v1)
/* 3AF3D0 E00AC5B0 3C02FA00 */  lui       $v0, 0xfa00
/* 3AF3D4 E00AC5B4 AD020008 */  sw        $v0, 8($t0)
/* 3AF3D8 E00AC5B8 AD030004 */  sw        $v1, 4($t0)
/* 3AF3DC E00AC5BC 92830027 */  lbu       $v1, 0x27($s4)
/* 3AF3E0 E00AC5C0 25020018 */  addiu     $v0, $t0, 0x18
/* 3AF3E4 E00AC5C4 AEA20000 */  sw        $v0, ($s5)
/* 3AF3E8 E00AC5C8 AD160010 */  sw        $s6, 0x10($t0)
/* 3AF3EC E00AC5CC AD03000C */  sw        $v1, 0xc($t0)
/* 3AF3F0 E00AC5D0 3C03E00B */  lui       $v1, %hi(D_E00AC7BC)
/* 3AF3F4 E00AC5D4 00661821 */  addu      $v1, $v1, $a2
/* 3AF3F8 E00AC5D8 8C63C7BC */  lw        $v1, %lo(D_E00AC7BC)($v1)
/* 3AF3FC E00AC5DC 25020020 */  addiu     $v0, $t0, 0x20
/* 3AF400 E00AC5E0 AEA20000 */  sw        $v0, ($s5)
/* 3AF404 E00AC5E4 24020040 */  addiu     $v0, $zero, 0x40
/* 3AF408 E00AC5E8 AD02001C */  sw        $v0, 0x1c($t0)
/* 3AF40C E00AC5EC 3C020900 */  lui       $v0, 0x900
/* 3AF410 E00AC5F0 244228E0 */  addiu     $v0, $v0, 0x28e0
/* 3AF414 E00AC5F4 AD090018 */  sw        $t1, 0x18($t0)
/* 3AF418 E00AC5F8 AD160020 */  sw        $s6, 0x20($t0)
/* 3AF41C E00AC5FC AD020024 */  sw        $v0, 0x24($t0)
/* 3AF420 E00AC600 AD030014 */  sw        $v1, 0x14($t0)
/* 3AF424 E00AC604 8E86003C */  lw        $a2, 0x3c($s4)
/* 3AF428 E00AC608 25080028 */  addiu     $t0, $t0, 0x28
/* 3AF42C E00AC60C 0C080108 */  jal       func_E0200420
/* 3AF430 E00AC610 AEA80000 */   sw       $t0, ($s5)
/* 3AF434 E00AC614 27A40020 */  addiu     $a0, $sp, 0x20
/* 3AF438 E00AC618 96050000 */  lhu       $a1, ($s0)
/* 3AF43C E00AC61C 8E220000 */  lw        $v0, ($s1)
/* 3AF440 E00AC620 00052980 */  sll       $a1, $a1, 6
/* 3AF444 E00AC624 00B22821 */  addu      $a1, $a1, $s2
/* 3AF448 E00AC628 0C080118 */  jal       func_E0200460
/* 3AF44C E00AC62C 00452821 */   addu     $a1, $v0, $a1
/* 3AF450 E00AC630 02E0302D */  daddu     $a2, $s7, $zero
/* 3AF454 E00AC634 8EA50000 */  lw        $a1, ($s5)
/* 3AF458 E00AC638 96020000 */  lhu       $v0, ($s0)
/* 3AF45C E00AC63C 00A0202D */  daddu     $a0, $a1, $zero
/* 3AF460 E00AC640 24A50008 */  addiu     $a1, $a1, 8
/* 3AF464 E00AC644 24430001 */  addiu     $v1, $v0, 1
/* 3AF468 E00AC648 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3AF46C E00AC64C 00021180 */  sll       $v0, $v0, 6
/* 3AF470 E00AC650 AEA50000 */  sw        $a1, ($s5)
/* 3AF474 E00AC654 AC930000 */  sw        $s3, ($a0)
/* 3AF478 E00AC658 A6030000 */  sh        $v1, ($s0)
/* 3AF47C E00AC65C 8E230000 */  lw        $v1, ($s1)
/* 3AF480 E00AC660 00521021 */  addu      $v0, $v0, $s2
/* 3AF484 E00AC664 00621821 */  addu      $v1, $v1, $v0
/* 3AF488 E00AC668 06E10002 */  bgez      $s7, .LE00AC674
/* 3AF48C E00AC66C AC830004 */   sw       $v1, 4($a0)
/* 3AF490 E00AC670 00173023 */  negu      $a2, $s7
.LE00AC674:
/* 3AF494 E00AC674 3C026666 */  lui       $v0, 0x6666
/* 3AF498 E00AC678 34426667 */  ori       $v0, $v0, 0x6667
/* 3AF49C E00AC67C 00C20018 */  mult      $a2, $v0
/* 3AF4A0 E00AC680 24A20008 */  addiu     $v0, $a1, 8
/* 3AF4A4 E00AC684 AEA20000 */  sw        $v0, ($s5)
/* 3AF4A8 E00AC688 000617C3 */  sra       $v0, $a2, 0x1f
/* 3AF4AC E00AC68C ACB60000 */  sw        $s6, ($a1)
/* 3AF4B0 E00AC690 00005010 */  mfhi      $t2
/* 3AF4B4 E00AC694 000A1883 */  sra       $v1, $t2, 2
/* 3AF4B8 E00AC698 00621823 */  subu      $v1, $v1, $v0
/* 3AF4BC E00AC69C 00031080 */  sll       $v0, $v1, 2
/* 3AF4C0 E00AC6A0 00431021 */  addu      $v0, $v0, $v1
/* 3AF4C4 E00AC6A4 00021040 */  sll       $v0, $v0, 1
/* 3AF4C8 E00AC6A8 00C21023 */  subu      $v0, $a2, $v0
/* 3AF4CC E00AC6AC 00021080 */  sll       $v0, $v0, 2
/* 3AF4D0 E00AC6B0 3C03E00B */  lui       $v1, %hi(D_E00AC7C8)
/* 3AF4D4 E00AC6B4 00621821 */  addu      $v1, $v1, $v0
/* 3AF4D8 E00AC6B8 8C63C7C8 */  lw        $v1, %lo(D_E00AC7C8)($v1)
/* 3AF4DC E00AC6BC 24A20010 */  addiu     $v0, $a1, 0x10
/* 3AF4E0 E00AC6C0 AEA20000 */  sw        $v0, ($s5)
/* 3AF4E4 E00AC6C4 3C020900 */  lui       $v0, 0x900
/* 3AF4E8 E00AC6C8 244228C0 */  addiu     $v0, $v0, 0x28c0
/* 3AF4EC E00AC6CC ACA2000C */  sw        $v0, 0xc($a1)
/* 3AF4F0 E00AC6D0 3C02E00B */  lui       $v0, %hi(D_E00AC7C8)
/* 3AF4F4 E00AC6D4 2442C7C8 */  addiu     $v0, $v0, %lo(D_E00AC7C8)
/* 3AF4F8 E00AC6D8 ACB60008 */  sw        $s6, 8($a1)
/* 3AF4FC E00AC6DC 06E00005 */  bltz      $s7, .LE00AC6F4
/* 3AF500 E00AC6E0 ACA30004 */   sw       $v1, 4($a1)
/* 3AF504 E00AC6E4 ACB60010 */  sw        $s6, 0x10($a1)
/* 3AF508 E00AC6E8 8C43002C */  lw        $v1, 0x2c($v0)
/* 3AF50C E00AC6EC 0802B1C0 */  j         .LE00AC700
/* 3AF510 E00AC6F0 24A20018 */   addiu    $v0, $a1, 0x18
.LE00AC6F4:
/* 3AF514 E00AC6F4 ACB60010 */  sw        $s6, 0x10($a1)
/* 3AF518 E00AC6F8 8C430028 */  lw        $v1, 0x28($v0)
/* 3AF51C E00AC6FC 24A20018 */  addiu     $v0, $a1, 0x18
.LE00AC700:
/* 3AF520 E00AC700 AEA20000 */  sw        $v0, ($s5)
/* 3AF524 E00AC704 ACA30014 */  sw        $v1, 0x14($a1)
/* 3AF528 E00AC708 3C06D838 */  lui       $a2, 0xd838
/* 3AF52C E00AC70C 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 3AF530 E00AC710 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 3AF534 E00AC714 34C60002 */  ori       $a2, $a2, 2
/* 3AF538 E00AC718 8C830000 */  lw        $v1, ($a0)
/* 3AF53C E00AC71C 3C02DE00 */  lui       $v0, 0xde00
/* 3AF540 E00AC720 0060282D */  daddu     $a1, $v1, $zero
/* 3AF544 E00AC724 24630008 */  addiu     $v1, $v1, 8
/* 3AF548 E00AC728 AC830000 */  sw        $v1, ($a0)
/* 3AF54C E00AC72C ACA20000 */  sw        $v0, ($a1)
/* 3AF550 E00AC730 3C020900 */  lui       $v0, 0x900
/* 3AF554 E00AC734 244228A0 */  addiu     $v0, $v0, 0x28a0
/* 3AF558 E00AC738 ACA20004 */  sw        $v0, 4($a1)
/* 3AF55C E00AC73C 24620008 */  addiu     $v0, $v1, 8
/* 3AF560 E00AC740 24050040 */  addiu     $a1, $zero, 0x40
/* 3AF564 E00AC744 AC820000 */  sw        $v0, ($a0)
/* 3AF568 E00AC748 24620010 */  addiu     $v0, $v1, 0x10
/* 3AF56C E00AC74C AC660000 */  sw        $a2, ($v1)
/* 3AF570 E00AC750 AC650004 */  sw        $a1, 4($v1)
/* 3AF574 E00AC754 AC820000 */  sw        $v0, ($a0)
/* 3AF578 E00AC758 24620018 */  addiu     $v0, $v1, 0x18
/* 3AF57C E00AC75C AC660008 */  sw        $a2, 8($v1)
/* 3AF580 E00AC760 AC65000C */  sw        $a1, 0xc($v1)
/* 3AF584 E00AC764 AC820000 */  sw        $v0, ($a0)
/* 3AF588 E00AC768 3C02E700 */  lui       $v0, 0xe700
/* 3AF58C E00AC76C AC620010 */  sw        $v0, 0x10($v1)
/* 3AF590 E00AC770 AC600014 */  sw        $zero, 0x14($v1)
.LE00AC774:
/* 3AF594 E00AC774 8FBF00C4 */  lw        $ra, 0xc4($sp)
/* 3AF598 E00AC778 8FBE00C0 */  lw        $fp, 0xc0($sp)
/* 3AF59C E00AC77C 8FB700BC */  lw        $s7, 0xbc($sp)
/* 3AF5A0 E00AC780 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 3AF5A4 E00AC784 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 3AF5A8 E00AC788 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 3AF5AC E00AC78C 8FB300AC */  lw        $s3, 0xac($sp)
/* 3AF5B0 E00AC790 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 3AF5B4 E00AC794 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 3AF5B8 E00AC798 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 3AF5BC E00AC79C D7B400C8 */  ldc1      $f20, 0xc8($sp)
/* 3AF5C0 E00AC7A0 03E00008 */  jr        $ra
/* 3AF5C4 E00AC7A4 27BD00D0 */   addiu    $sp, $sp, 0xd0
/* 3AF5C8 E00AC7A8 00000000 */  nop       
/* 3AF5CC E00AC7AC 00000000 */  nop       
