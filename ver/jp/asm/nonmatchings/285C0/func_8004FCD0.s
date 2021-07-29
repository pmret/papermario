.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FCD0
/* 2B0D0 8004FCD0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 2B0D4 8004FCD4 AFB20018 */  sw        $s2, 0x18($sp)
/* 2B0D8 8004FCD8 00A0902D */  daddu     $s2, $a1, $zero
/* 2B0DC 8004FCDC AFBF001C */  sw        $ra, 0x1c($sp)
/* 2B0E0 8004FCE0 AFB10014 */  sw        $s1, 0x14($sp)
/* 2B0E4 8004FCE4 AFB00010 */  sw        $s0, 0x10($sp)
/* 2B0E8 8004FCE8 908500D4 */  lbu       $a1, 0xd4($a0)
/* 2B0EC 8004FCEC 2CA20080 */  sltiu     $v0, $a1, 0x80
/* 2B0F0 8004FCF0 50400008 */  beql      $v0, $zero, .L8004FD14
/* 2B0F4 8004FCF4 24A5FF80 */   addiu    $a1, $a1, -0x80
/* 2B0F8 8004FCF8 9082021D */  lbu       $v0, 0x21d($a0)
/* 2B0FC 8004FCFC 00A2102B */  sltu      $v0, $a1, $v0
/* 2B100 8004FD00 1040000C */  beqz      $v0, .L8004FD34
/* 2B104 8004FD04 000510C0 */   sll      $v0, $a1, 3
/* 2B108 8004FD08 8C83007C */  lw        $v1, 0x7c($a0)
/* 2B10C 8004FD0C 08013F4F */  j         .L8004FD3C
/* 2B110 8004FD10 00628821 */   addu     $s1, $v1, $v0
.L8004FD14:
/* 2B114 8004FD14 2CA20040 */  sltiu     $v0, $a1, 0x40
/* 2B118 8004FD18 10400006 */  beqz      $v0, .L8004FD34
/* 2B11C 8004FD1C 00000000 */   nop
/* 2B120 8004FD20 8C820000 */  lw        $v0, ($a0)
/* 2B124 8004FD24 8C430058 */  lw        $v1, 0x58($v0)
/* 2B128 8004FD28 000510C0 */  sll       $v0, $a1, 3
/* 2B12C 8004FD2C 08013F4F */  j         .L8004FD3C
/* 2B130 8004FD30 00628821 */   addu     $s1, $v1, $v0
.L8004FD34:
/* 2B134 8004FD34 8C820000 */  lw        $v0, ($a0)
/* 2B138 8004FD38 24510014 */  addiu     $s1, $v0, 0x14
.L8004FD3C:
/* 2B13C 8004FD3C 26470010 */  addiu     $a3, $s2, 0x10
/* 2B140 8004FD40 96250000 */  lhu       $a1, ($s1)
/* 2B144 8004FD44 92220002 */  lbu       $v0, 2($s1)
/* 2B148 8004FD48 92260001 */  lbu       $a2, 1($s1)
/* 2B14C 8004FD4C 3050007F */  andi      $s0, $v0, 0x7f
/* 2B150 8004FD50 A6460044 */  sh        $a2, 0x44($s2)
/* 2B154 8004FD54 8C840000 */  lw        $a0, ($a0)
/* 2B158 8004FD58 0C014E26 */  jal       func_80053898
/* 2B15C 8004FD5C 00052A02 */   srl      $a1, $a1, 8
/* 2B160 8004FD60 12000002 */  beqz      $s0, .L8004FD6C
/* 2B164 8004FD64 AE42000C */   sw       $v0, 0xc($s2)
/* 2B168 8004FD68 00108600 */  sll       $s0, $s0, 0x18
.L8004FD6C:
/* 2B16C 8004FD6C AE500018 */  sw        $s0, 0x18($s2)
/* 2B170 8004FD70 92220003 */  lbu       $v0, 3($s1)
/* 2B174 8004FD74 3042007F */  andi      $v0, $v0, 0x7f
/* 2B178 8004FD78 A242004A */  sb        $v0, 0x4a($s2)
/* 2B17C 8004FD7C 92220004 */  lbu       $v0, 4($s1)
/* 2B180 8004FD80 3C040001 */  lui       $a0, 1
/* 2B184 8004FD84 3042007F */  andi      $v0, $v0, 0x7f
/* 2B188 8004FD88 A242004B */  sb        $v0, 0x4b($s2)
/* 2B18C 8004FD8C 82230005 */  lb        $v1, 5($s1)
/* 2B190 8004FD90 34840101 */  ori       $a0, $a0, 0x101
/* 2B194 8004FD94 00031040 */  sll       $v0, $v1, 1
/* 2B198 8004FD98 00431021 */  addu      $v0, $v0, $v1
/* 2B19C 8004FD9C 000210C0 */  sll       $v0, $v0, 3
/* 2B1A0 8004FDA0 00431021 */  addu      $v0, $v0, $v1
/* 2B1A4 8004FDA4 00021080 */  sll       $v0, $v0, 2
/* 2B1A8 8004FDA8 A6420046 */  sh        $v0, 0x46($s2)
/* 2B1AC 8004FDAC 8E420040 */  lw        $v0, 0x40($s2)
/* 2B1B0 8004FDB0 92230006 */  lbu       $v1, 6($s1)
/* 2B1B4 8004FDB4 00441025 */  or        $v0, $v0, $a0
/* 2B1B8 8004FDB8 AE420040 */  sw        $v0, 0x40($s2)
/* 2B1BC 8004FDBC A2430048 */  sb        $v1, 0x48($s2)
/* 2B1C0 8004FDC0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 2B1C4 8004FDC4 8FB20018 */  lw        $s2, 0x18($sp)
/* 2B1C8 8004FDC8 8FB10014 */  lw        $s1, 0x14($sp)
/* 2B1CC 8004FDCC 8FB00010 */  lw        $s0, 0x10($sp)
/* 2B1D0 8004FDD0 03E00008 */  jr        $ra
/* 2B1D4 8004FDD4 27BD0020 */   addiu    $sp, $sp, 0x20
