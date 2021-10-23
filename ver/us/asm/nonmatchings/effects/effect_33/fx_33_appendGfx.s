.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_33_appendGfx
/* 354B58 E00423B8 27BDFF28 */  addiu     $sp, $sp, -0xd8
/* 354B5C E00423BC 3C05DB06 */  lui       $a1, 0xdb06
/* 354B60 E00423C0 34A50024 */  ori       $a1, $a1, 0x24
/* 354B64 E00423C4 3C0638E3 */  lui       $a2, 0x38e3
/* 354B68 E00423C8 34C68E39 */  ori       $a2, $a2, 0x8e39
/* 354B6C E00423CC 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* 354B70 E00423D0 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* 354B74 E00423D4 3C02E700 */  lui       $v0, 0xe700
/* 354B78 E00423D8 AFBF00C4 */  sw        $ra, 0xc4($sp)
/* 354B7C E00423DC AFBE00C0 */  sw        $fp, 0xc0($sp)
/* 354B80 E00423E0 AFB700BC */  sw        $s7, 0xbc($sp)
/* 354B84 E00423E4 AFB600B8 */  sw        $s6, 0xb8($sp)
/* 354B88 E00423E8 AFB500B4 */  sw        $s5, 0xb4($sp)
/* 354B8C E00423EC AFB400B0 */  sw        $s4, 0xb0($sp)
/* 354B90 E00423F0 AFB300AC */  sw        $s3, 0xac($sp)
/* 354B94 E00423F4 AFB200A8 */  sw        $s2, 0xa8($sp)
/* 354B98 E00423F8 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 354B9C E00423FC AFB000A0 */  sw        $s0, 0xa0($sp)
/* 354BA0 E0042400 F7B600D0 */  sdc1      $f22, 0xd0($sp)
/* 354BA4 E0042404 F7B400C8 */  sdc1      $f20, 0xc8($sp)
/* 354BA8 E0042408 AFA400D8 */  sw        $a0, 0xd8($sp)
/* 354BAC E004240C 8D040000 */  lw        $a0, ($t0)
/* 354BB0 E0042410 8FA900D8 */  lw        $t1, 0xd8($sp)
/* 354BB4 E0042414 0080182D */  daddu     $v1, $a0, $zero
/* 354BB8 E0042418 8D27000C */  lw        $a3, 0xc($t1)
/* 354BBC E004241C 24840008 */  addiu     $a0, $a0, 8
/* 354BC0 E0042420 AC620000 */  sw        $v0, ($v1)
/* 354BC4 E0042424 AC600004 */  sw        $zero, 4($v1)
/* 354BC8 E0042428 AC850000 */  sw        $a1, ($a0)
/* 354BCC E004242C 8D220010 */  lw        $v0, 0x10($t1)
/* 354BD0 E0042430 24150001 */  addiu     $s5, $zero, 1
/* 354BD4 E0042434 AD040000 */  sw        $a0, ($t0)
/* 354BD8 E0042438 8C43001C */  lw        $v1, 0x1c($v0)
/* 354BDC E004243C 3C02DE00 */  lui       $v0, 0xde00
/* 354BE0 E0042440 AC820008 */  sw        $v0, 8($a0)
/* 354BE4 E0042444 3C020900 */  lui       $v0, 0x900
/* 354BE8 E0042448 244204C0 */  addiu     $v0, $v0, 0x4c0
/* 354BEC E004244C AC82000C */  sw        $v0, 0xc($a0)
/* 354BF0 E0042450 3C028000 */  lui       $v0, 0x8000
/* 354BF4 E0042454 00621821 */  addu      $v1, $v1, $v0
/* 354BF8 E0042458 AC830004 */  sw        $v1, 4($a0)
/* 354BFC E004245C 24830008 */  addiu     $v1, $a0, 8
/* 354C00 E0042460 8CE20034 */  lw        $v0, 0x34($a3)
/* 354C04 E0042464 24840010 */  addiu     $a0, $a0, 0x10
/* 354C08 E0042468 AD030000 */  sw        $v1, ($t0)
/* 354C0C E004246C 2442FFFF */  addiu     $v0, $v0, -1
/* 354C10 E0042470 02A21804 */  sllv      $v1, $v0, $s5
/* 354C14 E0042474 00629821 */  addu      $s3, $v1, $v0
/* 354C18 E0042478 02660018 */  mult      $s3, $a2
/* 354C1C E004247C AD040000 */  sw        $a0, ($t0)
/* 354C20 E0042480 8CE9002C */  lw        $t1, 0x2c($a3)
/* 354C24 E0042484 001317C3 */  sra       $v0, $s3, 0x1f
/* 354C28 E0042488 AFA90098 */  sw        $t1, 0x98($sp)
/* 354C2C E004248C 00004810 */  mfhi      $t1
/* 354C30 E0042490 000918C3 */  sra       $v1, $t1, 3
/* 354C34 E0042494 00621823 */  subu      $v1, $v1, $v0
/* 354C38 E0042498 000310C0 */  sll       $v0, $v1, 3
/* 354C3C E004249C 00431021 */  addu      $v0, $v0, $v1
/* 354C40 E00424A0 00021080 */  sll       $v0, $v0, 2
/* 354C44 E00424A4 8FA900D8 */  lw        $t1, 0xd8($sp)
/* 354C48 E00424A8 02629823 */  subu      $s3, $s3, $v0
/* 354C4C E00424AC 8D220008 */  lw        $v0, 8($t1)
/* 354C50 E00424B0 02A2102A */  slt       $v0, $s5, $v0
/* 354C54 E00424B4 104000A1 */  beqz      $v0, .LE004273C
/* 354C58 E00424B8 24E70038 */   addiu    $a3, $a3, 0x38
/* 354C5C E00424BC 0100A02D */  daddu     $s4, $t0, $zero
/* 354C60 E00424C0 3C1E38E3 */  lui       $fp, 0x38e3
/* 354C64 E00424C4 37DE8E39 */  ori       $fp, $fp, 0x8e39
/* 354C68 E00424C8 27B20058 */  addiu     $s2, $sp, 0x58
/* 354C6C E00424CC 3C090001 */  lui       $t1, 1
/* 354C70 E00424D0 35291630 */  ori       $t1, $t1, 0x1630
/* 354C74 E00424D4 24F00024 */  addiu     $s0, $a3, 0x24
/* 354C78 E00424D8 24170005 */  addiu     $s7, $zero, 5
/* 354C7C E00424DC 24160004 */  addiu     $s6, $zero, 4
/* 354C80 E00424E0 4480B000 */  mtc1      $zero, $f22
/* 354C84 E00424E4 3C013F80 */  lui       $at, 0x3f80
/* 354C88 E00424E8 4481A000 */  mtc1      $at, $f20
/* 354C8C E00424EC 26710003 */  addiu     $s1, $s3, 3
/* 354C90 E00424F0 AFA9009C */  sw        $t1, 0x9c($sp)
.LE00424F4:
/* 354C94 E00424F4 27A40018 */  addiu     $a0, $sp, 0x18
/* 354C98 E00424F8 02773821 */  addu      $a3, $s3, $s7
/* 354C9C E00424FC 26F70003 */  addiu     $s7, $s7, 3
/* 354CA0 E0042500 02763021 */  addu      $a2, $s3, $s6
/* 354CA4 E0042504 26D60003 */  addiu     $s6, $s6, 3
/* 354CA8 E0042508 26B50001 */  addiu     $s5, $s5, 1
/* 354CAC E004250C 8E820000 */  lw        $v0, ($s4)
/* 354CB0 E0042510 023E0018 */  mult      $s1, $fp
/* 354CB4 E0042514 0040402D */  daddu     $t0, $v0, $zero
/* 354CB8 E0042518 24420008 */  addiu     $v0, $v0, 8
/* 354CBC E004251C AE820000 */  sw        $v0, ($s4)
/* 354CC0 E0042520 3C02FA00 */  lui       $v0, 0xfa00
/* 354CC4 E0042524 AD020000 */  sw        $v0, ($t0)
/* 354CC8 E0042528 001117C3 */  sra       $v0, $s1, 0x1f
/* 354CCC E004252C 00004810 */  mfhi      $t1
/* 354CD0 E0042530 000918C3 */  sra       $v1, $t1, 3
/* 354CD4 E0042534 00621823 */  subu      $v1, $v1, $v0
/* 354CD8 E0042538 000328C0 */  sll       $a1, $v1, 3
/* 354CDC E004253C 00A32821 */  addu      $a1, $a1, $v1
/* 354CE0 E0042540 00052880 */  sll       $a1, $a1, 2
/* 354CE4 E0042544 02252823 */  subu      $a1, $s1, $a1
/* 354CE8 E0042548 3C09E004 */  lui       $t1, %hi(D_E0042780)
/* 354CEC E004254C 25292780 */  addiu     $t1, $t1, %lo(D_E0042780)
/* 354CF0 E0042550 00DE0018 */  mult      $a2, $fp
/* 354CF4 E0042554 00A92821 */  addu      $a1, $a1, $t1
/* 354CF8 E0042558 90A50000 */  lbu       $a1, ($a1)
/* 354CFC E004255C 000617C3 */  sra       $v0, $a2, 0x1f
/* 354D00 E0042560 00052E00 */  sll       $a1, $a1, 0x18
/* 354D04 E0042564 00004810 */  mfhi      $t1
/* 354D08 E0042568 000918C3 */  sra       $v1, $t1, 3
/* 354D0C E004256C 00621823 */  subu      $v1, $v1, $v0
/* 354D10 E0042570 000310C0 */  sll       $v0, $v1, 3
/* 354D14 E0042574 00431021 */  addu      $v0, $v0, $v1
/* 354D18 E0042578 00021080 */  sll       $v0, $v0, 2
/* 354D1C E004257C 00C23023 */  subu      $a2, $a2, $v0
/* 354D20 E0042580 3C09E004 */  lui       $t1, %hi(D_E0042780)
/* 354D24 E0042584 25292780 */  addiu     $t1, $t1, %lo(D_E0042780)
/* 354D28 E0042588 00C93021 */  addu      $a2, $a2, $t1
/* 354D2C E004258C 00FE0018 */  mult      $a3, $fp
/* 354D30 E0042590 90C60000 */  lbu       $a2, ($a2)
/* 354D34 E0042594 000717C3 */  sra       $v0, $a3, 0x1f
/* 354D38 E0042598 00063400 */  sll       $a2, $a2, 0x10
/* 354D3C E004259C 00A62825 */  or        $a1, $a1, $a2
/* 354D40 E00425A0 00004810 */  mfhi      $t1
/* 354D44 E00425A4 000918C3 */  sra       $v1, $t1, 3
/* 354D48 E00425A8 00621823 */  subu      $v1, $v1, $v0
/* 354D4C E00425AC 000310C0 */  sll       $v0, $v1, 3
/* 354D50 E00425B0 00431021 */  addu      $v0, $v0, $v1
/* 354D54 E00425B4 00021080 */  sll       $v0, $v0, 2
/* 354D58 E00425B8 00E23823 */  subu      $a3, $a3, $v0
/* 354D5C E00425BC 3C09E004 */  lui       $t1, %hi(D_E0042780)
/* 354D60 E00425C0 25292780 */  addiu     $t1, $t1, %lo(D_E0042780)
/* 354D64 E00425C4 00E93821 */  addu      $a3, $a3, $t1
/* 354D68 E00425C8 90E20000 */  lbu       $v0, ($a3)
/* 354D6C E00425CC 8FA90098 */  lw        $t1, 0x98($sp)
/* 354D70 E00425D0 00021200 */  sll       $v0, $v0, 8
/* 354D74 E00425D4 00A22825 */  or        $a1, $a1, $v0
/* 354D78 E00425D8 312200FF */  andi      $v0, $t1, 0xff
/* 354D7C E00425DC 00A22825 */  or        $a1, $a1, $v0
/* 354D80 E00425E0 AD050004 */  sw        $a1, 4($t0)
/* 354D84 E00425E4 8E05FFE0 */  lw        $a1, -0x20($s0)
/* 354D88 E00425E8 8E06FFE4 */  lw        $a2, -0x1c($s0)
/* 354D8C E00425EC 8E07FFE8 */  lw        $a3, -0x18($s0)
/* 354D90 E00425F0 0C080108 */  jal       shim_guTranslateF
/* 354D94 E00425F4 26310003 */   addiu    $s1, $s1, 3
/* 354D98 E00425F8 3C09800B */  lui       $t1, %hi(gCameras)
/* 354D9C E00425FC 25291D80 */  addiu     $t1, $t1, %lo(gCameras)
/* 354DA0 E0042600 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 354DA4 E0042604 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 354DA8 E0042608 4406B000 */  mfc1      $a2, $f22
/* 354DAC E004260C 00031080 */  sll       $v0, $v1, 2
/* 354DB0 E0042610 00431021 */  addu      $v0, $v0, $v1
/* 354DB4 E0042614 00021080 */  sll       $v0, $v0, 2
/* 354DB8 E0042618 00431023 */  subu      $v0, $v0, $v1
/* 354DBC E004261C 000218C0 */  sll       $v1, $v0, 3
/* 354DC0 E0042620 00431021 */  addu      $v0, $v0, $v1
/* 354DC4 E0042624 000210C0 */  sll       $v0, $v0, 3
/* 354DC8 E0042628 00491021 */  addu      $v0, $v0, $t1
/* 354DCC E004262C C440006C */  lwc1      $f0, 0x6c($v0)
/* 354DD0 E0042630 4407A000 */  mfc1      $a3, $f20
/* 354DD4 E0042634 46000007 */  neg.s     $f0, $f0
/* 354DD8 E0042638 44050000 */  mfc1      $a1, $f0
/* 354DDC E004263C 0240202D */  daddu     $a0, $s2, $zero
/* 354DE0 E0042640 0C080104 */  jal       shim_guRotateF
/* 354DE4 E0042644 E7B60010 */   swc1     $f22, 0x10($sp)
/* 354DE8 E0042648 0240202D */  daddu     $a0, $s2, $zero
/* 354DEC E004264C 27A50018 */  addiu     $a1, $sp, 0x18
/* 354DF0 E0042650 0C080114 */  jal       shim_guMtxCatF
/* 354DF4 E0042654 00A0302D */   daddu    $a2, $a1, $zero
/* 354DF8 E0042658 0240202D */  daddu     $a0, $s2, $zero
/* 354DFC E004265C 8E050000 */  lw        $a1, ($s0)
/* 354E00 E0042660 4407A000 */  mfc1      $a3, $f20
/* 354E04 E0042664 0C080110 */  jal       shim_guScaleF
/* 354E08 E0042668 00A0302D */   daddu    $a2, $a1, $zero
/* 354E0C E004266C 0240202D */  daddu     $a0, $s2, $zero
/* 354E10 E0042670 27A50018 */  addiu     $a1, $sp, 0x18
/* 354E14 E0042674 0C080114 */  jal       shim_guMtxCatF
/* 354E18 E0042678 00A0302D */   daddu    $a2, $a1, $zero
/* 354E1C E004267C 27A40018 */  addiu     $a0, $sp, 0x18
/* 354E20 E0042680 3C058007 */  lui       $a1, %hi(gMatrixListPos)
/* 354E24 E0042684 94A541F0 */  lhu       $a1, %lo(gMatrixListPos)($a1)
/* 354E28 E0042688 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 354E2C E004268C 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 354E30 E0042690 8FA9009C */  lw        $t1, 0x9c($sp)
/* 354E34 E0042694 00052980 */  sll       $a1, $a1, 6
/* 354E38 E0042698 00A92821 */  addu      $a1, $a1, $t1
/* 354E3C E004269C 0C080118 */  jal       shim_guMtxF2L
/* 354E40 E00426A0 00452821 */   addu     $a1, $v0, $a1
/* 354E44 E00426A4 3C06D838 */  lui       $a2, 0xd838
/* 354E48 E00426A8 8E840000 */  lw        $a0, ($s4)
/* 354E4C E00426AC 34C60002 */  ori       $a2, $a2, 2
/* 354E50 E00426B0 0080282D */  daddu     $a1, $a0, $zero
/* 354E54 E00426B4 24840008 */  addiu     $a0, $a0, 8
/* 354E58 E00426B8 AE840000 */  sw        $a0, ($s4)
/* 354E5C E00426BC 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* 354E60 E00426C0 944241F0 */  lhu       $v0, %lo(gMatrixListPos)($v0)
/* 354E64 E00426C4 3C03DA38 */  lui       $v1, 0xda38
/* 354E68 E00426C8 ACA30000 */  sw        $v1, ($a1)
/* 354E6C E00426CC 8FA9009C */  lw        $t1, 0x9c($sp)
/* 354E70 E00426D0 24430001 */  addiu     $v1, $v0, 1
/* 354E74 E00426D4 3042FFFF */  andi      $v0, $v0, 0xffff
/* 354E78 E00426D8 00021180 */  sll       $v0, $v0, 6
/* 354E7C E00426DC 3C018007 */  lui       $at, %hi(gMatrixListPos)
/* 354E80 E00426E0 A42341F0 */  sh        $v1, %lo(gMatrixListPos)($at)
/* 354E84 E00426E4 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 354E88 E00426E8 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 354E8C E00426EC 00491021 */  addu      $v0, $v0, $t1
/* 354E90 E00426F0 00621821 */  addu      $v1, $v1, $v0
/* 354E94 E00426F4 24820008 */  addiu     $v0, $a0, 8
/* 354E98 E00426F8 ACA30004 */  sw        $v1, 4($a1)
/* 354E9C E00426FC AE820000 */  sw        $v0, ($s4)
/* 354EA0 E0042700 3C02DE00 */  lui       $v0, 0xde00
/* 354EA4 E0042704 3C090900 */  lui       $t1, 0x900
/* 354EA8 E0042708 252905E0 */  addiu     $t1, $t1, 0x5e0
/* 354EAC E004270C AC820000 */  sw        $v0, ($a0)
/* 354EB0 E0042710 24020040 */  addiu     $v0, $zero, 0x40
/* 354EB4 E0042714 AC890004 */  sw        $t1, 4($a0)
/* 354EB8 E0042718 AC860008 */  sw        $a2, 8($a0)
/* 354EBC E004271C AC82000C */  sw        $v0, 0xc($a0)
/* 354EC0 E0042720 8FA900D8 */  lw        $t1, 0xd8($sp)
/* 354EC4 E0042724 26100038 */  addiu     $s0, $s0, 0x38
/* 354EC8 E0042728 8D220008 */  lw        $v0, 8($t1)
/* 354ECC E004272C 24840010 */  addiu     $a0, $a0, 0x10
/* 354ED0 E0042730 02A2102A */  slt       $v0, $s5, $v0
/* 354ED4 E0042734 1440FF6F */  bnez      $v0, .LE00424F4
/* 354ED8 E0042738 AE840000 */   sw       $a0, ($s4)
.LE004273C:
/* 354EDC E004273C 8FBF00C4 */  lw        $ra, 0xc4($sp)
/* 354EE0 E0042740 8FBE00C0 */  lw        $fp, 0xc0($sp)
/* 354EE4 E0042744 8FB700BC */  lw        $s7, 0xbc($sp)
/* 354EE8 E0042748 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 354EEC E004274C 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 354EF0 E0042750 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 354EF4 E0042754 8FB300AC */  lw        $s3, 0xac($sp)
/* 354EF8 E0042758 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 354EFC E004275C 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 354F00 E0042760 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 354F04 E0042764 D7B600D0 */  ldc1      $f22, 0xd0($sp)
/* 354F08 E0042768 D7B400C8 */  ldc1      $f20, 0xc8($sp)
/* 354F0C E004276C 03E00008 */  jr        $ra
/* 354F10 E0042770 27BD00D8 */   addiu    $sp, $sp, 0xd8
/* 354F14 E0042774 00000000 */  nop
/* 354F18 E0042778 00000000 */  nop
/* 354F1C E004277C 00000000 */  nop
