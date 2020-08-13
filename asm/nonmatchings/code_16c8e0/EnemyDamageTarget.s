.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel EnemyDamageTarget
/* 1AB594 8027CCB4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 1AB598 8027CCB8 AFB3001C */  sw    $s3, 0x1c($sp)
/* 1AB59C 8027CCBC 0080982D */  daddu $s3, $a0, $zero
/* 1AB5A0 8027CCC0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 1AB5A4 8027CCC4 AFB40020 */  sw    $s4, 0x20($sp)
/* 1AB5A8 8027CCC8 AFB20018 */  sw    $s2, 0x18($sp)
/* 1AB5AC 8027CCCC AFB10014 */  sw    $s1, 0x14($sp)
/* 1AB5B0 8027CCD0 AFB00010 */  sw    $s0, 0x10($sp)
/* 1AB5B4 8027CCD4 8E70000C */  lw    $s0, 0xc($s3)
/* 1AB5B8 8027CCD8 8E050000 */  lw    $a1, ($s0)
/* 1AB5BC 8027CCDC 0C0B1EAF */  jal   get_variable
/* 1AB5C0 8027CCE0 26100004 */   addiu $s0, $s0, 4
/* 1AB5C4 8027CCE4 0040202D */  daddu $a0, $v0, $zero
/* 1AB5C8 8027CCE8 3C11800E */  lui   $s1, 0x800e
/* 1AB5CC 8027CCEC 2631C070 */  addiu $s1, $s1, -0x3f90
/* 1AB5D0 8027CCF0 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1AB5D4 8027CCF4 14820002 */  bne   $a0, $v0, .L8027CD00
/* 1AB5D8 8027CCF8 00000000 */   nop   
/* 1AB5DC 8027CCFC 8E640148 */  lw    $a0, 0x148($s3)
.L8027CD00:
/* 1AB5E0 8027CD00 0C09A75B */  jal   get_actor
/* 1AB5E4 8027CD04 00000000 */   nop   
/* 1AB5E8 8027CD08 8E140000 */  lw    $s4, ($s0)
/* 1AB5EC 8027CD0C 26100004 */  addiu $s0, $s0, 4
/* 1AB5F0 8027CD10 8E030000 */  lw    $v1, ($s0)
/* 1AB5F4 8027CD14 26100004 */  addiu $s0, $s0, 4
/* 1AB5F8 8027CD18 0260202D */  daddu $a0, $s3, $zero
/* 1AB5FC 8027CD1C 0040902D */  daddu $s2, $v0, $zero
/* 1AB600 8027CD20 AE230188 */  sw    $v1, 0x188($s1)
/* 1AB604 8027CD24 8E030000 */  lw    $v1, ($s0)
/* 1AB608 8027CD28 26100004 */  addiu $s0, $s0, 4
/* 1AB60C 8027CD2C AE23018C */  sw    $v1, 0x18c($s1)
/* 1AB610 8027CD30 8E030000 */  lw    $v1, ($s0)
/* 1AB614 8027CD34 26100004 */  addiu $s0, $s0, 4
/* 1AB618 8027CD38 AE230190 */  sw    $v1, 0x190($s1)
/* 1AB61C 8027CD3C 8E050000 */  lw    $a1, ($s0)
/* 1AB620 8027CD40 0C0B1EAF */  jal   get_variable
/* 1AB624 8027CD44 26100004 */   addiu $s0, $s0, 4
/* 1AB628 8027CD48 A622017E */  sh    $v0, 0x17e($s1)
/* 1AB62C 8027CD4C 8E050000 */  lw    $a1, ($s0)
/* 1AB630 8027CD50 30A20010 */  andi  $v0, $a1, 0x10
/* 1AB634 8027CD54 10400004 */  beqz  $v0, .L8027CD68
/* 1AB638 8027CD58 2403FFDF */   addiu $v1, $zero, -0x21
/* 1AB63C 8027CD5C 8E220000 */  lw    $v0, ($s1)
/* 1AB640 8027CD60 0809F364 */  j     .L8027CD90
/* 1AB644 8027CD64 34420010 */   ori   $v0, $v0, 0x10

