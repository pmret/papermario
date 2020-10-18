.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E000C654
/* 328764 E000C654 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 328768 E000C658 AFB3001C */  sw        $s3, 0x1c($sp)
/* 32876C E000C65C 0080982D */  daddu     $s3, $a0, $zero
/* 328770 E000C660 AFBF0024 */  sw        $ra, 0x24($sp)
/* 328774 E000C664 AFB40020 */  sw        $s4, 0x20($sp)
/* 328778 E000C668 AFB20018 */  sw        $s2, 0x18($sp)
/* 32877C E000C66C AFB10014 */  sw        $s1, 0x14($sp)
/* 328780 E000C670 AFB00010 */  sw        $s0, 0x10($sp)
/* 328784 E000C674 8E70000C */  lw        $s0, 0xc($s3)
/* 328788 E000C678 8E020038 */  lw        $v0, 0x38($s0)
/* 32878C E000C67C 8E03003C */  lw        $v1, 0x3c($s0)
/* 328790 E000C680 00021080 */  sll       $v0, $v0, 2
/* 328794 E000C684 3C01E001 */  lui       $at, 0xe001
/* 328798 E000C688 00220821 */  addu      $at, $at, $v0
/* 32879C E000C68C 8C22CD24 */  lw        $v0, -0x32dc($at)
/* 3287A0 E000C690 00431021 */  addu      $v0, $v0, $v1
/* 3287A4 E000C694 80420000 */  lb        $v0, ($v0)
/* 3287A8 E000C698 24630001 */  addiu     $v1, $v1, 1
/* 3287AC E000C69C AE03003C */  sw        $v1, 0x3c($s0)
/* 3287B0 E000C6A0 04410005 */  bgez      $v0, .LE000C6B8
/* 3287B4 E000C6A4 AE020040 */   sw       $v0, 0x40($s0)
/* 3287B8 E000C6A8 0C080128 */  jal       func_E02004A0
/* 3287BC E000C6AC 00000000 */   nop      
/* 3287C0 E000C6B0 080031CD */  j         .LE000C734
/* 3287C4 E000C6B4 00000000 */   nop      
.LE000C6B8:
/* 3287C8 E000C6B8 96040000 */  lhu       $a0, ($s0)
/* 3287CC E000C6BC 8E620008 */  lw        $v0, 8($s3)
/* 3287D0 E000C6C0 24110001 */  addiu     $s1, $zero, 1
/* 3287D4 E000C6C4 0222102A */  slt       $v0, $s1, $v0
/* 3287D8 E000C6C8 1040001A */  beqz      $v0, .LE000C734
/* 3287DC E000C6CC 26100044 */   addiu    $s0, $s0, 0x44
/* 3287E0 E000C6D0 2C940005 */  sltiu     $s4, $a0, 5
/* 3287E4 E000C6D4 3C03E001 */  lui       $v1, 0xe001
/* 3287E8 E000C6D8 2463CD70 */  addiu     $v1, $v1, -0x3290
/* 3287EC E000C6DC 00041080 */  sll       $v0, $a0, 2
/* 3287F0 E000C6E0 00439021 */  addu      $s2, $v0, $v1
.LE000C6E4:
/* 3287F4 E000C6E4 5280000F */  beql      $s4, $zero, .LE000C724
/* 3287F8 E000C6E8 26310001 */   addiu    $s1, $s1, 1
/* 3287FC E000C6EC 8E420000 */  lw        $v0, ($s2)
/* 328800 E000C6F0 00400008 */  jr        $v0
/* 328804 E000C6F4 00000000 */   nop      
/* 328808 E000C6F8 0C003000 */  jal       func_E000C000
/* 32880C E000C6FC 0200202D */   daddu    $a0, $s0, $zero
/* 328810 E000C700 080031C9 */  j         .LE000C724
/* 328814 E000C704 26310001 */   addiu    $s1, $s1, 1
/* 328818 E000C708 0C003025 */  jal       func_E000C094
/* 32881C E000C70C 0200202D */   daddu    $a0, $s0, $zero
/* 328820 E000C710 080031C9 */  j         .LE000C724
/* 328824 E000C714 26310001 */   addiu    $s1, $s1, 1
/* 328828 E000C718 0C003032 */  jal       func_E000C0C8
/* 32882C E000C71C 0200202D */   daddu    $a0, $s0, $zero
/* 328830 E000C720 26310001 */  addiu     $s1, $s1, 1
.LE000C724:
/* 328834 E000C724 8E620008 */  lw        $v0, 8($s3)
/* 328838 E000C728 0222102A */  slt       $v0, $s1, $v0
/* 32883C E000C72C 1440FFED */  bnez      $v0, .LE000C6E4
/* 328840 E000C730 26100044 */   addiu    $s0, $s0, 0x44
.LE000C734:
/* 328844 E000C734 8FBF0024 */  lw        $ra, 0x24($sp)
/* 328848 E000C738 8FB40020 */  lw        $s4, 0x20($sp)
/* 32884C E000C73C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 328850 E000C740 8FB20018 */  lw        $s2, 0x18($sp)
/* 328854 E000C744 8FB10014 */  lw        $s1, 0x14($sp)
/* 328858 E000C748 8FB00010 */  lw        $s0, 0x10($sp)
/* 32885C E000C74C 03E00008 */  jr        $ra
/* 328860 E000C750 27BD0028 */   addiu    $sp, $sp, 0x28
