.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80283810
/* 7E4690 80283810 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7E4694 80283814 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E4698 80283818 0080802D */  daddu     $s0, $a0, $zero
/* 7E469C 8028381C AFBF0014 */  sw        $ra, 0x14($sp)
/* 7E46A0 80283820 0C03AD8E */  jal       partner_get_ride_script
/* 7E46A4 80283824 AE0000AC */   sw       $zero, 0xac($s0)
/* 7E46A8 80283828 1040000F */  beqz      $v0, .L80283868
/* 7E46AC 8028382C 00000000 */   nop      
/* 7E46B0 80283830 3C028011 */  lui       $v0, 0x8011
/* 7E46B4 80283834 8042EBB0 */  lb        $v0, -0x1450($v0)
/* 7E46B8 80283838 14400003 */  bnez      $v0, .L80283848
/* 7E46BC 8028383C 24020001 */   addiu    $v0, $zero, 1
/* 7E46C0 80283840 080A0E1A */  j         .L80283868
/* 7E46C4 80283844 AE0000AC */   sw       $zero, 0xac($s0)
.L80283848:
/* 7E46C8 80283848 0C03AD8E */  jal       partner_get_ride_script
/* 7E46CC 8028384C AE0200AC */   sw       $v0, 0xac($s0)
/* 7E46D0 80283850 AE0200B0 */  sw        $v0, 0xb0($s0)
/* 7E46D4 80283854 3C028011 */  lui       $v0, 0x8011
/* 7E46D8 80283858 2442EFC8 */  addiu     $v0, $v0, -0x1038
/* 7E46DC 8028385C C4400080 */  lwc1      $f0, 0x80($v0)
/* 7E46E0 80283860 4600008D */  trunc.w.s $f2, $f0
/* 7E46E4 80283864 E60200B8 */  swc1      $f2, 0xb8($s0)
.L80283868:
/* 7E46E8 80283868 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7E46EC 8028386C 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E46F0 80283870 24020002 */  addiu     $v0, $zero, 2
/* 7E46F4 80283874 03E00008 */  jr        $ra
/* 7E46F8 80283878 27BD0018 */   addiu    $sp, $sp, 0x18