.L8027CD68:
/* 1AB648 8027CD68 30A20020 */  andi  $v0, $a1, 0x20
/* 1AB64C 8027CD6C 10400005 */  beqz  $v0, .L8027CD84
/* 1AB650 8027CD70 2403FFEF */   addiu $v1, $zero, -0x11
/* 1AB654 8027CD74 8E220000 */  lw    $v0, ($s1)
/* 1AB658 8027CD78 00431024 */  and   $v0, $v0, $v1
/* 1AB65C 8027CD7C 0809F365 */  j     .L8027CD94
/* 1AB660 8027CD80 34420020 */   ori   $v0, $v0, 0x20

.L8027CD84:
/* 1AB664 8027CD84 8E220000 */  lw    $v0, ($s1)
/* 1AB668 8027CD88 00431024 */  and   $v0, $v0, $v1
/* 1AB66C 8027CD8C 2403FFDF */  addiu $v1, $zero, -0x21
.L8027CD90:
/* 1AB670 8027CD90 00431024 */  and   $v0, $v0, $v1
.L8027CD94:
/* 1AB674 8027CD94 AE220000 */  sw    $v0, ($s1)
/* 1AB678 8027CD98 30A20040 */  andi  $v0, $a1, 0x40
/* 1AB67C 8027CD9C 10400007 */  beqz  $v0, .L8027CDBC
/* 1AB680 8027CDA0 2404FFBF */   addiu $a0, $zero, -0x41
/* 1AB684 8027CDA4 3C03800E */  lui   $v1, 0x800e
/* 1AB688 8027CDA8 2463C070 */  addiu $v1, $v1, -0x3f90
/* 1AB68C 8027CDAC 8C620000 */  lw    $v0, ($v1)
/* 1AB690 8027CDB0 34420040 */  ori   $v0, $v0, 0x40
/* 1AB694 8027CDB4 0809F374 */  j     .L8027CDD0
/* 1AB698 8027CDB8 AC620000 */   sw    $v0, ($v1)

.L8027CDBC:
/* 1AB69C 8027CDBC 3C02800E */  lui   $v0, 0x800e
/* 1AB6A0 8027CDC0 2442C070 */  addiu $v0, $v0, -0x3f90
/* 1AB6A4 8027CDC4 8C430000 */  lw    $v1, ($v0)
/* 1AB6A8 8027CDC8 00641824 */  and   $v1, $v1, $a0
/* 1AB6AC 8027CDCC AC430000 */  sw    $v1, ($v0)
.L8027CDD0:
/* 1AB6B0 8027CDD0 30A20200 */  andi  $v0, $a1, 0x200
/* 1AB6B4 8027CDD4 10400007 */  beqz  $v0, .L8027CDF4
/* 1AB6B8 8027CDD8 2404FDFF */   addiu $a0, $zero, -0x201
/* 1AB6BC 8027CDDC 3C03800E */  lui   $v1, 0x800e
/* 1AB6C0 8027CDE0 2463C070 */  addiu $v1, $v1, -0x3f90
/* 1AB6C4 8027CDE4 8C620000 */  lw    $v0, ($v1)
/* 1AB6C8 8027CDE8 34420200 */  ori   $v0, $v0, 0x200
/* 1AB6CC 8027CDEC 0809F382 */  j     .L8027CE08
/* 1AB6D0 8027CDF0 AC620000 */   sw    $v0, ($v1)

.L8027CDF4:
/* 1AB6D4 8027CDF4 3C02800E */  lui   $v0, 0x800e
/* 1AB6D8 8027CDF8 2442C070 */  addiu $v0, $v0, -0x3f90
/* 1AB6DC 8027CDFC 8C430000 */  lw    $v1, ($v0)
/* 1AB6E0 8027CE00 00641824 */  and   $v1, $v1, $a0
/* 1AB6E4 8027CE04 AC430000 */  sw    $v1, ($v0)
.L8027CE08:
/* 1AB6E8 8027CE08 30A20080 */  andi  $v0, $a1, 0x80
/* 1AB6EC 8027CE0C 10400007 */  beqz  $v0, .L8027CE2C
/* 1AB6F0 8027CE10 2404FF7F */   addiu $a0, $zero, -0x81
/* 1AB6F4 8027CE14 3C03800E */  lui   $v1, 0x800e
/* 1AB6F8 8027CE18 2463C070 */  addiu $v1, $v1, -0x3f90
/* 1AB6FC 8027CE1C 8C620000 */  lw    $v0, ($v1)
/* 1AB700 8027CE20 34420080 */  ori   $v0, $v0, 0x80
/* 1AB704 8027CE24 0809F390 */  j     .L8027CE40
/* 1AB708 8027CE28 AC620000 */   sw    $v0, ($v1)

