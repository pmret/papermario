.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_96_appendGfx
/* 3BD4C0 E00C0760 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* 3BD4C4 E00C0764 0080282D */  daddu     $a1, $a0, $zero
/* 3BD4C8 E00C0768 3C06DB06 */  lui       $a2, 0xdb06
/* 3BD4CC E00C076C 34C60024 */  ori       $a2, $a2, 0x24
/* 3BD4D0 E00C0770 27A40018 */  addiu     $a0, $sp, 0x18
/* 3BD4D4 E00C0774 AFB1009C */  sw        $s1, 0x9c($sp)
/* 3BD4D8 E00C0778 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* 3BD4DC E00C077C 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* 3BD4E0 E00C0780 AFB500AC */  sw        $s5, 0xac($sp)
/* 3BD4E4 E00C0784 3C150001 */  lui       $s5, 1
/* 3BD4E8 E00C0788 3C02E700 */  lui       $v0, 0xe700
/* 3BD4EC E00C078C AFBF00B4 */  sw        $ra, 0xb4($sp)
/* 3BD4F0 E00C0790 AFB600B0 */  sw        $s6, 0xb0($sp)
/* 3BD4F4 E00C0794 AFB400A8 */  sw        $s4, 0xa8($sp)
/* 3BD4F8 E00C0798 AFB300A4 */  sw        $s3, 0xa4($sp)
/* 3BD4FC E00C079C AFB200A0 */  sw        $s2, 0xa0($sp)
/* 3BD500 E00C07A0 AFB00098 */  sw        $s0, 0x98($sp)
/* 3BD504 E00C07A4 8E280000 */  lw        $t0, ($s1)
/* 3BD508 E00C07A8 8CB0000C */  lw        $s0, 0xc($a1)
/* 3BD50C E00C07AC 0100182D */  daddu     $v1, $t0, $zero
/* 3BD510 E00C07B0 8E160024 */  lw        $s6, 0x24($s0)
/* 3BD514 E00C07B4 25080008 */  addiu     $t0, $t0, 8
/* 3BD518 E00C07B8 AC620000 */  sw        $v0, ($v1)
/* 3BD51C E00C07BC AC600004 */  sw        $zero, 4($v1)
/* 3BD520 E00C07C0 AD060000 */  sw        $a2, ($t0)
/* 3BD524 E00C07C4 8CA20010 */  lw        $v0, 0x10($a1)
/* 3BD528 E00C07C8 36B51630 */  ori       $s5, $s5, 0x1630
/* 3BD52C E00C07CC AE280000 */  sw        $t0, ($s1)
/* 3BD530 E00C07D0 8C42001C */  lw        $v0, 0x1c($v0)
/* 3BD534 E00C07D4 3C038000 */  lui       $v1, 0x8000
/* 3BD538 E00C07D8 00431021 */  addu      $v0, $v0, $v1
/* 3BD53C E00C07DC AD020004 */  sw        $v0, 4($t0)
/* 3BD540 E00C07E0 8E050004 */  lw        $a1, 4($s0)
/* 3BD544 E00C07E4 8E060008 */  lw        $a2, 8($s0)
/* 3BD548 E00C07E8 8E07000C */  lw        $a3, 0xc($s0)
/* 3BD54C E00C07EC 25080008 */  addiu     $t0, $t0, 8
/* 3BD550 E00C07F0 0C080108 */  jal       shim_guTranslateF
/* 3BD554 E00C07F4 AE280000 */   sw       $t0, ($s1)
/* 3BD558 E00C07F8 27B20058 */  addiu     $s2, $sp, 0x58
/* 3BD55C E00C07FC 8E050028 */  lw        $a1, 0x28($s0)
/* 3BD560 E00C0800 0240202D */  daddu     $a0, $s2, $zero
/* 3BD564 E00C0804 00A0302D */  daddu     $a2, $a1, $zero
/* 3BD568 E00C0808 0C080110 */  jal       shim_guScaleF
/* 3BD56C E00C080C 00A0382D */   daddu    $a3, $a1, $zero
/* 3BD570 E00C0810 0240202D */  daddu     $a0, $s2, $zero
/* 3BD574 E00C0814 27A50018 */  addiu     $a1, $sp, 0x18
/* 3BD578 E00C0818 0C080114 */  jal       shim_guMtxCatF
/* 3BD57C E00C081C 00A0302D */   daddu    $a2, $a1, $zero
/* 3BD580 E00C0820 27A40018 */  addiu     $a0, $sp, 0x18
/* 3BD584 E00C0824 3C138007 */  lui       $s3, %hi(gMatrixListPos)
/* 3BD588 E00C0828 267341F0 */  addiu     $s3, $s3, %lo(gMatrixListPos)
/* 3BD58C E00C082C 3C14800A */  lui       $s4, %hi(gDisplayContext)
/* 3BD590 E00C0830 2694A674 */  addiu     $s4, $s4, %lo(gDisplayContext)
/* 3BD594 E00C0834 96650000 */  lhu       $a1, ($s3)
/* 3BD598 E00C0838 8E820000 */  lw        $v0, ($s4)
/* 3BD59C E00C083C 00052980 */  sll       $a1, $a1, 6
/* 3BD5A0 E00C0840 00B52821 */  addu      $a1, $a1, $s5
/* 3BD5A4 E00C0844 0C080118 */  jal       shim_guMtxF2L
/* 3BD5A8 E00C0848 00452821 */   addu     $a1, $v0, $a1
/* 3BD5AC E00C084C 3C02DA38 */  lui       $v0, 0xda38
/* 3BD5B0 E00C0850 34420002 */  ori       $v0, $v0, 2
/* 3BD5B4 E00C0854 27A40018 */  addiu     $a0, $sp, 0x18
/* 3BD5B8 E00C0858 8E280000 */  lw        $t0, ($s1)
/* 3BD5BC E00C085C 96690000 */  lhu       $t1, ($s3)
/* 3BD5C0 E00C0860 0100282D */  daddu     $a1, $t0, $zero
/* 3BD5C4 E00C0864 ACA20000 */  sw        $v0, ($a1)
/* 3BD5C8 E00C0868 3122FFFF */  andi      $v0, $t1, 0xffff
/* 3BD5CC E00C086C 00021180 */  sll       $v0, $v0, 6
/* 3BD5D0 E00C0870 00551021 */  addu      $v0, $v0, $s5
/* 3BD5D4 E00C0874 8E830000 */  lw        $v1, ($s4)
/* 3BD5D8 E00C0878 25080008 */  addiu     $t0, $t0, 8
/* 3BD5DC E00C087C 00621821 */  addu      $v1, $v1, $v0
/* 3BD5E0 E00C0880 ACA30004 */  sw        $v1, 4($a1)
/* 3BD5E4 E00C0884 8E050030 */  lw        $a1, 0x30($s0)
/* 3BD5E8 E00C0888 8E060034 */  lw        $a2, 0x34($s0)
/* 3BD5EC E00C088C 8E070038 */  lw        $a3, 0x38($s0)
/* 3BD5F0 E00C0890 25290001 */  addiu     $t1, $t1, 1
/* 3BD5F4 E00C0894 AE280000 */  sw        $t0, ($s1)
/* 3BD5F8 E00C0898 0C080108 */  jal       shim_guTranslateF
/* 3BD5FC E00C089C A6690000 */   sh       $t1, ($s3)
/* 3BD600 E00C08A0 0240202D */  daddu     $a0, $s2, $zero
/* 3BD604 E00C08A4 8E050048 */  lw        $a1, 0x48($s0)
/* 3BD608 E00C08A8 8E06004C */  lw        $a2, 0x4c($s0)
/* 3BD60C E00C08AC 0C080110 */  jal       shim_guScaleF
/* 3BD610 E00C08B0 00A0382D */   daddu    $a3, $a1, $zero
/* 3BD614 E00C08B4 0240202D */  daddu     $a0, $s2, $zero
/* 3BD618 E00C08B8 27A50018 */  addiu     $a1, $sp, 0x18
/* 3BD61C E00C08BC 0C080114 */  jal       shim_guMtxCatF
/* 3BD620 E00C08C0 00A0302D */   daddu    $a2, $a1, $zero
/* 3BD624 E00C08C4 44800000 */  mtc1      $zero, $f0
/* 3BD628 E00C08C8 3C073F80 */  lui       $a3, 0x3f80
/* 3BD62C E00C08CC E7A00010 */  swc1      $f0, 0x10($sp)
/* 3BD630 E00C08D0 8E05002C */  lw        $a1, 0x2c($s0)
/* 3BD634 E00C08D4 44060000 */  mfc1      $a2, $f0
/* 3BD638 E00C08D8 0C080104 */  jal       shim_guRotateF
/* 3BD63C E00C08DC 0240202D */   daddu    $a0, $s2, $zero
/* 3BD640 E00C08E0 0240202D */  daddu     $a0, $s2, $zero
/* 3BD644 E00C08E4 27A50018 */  addiu     $a1, $sp, 0x18
/* 3BD648 E00C08E8 0C080114 */  jal       shim_guMtxCatF
/* 3BD64C E00C08EC 00A0302D */   daddu    $a2, $a1, $zero
/* 3BD650 E00C08F0 27A40018 */  addiu     $a0, $sp, 0x18
/* 3BD654 E00C08F4 96650000 */  lhu       $a1, ($s3)
/* 3BD658 E00C08F8 8E820000 */  lw        $v0, ($s4)
/* 3BD65C E00C08FC 00052980 */  sll       $a1, $a1, 6
/* 3BD660 E00C0900 00B52821 */  addu      $a1, $a1, $s5
/* 3BD664 E00C0904 0C080118 */  jal       shim_guMtxF2L
/* 3BD668 E00C0908 00452821 */   addu     $a1, $v0, $a1
/* 3BD66C E00C090C 3C08D838 */  lui       $t0, 0xd838
/* 3BD670 E00C0910 35080002 */  ori       $t0, $t0, 2
/* 3BD674 E00C0914 8E240000 */  lw        $a0, ($s1)
/* 3BD678 E00C0918 3C03DA38 */  lui       $v1, 0xda38
/* 3BD67C E00C091C 0080282D */  daddu     $a1, $a0, $zero
/* 3BD680 E00C0920 24840008 */  addiu     $a0, $a0, 8
/* 3BD684 E00C0924 AE240000 */  sw        $a0, ($s1)
/* 3BD688 E00C0928 96620000 */  lhu       $v0, ($s3)
/* 3BD68C E00C092C 32D600FF */  andi      $s6, $s6, 0xff
/* 3BD690 E00C0930 ACA30000 */  sw        $v1, ($a1)
/* 3BD694 E00C0934 24430001 */  addiu     $v1, $v0, 1
/* 3BD698 E00C0938 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3BD69C E00C093C 00021180 */  sll       $v0, $v0, 6
/* 3BD6A0 E00C0940 A6630000 */  sh        $v1, ($s3)
/* 3BD6A4 E00C0944 8E830000 */  lw        $v1, ($s4)
/* 3BD6A8 E00C0948 00551021 */  addu      $v0, $v0, $s5
/* 3BD6AC E00C094C 00621821 */  addu      $v1, $v1, $v0
/* 3BD6B0 E00C0950 24820008 */  addiu     $v0, $a0, 8
/* 3BD6B4 E00C0954 ACA30004 */  sw        $v1, 4($a1)
/* 3BD6B8 E00C0958 AE220000 */  sw        $v0, ($s1)
/* 3BD6BC E00C095C 3C02FA00 */  lui       $v0, 0xfa00
/* 3BD6C0 E00C0960 AC820000 */  sw        $v0, ($a0)
/* 3BD6C4 E00C0964 24820010 */  addiu     $v0, $a0, 0x10
/* 3BD6C8 E00C0968 9203001B */  lbu       $v1, 0x1b($s0)
/* 3BD6CC E00C096C 9206001F */  lbu       $a2, 0x1f($s0)
/* 3BD6D0 E00C0970 92070023 */  lbu       $a3, 0x23($s0)
/* 3BD6D4 E00C0974 3C05DE00 */  lui       $a1, 0xde00
/* 3BD6D8 E00C0978 AE220000 */  sw        $v0, ($s1)
/* 3BD6DC E00C097C 3C020900 */  lui       $v0, 0x900
/* 3BD6E0 E00C0980 244237A8 */  addiu     $v0, $v0, 0x37a8
/* 3BD6E4 E00C0984 AC82000C */  sw        $v0, 0xc($a0)
/* 3BD6E8 E00C0988 24820018 */  addiu     $v0, $a0, 0x18
/* 3BD6EC E00C098C AC850008 */  sw        $a1, 8($a0)
/* 3BD6F0 E00C0990 AE220000 */  sw        $v0, ($s1)
/* 3BD6F4 E00C0994 3C020900 */  lui       $v0, 0x900
/* 3BD6F8 E00C0998 24423818 */  addiu     $v0, $v0, 0x3818
/* 3BD6FC E00C099C AC820014 */  sw        $v0, 0x14($a0)
/* 3BD700 E00C09A0 24820020 */  addiu     $v0, $a0, 0x20
/* 3BD704 E00C09A4 AC850010 */  sw        $a1, 0x10($a0)
/* 3BD708 E00C09A8 24050040 */  addiu     $a1, $zero, 0x40
/* 3BD70C E00C09AC AE220000 */  sw        $v0, ($s1)
/* 3BD710 E00C09B0 24820028 */  addiu     $v0, $a0, 0x28
/* 3BD714 E00C09B4 AC880018 */  sw        $t0, 0x18($a0)
/* 3BD718 E00C09B8 AC85001C */  sw        $a1, 0x1c($a0)
/* 3BD71C E00C09BC AE220000 */  sw        $v0, ($s1)
/* 3BD720 E00C09C0 AC880020 */  sw        $t0, 0x20($a0)
/* 3BD724 E00C09C4 AC850024 */  sw        $a1, 0x24($a0)
/* 3BD728 E00C09C8 00031E00 */  sll       $v1, $v1, 0x18
/* 3BD72C E00C09CC 00063400 */  sll       $a2, $a2, 0x10
/* 3BD730 E00C09D0 00661825 */  or        $v1, $v1, $a2
/* 3BD734 E00C09D4 00073A00 */  sll       $a3, $a3, 8
/* 3BD738 E00C09D8 00671825 */  or        $v1, $v1, $a3
/* 3BD73C E00C09DC 00761825 */  or        $v1, $v1, $s6
/* 3BD740 E00C09E0 AC830004 */  sw        $v1, 4($a0)
/* 3BD744 E00C09E4 8FBF00B4 */  lw        $ra, 0xb4($sp)
/* 3BD748 E00C09E8 8FB600B0 */  lw        $s6, 0xb0($sp)
/* 3BD74C E00C09EC 8FB500AC */  lw        $s5, 0xac($sp)
/* 3BD750 E00C09F0 8FB400A8 */  lw        $s4, 0xa8($sp)
/* 3BD754 E00C09F4 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 3BD758 E00C09F8 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 3BD75C E00C09FC 8FB1009C */  lw        $s1, 0x9c($sp)
/* 3BD760 E00C0A00 8FB00098 */  lw        $s0, 0x98($sp)
/* 3BD764 E00C0A04 03E00008 */  jr        $ra
/* 3BD768 E00C0A08 27BD00B8 */   addiu    $sp, $sp, 0xb8
/* 3BD76C E00C0A0C 00000000 */  nop
