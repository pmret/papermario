.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_load_INIT
/* 2F6BC 800542BC 27BDFF70 */  addiu     $sp, $sp, -0x90
/* 2F6C0 800542C0 AFB3007C */  sw        $s3, 0x7c($sp)
/* 2F6C4 800542C4 0080982D */  daddu     $s3, $a0, $zero
/* 2F6C8 800542C8 AFB10074 */  sw        $s1, 0x74($sp)
/* 2F6CC 800542CC 00A0882D */  daddu     $s1, $a1, $zero
/* 2F6D0 800542D0 AFB40080 */  sw        $s4, 0x80($sp)
/* 2F6D4 800542D4 00C0A02D */  daddu     $s4, $a2, $zero
/* 2F6D8 800542D8 0220202D */  daddu     $a0, $s1, $zero
/* 2F6DC 800542DC 27A50010 */  addiu     $a1, $sp, 0x10
/* 2F6E0 800542E0 24060040 */  addiu     $a2, $zero, 0x40
/* 2F6E4 800542E4 AFB50084 */  sw        $s5, 0x84($sp)
/* 2F6E8 800542E8 2675001C */  addiu     $s5, $s3, 0x1c
/* 2F6EC 800542EC AFBF0088 */  sw        $ra, 0x88($sp)
/* 2F6F0 800542F0 AFB20078 */  sw        $s2, 0x78($sp)
/* 2F6F4 800542F4 0C015380 */  jal       snd_read_rom
/* 2F6F8 800542F8 AFB00070 */   sw       $s0, 0x70($sp)
/* 2F6FC 800542FC 0280202D */  daddu     $a0, $s4, $zero
/* 2F700 80054300 8FB00024 */  lw        $s0, 0x24($sp)
/* 2F704 80054304 24050001 */  addiu     $a1, $zero, 1
/* 2F708 80054308 AE71001C */  sw        $s1, 0x1c($s3)
/* 2F70C 8005430C 8FA20024 */  lw        $v0, 0x24($sp)
/* 2F710 80054310 001080C0 */  sll       $s0, $s0, 3
/* 2F714 80054314 0200302D */  daddu     $a2, $s0, $zero
/* 2F718 80054318 0C015FE4 */  jal       alHeapAlloc
/* 2F71C 8005431C AE620024 */   sw       $v0, 0x24($s3)
/* 2F720 80054320 0040282D */  daddu     $a1, $v0, $zero
/* 2F724 80054324 8E62001C */  lw        $v0, 0x1c($s3)
/* 2F728 80054328 AE650020 */  sw        $a1, 0x20($s3)
/* 2F72C 8005432C 8FA40020 */  lw        $a0, 0x20($sp)
/* 2F730 80054330 0200302D */  daddu     $a2, $s0, $zero
/* 2F734 80054334 0C015380 */  jal       snd_read_rom
/* 2F738 80054338 00442021 */   addu     $a0, $v0, $a0
/* 2F73C 8005433C 8FA20024 */  lw        $v0, 0x24($sp)
/* 2F740 80054340 8E650020 */  lw        $a1, 0x20($s3)
/* 2F744 80054344 0040182D */  daddu     $v1, $v0, $zero
/* 2F748 80054348 2442FFFF */  addiu     $v0, $v0, -1
/* 2F74C 8005434C 10600013 */  beqz      $v1, .L8005439C
/* 2F750 80054350 AFA20024 */   sw       $v0, 0x24($sp)
/* 2F754 80054354 3C0600FF */  lui       $a2, 0xff
/* 2F758 80054358 34C6FFFF */  ori       $a2, $a2, 0xffff
/* 2F75C 8005435C 2407FFF0 */  addiu     $a3, $zero, -0x10
/* 2F760 80054360 24A40004 */  addiu     $a0, $a1, 4
.L80054364:
/* 2F764 80054364 8CA20000 */  lw        $v0, ($a1)
/* 2F768 80054368 00461024 */  and       $v0, $v0, $a2
/* 2F76C 8005436C 1040000B */  beqz      $v0, .L8005439C
/* 2F770 80054370 24A50008 */   addiu    $a1, $a1, 8
/* 2F774 80054374 8C920000 */  lw        $s2, ($a0)
/* 2F778 80054378 2642000F */  addiu     $v0, $s2, 0xf
/* 2F77C 8005437C 00471024 */  and       $v0, $v0, $a3
/* 2F780 80054380 AC820000 */  sw        $v0, ($a0)
/* 2F784 80054384 8FA20024 */  lw        $v0, 0x24($sp)
/* 2F788 80054388 24840008 */  addiu     $a0, $a0, 8
/* 2F78C 8005438C 0040182D */  daddu     $v1, $v0, $zero
/* 2F790 80054390 2442FFFF */  addiu     $v0, $v0, -1
/* 2F794 80054394 1460FFF3 */  bnez      $v1, .L80054364
/* 2F798 80054398 AFA20024 */   sw       $v0, 0x24($sp)
.L8005439C:
/* 2F79C 8005439C 8FA20034 */  lw        $v0, 0x34($sp)
/* 2F7A0 800543A0 1040002D */  beqz      $v0, .L80054458
/* 2F7A4 800543A4 27A50050 */   addiu    $a1, $sp, 0x50
/* 2F7A8 800543A8 8EB10000 */  lw        $s1, ($s5)
/* 2F7AC 800543AC 24060020 */  addiu     $a2, $zero, 0x20
/* 2F7B0 800543B0 02228821 */  addu      $s1, $s1, $v0
/* 2F7B4 800543B4 0C015380 */  jal       snd_read_rom
/* 2F7B8 800543B8 0220202D */   daddu    $a0, $s1, $zero
/* 2F7BC 800543BC 0280202D */  daddu     $a0, $s4, $zero
/* 2F7C0 800543C0 24050001 */  addiu     $a1, $zero, 1
/* 2F7C4 800543C4 97A2005E */  lhu       $v0, 0x5e($sp)
/* 2F7C8 800543C8 97B0005C */  lhu       $s0, 0x5c($sp)
/* 2F7CC 800543CC 2442000F */  addiu     $v0, $v0, 0xf
/* 2F7D0 800543D0 3052FFF0 */  andi      $s2, $v0, 0xfff0
/* 2F7D4 800543D4 0240302D */  daddu     $a2, $s2, $zero
/* 2F7D8 800543D8 0C015FE4 */  jal       alHeapAlloc
/* 2F7DC 800543DC 02308021 */   addu     $s0, $s1, $s0
/* 2F7E0 800543E0 0200202D */  daddu     $a0, $s0, $zero
/* 2F7E4 800543E4 0040282D */  daddu     $a1, $v0, $zero
/* 2F7E8 800543E8 0240302D */  daddu     $a2, $s2, $zero
/* 2F7EC 800543EC 0C015380 */  jal       snd_read_rom
/* 2F7F0 800543F0 AE65002C */   sw       $a1, 0x2c($s3)
/* 2F7F4 800543F4 0280202D */  daddu     $a0, $s4, $zero
/* 2F7F8 800543F8 24050001 */  addiu     $a1, $zero, 1
/* 2F7FC 800543FC 97A20062 */  lhu       $v0, 0x62($sp)
/* 2F800 80054400 97B00060 */  lhu       $s0, 0x60($sp)
/* 2F804 80054404 2442000F */  addiu     $v0, $v0, 0xf
/* 2F808 80054408 3052FFF0 */  andi      $s2, $v0, 0xfff0
/* 2F80C 8005440C 0240302D */  daddu     $a2, $s2, $zero
/* 2F810 80054410 0C015FE4 */  jal       alHeapAlloc
/* 2F814 80054414 02308021 */   addu     $s0, $s1, $s0
/* 2F818 80054418 0200202D */  daddu     $a0, $s0, $zero
/* 2F81C 8005441C 0040282D */  daddu     $a1, $v0, $zero
/* 2F820 80054420 0240302D */  daddu     $a2, $s2, $zero
/* 2F824 80054424 0C015380 */  jal       snd_read_rom
/* 2F828 80054428 AE65003C */   sw       $a1, 0x3c($s3)
/* 2F82C 8005442C 97A20058 */  lhu       $v0, 0x58($sp)
/* 2F830 80054430 02228821 */  addu      $s1, $s1, $v0
/* 2F834 80054434 AE710034 */  sw        $s1, 0x34($s3)
/* 2F838 80054438 97A2005A */  lhu       $v0, 0x5a($sp)
/* 2F83C 8005443C 2442000F */  addiu     $v0, $v0, 0xf
/* 2F840 80054440 3042FFF0 */  andi      $v0, $v0, 0xfff0
/* 2F844 80054444 AE620038 */  sw        $v0, 0x38($s3)
/* 2F848 80054448 97A2005E */  lhu       $v0, 0x5e($sp)
/* 2F84C 8005444C 000210C2 */  srl       $v0, $v0, 3
/* 2F850 80054450 2442FFFF */  addiu     $v0, $v0, -1
/* 2F854 80054454 AE620030 */  sw        $v0, 0x30($s3)
.L80054458:
/* 2F858 80054458 8FBF0088 */  lw        $ra, 0x88($sp)
/* 2F85C 8005445C 8FB50084 */  lw        $s5, 0x84($sp)
/* 2F860 80054460 8FB40080 */  lw        $s4, 0x80($sp)
/* 2F864 80054464 8FB3007C */  lw        $s3, 0x7c($sp)
/* 2F868 80054468 8FB20078 */  lw        $s2, 0x78($sp)
/* 2F86C 8005446C 8FB10074 */  lw        $s1, 0x74($sp)
/* 2F870 80054470 8FB00070 */  lw        $s0, 0x70($sp)
/* 2F874 80054474 03E00008 */  jr        $ra
/* 2F878 80054478 27BD0090 */   addiu    $sp, $sp, 0x90
