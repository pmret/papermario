.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011F058
/* B5758 8011F058 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* B575C 8011F05C AFB00050 */  sw        $s0, 0x50($sp)
/* B5760 8011F060 0080802D */  daddu     $s0, $a0, $zero
/* B5764 8011F064 AFBF0058 */  sw        $ra, 0x58($sp)
/* B5768 8011F068 AFB10054 */  sw        $s1, 0x54($sp)
/* B576C 8011F06C 8E020010 */  lw        $v0, 0x10($s0)
/* B5770 8011F070 10400024 */  beqz      $v0, .L8011F104
/* B5774 8011F074 00A0882D */   daddu    $s1, $a1, $zero
/* B5778 8011F078 8E020000 */  lw        $v0, ($s0)
/* B577C 8011F07C 30430700 */  andi      $v1, $v0, 0x700
/* B5780 8011F080 24020200 */  addiu     $v0, $zero, 0x200
/* B5784 8011F084 10620010 */  beq       $v1, $v0, .L8011F0C8
/* B5788 8011F088 2C620201 */   sltiu    $v0, $v1, 0x201
/* B578C 8011F08C 10400005 */  beqz      $v0, .L8011F0A4
/* B5790 8011F090 24020100 */   addiu    $v0, $zero, 0x100
/* B5794 8011F094 10620008 */  beq       $v1, $v0, .L8011F0B8
/* B5798 8011F098 00000000 */   nop      
/* B579C 8011F09C 08047C3A */  j         .L8011F0E8
/* B57A0 8011F0A0 00000000 */   nop      
.L8011F0A4:
/* B57A4 8011F0A4 24020400 */  addiu     $v0, $zero, 0x400
/* B57A8 8011F0A8 1062000B */  beq       $v1, $v0, .L8011F0D8
/* B57AC 8011F0AC 00000000 */   nop      
/* B57B0 8011F0B0 08047C3A */  j         .L8011F0E8
/* B57B4 8011F0B4 00000000 */   nop      
.L8011F0B8:
/* B57B8 8011F0B8 0C0477F4 */  jal       func_8011DFD0
/* B57BC 8011F0BC 27A40010 */   addiu    $a0, $sp, 0x10
/* B57C0 8011F0C0 08047C3D */  j         .L8011F0F4
/* B57C4 8011F0C4 0200202D */   daddu    $a0, $s0, $zero
.L8011F0C8:
/* B57C8 8011F0C8 0C047805 */  jal       func_8011E014
/* B57CC 8011F0CC 27A40010 */   addiu    $a0, $sp, 0x10
/* B57D0 8011F0D0 08047C3D */  j         .L8011F0F4
/* B57D4 8011F0D4 0200202D */   daddu    $a0, $s0, $zero
.L8011F0D8:
/* B57D8 8011F0D8 0C047816 */  jal       func_8011E058
/* B57DC 8011F0DC 27A40010 */   addiu    $a0, $sp, 0x10
/* B57E0 8011F0E0 08047C3D */  j         .L8011F0F4
/* B57E4 8011F0E4 0200202D */   daddu    $a0, $s0, $zero
.L8011F0E8:
/* B57E8 8011F0E8 0C047827 */  jal       func_8011E09C
/* B57EC 8011F0EC 27A40010 */   addiu    $a0, $sp, 0x10
/* B57F0 8011F0F0 0200202D */  daddu     $a0, $s0, $zero
.L8011F0F4:
/* B57F4 8011F0F4 27A50010 */  addiu     $a1, $sp, 0x10
/* B57F8 8011F0F8 8C860010 */  lw        $a2, 0x10($a0)
/* B57FC 8011F0FC 0C047C46 */  jal       func_8011F118
/* B5800 8011F100 0220382D */   daddu    $a3, $s1, $zero
.L8011F104:
/* B5804 8011F104 8FBF0058 */  lw        $ra, 0x58($sp)
/* B5808 8011F108 8FB10054 */  lw        $s1, 0x54($sp)
/* B580C 8011F10C 8FB00050 */  lw        $s0, 0x50($sp)
/* B5810 8011F110 03E00008 */  jr        $ra
/* B5814 8011F114 27BD0060 */   addiu    $sp, $sp, 0x60
