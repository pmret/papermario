.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025CD40
/* 18B620 8025CD40 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 18B624 8025CD44 AFB10014 */  sw        $s1, 0x14($sp)
/* 18B628 8025CD48 00A0882D */  daddu     $s1, $a1, $zero
/* 18B62C 8025CD4C AFBF0020 */  sw        $ra, 0x20($sp)
/* 18B630 8025CD50 AFB3001C */  sw        $s3, 0x1c($sp)
/* 18B634 8025CD54 AFB20018 */  sw        $s2, 0x18($sp)
/* 18B638 8025CD58 AFB00010 */  sw        $s0, 0x10($sp)
/* 18B63C 8025CD5C 8E3000C0 */  lw        $s0, 0xc0($s1)
/* 18B640 8025CD60 82020765 */  lb        $v0, 0x765($s0)
/* 18B644 8025CD64 10400017 */  beqz      $v0, .L8025CDC4
/* 18B648 8025CD68 00E0982D */   daddu    $s3, $a3, $zero
/* 18B64C 8025CD6C 0C095094 */  jal       func_80254250
/* 18B650 8025CD70 0220202D */   daddu    $a0, $s1, $zero
/* 18B654 8025CD74 0040182D */  daddu     $v1, $v0, $zero
/* 18B658 8025CD78 24040001 */  addiu     $a0, $zero, 1
/* 18B65C 8025CD7C 10640008 */  beq       $v1, $a0, .L8025CDA0
/* 18B660 8025CD80 28620002 */   slti     $v0, $v1, 2
/* 18B664 8025CD84 1040000A */  beqz      $v0, .L8025CDB0
/* 18B668 8025CD88 2402000E */   addiu    $v0, $zero, 0xe
/* 18B66C 8025CD8C 54600009 */  bnel      $v1, $zero, .L8025CDB4
/* 18B670 8025CD90 A2020767 */   sb       $v0, 0x767($s0)
/* 18B674 8025CD94 A2040767 */  sb        $a0, 0x767($s0)
/* 18B678 8025CD98 0809736F */  j         .L8025CDBC
/* 18B67C 8025CD9C A2000766 */   sb       $zero, 0x766($s0)
.L8025CDA0:
/* 18B680 8025CDA0 24020008 */  addiu     $v0, $zero, 8
/* 18B684 8025CDA4 A2020767 */  sb        $v0, 0x767($s0)
/* 18B688 8025CDA8 0809736F */  j         .L8025CDBC
/* 18B68C 8025CDAC A2030766 */   sb       $v1, 0x766($s0)
.L8025CDB0:
/* 18B690 8025CDB0 A2020767 */  sb        $v0, 0x767($s0)
.L8025CDB4:
/* 18B694 8025CDB4 24020002 */  addiu     $v0, $zero, 2
/* 18B698 8025CDB8 A2020766 */  sb        $v0, 0x766($s0)
.L8025CDBC:
/* 18B69C 8025CDBC A2000768 */  sb        $zero, 0x768($s0)
/* 18B6A0 8025CDC0 A2000765 */  sb        $zero, 0x765($s0)
.L8025CDC4:
/* 18B6A4 8025CDC4 82020766 */  lb        $v0, 0x766($s0)
/* 18B6A8 8025CDC8 24120003 */  addiu     $s2, $zero, 3
/* 18B6AC 8025CDCC 14520004 */  bne       $v0, $s2, .L8025CDE0
/* 18B6B0 8025CDD0 00000000 */   nop
/* 18B6B4 8025CDD4 A2000768 */  sb        $zero, 0x768($s0)
/* 18B6B8 8025CDD8 0C099C27 */  jal       func_8026709C
/* 18B6BC 8025CDDC 0220202D */   daddu    $a0, $s1, $zero
.L8025CDE0:
/* 18B6C0 8025CDE0 82030766 */  lb        $v1, 0x766($s0)
/* 18B6C4 8025CDE4 24020001 */  addiu     $v0, $zero, 1
/* 18B6C8 8025CDE8 10620012 */  beq       $v1, $v0, .L8025CE34
/* 18B6CC 8025CDEC 28620002 */   slti     $v0, $v1, 2
/* 18B6D0 8025CDF0 50400005 */  beql      $v0, $zero, .L8025CE08
/* 18B6D4 8025CDF4 24020002 */   addiu    $v0, $zero, 2
/* 18B6D8 8025CDF8 10600007 */  beqz      $v1, .L8025CE18
/* 18B6DC 8025CDFC 00000000 */   nop
/* 18B6E0 8025CE00 080973AB */  j         .L8025CEAC
/* 18B6E4 8025CE04 00000000 */   nop
.L8025CE08:
/* 18B6E8 8025CE08 10620013 */  beq       $v1, $v0, .L8025CE58
/* 18B6EC 8025CE0C 00000000 */   nop
/* 18B6F0 8025CE10 080973AB */  j         .L8025CEAC
/* 18B6F4 8025CE14 00000000 */   nop
.L8025CE18:
/* 18B6F8 8025CE18 82020767 */  lb        $v0, 0x767($s0)
/* 18B6FC 8025CE1C 5440001E */  bnel      $v0, $zero, .L8025CE98
/* 18B700 8025CE20 A2000768 */   sb       $zero, 0x768($s0)
/* 18B704 8025CE24 240200FF */  addiu     $v0, $zero, 0xff
/* 18B708 8025CE28 A2020768 */  sb        $v0, 0x768($s0)
/* 18B70C 8025CE2C 080973AB */  j         .L8025CEAC
/* 18B710 8025CE30 A2120766 */   sb       $s2, 0x766($s0)
.L8025CE34:
/* 18B714 8025CE34 82030767 */  lb        $v1, 0x767($s0)
/* 18B718 8025CE38 2C620009 */  sltiu     $v0, $v1, 9
/* 18B71C 8025CE3C 10400016 */  beqz      $v0, .L8025CE98
/* 18B720 8025CE40 00031080 */   sll      $v0, $v1, 2
/* 18B724 8025CE44 3C01802A */  lui       $at, %hi(jtbl_8029D420_1CBD00)
/* 18B728 8025CE48 00220821 */  addu      $at, $at, $v0
/* 18B72C 8025CE4C 8C22D420 */  lw        $v0, %lo(jtbl_8029D420_1CBD00)($at)
/* 18B730 8025CE50 00400008 */  jr        $v0
/* 18B734 8025CE54 00000000 */   nop
.L8025CE58:
/* 18B738 8025CE58 82030767 */  lb        $v1, 0x767($s0)
/* 18B73C 8025CE5C 2C62000F */  sltiu     $v0, $v1, 0xf
/* 18B740 8025CE60 1040000D */  beqz      $v0, .L8025CE98
/* 18B744 8025CE64 00031080 */   sll      $v0, $v1, 2
/* 18B748 8025CE68 3C01802A */  lui       $at, %hi(jtbl_8029D448_1CBD28)
/* 18B74C 8025CE6C 00220821 */  addu      $at, $at, $v0
/* 18B750 8025CE70 8C22D448 */  lw        $v0, %lo(jtbl_8029D448_1CBD28)($at)
/* 18B754 8025CE74 00400008 */  jr        $v0
/* 18B758 8025CE78 00000000 */   nop
glabel L8025CE7C_18B75C
/* 18B75C 8025CE7C 080973A6 */  j         .L8025CE98
/* 18B760 8025CE80 A2000768 */   sb       $zero, 0x768($s0)
glabel L8025CE84_18B764
/* 18B764 8025CE84 240200FF */  addiu     $v0, $zero, 0xff
/* 18B768 8025CE88 080973A6 */  j         .L8025CE98
/* 18B76C 8025CE8C A2020768 */   sb       $v0, 0x768($s0)
glabel L8025CE90_18B770
/* 18B770 8025CE90 24020003 */  addiu     $v0, $zero, 3
/* 18B774 8025CE94 A2020766 */  sb        $v0, 0x766($s0)
.L8025CE98:
/* 18B778 8025CE98 16600004 */  bnez      $s3, .L8025CEAC
/* 18B77C 8025CE9C 00000000 */   nop
/* 18B780 8025CEA0 92020767 */  lbu       $v0, 0x767($s0)
/* 18B784 8025CEA4 2442FFFF */  addiu     $v0, $v0, -1
/* 18B788 8025CEA8 A2020767 */  sb        $v0, 0x767($s0)
.L8025CEAC:
/* 18B78C 8025CEAC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 18B790 8025CEB0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 18B794 8025CEB4 8FB20018 */  lw        $s2, 0x18($sp)
/* 18B798 8025CEB8 8FB10014 */  lw        $s1, 0x14($sp)
/* 18B79C 8025CEBC 8FB00010 */  lw        $s0, 0x10($sp)
/* 18B7A0 8025CEC0 03E00008 */  jr        $ra
/* 18B7A4 8025CEC4 27BD0028 */   addiu    $sp, $sp, 0x28
