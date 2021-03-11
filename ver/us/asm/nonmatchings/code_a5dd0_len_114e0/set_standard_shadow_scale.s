.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_8014F950
.double 0.13

glabel D_8014F958
.double 0.12

glabel D_8014F960
.double 0.01

.section .text

glabel set_standard_shadow_scale
/* A8F5C 8011285C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* A8F60 80112860 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* A8F64 80112864 80420070 */  lb        $v0, 0x70($v0)
/* A8F68 80112868 44851000 */  mtc1      $a1, $f2
/* A8F6C 8011286C 1440000A */  bnez      $v0, .L80112898
/* A8F70 80112870 00000000 */   nop
/* A8F74 80112874 3C014522 */  lui       $at, 0x4522
/* A8F78 80112878 34218000 */  ori       $at, $at, 0x8000
/* A8F7C 8011287C 44810000 */  mtc1      $at, $f0
/* A8F80 80112880 00000000 */  nop
/* A8F84 80112884 46001003 */  div.s     $f0, $f2, $f0
/* A8F88 80112888 3C018015 */  lui       $at, %hi(D_8014F950)
/* A8F8C 8011288C D422F950 */  ldc1      $f2, %lo(D_8014F950)($at)
/* A8F90 80112890 08044A2D */  j         .L801128B4
/* A8F94 80112894 46000021 */   cvt.d.s  $f0, $f0
.L80112898:
/* A8F98 80112898 3C014561 */  lui       $at, 0x4561
/* A8F9C 8011289C 44810000 */  mtc1      $at, $f0
/* A8FA0 801128A0 00000000 */  nop
/* A8FA4 801128A4 46001003 */  div.s     $f0, $f2, $f0
/* A8FA8 801128A8 3C018015 */  lui       $at, %hi(D_8014F958)
/* A8FAC 801128AC D422F958 */  ldc1      $f2, %lo(D_8014F958)($at)
/* A8FB0 801128B0 46000021 */  cvt.d.s   $f0, $f0
.L801128B4:
/* A8FB4 801128B4 46201081 */  sub.d     $f2, $f2, $f0
/* A8FB8 801128B8 462010A0 */  cvt.s.d   $f2, $f2
/* A8FBC 801128BC E482001C */  swc1      $f2, 0x1c($a0)
/* A8FC0 801128C0 C480001C */  lwc1      $f0, 0x1c($a0)
/* A8FC4 801128C4 3C018015 */  lui       $at, %hi(D_8014F960)
/* A8FC8 801128C8 D422F960 */  ldc1      $f2, %lo(D_8014F960)($at)
/* A8FCC 801128CC 46000021 */  cvt.d.s   $f0, $f0
/* A8FD0 801128D0 4622003C */  c.lt.d    $f0, $f2
/* A8FD4 801128D4 00000000 */  nop
/* A8FD8 801128D8 45000006 */  bc1f      .L801128F4
/* A8FDC 801128DC 00000000 */   nop
/* A8FE0 801128E0 3C013C23 */  lui       $at, 0x3c23
/* A8FE4 801128E4 3421D70A */  ori       $at, $at, 0xd70a
/* A8FE8 801128E8 44810000 */  mtc1      $at, $f0
/* A8FEC 801128EC 00000000 */  nop
/* A8FF0 801128F0 E480001C */  swc1      $f0, 0x1c($a0)
.L801128F4:
/* A8FF4 801128F4 C480001C */  lwc1      $f0, 0x1c($a0)
/* A8FF8 801128F8 03E00008 */  jr        $ra
/* A8FFC 801128FC E4800024 */   swc1     $f0, 0x24($a0)