.L8027CE2C:
/* 1AB70C 8027CE2C 3C02800E */  lui   $v0, 0x800e
/* 1AB710 8027CE30 2442C070 */  addiu $v0, $v0, -0x3f90
/* 1AB714 8027CE34 8C430000 */  lw    $v1, ($v0)
/* 1AB718 8027CE38 00641824 */  and   $v1, $v1, $a0
/* 1AB71C 8027CE3C AC430000 */  sw    $v1, ($v0)
.L8027CE40:
/* 1AB720 8027CE40 96420428 */  lhu   $v0, 0x428($s2)
/* 1AB724 8027CE44 92230193 */  lbu   $v1, 0x193($s1)
/* 1AB728 8027CE48 A62201A0 */  sh    $v0, 0x1a0($s1)
/* 1AB72C 8027CE4C 92420426 */  lbu   $v0, 0x426($s2)
/* 1AB730 8027CE50 A2230194 */  sb    $v1, 0x194($s1)
/* 1AB734 8027CE54 306300FF */  andi  $v1, $v1, 0xff
/* 1AB738 8027CE58 A22201A2 */  sb    $v0, 0x1a2($s1)
/* 1AB73C 8027CE5C 240200FF */  addiu $v0, $zero, 0xff
/* 1AB740 8027CE60 50620001 */  beql  $v1, $v0, .L8027CE68
/* 1AB744 8027CE64 A2200194 */   sb    $zero, 0x194($s1)
.L8027CE68:
/* 1AB748 8027CE68 8E220190 */  lw    $v0, 0x190($s1)
/* 1AB74C 8027CE6C 0240202D */  daddu $a0, $s2, $zero
/* 1AB750 8027CE70 30420F00 */  andi  $v0, $v0, 0xf00
/* 1AB754 8027CE74 00021203 */  sra   $v0, $v0, 8
/* 1AB758 8027CE78 0C09DD0B */  jal   calc_enemy_damage_target
/* 1AB75C 8027CE7C A2220195 */   sb    $v0, 0x195($s1)
/* 1AB760 8027CE80 0440000B */  bltz  $v0, .L8027CEB0
/* 1AB764 8027CE84 0260202D */   daddu $a0, $s3, $zero
/* 1AB768 8027CE88 0280282D */  daddu $a1, $s4, $zero
/* 1AB76C 8027CE8C 0C0B2026 */  jal   set_variable
/* 1AB770 8027CE90 0040302D */   daddu $a2, $v0, $zero
/* 1AB774 8027CE94 0C0B1069 */  jal   does_script_exist_by_ref
/* 1AB778 8027CE98 0260202D */   daddu $a0, $s3, $zero
/* 1AB77C 8027CE9C 0040182D */  daddu $v1, $v0, $zero
/* 1AB780 8027CEA0 10600004 */  beqz  $v1, .L8027CEB4
/* 1AB784 8027CEA4 240200FF */   addiu $v0, $zero, 0xff
/* 1AB788 8027CEA8 0809F3AD */  j     .L8027CEB4
/* 1AB78C 8027CEAC 24020002 */   addiu $v0, $zero, 2

.L8027CEB0:
/* 1AB790 8027CEB0 240200FF */  addiu $v0, $zero, 0xff
.L8027CEB4:
.L8027CEB4:
/* 1AB794 8027CEB4 8FBF0024 */  lw    $ra, 0x24($sp)
/* 1AB798 8027CEB8 8FB40020 */  lw    $s4, 0x20($sp)
/* 1AB79C 8027CEBC 8FB3001C */  lw    $s3, 0x1c($sp)
/* 1AB7A0 8027CEC0 8FB20018 */  lw    $s2, 0x18($sp)
/* 1AB7A4 8027CEC4 8FB10014 */  lw    $s1, 0x14($sp)
/* 1AB7A8 8027CEC8 8FB00010 */  lw    $s0, 0x10($sp)
/* 1AB7AC 8027CECC 03E00008 */  jr    $ra
/* 1AB7B0 8027CED0 27BD0028 */   addiu $sp, $sp, 0x28

