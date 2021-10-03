.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_8_appendGfx
/* 32CCB0 E0010510 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 32CCB4 E0010514 0080602D */  daddu     $t4, $a0, $zero
/* 32CCB8 E0010518 3C05DB06 */  lui       $a1, 0xdb06
/* 32CCBC E001051C 34A50024 */  ori       $a1, $a1, 0x24
/* 32CCC0 E0010520 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 32CCC4 E0010524 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 32CCC8 E0010528 3C02E700 */  lui       $v0, 0xe700
/* 32CCCC E001052C AFB7001C */  sw        $s7, 0x1c($sp)
/* 32CCD0 E0010530 AFB60018 */  sw        $s6, 0x18($sp)
/* 32CCD4 E0010534 AFB50014 */  sw        $s5, 0x14($sp)
/* 32CCD8 E0010538 AFB40010 */  sw        $s4, 0x10($sp)
/* 32CCDC E001053C AFB3000C */  sw        $s3, 0xc($sp)
/* 32CCE0 E0010540 AFB20008 */  sw        $s2, 8($sp)
/* 32CCE4 E0010544 AFB10004 */  sw        $s1, 4($sp)
/* 32CCE8 E0010548 AFB00000 */  sw        $s0, ($sp)
/* 32CCEC E001054C 8CC40000 */  lw        $a0, ($a2)
/* 32CCF0 E0010550 8D88000C */  lw        $t0, 0xc($t4)
/* 32CCF4 E0010554 0080182D */  daddu     $v1, $a0, $zero
/* 32CCF8 E0010558 24840008 */  addiu     $a0, $a0, 8
/* 32CCFC E001055C AC620000 */  sw        $v0, ($v1)
/* 32CD00 E0010560 AC600004 */  sw        $zero, 4($v1)
/* 32CD04 E0010564 AC850000 */  sw        $a1, ($a0)
/* 32CD08 E0010568 8D820010 */  lw        $v0, 0x10($t4)
/* 32CD0C E001056C 0000482D */  daddu     $t1, $zero, $zero
/* 32CD10 E0010570 ACC40000 */  sw        $a0, ($a2)
/* 32CD14 E0010574 8C42001C */  lw        $v0, 0x1c($v0)
/* 32CD18 E0010578 3C038000 */  lui       $v1, 0x8000
/* 32CD1C E001057C 00431021 */  addu      $v0, $v0, $v1
/* 32CD20 E0010580 AC820004 */  sw        $v0, 4($a0)
/* 32CD24 E0010584 8D820008 */  lw        $v0, 8($t4)
/* 32CD28 E0010588 24840008 */  addiu     $a0, $a0, 8
/* 32CD2C E001058C 1840004A */  blez      $v0, .LE00106B8
/* 32CD30 E0010590 ACC40000 */   sw       $a0, ($a2)
/* 32CD34 E0010594 3C0F800A */  lui       $t7, %hi(gDisplayContext)
/* 32CD38 E0010598 25EFA674 */  addiu     $t7, $t7, %lo(gDisplayContext)
/* 32CD3C E001059C 3C0D8007 */  lui       $t5, %hi(gMatrixListPos)
/* 32CD40 E00105A0 25AD41F0 */  addiu     $t5, $t5, %lo(gMatrixListPos)
/* 32CD44 E00105A4 3C0B0001 */  lui       $t3, 1
/* 32CD48 E00105A8 356B1630 */  ori       $t3, $t3, 0x1630
/* 32CD4C E00105AC 00C0502D */  daddu     $t2, $a2, $zero
/* 32CD50 E00105B0 3C13FA00 */  lui       $s3, 0xfa00
/* 32CD54 E00105B4 3C197060 */  lui       $t9, 0x7060
/* 32CD58 E00105B8 37391800 */  ori       $t9, $t9, 0x1800
/* 32CD5C E00105BC 3C12DA38 */  lui       $s2, 0xda38
/* 32CD60 E00105C0 3C11DE00 */  lui       $s1, 0xde00
/* 32CD64 E00105C4 3C18D838 */  lui       $t8, 0xd838
/* 32CD68 E00105C8 37180002 */  ori       $t8, $t8, 2
/* 32CD6C E00105CC 24100040 */  addiu     $s0, $zero, 0x40
/* 32CD70 E00105D0 25070070 */  addiu     $a3, $t0, 0x70
.LE00105D4:
/* 32CD74 E00105D4 8D020000 */  lw        $v0, ($t0)
/* 32CD78 E00105D8 50400032 */  beql      $v0, $zero, .LE00106A4
/* 32CD7C E00105DC 25290001 */   addiu    $t1, $t1, 1
/* 32CD80 E00105E0 3C0E0900 */  lui       $t6, 0x900
/* 32CD84 E00105E4 25CE0E08 */  addiu     $t6, $t6, 0xe08
/* 32CD88 E00105E8 25040030 */  addiu     $a0, $t0, 0x30
/* 32CD8C E00105EC 00E0282D */  daddu     $a1, $a3, $zero
/* 32CD90 E00105F0 95A20000 */  lhu       $v0, ($t5)
/* 32CD94 E00105F4 8DE30000 */  lw        $v1, ($t7)
/* 32CD98 E00105F8 00021180 */  sll       $v0, $v0, 6
/* 32CD9C E00105FC 00621821 */  addu      $v1, $v1, $v0
/* 32CDA0 E0010600 006B1821 */  addu      $v1, $v1, $t3
.LE0010604:
/* 32CDA4 E0010604 8C940000 */  lw        $s4, ($a0)
/* 32CDA8 E0010608 8C950004 */  lw        $s5, 4($a0)
/* 32CDAC E001060C 8C960008 */  lw        $s6, 8($a0)
/* 32CDB0 E0010610 8C97000C */  lw        $s7, 0xc($a0)
/* 32CDB4 E0010614 AC740000 */  sw        $s4, ($v1)
/* 32CDB8 E0010618 AC750004 */  sw        $s5, 4($v1)
/* 32CDBC E001061C AC760008 */  sw        $s6, 8($v1)
/* 32CDC0 E0010620 AC77000C */  sw        $s7, 0xc($v1)
/* 32CDC4 E0010624 24840010 */  addiu     $a0, $a0, 0x10
/* 32CDC8 E0010628 1485FFF6 */  bne       $a0, $a1, .LE0010604
/* 32CDCC E001062C 24630010 */   addiu    $v1, $v1, 0x10
/* 32CDD0 E0010630 8D440000 */  lw        $a0, ($t2)
/* 32CDD4 E0010634 0080302D */  daddu     $a2, $a0, $zero
/* 32CDD8 E0010638 24840008 */  addiu     $a0, $a0, 8
/* 32CDDC E001063C AD440000 */  sw        $a0, ($t2)
/* 32CDE0 E0010640 ACD30000 */  sw        $s3, ($a2)
/* 32CDE4 E0010644 90E5FF98 */  lbu       $a1, -0x68($a3)
/* 32CDE8 E0010648 95A30000 */  lhu       $v1, ($t5)
/* 32CDEC E001064C 24820008 */  addiu     $v0, $a0, 8
/* 32CDF0 E0010650 AD420000 */  sw        $v0, ($t2)
/* 32CDF4 E0010654 24620001 */  addiu     $v0, $v1, 1
/* 32CDF8 E0010658 A5A20000 */  sh        $v0, ($t5)
/* 32CDFC E001065C 24820010 */  addiu     $v0, $a0, 0x10
/* 32CE00 E0010660 AD420000 */  sw        $v0, ($t2)
/* 32CE04 E0010664 24820018 */  addiu     $v0, $a0, 0x18
/* 32CE08 E0010668 00B92825 */  or        $a1, $a1, $t9
/* 32CE0C E001066C 3063FFFF */  andi      $v1, $v1, 0xffff
/* 32CE10 E0010670 00031980 */  sll       $v1, $v1, 6
/* 32CE14 E0010674 AD420000 */  sw        $v0, ($t2)
/* 32CE18 E0010678 ACC50004 */  sw        $a1, 4($a2)
/* 32CE1C E001067C AC920000 */  sw        $s2, ($a0)
/* 32CE20 E0010680 8DE20000 */  lw        $v0, ($t7)
/* 32CE24 E0010684 006B1821 */  addu      $v1, $v1, $t3
/* 32CE28 E0010688 AC910008 */  sw        $s1, 8($a0)
/* 32CE2C E001068C AC8E000C */  sw        $t6, 0xc($a0)
/* 32CE30 E0010690 AC980010 */  sw        $t8, 0x10($a0)
/* 32CE34 E0010694 AC900014 */  sw        $s0, 0x14($a0)
/* 32CE38 E0010698 00431021 */  addu      $v0, $v0, $v1
/* 32CE3C E001069C AC820004 */  sw        $v0, 4($a0)
/* 32CE40 E00106A0 25290001 */  addiu     $t1, $t1, 1
.LE00106A4:
/* 32CE44 E00106A4 24E70098 */  addiu     $a3, $a3, 0x98
/* 32CE48 E00106A8 8D820008 */  lw        $v0, 8($t4)
/* 32CE4C E00106AC 0122102A */  slt       $v0, $t1, $v0
/* 32CE50 E00106B0 1440FFC8 */  bnez      $v0, .LE00105D4
/* 32CE54 E00106B4 25080098 */   addiu    $t0, $t0, 0x98
.LE00106B8:
/* 32CE58 E00106B8 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 32CE5C E00106BC 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 32CE60 E00106C0 8C620000 */  lw        $v0, ($v1)
/* 32CE64 E00106C4 0040202D */  daddu     $a0, $v0, $zero
/* 32CE68 E00106C8 24420008 */  addiu     $v0, $v0, 8
/* 32CE6C E00106CC AC620000 */  sw        $v0, ($v1)
/* 32CE70 E00106D0 3C02E700 */  lui       $v0, 0xe700
/* 32CE74 E00106D4 AC820000 */  sw        $v0, ($a0)
/* 32CE78 E00106D8 AC800004 */  sw        $zero, 4($a0)
/* 32CE7C E00106DC 8FB7001C */  lw        $s7, 0x1c($sp)
/* 32CE80 E00106E0 8FB60018 */  lw        $s6, 0x18($sp)
/* 32CE84 E00106E4 8FB50014 */  lw        $s5, 0x14($sp)
/* 32CE88 E00106E8 8FB40010 */  lw        $s4, 0x10($sp)
/* 32CE8C E00106EC 8FB3000C */  lw        $s3, 0xc($sp)
/* 32CE90 E00106F0 8FB20008 */  lw        $s2, 8($sp)
/* 32CE94 E00106F4 8FB10004 */  lw        $s1, 4($sp)
/* 32CE98 E00106F8 8FB00000 */  lw        $s0, ($sp)
/* 32CE9C E00106FC 03E00008 */  jr        $ra
/* 32CEA0 E0010700 27BD0020 */   addiu    $sp, $sp, 0x20
/* 32CEA4 E0010704 00000000 */  nop
/* 32CEA8 E0010708 00000000 */  nop
/* 32CEAC E001070C 00000000 */  nop
