.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E003245C
/* 343ADC E003245C 27BDFF30 */  addiu     $sp, $sp, -0xd0
/* 343AE0 E0032460 0080302D */  daddu     $a2, $a0, $zero
/* 343AE4 E0032464 3C07DB06 */  lui       $a3, 0xdb06
/* 343AE8 E0032468 34E70024 */  ori       $a3, $a3, 0x24
/* 343AEC E003246C 27A40018 */  addiu     $a0, $sp, 0x18
/* 343AF0 E0032470 AFB600B0 */  sw        $s6, 0xb0($sp)
/* 343AF4 E0032474 3C160001 */  lui       $s6, 1
/* 343AF8 E0032478 36D61630 */  ori       $s6, $s6, 0x1630
/* 343AFC E003247C AFB200A0 */  sw        $s2, 0xa0($sp)
/* 343B00 E0032480 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* 343B04 E0032484 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* 343B08 E0032488 AFBF00B8 */  sw        $ra, 0xb8($sp)
/* 343B0C E003248C AFB700B4 */  sw        $s7, 0xb4($sp)
/* 343B10 E0032490 AFB500AC */  sw        $s5, 0xac($sp)
/* 343B14 E0032494 AFB400A8 */  sw        $s4, 0xa8($sp)
/* 343B18 E0032498 AFB300A4 */  sw        $s3, 0xa4($sp)
/* 343B1C E003249C AFB1009C */  sw        $s1, 0x9c($sp)
/* 343B20 E00324A0 AFB00098 */  sw        $s0, 0x98($sp)
/* 343B24 E00324A4 F7B600C8 */  sdc1      $f22, 0xc8($sp)
/* 343B28 E00324A8 F7B400C0 */  sdc1      $f20, 0xc0($sp)
/* 343B2C E00324AC 8E450000 */  lw        $a1, ($s2)
/* 343B30 E00324B0 8CD1000C */  lw        $s1, 0xc($a2)
/* 343B34 E00324B4 00A0182D */  daddu     $v1, $a1, $zero
/* 343B38 E00324B8 24A50008 */  addiu     $a1, $a1, 8
/* 343B3C E00324BC AE450000 */  sw        $a1, ($s2)
/* 343B40 E00324C0 8E330034 */  lw        $s3, 0x34($s1)
/* 343B44 E00324C4 3C02E700 */  lui       $v0, 0xe700
/* 343B48 E00324C8 AC620000 */  sw        $v0, ($v1)
/* 343B4C E00324CC AC600004 */  sw        $zero, 4($v1)
/* 343B50 E00324D0 ACA70000 */  sw        $a3, ($a1)
/* 343B54 E00324D4 8CC30010 */  lw        $v1, 0x10($a2)
/* 343B58 E00324D8 24A20008 */  addiu     $v0, $a1, 8
/* 343B5C E00324DC AE420000 */  sw        $v0, ($s2)
/* 343B60 E00324E0 8C62001C */  lw        $v0, 0x1c($v1)
/* 343B64 E00324E4 3C038000 */  lui       $v1, 0x8000
/* 343B68 E00324E8 00431021 */  addu      $v0, $v0, $v1
/* 343B6C E00324EC ACA20004 */  sw        $v0, 4($a1)
/* 343B70 E00324F0 8E250004 */  lw        $a1, 4($s1)
/* 343B74 E00324F4 8E260008 */  lw        $a2, 8($s1)
/* 343B78 E00324F8 8E27000C */  lw        $a3, 0xc($s1)
/* 343B7C E00324FC 0C080108 */  jal       func_E0200420
/* 343B80 E0032500 2631003C */   addiu    $s1, $s1, 0x3c
/* 343B84 E0032504 27B50058 */  addiu     $s5, $sp, 0x58
/* 343B88 E0032508 4480B000 */  mtc1      $zero, $f22
/* 343B8C E003250C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 343B90 E0032510 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 343B94 E0032514 3C013F80 */  lui       $at, 0x3f80
/* 343B98 E0032518 4481A000 */  mtc1      $at, $f20
/* 343B9C E003251C 00031080 */  sll       $v0, $v1, 2
/* 343BA0 E0032520 00431021 */  addu      $v0, $v0, $v1
/* 343BA4 E0032524 00021080 */  sll       $v0, $v0, 2
/* 343BA8 E0032528 00431023 */  subu      $v0, $v0, $v1
/* 343BAC E003252C 000218C0 */  sll       $v1, $v0, 3
/* 343BB0 E0032530 00431021 */  addu      $v0, $v0, $v1
/* 343BB4 E0032534 000210C0 */  sll       $v0, $v0, 3
/* 343BB8 E0032538 4406B000 */  mfc1      $a2, $f22
/* 343BBC E003253C 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 343BC0 E0032540 00220821 */  addu      $at, $at, $v0
/* 343BC4 E0032544 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 343BC8 E0032548 4407A000 */  mfc1      $a3, $f20
/* 343BCC E003254C 46000007 */  neg.s     $f0, $f0
/* 343BD0 E0032550 44050000 */  mfc1      $a1, $f0
/* 343BD4 E0032554 02A0202D */  daddu     $a0, $s5, $zero
/* 343BD8 E0032558 0C080104 */  jal       func_E0200410
/* 343BDC E003255C E7B60010 */   swc1     $f22, 0x10($sp)
/* 343BE0 E0032560 02A0202D */  daddu     $a0, $s5, $zero
/* 343BE4 E0032564 27A50018 */  addiu     $a1, $sp, 0x18
/* 343BE8 E0032568 0C080114 */  jal       func_E0200450
/* 343BEC E003256C 00A0302D */   daddu    $a2, $a1, $zero
/* 343BF0 E0032570 27A40018 */  addiu     $a0, $sp, 0x18
/* 343BF4 E0032574 3C148007 */  lui       $s4, %hi(gMatrixListPos)
/* 343BF8 E0032578 269441F0 */  addiu     $s4, $s4, %lo(gMatrixListPos)
/* 343BFC E003257C 3C17800A */  lui       $s7, %hi(gDisplayContext)
/* 343C00 E0032580 26F7A674 */  addiu     $s7, $s7, %lo(gDisplayContext)
/* 343C04 E0032584 96850000 */  lhu       $a1, ($s4)
/* 343C08 E0032588 8EE20000 */  lw        $v0, ($s7)
/* 343C0C E003258C 00052980 */  sll       $a1, $a1, 6
/* 343C10 E0032590 00B62821 */  addu      $a1, $a1, $s6
/* 343C14 E0032594 0C080118 */  jal       func_E0200460
/* 343C18 E0032598 00452821 */   addu     $a1, $v0, $a1
/* 343C1C E003259C 3C03DA38 */  lui       $v1, 0xda38
/* 343C20 E00325A0 34630002 */  ori       $v1, $v1, 2
/* 343C24 E00325A4 8E460000 */  lw        $a2, ($s2)
/* 343C28 E00325A8 96820000 */  lhu       $v0, ($s4)
/* 343C2C E00325AC 00C0202D */  daddu     $a0, $a2, $zero
/* 343C30 E00325B0 24C60008 */  addiu     $a2, $a2, 8
/* 343C34 E00325B4 AE460000 */  sw        $a2, ($s2)
/* 343C38 E00325B8 AC830000 */  sw        $v1, ($a0)
/* 343C3C E00325BC 24430001 */  addiu     $v1, $v0, 1
/* 343C40 E00325C0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 343C44 E00325C4 00021180 */  sll       $v0, $v0, 6
/* 343C48 E00325C8 A6830000 */  sh        $v1, ($s4)
/* 343C4C E00325CC 8EE30000 */  lw        $v1, ($s7)
/* 343C50 E00325D0 00561021 */  addu      $v0, $v0, $s6
/* 343C54 E00325D4 00621821 */  addu      $v1, $v1, $v0
/* 343C58 E00325D8 AC830004 */  sw        $v1, 4($a0)
/* 343C5C E00325DC 8E230000 */  lw        $v1, ($s1)
/* 343C60 E00325E0 2402FFFF */  addiu     $v0, $zero, -1
/* 343C64 E00325E4 10620037 */  beq       $v1, $v0, .LE00326C4
/* 343C68 E00325E8 27A40018 */   addiu    $a0, $sp, 0x18
/* 343C6C E00325EC 3C10DE00 */  lui       $s0, 0xde00
/* 343C70 E00325F0 3C020900 */  lui       $v0, 0x900
/* 343C74 E00325F4 24420840 */  addiu     $v0, $v0, 0x840
/* 343C78 E00325F8 ACD00000 */  sw        $s0, ($a2)
/* 343C7C E00325FC ACC20004 */  sw        $v0, 4($a2)
/* 343C80 E0032600 8E250020 */  lw        $a1, 0x20($s1)
/* 343C84 E0032604 4407A000 */  mfc1      $a3, $f20
/* 343C88 E0032608 24C20008 */  addiu     $v0, $a2, 8
/* 343C8C E003260C AE420000 */  sw        $v0, ($s2)
/* 343C90 E0032610 0C080110 */  jal       func_E0200440
/* 343C94 E0032614 00A0302D */   daddu    $a2, $a1, $zero
/* 343C98 E0032618 27A40018 */  addiu     $a0, $sp, 0x18
/* 343C9C E003261C 96850000 */  lhu       $a1, ($s4)
/* 343CA0 E0032620 8EE20000 */  lw        $v0, ($s7)
/* 343CA4 E0032624 00052980 */  sll       $a1, $a1, 6
/* 343CA8 E0032628 00B62821 */  addu      $a1, $a1, $s6
/* 343CAC E003262C 0C080118 */  jal       func_E0200460
/* 343CB0 E0032630 00452821 */   addu     $a1, $v0, $a1
/* 343CB4 E0032634 3C07D838 */  lui       $a3, 0xd838
/* 343CB8 E0032638 34E70002 */  ori       $a3, $a3, 2
/* 343CBC E003263C 8E440000 */  lw        $a0, ($s2)
/* 343CC0 E0032640 3C02FA00 */  lui       $v0, 0xfa00
/* 343CC4 E0032644 0080302D */  daddu     $a2, $a0, $zero
/* 343CC8 E0032648 24840008 */  addiu     $a0, $a0, 8
/* 343CCC E003264C AE440000 */  sw        $a0, ($s2)
/* 343CD0 E0032650 ACC20000 */  sw        $v0, ($a2)
/* 343CD4 E0032654 9225003B */  lbu       $a1, 0x3b($s1)
/* 343CD8 E0032658 96830000 */  lhu       $v1, ($s4)
/* 343CDC E003265C 24820008 */  addiu     $v0, $a0, 8
/* 343CE0 E0032660 AE420000 */  sw        $v0, ($s2)
/* 343CE4 E0032664 24620001 */  addiu     $v0, $v1, 1
/* 343CE8 E0032668 A6820000 */  sh        $v0, ($s4)
/* 343CEC E003266C 24820010 */  addiu     $v0, $a0, 0x10
/* 343CF0 E0032670 AE420000 */  sw        $v0, ($s2)
/* 343CF4 E0032674 24820018 */  addiu     $v0, $a0, 0x18
/* 343CF8 E0032678 AE420000 */  sw        $v0, ($s2)
/* 343CFC E003267C 2402F000 */  addiu     $v0, $zero, -0x1000
/* 343D00 E0032680 00A22825 */  or        $a1, $a1, $v0
/* 343D04 E0032684 3C02DA38 */  lui       $v0, 0xda38
/* 343D08 E0032688 3063FFFF */  andi      $v1, $v1, 0xffff
/* 343D0C E003268C 00031980 */  sll       $v1, $v1, 6
/* 343D10 E0032690 ACC50004 */  sw        $a1, 4($a2)
/* 343D14 E0032694 AC820000 */  sw        $v0, ($a0)
/* 343D18 E0032698 8EE20000 */  lw        $v0, ($s7)
/* 343D1C E003269C 00761821 */  addu      $v1, $v1, $s6
/* 343D20 E00326A0 AC900008 */  sw        $s0, 8($a0)
/* 343D24 E00326A4 AC870010 */  sw        $a3, 0x10($a0)
/* 343D28 E00326A8 00431021 */  addu      $v0, $v0, $v1
/* 343D2C E00326AC AC820004 */  sw        $v0, 4($a0)
/* 343D30 E00326B0 3C020900 */  lui       $v0, 0x900
/* 343D34 E00326B4 244208F0 */  addiu     $v0, $v0, 0x8f0
/* 343D38 E00326B8 AC82000C */  sw        $v0, 0xc($a0)
/* 343D3C E00326BC 24020040 */  addiu     $v0, $zero, 0x40
/* 343D40 E00326C0 AC820014 */  sw        $v0, 0x14($a0)
.LE00326C4:
/* 343D44 E00326C4 2631003C */  addiu     $s1, $s1, 0x3c
/* 343D48 E00326C8 27A40018 */  addiu     $a0, $sp, 0x18
/* 343D4C E00326CC 8E430000 */  lw        $v1, ($s2)
/* 343D50 E00326D0 3C02DE00 */  lui       $v0, 0xde00
/* 343D54 E00326D4 0060282D */  daddu     $a1, $v1, $zero
/* 343D58 E00326D8 ACA20000 */  sw        $v0, ($a1)
/* 343D5C E00326DC 3C020900 */  lui       $v0, 0x900
/* 343D60 E00326E0 24420910 */  addiu     $v0, $v0, 0x910
/* 343D64 E00326E4 ACA20004 */  sw        $v0, 4($a1)
/* 343D68 E00326E8 8E250020 */  lw        $a1, 0x20($s1)
/* 343D6C E00326EC 24630008 */  addiu     $v1, $v1, 8
/* 343D70 E00326F0 AE430000 */  sw        $v1, ($s2)
/* 343D74 E00326F4 00A0302D */  daddu     $a2, $a1, $zero
/* 343D78 E00326F8 0C080110 */  jal       func_E0200440
/* 343D7C E00326FC 00A0382D */   daddu    $a3, $a1, $zero
/* 343D80 E0032700 4406B000 */  mfc1      $a2, $f22
/* 343D84 E0032704 02A0202D */  daddu     $a0, $s5, $zero
/* 343D88 E0032708 E7B40010 */  swc1      $f20, 0x10($sp)
/* 343D8C E003270C 8E250028 */  lw        $a1, 0x28($s1)
/* 343D90 E0032710 0C080104 */  jal       func_E0200410
/* 343D94 E0032714 00C0382D */   daddu    $a3, $a2, $zero
/* 343D98 E0032718 02A0202D */  daddu     $a0, $s5, $zero
/* 343D9C E003271C 27A50018 */  addiu     $a1, $sp, 0x18
/* 343DA0 E0032720 0C080114 */  jal       func_E0200450
/* 343DA4 E0032724 00A0302D */   daddu    $a2, $a1, $zero
/* 343DA8 E0032728 27A40018 */  addiu     $a0, $sp, 0x18
/* 343DAC E003272C 96850000 */  lhu       $a1, ($s4)
/* 343DB0 E0032730 8EE20000 */  lw        $v0, ($s7)
/* 343DB4 E0032734 00052980 */  sll       $a1, $a1, 6
/* 343DB8 E0032738 00B62821 */  addu      $a1, $a1, $s6
/* 343DBC E003273C 0C080118 */  jal       func_E0200460
/* 343DC0 E0032740 00452821 */   addu     $a1, $v0, $a1
/* 343DC4 E0032744 24020001 */  addiu     $v0, $zero, 1
/* 343DC8 E0032748 12620006 */  beq       $s3, $v0, .LE0032764
/* 343DCC E003274C 24020002 */   addiu    $v0, $zero, 2
/* 343DD0 E0032750 12620005 */  beq       $s3, $v0, .LE0032768
/* 343DD4 E0032754 240400FF */   addiu    $a0, $zero, 0xff
/* 343DD8 E0032758 8E240038 */  lw        $a0, 0x38($s1)
/* 343DDC E003275C 0800C9DB */  j         .LE003276C
/* 343DE0 E0032760 2A620003 */   slti     $v0, $s3, 3
.LE0032764:
/* 343DE4 E0032764 240400C0 */  addiu     $a0, $zero, 0xc0
.LE0032768:
/* 343DE8 E0032768 2A620003 */  slti      $v0, $s3, 3
.LE003276C:
/* 343DEC E003276C 14400005 */  bnez      $v0, .LE0032784
/* 343DF0 E0032770 240300FF */   addiu    $v1, $zero, 0xff
/* 343DF4 E0032774 2A620008 */  slti      $v0, $s3, 8
/* 343DF8 E0032778 10400002 */  beqz      $v0, .LE0032784
/* 343DFC E003277C 00131100 */   sll      $v0, $s3, 4
/* 343E00 E0032780 24430080 */  addiu     $v1, $v0, 0x80
.LE0032784:
/* 343E04 E0032784 3C080001 */  lui       $t0, 1
/* 343E08 E0032788 35081630 */  ori       $t0, $t0, 0x1630
/* 343E0C E003278C 3C0A5555 */  lui       $t2, 0x5555
/* 343E10 E0032790 354A5556 */  ori       $t2, $t2, 0x5556
/* 343E14 E0032794 3C09D838 */  lui       $t1, 0xd838
/* 343E18 E0032798 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 343E1C E003279C 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 343E20 E00327A0 35290002 */  ori       $t1, $t1, 2
/* 343E24 E00327A4 3C02FA00 */  lui       $v0, 0xfa00
/* 343E28 E00327A8 306300FF */  andi      $v1, $v1, 0xff
/* 343E2C E00327AC 00031A00 */  sll       $v1, $v1, 8
/* 343E30 E00327B0 8CC50000 */  lw        $a1, ($a2)
/* 343E34 E00327B4 026A0018 */  mult      $s3, $t2
/* 343E38 E00327B8 00A0382D */  daddu     $a3, $a1, $zero
/* 343E3C E00327BC 24A50008 */  addiu     $a1, $a1, 8
/* 343E40 E00327C0 ACC50000 */  sw        $a1, ($a2)
/* 343E44 E00327C4 ACE20000 */  sw        $v0, ($a3)
/* 343E48 E00327C8 308200FF */  andi      $v0, $a0, 0xff
/* 343E4C E00327CC 3C04FFFF */  lui       $a0, 0xffff
/* 343E50 E00327D0 00441025 */  or        $v0, $v0, $a0
/* 343E54 E00327D4 00621825 */  or        $v1, $v1, $v0
/* 343E58 E00327D8 24A20008 */  addiu     $v0, $a1, 8
/* 343E5C E00327DC 3C048007 */  lui       $a0, %hi(gMatrixListPos)
/* 343E60 E00327E0 248441F0 */  addiu     $a0, $a0, %lo(gMatrixListPos)
/* 343E64 E00327E4 ACE30004 */  sw        $v1, 4($a3)
/* 343E68 E00327E8 ACC20000 */  sw        $v0, ($a2)
/* 343E6C E00327EC 94820000 */  lhu       $v0, ($a0)
/* 343E70 E00327F0 3C03DA38 */  lui       $v1, 0xda38
/* 343E74 E00327F4 ACA30000 */  sw        $v1, ($a1)
/* 343E78 E00327F8 24430001 */  addiu     $v1, $v0, 1
/* 343E7C E00327FC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 343E80 E0032800 00021180 */  sll       $v0, $v0, 6
/* 343E84 E0032804 A4830000 */  sh        $v1, ($a0)
/* 343E88 E0032808 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 343E8C E003280C 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 343E90 E0032810 00481021 */  addu      $v0, $v0, $t0
/* 343E94 E0032814 00621821 */  addu      $v1, $v1, $v0
/* 343E98 E0032818 24A20010 */  addiu     $v0, $a1, 0x10
/* 343E9C E003281C ACA30004 */  sw        $v1, 4($a1)
/* 343EA0 E0032820 ACC20000 */  sw        $v0, ($a2)
/* 343EA4 E0032824 3C02DE00 */  lui       $v0, 0xde00
/* 343EA8 E0032828 ACA20008 */  sw        $v0, 8($a1)
/* 343EAC E003282C 24A20018 */  addiu     $v0, $a1, 0x18
/* 343EB0 E0032830 00131FC3 */  sra       $v1, $s3, 0x1f
/* 343EB4 E0032834 ACC20000 */  sw        $v0, ($a2)
/* 343EB8 E0032838 00005810 */  mfhi      $t3
/* 343EBC E003283C 01631823 */  subu      $v1, $t3, $v1
/* 343EC0 E0032840 00031040 */  sll       $v0, $v1, 1
/* 343EC4 E0032844 00431021 */  addu      $v0, $v0, $v1
/* 343EC8 E0032848 02621023 */  subu      $v0, $s3, $v0
/* 343ECC E003284C 00021080 */  sll       $v0, $v0, 2
/* 343ED0 E0032850 3C03E003 */  lui       $v1, %hi(D_E00328B0)
/* 343ED4 E0032854 00621821 */  addu      $v1, $v1, $v0
/* 343ED8 E0032858 8C6328B0 */  lw        $v1, %lo(D_E00328B0)($v1)
/* 343EDC E003285C 24A20020 */  addiu     $v0, $a1, 0x20
/* 343EE0 E0032860 ACC20000 */  sw        $v0, ($a2)
/* 343EE4 E0032864 24020040 */  addiu     $v0, $zero, 0x40
/* 343EE8 E0032868 ACA90010 */  sw        $t1, 0x10($a1)
/* 343EEC E003286C ACA20014 */  sw        $v0, 0x14($a1)
/* 343EF0 E0032870 ACA90018 */  sw        $t1, 0x18($a1)
/* 343EF4 E0032874 ACA2001C */  sw        $v0, 0x1c($a1)
/* 343EF8 E0032878 ACA3000C */  sw        $v1, 0xc($a1)
/* 343EFC E003287C 8FBF00B8 */  lw        $ra, 0xb8($sp)
/* 343F00 E0032880 8FB700B4 */  lw        $s7, 0xb4($sp)
/* 343F04 E0032884 8FB600B0 */  lw        $s6, 0xb0($sp)
/* 343F08 E0032888 8FB500AC */  lw        $s5, 0xac($sp)
/* 343F0C E003288C 8FB400A8 */  lw        $s4, 0xa8($sp)
/* 343F10 E0032890 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 343F14 E0032894 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 343F18 E0032898 8FB1009C */  lw        $s1, 0x9c($sp)
/* 343F1C E003289C 8FB00098 */  lw        $s0, 0x98($sp)
/* 343F20 E00328A0 D7B600C8 */  ldc1      $f22, 0xc8($sp)
/* 343F24 E00328A4 D7B400C0 */  ldc1      $f20, 0xc0($sp)
/* 343F28 E00328A8 03E00008 */  jr        $ra
/* 343F2C E00328AC 27BD00D0 */   addiu    $sp, $sp, 0xd0
