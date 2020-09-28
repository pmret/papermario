.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011C028
/* B2728 8011C028 27BDFFF8 */  addiu     $sp, $sp, -8
/* B272C 8011C02C 0000482D */  daddu     $t1, $zero, $zero
/* B2730 8011C030 8FAC0018 */  lw        $t4, 0x18($sp)
/* B2734 8011C034 14800004 */  bnez      $a0, .L8011C048
/* B2738 8011C038 0120502D */   daddu    $t2, $t1, $zero
/* B273C 8011C03C ACA00000 */  sw        $zero, ($a1)
/* B2740 8011C040 08047035 */  j         .L8011C0D4
/* B2744 8011C044 ACC00000 */   sw       $zero, ($a2)
.L8011C048:
/* B2748 8011C048 0080682D */  daddu     $t5, $a0, $zero
/* B274C 8011C04C 240F0001 */  addiu     $t7, $zero, 1
/* B2750 8011C050 240E00DF */  addiu     $t6, $zero, 0xdf
.L8011C054:
/* B2754 8011C054 8C880000 */  lw        $t0, ($a0)
/* B2758 8011C058 8C820004 */  lw        $v0, 4($a0)
/* B275C 8011C05C 00085E02 */  srl       $t3, $t0, 0x18
/* B2760 8011C060 156F0013 */  bne       $t3, $t7, .L8011C0B0
/* B2764 8011C064 00000000 */   nop      
/* B2768 8011C068 11800003 */  beqz      $t4, .L8011C078
/* B276C 8011C06C 0040182D */   daddu    $v1, $v0, $zero
/* B2770 8011C070 3042FFFF */  andi      $v0, $v0, 0xffff
/* B2774 8011C074 004C1821 */  addu      $v1, $v0, $t4
.L8011C078:
/* B2778 8011C078 00081302 */  srl       $v0, $t0, 0xc
/* B277C 8011C07C 15200004 */  bnez      $t1, .L8011C090
/* B2780 8011C080 304800FF */   andi     $t0, $v0, 0xff
/* B2784 8011C084 0060482D */  daddu     $t1, $v1, $zero
/* B2788 8011C088 00081100 */  sll       $v0, $t0, 4
/* B278C 8011C08C 01225021 */  addu      $t2, $t1, $v0
.L8011C090:
/* B2790 8011C090 00081100 */  sll       $v0, $t0, 4
/* B2794 8011C094 00621821 */  addu      $v1, $v1, $v0
/* B2798 8011C098 0143102B */  sltu      $v0, $t2, $v1
/* B279C 8011C09C 54400001 */  bnel      $v0, $zero, .L8011C0A4
/* B27A0 8011C0A0 0060502D */   daddu    $t2, $v1, $zero
.L8011C0A4:
/* B27A4 8011C0A4 0069102B */  sltu      $v0, $v1, $t1
/* B27A8 8011C0A8 54400001 */  bnel      $v0, $zero, .L8011C0B0
/* B27AC 8011C0AC 0060482D */   daddu    $t1, $v1, $zero
.L8011C0B0:
/* B27B0 8011C0B0 156EFFE8 */  bne       $t3, $t6, .L8011C054
/* B27B4 8011C0B4 24840008 */   addiu    $a0, $a0, 8
/* B27B8 8011C0B8 01491023 */  subu      $v0, $t2, $t1
/* B27BC 8011C0BC 00021103 */  sra       $v0, $v0, 4
/* B27C0 8011C0C0 ACA20000 */  sw        $v0, ($a1)
/* B27C4 8011C0C4 008D1023 */  subu      $v0, $a0, $t5
/* B27C8 8011C0C8 000210C3 */  sra       $v0, $v0, 3
/* B27CC 8011C0CC ACC90000 */  sw        $t1, ($a2)
/* B27D0 8011C0D0 ACE20000 */  sw        $v0, ($a3)
.L8011C0D4:
/* B27D4 8011C0D4 03E00008 */  jr        $ra
/* B27D8 8011C0D8 27BD0008 */   addiu    $sp, $sp, 8
