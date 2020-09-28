.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80138D88
/* CF488 80138D88 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CF48C 80138D8C AFBF0018 */  sw        $ra, 0x18($sp)
/* CF490 80138D90 0080182D */  daddu     $v1, $a0, $zero
/* CF494 80138D94 00C3102A */  slt       $v0, $a2, $v1
/* CF498 80138D98 10400004 */  beqz      $v0, .L80138DAC
/* CF49C 80138D9C 00A0402D */   daddu    $t0, $a1, $zero
/* CF4A0 80138DA0 00C0202D */  daddu     $a0, $a2, $zero
/* CF4A4 80138DA4 0804E36C */  j         .L80138DB0
/* CF4A8 80138DA8 0060302D */   daddu    $a2, $v1, $zero
.L80138DAC:
/* CF4AC 80138DAC 0060202D */  daddu     $a0, $v1, $zero
.L80138DB0:
/* CF4B0 80138DB0 00E8102A */  slt       $v0, $a3, $t0
/* CF4B4 80138DB4 10400003 */  beqz      $v0, .L80138DC4
/* CF4B8 80138DB8 00E0282D */   daddu    $a1, $a3, $zero
/* CF4BC 80138DBC 0804E372 */  j         .L80138DC8
/* CF4C0 80138DC0 0100382D */   daddu    $a3, $t0, $zero
.L80138DC4:
/* CF4C4 80138DC4 0100282D */  daddu     $a1, $t0, $zero
.L80138DC8:
/* CF4C8 80138DC8 0086102A */  slt       $v0, $a0, $a2
/* CF4CC 80138DCC 1040001E */  beqz      $v0, .L80138E48
/* CF4D0 80138DD0 00A7102A */   slt      $v0, $a1, $a3
/* CF4D4 80138DD4 1040001C */  beqz      $v0, .L80138E48
/* CF4D8 80138DD8 00000000 */   nop      
/* CF4DC 80138DDC 04820001 */  bltzl     $a0, .L80138DE4
/* CF4E0 80138DE0 0000202D */   daddu    $a0, $zero, $zero
.L80138DE4:
/* CF4E4 80138DE4 04A20001 */  bltzl     $a1, .L80138DEC
/* CF4E8 80138DE8 0000282D */   daddu    $a1, $zero, $zero
.L80138DEC:
/* CF4EC 80138DEC 04C20001 */  bltzl     $a2, .L80138DF4
/* CF4F0 80138DF0 0000302D */   daddu    $a2, $zero, $zero
.L80138DF4:
/* CF4F4 80138DF4 04E20001 */  bltzl     $a3, .L80138DFC
/* CF4F8 80138DF8 0000382D */   daddu    $a3, $zero, $zero
.L80138DFC:
/* CF4FC 80138DFC 28820140 */  slti      $v0, $a0, 0x140
/* CF500 80138E00 50400001 */  beql      $v0, $zero, .L80138E08
/* CF504 80138E04 2404013F */   addiu    $a0, $zero, 0x13f
.L80138E08:
/* CF508 80138E08 28A200F0 */  slti      $v0, $a1, 0xf0
/* CF50C 80138E0C 50400001 */  beql      $v0, $zero, .L80138E14
/* CF510 80138E10 240500EF */   addiu    $a1, $zero, 0xef
.L80138E14:
/* CF514 80138E14 28C20140 */  slti      $v0, $a2, 0x140
/* CF518 80138E18 50400001 */  beql      $v0, $zero, .L80138E20
/* CF51C 80138E1C 2406013F */   addiu    $a2, $zero, 0x13f
.L80138E20:
/* CF520 80138E20 28E200F0 */  slti      $v0, $a3, 0xf0
/* CF524 80138E24 50400001 */  beql      $v0, $zero, .L80138E2C
/* CF528 80138E28 240700EF */   addiu    $a3, $zero, 0xef
.L80138E2C:
/* CF52C 80138E2C 10860006 */  beq       $a0, $a2, .L80138E48
/* CF530 80138E30 00000000 */   nop      
/* CF534 80138E34 10A70004 */  beq       $a1, $a3, .L80138E48
/* CF538 80138E38 00000000 */   nop      
/* CF53C 80138E3C C7A00030 */  lwc1      $f0, 0x30($sp)
/* CF540 80138E40 0C04E1D0 */  jal       func_80138740
/* CF544 80138E44 E7A00010 */   swc1     $f0, 0x10($sp)
.L80138E48:
/* CF548 80138E48 8FBF0018 */  lw        $ra, 0x18($sp)
/* CF54C 80138E4C 03E00008 */  jr        $ra
/* CF550 80138E50 27BD0020 */   addiu    $sp, $sp, 0x20
