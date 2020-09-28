.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004E444
/* 29844 8004E444 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 29848 8004E448 AFB10014 */  sw        $s1, 0x14($sp)
/* 2984C 8004E44C 0080882D */  daddu     $s1, $a0, $zero
/* 29850 8004E450 AFBF001C */  sw        $ra, 0x1c($sp)
/* 29854 8004E454 AFB20018 */  sw        $s2, 0x18($sp)
/* 29858 8004E458 AFB00010 */  sw        $s0, 0x10($sp)
/* 2985C 8004E45C 9623002C */  lhu       $v1, 0x2c($s1)
/* 29860 8004E460 9622003C */  lhu       $v0, 0x3c($s1)
/* 29864 8004E464 00620018 */  mult      $v1, $v0
/* 29868 8004E468 0000802D */  daddu     $s0, $zero, $zero
/* 2986C 8004E46C 00003812 */  mflo      $a3
/* 29870 8004E470 000793C2 */  srl       $s2, $a3, 0xf
/* 29874 8004E474 02301021 */  addu      $v0, $s1, $s0
.L8004E478:
/* 29878 8004E478 8043004C */  lb        $v1, 0x4c($v0)
/* 2987C 8004E47C 9044004C */  lbu       $a0, 0x4c($v0)
/* 29880 8004E480 04600007 */  bltz      $v1, .L8004E4A0
/* 29884 8004E484 26100001 */   addiu    $s0, $s0, 1
/* 29888 8004E488 8E260048 */  lw        $a2, 0x48($s1)
/* 2988C 8004E48C 0C014EA6 */  jal       func_80053A98
/* 29890 8004E490 3245FFFF */   andi     $a1, $s2, 0xffff
/* 29894 8004E494 2A020004 */  slti      $v0, $s0, 4
/* 29898 8004E498 1440FFF7 */  bnez      $v0, .L8004E478
/* 2989C 8004E49C 02301021 */   addu     $v0, $s1, $s0
.L8004E4A0:
/* 298A0 8004E4A0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 298A4 8004E4A4 8FB20018 */  lw        $s2, 0x18($sp)
/* 298A8 8004E4A8 8FB10014 */  lw        $s1, 0x14($sp)
/* 298AC 8004E4AC 8FB00010 */  lw        $s0, 0x10($sp)
/* 298B0 8004E4B0 03E00008 */  jr        $ra
/* 298B4 8004E4B4 27BD0020 */   addiu    $sp, $sp, 0x20
